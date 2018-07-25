
extern zend_class_entry *vii_interfaces_serviceinterface_ce;

ZEPHIR_INIT_CLASS(Vii_Interfaces_ServiceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_serviceinterface_setservice, 0, 0, 1)
	ZEND_ARG_INFO(0, _service)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_interfaces_serviceinterface_method_entry) {
	PHP_ABSTRACT_ME(Vii_Interfaces_ServiceInterface, setService, arginfo_vii_interfaces_serviceinterface_setservice)
	PHP_ABSTRACT_ME(Vii_Interfaces_ServiceInterface, getService, NULL)
	PHP_FE_END
};
