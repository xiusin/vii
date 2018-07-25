
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
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Vii_Config_Php) {

	ZEPHIR_REGISTER_CLASS_EX(Vii\\Config, Php, vii, config_php, vii_config_ce, vii_config_php_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Vii_Config_Php, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *phpFile_param = NULL, _1;
	zval phpFile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phpFile);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &phpFile_param);

	if (UNEXPECTED(Z_TYPE_P(phpFile_param) != IS_STRING && Z_TYPE_P(phpFile_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'phpFile' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(phpFile_param) == IS_STRING)) {
		zephir_get_strval(&phpFile, phpFile_param);
	} else {
		ZEPHIR_INIT_VAR(&phpFile);
		ZVAL_EMPTY_STRING(&phpFile);
	}


	if (!((zephir_file_exists(&phpFile TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_configexception_ce, "Php config file is not exists!", "vii/config/php.zep", 9);
		return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_1);
	if (zephir_require_zval_ret(&_1, &phpFile TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_PARENT(NULL, vii_config_php_ce, getThis(), "__construct", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

