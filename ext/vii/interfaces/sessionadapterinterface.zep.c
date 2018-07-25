
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Vii_Interfaces_SessionAdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Vii\\Interfaces, SessionAdapterInterface, vii, interfaces_sessionadapterinterface, vii_interfaces_sessionadapterinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Vii_Interfaces_SessionAdapterInterface, start);

ZEPHIR_DOC_METHOD(Vii_Interfaces_SessionAdapterInterface, get);

ZEPHIR_DOC_METHOD(Vii_Interfaces_SessionAdapterInterface, set);

ZEPHIR_DOC_METHOD(Vii_Interfaces_SessionAdapterInterface, has);

ZEPHIR_DOC_METHOD(Vii_Interfaces_SessionAdapterInterface, remove);

ZEPHIR_DOC_METHOD(Vii_Interfaces_SessionAdapterInterface, getId);

ZEPHIR_DOC_METHOD(Vii_Interfaces_SessionAdapterInterface, isStarted);

ZEPHIR_DOC_METHOD(Vii_Interfaces_SessionAdapterInterface, destroy);

