namespace Vii; //定义命名空间
use Vii\Interfaces\ConfigInterface;
use Vii\Exceptions\ConfigException;
//接收数组对象
class Config implements ConfigInterface
{
    public function __construct(array! config)
    {
        var key,value;
        for key, value in config {
            this->isValidKey(key);
            if !is_array(value) {
                let this->{key} = value;
            } else {
                let this->{key} = new Config(value);
            }
        }
    }

    public function merge(<ConfigInterface> config)
    {
        var key,value,configArr;
        let configArr = Helper::obj2arr(config);
        for key,value in configArr {
           this->isValidKey("" . key);
           if typeof this->{key} == "object" && typeof value == "object" {
                this->{key}->merge(value);
           }else{
                let this->{key} = value;
           }
        }
    }

    private function isValidKey(key)
    {
        if !preg_match("/^[a-z_A-Z][a-z_A-Z0-9]+/",key) {
            throw new ConfigException("the config key ".key." is valid key , must string");
        }
    }

    public function toArray()->array
    {
        var config,key,value;
        let config = (array) this;
        for key,value in config {
            if typeof value == "object" || is_array(value) {
                let config[key] = (array) value->toArray();
            }
        }
        return config;
    }
}
