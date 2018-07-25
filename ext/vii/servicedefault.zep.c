
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
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Vii_ServiceDefault) {

	ZEPHIR_REGISTER_CLASS_EX(Vii, ServiceDefault, vii, servicedefault, vii_service_ce, vii_servicedefault_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Vii_ServiceDefault, __construct) {

	HashTable *_6;
	HashPosition _5;
	zval *services = NULL, *serverKey = NULL, *serviceValue = NULL, *_1, *_2 = NULL, *_3, *_4, **_7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, vii_servicedefault_ce, this_ptr, "__construct", &_0, 119);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(services);
	zephir_create_array(services, 10, 0 TSRMLS_CC);
	add_assoc_stringl_ex(services, SS("assets"), SL("Vii\\Assets\\Manager"), 1);
	add_assoc_stringl_ex(services, SS("urlManager"), SL("Vii\\UrlManager"), 1);
	add_assoc_stringl_ex(services, SS("cookie"), SL("Vii\\Cookie"), 1);
	add_assoc_stringl_ex(services, SS("request"), SL("Vii\\Request"), 1);
	add_assoc_stringl_ex(services, SS("response"), SL("Vii\\Response"), 1);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, vii_dispatcher_ce);
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, _1, "setservice", NULL, 120, this_ptr);
	zephir_check_call_status();
	zephir_array_update_string(&services, SL("dispatcher"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, vii_mvc_router_ce);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 121);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _3, "setservice", NULL, 122, this_ptr);
	zephir_check_call_status();
	zephir_array_update_string(&services, SL("router"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, vii_mvc_view_ce);
	if (zephir_has_constructor(_4 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, _4, "setservice", NULL, 123, this_ptr);
	zephir_check_call_status();
	zephir_array_update_string(&services, SL("view"), &_2, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(services, SS("dump"), SL("Vii\\Dump"), 1);
	add_assoc_stringl_ex(services, SS("alias"), SL("Vii\\Alias"), 1);
	zephir_is_iterable(services, &_6, &_5, 0, 0, "vii/servicedefault.zep", 26);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(serverKey, _6, _5);
		ZEPHIR_GET_HVALUE(serviceValue, _7);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_8, 0, serverKey, serviceValue);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

