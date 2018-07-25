
extern zend_class_entry *vii_pagination_ce;

ZEPHIR_INIT_CLASS(Vii_pagination);

PHP_METHOD(Vii_pagination, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_pagination___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_pagination_method_entry) {
	PHP_ME(Vii_pagination, __construct, arginfo_vii_pagination___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
