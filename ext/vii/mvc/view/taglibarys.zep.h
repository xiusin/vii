
extern zend_class_entry *vii_mvc_view_taglibarys_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View_Taglibarys);

PHP_METHOD(Vii_Mvc_View_Taglibarys, __construct);
PHP_METHOD(Vii_Mvc_View_Taglibarys, checkAttr);
PHP_METHOD(Vii_Mvc_View_Taglibarys, parse);
PHP_METHOD(Vii_Mvc_View_Taglibarys, _attr);
PHP_METHOD(Vii_Mvc_View_Taglibarys, callback);
zend_object_value zephir_init_properties_Vii_Mvc_View_Taglibarys(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_taglibarys_checkattr, 0, 0, 2)
	ZEND_ARG_INFO(0, attr)
	ZEND_ARG_INFO(0, currtag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_taglibarys_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_taglibarys__attr, 0, 0, 1)
	ZEND_ARG_INFO(0, param_attr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_taglibarys_callback, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_taglibarys_method_entry) {
	PHP_ME(Vii_Mvc_View_Taglibarys, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_View_Taglibarys, checkAttr, arginfo_vii_mvc_view_taglibarys_checkattr, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Taglibarys, parse, arginfo_vii_mvc_view_taglibarys_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Taglibarys, _attr, arginfo_vii_mvc_view_taglibarys__attr, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Mvc_View_Taglibarys, callback, arginfo_vii_mvc_view_taglibarys_callback, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
