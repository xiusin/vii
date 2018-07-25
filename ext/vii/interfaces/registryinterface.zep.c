
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Vii_Interfaces_RegistryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Vii\\Interfaces, RegistryInterface, vii, interfaces_registryinterface, NULL);

	return SUCCESS;

}

