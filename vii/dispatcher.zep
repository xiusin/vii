namespace Vii;
use Vii\Interfaces\IocInterface;
use Vii\Exceptions\HttpException;
use Vii\Exceptions\RunTimeException;
use Vii\Interfaces\ModuleInterface;

/**
 * 路由分发类库
 */
class Dispatcher implements IocInterface
{
    private ioc;
    private actionName;
    private controllerName;
    private moduleName;
    private namespaceName;
    private application;
    private actionSuffix = "Action";
    private controllerSuffix = "Controller";
    private _defaultController = "Index";
    private _defaultAction="index";
    private _defaultModule="";
    private _defaultNamespace="";
    private _controllerInstance;    //最终路由到的实例
    //设置当前Application的实例
    public function setApp(appname){
        let this->application = appname;
        return this;
    }

    //获取当前Application的实例
    public function getApp(){
        return this->application;
    }

    //设置操作的后缀
    public function setActionSuffix(actionSuffix){
        let this->actionSuffix = actionSuffix;
        return this;
    }
    //获取操作后缀
    public function getActionSuffix(){
        return this->actionSuffix;
    }
    //设置控制器后缀
    public function setControllerSuffix(controllerSuffix){
        let this->controllerSuffix = controllerSuffix;
        return this;
    }
    //获取控制器后缀
    public function getControllerSuffix(){
        return this->controllerSuffix;
    }

    //获取最终路由到的信息内容
    private function getHandlerController(){
        var _controller ;
        if !this->namespaceName {
            let this->namespaceName = this->_defaultNamespace;
        }
        if !this->moduleName {
            let this->moduleName = this->_defaultModule;
        }
        if !this->controllerName  {
            let this->controllerName = this->_defaultController;
        }
        if !this->actionName  {
            let this->actionName = this->_defaultAction;
        }
        let _controller = ucfirst(strtolower(this->controllerName)).this->controllerSuffix;

        if this->namespaceName != "" {
            let _controller = this->namespaceName . "\\Controller\\" . _controller;
        }
        return _controller;
    }

    /**
     * 分发路由
     * @return string
     */
    public function dispatch(){
         var router,_url;
         let router = this->ioc->get("router");
         let _url = this->ioc->get("request")->get("_url");
         if !_url || _url == "/" || typeof _url == "array" {
             //情况分析：第一：直接访问网址  第二 _url被替换 则直接用默认路由处理
             let this->moduleName = router->getDefaultModule();
         } else {
             router->handle(_url);  //处理路由
             if !router->wasMatched() {   //没有匹配到内容
                 throw new HttpException("没有找到指定的路由信息");
             }else{ //能匹配到路由
                 //将匹配到的路由信息分配给调度程序
                 this->setMatches(router->getMatches());
             }
         }
         this->setModuleHandleInfo();
         return this->sendContent(this->_exec(this->getHandlerController()));
    }

    //设置模块处理信息 [针对模块化开发，普通方式开发忽略此项]
    private function setModuleHandleInfo(){
        var handleModuleInfo = [],className;
        //通过模块名获取注册的模块信息 todo 此处踩坑好几十个小时， 方法放到if里则会无缘无故出现错误。
        let handleModuleInfo = this->getApp()->{"getRegisterModuleByModuleName"}(this->moduleName);
        if ! Empty this->moduleName {
            this->loadModuleByName(handleModuleInfo,this->moduleName);
            let className = handleModuleInfo["className"];
            let this->namespaceName = substr(className,0,strrpos(className,"\\"));
        }
    }
    //将路由匹配到的信息分配到调度器内
    private function setMatches(array! matches){
        let this->namespaceName = matches["namespace"];
        let this->moduleName = matches["module"];
        let this->controllerName = matches["controller"];
        let this->actionName = matches["action"];
        return this;
    }

    public function setIoc(_ioc){
        let this->ioc = _ioc;
        return this;
    }
    public function getIoc(){
        return this->ioc;
    }
    //获取最终的uri的额外的params
    public function getParams(){
        return this->ioc->get("router")->getParams();
    }
    //分析执行实例
    private function _exec(string! handlerClass){
        var _handler,_method,actionName,parameters,parameter,_methodParameter = [];
        let actionName = this->actionName . this->actionSuffix;
        if !class_exists(handlerClass) {
             throw new HttpException("没有找到指定的类文件:[[".handlerClass."]]");
        }
        let _method = new \ReflectionMethod(handlerClass,actionName);
        if !_method {
                throw new HttpException("没有找到指定的方法:[[".handlerClass."::".actionName."]]");
        }else{
            //todo 反射一下方法内的参数
            if !_method->isPublic() {
                throw new HttpException("方法可见性不正确 必须为public");
            }
            let _handler = new \ReflectionClass(handlerClass);
            if !_handler->isSubclassOf("Vii\\Mvc\\Controller") {
                throw new RunTimeException(handlerClass . " 没有继承Vii\\Mvc\\Controller");
            }
            let this->_controllerInstance = _handler->newInstanceArgs([]);
            this->_controllerInstance->setIoc(this->ioc);   //向Controller内注入服务
            let parameters = _method->getParameters();
            var currcls = "",clsType = ["array","string"];
            for parameter in parameters {
                let currcls = parameter->getClass();
                if currcls {    //如果定义了参数类型
                    if !in_array(clsType,currcls->name) {
                        throw new RunTimeException("操作可接收的参数类型只能为数组和字符串");//检查是否在DI里实例化过方法
                    }
                }
                if isset _REQUEST[parameter->name] {
                    let _methodParameter[] = _REQUEST[parameter->name];
                }else{
                    if parameter->isOptional() {    //判断是否是一个可选项
                        let _methodParameter[] = parameter->getDefaultValue(); //todo 是否需要严谨判定参数
                    }
                }
            }
            //对比参数数量是否一致
            if count(_methodParameter) != count(parameters) {
                 throw new RunTimeException("操作的参数个数不符");
            }
            return call_user_func_array([this->_controllerInstance, actionName], _methodParameter);
        }
    }

    //content 从控制器内获取到的返回值
    private function sendContent(content = null){
       var beforeBuffer,response,hasContent,hasHeader;
       let response = this->ioc->get("response");
       //返回的内容为逻辑假 并且没有往response内塞入内容
       if content === false && response->getContent() === "" && !response->isSend(){
           return response->send();
       }
       let beforeBuffer = ob_get_clean();   //缓冲区内获得echo出来的数据
       if beforeBuffer {
           if !response->getContent()  {
               response->setContent(beforeBuffer);
           }else{
               response->appendContent(beforeBuffer);
           }
       }
       var condition1,condition2,condition3;
       //判断逻辑之前是否发送过内容
       if !response->isSend() {
           let hasContent = response->getContent();
           let hasHeader = response->hasHeader();
           let condition1 = !hasContent && !hasHeader;//条件1:内容为空 没有头信息
           let condition2 = hasContent && !hasHeader; //条件2:内容不为空 头信息为空
           let condition3 = !hasContent && hasHeader;//条件3:内容为空 头信息不为空
           if condition1 {
              if content === null {
                  let content = this->_controllerInstance->display(this->moduleName,this->controllerName,this->actionName);
                  response->setStatusCode(200);
                  response->setContent(content);
              }else{
                  response->setContent(content);
              }
          } elseif condition2 || condition3 {
               if content === null {
                   let content = this->_controllerInstance->display(this->moduleName,this->controllerName,this->actionName);  //直接调用controllerInstance实例
                   response->appendContent(content);
               }else{
                   response->appendContent(content);
               }
               response->setStatusCode(200);
           }
           ob_start();
           return response->send();
       }else{
           return response->getContent();   //直接将保存的内容返回给application
       }
   }

   //加载处理模块信息
   private function loadModuleByName(array module,string! name){
            var moduleClass;
            if !isset module["className"] || !isset module["path"] {
                 throw new RunTimeException("registerModule参数结构错误：['模块名'=>['className'=>'模块名',‘path’=>'要载入的文件名']]");
            }
            let module["path"] = this->ioc->get("alias")->{"resolve"}(module["path"]);
            if !file_exists(module["path"]) {
                throw new RunTimeException("registerModule错误：".name."对应的文件[[".module["path"]."]]不存在");
            }
            if Empty module["className"] {
                throw new RunTimeException("registerModule错误：".name."对应的className不能为空");
            }
            //载入当前module文件
            require module["path"];
            //实例化当前文件
            if !class_exists(module["className"]) {
                throw new RunTimeException("[[".module["className"] . "]] 不存在");
            }
            var className = module["className"];
            let moduleClass = new {className}();
            if  ! (moduleClass instanceof ModuleInterface) {
                 throw new RunTimeException("[[".className. "]] 必须继承Vii\\Interfaces\\ModuleInterface");
            }
            //注册模块自动载入方法
            moduleClass->{"registerAutoloader"}();
            //todo 这里最好处理为按需处理， 当路由分析出来对应的模块 从这里拿到载入办法
            moduleClass->registerServices(<IocInterface> this->ioc);   //传入ioc
   }
}
