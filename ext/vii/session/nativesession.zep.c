
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


/**
 * 封装原生SESSION操作,可以将
 */
ZEPHIR_INIT_CLASS(Vii_Session_NativeSession) {

	ZEPHIR_REGISTER_CLASS(Vii\\Session, NativeSession, vii, session_nativesession, vii_session_nativesession_method_entry, 0);

	zend_declare_property_null(vii_session_nativesession_ce, SL("_uniqueId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(vii_session_nativesession_ce, SL("_started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_session_nativesession_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(vii_session_nativesession_ce, SL("_maxlifetime"), 86400, ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_long(vii_session_nativesession_ce, SL("SESSION_ACTIVE"), 2);

	zephir_declare_class_constant_long(vii_session_nativesession_ce, SL("SESSION_NONE"), 1);

	zephir_declare_class_constant_long(vii_session_nativesession_ce, SL("SESSION_DISABLED"), 0);

	zend_class_implements(vii_session_nativesession_ce TSRMLS_CC, 1, vii_interfaces_sessionadapterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Session_NativeSession, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub, __$null, _0, _1;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.auto_start");
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 5, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(&_1, 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_runtimeexception_ce, "Session::__construct 不接受php.ini的配置信息内开启session.auto_start", "vii/session/nativesession.zep", 21);
		return;
	}
	if (Z_TYPE_P(options) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, options);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 开启SESSION 需要检测是否已经发送过header避免错误
 */
PHP_METHOD(Vii_Session_NativeSession, start) {

	zend_bool _2;
	zval __$true, __$false, _0, _1, _3;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 6);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_runtimeexception_ce, "Session::start 之前不要进行header头发送信息", "vii/session/nativesession.zep", 34);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("_started"), PH_NOISY_CC | PH_READONLY);
	_2 = !zephir_is_true(&_1);
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "status", NULL, 0);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_LONG_IDENTICAL(&_3, 2);
	}
	if (_2) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL, 7);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 设置session的配置信息
 * 包括session包的唯一ID
 */
PHP_METHOD(Vii_Session_NativeSession, setOptions) {

	zval *options_param = NULL, uniqueId, maxlifetime;
	zval options;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&maxlifetime);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZVAL_COPY_VALUE(&options, options_param);


	ZEPHIR_OBS_VAR(&uniqueId);
	if (zephir_array_isset_string_fetch(&uniqueId, &options, SL("uniqueId"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_uniqueId"), &uniqueId);
		zephir_array_unset_string(&options, SL("uniqueId"), PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&maxlifetime);
	if (zephir_array_isset_string_fetch(&maxlifetime, &options, SL("lifetime"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_maxlifetime"), &maxlifetime);
		zephir_array_unset_string(&options, SL("lifetime"), PH_SEPARATE);
	}
	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Session_NativeSession, getOptions) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * 设置session名称
 */
PHP_METHOD(Vii_Session_NativeSession, setName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_FUNCTION(NULL, "session_name", NULL, 8, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取session名称
 */
PHP_METHOD(Vii_Session_NativeSession, getName) {

	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_name", NULL, 8);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 重新生成sessionID替换现有sessionid
 * @deleteOldSession bool 是否要删除以前的session数据
 */
PHP_METHOD(Vii_Session_NativeSession, regenerateId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *deleteOldSession_param = NULL, _0;
	zend_bool deleteOldSession;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &deleteOldSession_param);

	if (!deleteOldSession_param) {
		deleteOldSession = 1;
	} else {
		deleteOldSession = zephir_get_boolval(deleteOldSession_param);
	}


	ZVAL_BOOL(&_0, (deleteOldSession ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(NULL, "session_regenerate_id", NULL, 9, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Vii_Session_NativeSession, getIndex) {

	zval *index, index_sub, _0, _1$$3;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	zephir_fetch_params(0, 1, 0, &index);



	zephir_read_property(&_0, this_ptr, SL("_uniqueId"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_uniqueId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSV(return_value, &_1$$3, ".", index);
		return;
	}
	RETVAL_ZVAL(index, 1, 0);
	return;

}

/**
 * 获取一个session值
 * @param index session索引
 * @param defaultValue any 不存在时需要返回的默认值
 * @param remove bool 是否获取以后删除该session数据
 */
PHP_METHOD(Vii_Session_NativeSession, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool remove;
	zval *index_param = NULL, *defaultValue = NULL, defaultValue_sub, *remove_param = NULL, _SESSION, __$null, value, _0;
	zval index;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 2, &index_param, &defaultValue, &remove_param);

	zephir_get_strval(&index, index_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!remove_param) {
		remove = 0;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getindex", NULL, 0, &index);
	zephir_check_call_status();
	zephir_get_strval(&index, &_0);
	ZEPHIR_OBS_VAR(&value);
	if (zephir_array_isset_fetch(&value, &_SESSION, &index, 0 TSRMLS_CC)) {
		if (remove) {
			zephir_array_unset(&_SESSION, &index, PH_SEPARATE);
		}
		RETURN_CCTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * 设置一个session数据
 */
PHP_METHOD(Vii_Session_NativeSession, set) {

	int ZEPHIR_LAST_CALL_STATUS, _1;
	zval *index_param = NULL, *value, value_sub, _SESSION, _0;
	zval index;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 2, 0, &index_param, &value);

	zephir_get_strval(&index, index_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getindex", NULL, 0, &index);
	zephir_check_call_status();
	_1 = zephir_maybe_separate_zval(&_SESSION);
	zephir_array_update_zval(&_SESSION, &_0, value, PH_COPY | PH_SEPARATE);
	if (_1) {
		ZEPHIR_SET_SYMBOL(&EG(symbol_table), "_SESSION", &_SESSION);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 检查一个session数据是否已经被设置过
 */
PHP_METHOD(Vii_Session_NativeSession, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, _SESSION, _0;
	zval index;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getindex", NULL, 0, &index);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_isset(&_SESSION, &_0));

}

/**
 * 删除一个sesion数据
 */
PHP_METHOD(Vii_Session_NativeSession, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, _SESSION, _0;
	zval index;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getindex", NULL, 0, &index);
	zephir_check_call_status();
	zephir_array_unset(&_SESSION, &_0, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回活动的sessionid
 */
PHP_METHOD(Vii_Session_NativeSession, getId) {

	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_id", NULL, 10);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置当前的sessionid
 */
PHP_METHOD(Vii_Session_NativeSession, setId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL;
	zval id;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&id);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 10, &id);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 检查session是否已经开启
 */
PHP_METHOD(Vii_Session_NativeSession, isStarted) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "_started");

}

/**
 * 销毁活动的session
 * @param removeCurrentSessionData bool 是否移除当前活动的session数据
 */
PHP_METHOD(Vii_Session_NativeSession, destroy) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *removeCurrentSessionData_param = NULL, _SESSION, __$true, __$false, key$$3, _0$$3, *_1$$3, _4$$4;
	zend_bool removeCurrentSessionData;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_SESSION);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&key$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 0, 1, &removeCurrentSessionData_param);

	if (!removeCurrentSessionData_param) {
		removeCurrentSessionData = 0;
	} else {
		removeCurrentSessionData = zephir_get_boolval(removeCurrentSessionData_param);
	}


	if (removeCurrentSessionData) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_is_iterable(&_SESSION, 1, "vii/session/nativesession.zep", 179);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SESSION), _2$$3, _3$$3, _1$$3)
		{
			ZEPHIR_INIT_NVAR(&key$$3);
			if (_3$$3 != NULL) { 
				ZVAL_STR_COPY(&key$$3, _3$$3);
			} else {
				ZVAL_LONG(&key$$3, _2$$3);
			}
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_COPY(&_0$$3, _1$$3);
			ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "getindex", &_5, 0, &key$$3);
			zephir_check_call_status();
			zephir_array_unset(&_SESSION, &_4$$4, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZEPHIR_INIT_NVAR(&key$$3);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("session_destroy", NULL, 11);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回当前session的状态
 */
PHP_METHOD(Vii_Session_NativeSession, status) {

	zval status;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&status);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&status, "session_status", NULL, 12);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(&status, 0)) {
			RETURN_MM_LONG(0);
		}
		if (ZEPHIR_IS_LONG(&status, 2)) {
			RETURN_MM_LONG(2);
		}
	} while(0);

	RETURN_MM_LONG(1);

}

PHP_METHOD(Vii_Session_NativeSession, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval index;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&index);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &index);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Session_NativeSession, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *value, value_sub;
	zval index;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index_param, &value);

	zephir_get_strval(&index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &index, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Session_NativeSession, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval index;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&index);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &index);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Session_NativeSession, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval index;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&index);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "remove", NULL, 0, &index);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Session_NativeSession, __destruct) {

	zval __$true, __$false, _0;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_started"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_write_close", NULL, 13);
		zephir_check_call_status();
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
		}
	}
	ZEPHIR_MM_RESTORE();

}

