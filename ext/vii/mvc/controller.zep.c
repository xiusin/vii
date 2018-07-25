
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_Controller) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc, Controller, vii, mvc_controller, vii_mvc_controller_method_entry, 0);

	zend_declare_property_null(vii_mvc_controller_ce, SL("ioc"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_class_implements(vii_mvc_controller_ce TSRMLS_CC, 1, vii_interfaces_iocinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_Controller, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	if ((zephir_method_exists_ex(this_ptr, SL("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialize", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_Controller, display) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *module, module_sub, *controller, controller_sub, *action, action_sub, view, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module_sub);
	ZVAL_UNDEF(&controller_sub);
	ZVAL_UNDEF(&action_sub);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &module, &controller, &action);



	zephir_read_property(&_0, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "view");
	ZEPHIR_CALL_METHOD(&view, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, controller, "/", action);
	ZEPHIR_CALL_METHOD(&_3, &view, "getvars", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&view, "render", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 跳转到根目录
 */
PHP_METHOD(Vii_Mvc_Controller, goHome) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "redirect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 重定向 利用response
 */
PHP_METHOD(Vii_Mvc_Controller, redirect) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Vii_Mvc_Controller, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Mvc_Controller, setIoc) {

	zval *_ioc, _ioc_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_ioc_sub);

	zephir_fetch_params(0, 1, 0, &_ioc);



	zephir_update_property_zval(this_ptr, SL("ioc"), _ioc);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_Controller, getIoc) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "ioc");

}

