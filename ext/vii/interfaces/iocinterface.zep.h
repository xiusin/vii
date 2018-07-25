
extern zend_class_entry *vii_interfaces_iocinterface_ce;

ZEPHIR_INIT_CLASS(Vii_Interfaces_IocInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_iocinterface_setioc, 0, 0, 1)
	ZEND_ARG_INFO(0, _ioc)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_interfaces_iocinterface_method_entry) {
	PHP_ABSTRACT_ME(Vii_Interfaces_IocInterface, setIoc, arginfo_vii_interfaces_iocinterface_setioc)
	PHP_ABSTRACT_ME(Vii_Interfaces_IocInterface, getIoc, NULL)
	PHP_FE_END
};
