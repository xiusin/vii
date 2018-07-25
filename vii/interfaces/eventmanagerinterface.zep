namespace Vii\Interfaces;
interface EventManagerInterface
{
    public function __construct(<IocInterface> ioc);
    public function attach(string! eventType, object handler,int priority = 100);
    public function detachAll(string! eventType = null);
    public function fire(string! eventType, source, data = null, boolean cancelable = true);
    public function getListener(string! eventType);
    public function hasListener(string! eventType);
}
