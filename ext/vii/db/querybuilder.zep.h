
extern zend_class_entry *vii_db_querybuilder_ce;

ZEPHIR_INIT_CLASS(Vii_Db_QueryBuilder);

PHP_METHOD(Vii_Db_QueryBuilder, __construct);
PHP_METHOD(Vii_Db_QueryBuilder, columns);
PHP_METHOD(Vii_Db_QueryBuilder, getColumns);
PHP_METHOD(Vii_Db_QueryBuilder, from);
PHP_METHOD(Vii_Db_QueryBuilder, addFrom);
PHP_METHOD(Vii_Db_QueryBuilder, addParams);
PHP_METHOD(Vii_Db_QueryBuilder, getFrom);
PHP_METHOD(Vii_Db_QueryBuilder, orderBy);
PHP_METHOD(Vii_Db_QueryBuilder, getDb);
PHP_METHOD(Vii_Db_QueryBuilder, join);
PHP_METHOD(Vii_Db_QueryBuilder, innerJoin);
PHP_METHOD(Vii_Db_QueryBuilder, leftJoin);
PHP_METHOD(Vii_Db_QueryBuilder, rightJoin);
PHP_METHOD(Vii_Db_QueryBuilder, _mergeBindParams);
PHP_METHOD(Vii_Db_QueryBuilder, where);
PHP_METHOD(Vii_Db_QueryBuilder, andWhere);
PHP_METHOD(Vii_Db_QueryBuilder, orWhere);
PHP_METHOD(Vii_Db_QueryBuilder, betweenWhere);
PHP_METHOD(Vii_Db_QueryBuilder, notBetweenWhere);
PHP_METHOD(Vii_Db_QueryBuilder, inWhere);
PHP_METHOD(Vii_Db_QueryBuilder, notInWhere);
PHP_METHOD(Vii_Db_QueryBuilder, getWhere);
PHP_METHOD(Vii_Db_QueryBuilder, limit);
PHP_METHOD(Vii_Db_QueryBuilder, groupBy);
PHP_METHOD(Vii_Db_QueryBuilder, _buildColumns);
PHP_METHOD(Vii_Db_QueryBuilder, _buildFroms);
PHP_METHOD(Vii_Db_QueryBuilder, select);
PHP_METHOD(Vii_Db_QueryBuilder, update);
PHP_METHOD(Vii_Db_QueryBuilder, insert);
PHP_METHOD(Vii_Db_QueryBuilder, getLastInsertId);
PHP_METHOD(Vii_Db_QueryBuilder, getLastQuery);
PHP_METHOD(Vii_Db_QueryBuilder, delete);
PHP_METHOD(Vii_Db_QueryBuilder, parseWhereArr);
static zend_object *zephir_init_properties_Vii_Db_QueryBuilder(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_from, 0, 0, 1)
	ZEND_ARG_INFO(0, tablenames)
	ZEND_ARG_INFO(0, aliasName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_addfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, tablename)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_addparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, order)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_join, 0, 0, 1)
	ZEND_ARG_INFO(0, joinTable)
	ZEND_ARG_INFO(0, joinCondition)
	ZEND_ARG_INFO(0, joinTableAlias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_innerjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, joinTable)
	ZEND_ARG_INFO(0, joinCondition)
	ZEND_ARG_INFO(0, joinTableAlias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_leftjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, joinTable)
	ZEND_ARG_INFO(0, joinCondition)
	ZEND_ARG_INFO(0, joinTableAlias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_rightjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, joinTable)
	ZEND_ARG_INFO(0, joinCondition)
	ZEND_ARG_INFO(0, joinTableAlias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder__mergebindparams, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_notbetweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_notinwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, groupByColumn)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_update, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, tablename)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_querybuilder_parsewherearr, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_db_querybuilder_method_entry) {
	PHP_ME(Vii_Db_QueryBuilder, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Db_QueryBuilder, columns, arginfo_vii_db_querybuilder_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, getColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, from, arginfo_vii_db_querybuilder_from, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, addFrom, arginfo_vii_db_querybuilder_addfrom, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, addParams, arginfo_vii_db_querybuilder_addparams, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, getFrom, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, orderBy, arginfo_vii_db_querybuilder_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, getDb, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, join, arginfo_vii_db_querybuilder_join, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, innerJoin, arginfo_vii_db_querybuilder_innerjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, leftJoin, arginfo_vii_db_querybuilder_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, rightJoin, arginfo_vii_db_querybuilder_rightjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, _mergeBindParams, arginfo_vii_db_querybuilder__mergebindparams, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Db_QueryBuilder, where, arginfo_vii_db_querybuilder_where, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, andWhere, arginfo_vii_db_querybuilder_andwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, orWhere, arginfo_vii_db_querybuilder_orwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, betweenWhere, arginfo_vii_db_querybuilder_betweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, notBetweenWhere, arginfo_vii_db_querybuilder_notbetweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, inWhere, arginfo_vii_db_querybuilder_inwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, notInWhere, arginfo_vii_db_querybuilder_notinwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, getWhere, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, limit, arginfo_vii_db_querybuilder_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, groupBy, arginfo_vii_db_querybuilder_groupby, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, _buildColumns, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Db_QueryBuilder, _buildFroms, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Db_QueryBuilder, select, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, update, arginfo_vii_db_querybuilder_update, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, insert, arginfo_vii_db_querybuilder_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, getLastInsertId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, getLastQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, delete, arginfo_vii_db_querybuilder_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db_QueryBuilder, parseWhereArr, arginfo_vii_db_querybuilder_parsewherearr, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
