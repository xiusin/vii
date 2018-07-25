namespace Vii;

class Alias
{
    protected _aliases = [];    //所有别名入口
    /**
     * 设置别名变量
     * @param string name 别名称
     * @param string value 别名值
     * @return void
     */
    public function set(var name,string! value = "") {
        var k,v;
        if typeof name == "array" {
            for k,v in name {
                this->set(k,v);
            }
        }else{
            if !starts_with (name,"@") {
                throw new \Exception("Alias::set 别名必须以 '@' 开始");
            }

            if this->has(name) {
                throw new \Exception("别名: ".name." 已经存在");
            }
            let this->_aliases[name] = value;
        }
    }

    public function has(string! name){
        if isset this->_aliases[name] {
            return true;
        }
        return false;
    }
    //替换别名符号必须以@符号开始
    public function resolve(string! path){
        if !starts_with(path,"@") {
            return path;
        }
        let path = strtr(path,"\\","/");
        var pathinfo,alias;
        let pathinfo = explode("/",path);
        let alias = pathinfo[0];
        if !this->has(alias) {
            throw new \Exception("Alias::resolve 别名:".alias." 没有被设置");
        }
        //递归解析别名替换, 直到全部被解析出来
        return this->resolve(str_replace(alias,this->_aliases[alias],path));
    }
}
