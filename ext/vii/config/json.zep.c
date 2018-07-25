
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
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Vii_Config_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Vii\\Config, Json, vii, config_json, vii_config_ce, vii_config_json_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Vii_Config_Json, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *jsonFile_param = NULL, __$true, _1, _2;
	zval jsonFile;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&jsonFile);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &jsonFile_param);

	if (unlikely(Z_TYPE_P(jsonFile_param) != IS_STRING && Z_TYPE_P(jsonFile_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'jsonFile' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(jsonFile_param) == IS_STRING)) {
		zephir_get_strval(&jsonFile, jsonFile_param);
	} else {
		ZEPHIR_INIT_VAR(&jsonFile);
		ZVAL_EMPTY_STRING(&jsonFile);
	}


	if (!((zephir_file_exists(&jsonFile TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_configexception_ce, "Json config file is not exists!", "vii/config/json.zep", 8);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_file_get_contents(&_2, &jsonFile TSRMLS_CC);
	zephir_json_decode(&_1, &_2, zephir_get_intval(&__$true) );
	ZEPHIR_CALL_PARENT(NULL, vii_config_json_ce, this_ptr, "__construct", &_0, 2, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

