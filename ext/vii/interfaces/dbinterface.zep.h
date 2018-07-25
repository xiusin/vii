
extern zend_class_entry *vii_interfaces_dbinterface_ce;

ZEPHIR_INIT_CLASS(Vii_Interfaces_DbInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_dbinterface_findone, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, where)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_interfaces_dbinterface_method_entry) {
	PHP_ABSTRACT_ME(Vii_Interfaces_DbInterface, findOne, arginfo_vii_interfaces_dbinterface_findone)
	PHP_FE_END
};
