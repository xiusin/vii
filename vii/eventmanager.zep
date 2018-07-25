namespace Vii;

use Vii\Interfaces\EventManagerInterface;
use Vii\Interfaces\IocInterface;
use Vii\Ioc;
use Vii\Exceptions\EventException;
use SplPriorityQueue;  //spl优先级队列

class EventManager implements EventManagerInterface
{
    //全局服务容器
    protected _ioc;
    //注册的事件容器
    protected _events = [];
    //是否开启返回值收集
    protected _collect = false ;
    //是否启用优先级队列
    protected _priority = false;
    //返回值收集容器
    protected _responses;

    public function __construct(<IocInterface> ioc = null) {
        if !ioc {
            let this->_ioc = Ioc::getDefault();
        }else {
            let this->_ioc = ioc;
        }
    }

    /**
     * 设置是否启用优先级
     */
    public function setPriorityState(boolean! priority){
        let this->_priority = priority;
        return this;
    }

    /**
     * 是否收集每个事件的返回值
     */
    public function collectResponses(boolean! collect){
        let this->_collect = collect;
        return this;
    }

    /**
     * 附上一个侦听者
     * @param eventType string 事件类型 可以多个使用同一个
     * @param handler object 事件处理对象 闭包函数
     * @param priority int 处理优先级
     */
    public function attach(string! eventType, object handler,int priority = 100){
        var priorityQueue;
        if this->_priority {
            let priorityQueue = new SplPriorityQueue(); //设置优先队列
            priorityQueue->setExtractFlags(\SplPriorityQueue::EXTR_DATA);   //取值类型
            priorityQueue->insert(new Event(handler,priority),priority);    //插入队列
        }else{
            let priorityQueue = [];
            let priorityQueue[] = new Event(handler,priority);
            let this->_events[eventType] = priorityQueue;
        }
    }

    /**
     * 注销eventType下的所有事件
     */
    public function detachAll(string! eventType = null){
        if !eventType {
            let this->_events = [];
        }else{
            if !this->hasListener(eventType) {
                throw new EventException("事件类型:".eventType."没有被注册");
            }
            unset(this->_events[eventType]);
        }
    }

    /**
     * 返回收集事件信息的状态
     */
    public function iscollect(){
        return this->_collect;
    }

    /**
     * 返回事件收集的信息
     */
    public function getResponses(){
        return this->_responses;
    }

    /**
     * 检查监听器是否存在
     * @param eventType string 事件类型
     */
    public function hasListener(string! eventType){
        return isset(this->_events[eventType]);
    }

    /**
     * 获取监听事件
     * @param eventType string 事件类型
     */
    public function getListener(string! eventType){
        if !this->hasListener(eventType) {
            return [];
        }else{
            return this->_events[eventType];
        }
    }

    /**
     * 触发监听
     * @param eventType string 事件类型
     * @param source
     */
    public function fire(string! eventType, source, data = null, boolean cancelable = true){

    }
}
