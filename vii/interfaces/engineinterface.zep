namespace Vii\Interfaces;
interface EngineInterface
{
    public function __construct(<ViewInterface> view, <IocInterface> ioc = NULL);
	public function render(string! path, array data = []);
}
