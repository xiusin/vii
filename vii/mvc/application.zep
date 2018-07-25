namespace Vii\Mvc;
use Vii\Interfaces\IocInterface;
use Vii\Interfaces\ApplicationInterface;
use Vii\Interfaces\IocInterface;
use Vii\Exceptions\FileNotExistsException;
use Vii\Exceptions\RunTimeException;
class Application implements ApplicationInterface,IocInterface
{
    protected ioc = null;
    public debug = false;
    public _module = [];
    const VERSION = "DEV 0.1";

    /**
     *  @param ioc IocInterface 全局Ioc容器
     *  @param composerAutoLoadFile 传入的composer管理位置
     */
    public function __construct(<IocInterface> ioc,string composerAutoLoadFile = "")
    {
        let this->ioc = ioc;
        this->ioc->get("loader")->register();
        //动态加载
        if file_exists(composerAutoLoadFile) {
            require composerAutoLoadFile;
        }
    }

    /**
     * 调试开关
     * @param debug bool 状态
     * @return Application
     */
    public function debug(bool! debug){
        let this->debug = debug;
        return this;
    }

    /**
     * 程序执行入口
     * @return string | Exception | RunTimeException | void
     */
    public function handle()
    {
        var e,notFound;
        ob_start();
        try{
            return this->ioc->get("dispatcher")->setApp(this)->dispatch();
        }catch \Exception , e {
            if this->debug {
                throw new \RunTimeException(e->getMessage());   //todo 記錄成日誌
            } else {
                let notFound = this->ioc->get("router")->getNotFound();
                if is_null(notFound) { //检测是否设置了notFound方法
                    throw new \RunTimeException(e->getMessage());   //todo 記錄成日誌
                }else{
                    if notFound instanceof \Closure {
                        {notFound}();
                    }else{
                        throw new \RunTimeException(e->getMessage());
                    }
                }
            }
        }
    }

    /**
     * 初始化启动文件方法 一般用于注册服务或其他判断
     * @param filename string 要初始化加载的Bootstrap类文件
     * @return ApplicationInterface | Application
     */
    public function bootstrap(string! filename) -> <ApplicationInterface>
    {
            var bootstrap,methods,bootstrapClass,method,methodName;
            let filename = this->ioc->get("alias")->{"resolve"}(filename);
            if !file_exists(filename) {
                throw new FileNotExistsException("the bootstrap:".filename." file is not exists!");
            }
            //注册bootstrap
            this->ioc->get("loader")->{"registerClass"}(["Bootstrap" : filename]);
            let bootstrap = new \ReflectionClass("Bootstrap");   //反射BootStrap类库
            let methods = bootstrap->getMethods(\ReflectionMethod::IS_PUBLIC);  //过滤
            if !bootstrap->implementsInterface("Vii\\Interfaces\\BootstrapInterface") {//检查是否实现了接口
               throw new RunTimeException("bootstrapClass must implements Vii\\Interfaces\\BootstrapInterface");
            }
            let bootstrapClass = bootstrap->newInstanceArgs([<IocInterface> this->ioc]);
            for method in methods {
                 let methodName = method->getName();
                 if !starts_with(methodName, "init") {
                     continue;
                 }
                 bootstrapClass->{methodName}();
            }
            return this;
    }

    /**
     * 创建基本的模块结构
     * @applicationDirName 应用目录地址
     * @moduleName 应用模块名
     */
    public static function bulidBaseStruct(string applicationDirName,string! moduleName)
    {
        var value,moduleDir;
        let applicationDirName  =  trim(applicationDirName,"/");
        let moduleDir = applicationDirName;
        if moduleName {
            let moduleDir = applicationDirName . "/" . moduleName;
        }
        var new_app = [
            moduleDir . "/views",
            moduleDir . "/controllers" ,
            moduleDir . "/models" ,
            applicationDirName . "/config"
        ];
        for value in new_app {
            if (!is_dir(value)) {
                mkdir(value, 0777, true);
            }
        }
    }

    /**
     * 向应用内注册模块
     * @modules array 要注册的模块信息数组
     */
    public function registerModules(array modules)
    {
        let this->_module = modules;
    }

    /**
     * 根据获取的模块名获取注册的模块信息
     * @param name string 模块名称
     * @return array | RunTimeException
     */
    public function getRegisterModuleByModuleName(string! name) -> array
    {
        if ! isset this->_module[name] {
            throw new RunTimeException(name."模块没有被注册");
        }
        return this->_module[name];
    }

    /**
     * 获取当前注册的模块信息
     */
    public function getRegisterModules(){
        return this->_module;
    }

    public function setIoc(_ioc){
            let this->ioc = _ioc;
    }
    public function getIoc(){
            return this->ioc;
    }
}
