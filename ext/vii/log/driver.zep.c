
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Vii_Log_Driver) {

	ZEPHIR_REGISTER_CLASS(Vii\\Log, Driver, vii, log_driver, vii_log_driver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(vii_log_driver_ce, SL("_recordLevel"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(vii_log_driver_ce, SL("_enable"), 1, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_long(vii_log_driver_ce, SL("_logFileSize"), 1, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Vii_Log_Driver, setRecordLevel) {

	zval *recordLevel_param = NULL;
	zval recordLevel;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&recordLevel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &recordLevel_param);

	if (!recordLevel_param) {
		ZEPHIR_INIT_VAR(&recordLevel);
		array_init(&recordLevel);
	} else {
	ZVAL_COPY_VALUE(&recordLevel, recordLevel_param);
	}


	zephir_update_static_property_ce(vii_log_driver_ce, SL("_recordLevel"), &recordLevel);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Log_Driver, disable) {

	zval __$false;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_BOOL(&__$false, 0);


	zephir_update_static_property_ce(vii_log_driver_ce, SL("_enable"), &__$false);

}

PHP_METHOD(Vii_Log_Driver, setLogFileSize) {

	zval *_size_param = NULL, _0;
	int _size;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 0, 1, &_size_param);

	if (!_size_param) {
		_size = 1;
	} else {
		_size = zephir_get_intval(_size_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, _size);
	zephir_update_static_property_ce(vii_log_driver_ce, SL("_logFileSize"), &_0);

}

PHP_METHOD(Vii_Log_Driver, log) {

	zval placeholders;
	zval *logLevel_param = NULL, *message_param = NULL, *placeholders_param = NULL;
	zval logLevel, message;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&logLevel);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &logLevel_param, &message_param, &placeholders_param);

	if (unlikely(Z_TYPE_P(logLevel_param) != IS_STRING && Z_TYPE_P(logLevel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'logLevel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(logLevel_param) == IS_STRING)) {
		zephir_get_strval(&logLevel, logLevel_param);
	} else {
		ZEPHIR_INIT_VAR(&logLevel);
		ZVAL_EMPTY_STRING(&logLevel);
	}
	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}



}

void zephir_init_static_properties_Vii_Log_Driver(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(vii_log_driver_ce, SL("_recordLevel"), &_0);
	ZEPHIR_MM_RESTORE();

}

