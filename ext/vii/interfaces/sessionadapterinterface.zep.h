
extern zend_class_entry *vii_interfaces_sessionadapterinterface_ce;

ZEPHIR_INIT_CLASS(Vii_Interfaces_SessionAdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_sessionadapterinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_sessionadapterinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_sessionadapterinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_sessionadapterinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_interfaces_sessionadapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Vii_Interfaces_SessionAdapterInterface, start, NULL)
	PHP_ABSTRACT_ME(Vii_Interfaces_SessionAdapterInterface, get, arginfo_vii_interfaces_sessionadapterinterface_get)
	PHP_ABSTRACT_ME(Vii_Interfaces_SessionAdapterInterface, set, arginfo_vii_interfaces_sessionadapterinterface_set)
	PHP_ABSTRACT_ME(Vii_Interfaces_SessionAdapterInterface, has, arginfo_vii_interfaces_sessionadapterinterface_has)
	PHP_ABSTRACT_ME(Vii_Interfaces_SessionAdapterInterface, remove, arginfo_vii_interfaces_sessionadapterinterface_remove)
	PHP_ABSTRACT_ME(Vii_Interfaces_SessionAdapterInterface, getId, NULL)
	PHP_ABSTRACT_ME(Vii_Interfaces_SessionAdapterInterface, isStarted, NULL)
	PHP_ABSTRACT_ME(Vii_Interfaces_SessionAdapterInterface, destroy, NULL)
	PHP_FE_END
};
