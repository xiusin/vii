
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Vii_Interfaces_ServiceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Vii\\Interfaces, ServiceInterface, vii, interfaces_serviceinterface, vii_interfaces_serviceinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Vii_Interfaces_ServiceInterface, setService);

ZEPHIR_DOC_METHOD(Vii_Interfaces_ServiceInterface, getService);

