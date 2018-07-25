namespace Vii\Interfaces;
use Vii\Interfaces\IocInterface;
interface ModuleInterface
{
    public function registerServices(<IocInterface> _ioc);
    public function registerAutoloader();
}
