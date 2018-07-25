
extern zend_class_entry *vii_assets_inlines_ce;

ZEPHIR_INIT_CLASS(Vii_Assets_Inlines);

PHP_METHOD(Vii_Assets_Inlines, getType);
PHP_METHOD(Vii_Assets_Inlines, getContent);
PHP_METHOD(Vii_Assets_Inlines, __construct);
PHP_METHOD(Vii_Assets_Inlines, setType);
PHP_METHOD(Vii_Assets_Inlines, setContent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_inlines___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_inlines_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_inlines_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_assets_inlines_method_entry) {
	PHP_ME(Vii_Assets_Inlines, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Inlines, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Inlines, __construct, arginfo_vii_assets_inlines___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Assets_Inlines, setType, arginfo_vii_assets_inlines_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Inlines, setContent, arginfo_vii_assets_inlines_setcontent, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
