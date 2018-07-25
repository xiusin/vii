namespace Vii;

use Vii\Db\Pdo;
use Vii\DbInterface;
use Vii\Db\QueryBuilder;
class Db
{
    protected _queryBuilder = null;
    protected driver { get, set };
    public function __construct(var driver,host=null,port=null,name=null,user=null,password=null,array! options= []){
            if typeof driver == "object" && driver instanceof DbInterface {
                let this->driver = driver;
            }else{
                let this->driver = new Pdo(driver . ":host=" . host . ";port=" . port . ";dbname=" . name, user, password,options);
            }
    }
    /**
     * 创建构造器
     */
    public function createBuilder(){
        if !this->_queryBuilder{
            let this->_queryBuilder = new QueryBuilder();
        }
        return this->_queryBuilder;
    }
    /**
     * 开启数据库事务
     */
    public function begin(){
        this->driver->beginTransaction();
    }
    /**
     * 回滚事务
     */
    public function rollback(){
        this->driver->rollBack();
    }
    /**
     * 提交事务
     */
    public function commit(){
        this->driver->commit();
    }
  
    public function __call(string method, arguments = null) {
       return call_user_func_array([this->driver, method], arguments);
    }
}
