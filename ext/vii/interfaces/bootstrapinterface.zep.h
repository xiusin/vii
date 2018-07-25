
extern zend_class_entry *vii_interfaces_bootstrapinterface_ce;

ZEPHIR_INIT_CLASS(Vii_Interfaces_BootstrapInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_bootstrapinterface___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, ioc, Vii\\Interfaces\\IocInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_interfaces_bootstrapinterface_method_entry) {
	PHP_ABSTRACT_ME(Vii_Interfaces_BootstrapInterface, __construct, arginfo_vii_interfaces_bootstrapinterface___construct)
	PHP_FE_END
};
