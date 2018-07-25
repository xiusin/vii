namespace Vii;
use  Vii\Mvc\Router;
use  Vii\Mvc\View;
use  Vii\Interfaces\IocInterface;
class IocDefault extends Ioc
{
   public function __construct()
   {
       parent::__construct();
       var iocs,serverKey,iocValue;
       let iocs = [
           "assets"       : "Vii\\Assets\\Manager",
           "urlManager"   : "Vii\\UrlManager",
           "cookie"       : "Vii\\Cookie",
           "request"      : "Vii\\Request",
           "response"     : "Vii\\Response",
           "dispatcher"   : (new Dispatcher)->setIoc(<IocInterface> this),
           "router"       : (new Router)->setIoc(<IocInterface> this),
           "view"         : (new View)->setIoc(<IocInterface> this),
           "dump"         : "Vii\\Dump",
           "alias"        : "Vii\\Alias",
           "filesystem"   : "Vii\\FileSystem"
       ];
       for serverKey,iocValue in iocs {
           this->set(serverKey,iocValue);
       }
   }
}
