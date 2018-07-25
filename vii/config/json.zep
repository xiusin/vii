namespace Vii\Config;
use Vii\Config;
use Vii\Exceptions\ConfigException;
class Json extends Config
{
    public function __construct(string! jsonFile){
        if !file_exists(jsonFile){
            throw new ConfigException("Json config file is not exists!");
        }
        parent::__construct(json_decode(file_get_contents(jsonFile),true));
    }
}
