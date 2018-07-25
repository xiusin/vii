
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Vii_Session_Adapter_Memcache) {

	ZEPHIR_REGISTER_CLASS_EX(Vii\\Session\\Adapter, Memcache, vii, session_adapter_memcache, vii_session_nativesession_ce, vii_session_adapter_memcache_method_entry, 0);

	zend_declare_property_null(vii_session_adapter_memcache_ce, SL("_memcache"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(vii_session_adapter_memcache_ce, SL("_maxlifetime"), 3600, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(vii_session_adapter_memcache_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	return SUCCESS;

}

PHP_METHOD(Vii_Session_Adapter_Memcache, __construct) {

	zend_bool _3$$5, _4$$5;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1, _8, _2$$4, server$$5, _5$$5, _6$$5;
	zval options, _7, _9, _10, _11, _12, _13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&server$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "memcache");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 30, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_runtimeexception_ce, "必须安装php-memcached扩展", "vii/session/adapter/memcache.zep", 11);
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("memcache")));
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_memcache"), &_0);
	if (zephir_array_isset_string(&options, SL("servers"))) {
		zephir_array_fetch_string(&_2$$4, &options, SL("servers"), PH_NOISY | PH_READONLY, "vii/session/adapter/memcache.zep", 16 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addservers", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&options, SL("server"))) {
		ZEPHIR_OBS_VAR(&server$$5);
		zephir_array_fetch_string(&server$$5, &options, SL("server"), PH_NOISY, "vii/session/adapter/memcache.zep", 21 TSRMLS_CC);
		_3$$5 = Z_TYPE_P(&server$$5) != IS_ARRAY;
		if (!(_3$$5)) {
			_3$$5 = !(zephir_array_isset_string(&server$$5, SL("host")));
		}
		_4$$5 = _3$$5;
		if (!(_4$$5)) {
			_4$$5 = !(zephir_array_isset_string(&server$$5, SL("port")));
		}
		if (_4$$5) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_runtimeexception_ce, "配置Session::Memcache参数server必须为数组并且包括host和port", "vii/session/adapter/memcache.zep", 23);
			return;
		}
		zephir_array_fetch_string(&_5$$5, &server$$5, SL("host"), PH_NOISY | PH_READONLY, "vii/session/adapter/memcache.zep", 25 TSRMLS_CC);
		zephir_array_fetch_string(&_6$$5, &server$$5, SL("port"), PH_NOISY | PH_READONLY, "vii/session/adapter/memcache.zep", 25 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addserver", NULL, 0, &_5$$5, &_6$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_7, this_ptr);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "open");
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_9, this_ptr);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "close");
	zephir_array_fast_append(&_9, &_8);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_10, this_ptr);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "read");
	zephir_array_fast_append(&_10, &_8);
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_11, this_ptr);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "write");
	zephir_array_fast_append(&_11, &_8);
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_12, this_ptr);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "destroy");
	zephir_array_fast_append(&_12, &_8);
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_13, this_ptr);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "gc");
	zephir_array_fast_append(&_13, &_8);
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 139, &_7, &_9, &_10, &_11, &_12, &_13);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, vii_session_adapter_memcache_ce, getThis(), "__construct", &_14, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Session_Adapter_Memcache, addServer) {

	zend_long port, ZEPHIR_LAST_CALL_STATUS;
	zval *ip_param = NULL, *port_param = NULL, _0, _1;
	zval ip;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ip_param, &port_param);

	if (UNEXPECTED(Z_TYPE_P(ip_param) != IS_STRING && Z_TYPE_P(ip_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ip' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(ip_param) == IS_STRING)) {
		zephir_get_strval(&ip, ip_param);
	} else {
		ZEPHIR_INIT_VAR(&ip);
		ZVAL_EMPTY_STRING(&ip);
	}
	port = zephir_get_intval(port_param);


	zephir_read_property(&_0, this_ptr, SL("_memcache"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, port);
	ZEPHIR_CALL_METHOD(NULL, &_0, "addserver", NULL, 0, &ip, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 一次性添加多台服务器
 */
PHP_METHOD(Vii_Session_Adapter_Memcache, addServers) {

	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *servers_param = NULL, server, _0, *_1, _4$$3, _5$$3, _6$$3;
	zval servers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&servers);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &servers_param);

	ZEPHIR_OBS_COPY_OR_DUP(&servers, servers_param);


	ZEPHIR_INIT_VAR(&server);
	array_init(&server);
	ZEPHIR_INIT_VAR(&_0);
	zephir_is_iterable(&servers, 0, "vii/session/adapter/memcache.zep", 51);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&servers), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&_0);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&_0, _3);
		} else {
			ZVAL_LONG(&_0, _2);
		}
		ZEPHIR_INIT_NVAR(&server);
		ZVAL_COPY(&server, _1);
		zephir_read_property(&_4$$3, this_ptr, SL("_memcache"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_5$$3, &server, SL("host"), PH_NOISY | PH_READONLY, "vii/session/adapter/memcache.zep", 49 TSRMLS_CC);
		zephir_array_fetch_string(&_6$$3, &server, SL("port"), PH_NOISY | PH_READONLY, "vii/session/adapter/memcache.zep", 49 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "addserver", NULL, 0, &_5$$3, &_6$$3);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&server);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Session_Adapter_Memcache, open) {

	zval *save_path_param = NULL, *session_name_param = NULL;
	zval save_path, session_name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&save_path);
	ZVAL_UNDEF(&session_name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &save_path_param, &session_name_param);

	zephir_get_strval(&save_path, save_path_param);
	zephir_get_strval(&session_name, session_name_param);


	RETURN_MM_BOOL(1);

}

PHP_METHOD(Vii_Session_Adapter_Memcache, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id_param = NULL, _0, _1;
	zval session_id, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_id);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &session_id_param);

	if (UNEXPECTED(Z_TYPE_P(session_id_param) != IS_STRING && Z_TYPE_P(session_id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(session_id_param) == IS_STRING)) {
		zephir_get_strval(&session_id, session_id_param);
	} else {
		ZEPHIR_INIT_VAR(&session_id);
		ZVAL_EMPTY_STRING(&session_id);
	}


	zephir_read_property(&_0, this_ptr, SL("_memcache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &session_id);
	zephir_check_call_status();
	zephir_get_strval(&_2, &_1);
	RETURN_CTOR(&_2);

}

PHP_METHOD(Vii_Session_Adapter_Memcache, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id_param = NULL, *session_data_param = NULL, _0, _1, _2;
	zval session_id, session_data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_id);
	ZVAL_UNDEF(&session_data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &session_id_param, &session_data_param);

	if (UNEXPECTED(Z_TYPE_P(session_id_param) != IS_STRING && Z_TYPE_P(session_id_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_id' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(session_id_param) == IS_STRING)) {
		zephir_get_strval(&session_id, session_id_param);
	} else {
		ZEPHIR_INIT_VAR(&session_id);
		ZVAL_EMPTY_STRING(&session_id);
	}
	if (UNEXPECTED(Z_TYPE_P(session_data_param) != IS_STRING && Z_TYPE_P(session_data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'session_data' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(session_data_param) == IS_STRING)) {
		zephir_get_strval(&session_data, session_data_param);
	} else {
		ZEPHIR_INIT_VAR(&session_data);
		ZVAL_EMPTY_STRING(&session_data);
	}


	zephir_read_property(&_0, this_ptr, SL("_memcache"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_maxlifetime"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &session_id, &session_data, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Session_Adapter_Memcache, destroy) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *session_id_param = NULL, sessionid, _0, _1, _2$$5;
	zval session_id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_id);
	ZVAL_UNDEF(&sessionid);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &session_id_param);

	if (!session_id_param) {
		ZEPHIR_INIT_VAR(&session_id);
		ZVAL_STRING(&session_id, "");
	} else {
		zephir_get_strval(&session_id, session_id_param);
	}


	if (!(!(Z_TYPE_P(&session_id) == IS_UNDEF) && Z_STRLEN_P(&session_id))) {
		ZEPHIR_CALL_METHOD(&sessionid, this_ptr, "getid", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&sessionid, &session_id);
	}
	zephir_read_property(&_0, this_ptr, SL("_memcache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &sessionid);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		zephir_read_property(&_2$$5, this_ptr, SL("_memcache"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "delete", NULL, 0, &sessionid);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Vii_Session_Adapter_Memcache, gc) {

	zval *maxlifetime_param = NULL;
	zend_long maxlifetime;
	zval *this_ptr = getThis();


	zephir_fetch_params(0, 1, 0, &maxlifetime_param);

	maxlifetime = zephir_get_intval(maxlifetime_param);


	RETURN_BOOL(1);

}

PHP_METHOD(Vii_Session_Adapter_Memcache, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

