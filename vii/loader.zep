namespace Vii;
use Vii\Interfaces\LoaderInterface;
use Vii\Interfaces\IocInterface;
use Vii\Exceptions\FileNotExistsException;
use Vii\Exceptions\LoaderException;
use Vii\Exceptions\RunTimeException;
use Vii\Ioc;
class Loader implements LoaderInterface,IocInterface
{
        protected  registerNamespaces = [];
        protected  classmap  = [];
        protected  registerDirs  = [];
        protected  registerPrefixes  = [];
        protected  cachefile ;
        protected  ioc;

        /**
         * 构造函数
         */
        public function __construct(classFileName = null)
        {
           this->setClassMapFile(classFileName);
        }

        /**
         * 设置Ioc
         */
        public function setIoc(_ioc){
            let this->ioc = _ioc;
        }

        /**
         * 获取Ioc
         */
        public function getIoc(){
            if !this->ioc {
                this->setIoc(Ioc::getDefault());
            }
            return this->ioc;
        }

        /**
         * 注册类名映射缓存地址
         */
        public function setClassMapFile(classFileName = null){
            let classFileName = classFileName ? classFileName :  "classmap.php";
            let this->cachefile = classFileName;
        }

        /**
         * 注册名称空间
         * @param $namespace
         * @demo array('namespace'=>'dirs')
         */
        public function registerNamespaces(array! namespaceName)
        {
            let this->registerNamespaces = array_merge(this->registerNamespaces, namespaceName);
            return this;
        }


        /**
         * 注册类名
         * @param array $array
         * @demo array('namespace\classname'=>'dirs/classfile','class'=>'dir/classfile')
         */
        public function registerClass(array! classArr)
        {
            let this->classmap = array_merge(this->classmap, classArr);
            return this;
        }

        /**
         * @method 监听自动注册
         * @param $className  string 自动加载类名称
         */
        public function register()
        {
            spl_autoload_register([this, "registerAutoload"]);         //注册自动加载函数
        }

        /**
         * 注册自动载入
         */
        public function registerAutoload(string! className){
            var fileName,info,controller_name,
            noNamespaceName = false,//默认视为含有命名空间
            onlyClassName,  //提取出来的不包含命名空间的方法
            classNamespace,
            dirkeys;
            //直接查看是否已经直接注册过该方法 即 registerClass 包括已经记录的映射关系
            if array_key_exists(className, this->getMap()) {
                //从映射中获取对应的文件进行加载
                let fileName = this->classmap[className];
                return this->loadFile(fileName, className);
            }
            //检测需要自动加载的className是否包含命名空间
            //检测在方法前缀是否可以找到文件
            if !memstr(className,"\\"){
                let noNamespaceName = true;   //不包含命名空间
                let onlyClassName = className;
            }

            //检测是不是命名空间中是否含有
            let info = explode("\\", className);  //Slothful\Mvc\Controller
            let controller_name = end(info);            //Controller
            array_pop(info);
            let classNamespace = implode("\\", info);
            if array_key_exists(classNamespace, this->registerNamespaces) { //加载注册的命名空间
                let fileName = rtrim(this->registerNamespaces[classNamespace], "/") . "/" . controller_name . ".php";
                return this->loadFile(fileName, className);
            }

            //扫描注册的文件夹下是否可以载入
            if noNamespaceName {
                for dirkeys in this->registerDirs {
                    let fileName = rtrim(dirkeys, "/") . "/" . onlyClassName .".php";
                    if file_exists(fileName) {
                        return this->loadFile(fileName, className);
                    }
                }
            }
        }

        /**
         * 载入文件 并且记录映射关系
         * @param $filename  string 载入文件的方式
         * @param $className string 名称
         */
        protected function loadFile(string! filename,  className = "")
        {
            var result;
            let filename = this->getIoc()->get("alias")->{"resolve"}(filename);
            if !file_exists(filename) {
                throw new FileNotExistsException("file [" . filename . "] not exists");
            }
            let result = require(filename);
            if (result && !empty(className)){
                 this->saveMap(className,filename);
            }
            return result;
        }

        /**
         * 注册自动载入目录,注册的目录为自动扫描的目录
         * @param $dir_str array|string
         * @demo registerDirs(['a','b','c']);
         * @demo new Demo(); a/demo.php loaded
         */
        public function registerDirs(dir_str)
        {
            if typeof dir_str != "array" {
                let dir_str = [dir_str];
            }
            let this->registerDirs = array_merge(this->registerDirs, dir_str);
            return this;
        }


        // /**
        //  * 注册类库载入前缀，只接受不包含命名空间的类名
        //  * @demo registerPrefixes(['A_b_c'=>'a/b/c']);
        //  * @demo new A_b_c_Demo();
        //  */
        // public function registerPrefixes(arr)
        // {
        //     if typeof arr != "array" {
        //         let arr = [arr];
        //     }
        //     let this->registerPrefixes = array_merge(this->registerPrefixes, arr);
        //     return this;
        // }

        /**
         * 获取注册的命名空间
         */
        public function getNamespaces()
        {
            return this->registerNamespaces;
        }


        /**
         * 保存匹配到的文件
         */
        protected function saveMap(string! className, string! filePath)
        {
            let this->classmap[className] = filePath;
        }

        /**
         * 获取最终的class映射
         */
        protected function getMap()
        {
            if file_exists(this->cachefile) {
                let this->classmap = array_merge(this->classmap, require this->cachefile);
            }
            return this->classmap;
        }
}
