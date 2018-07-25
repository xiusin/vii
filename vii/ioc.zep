namespace Vii;
use Vii\Exceptions\IocException;
use Vii\Interfaces\IocInterface;
/**
 * 简单的实现了依赖注入的功能
 * 思想 : 根据依赖注入的值来判定需要放入的容器
 * 参见 : Phalcon的依赖注入
 * 服务定位现在没搞明白 啧啧
 */
class Ioc implements IocInterface,\ArrayAccess,\Countable
{
    //全局静态获取所有服务
    protected static _default = null;
    //已经被实例化的服务
    protected _instance = [];
    //未被实例化的服务
    protected container = [];
    public function __construct(){
        if !self::_default {
            let self::_default = this;
        }
    }
    /**
     * 设置服务
     */
    public function set(string! name, value)
    {
        if this->has(name) {
            throw new IocException("the name : ".name." has exists");
        }
        if typeof value == "string" {
           let this->container[name] = value;
        } elseif typeof value == "array" {
            if !isset(value["className"]) { //不存在className属性
                throw new IocException("Ioc::set param 2 must have className");
            }
            if isset(value["arguments"]) && typeof value["arguments"] != "array" {
                throw new IocException("Ioc::set arguments must be array");
            }
           let this->container[name] = value;
        } elseif typeof value == "object" {
            let this->container[name] = value;  //直接传入new的方式或者闭包
        }else{
            throw new IocException("Ioc::set value is not support");
        }
        return this;
    }

    /**
     * 获取服务实例
     * @name string 服务名称
     */
    public function get(string! name)
    {
        var _ioc,_className;
        if !this->has(name) {
            throw new IocException("服务:".name."未注册");
        }
        if !isset this->_instance[name]  {  //没有实例化就先实例化数据
            let _ioc = this->container[name];
            if typeof _ioc == "string" {
                 let this->_instance[name] = new {_ioc}();
            } elseif typeof _ioc == "array" {
                let _className = _ioc["className"];
                if isset _ioc["arguments"]  {
                     let this->_instance[name] = (new \ReflectionClass(_className))->newInstanceArgs(_ioc["arguments"]);
                }else{
                     let this->_instance[name] = new {_className}();
                }
            } elseif typeof _ioc == "object" {
                    if _ioc instanceof \Closure  {
                        let this->_instance[name] = call_user_func_array(_ioc,[]);
                    }else{
                        let this->_instance[name] = _ioc;
                    }
            }
            unset(this->container[name]);
        }
        return this->_instance[name];
    }

    /**
     * 检测服务是否已经被注册
     */
    public function has(string name) -> bool
    {
        if !isset this->container[name] && !isset this->_instance[name] {
            return false;
        }
        return true;
    }

    /**
     * 重新定义服务
     */
    public function setDefinition(string name,value){
        this->del(name);
        this->set(name,value);
    }

    /**
     * 注销已经定义的服务
     */
    public function del(string! name){
        if !this->has(name) {
            return null;
        }
        if (isset this->container[name]){
            unset (this->container[name]);
        }
        if(isset this->_instance[name]) {
            unset (this->_instance[name]);
        }
    }

    /**
     * 静态获取已经注册的服务
     */
    public static function getDefault(){
        return self::_default;
    }

    public function __get(key){
        return this->get(key);
    }

    public function __unset(key){
        this->del(key);
    }

    public function offsetExists (offset) {
        return this->has(offset);
    }

    public function offsetGet (offset)
    {
         return this->get(offset);
    }

    public function offsetSet(offset,value) {
         this->set(offset,value);
    }

    public function offsetUnset (offset) {
          this->del(offset);
    }

    public function setIoc(_ioc){}

    public function getIoc(){}
    /**
     * 统计服务个数
     */
    public function count()
    {
        return count(this->_instance) + count(this->container);
    }

}
