
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Vii_Service) {

	ZEPHIR_REGISTER_CLASS(Vii, Service, vii, service, vii_service_method_entry, 0);

	zend_declare_property_null(vii_service_ce, SL("_default"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(vii_service_ce, SL("_instance"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_service_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	vii_service_ce->create_object = zephir_init_properties_Vii_Service;

	zend_class_implements(vii_service_ce TSRMLS_CC, 1, vii_interfaces_serviceinterface_ce);
	zend_class_implements(vii_service_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(vii_service_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

PHP_METHOD(Vii_Service, __construct) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(vii_service_ce, SL("_default") TSRMLS_CC);
	if (!(zephir_is_true(_0))) {
		zephir_update_static_property_ce(vii_service_ce, SL("_default"), &this_ptr TSRMLS_CC);
	}

}

/**
 * 设置服务
 */
PHP_METHOD(Vii_Service, set) {

	zend_bool _3$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, *_0 = NULL, *_1$$3, *_4$$5;
	zval *name = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, vii_exceptions_serviceexception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "the name : ", name, " has exists");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 4, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "vii/service.zep", 24 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(value) == IS_STRING) {
		zephir_update_property_array(this_ptr, SL("container"), name, value TSRMLS_CC);
	} else if (Z_TYPE_P(value) == IS_ARRAY) {
		if (!(zephir_array_isset_string(value, SS("className")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_serviceexception_ce, "Service::set param 2 must have className", "vii/service.zep", 30);
			return;
		}
		_3$$5 = zephir_array_isset_string(value, SS("arguments"));
		if (_3$$5) {
			ZEPHIR_OBS_VAR(_4$$5);
			zephir_array_fetch_string(&_4$$5, value, SL("arguments"), PH_NOISY, "vii/service.zep", 32 TSRMLS_CC);
			_3$$5 = Z_TYPE_P(_4$$5) != IS_ARRAY;
		}
		if (_3$$5) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_serviceexception_ce, "Service::set arguments must be array", "vii/service.zep", 33);
			return;
		}
		zephir_update_property_array(this_ptr, SL("container"), name, value TSRMLS_CC);
	} else if (Z_TYPE_P(value) == IS_OBJECT) {
		zephir_update_property_array(this_ptr, SL("container"), name, value TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_serviceexception_ce, "Service::set value is not support", "vii/service.zep", 39);
		return;
	}
	RETURN_THIS();

}

/**
 * 获取服务实例
 * @name string 服务名称
 */
PHP_METHOD(Vii_Service, get) {

	zend_class_entry *_7$$5, *_13$$8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_service = NULL, *_className = NULL, *_0 = NULL, *_3, *_17, *_18, *_1$$3, *_4$$4, *_16$$4, *_5$$5, *_6$$5 = NULL, *_8$$7, *_9$$7 = NULL, *_10$$7, *_11$$8, *_12$$8 = NULL, *_14$$10, *_15$$10;
	zval *name = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, name);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, vii_exceptions_serviceexception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "服务:", name, "未注册");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 4, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "vii/service.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
	if (!(zephir_array_isset(_3, name))) {
		_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
		zephir_array_fetch(&_service, _4$$4, name, PH_NOISY | PH_READONLY, "vii/service.zep", 55 TSRMLS_CC);
		if (Z_TYPE_P(_service) == IS_STRING) {
			ZEPHIR_INIT_VAR(_5$$5);
			zephir_fetch_safe_class(_6$$5, _service);
				_7$$5 = zend_fetch_class(Z_STRVAL_P(_6$$5), Z_STRLEN_P(_6$$5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(_5$$5, _7$$5);
			if (zephir_has_constructor(_5$$5 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, _5$$5, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			zephir_update_property_array(this_ptr, SL("_instance"), name, _5$$5 TSRMLS_CC);
		} else if (Z_TYPE_P(_service) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(_className);
			zephir_array_fetch_string(&_className, _service, SL("className"), PH_NOISY, "vii/service.zep", 59 TSRMLS_CC);
			if (zephir_array_isset_string(_service, SS("arguments"))) {
				ZEPHIR_INIT_VAR(_8$$7);
				object_init_ex(_8$$7, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
				ZEPHIR_CALL_METHOD(NULL, _8$$7, "__construct", NULL, 9, _className);
				zephir_check_call_status();
				zephir_array_fetch_string(&_10$$7, _service, SL("arguments"), PH_NOISY | PH_READONLY, "vii/service.zep", 61 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_9$$7, _8$$7, "newinstanceargs", NULL, 10, _10$$7);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("_instance"), name, _9$$7 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(_11$$8);
				zephir_fetch_safe_class(_12$$8, _className);
					_13$$8 = zend_fetch_class(Z_STRVAL_P(_12$$8), Z_STRLEN_P(_12$$8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(_11$$8, _13$$8);
				if (zephir_has_constructor(_11$$8 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, _11$$8, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				zephir_update_property_array(this_ptr, SL("_instance"), name, _11$$8 TSRMLS_CC);
			}
		} else if (Z_TYPE_P(_service) == IS_OBJECT) {
			if (zephir_instance_of_ev(_service, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_14$$10);
				ZEPHIR_INIT_VAR(_15$$10);
				array_init(_15$$10);
				ZEPHIR_CALL_USER_FUNC_ARRAY(_14$$10, _service, _15$$10);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("_instance"), name, _14$$10 TSRMLS_CC);
			} else {
				zephir_update_property_array(this_ptr, SL("_instance"), name, _service TSRMLS_CC);
			}
		}
		_16$$4 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
		zephir_array_unset(&_16$$4, name, PH_SEPARATE);
	}
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
	zephir_array_fetch(&_18, _17, name, PH_NOISY | PH_READONLY, "vii/service.zep", 74 TSRMLS_CC);
	RETURN_CTOR(_18);

}

/**
 * 检测服务是否已经被注册
 */
PHP_METHOD(Vii_Service, has) {

	zend_bool _1;
	zval *name_param = NULL, *_0, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	_1 = !(zephir_array_isset(_0, name));
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
		_1 = !(zephir_array_isset(_2, name));
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * 重新定义服务
 */
PHP_METHOD(Vii_Service, setDefinition) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "del", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注销已经定义的服务
 */
PHP_METHOD(Vii_Service, del) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL, *_1, *_3, *_2$$4, *_4$$5;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, name);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	if (zephir_array_isset(_1, name)) {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
		zephir_array_unset(&_2$$4, name, PH_SEPARATE);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
	if (zephir_array_isset(_3, name)) {
		_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
		zephir_array_unset(&_4$$5, name, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 静态获取已经注册的服务
 */
PHP_METHOD(Vii_Service, getDefault) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(vii_service_ce, SL("_default") TSRMLS_CC);
	RETURN_CTORW(_0);

}

PHP_METHOD(Vii_Service, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Service, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "del", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Service, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Service, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Service, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, offset, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Service, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "del", NULL, 0, offset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Service, setService) {

	zval *_service;

	zephir_fetch_params(0, 1, 0, &_service);




}

PHP_METHOD(Vii_Service, getService) {

	


}

/**
 * 统计服务个数
 */
PHP_METHOD(Vii_Service, count) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	RETURN_LONG((zephir_fast_count_int(_0 TSRMLS_CC) + zephir_fast_count_int(_1 TSRMLS_CC)));

}

zend_object_value zephir_init_properties_Vii_Service(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("container"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_instance"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("_instance"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

