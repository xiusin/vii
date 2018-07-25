
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Vii_Interfaces_EventManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Vii\\Interfaces, EventManagerInterface, vii, interfaces_eventmanagerinterface, vii_interfaces_eventmanagerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Vii_Interfaces_EventManagerInterface, __construct);

ZEPHIR_DOC_METHOD(Vii_Interfaces_EventManagerInterface, attach);

ZEPHIR_DOC_METHOD(Vii_Interfaces_EventManagerInterface, detachAll);

ZEPHIR_DOC_METHOD(Vii_Interfaces_EventManagerInterface, fire);

ZEPHIR_DOC_METHOD(Vii_Interfaces_EventManagerInterface, getListener);

ZEPHIR_DOC_METHOD(Vii_Interfaces_EventManagerInterface, hasListener);

