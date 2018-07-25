
extern zend_class_entry *vii_dump_ce;

ZEPHIR_INIT_CLASS(Vii_Dump);

PHP_METHOD(Vii_Dump, getDetailed);
PHP_METHOD(Vii_Dump, setDetailed);
PHP_METHOD(Vii_Dump, getPlain);
PHP_METHOD(Vii_Dump, setPlain);
PHP_METHOD(Vii_Dump, getSkipIoc);
PHP_METHOD(Vii_Dump, setSkipIoc);
PHP_METHOD(Vii_Dump, __construct);
PHP_METHOD(Vii_Dump, all);
PHP_METHOD(Vii_Dump, getStyle);
PHP_METHOD(Vii_Dump, setStyles);
PHP_METHOD(Vii_Dump, one);
PHP_METHOD(Vii_Dump, output);
PHP_METHOD(Vii_Dump, variable);
PHP_METHOD(Vii_Dump, vars);
zend_object *zephir_init_properties_Vii_Dump(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dump_setdetailed, 0, 0, 1)
	ZEND_ARG_INFO(0, detailed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dump_setplain, 0, 0, 1)
	ZEND_ARG_INFO(0, plain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dump_setskipioc, 0, 0, 1)
	ZEND_ARG_INFO(0, skipIoc)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dump___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, detailed)
	ZEND_ARG_INFO(0, styles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dump_all, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dump_getstyle, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dump_setstyles, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, styles, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dump_one, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dump_output, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, tab)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dump_variable, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_dump_method_entry) {
	PHP_ME(Vii_Dump, getDetailed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dump, setDetailed, arginfo_vii_dump_setdetailed, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dump, getPlain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dump, setPlain, arginfo_vii_dump_setplain, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dump, getSkipIoc, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dump, setSkipIoc, arginfo_vii_dump_setskipioc, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dump, __construct, arginfo_vii_dump___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Dump, all, arginfo_vii_dump_all, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dump, getStyle, arginfo_vii_dump_getstyle, ZEND_ACC_PROTECTED)
	PHP_ME(Vii_Dump, setStyles, arginfo_vii_dump_setstyles, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dump, one, arginfo_vii_dump_one, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dump, output, arginfo_vii_dump_output, ZEND_ACC_PROTECTED)
	PHP_ME(Vii_Dump, variable, arginfo_vii_dump_variable, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dump, vars, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
