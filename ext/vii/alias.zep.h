
extern zend_class_entry *vii_alias_ce;

ZEPHIR_INIT_CLASS(Vii_Alias);

PHP_METHOD(Vii_Alias, set);
PHP_METHOD(Vii_Alias, has);
PHP_METHOD(Vii_Alias, resolve);
static zend_object *zephir_init_properties_Vii_Alias(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_alias_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_alias_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_alias_resolve, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_alias_method_entry) {
	PHP_ME(Vii_Alias, set, arginfo_vii_alias_set, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Alias, has, arginfo_vii_alias_has, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Alias, resolve, arginfo_vii_alias_resolve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
