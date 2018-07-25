
namespace Vii;

use Vii\Exceptions\HttpException;
use Vii\Interfaces\IocInterface;
use Vii\Exceptions\RunTimeException;
class Request implements IocInterface
{
    private method = "GET";
    protected cookie;
    private file;
    //SERVER变量
    private static server = [];

    //构造函数
    public function __construct()
    {
         let this->method = this->server("REQUEST_METHOD");
         let this->file = _FILES;
    }

    public function setIoc(_ioc){
        let this->cookie = _ioc->get("cookie");
    }
    public function getIoc(){
      
    }

    //获取服务请求
    private function server(key, _default = "")
    {
        return isset _SERVER[key] ? _SERVER[key] : _default;
    }

    //获取请求方式
    public function getReferer()
    {
        return this->server("HTTP_REFERER");
    }

    //获取cookie
    public function getCookie(key, _default = null)
    {
        return this->cookie->get(key, _default);
    }

    //设置cookie
    public function setCookie(key, value, _time = "")
    {
        this->cookie->set(key, value, _time);
        return this;
    }

    //获取请求方法
    public function getMethod()
    {
        return this->method;
    }

    //获取闪存cookie
    public function flashCookie(key, _default = "")
    {
        return this->cookie->flashGet(key, _default);
    }

    //获取客户机IP
    public function clientIp()
    {
        var ip;
        if getenv("HTTP_CLIENT_IP") {
            let ip = getenv("HTTP_CLIENT_IP");
        } elseif (getenv("HTTP_X_FORWARDED_FOR")) {
            let ip = getenv("HTTP_X_FORWARDED_FOR");
        } elseif (getenv("REMOTE_ADDR")) {
            let ip = getenv("REMOTE_ADDR");
        } else {
            let ip = false;
        }
        return ip;
    }

    //获取请求时间
    public function getRequestTime()
    {
        return this->server("REQUEST_TIME");
    }
    public function isweixin()
    {
        return false !== strpos(this->server("HTTP_USER_AGENT"), "MicroMessenger");
    }

    public function pathinfo()
    {
        return this->server("PATH_INFO");
    }

    public function getPost(key = "", def = "", filter = "")
    {
        return this->_get_post(key, def, filter, 1);
    }

    public function get(key = "", def = "", filter = "")
    {
        return this->_get_post(key, def, filter, 0);
    }

    protected function _get_post(key = "", def = "", filter = "", type)
    {
        var data;
        if type == 0 {
            let data = _GET;
        }else{
            let data =  _POST;
        }
        if empty(key) {
            return data;
        }
        if key {
            if isset data[key] {
                if !Empty filter {
                    if !is_callable(filter) {
                        throw new RunTimeException(filter . " can not callable");
                    }
                    return {filter}(data[key]);
                } else {
                    return data[key];
                }
            } else {
                return def;
            }
        }
    }

    public function hasFiles()
    {
        if this->file && count(this->file) {
            return true;
        }
        return false;
    }

    public function getUploadedFiles(only_success = false)
    {
        var files = [],v;
        for v in this->file  {
            if only_success && v["error"] != "" {
                continue;
            }
            let files[] = new UploadFileInfo(v);
        }
        return files;
    }

}
