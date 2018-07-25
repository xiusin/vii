
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/time.h"


ZEPHIR_INIT_CLASS(Vii_Cookie) {

	ZEPHIR_REGISTER_CLASS(Vii, Cookie, vii, cookie, vii_cookie_method_entry, 0);

	zend_declare_property_string(vii_cookie_ce, SL("domain"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(vii_cookie_ce, SL("salt"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(vii_cookie_ce, SL("isuse"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Vii_Cookie, __construct) {

	zval *domain = NULL, domain_sub, *salt = NULL, salt_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain_sub);
	ZVAL_UNDEF(&salt_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &domain, &salt);

	if (!domain) {
		domain = &domain_sub;
		ZEPHIR_INIT_VAR(domain);
		ZVAL_STRING(domain, "");
	}
	if (!salt) {
		salt = &salt_sub;
		ZEPHIR_INIT_VAR(salt);
		ZVAL_STRING(salt, "vii_cookie_encodekey");
	}


	zephir_update_property_zval(this_ptr, SL("domain"), domain);
	zephir_update_property_zval(this_ptr, SL("salt"), salt);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Cookie, encryption) {

	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS, k = 0, _3;
	zval *_string = NULL, _string_sub, *aciton = NULL, aciton_sub, code, i, keylen, _1, _strlen, _4, _11, _0$$3, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_string_sub);
	ZVAL_UNDEF(&aciton_sub);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&keylen);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_strlen);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &_string, &aciton);

	ZEPHIR_SEPARATE_PARAM(_string);
	if (!aciton) {
		aciton = &aciton_sub;
		ZEPHIR_INIT_VAR(aciton);
		ZVAL_STRING(aciton, "ENCODE");
	}


	ZEPHIR_INIT_VAR(&code);
	ZVAL_STRING(&code, "");
	ZEPHIR_INIT_VAR(&i);
	ZVAL_LONG(&i, 0);
	if (!ZEPHIR_IS_STRING(aciton, "ENCODE")) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "base64_decode", NULL, 25, _string);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(_string, &_0$$3);
	}
	zephir_read_property(&_1, this_ptr, SL("salt"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&keylen);
	ZVAL_LONG(&keylen, zephir_fast_strlen_ev(&_1));
	ZEPHIR_INIT_VAR(&_strlen);
	ZVAL_LONG(&_strlen, zephir_fast_strlen_ev(_string));
	ZEPHIR_CPY_WRT(&_4, &_strlen);
	_3 = 0;
	_2 = 0;
	if (ZEPHIR_GE_LONG(&_4, _3)) {
		while (1) {
			if (_2) {
				_3++;
				if (!(ZEPHIR_GE_LONG(&_4, _3))) {
					break;
				}
			} else {
				_2 = 1;
			}
			ZEPHIR_INIT_NVAR(&i);
			ZVAL_LONG(&i, _3);
			ZEPHIR_INIT_LNVAR(_5$$4);
			mod_function(&_5$$4, &i, &keylen TSRMLS_CC);
			k = zephir_get_numberval(&_5$$4);
			zephir_array_fetch(&_6$$4, _string, &i, PH_NOISY | PH_READONLY, "vii/cookie.zep", 24 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_7$$4);
			ZEPHIR_CONCAT_VV(&_7$$4, &code, &_6$$4);
			zephir_read_property(&_8$$4, this_ptr, SL("salt"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_long(&_9$$4, &_8$$4, k, PH_NOISY | PH_READONLY, "vii/cookie.zep", 24 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10$$4);
			zephir_bitwise_xor_function(&_10$$4, &_7$$4, &_9$$4 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&code, &_10$$4);
		}
	}
	ZEPHIR_INIT_VAR(&_11);
	if (!ZEPHIR_IS_STRING(aciton, "DECODE")) {
		ZEPHIR_CALL_FUNCTION(&_11, "base64_encode", NULL, 26, &code);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_11, &code);
	}
	RETURN_CCTOR(&_11);

}

PHP_METHOD(Vii_Cookie, useEncryption) {

	zval *isuse = NULL, isuse_sub, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&isuse_sub);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 0, 1, &isuse);

	if (!isuse) {
		isuse = &isuse_sub;
		isuse = &__$false;
	}


	zephir_update_property_zval(this_ptr, SL("isuse"), isuse);

}

PHP_METHOD(Vii_Cookie, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *value, value_sub, *_time = NULL, _time_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_time_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &value, &_time);

	if (!_time) {
		_time = &_time_sub;
		ZEPHIR_INIT_VAR(_time);
		ZVAL_LONG(_time, 0);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "setvalue", NULL, 0, value);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("domain"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 27, key, &_0, _time, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Cookie, setValue) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	zephir_read_property(&_0, this_ptr, SL("isuse"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "ENCODE");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "encryption", NULL, 0, value, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Vii_Cookie, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *_default = NULL, _default_sub, *_COOKIE, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params(1, 1, 1, &key, &_default);

	if (!_default) {
		_default = &_default_sub;
		ZEPHIR_INIT_VAR(_default);
		ZVAL_STRING(_default, "");
	}


	if (!(zephir_array_isset(_COOKIE, key))) {
		RETVAL_ZVAL(_default, 1, 0);
		RETURN_MM();
	}
	zephir_array_fetch(&_0, _COOKIE, key, PH_NOISY | PH_READONLY, "vii/cookie.zep", 52 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Cookie, getValue) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	zephir_read_property(&_0, this_ptr, SL("isuse"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "DECODE");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "encryption", NULL, 0, value, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Vii_Cookie, clear) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_COOKIE, k, _0, *_1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));

	ZEPHIR_INIT_VAR(&_0);
	zephir_is_iterable(_COOKIE, 0, "vii/cookie.zep", 70);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_COOKIE), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&k, _3);
		} else {
			ZVAL_LONG(&k, _2);
		}
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_COPY(&_0, _1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "del", &_4, 0, &k);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&k);
	RETURN_THIS();

}

PHP_METHOD(Vii_Cookie, flashGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *_default, _default_sub, result;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_UNDEF(&result);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &_default);



	ZEPHIR_CALL_METHOD(&result, this_ptr, "get", NULL, 0, key, _default);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "del", NULL, 0, key);
	zephir_check_call_status();
	RETURN_CCTOR(&result);

}

PHP_METHOD(Vii_Cookie, del) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, __$null, *_COOKIE, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) - 3600));
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 27, key, &__$null, &_1);
	zephir_check_call_status();
	zephir_array_unset(_COOKIE, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

