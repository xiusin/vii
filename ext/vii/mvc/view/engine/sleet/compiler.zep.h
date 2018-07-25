
extern zend_class_entry *vii_mvc_view_engine_sleet_compiler_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Sleet_Compiler);

PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Compiler, getParser);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Compiler, __construct);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Compiler, compile);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Compiler, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_compiler___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_compiler_compile, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_engine_sleet_compiler_method_entry) {
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Compiler, getParser, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Compiler, __construct, arginfo_vii_mvc_view_engine_sleet_compiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Compiler, compile, arginfo_vii_mvc_view_engine_sleet_compiler_compile, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Compiler, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
