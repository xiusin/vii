namespace Vii\Session;
use Vii\Interfaces\SessionAdapterInterface;
use Vii\Exceptions\RunTimeException;

/**
 * 封装原生SESSION操作,可以将
 */
class NativeSession implements SessionAdapterInterface
{
	const SESSION_ACTIVE = 2;   //会话是启用的，并且已经开启
	const SESSION_NONE = 1; //会话是启用的，但没有开启
	const SESSION_DISABLED = 0; //会话是被禁用的 扩展未安装
	protected _uniqueId;
	protected _started = false;
	protected _options;
	protected _maxlifetime = 86400;

	public function __construct(var options = null)
	{
	    if ini_get("session.auto_start") === "1" {
    		    throw new RunTimeException("Session::__construct 不接受php.ini的配置信息内开启session.auto_start");
    	}
		if typeof options == "array" {
			this->setOptions(options);
		}
	}

	/**
	 * 开启SESSION 需要检测是否已经发送过header避免错误
	 */
	public function start() -> boolean
	{
		if headers_sent() {
		    throw new RunTimeException("Session::start 之前不要进行header头发送信息");
		}
		if !this->_started && this->status() !== self::SESSION_ACTIVE {
			session_start();
			let this->_started = true;
			return true;
		}
		return false;
	}

	/**
	 * 设置session的配置信息
	 * 包括session包的唯一ID
	 */
	public function setOptions(array! options)
	{
		var uniqueId,maxlifetime;
		if fetch uniqueId, options["uniqueId"] {
			let this->_uniqueId = uniqueId;
			unset options["uniqueId"];
		}
		if fetch maxlifetime, options["lifetime"] {
			let this->_maxlifetime = maxlifetime;
			unset options["lifetime"];
		}
		let this->_options = options;
	}

	public function getOptions() -> array
	{
		return this->_options;
	}

	/**
	 * 设置session名称
	 */
	public function setName(string name)
	{
	    session_name(name);
	}

	/**
	 * 获取session名称
	 */
	public function getName() -> string
	{
	    return session_name();
	}

	/**
	 * 重新生成sessionID替换现有sessionid
	 * @deleteOldSession bool 是否要删除以前的session数据
	 */
	public function regenerateId(bool deleteOldSession = true)
	{
		session_regenerate_id(deleteOldSession);
		return this;
	}

    protected function getIndex(var index)->string
    {
        if this->_uniqueId {
            return this->_uniqueId . "." . index;
        }
        return index;
    }

	/**
	 * 获取一个session值
	 * @param index session索引
	 * @param defaultValue any 不存在时需要返回的默认值
	 * @param remove bool 是否获取以后删除该session数据
	 */
	public function get(string index, var defaultValue = null, boolean remove = false) -> var
	{
		var value;
        let index = this->getIndex(index);
		if fetch value, _SESSION[index] {
			if remove {
				unset _SESSION[index];
			}
			return value;
		}
		return defaultValue;
	}

	/**
	 * 设置一个session数据
	 */
	public function set(string index, var value)
	{
		let _SESSION[this->getIndex(index)] = value;
	}

	/**
	 * 检查一个session数据是否已经被设置过
	 */
	public function has(string index) -> boolean
	{
		return isset _SESSION[this->getIndex(index)];
	}

	/**
	 * 删除一个sesion数据
	 */
	public function remove(string index)
	{
		unset _SESSION[this->getIndex(index)];
	}

	/**
	 * 返回活动的sessionid
	 */
	public function getId() -> string
	{
		return session_id();
	}

	/**
	 * 设置当前的sessionid
	 */
	public function setId(string id)
	{
		session_id(id);
	}

	/**
	 * 检查session是否已经开启
	 */
	public function isStarted() -> boolean
	{
		return this->_started;
	}

	/**
	 * 销毁活动的session
	 * @param removeCurrentSessionData bool 是否移除当前活动的session数据
	 */
	public function destroy(boolean removeCurrentSessionData = false) -> boolean
	{
		if removeCurrentSessionData {
			var  key;
			for key, _ in _SESSION {
					unset _SESSION[this->getIndex(key)];
			}
		}
		let this->_started = false;
		return session_destroy();
	}

	/**
	 * 返回当前session的状态
	 */
	public function status() -> int
	{
		var status;
		let status = session_status();
		switch status {
			case PHP_SESSION_DISABLED:
				return self::SESSION_DISABLED;
			case PHP_SESSION_ACTIVE:
				return self::SESSION_ACTIVE;
		}
		return self::SESSION_NONE;
	}

	public function __get(string index) -> var
	{
		return this->get(index);
	}

	public function __set(string index, var value)
	{
		return this->set(index, value);
	}

	public function __isset(string index) -> boolean
	{
		return this->has(index);
	}

	public function __unset(string index)
	{
		return this->remove(index);
	}

	public function __destruct()
	{
		if this->_started {
			session_write_close();
			let this->_started = false;
		}
	}
}
