
extern zend_class_entry *vii_mvc_view_engine_tiny_tag_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Tiny_Tag);

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _php);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _if);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _else);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _js);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _css);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _foreach);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _list);
zend_object *zephir_init_properties_Vii_Mvc_View_Engine_Tiny_Tag(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_tag__php, 0, 0, 2)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_tag__if, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_tag__js, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_tag__css, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_tag__foreach, 0, 0, 2)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_tag__list, 0, 0, 2)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_engine_tiny_tag_method_entry) {
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Tag, _php, arginfo_vii_mvc_view_engine_tiny_tag__php, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Tag, _if, arginfo_vii_mvc_view_engine_tiny_tag__if, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Tag, _else, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Tag, _js, arginfo_vii_mvc_view_engine_tiny_tag__js, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Tag, _css, arginfo_vii_mvc_view_engine_tiny_tag__css, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Tag, _foreach, arginfo_vii_mvc_view_engine_tiny_tag__foreach, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Tag, _list, arginfo_vii_mvc_view_engine_tiny_tag__list, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
