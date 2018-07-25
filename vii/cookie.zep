namespace Vii;
class Cookie
{
    protected domain = "";
    protected salt = "";
    protected isuse = false;

    public function __construct(domain = "", salt = "vii_cookie_encodekey")
    {
        let this->domain = domain;
        let this->salt = salt;
    }

    public function encryption(_string, aciton = "ENCODE")
    {
        var code = "", k,i = 0;
        if aciton != "ENCODE" {
            let _string = base64_decode(_string);
        }
        var keylen = strlen(this->salt);
        var _strlen = strlen(_string);
        for i in range(0,_strlen) {
            let k = i % keylen;
            let code = code . _string[i] ^ this->salt[k];
        }
        return (aciton != "DECODE" ? base64_encode(code) : code);
    }

    public function useEncryption(isuse = false)
    {
        let this->isuse = isuse;
    }

    public function set(key, value, _time = 0)
    {
        setcookie(key, this->setValue(value), _time, this->domain);
    }

    protected function setValue(value)
    {
        if this->isuse {
            return this->encryption(value, "ENCODE");
        }
        return value;
    }

    public function get(key, _default = "")
    {
        if !isset(_COOKIE[key]) {
            return _default;
        }
        return this->getValue(_COOKIE[key]);
    }

    public function getValue($value)
    {
        if this->isuse {
            return this->encryption(value, "DECODE");
        }
        return value;
    }


    public function clear()
    {
        var k;
        for k,_ in _COOKIE {
            this->del(k);
        }
        return this;
    }

    public function flashGet(key, _default)
    {
        var result = this->get(key, _default);
        this->del(key);
        return result;
    }

    public function del(key)
    {
        setcookie(key, null, time() - 3600);
        unset(_COOKIE[key]);
    }

}
