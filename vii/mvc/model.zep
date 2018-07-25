namespace Vii\Mvc;

use Vii\Ioc;
class Model
{
    protected _source;
    protected _db;
    protected queryBuilder;
    public function __construct(array! fields = []){
        //分析表名称
        if method_exists(this,"getSource"){
            let this->_source = this->{"getSource"}();
        }else{
            var calledClass ;
            let calledClass = get_called_class();
            let this->_source = strtolower(substr(calledClass,strrpos(calledClass,"\\") + 1));
        }
        let this->_db = Ioc::getDefault()->get("db");   //获取操作对象
        let this->queryBuilder = this->_db->createBuilder();
    }

    public function find(var options = []){
        var res;
        this->queryBuilder->from(this->_source);
        if typeof options != "array" {
            this->queryBuilder->where(options);
        }
        if isset options["conditions"] {
            if isset options["bind"] {
                let res = this->queryBuilder->parseWhereArr(options["conditions"],options["bind"]);
            }else{
                let res = this->queryBuilder->parseWhereArr(options["conditions"]);
            }
            this->queryBuilder->where(res[0],res[1]);
        }
        if isset options["limit"] {
            this->queryBuilder->limit(options["limit"]);
        }
        if isset options["order"] {
            this->queryBuilder->orderBy(options["order"]);
        }
        if isset options["columns"] {
            this->queryBuilder->columns(options["columns"]);
        }
        return this->queryBuilder->select();    //返回结果
    }

    public function getLastQuery(){
        return this->queryBuilder->getLastQuery();
    }
}
