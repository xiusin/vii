
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Vii_Router) {

	ZEPHIR_REGISTER_CLASS(Vii, Router, vii, router, vii_router_method_entry, 0);

	zend_declare_property_null(vii_router_ce, SL("service"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_router_ce, SL("routes"), ZEND_ACC_PRIVATE TSRMLS_CC);

	vii_router_ce->create_object = zephir_init_properties_Vii_Router;

	zend_class_implements(vii_router_ce TSRMLS_CC, 1, vii_interfaces_serviceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Router, setService) {

	zval *_service;

	zephir_fetch_params(0, 1, 0, &_service);



	zephir_update_property_this(this_ptr, SL("service"), _service TSRMLS_CC);

}

PHP_METHOD(Vii_Router, getService) {

	

	RETURN_MEMBER(this_ptr, "service");

}

PHP_METHOD(Vii_Router, __construct) {

	zval *_1$$3, *_4$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *hasDefaultRouter_param = NULL, *_0$$3 = NULL, *_2$$3 = NULL;
	zend_bool hasDefaultRouter;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &hasDefaultRouter_param);

	if (!hasDefaultRouter_param) {
		hasDefaultRouter = 1;
	} else {
	if (unlikely(Z_TYPE_P(hasDefaultRouter_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hasDefaultRouter' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	hasDefaultRouter = Z_BVAL_P(hasDefaultRouter_param);
	}


	if (hasDefaultRouter) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, vii_mvc_route_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(_1$$3, SS("controller"), 1);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "#^/([\\w0-9\\_\\-]+)[/]{0,1}$#u", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", &_3, 38, _2$$3, _1$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("routes"), _0$$3 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_0$$3);
		object_init_ex(_0$$3, vii_mvc_route_ce);
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_create_array(_4$$3, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(_4$$3, SS("controller"), 1);
		add_assoc_long_ex(_4$$3, SS("action"), 2);
		add_assoc_long_ex(_4$$3, SS("params"), 3);
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_STRING(_2$$3, "#^/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*$#u", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", &_3, 38, _2$$3, _4$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("routes"), _0$$3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Router, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattren_param = NULL, *path, *_route = NULL;
	zval *pattren = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pattren_param, &path);

	if (unlikely(Z_TYPE_P(pattren_param) != IS_STRING && Z_TYPE_P(pattren_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattren' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattren_param) == IS_STRING)) {
		zephir_get_strval(pattren, pattren_param);
	} else {
		ZEPHIR_INIT_VAR(pattren);
		ZVAL_EMPTY_STRING(pattren);
	}


	ZEPHIR_INIT_VAR(_route);
	object_init_ex(_route, vii_mvc_route_ce);
	ZEPHIR_CALL_METHOD(NULL, _route, "__construct", NULL, 38, pattren, path);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("routes"), _route TSRMLS_CC);
	RETURN_CCTOR(_route);

}

PHP_METHOD(Vii_Router, handle) {

	


}

PHP_METHOD(Vii_Router, addGet) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattren_param = NULL, *path, *_0 = NULL, *_2;
	zval *pattren = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pattren_param, &path);

	if (unlikely(Z_TYPE_P(pattren_param) != IS_STRING && Z_TYPE_P(pattren_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattren' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattren_param) == IS_STRING)) {
		zephir_get_strval(pattren, pattren_param);
	} else {
		ZEPHIR_INIT_VAR(pattren);
		ZVAL_EMPTY_STRING(pattren);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "add", NULL, 0, pattren, path);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "get", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_CALL_METHOD(NULL, _0, "via", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Router, addPost) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattren_param = NULL, *path, *_0 = NULL, *_2;
	zval *pattren = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pattren_param, &path);

	if (unlikely(Z_TYPE_P(pattren_param) != IS_STRING && Z_TYPE_P(pattren_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattren' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattren_param) == IS_STRING)) {
		zephir_get_strval(pattren, pattren_param);
	} else {
		ZEPHIR_INIT_VAR(pattren);
		ZVAL_EMPTY_STRING(pattren);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "add", NULL, 0, pattren, path);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "post", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_CALL_METHOD(NULL, _0, "via", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Vii_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("routes"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("routes"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

