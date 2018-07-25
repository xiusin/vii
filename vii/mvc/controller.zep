namespace Vii\Mvc;
use Vii\Exceptions\IocException;
use Vii\Interfaces\IocInterface;
class Controller implements IocInterface
{
    public  ioc;

    public function __construct (){
        if method_exists(this, "initialize") {
            this->{"initialize"}();
        }
    }

   //需要重写模板的时候就重写此方法，此方法为自动调用如果要拦截自动渲染可以再控制器内返回false
   //固定传参数 模块名称，控制器名称，方法名称 根据需要使用
   public function display(module,controller,action) -> string
   {
       var view;
       let view = this->ioc->get("view");
       return view->render(controller . "/" . action,view->getVars());    //默认渲染
   }

   /**
    * 跳转到根目录
    */
   public function goHome(){
       this->redirect();
   }

   /**
    * 重定向 利用response
    */
   public function redirect(){

   }

   public function __get(string! name)
   {
        return this->ioc->get(name);
   }

   public function setIoc (_ioc)
   {
       let this->ioc = _ioc;
       return this;
   }

   public function getIoc ()
   {
       return this->ioc;
   }
}
