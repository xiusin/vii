
extern zend_class_entry *vii_iocdefault_ce;

ZEPHIR_INIT_CLASS(Vii_IocDefault);

PHP_METHOD(Vii_IocDefault, __construct);

ZEPHIR_INIT_FUNCS(vii_iocdefault_method_entry) {
	PHP_ME(Vii_IocDefault, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
