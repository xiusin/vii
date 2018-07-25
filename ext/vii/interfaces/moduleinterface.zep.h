
extern zend_class_entry *vii_interfaces_moduleinterface_ce;

ZEPHIR_INIT_CLASS(Vii_Interfaces_ModuleInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_moduleinterface_registerservices, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, _ioc, Vii\\Interfaces\\IocInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_interfaces_moduleinterface_method_entry) {
	PHP_ABSTRACT_ME(Vii_Interfaces_ModuleInterface, registerServices, arginfo_vii_interfaces_moduleinterface_registerservices)
	PHP_ABSTRACT_ME(Vii_Interfaces_ModuleInterface, registerAutoloader, NULL)
	PHP_FE_END
};
