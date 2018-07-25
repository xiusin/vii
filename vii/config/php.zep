
namespace Vii\Config;
use Vii\Config;
use Vii\Exceptions\ConfigException;
class Php extends Config
{
    public function __construct(string! phpFile){
        if !file_exists(phpFile){
            throw new ConfigException("Php config file is not exists!");
        }
        parent::__construct(require phpFile);
    }
}
