
extern zend_class_entry *vii_mvc_view_template_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View_Template);

PHP_METHOD(Vii_Mvc_View_Template, __construct);
PHP_METHOD(Vii_Mvc_View_Template, setConfig);
PHP_METHOD(Vii_Mvc_View_Template, getConfig);
PHP_METHOD(Vii_Mvc_View_Template, run);
PHP_METHOD(Vii_Mvc_View_Template, parseVarPath);
PHP_METHOD(Vii_Mvc_View_Template, parseTags);
PHP_METHOD(Vii_Mvc_View_Template, parseVar);
PHP_METHOD(Vii_Mvc_View_Template, parseLoad);
PHP_METHOD(Vii_Mvc_View_Template, parseBlock);
PHP_METHOD(Vii_Mvc_View_Template, _block);
PHP_METHOD(Vii_Mvc_View_Template, loadDpr);
PHP_METHOD(Vii_Mvc_View_Template, nocache);
PHP_METHOD(Vii_Mvc_View_Template, _nocache);
PHP_METHOD(Vii_Mvc_View_Template, replace_nocacheToVar);
PHP_METHOD(Vii_Mvc_View_Template, replace_blockContent);
zend_object_value zephir_init_properties_Vii_Mvc_View_Template(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_template___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_template_setconfig, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_template_getconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_template_run, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_template_parseload, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_template_parseblock, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_template__block, 0, 0, 1)
	ZEND_ARG_INFO(0, matchs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_template_loaddpr, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_template__nocache, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_template_method_entry) {
	PHP_ME(Vii_Mvc_View_Template, __construct, arginfo_vii_mvc_view_template___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_View_Template, setConfig, arginfo_vii_mvc_view_template_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, getConfig, arginfo_vii_mvc_view_template_getconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, run, arginfo_vii_mvc_view_template_run, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, parseVarPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, parseTags, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, parseVar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, parseLoad, arginfo_vii_mvc_view_template_parseload, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, parseBlock, arginfo_vii_mvc_view_template_parseblock, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, _block, arginfo_vii_mvc_view_template__block, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, loadDpr, arginfo_vii_mvc_view_template_loaddpr, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, nocache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, _nocache, arginfo_vii_mvc_view_template__nocache, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, replace_nocacheToVar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Template, replace_blockContent, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
