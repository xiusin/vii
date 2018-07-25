
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Vii_Session_Adapter_File) {

	ZEPHIR_REGISTER_CLASS_EX(Vii\\Session\\Adapter, File, vii, session_adapter_file, vii_session_nativesession_ce, NULL, 0);

	return SUCCESS;

}

