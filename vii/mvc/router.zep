namespace Vii\Mvc;
use Vii\Interfaces\IocInterface;
use Vii\Mvc\Router\Route;
use Vii\Helper;
class Router implements IocInterface
{
    private ioc = null;
    private routes = [];
    private namespaceName;
    private moduleName;
    private controllerName;
    private actionName;
    private defaultNamespaceName;
    private defaultModuleName;
    private defaultControllerName;
    private defaultActionName;
    private _group ;
    private _notFound;
    private matchedRoute;
    private _params = [];
    private _wasMatched = false;
    private _uriSource;

    public function setIoc(_ioc){
        let this->ioc = _ioc;
        return this;
    }
    public function getIoc(){
        return this->ioc;
    }
    public function __construct(bool! hasDefaultRouter  = true){
        if hasDefaultRouter {
            let this->routes[] = new Route("/([\\w0-9\\_\\-]+)[/]{0,1}",[
                "controller":1
            ]);
            let this->routes[] = new Route("/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*",[
				"controller": 1,
				"action": 2,
				"params": 3
			]);
        }
    }

    //添加路由
    public function add(string! pattren,var path){
            var _route ;
            let _route = new Route(pattren,path);
            let this->routes[] = _route;
            return _route;
    }

    //开始处理函数    传入pathinfo
    public function handle(string! url)
    {
        var v,
        paths,
        methods = null,
        matches, //本轮匹配数据容器
        matchMethod,    //匹配回调函数
        beforeMatch,    //匹配前回调函数
        pattren;
        //翻转路由注册数组，防止解析时被默认的给拦截
        for v in reverse this->routes {
            let matches = null,pattren = v->getCompiledPattern();   //必须得先把matches初始化,否则一直报错 fack;
            //echo "pattren:",pattren . "\n";
            if memstr(pattren, "^") {   //检测是否需要正则验证
				let this->_wasMatched = preg_match(pattren,url,matches);
			} else {
				let this->_wasMatched = pattren == url;
			}
            //本轮无法匹配路由
            if !this->_wasMatched {
                continue;
            }else{
                //可以匹配对应的数据
                let matchMethod = v->getMatch();
                let methods = v->getMethods();
                if methods !== null {       //设置方法限制
                   if !in_array(Helper::getHttpMethod(),methods) {
                       continue;    //方法不适合
                   }
                }
                let beforeMatch = v->getBeforeMatch();
                if  is_callable(beforeMatch) && !call_user_func_array(beforeMatch,[url,this]) { //如果前置匹配不能合适则寻找下一个
                    continue;
                }
                if matchMethod != null && is_callable(matchMethod) {
                    call_user_func_array(matchMethod); //执行一次此函数
                }
                //都验证通过了
                let this->matchedRoute = v; //设置匹配的路由对象
                //从匹配的路由对象中获取paths;
                if !Empty matches {
                    var k,params;
                    let paths = v->getPaths();
                    for k,params in paths {
                        switch k {
                            case "controller":
                                let this->controllerName = is_numeric(params) ? matches[params] : params;
                                break;
                            case "action":
                                let this->actionName = is_numeric(params) ? matches[params] : params;
                                break;
                            case "module":
                                let this->moduleName = is_numeric(params) ? matches[params] : params;
                                break;
                            case "namespace":
                                let this->namespaceName = is_numeric(params) ? matches[params] : params;
                                break;
                            case "params":
                                if is_numeric(params) &&  isset matches[params] {
                                    let this->_params = explode("/",trim(matches[params],"/"));
                                }else{
                                    let this->_params = [] ;
                                }
                                break;
                        }
                    }
                }
                break;
            }
        }

        if !this->namespaceName {
            let this->namespaceName = this->defaultNamespaceName;
        }
        if !this->moduleName {
            let this->moduleName = this->defaultModuleName;
        }
        if !this->controllerName {
            let this->controllerName = this->defaultControllerName;
        }
        if !this->actionName {
            let this->actionName = this->defaultActionName;
        }
        if !this->_params {
            let this->_params = [];
        }
    }

    public function addGet(string! pattren,path){
        this->add(pattren,path)->via(["get"]);
    }

    public function addPost(string! pattren,path){
        this->add(pattren,path)->via(["post"]);
    }

    public function setDefaultModule (string moduleName){
        let this->defaultModuleName = moduleName;
        return this;
    }

    public function getDefaultModule (){
        return this->defaultModuleName;
    }

    public function setDefaultNamespace (string namespaceName) {
        let this->defaultNamespaceName = namespaceName;
        return this;
    }

    public function setDefaultController (string controllerName) {
        let this->defaultControllerName = controllerName;
        return this;
    }

    public function setDefaultAction (string actionName){
        let this->defaultActionName = actionName;
        return this;
    }

    public function getModuleName (){
        return this->moduleName;
    }

    public function getNamespaceName  (){
        return this->namespaceName;
    }

    public function getControllerName  (){
        return this->controllerName;
    }

    public function getActionName  (){
        return this->actionName;
    }

    public function getParams() -> array
    {
        return  this->_params;
    }

    public function wasMatched () ->bool
    {
        return this->_wasMatched;
    }

    public function getRoutes () -> array
    {
        return this->routes;
    }

    public function getMatchedRoute(){
        return this->matchedRoute;
    }

    public function setNotFound(callback){
        let this->_notFound = callback; //设置notFound;
    }

    public function getNotFound(){
        return this->_notFound;
    }

    public function getMatches()->array
    {
        return [
            "namespace" : this->namespaceName,
            "module" : this->moduleName,
            "controller" : this->controllerName,
            "action" : this->actionName,
            "params" : this->getParams()
        ];
    }
}
