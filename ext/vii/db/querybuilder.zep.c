
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * 针对SELECTSQL语句的创建
 */
ZEPHIR_INIT_CLASS(Vii_Db_QueryBuilder) {

	ZEPHIR_REGISTER_CLASS(Vii\\Db, QueryBuilder, vii, db_querybuilder, vii_db_querybuilder_method_entry, 0);

	zend_declare_property_null(vii_db_querybuilder_ce, SL("_columns"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_db_querybuilder_ce, SL("_froms"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_db_querybuilder_ce, SL("db"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_db_querybuilder_ce, SL("_where"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_db_querybuilder_ce, SL("_bindParams"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_db_querybuilder_ce, SL("_limit"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_db_querybuilder_ce, SL("_order"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_db_querybuilder_ce, SL("_join"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_db_querybuilder_ce, SL("_lastQuery"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_db_querybuilder_ce, SL("_groupby"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_db_querybuilder_ce, SL("error"), ZEND_ACC_PUBLIC TSRMLS_CC);

	vii_db_querybuilder_ce->create_object = zephir_init_properties_Vii_Db_QueryBuilder;
	return SUCCESS;

}

PHP_METHOD(Vii_Db_QueryBuilder, __construct) {

	zval _0, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, vii_ioc_ce, "getdefault", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "db");
	ZEPHIR_CALL_METHOD(&_2, &_0, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("db"), &_2);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Db_QueryBuilder, columns) {

	zval *columns, columns_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);

	zephir_fetch_params(0, 1, 0, &columns);



	zephir_update_property_zval(this_ptr, SL("_columns"), columns);
	RETURN_THISW();

}

PHP_METHOD(Vii_Db_QueryBuilder, getColumns) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_columns");

}

PHP_METHOD(Vii_Db_QueryBuilder, from) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zval *tablenames, tablenames_sub, *aliasName = NULL, aliasName_sub, __$null, alias$$3, tablename$$3, *_0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tablenames_sub);
	ZVAL_UNDEF(&aliasName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&alias$$3);
	ZVAL_UNDEF(&tablename$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tablenames, &aliasName);

	if (!aliasName) {
		aliasName = &aliasName_sub;
		aliasName = &__$null;
	}


	if (Z_TYPE_P(tablenames) == IS_ARRAY) {
		zephir_is_iterable(tablenames, 0, "vii/db/querybuilder.zep", 43);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(tablenames), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&alias$$3);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&alias$$3, _2$$3);
			} else {
				ZVAL_LONG(&alias$$3, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&tablename$$3);
			ZVAL_COPY(&tablename$$3, _0$$3);
			if (Z_TYPE_P(&alias$$3) == IS_STRING) {
				zephir_update_property_array(this_ptr, SL("_froms"), &alias$$3, &tablename$$3 TSRMLS_CC);
			} else {
				zephir_update_property_array(this_ptr, SL("_froms"), &tablename$$3, &tablename$$3 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&tablename$$3);
		ZEPHIR_INIT_NVAR(&alias$$3);
	} else {
		if (zephir_is_true(aliasName)) {
			zephir_update_property_array(this_ptr, SL("_froms"), aliasName, tablenames TSRMLS_CC);
		} else {
			zephir_update_property_array(this_ptr, SL("_froms"), tablenames, tablenames TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

PHP_METHOD(Vii_Db_QueryBuilder, addFrom) {

	zval *tablename_param = NULL, *alias_param = NULL;
	zval tablename, alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tablename);
	ZVAL_UNDEF(&alias);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tablename_param, &alias_param);

	if (UNEXPECTED(Z_TYPE_P(tablename_param) != IS_STRING && Z_TYPE_P(tablename_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tablename' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tablename_param) == IS_STRING)) {
		zephir_get_strval(&tablename, tablename_param);
	} else {
		ZEPHIR_INIT_VAR(&tablename);
		ZVAL_EMPTY_STRING(&tablename);
	}
	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_STRING(&alias, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_EMPTY_STRING(&alias);
	}
	}


	if (ZEPHIR_IS_EMPTY(&alias)) {
		zephir_update_property_array(this_ptr, SL("_froms"), &tablename, &tablename TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("_froms"), &alias, &tablename TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Db_QueryBuilder, addParams) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_mergebindparams", NULL, 31, &params);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Vii_Db_QueryBuilder, getFrom) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_froms");

}

PHP_METHOD(Vii_Db_QueryBuilder, orderBy) {

	zval *order, order_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order_sub);

	zephir_fetch_params(0, 1, 0, &order);



	zephir_update_property_zval(this_ptr, SL("_order"), order);
	RETURN_THISW();

}

PHP_METHOD(Vii_Db_QueryBuilder, getDb) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "db");

}

PHP_METHOD(Vii_Db_QueryBuilder, join) {

	zval *joinTable_param = NULL, *joinCondition_param = NULL, *joinTableAlias_param = NULL, _1$$4, _2$$4, _3, _4;
	zval joinTable, joinCondition, joinTableAlias, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&joinTable);
	ZVAL_UNDEF(&joinCondition);
	ZVAL_UNDEF(&joinTableAlias);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &joinTable_param, &joinCondition_param, &joinTableAlias_param);

	if (UNEXPECTED(Z_TYPE_P(joinTable_param) != IS_STRING && Z_TYPE_P(joinTable_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinTable' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinTable_param) == IS_STRING)) {
		zephir_get_strval(&joinTable, joinTable_param);
	} else {
		ZEPHIR_INIT_VAR(&joinTable);
		ZVAL_EMPTY_STRING(&joinTable);
	}
	if (!joinCondition_param) {
		ZEPHIR_INIT_VAR(&joinCondition);
		ZVAL_STRING(&joinCondition, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(joinCondition_param) != IS_STRING && Z_TYPE_P(joinCondition_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinCondition' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinCondition_param) == IS_STRING)) {
		zephir_get_strval(&joinCondition, joinCondition_param);
	} else {
		ZEPHIR_INIT_VAR(&joinCondition);
		ZVAL_EMPTY_STRING(&joinCondition);
	}
	}
	if (!joinTableAlias_param) {
		ZEPHIR_INIT_VAR(&joinTableAlias);
		ZVAL_STRING(&joinTableAlias, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(joinTableAlias_param) != IS_STRING && Z_TYPE_P(joinTableAlias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinTableAlias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinTableAlias_param) == IS_STRING)) {
		zephir_get_strval(&joinTableAlias, joinTableAlias_param);
	} else {
		ZEPHIR_INIT_VAR(&joinTableAlias);
		ZVAL_EMPTY_STRING(&joinTableAlias);
	}
	}


	if (!(Z_TYPE_P(&joinCondition) == IS_UNDEF) && Z_STRLEN_P(&joinCondition)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, " ON ", &joinCondition);
		ZEPHIR_CPY_WRT(&joinCondition, &_0$$3);
	}
	if (!(!(Z_TYPE_P(&joinTableAlias) == IS_UNDEF) && Z_STRLEN_P(&joinTableAlias))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, ".");
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "_");
		ZEPHIR_INIT_NVAR(&joinTableAlias);
		zephir_fast_str_replace(&joinTableAlias, &_1$$4, &_2$$4, &joinTable TSRMLS_CC);
	}
	zephir_read_property(&_3, this_ptr, SL("_join"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VSVSVV(&_4, &_3, " JOIN ", &joinTable, " AS ", &joinTableAlias, &joinCondition);
	zephir_update_property_zval(this_ptr, SL("_join"), &_4);
	RETURN_THIS();

}

PHP_METHOD(Vii_Db_QueryBuilder, innerJoin) {

	zval *joinTable_param = NULL, *joinCondition_param = NULL, *joinTableAlias_param = NULL, _1$$4, _2$$4, _3, _4;
	zval joinTable, joinCondition, joinTableAlias, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&joinTable);
	ZVAL_UNDEF(&joinCondition);
	ZVAL_UNDEF(&joinTableAlias);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &joinTable_param, &joinCondition_param, &joinTableAlias_param);

	if (UNEXPECTED(Z_TYPE_P(joinTable_param) != IS_STRING && Z_TYPE_P(joinTable_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinTable' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinTable_param) == IS_STRING)) {
		zephir_get_strval(&joinTable, joinTable_param);
	} else {
		ZEPHIR_INIT_VAR(&joinTable);
		ZVAL_EMPTY_STRING(&joinTable);
	}
	if (!joinCondition_param) {
		ZEPHIR_INIT_VAR(&joinCondition);
		ZVAL_STRING(&joinCondition, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(joinCondition_param) != IS_STRING && Z_TYPE_P(joinCondition_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinCondition' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinCondition_param) == IS_STRING)) {
		zephir_get_strval(&joinCondition, joinCondition_param);
	} else {
		ZEPHIR_INIT_VAR(&joinCondition);
		ZVAL_EMPTY_STRING(&joinCondition);
	}
	}
	if (!joinTableAlias_param) {
		ZEPHIR_INIT_VAR(&joinTableAlias);
		ZVAL_STRING(&joinTableAlias, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(joinTableAlias_param) != IS_STRING && Z_TYPE_P(joinTableAlias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinTableAlias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinTableAlias_param) == IS_STRING)) {
		zephir_get_strval(&joinTableAlias, joinTableAlias_param);
	} else {
		ZEPHIR_INIT_VAR(&joinTableAlias);
		ZVAL_EMPTY_STRING(&joinTableAlias);
	}
	}


	if (!(Z_TYPE_P(&joinCondition) == IS_UNDEF) && Z_STRLEN_P(&joinCondition)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, " ON ", &joinCondition);
		ZEPHIR_CPY_WRT(&joinCondition, &_0$$3);
	}
	if (!(!(Z_TYPE_P(&joinTableAlias) == IS_UNDEF) && Z_STRLEN_P(&joinTableAlias))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, ".");
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "_");
		ZEPHIR_INIT_NVAR(&joinTableAlias);
		zephir_fast_str_replace(&joinTableAlias, &_1$$4, &_2$$4, &joinTable TSRMLS_CC);
	}
	zephir_read_property(&_3, this_ptr, SL("_join"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VSVSVV(&_4, &_3, " INNER JOIN ", &joinTable, " AS ", &joinTableAlias, &joinCondition);
	zephir_update_property_zval(this_ptr, SL("_join"), &_4);
	RETURN_THIS();

}

PHP_METHOD(Vii_Db_QueryBuilder, leftJoin) {

	zval *joinTable_param = NULL, *joinCondition_param = NULL, *joinTableAlias_param = NULL, _1$$4, _2$$4, _3, _4;
	zval joinTable, joinCondition, joinTableAlias, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&joinTable);
	ZVAL_UNDEF(&joinCondition);
	ZVAL_UNDEF(&joinTableAlias);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &joinTable_param, &joinCondition_param, &joinTableAlias_param);

	if (UNEXPECTED(Z_TYPE_P(joinTable_param) != IS_STRING && Z_TYPE_P(joinTable_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinTable' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinTable_param) == IS_STRING)) {
		zephir_get_strval(&joinTable, joinTable_param);
	} else {
		ZEPHIR_INIT_VAR(&joinTable);
		ZVAL_EMPTY_STRING(&joinTable);
	}
	if (!joinCondition_param) {
		ZEPHIR_INIT_VAR(&joinCondition);
		ZVAL_STRING(&joinCondition, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(joinCondition_param) != IS_STRING && Z_TYPE_P(joinCondition_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinCondition' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinCondition_param) == IS_STRING)) {
		zephir_get_strval(&joinCondition, joinCondition_param);
	} else {
		ZEPHIR_INIT_VAR(&joinCondition);
		ZVAL_EMPTY_STRING(&joinCondition);
	}
	}
	if (!joinTableAlias_param) {
		ZEPHIR_INIT_VAR(&joinTableAlias);
		ZVAL_STRING(&joinTableAlias, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(joinTableAlias_param) != IS_STRING && Z_TYPE_P(joinTableAlias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinTableAlias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinTableAlias_param) == IS_STRING)) {
		zephir_get_strval(&joinTableAlias, joinTableAlias_param);
	} else {
		ZEPHIR_INIT_VAR(&joinTableAlias);
		ZVAL_EMPTY_STRING(&joinTableAlias);
	}
	}


	if (!(Z_TYPE_P(&joinCondition) == IS_UNDEF) && Z_STRLEN_P(&joinCondition)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, " ON ", &joinCondition);
		ZEPHIR_CPY_WRT(&joinCondition, &_0$$3);
	}
	if (!(!(Z_TYPE_P(&joinTableAlias) == IS_UNDEF) && Z_STRLEN_P(&joinTableAlias))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, ".");
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "_");
		ZEPHIR_INIT_NVAR(&joinTableAlias);
		zephir_fast_str_replace(&joinTableAlias, &_1$$4, &_2$$4, &joinTable TSRMLS_CC);
	}
	zephir_read_property(&_3, this_ptr, SL("_join"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VSVSVV(&_4, &_3, " LEFT JOIN ", &joinTable, " AS ", &joinTableAlias, &joinCondition);
	zephir_update_property_zval(this_ptr, SL("_join"), &_4);
	RETURN_THIS();

}

PHP_METHOD(Vii_Db_QueryBuilder, rightJoin) {

	zval *joinTable_param = NULL, *joinCondition_param = NULL, *joinTableAlias_param = NULL, _1$$4, _2$$4, _3, _4;
	zval joinTable, joinCondition, joinTableAlias, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&joinTable);
	ZVAL_UNDEF(&joinCondition);
	ZVAL_UNDEF(&joinTableAlias);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &joinTable_param, &joinCondition_param, &joinTableAlias_param);

	if (UNEXPECTED(Z_TYPE_P(joinTable_param) != IS_STRING && Z_TYPE_P(joinTable_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinTable' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinTable_param) == IS_STRING)) {
		zephir_get_strval(&joinTable, joinTable_param);
	} else {
		ZEPHIR_INIT_VAR(&joinTable);
		ZVAL_EMPTY_STRING(&joinTable);
	}
	if (!joinCondition_param) {
		ZEPHIR_INIT_VAR(&joinCondition);
		ZVAL_STRING(&joinCondition, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(joinCondition_param) != IS_STRING && Z_TYPE_P(joinCondition_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinCondition' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinCondition_param) == IS_STRING)) {
		zephir_get_strval(&joinCondition, joinCondition_param);
	} else {
		ZEPHIR_INIT_VAR(&joinCondition);
		ZVAL_EMPTY_STRING(&joinCondition);
	}
	}
	if (!joinTableAlias_param) {
		ZEPHIR_INIT_VAR(&joinTableAlias);
		ZVAL_STRING(&joinTableAlias, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(joinTableAlias_param) != IS_STRING && Z_TYPE_P(joinTableAlias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'joinTableAlias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(joinTableAlias_param) == IS_STRING)) {
		zephir_get_strval(&joinTableAlias, joinTableAlias_param);
	} else {
		ZEPHIR_INIT_VAR(&joinTableAlias);
		ZVAL_EMPTY_STRING(&joinTableAlias);
	}
	}


	if (!(Z_TYPE_P(&joinCondition) == IS_UNDEF) && Z_STRLEN_P(&joinCondition)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, " ON ", &joinCondition);
		ZEPHIR_CPY_WRT(&joinCondition, &_0$$3);
	}
	if (!(!(Z_TYPE_P(&joinTableAlias) == IS_UNDEF) && Z_STRLEN_P(&joinTableAlias))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, ".");
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "_");
		ZEPHIR_INIT_NVAR(&joinTableAlias);
		zephir_fast_str_replace(&joinTableAlias, &_1$$4, &_2$$4, &joinTable TSRMLS_CC);
	}
	zephir_read_property(&_3, this_ptr, SL("_join"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VSVSVV(&_4, &_3, " RIGHT JOIN ", &joinTable, " AS ", &joinTableAlias, &joinCondition);
	zephir_update_property_zval(this_ptr, SL("_join"), &_4);
	RETURN_THIS();

}

PHP_METHOD(Vii_Db_QueryBuilder, _mergeBindParams) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zval *bindParams_param = NULL, k$$3, v$$3, *_0$$3, _3$$4;
	zval bindParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&k$$3);
	ZVAL_UNDEF(&v$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &bindParams_param);

	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&bindParams))) {
		zephir_is_iterable(&bindParams, 0, "vii/db/querybuilder.zep", 131);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bindParams), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&k$$3);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&k$$3, _2$$3);
			} else {
				ZVAL_LONG(&k$$3, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&v$$3);
			ZVAL_COPY(&v$$3, _0$$3);
			ZEPHIR_INIT_LNVAR(_3$$4);
			ZEPHIR_CONCAT_SV(&_3$$4, ":", &k$$3);
			zephir_update_property_array(this_ptr, SL("_bindParams"), &_3$$4, &v$$3 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v$$3);
		ZEPHIR_INIT_NVAR(&k$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Db_QueryBuilder, where) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams;
	zval *conditions_param = NULL, *bindParams_param = NULL, _0, _1;
	zval conditions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&bindParams);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &conditions_param, &bindParams_param);

	zephir_get_strval(&conditions, conditions_param);
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_where"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &conditions);
	zephir_update_property_zval(this_ptr, SL("_where"), &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_mergebindparams", NULL, 31, &bindParams);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Vii_Db_QueryBuilder, andWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams;
	zval *conditions_param = NULL, *bindParams_param = NULL;
	zval conditions, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&bindParams);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &conditions_param, &bindParams_param);

	zephir_get_strval(&conditions, conditions_param);
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, " AND ", &conditions);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &_0, &bindParams);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Db_QueryBuilder, orWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval bindParams;
	zval *conditions_param = NULL, *bindParams_param = NULL;
	zval conditions, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&bindParams);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &conditions_param, &bindParams_param);

	zephir_get_strval(&conditions, conditions_param);
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, " OR ", &conditions);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &_0, &bindParams);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Db_QueryBuilder, betweenWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, _0;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);

	zephir_get_strval(&expr, expr_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSVSV(&_0, " AND BETWEEN ", &expr, " ", minimum, " AND ", maximum);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Db_QueryBuilder, notBetweenWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *minimum, minimum_sub, *maximum, maximum_sub, _0;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&minimum_sub);
	ZVAL_UNDEF(&maximum_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &expr_param, &minimum, &maximum);

	zephir_get_strval(&expr, expr_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSVSV(&_0, " AND NOT BETWEEN ", &expr, " ", minimum, " AND ", maximum);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Db_QueryBuilder, inWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval columns, _3;
	zval *expr_param = NULL, *columns_param = NULL, param, _0, _1, _2;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &columns_param);

	zephir_get_strval(&expr, expr_param);
	ZEPHIR_OBS_COPY_OR_DUP(&columns, columns_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, ".");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_CALL_FUNCTION(&param, "strtr", NULL, 20, &expr, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSVS(&_2, " AND ", &expr, " IN (:", &param, ")");
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_join_str(&_0, SL(","), &columns TSRMLS_CC);
	zephir_array_update_zval(&_3, &param, &_0, PH_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Db_QueryBuilder, notInWhere) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval columns, _3;
	zval *expr_param = NULL, *columns_param = NULL, param, _0, _1, _2;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &expr_param, &columns_param);

	zephir_get_strval(&expr, expr_param);
	ZEPHIR_OBS_COPY_OR_DUP(&columns, columns_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, ".");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_CALL_FUNCTION(&param, "strtr", NULL, 20, &expr, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSVS(&_2, " AND ", &expr, " NOT IN (:", &param, ")");
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_join_str(&_0, SL(","), &columns TSRMLS_CC);
	zephir_array_update_zval(&_3, &param, &_0, PH_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "where", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Db_QueryBuilder, getWhere) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_where");

}

PHP_METHOD(Vii_Db_QueryBuilder, limit) {

	zval _2$$3;
	zval *limit_param = NULL, *offset_param = NULL, _0$$3, _1$$3, _3$$4;
	zend_long limit, offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &limit_param, &offset_param);

	limit = zephir_get_intval(limit_param);
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	if (offset) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, offset);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, limit);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VSV(&_2$$3, &_0$$3, ",", &_1$$3);
		zephir_update_property_zval(this_ptr, SL("_limit"), &_2$$3);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_3$$4);
		ZVAL_LONG(&_3$$4, limit);
		zephir_update_property_zval(this_ptr, SL("_limit"), &_3$$4);
	}
	RETURN_THIS();

}

PHP_METHOD(Vii_Db_QueryBuilder, groupBy) {

	zval *groupByColumn_param = NULL;
	zval groupByColumn;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&groupByColumn);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &groupByColumn_param);

	if (UNEXPECTED(Z_TYPE_P(groupByColumn_param) != IS_STRING && Z_TYPE_P(groupByColumn_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'groupByColumn' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(groupByColumn_param) == IS_STRING)) {
		zephir_get_strval(&groupByColumn, groupByColumn_param);
	} else {
		ZEPHIR_INIT_VAR(&groupByColumn);
		ZVAL_EMPTY_STRING(&groupByColumn);
	}


	zephir_update_property_array_append(this_ptr, SL("_groupby"), &groupByColumn TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Vii_Db_QueryBuilder, _buildColumns) {

	zval _0, _1$$3, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_columns"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		zephir_read_property(&_1$$3, this_ptr, SL("_columns"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_join_str(return_value, SL(","), &_1$$3 TSRMLS_CC);
		RETURN_MM();
	} else {
		zephir_read_property(&_2$$4, this_ptr, SL("_columns"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_2$$4))) {
			RETURN_MM_STRING("*");
		} else {
			RETURN_MM_MEMBER(getThis(), "_columns");
		}
	}

}

PHP_METHOD(Vii_Db_QueryBuilder, _buildFroms) {

	zend_string *_3;
	zend_ulong _2;
	zval k, v, froms, _0, *_1, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&froms);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&froms);
	array_init(&froms);
	zephir_read_property(&_0, this_ptr, SL("_froms"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "vii/db/querybuilder.zep", 204);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&k, _3);
		} else {
			ZVAL_LONG(&k, _2);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _1);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SVSVS(&_4$$3, "`", &k, "` AS `", &v, "`");
		zephir_array_append(&froms, &_4$$3, PH_SEPARATE, "vii/db/querybuilder.zep", 202);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_fast_join_str(return_value, SL(","), &froms TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Vii_Db_QueryBuilder, select) {

	zval condition, pdostate, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&pdostate);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_where"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_VAR(&condition);
		ZVAL_STRING(&condition, "1");
	} else {
		ZEPHIR_OBS_NVAR(&condition);
		zephir_read_property(&condition, this_ptr, SL("_where"), PH_NOISY_CC);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_buildcolumns", NULL, 32);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_buildfroms", NULL, 33);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("_join"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("_order"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, SL("_limit"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSVVSVVV(&_6, "SELECT ", &_1, " FROM ", &_2, &_3, " WHERE ", &condition, &_4, &_5);
	zephir_update_property_zval(this_ptr, SL("_lastQuery"), &_6);
	zephir_read_property(&_7, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_8, this_ptr, SL("_lastQuery"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&pdostate, &_7, "prepare", NULL, 0, &_8);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &pdostate, "execute", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, &pdostate, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_10);
	ZVAL_LONG(&_11, 8);
	ZEPHIR_RETURN_CALL_METHOD(&pdostate, "fetchall", NULL, 0, &_11);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Db_QueryBuilder, update) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fields;
	zval *from_param = NULL, *filters = NULL, filters_sub, *fields_param = NULL, key, value, columns, values, filtered, query, status, *_0, _5, _6, _7, _8, _9, _10, _11, _12, _13, _3$$3, _4$$3;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&fields);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &from_param, &filters, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
		zephir_get_arrval(&fields, fields_param);
	}


	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	zephir_is_iterable(&fields, 0, "vii/db/querybuilder.zep", 233);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, ":", &key);
		zephir_array_update_zval(&values, &_3$$3, &value, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SVSV(&_4$$3, "`", &key, "` = :", &key);
		zephir_array_append(&columns, &_4$$3, PH_SEPARATE, "vii/db/querybuilder.zep", 231);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "parsewherearr", NULL, 0, filters, &values);
	zephir_check_call_status();
	zephir_array_fetch_long(&_5, &filtered, 0, PH_NOISY | PH_READONLY, "vii/db/querybuilder.zep", 234 TSRMLS_CC);
	zephir_array_fetch_long(&_6, &filtered, 1, PH_NOISY | PH_READONLY, "vii/db/querybuilder.zep", 234 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", NULL, 0, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_join_str(&_7, SL(", "), &columns TSRMLS_CC);
	zephir_read_property(&_8, this_ptr, SL("_where"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SVSVSV(&_9, "UPDATE `", &from, "` SET ", &_7, " WHERE ", &_8);
	zephir_update_property_zval(this_ptr, SL("_lastQuery"), &_9);
	zephir_read_property(&_10, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, this_ptr, SL("_lastQuery"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&query, &_10, "prepare", NULL, 0, &_11);
	zephir_check_call_status();
	zephir_read_property(&_12, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &query, "execute", NULL, 0, &_12);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_13, &query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_13);
	RETURN_CCTOR(&status);

}

PHP_METHOD(Vii_Db_QueryBuilder, insert) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval columns;
	zval *tablename_param = NULL, *columns_param = NULL, k, v, ks, vs, pdostate, status, *_0, _5, _6, _7, _8, _9, _10, _11, _12, _13, _3$$3, _4$$3;
	zval tablename;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tablename);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&ks);
	ZVAL_UNDEF(&vs);
	ZVAL_UNDEF(&pdostate);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&columns);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tablename_param, &columns_param);

	if (UNEXPECTED(Z_TYPE_P(tablename_param) != IS_STRING && Z_TYPE_P(tablename_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tablename' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tablename_param) == IS_STRING)) {
		zephir_get_strval(&tablename, tablename_param);
	} else {
		ZEPHIR_INIT_VAR(&tablename);
		ZVAL_EMPTY_STRING(&tablename);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&columns, columns_param);


	ZEPHIR_INIT_VAR(&ks);
	array_init(&ks);
	ZEPHIR_INIT_VAR(&vs);
	array_init(&vs);
	zephir_is_iterable(&columns, 0, "vii/db/querybuilder.zep", 248);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columns), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&k, _2);
		} else {
			ZVAL_LONG(&k, _1);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, ":", &k);
		zephir_array_update_zval(&ks, &k, &_3$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SV(&_4$$3, ":", &k);
		zephir_array_update_zval(&vs, &_4$$3, &v, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_mergebindparams", NULL, 31, &vs);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_array_keys(&_6, &ks TSRMLS_CC);
	zephir_fast_join_str(&_5, SL(","), &_6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CALL_FUNCTION(&_8, "array_values", NULL, 34, &ks);
	zephir_check_call_status();
	zephir_fast_join_str(&_7, SL(","), &_8 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SVSVSVS(&_9, "INSERT INTO ", &tablename, " (", &_5, ") VALUE (", &_7, ")");
	zephir_update_property_zval(this_ptr, SL("_lastQuery"), &_9);
	zephir_read_property(&_10, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, this_ptr, SL("_lastQuery"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&pdostate, &_10, "prepare", NULL, 0, &_11);
	zephir_check_call_status();
	zephir_read_property(&_12, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &pdostate, "execute", NULL, 0, &_12);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_13, &pdostate, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_13);
	RETURN_CCTOR(&status);

}

PHP_METHOD(Vii_Db_QueryBuilder, getLastInsertId) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "lastinsertid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Db_QueryBuilder, getLastQuery) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_lastQuery");

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
PHP_METHOD(Vii_Db_QueryBuilder, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval values;
	zval *from_param = NULL, *filters = NULL, filters_sub, *values_param = NULL, result, pdostate, status, _0, _1, _2, _3, _4, _5, _6, _7;
	zval from;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&pdostate);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&values);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &from_param, &filters, &values_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(&from, from_param);
	} else {
		ZEPHIR_INIT_VAR(&from);
		ZVAL_EMPTY_STRING(&from);
	}
	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	}


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "parsewherearr", NULL, 0, filters, &values);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, &result, 0, PH_NOISY | PH_READONLY, "vii/db/querybuilder.zep", 280 TSRMLS_CC);
	zephir_array_fetch_long(&_1, &result, 1, PH_NOISY | PH_READONLY, "vii/db/querybuilder.zep", 280 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("_where"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSV(&_3, "DELETE FROM `", &from, "` WHERE ", &_2);
	zephir_update_property_zval(this_ptr, SL("_lastQuery"), &_3);
	zephir_read_property(&_4, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, SL("_lastQuery"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&pdostate, &_4, "prepare", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &pdostate, "execute", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, &pdostate, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("error"), &_7);
	RETURN_CCTOR(&status);

}

PHP_METHOD(Vii_Db_QueryBuilder, parseWhereArr) {

	zend_string *_4$$4, *_13$$14;
	zend_ulong _3$$4, _12$$14;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$3;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zval values, _5$$8;
	zval *filters = NULL, filters_sub, *values_param = NULL, and, data, operator, key, item, value, or, is, index, i, sql, condition, _1, *_2$$4, _19$$4, tmp$$8, *_6$$5, _9$$10, _10$$12, j$$14, id$$14, ids$$14, *_11$$14, _16$$14, _14$$15, _15$$15, _17$$20, _18$$20, _20$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&and);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&operator);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&or);
	ZVAL_UNDEF(&is);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&tmp$$8);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&j$$14);
	ZVAL_UNDEF(&id$$14);
	ZVAL_UNDEF(&ids$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_18$$20);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_5$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &filters, &values_param);

	if (!filters) {
		filters = &filters_sub;
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		ZEPHIR_SEPARATE_PARAM(filters);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(&values);
		array_init(&values);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	}


	ZEPHIR_INIT_VAR(&and);
	array_init(&and);
	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "");
	ZEPHIR_INIT_VAR(&i);
	ZVAL_STRING(&i, "");
	if (zephir_is_numeric(filters)) {
		_0$$3 = zephir_get_intval(filters);
		ZEPHIR_INIT_NVAR(filters);
		ZVAL_LONG(filters, _0$$3);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_gettype(&_1, filters TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(&_1, "array")) {
			zephir_is_iterable(filters, 0, "vii/db/querybuilder.zep", 374);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(filters), _3$$4, _4$$4, _2$$4)
			{
				ZEPHIR_INIT_NVAR(&operator);
				if (_4$$4 != NULL) { 
					ZVAL_STR_COPY(&operator, _4$$4);
				} else {
					ZVAL_LONG(&operator, _3$$4);
				}
				ZEPHIR_INIT_NVAR(&data);
				ZVAL_COPY(&data, _2$$4);
				do {
					if (ZEPHIR_IS_STRING(&operator, "OR") || ZEPHIR_IS_STRING(&operator, "or") || ZEPHIR_IS_STRING(&operator, "$or")) {
						ZEPHIR_INIT_NVAR(&or);
						array_init(&or);
						ZEPHIR_INIT_NVAR(&operator);
						ZVAL_STRING(&operator, "OR");
						break;
					}
					if (ZEPHIR_IS_STRING(&operator, "AND") || ZEPHIR_IS_STRING(&operator, "and") || ZEPHIR_IS_STRING(&operator, "$and")) {
						ZEPHIR_INIT_NVAR(&operator);
						ZVAL_STRING(&operator, "AND");
						break;
					}
					ZEPHIR_CPY_WRT(&tmp$$8, &data);
					ZEPHIR_INIT_NVAR(&data);
					zephir_create_array(&data, 1, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_5$$8);
					zephir_create_array(&_5$$8, 1, 0 TSRMLS_CC);
					zephir_array_update_zval(&_5$$8, &operator, &tmp$$8, PH_COPY);
					zephir_array_update_string(&data, SL("AND"), &_5$$8, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&operator);
					ZVAL_STRING(&operator, "AND");
					break;
				} while(0);

				zephir_is_iterable(&data, 0, "vii/db/querybuilder.zep", 370);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _6$$5)
				{
					ZEPHIR_INIT_NVAR(&item);
					ZVAL_COPY(&item, _6$$5);
					ZEPHIR_CALL_FUNCTION(&key, "key", &_7, 35, &item);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&value, "current", &_8, 36, &item);
					zephir_check_call_status();
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEPHIR_CALL_FUNCTION(&is, "key", &_7, 35, &value);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_9$$10, "current", &_8, 36, &value);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&value, &_9$$10);
					} else {
						ZEPHIR_INIT_NVAR(&is);
						ZVAL_STRING(&is, "=");
					}
					do {
						ZEPHIR_INIT_NVAR(&index);
						ZEPHIR_CONCAT_SVV(&index, ":", &key, &i);
						ZEPHIR_INIT_LNVAR(_10$$12);
						if (zephir_is_true(&i)) {
							ZEPHIR_INIT_NVAR(&_10$$12);
							ZVAL_LONG(&_10$$12, (zephir_get_intval(&i) + 1));
						} else {
							ZEPHIR_INIT_NVAR(&_10$$12);
							ZVAL_LONG(&_10$$12, 1);
						}
						ZEPHIR_CPY_WRT(&i, &_10$$12);
					} while (zephir_array_isset(&values, &index));
					do {
						if (ZEPHIR_IS_STRING(&is, "IN") || ZEPHIR_IS_STRING(&is, "in") || ZEPHIR_IS_STRING(&is, "$in")) {
							if (Z_TYPE_P(&value) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&ids$$14);
								array_init(&ids$$14);
								zephir_is_iterable(&value, 0, "vii/db/querybuilder.zep", 345);
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _12$$14, _13$$14, _11$$14)
								{
									ZEPHIR_INIT_NVAR(&j$$14);
									if (_13$$14 != NULL) { 
										ZVAL_STR_COPY(&j$$14, _13$$14);
									} else {
										ZVAL_LONG(&j$$14, _12$$14);
									}
									ZEPHIR_INIT_NVAR(&id$$14);
									ZVAL_COPY(&id$$14, _11$$14);
									ZEPHIR_INIT_LNVAR(_14$$15);
									ZEPHIR_CONCAT_VV(&_14$$15, &index, &j$$14);
									zephir_array_append(&ids$$14, &_14$$15, PH_SEPARATE, "vii/db/querybuilder.zep", 341);
									ZEPHIR_INIT_LNVAR(_15$$15);
									ZEPHIR_CONCAT_VV(&_15$$15, &index, &j$$14);
									zephir_array_update_zval(&values, &_15$$15, &id$$14, PH_COPY | PH_SEPARATE);
								} ZEND_HASH_FOREACH_END();
								ZEPHIR_INIT_NVAR(&id$$14);
								ZEPHIR_INIT_NVAR(&j$$14);
								ZEPHIR_INIT_NVAR(&_16$$14);
								zephir_fast_join_str(&_16$$14, SL(", "), &ids$$14 TSRMLS_CC);
								ZEPHIR_INIT_NVAR(&value);
								ZEPHIR_CONCAT_SVS(&value, "(", &_16$$14, ")");
							}
							ZEPHIR_INIT_NVAR(&condition);
							ZEPHIR_CONCAT_SVSVSV(&condition, "`", &key, "` ", &is, " ", &value);
							break;
						}
						if (ZEPHIR_IS_STRING(&is, "IS") || ZEPHIR_IS_STRING(&is, "is") || ZEPHIR_IS_STRING(&is, "IS NOT") || ZEPHIR_IS_STRING(&is, "is not")) {
							ZEPHIR_INIT_NVAR(&condition);
							ZEPHIR_CONCAT_SVSVSV(&condition, "`", &key, "` ", &is, " ", &value);
							break;
						}
						ZEPHIR_INIT_NVAR(&condition);
						ZEPHIR_CONCAT_SVSVSV(&condition, "`", &key, "` ", &is, " ", &index);
						zephir_array_update_zval(&values, &index, &value, PH_COPY | PH_SEPARATE);
						break;
					} while(0);

					if (ZEPHIR_IS_STRING(&operator, "AND")) {
						zephir_array_append(&and, &condition, PH_SEPARATE, "vii/db/querybuilder.zep", 364);
					} else {
						zephir_array_append(&or, &condition, PH_SEPARATE, "vii/db/querybuilder.zep", 366);
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&item);
				if (ZEPHIR_IS_STRING(&operator, "OR")) {
					ZEPHIR_INIT_NVAR(&_17$$20);
					zephir_fast_join_str(&_17$$20, SL(" OR "), &or TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_18$$20);
					ZEPHIR_CONCAT_SVS(&_18$$20, "(", &_17$$20, ")");
					zephir_array_append(&and, &_18$$20, PH_SEPARATE, "vii/db/querybuilder.zep", 371);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&data);
			ZEPHIR_INIT_NVAR(&operator);
			ZEPHIR_INIT_VAR(&_19$$4);
			zephir_fast_join_str(&_19$$4, SL(" AND "), &and TSRMLS_CC);
			zephir_concat_self(&sql, &_19$$4 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "integer")) {
			ZEPHIR_INIT_VAR(&_20$$21);
			ZEPHIR_CONCAT_SV(&_20$$21, "`id` = ", filters);
			zephir_concat_self(&sql, &_20$$21 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(&_1, "string")) {
			zephir_concat_self(&sql, filters TSRMLS_CC);
			break;
		}
		zephir_concat_self_str(&sql, SL("TRUE") TSRMLS_CC);
		break;
	} while(0);

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &sql);
	zephir_array_fast_append(return_value, &values);
	RETURN_MM();

}

zend_object *zephir_init_properties_Vii_Db_QueryBuilder(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_groupby"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_groupby"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("_bindParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("_bindParams"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

