
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Vii_Request) {

	ZEPHIR_REGISTER_CLASS(Vii, Request, vii, request, vii_request_method_entry, 0);

	zend_declare_property_string(vii_request_ce, SL("method"), "GET", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_request_ce, SL("cookie"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_request_ce, SL("file"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_request_ce, SL("server"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(vii_request_ce TSRMLS_CC, 1, vii_interfaces_iocinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Request, __construct) {

	zval *_FILES, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "REQUEST_METHOD");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "server", NULL, 135, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("method"), &_0);
	zephir_update_property_zval(this_ptr, SL("file"), _FILES);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Request, setIoc) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_ioc, _ioc_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_ioc_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_ioc);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cookie");
	ZEPHIR_CALL_METHOD(&_0, _ioc, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("cookie"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Request, getIoc) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Vii_Request, server) {

	zval *key, key_sub, *_default = NULL, _default_sub, *_SERVER, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 1, &key, &_default);

	if (!_default) {
		_default = &_default_sub;
		ZEPHIR_INIT_VAR(_default);
		ZVAL_STRING(_default, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_array_isset(_SERVER, key)) {
		zephir_array_fetch(&_0, _SERVER, key, PH_NOISY, "vii/request.zep", 32 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, _default);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(Vii_Request, getReferer) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_REFERER");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "server", NULL, 135, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Request, getCookie) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *_default = NULL, _default_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &_default);

	if (!_default) {
		_default = &_default_sub;
		_default = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("cookie"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, key, _default);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Request, setCookie) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *value, value_sub, *_time = NULL, _time_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_time_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &value, &_time);

	if (!_time) {
		_time = &_time_sub;
		ZEPHIR_INIT_VAR(_time);
		ZVAL_STRING(_time, "");
	}


	zephir_read_property(&_0, this_ptr, SL("cookie"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, key, value, _time);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Vii_Request, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

PHP_METHOD(Vii_Request, flashCookie) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *_default = NULL, _default_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &_default);

	if (!_default) {
		_default = &_default_sub;
		ZEPHIR_INIT_VAR(_default);
		ZVAL_STRING(_default, "");
	}


	zephir_read_property(&_0, this_ptr, SL("cookie"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "flashget", NULL, 0, key, _default);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Request, clientIp) {

	zval ip, _0, _1, _3, _4, _5$$3, _6$$4, _7$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP_CLIENT_IP");
	ZEPHIR_CALL_FUNCTION(&_1, "getenv", &_2, 136, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "HTTP_X_FORWARDED_FOR");
	ZEPHIR_CALL_FUNCTION(&_3, "getenv", &_2, 136, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "REMOTE_ADDR");
	ZEPHIR_CALL_FUNCTION(&_4, "getenv", &_2, 136, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "HTTP_CLIENT_IP");
		ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, 136, &_5$$3);
		zephir_check_call_status();
	} else if (zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "HTTP_X_FORWARDED_FOR");
		ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, 136, &_6$$4);
		zephir_check_call_status();
	} else if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "REMOTE_ADDR");
		ZEPHIR_CALL_FUNCTION(&ip, "getenv", &_2, 136, &_7$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&ip);
		ZVAL_BOOL(&ip, 0);
	}
	RETURN_CCTOR(&ip);

}

PHP_METHOD(Vii_Request, getRequestTime) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "REQUEST_TIME");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "server", NULL, 135, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Request, isweixin) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "HTTP_USER_AGENT");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "server", NULL, 135, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "MicroMessenger");
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, &_0, &_1, 0 );
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_2));

}

PHP_METHOD(Vii_Request, pathinfo) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PATH_INFO");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "server", NULL, 135, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Request, getPost) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *def = NULL, def_sub, *filter = NULL, filter_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&def_sub);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &key, &def, &filter);

	if (!key) {
		key = &key_sub;
		ZEPHIR_INIT_VAR(key);
		ZVAL_STRING(key, "");
	}
	if (!def) {
		def = &def_sub;
		ZEPHIR_INIT_VAR(def);
		ZVAL_STRING(def, "");
	}
	if (!filter) {
		filter = &filter_sub;
		ZEPHIR_INIT_VAR(filter);
		ZVAL_STRING(filter, "");
	}


	ZVAL_LONG(&_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_get_post", NULL, 0, key, def, filter, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Request, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *def = NULL, def_sub, *filter = NULL, filter_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&def_sub);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &key, &def, &filter);

	if (!key) {
		key = &key_sub;
		ZEPHIR_INIT_VAR(key);
		ZVAL_STRING(key, "");
	}
	if (!def) {
		def = &def_sub;
		ZEPHIR_INIT_VAR(def);
		ZVAL_STRING(def, "");
	}
	if (!filter) {
		filter = &filter_sub;
		ZEPHIR_INIT_VAR(filter);
		ZVAL_STRING(filter, "");
	}


	ZVAL_LONG(&_0, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_get_post", NULL, 0, key, def, filter, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Request, _get_post) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *def = NULL, def_sub, *filter = NULL, filter_sub, *type, type_sub, *_GET, *_POST, data, _0$$9, _1$$9, _2$$8, _3$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&def_sub);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0$$9);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$10);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 1, 3, &key, &def, &filter, &type);

	if (!key) {
		key = &key_sub;
		ZEPHIR_INIT_VAR(key);
		ZVAL_STRING(key, "");
	}
	if (!def) {
		def = &def_sub;
		ZEPHIR_INIT_VAR(def);
		ZVAL_STRING(def, "");
	}
	if (!filter) {
		filter = &filter_sub;
		ZEPHIR_INIT_VAR(filter);
		ZVAL_STRING(filter, "");
	}


	if (ZEPHIR_IS_LONG(type, 0)) {
		ZEPHIR_CPY_WRT(&data, _GET);
	} else {
		ZEPHIR_CPY_WRT(&data, _POST);
	}
	if (ZEPHIR_IS_EMPTY(key)) {
		RETURN_CCTOR(&data);
	}
	if (zephir_is_true(key)) {
		if (zephir_array_isset(&data, key)) {
			if (!(ZEPHIR_IS_EMPTY(filter))) {
				if (!(zephir_is_callable(filter TSRMLS_CC))) {
					ZEPHIR_INIT_VAR(&_0$$9);
					object_init_ex(&_0$$9, vii_exceptions_runtimeexception_ce);
					ZEPHIR_INIT_VAR(&_1$$9);
					ZEPHIR_CONCAT_VS(&_1$$9, filter, " can not callable");
					ZEPHIR_CALL_METHOD(NULL, &_0$$9, "__construct", NULL, 3, &_1$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_0$$9, "vii/request.zep", 122 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_2$$8, &data, key, PH_NOISY | PH_READONLY, "vii/request.zep", 124 TSRMLS_CC);
				ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(filter, NULL, 0, &_2$$8);
				zephir_check_call_status();
				RETURN_MM();
			} else {
				zephir_array_fetch(&_3$$10, &data, key, PH_NOISY | PH_READONLY, "vii/request.zep", 126 TSRMLS_CC);
				RETURN_CTOR(&_3$$10);
			}
		} else {
			RETVAL_ZVAL(def, 1, 0);
			RETURN_MM();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Request, hasFiles) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
		_1 = ((zephir_fast_count_int(&_2 TSRMLS_CC)) ? 1 : 0);
	}
	if (_1) {
		RETURN_BOOL(1);
	}
	RETURN_BOOL(0);

}

PHP_METHOD(Vii_Request, getUploadedFiles) {

	zend_bool _2$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *only_success = NULL, only_success_sub, __$false, files, v, _0, *_1, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&only_success_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &only_success);

	if (!only_success) {
		only_success = &only_success_sub;
		only_success = &__$false;
	}


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	zephir_read_property(&_0, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "vii/request.zep", 151);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _1);
		_2$$3 = zephir_is_true(only_success);
		if (_2$$3) {
			zephir_array_fetch_string(&_3$$3, &v, SL("error"), PH_NOISY | PH_READONLY, "vii/request.zep", 146 TSRMLS_CC);
			_2$$3 = !ZEPHIR_IS_STRING(&_3$$3, "");
		}
		if (_2$$3) {
			continue;
		}
		ZEPHIR_INIT_NVAR(&_4$$3);
		object_init_ex(&_4$$3, vii_uploadfileinfo_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", &_5, 137, &v);
		zephir_check_call_status();
		zephir_array_append(&files, &_4$$3, PH_SEPARATE, "vii/request.zep", 149);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	RETURN_CCTOR(&files);

}

void zephir_init_static_properties_Vii_Request(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(vii_request_ce, ZEND_STRL("server"), &_0);
	ZEPHIR_MM_RESTORE();

}

