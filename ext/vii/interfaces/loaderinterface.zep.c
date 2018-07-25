
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Vii_Interfaces_LoaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Vii\\Interfaces, LoaderInterface, vii, interfaces_loaderinterface, NULL);

	return SUCCESS;

}

