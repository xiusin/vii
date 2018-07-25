namespace Vii;

class Event {
    protected handlerFun;
    protected priority = 100;
    public function __construct(var handlerFun,int priority = 100){
        let this->handlerFun = handlerFun;
        let this->priority = priority;
    }
}
