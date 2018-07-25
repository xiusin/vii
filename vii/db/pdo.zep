namespace Vii\Db;
//PDO数据库
class Pdo
{
    private pdo;
    public function __construct(var dsn, string user = null, string password = null, array! options = []){
        var e;
        if  !extension_loaded("pdo") {
            throw new \Exception("Pdo扩展没有安装，无法使用数据库服务");
        }
        try {
            var pdo = "Pdo";    //这种模式调用全局库
            let this->pdo = new {pdo}(dsn,user,password,options);
        } catch \PDOException , e {
            throw new \PDOException("连接数据库失败 [原因]:".e->getMessage());
        }
    }

    public function __call(string method, arguments = null) {
       return call_user_func_array([this->pdo, method], arguments);
    }
}
