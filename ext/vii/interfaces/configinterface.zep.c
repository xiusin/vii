
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Vii_Interfaces_ConfigInterface) {

	ZEPHIR_REGISTER_INTERFACE(Vii\\Interfaces, ConfigInterface, vii, interfaces_configinterface, vii_interfaces_configinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Vii_Interfaces_ConfigInterface, toArray);

