
extern zend_class_entry *vii_mvc_view_engine_sleet_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Sleet);

PHP_METHOD(Vii_Mvc_View_Engine_Sleet, getCompiler);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, setOptions);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, __construct);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, compile);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, render);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, getContent);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, load);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, partial);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Vii\\Interfaces\\ViewInterface, 0)
	ZEND_ARG_OBJ_INFO(0, ioc, Vii\\Interfaces\\IocInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_compile, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_render, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_load, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_engine_sleet_method_entry) {
	PHP_ME(Vii_Mvc_View_Engine_Sleet, getCompiler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Sleet, setOptions, arginfo_vii_mvc_view_engine_sleet_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Sleet, __construct, arginfo_vii_mvc_view_engine_sleet___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_View_Engine_Sleet, compile, arginfo_vii_mvc_view_engine_sleet_compile, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Sleet, render, arginfo_vii_mvc_view_engine_sleet_render, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Sleet, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Sleet, load, arginfo_vii_mvc_view_engine_sleet_load, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Sleet, partial, arginfo_vii_mvc_view_engine_sleet_partial, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
