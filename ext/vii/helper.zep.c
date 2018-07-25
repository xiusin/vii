
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
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Vii_Helper) {

	ZEPHIR_REGISTER_CLASS(Vii, Helper, vii, helper, vii_helper_method_entry, 0);

	return SUCCESS;

}

/**
 * 对象转数组方法
 */
PHP_METHOD(Vii_Helper, obj2arr) {

	zend_bool _4$$3;
	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *obj, obj_sub, arr, key, val, *_0, _3$$3;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&obj_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);

	if (unlikely(Z_TYPE_P(obj) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'obj' must be a object") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	ZEPHIR_CALL_FUNCTION(&arr, "get_object_vars", NULL, 56, obj);
	zephir_check_call_status();
	zephir_is_iterable(&arr, 1, "vii/helper.zep", 15);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arr), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&val);
		ZVAL_COPY(&val, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		_4$$3 = Z_TYPE_P(&val) == IS_ARRAY;
		if (!(_4$$3)) {
			_4$$3 = Z_TYPE_P(&val) == IS_OBJECT;
		}
		if (_4$$3) {
			ZEPHIR_CALL_SELF(&_3$$3, "obj2arr", &_5, 0, &val);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&_3$$3, &val);
		}
		ZEPHIR_CPY_WRT(&val, &_3$$3);
		zephir_array_update_zval(&arr, &key, &val, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(arr);

}

PHP_METHOD(Vii_Helper, getOs) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval _SERVER, browser, _0, _1, _2, _5, _6, _7, _8, _9, _10;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&browser);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	zephir_array_fetch_string(&_0, &_SERVER, SL("HTTP_USER_AGENT"), PH_NOISY | PH_READONLY, "vii/helper.zep", 21 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "iphone");
	ZEPHIR_CALL_FUNCTION(&_2, "stripos", &_3, 86, &_0, &_1);
	zephir_check_call_status();
	_4 = zephir_is_true(&_2);
	if (!(_4)) {
		zephir_array_fetch_string(&_5, &_SERVER, SL("HTTP_USER_AGENT"), PH_NOISY | PH_READONLY, "vii/helper.zep", 21 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "ipod");
		ZEPHIR_CALL_FUNCTION(&_6, "stripos", &_3, 86, &_5, &_1);
		zephir_check_call_status();
		_4 = zephir_is_true(&_6);
	}
	zephir_array_fetch_string(&_7, &_SERVER, SL("HTTP_USER_AGENT"), PH_NOISY | PH_READONLY, "vii/helper.zep", 23 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ipad");
	ZEPHIR_CALL_FUNCTION(&_8, "stripos", &_3, 86, &_7, &_1);
	zephir_check_call_status();
	zephir_array_fetch_string(&_9, &_SERVER, SL("HTTP_USER_AGENT"), PH_NOISY | PH_READONLY, "vii/helper.zep", 25 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "android");
	ZEPHIR_CALL_FUNCTION(&_10, "stripos", &_3, 86, &_9, &_1);
	zephir_check_call_status();
	if (_4) {
		ZEPHIR_INIT_VAR(&browser);
		ZVAL_STRING(&browser, "ios");
	} else if (zephir_is_true(&_8)) {
		ZEPHIR_INIT_NVAR(&browser);
		ZVAL_STRING(&browser, "ios");
	} else if (zephir_is_true(&_10)) {
		ZEPHIR_INIT_NVAR(&browser);
		ZVAL_STRING(&browser, "android");
	} else {
		ZEPHIR_INIT_NVAR(&browser);
		ZVAL_STRING(&browser, "other");
	}
	RETURN_CCTOR(browser);

}

PHP_METHOD(Vii_Helper, getHttpMethod) {

	zval _SERVER, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_0);

	zephir_get_global(&_SERVER, SL("_SERVER"));

	zephir_array_fetch_string(&_0, &_SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "vii/helper.zep", 35 TSRMLS_CC);
	zephir_fast_strtoupper(return_value, &_0);
	return;

}

/**
 * 获取文件扩展
 */
PHP_METHOD(Vii_Helper, getFileExtension) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1;
	zval path;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, ".");
	ZEPHIR_CALL_FUNCTION(&_1, "strrpos", NULL, 45, &path, &_0);
	zephir_check_call_status();
	zephir_substr(return_value, &path, zephir_get_intval(&_1), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	RETURN_MM();

}

PHP_METHOD(Vii_Helper, start_with) {

	zval *_string_param = NULL, *_find_param = NULL;
	zval _string, _find;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_string);
	ZVAL_UNDEF(&_find);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &_string_param, &_find_param);

	if (unlikely(Z_TYPE_P(_string_param) != IS_STRING && Z_TYPE_P(_string_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter '_string' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(_string_param) == IS_STRING)) {
		zephir_get_strval(&_string, _string_param);
	} else {
		ZEPHIR_INIT_VAR(&_string);
		ZVAL_EMPTY_STRING(&_string);
	}
	if (unlikely(Z_TYPE_P(_find_param) != IS_STRING && Z_TYPE_P(_find_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter '_find' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(_find_param) == IS_STRING)) {
		zephir_get_strval(&_find, _find_param);
	} else {
		ZEPHIR_INIT_VAR(&_find);
		ZVAL_EMPTY_STRING(&_find);
	}


	RETURN_MM_BOOL(zephir_start_with(&_string, &_find, NULL));

}

/**
 * I18n快速助手
 * @type {Array}
 */
PHP_METHOD(Vii_Helper, _t) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval value;
	zval *strOrId_param = NULL, *value_param = NULL, _0;
	zval strOrId;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&strOrId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strOrId_param, &value_param);

	if (unlikely(Z_TYPE_P(strOrId_param) != IS_STRING && Z_TYPE_P(strOrId_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'strOrId' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(strOrId_param) == IS_STRING)) {
		zephir_get_strval(&strOrId, strOrId_param);
	} else {
		ZEPHIR_INIT_VAR(&strOrId);
		ZVAL_EMPTY_STRING(&strOrId);
	}
	if (!value_param) {
		ZEPHIR_INIT_VAR(&value);
		array_init(&value);
	} else {
	ZVAL_COPY_VALUE(&value, value_param);
	}


	ZEPHIR_CALL_CE_STATIC(&_0, vii_i18n_ce, "getdefault", &_1, 87);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "translate", NULL, 0, &strOrId, &value);
	zephir_check_call_status();
	RETURN_MM();

}

