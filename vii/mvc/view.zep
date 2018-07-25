namespace Vii\Mvc;
use Vii\Mvc\View\Engine\Sleet;
use Vii\Interfaces\ViewInterface;
use Vii\Interfaces\IocInterface;
use Vii\Exceptions\ViewException;
class View implements ViewInterface,IocInterface
{
       protected engines { set };
       protected content { set, get };
       protected mainView = "index" { set, get };
       protected layoutsDir = "layouts/" { set, get };
       protected partialsDir = "partials/" { set, get };
       protected viewsDir { set, get };
       protected file { set, get };
       protected silent = false { set };
       protected viewVar = [];
       protected ioc;

       public function setIoc(_ioc){
           let this->ioc = _ioc;
           return this;
       }
       public function getIoc(){
           return this->ioc;
       }

       /**
        * 获取注册的模板引擎
        */
       public function getEngines()
       {
           var ext, engine;

           if !this->engines {
               let this->engines[".sleet"] = new Sleet(<ViewInterface> this,<IocInterface>this->ioc);
           }
           for ext, engine in this->engines {
               if typeof engine == "object" {
                   if engine instanceof \Closure {
                       //传入闭包
                       let this->engines[ext] = call_user_func_array(engine, [<ViewInterface> this,<IocInterface> this->ioc]);
                   }
               } else {
                   if typeof engine == "string" {
                       let this->engines[ext] = create_instance_params(engine, [<ViewInterface> this,<IocInterface> this->ioc]);
                   } else {
                       throw new ViewException(sprintf("不可用的模板引擎：%s", ext));
                   }
               }
           }
           return this->engines;
       }

       /**
        * 通过变量渲染模板
        *
        * @param string 文件名
        * @param array 变量数组
        * @return string
        */
       public function render(file = null, array data = [])
       {
           var ext, engine, engines, path, dir, dirs, exists, content;

           let exists = false,
               content = null;

           if file !== null {
               let this->file = strtolower(file);
           }

           if empty this->file {
               throw new ViewException("渲染模板之前请先设置一个模板");
           }
           //获取所有的模板引擎驱动
           let engines = this->getEngines();

           for ext, engine in engines {
               if typeof this->viewsDir == "array" {
                   let dirs = this->viewsDir;
               } else {
                   let dirs = [this->viewsDir];
               }

               for dir in dirs {
                   let path = dir . this->file . ext;
                   if file_exists(path) {
                       let exists = true;
                       let content = engine->render(path, data);
                       break;
                   }
               }
           }
           if !this->silent && !exists {
               throw new ViewException(sprintf("模板文件 %s 不能被找到", path));
           }
           return content;
       }

       /**
        * 加载模板
        *
        * @param string file 来自模板文件夹的没有扩展名的文件名
        * @param array data 要发送的数据
        * @return string
        */
       public function load(string! file, array data = [])
       {
           return this->render(file, data);
       }

       /**
        * 加载片段
        *
        * @param string file 来自片段文件夹的没有扩展名的文件名
        * @param array data Vars to send
        * @return string
        */
       public function partial(string! file, array data = [])
       {
           return this->render(this->partialsDir . file, data);
       }

       /**
        * 加载布局
        *
        * @param string file 相对于布局文件的布局名称
        * @param array data Vars to send
        * @return string
        */
       public function layout(var file = null, array data = [])
       {
           if !file {
               let file = this->mainView;
           }
           return this->render(this->layoutsDir . file, data);
       }

       /**
        * 设置模板变量
        *
        * @param string name
        * @param mixed value
        */
       public function setVar(string! name, value)
       {
           let this->viewVar[name]  = value;
       }

       /**
        * 一次设置多个变量
        *
        * @param array vars
        */
       public function setVars(array! vars)
       {
           var key,value;
           for key, value in vars {
                this->setVar(key, value);
            }
       }


       public function getVars(){
           return this->viewVar;
       }

       /**
        * 设置布局文件
        * @param array vars
        */
       public function setLayout(string layout)
       {
           this->setMainView(layout);
       }

       public function __toString()
       {
           return this->render();
       }
}
