
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Vii_Config_Ini) {

	ZEPHIR_REGISTER_CLASS_EX(Vii\\Config, Ini, vii, config_ini, zephir_get_internal_ce(SL("vii\\config\\config")), vii_config_ini_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Vii_Config_Ini, __construct) {

	zval *inipath_param = NULL;
	zval inipath;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&inipath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inipath_param);

	if (unlikely(Z_TYPE_P(inipath_param) != IS_STRING && Z_TYPE_P(inipath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'inipath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(inipath_param) == IS_STRING)) {
		zephir_get_strval(&inipath, inipath_param);
	} else {
		ZEPHIR_INIT_VAR(&inipath);
		ZVAL_EMPTY_STRING(&inipath);
	}


	if (!((zephir_file_exists(&inipath TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_configexception_ce, "Ini config file is not exists!", "vii/config/ini.zep", 7);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

