
extern zend_class_entry *vii_mvc_view_engine_tiny_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Tiny);

PHP_METHOD(Vii_Mvc_View_Engine_Tiny, getCompileDir);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny, setOptions);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny, getOptions);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny, __construct);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny, getComiler);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny, render);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny, partial);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny, getContent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Vii\\Interfaces\\ViewInterface, 0)
	ZEND_ARG_OBJ_INFO(0, ioc, Vii\\Interfaces\\IocInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_render, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_engine_tiny_method_entry) {
	PHP_ME(Vii_Mvc_View_Engine_Tiny, getCompileDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny, setOptions, arginfo_vii_mvc_view_engine_tiny_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny, __construct, arginfo_vii_mvc_view_engine_tiny___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_View_Engine_Tiny, getComiler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny, render, arginfo_vii_mvc_view_engine_tiny_render, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny, partial, arginfo_vii_mvc_view_engine_tiny_partial, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
