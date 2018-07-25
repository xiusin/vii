
extern zend_class_entry *vii_interfaces_engineinterface_ce;

ZEPHIR_INIT_CLASS(Vii_Interfaces_EngineInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_engineinterface___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Vii\\Interfaces\\ViewInterface, 0)
	ZEND_ARG_OBJ_INFO(0, ioc, Vii\\Interfaces\\IocInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_engineinterface_render, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_interfaces_engineinterface_method_entry) {
	PHP_ABSTRACT_ME(Vii_Interfaces_EngineInterface, __construct, arginfo_vii_interfaces_engineinterface___construct)
	PHP_ABSTRACT_ME(Vii_Interfaces_EngineInterface, render, arginfo_vii_interfaces_engineinterface_render)
	PHP_FE_END
};
