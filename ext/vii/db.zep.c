
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Vii_Db) {

	ZEPHIR_REGISTER_CLASS(Vii, Db, vii, db, vii_db_method_entry, 0);

	zend_declare_property_null(vii_db_ce, SL("_queryBuilder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_db_ce, SL("driver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Vii_Db, getDriver) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "driver");

}

PHP_METHOD(Vii_Db, setDriver) {

	zval *driver, driver_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver_sub);

	zephir_fetch_params(0, 1, 0, &driver);



	zephir_update_property_zval(this_ptr, SL("driver"), driver);
	RETURN_THISW();

}

PHP_METHOD(Vii_Db, __construct) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *driver, driver_sub, *host = NULL, host_sub, *port = NULL, port_sub, *name = NULL, name_sub, *user = NULL, user_sub, *password = NULL, password_sub, *options_param = NULL, __$null, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver_sub);
	ZVAL_UNDEF(&host_sub);
	ZVAL_UNDEF(&port_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&password_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &driver, &host, &port, &name, &user, &password, &options_param);

	if (!host) {
		host = &host_sub;
		host = &__$null;
	}
	if (!port) {
		port = &port_sub;
		port = &__$null;
	}
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}
	if (!user) {
		user = &user_sub;
		user = &__$null;
	}
	if (!password) {
		password = &password_sub;
		password = &__$null;
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	_0 = Z_TYPE_P(driver) == IS_OBJECT;
	if (_0) {
		_0 = zephir_is_instance_of(driver, SL("Vii\\DbInterface") TSRMLS_CC);
	}
	if (_0) {
		zephir_update_property_zval(this_ptr, SL("driver"), driver);
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, vii_db_pdo_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_VSVSVSV(&_2$$4, driver, ":host=", host, ";port=", port, ";dbname=", name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 28, &_2$$4, user, password, &options);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("driver"), &_1$$4);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建构造器
 */
PHP_METHOD(Vii_Db, createBuilder) {

	zval _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_queryBuilder"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, vii_db_querybuilder_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 29);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_queryBuilder"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "_queryBuilder");

}

/**
 * 开启数据库事务
 */
PHP_METHOD(Vii_Db, begin) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("driver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "begintransaction", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 回滚事务
 */
PHP_METHOD(Vii_Db, rollback) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("driver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "rollback", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 提交事务
 */
PHP_METHOD(Vii_Db, commit) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("driver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "commit", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Db, __call) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, arguments_sub, __$null, _1;
	zval method;
	zval *this_ptr = getThis();

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
	zephir_read_property(&_1, this_ptr, SL("driver"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, arguments);
	zephir_check_call_status();
	RETURN_MM();

}

