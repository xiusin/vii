
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Vii_Db_Pdo) {

	ZEPHIR_REGISTER_CLASS(Vii\\Db, Pdo, vii, db_pdo, vii_db_pdo_method_entry, 0);

	zend_declare_property_null(vii_db_pdo_ce, SL("pdo"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Vii_Db_Pdo, __construct) {

	zend_class_entry *_4$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval user, password;
	zval *dsn, dsn_sub, *user_param = NULL, *password_param = NULL, *options_param = NULL, e, _0, _1, pdo$$4, _2$$4, _3$$4, _5$$5, _6$$5, _7$$5;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&dsn_sub);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&pdo$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &dsn, &user_param, &password_param, &options_param);

	if (!user_param) {
		ZEPHIR_INIT_VAR(&user);
		ZVAL_STRING(&user, "");
	} else {
		zephir_get_strval(&user, user_param);
	}
	if (!password_param) {
		ZEPHIR_INIT_VAR(&password);
		ZVAL_STRING(&password, "");
	} else {
		zephir_get_strval(&password, password_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZVAL_COPY_VALUE(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "pdo");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 31, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Pdo扩展没有安装，无法使用数据库服务", "vii/db/pdo.zep", 9);
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&pdo$$4);
		ZVAL_STRING(&pdo$$4, "Pdo");
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_fetch_safe_class(_3$$4, pdo$$4);
		_4$$4 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$4), Z_STRLEN_P(&_3$$4), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_2$$4, _4$$4);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0, dsn, &user, &password, &options);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_update_property_zval(this_ptr, SL("pdo"), &_2$$4);

	try_end_1:

	if (EG(exception)) {
		ZVAL_OBJ(&e, EG(exception));
		Z_ADDREF_P(&e);
		if (zephir_instance_of_ev(&e, php_pdo_get_exception() TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_INIT_VAR(&_5$$5);
			object_init_ex(&_5$$5, php_pdo_get_exception());
			ZEPHIR_CALL_METHOD(&_6$$5, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$5);
			ZEPHIR_CONCAT_SV(&_7$$5, "连接数据库失败 [原因]:", &_6$$5);
			ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 0, &_7$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$5, "vii/db/pdo.zep", 15 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Db_Pdo, __call) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, arguments_sub, __$null, _1;
	zval method;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(&method, method_param);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("pdo"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, arguments);
	zephir_check_call_status();
	RETURN_MM();

}

