
extern zend_class_entry *vii_mvc_view_engine_sleet_parser_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Sleet_Parser);

PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Parser, __construct);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Parser, text);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Parser, parse);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Parser, parseControl);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Parser, parseEcho);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Parser, parseSet);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Parser, parseUse);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Parser, doParse);
PHP_METHOD(Vii_Mvc_View_Engine_Sleet_Parser, token);
zend_object *zephir_init_properties_Vii_Mvc_View_Engine_Sleet_Parser(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_parser_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_parser_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_parser_parsecontrol, 0, 0, 2)
	ZEND_ARG_INFO(0, control)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_parser_parseecho, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_parser_parseset, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_parser_parseuse, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_parser_doparse, 0, 0, 1)
	ZEND_ARG_INFO(0, tokens)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_sleet_parser_token, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, prev)
	ZEND_ARG_INFO(0, next)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_engine_sleet_parser_method_entry) {
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Parser, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Parser, text, arginfo_vii_mvc_view_engine_sleet_parser_text, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Parser, parse, arginfo_vii_mvc_view_engine_sleet_parser_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Parser, parseControl, arginfo_vii_mvc_view_engine_sleet_parser_parsecontrol, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Parser, parseEcho, arginfo_vii_mvc_view_engine_sleet_parser_parseecho, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Parser, parseSet, arginfo_vii_mvc_view_engine_sleet_parser_parseset, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Parser, parseUse, arginfo_vii_mvc_view_engine_sleet_parser_parseuse, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Parser, doParse, arginfo_vii_mvc_view_engine_sleet_parser_doparse, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Mvc_View_Engine_Sleet_Parser, token, arginfo_vii_mvc_view_engine_sleet_parser_token, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
