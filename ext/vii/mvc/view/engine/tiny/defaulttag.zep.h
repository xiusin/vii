
extern zend_class_entry *vii_mvc_view_engine_tiny_defaulttag_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Tiny_DefaultTag);

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _php);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _if);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _else);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _js);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _css);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _foreach);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _list);
zend_object_value zephir_init_properties_Vii_Mvc_View_Engine_Tiny_DefaultTag(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_defaulttag__php, 0, 0, 2)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_defaulttag__if, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_defaulttag__js, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_defaulttag__css, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_defaulttag__foreach, 0, 0, 2)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_defaulttag__list, 0, 0, 2)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_engine_tiny_defaulttag_method_entry) {
	PHP_ME(Vii_Mvc_View_Engine_Tiny_DefaultTag, _php, arginfo_vii_mvc_view_engine_tiny_defaulttag__php, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_DefaultTag, _if, arginfo_vii_mvc_view_engine_tiny_defaulttag__if, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_DefaultTag, _else, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_DefaultTag, _js, arginfo_vii_mvc_view_engine_tiny_defaulttag__js, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_DefaultTag, _css, arginfo_vii_mvc_view_engine_tiny_defaulttag__css, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_DefaultTag, _foreach, arginfo_vii_mvc_view_engine_tiny_defaulttag__foreach, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_DefaultTag, _list, arginfo_vii_mvc_view_engine_tiny_defaulttag__list, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
