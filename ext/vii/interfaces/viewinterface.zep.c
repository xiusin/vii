
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Vii_Interfaces_ViewInterface) {

	ZEPHIR_REGISTER_INTERFACE(Vii\\Interfaces, ViewInterface, vii, interfaces_viewinterface, NULL);

	return SUCCESS;

}

