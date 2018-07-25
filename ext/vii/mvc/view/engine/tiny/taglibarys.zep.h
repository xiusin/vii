
extern zend_class_entry *vii_mvc_view_engine_tiny_taglibarys_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Tiny_Taglibarys);

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Taglibarys, checkAttr);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Taglibarys, parse);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Taglibarys, _attr);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Taglibarys, callback);
static zend_object *zephir_init_properties_Vii_Mvc_View_Engine_Tiny_Taglibarys(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_taglibarys_checkattr, 0, 0, 2)
	ZEND_ARG_INFO(0, attr)
	ZEND_ARG_INFO(0, currtag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_taglibarys_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_taglibarys__attr, 0, 0, 1)
	ZEND_ARG_INFO(0, param_attr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_taglibarys_callback, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_engine_tiny_taglibarys_method_entry) {
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Taglibarys, checkAttr, arginfo_vii_mvc_view_engine_tiny_taglibarys_checkattr, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Taglibarys, parse, arginfo_vii_mvc_view_engine_tiny_taglibarys_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Taglibarys, _attr, arginfo_vii_mvc_view_engine_tiny_taglibarys__attr, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Taglibarys, callback, arginfo_vii_mvc_view_engine_tiny_taglibarys_callback, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
