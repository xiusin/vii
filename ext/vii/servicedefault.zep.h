
extern zend_class_entry *vii_servicedefault_ce;

ZEPHIR_INIT_CLASS(Vii_ServiceDefault);

PHP_METHOD(Vii_ServiceDefault, __construct);

ZEPHIR_INIT_FUNCS(vii_servicedefault_method_entry) {
	PHP_ME(Vii_ServiceDefault, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
