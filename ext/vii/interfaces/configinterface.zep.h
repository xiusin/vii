
extern zend_class_entry *vii_interfaces_configinterface_ce;

ZEPHIR_INIT_CLASS(Vii_Interfaces_ConfigInterface);

ZEPHIR_INIT_FUNCS(vii_interfaces_configinterface_method_entry) {
	PHP_ABSTRACT_ME(Vii_Interfaces_ConfigInterface, toArray, NULL)
	PHP_FE_END
};
