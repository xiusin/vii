
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_Model) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc, Model, vii, mvc_model, vii_mvc_model_method_entry, 0);

	zend_declare_property_null(vii_mvc_model_ce, SL("_source"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_model_ce, SL("_db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_model_ce, SL("queryBuilder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_Model, __construct) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fields_param = NULL, _0$$3, calledClass$$4, _1$$4, _2$$4, _3$$4, _4$$4, _5, _7, _8, _9, _10;
	zval fields;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&calledClass$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fields_param);

	if (!fields_param) {
		ZEPHIR_INIT_VAR(&fields);
		array_init(&fields);
	} else {
	ZVAL_COPY_VALUE(&fields, fields_param);
	}


	if ((zephir_method_exists_ex(this_ptr, SS("getsource") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getsource", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_source"), &_0$$3);
	} else {
		ZEPHIR_INIT_VAR(&calledClass$$4);
		zephir_get_called_class(&calledClass$$4 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "\\");
		ZEPHIR_CALL_FUNCTION(&_3$$4, "strrpos", NULL, 45, &calledClass$$4, &_2$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$4, (zephir_get_numberval(&_3$$4) + 1));
		ZEPHIR_INIT_NVAR(&_2$$4);
		zephir_substr(&_2$$4, &calledClass$$4, zephir_get_intval(&_4$$4), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_fast_strtolower(&_1$$4, &_2$$4);
		zephir_update_property_zval(this_ptr, SL("_source"), &_1$$4);
	}
	ZEPHIR_CALL_CE_STATIC(&_5, vii_ioc_ce, "getdefault", &_6, 32);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "db");
	ZEPHIR_CALL_METHOD(&_7, &_5, "get", NULL, 0, &_8);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_db"), &_7);
	zephir_read_property(&_9, this_ptr, SL("_db"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_10, &_9, "createbuilder", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("queryBuilder"), &_10);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_Model, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub, res, _0, _1, _17, _2$$3, _3$$5, _4$$5, _5$$5, _6$$6, _7$$6, _8$$4, _9$$4, _10$$4, _11$$7, _12$$7, _13$$8, _14$$8, _15$$9, _16$$9;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	}


	zephir_read_property(&_0, this_ptr, SL("queryBuilder"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_source"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "from", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(options) != IS_ARRAY) {
		zephir_read_property(&_2$$3, this_ptr, SL("queryBuilder"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "where", NULL, 0, options);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(options, SL("conditions"))) {
		if (zephir_array_isset_string(options, SL("bind"))) {
			zephir_read_property(&_3$$5, this_ptr, SL("queryBuilder"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_4$$5, options, SL("conditions"), PH_NOISY | PH_READONLY, "vii/mvc/model.zep", 30 TSRMLS_CC);
			zephir_array_fetch_string(&_5$$5, options, SL("bind"), PH_NOISY | PH_READONLY, "vii/mvc/model.zep", 30 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&res, &_3$$5, "parsewherearr", NULL, 0, &_4$$5, &_5$$5);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_6$$6, this_ptr, SL("queryBuilder"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_7$$6, options, SL("conditions"), PH_NOISY | PH_READONLY, "vii/mvc/model.zep", 32 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&res, &_6$$6, "parsewherearr", NULL, 0, &_7$$6);
			zephir_check_call_status();
		}
		zephir_read_property(&_8$$4, this_ptr, SL("queryBuilder"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_9$$4, &res, 0, PH_NOISY | PH_READONLY, "vii/mvc/model.zep", 34 TSRMLS_CC);
		zephir_array_fetch_long(&_10$$4, &res, 1, PH_NOISY | PH_READONLY, "vii/mvc/model.zep", 34 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_8$$4, "where", NULL, 0, &_9$$4, &_10$$4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(options, SL("limit"))) {
		zephir_read_property(&_11$$7, this_ptr, SL("queryBuilder"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_12$$7, options, SL("limit"), PH_NOISY | PH_READONLY, "vii/mvc/model.zep", 37 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_11$$7, "limit", NULL, 0, &_12$$7);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(options, SL("order"))) {
		zephir_read_property(&_13$$8, this_ptr, SL("queryBuilder"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_14$$8, options, SL("order"), PH_NOISY | PH_READONLY, "vii/mvc/model.zep", 40 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_13$$8, "orderby", NULL, 0, &_14$$8);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(options, SL("columns"))) {
		zephir_read_property(&_15$$9, this_ptr, SL("queryBuilder"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_16$$9, options, SL("columns"), PH_NOISY | PH_READONLY, "vii/mvc/model.zep", 43 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_15$$9, "columns", NULL, 0, &_16$$9);
		zephir_check_call_status();
	}
	zephir_read_property(&_17, this_ptr, SL("queryBuilder"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_17, "select", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Mvc_Model, getLastQuery) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("queryBuilder"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getlastquery", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

