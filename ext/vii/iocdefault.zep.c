
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
#include "kernel/memory.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Vii_IocDefault) {

	ZEPHIR_REGISTER_CLASS_EX(Vii, IocDefault, vii, iocdefault, vii_ioc_ce, vii_iocdefault_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Vii_IocDefault, __construct) {

	zend_string *_7;
	zend_ulong _6;
	zval iocs, serverKey, iocValue, _1, _2, _3, _4, *_5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_8 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&iocs);
	ZVAL_UNDEF(&serverKey);
	ZVAL_UNDEF(&iocValue);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, vii_iocdefault_ce, getThis(), "__construct", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&iocs);
	zephir_create_array(&iocs, 11, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&iocs, SL("assets"), SL("Vii\\Assets\\Manager"));
	add_assoc_stringl_ex(&iocs, SL("urlManager"), SL("Vii\\UrlManager"));
	add_assoc_stringl_ex(&iocs, SL("cookie"), SL("Vii\\Cookie"));
	add_assoc_stringl_ex(&iocs, SL("request"), SL("Vii\\Request"));
	add_assoc_stringl_ex(&iocs, SL("response"), SL("Vii\\Response"));
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, vii_dispatcher_ce);
	if (zephir_has_constructor(&_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, &_1, "setioc", NULL, 87, this_ptr);
	zephir_check_call_status();
	zephir_array_update_string(&iocs, SL("dispatcher"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, vii_mvc_router_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 88);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_3, "setioc", NULL, 89, this_ptr);
	zephir_check_call_status();
	zephir_array_update_string(&iocs, SL("router"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, vii_mvc_view_ce);
	if (zephir_has_constructor(&_4 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, &_4, "setioc", NULL, 90, this_ptr);
	zephir_check_call_status();
	zephir_array_update_string(&iocs, SL("view"), &_2, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&iocs, SL("dump"), SL("Vii\\Dump"));
	add_assoc_stringl_ex(&iocs, SL("alias"), SL("Vii\\Alias"));
	add_assoc_stringl_ex(&iocs, SL("filesystem"), SL("Vii\\FileSystem"));
	zephir_is_iterable(&iocs, 0, "vii/iocdefault.zep", 27);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&iocs), _6, _7, _5)
	{
		ZEPHIR_INIT_NVAR(&serverKey);
		if (_7 != NULL) { 
			ZVAL_STR_COPY(&serverKey, _7);
		} else {
			ZVAL_LONG(&serverKey, _6);
		}
		ZEPHIR_INIT_NVAR(&iocValue);
		ZVAL_COPY(&iocValue, _5);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_8, 0, &serverKey, &iocValue);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&iocValue);
	ZEPHIR_INIT_NVAR(&serverKey);
	ZEPHIR_MM_RESTORE();

}

