
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


/**
 * Log打印级别以及占位符
 */
ZEPHIR_INIT_CLASS(Vii_Log) {

	ZEPHIR_REGISTER_CLASS(Vii, Log, vii, log, NULL, 0);

	zephir_declare_class_constant_string(vii_log_ce, SL("ERROR"), "ERROR");

	zephir_declare_class_constant_string(vii_log_ce, SL("ALERT"), "ALERT");

	zephir_declare_class_constant_string(vii_log_ce, SL("NOTICE"), "NOTICE");

	zephir_declare_class_constant_string(vii_log_ce, SL("WARNING"), "WARNING");

	zephir_declare_class_constant_string(vii_log_ce, SL("INFO"), "INFO");

	zephir_declare_class_constant_string(vii_log_ce, SL("DEBUG"), "DEBUG");

	zephir_declare_class_constant_string(vii_log_ce, SL("PLACEHOLDER_TIME"), "{{TIME}}");

	zephir_declare_class_constant_string(vii_log_ce, SL("PLACEHOLDER_LEVEL"), "{{LEVEL}}");

	zephir_declare_class_constant_string(vii_log_ce, SL("PLACEHOLDER_MESSAGE"), "{{MESSAGE}}");

	return SUCCESS;

}

