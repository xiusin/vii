
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


ZEPHIR_INIT_CLASS(Vii_Event) {

	ZEPHIR_REGISTER_CLASS(Vii, Event, vii, event, vii_event_method_entry, 0);

	zend_declare_property_null(vii_event_ce, SL("handlerFun"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(vii_event_ce, SL("priority"), 100, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Vii_Event, __construct) {

	int priority;
	zval *handlerFun, handlerFun_sub, *priority_param = NULL, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&handlerFun_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 1, &handlerFun, &priority_param);

	if (!priority_param) {
		priority = 100;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	zephir_update_property_zval(this_ptr, SL("handlerFun"), handlerFun);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, priority);
	zephir_update_property_zval(this_ptr, SL("priority"), &_0);

}

