namespace Vii\Session\Adapter;
use Vii\Session\NativeSession;
use Vii\Exceptions\RunTimeException;
class Memcache extends NativeSession implements \SessionHandlerInterface
{
    private _memcache;
    private _maxlifetime = 3600;   //最大的有效时间
    public function __construct(array! options = [])
    {
        if !extension_loaded("memcache") {
            throw new RunTimeException("必须安装php-memcached扩展");
        }
        let this->_memcache = new \Memcache();
        //一次性配置多台服务器
        if isset options["servers"] {
            this->addServers(options["servers"]);
        }
        //配置一台服务器
        if isset options["server"] {
            var server;
            let server = options["server"];
            if typeof server != "array" || !isset server["host"] || !isset server["port"] {
                throw new RunTimeException("配置Session::Memcache参数server必须为数组并且包括host和port");
            }
            this->addServer(server["host"],server["port"]);
        }
        session_set_save_handler(
			[this, "open"],
			[this, "close"],
			[this, "read"],
			[this, "write"],
			[this, "destroy"],
			[this, "gc"]
		);
        parent::__construct(options);
    }


    public function addServer(string! ip,int port){
        this->_memcache->addServer(ip,port);
    }

    /**
     * 一次性添加多台服务器
     */
    public function addServers(array! servers){
        var server = [];
        for _,server in servers {
            this->_memcache->addServer(server["host"],server["port"]);
        }
    }

    public function open(string save_path , string session_name){
        return true;
    }

    public function read(string! session_id){
        return (string) this->_memcache->get(session_id);
    }

    public function write(string! session_id,string! session_data){
        //每次自动写入的时候覆盖之前的值
        this->_memcache->set(session_id,session_data,false,this->_maxlifetime);
    }

    public function destroy(string session_id = null){
        var sessionid;
        if !session_id {
            let sessionid = this->getId();
        }else{
            let sessionid = session_id;
        }
        //如果memcache内没有保存过值，则获取的值===false
        if this->_memcache->get(sessionid) !== false {
            this->_memcache->delete(sessionid);
        }
        return true;
    }

    public function gc(int maxlifetime){
        return true;
    }

    public function close(){
        return true;
    }
}
