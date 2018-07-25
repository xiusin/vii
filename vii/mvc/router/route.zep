namespace Vii\Mvc\Router;
use Vii\Exceptions\RouterException;
class Route
{
    private _methods;
    private pattern = "";
    private compilePattern = "";
    private path = [];
    private name = "";
    private match = null;
    private beforeMatch = null;
    private defaultMatchMap = [ //默认的字符替换匹配
        "/:module" : "/([a-zA-Z0-9_-]+)",
        "/:controller": "/([a-zA-Z0-9_-]+)",
        "/:action" : "/([a-zA-Z0-9_]+)",
        "/:params" : "(/.*)*",
        "/:namespace" : "/([a-zA-Z0-9_-]+)",
        "/:int" : "/([0-9]+)"
    ];

    public function __construct(string! pattern,paths=null,httpMethods=null){
        this->compilePattern(pattern,paths);
        if httpMethods != null {
            let this->_methods = httpMethods;
        }
    }

    //设置路由地址
    private function compilePattern(string! pattern,paths = null){
        let this->pattern = pattern;
        var routepath = this->getRoutePath(paths);
        let this->path = routepath;
        //解析pattern表达式
        //todo 先不支持 {year:\d{4}} 的模式
        //替换内置占位符 如:int :controller等
        let this->compilePattern = str_replace(array_keys(this->defaultMatchMap),array_values(this->defaultMatchMap),pattern);
        //检测是不是包含正则表达式所需要的字符
        if  memstr(this->compilePattern,"(") || memstr(this->compilePattern,"[") {
            let this->compilePattern = "#^".this->compilePattern."$#u"; //编译表达式改为正则
        }
    }

    public function via(array! httpMethods){
        let this->_methods = httpMethods;
        return this;
    }

    public function setName(string! name){
        let this->name = name;
        return this;
    }

    public function getName(){
        return this->name;
    }

    //匹配到结果时调用
    public function match(callback){
        let this->match = callback;
        return this;
    }

    public function getMatch() -> callable
	{
		return this->match;
	}

    public function getPattern() -> string
	{
		return this->pattern;
	}

    public function getMethods(){
        return this->_methods;
    }

    public function getCompiledPattern() -> string
	{
		return this->compilePattern;
	}

	/**
	 * Returns the paths
	 */
	public function getPaths() -> array
	{
		return this->path;
	}

    private function getRoutePath(paths = null ){
        var controllerInfo = [];
        if paths === null {
            return [];
        }
        if typeof paths === "string" {
            var module = null,
            controller=null,
            action = null;
            if stripos(paths, "::") === false {
                throw new RouterException("添加路由的第二个参数为字符串时必须含有 '::' ");
            }
            var parts = explode("::",paths);
            switch count(parts) {
                case 3:
                    let module = parts[0],
                     controller = parts[1],
                     action = parts[2];
                    break;
                case 2:
                    let controller = parts[0],
                     action  = parts[1];
                    break;
                case 1:
                    let controller = parts[0];
                    break;
            }
            var routePaths = [];
            let routePaths["params"] = [];
            if module != null {
                let routePaths["module"] = module;
            }
            if action != null {
                let routePaths["action"] = action;
            }
            if controller != null { //"\a\b\c::a"
                if stripos(controller,"\\") === false {
                    let routePaths["controller"] = controller;
                }else{
                    let controllerInfo = explode("\\",controller);
                    let routePaths["controller"] = controllerInfo[count(controllerInfo) - 1];
                    unset controllerInfo[count(controllerInfo) - 1];
                    let routePaths["namespace"] = implode("\\",controllerInfo);
                }
            }
            return routePaths;
        }else {
            return paths;
        }
    }

    public function setBeforeMatch(callback){
        let this->beforeMatch = callback;
        return this;
    }

    public function getBeforeMatch(){
        return this->beforeMatch;
    }

}
