
extern zend_class_entry *vii_i18n_ce;

ZEPHIR_INIT_CLASS(Vii_I18n);

PHP_METHOD(Vii_I18n, __construct);
PHP_METHOD(Vii_I18n, __clone);
PHP_METHOD(Vii_I18n, getDefault);
PHP_METHOD(Vii_I18n, getMessage);
PHP_METHOD(Vii_I18n, setOptions);
PHP_METHOD(Vii_I18n, getOptions);
PHP_METHOD(Vii_I18n, translate);
zend_object *zephir_init_properties_Vii_I18n(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_i18n___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_i18n_getdefault, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_i18n_setoptions, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_i18n_translate, 0, 0, 1)
	ZEND_ARG_INFO(0, strOrId)
	ZEND_ARG_ARRAY_INFO(0, value, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_i18n_method_entry) {
	PHP_ME(Vii_I18n, __construct, arginfo_vii_i18n___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Vii_I18n, __clone, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_I18n, getDefault, arginfo_vii_i18n_getdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vii_I18n, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_I18n, setOptions, arginfo_vii_i18n_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_I18n, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_I18n, translate, arginfo_vii_i18n_translate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
