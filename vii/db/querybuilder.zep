namespace Vii\Db;

use Vii\Ioc;
use Vii\Exceptions\DatabaseException;
/**
 * 针对SELECTSQL语句的创建
 */
class QueryBuilder
{
    private _columns;
    private _froms; //form数组 包含别名=>数据表名
    private db;
    private _where ;
    private _bindParams = [];
    private _limit;
    private _order = "";
    private _join = "";
    private _lastQuery;
    private _groupby = [];
    public error;
    public function __construct(){
        let this->db = Ioc::getDefault()->get("db");
    }
    public function columns(columns){
        let this->_columns = columns;
        return this;
    }

    public function getColumns(){
        return this->_columns;
    }
    //要查询的表名 默认别名为表名自己
    public function from(tablenames,aliasName = null){
        if typeof tablenames == "array" {
            var alias ,tablename ;
            for alias,tablename in tablenames {
                if typeof alias == "string" {   //写入了别名
                    let this->_froms[alias] = tablename;
                }else{
                    let this->_froms[tablename] = tablename;
                }
            }
        }else{
            if aliasName {
                let this->_froms[aliasName] = tablenames;
            }else{
                let this->_froms[tablenames] = tablenames;
            }
        }
        return this;
    }

    //添加一个数据表名
    public function addFrom(string! tablename,string! alias = ""){
        if Empty alias {
            let this->_froms[tablename] = tablename;
        }else{
            let this->_froms[alias] = tablename;
        }
    }

    public function addParams(array! params){
        this->_mergeBindParams(params);
        return this;
    }

    public function getFrom (){
        return this->_froms;
    }

    public function orderBy(order){
        let this->_order = order;
        return this;
    }

    public function getDb() {
        return this->db; //返回的是对象
    }

    public function join(string! joinTable, string! joinCondition = "", string! joinTableAlias = ""){
        if joinCondition {
            let joinCondition = " ON ".joinCondition;
        }
        if !joinTableAlias {
            let joinTableAlias = str_replace( ".", "_" , joinTable);
        }
        let this->_join = this->_join . " JOIN " . joinTable . " AS " . joinTableAlias . joinCondition;
        return this;
    }

    public function innerJoin(string! joinTable, string! joinCondition = "", string! joinTableAlias = ""){
        if joinCondition {
            let joinCondition = " ON ".joinCondition;
        }
        if !joinTableAlias {
            let joinTableAlias = str_replace( ".", "_" , joinTable);
        }
        let this->_join = this->_join . " INNER JOIN " . joinTable . " AS " . joinTableAlias . joinCondition;
        return this;
    }

    public function leftJoin(string! joinTable, string! joinCondition = "", string! joinTableAlias = ""){
        if joinCondition {
            let joinCondition = " ON ".joinCondition;
        }
        if !joinTableAlias {
            let joinTableAlias = str_replace( ".", "_" , joinTable);
        }
        let this->_join = this->_join . " LEFT JOIN " . joinTable . " AS " . joinTableAlias . joinCondition;
        return this;
    }

    public function rightJoin(string! joinTable, string! joinCondition = "", string! joinTableAlias = ""){
        if joinCondition {
            let joinCondition = " ON ".joinCondition;
        }
        if !joinTableAlias {
            let joinTableAlias = str_replace( ".", "_" , joinTable);
        }
        let this->_join = this->_join . " RIGHT JOIN " . joinTable . " AS " . joinTableAlias . joinCondition;
        return this;
    }

    //合并绑定参数
    private function _mergeBindParams(array! bindParams = []){
        if !Empty bindParams {  //合并参数绑定
            var k,v;
            for k,v in bindParams {
                let this->_bindParams[":".k] = v;
            }
        }
    }

    public function where(string conditions,array! bindParams = []){
        let this->_where = this->_where . conditions;
        this->_mergeBindParams(bindParams);
        return this;
    }

    public function andWhere(string conditions,array! bindParams = []){
        return this->where(" AND ".conditions , bindParams);
    }

    public function orWhere(string conditions,array! bindParams = []){
        return this->where(" OR ".conditions,bindParams);
    }

    public function betweenWhere(string expr,minimum,maximum){
        return this->where(" AND BETWEEN ".expr . " ".minimum. " AND ". maximum);
    }

    public function notBetweenWhere(string expr,minimum,maximum){
        return this->where(" AND NOT BETWEEN ".expr . " ".minimum. " AND ". maximum);
    }
    //自动使用占位符，替换 tablename.b => tablename_b
    public function inWhere(string expr,array! columns){
        var param ;
        let param = strtr(expr,".","_");
        return this->where(" AND ".expr. " IN (:".param.")",[ param : implode(",",columns)]);
    }

    public function notInWhere(string expr,array! columns){
        var param ;
        let param = strtr(expr,".","_");
        return this->where(" AND ".expr. " NOT IN (:".param.")",[ param : implode(",",columns)]);
    }

    public function getWhere(){
        return this->_where;
    }
    //设置偏移量
    public function limit(int limit , int offset = null){
        if offset {
            let this->_limit = offset . "," . limit;
        }else{
            let this->_limit = limit;
        }
        return this;
    }

    //可以使用多字段处理
    public function groupBy(string! groupByColumn){
        let this->_groupby[] = groupByColumn;
        return this;
    }

    private function _buildColumns(){
        if typeof this->_columns == "array"{
            return implode(",",this->_columns);
        }else{
            if ! this->_columns {
                return "*";
            }else{
                return this->_columns;
            }
        }
    }

    private function _buildFroms(){
        var k,v,froms = [];
        for k,v in this->_froms {
            let froms[] = "`".k."` AS `".v."`";
        }
        return implode(",",froms);
    }

    public function select(){
            var condition,pdostate;
            if Empty this->_where {
                let condition = "1";
            }else{
                let condition = this->_where;
            }
            let this->_lastQuery = "SELECT ".this->_buildColumns() .
            " FROM ".this->_buildFroms().this->_join .
            " WHERE " . condition . this->_order . this->_limit;
            //获取预处理语句
            let pdostate = this->db->prepare(this->_lastQuery);
            pdostate->execute(this->_bindParams);
            let this->error = pdostate->errorInfo();
            return pdostate->fetchAll(\Pdo::FETCH_CLASS);
    }

    public function update(string! from, var filters = [], array fields = []){
            var key, value, columns, values, filtered, query, status;
            let columns = [],
                values = [];

            for key, value in fields {
                let values[":" . key] = value,
                    columns[] = "`" . key . "` = :" . key;
            }
            let filtered = this->parseWhereArr(filters, values);
            this->where(filtered[0],filtered[1]);
            let this->_lastQuery = "UPDATE `" . from . "` SET " . join(", ", columns) . " WHERE " . this->_where,
            query = this->db->prepare(this->_lastQuery),
            status = query->execute(this->_bindParams),
            this->error = query->errorInfo();
            return status;
    }

    public function insert(string! tablename,array! columns){
        var k,v,ks=[],vs=[],pdostate,status;
        for k,v in columns {
            let ks[k] = ":".k;
            let vs[":".k] = v;
        }
        this->_mergeBindParams(vs);
        let this->_lastQuery = "INSERT INTO ". tablename.
        " (".implode(",",array_keys(ks)).") VALUE (".implode(",",array_values(ks)).")";
        let pdostate = this->db->prepare(this->_lastQuery);  //获取预处理语句
        let status = pdostate->execute(this->_bindParams);
        let this->error = pdostate->errorInfo();
        return status;
    }

    public function getLastInsertId(){
        return this->db->lastInsertId();
    }

    public function getLastQuery(){
        return this->_lastQuery;
    }

    /**
     * 删除数据库记录
     * @demo $db->createBuilder()->delete("test",[
     *     "condition1"=>"条件1",
     *     "or"=>[
     *         ["id"=>1],
     *         ["username"=>"45"],
     *         ["age"=>[">"=>"18"]]
     *     ]
     * ])
     */
    public function delete(string! from, var filters = [],array! values=[])
    {
           var result = [],pdostate,status;
           let result = this->parseWhereArr(filters,values);
           this->where(result[0],result[1]);
           let this->_lastQuery = "DELETE FROM `".from."` WHERE ".this->_where;
        //    return this->_lastQuery ;
           let pdostate = this->db->prepare(this->_lastQuery);  //获取预处理语句
           let status = pdostate->execute(this->_bindParams);
           let this->error = pdostate->errorInfo();
           return status;
    }

    public function parseWhereArr(var filters = [],array! values=[]){
        var and, data, operator, key, item, value, or, is, index, i, sql, condition;
        let and = [],sql = "",i = "";
        if is_numeric(filters) {
            let filters = (int) filters;
        }
        switch typeof filters {
            case "array":
                for operator, data in filters {
                    switch operator {
                        case "OR":
                        case "or":
                        case "$or":
                            let or = [],
                                operator = "OR";
                        break;
                        case "AND":
                        case "and":
                        case "$and":
                            let operator = "AND";
                        break;
                        default: // short " AND "
                            var tmp = data;
                            let data = ["AND": [operator: tmp]],
                                operator = "AND";
                        break;
                    }

                    for item in data {
                        let key = key(item),
                            value = current(item);

                        if typeof value == "array" {
                            let is = key(value),
                                value = current(value);
                        } else {
                            let is = "=";
                        }

                        do {
                            let index = ":" . key . i,
                                i = i ? (int) i + 1 : 1;
                        } while isset values[index];

                        switch is {
                            case "IN":
                            case "in":
                            case "$in":
                                if typeof value == "array" {
                                    var j, id, ids = [];
                                    // Bind all values
                                    for j, id in value {
                                        let ids[] = index . j,
                                            values[index . j] = id;
                                    }

                                    let value = "(" . join(", ", ids) . ")";
                                }
                                let condition = "`" . key . "` " . is . " " . value;
                            break;
                            case "IS":
                            case "is":
                            case "IS NOT":
                            case "is not":
                                // Don't bind value
                                let condition = "`" . key . "` " . is . " " . value;
                            break;
                            default:
                                // Bind value
                                let condition = "`" . key . "` " . is . " " . index,
                                    values[index] = value;
                            break;
                        }

                        if operator == "AND" {
                            let and[] = condition;
                        } else {
                            let or[] = condition;
                        }
                    }

                    if operator == "OR" {
                        let and[] = "(" . join(" OR ", or) . ")";
                    }
                }
                let sql .= join(" AND ", and);
            break;
            case "integer":
                let sql .= "`id` = " . filters;
            break;
            case "string":
                let sql .= filters;
            break;
            default:
                let sql .= "TRUE";
            break;
        }
        return [sql,values];
    }
}
