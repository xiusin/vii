
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Vii_Config) {

	ZEPHIR_REGISTER_CLASS(Vii, Config, vii, config, vii_config_method_entry, 0);

	zend_class_implements(vii_config_ce TSRMLS_CC, 1, vii_interfaces_configinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Config, __construct) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, key, value, *_0, _4$$5;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	ZEPHIR_OBS_COPY_OR_DUP(&config, config_param);


	zephir_is_iterable(&config, 0, "vii/config.zep", 18);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&config), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "isvalidkey", &_3, 1, &key);
		zephir_check_call_status();
		if (!(Z_TYPE_P(&value) == IS_ARRAY)) {
			zephir_update_property_zval_zval(this_ptr, &key, &value TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_4$$5);
			object_init_ex(&_4$$5, vii_config_ce);
			ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", &_5, 2, &value);
			zephir_check_call_status();
			zephir_update_property_zval_zval(this_ptr, &key, &_4$$5 TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Config, merge) {

	zend_bool _7$$3;
	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *config, config_sub, key, value, configArr, *_1, _4$$3, _6$$3, _8$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&configArr);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_CALL_CE_STATIC(&configArr, vii_helper_ce, "obj2arr", &_0, 0, config);
	zephir_check_call_status();
	zephir_is_iterable(&configArr, 0, "vii/config.zep", 32);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&configArr), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SV(&_4$$3, "", &key);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "isvalidkey", &_5, 1, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&_6$$3);
		zephir_read_property_zval(&_6$$3, this_ptr, &key, PH_NOISY_CC);
		_7$$3 = Z_TYPE_P(&_6$$3) == IS_OBJECT;
		if (_7$$3) {
			_7$$3 = Z_TYPE_P(&value) == IS_OBJECT;
		}
		if (_7$$3) {
			ZEPHIR_OBS_NVAR(&_8$$4);
			zephir_read_property_zval(&_8$$4, this_ptr, &key, PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, &_8$$4, "merge", NULL, 0, &value);
			zephir_check_call_status();
		} else {
			zephir_update_property_zval_zval(this_ptr, &key, &value TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Config, isValidKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0, _1, _2, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/^[a-z_A-Z][a-z_A-Z0-9]+/");
	zephir_preg_match(&_1, &_2, key, &_0, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, vii_exceptions_configexception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, "the config key ", key, " is valid key , must string");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "vii/config.zep", 37 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Config, toArray) {

	zend_bool _4$$3;
	zend_string *_3;
	zend_ulong _2;
	zval _0, _6$$4;
	zval config, key, value, *_1, _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();

	zephir_get_arrval(&_0, this_ptr);
	ZEPHIR_CPY_WRT(&config, &_0);
	zephir_is_iterable(&config, 1, "vii/config.zep", 50);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&config), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		_4$$3 = Z_TYPE_P(&value) == IS_OBJECT;
		if (!(_4$$3)) {
			_4$$3 = Z_TYPE_P(&value) == IS_ARRAY;
		}
		if (_4$$3) {
			ZEPHIR_CALL_METHOD(&_5$$4, &value, "toarray", NULL, 0);
			zephir_check_call_status();
			zephir_get_arrval(&_6$$4, &_5$$4);
			zephir_array_update_zval(&config, &key, &_6$$4, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&config);

}

