
extern zend_class_entry *vii_mvc_viewother_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_ViewOther);

PHP_METHOD(Vii_Mvc_ViewOther, setService);
PHP_METHOD(Vii_Mvc_ViewOther, getService);
PHP_METHOD(Vii_Mvc_ViewOther, setConfig);
PHP_METHOD(Vii_Mvc_ViewOther, getTplExt);
PHP_METHOD(Vii_Mvc_ViewOther, setViewDir);
PHP_METHOD(Vii_Mvc_ViewOther, getViewDir);
PHP_METHOD(Vii_Mvc_ViewOther, __construct);
PHP_METHOD(Vii_Mvc_ViewOther, assign);
PHP_METHOD(Vii_Mvc_ViewOther, start);
PHP_METHOD(Vii_Mvc_ViewOther, render);
PHP_METHOD(Vii_Mvc_ViewOther, finish);
PHP_METHOD(Vii_Mvc_ViewOther, display);
PHP_METHOD(Vii_Mvc_ViewOther, parse);
PHP_METHOD(Vii_Mvc_ViewOther, setLayout);
PHP_METHOD(Vii_Mvc_ViewOther, getContent);
PHP_METHOD(Vii_Mvc_ViewOther, getTpl);
PHP_METHOD(Vii_Mvc_ViewOther, get);
PHP_METHOD(Vii_Mvc_ViewOther, _fetch);
PHP_METHOD(Vii_Mvc_ViewOther, parseLayerout);
zend_object_value zephir_init_properties_Vii_Mvc_ViewOther(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother_setservice, 0, 0, 1)
	ZEND_ARG_INFO(0, _service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother_setconfig, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother_setviewdir, 0, 0, 1)
	ZEND_ARG_INFO(0, dirpath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother_assign, 0, 0, 1)
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_INFO(0, _value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother_render, 0, 0, 1)
	ZEND_ARG_INFO(0, templateName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother_display, 0, 0, 1)
	ZEND_ARG_INFO(0, templateName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother_setlayout, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother_gettpl, 0, 0, 1)
	ZEND_ARG_INFO(0, template)
	ZEND_ARG_INFO(0, _return)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother_get, 0, 0, 0)
	ZEND_ARG_INFO(0, _var)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother__fetch, 0, 0, 1)
	ZEND_ARG_INFO(0, templateFile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_viewother_parselayerout, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_viewother_method_entry) {
	PHP_ME(Vii_Mvc_ViewOther, setService, arginfo_vii_mvc_viewother_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, getService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, setConfig, arginfo_vii_mvc_viewother_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, getTplExt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, setViewDir, arginfo_vii_mvc_viewother_setviewdir, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, getViewDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, __construct, arginfo_vii_mvc_viewother___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_ViewOther, assign, arginfo_vii_mvc_viewother_assign, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, render, arginfo_vii_mvc_viewother_render, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, finish, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, display, arginfo_vii_mvc_viewother_display, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, parse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, setLayout, arginfo_vii_mvc_viewother_setlayout, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, getTpl, arginfo_vii_mvc_viewother_gettpl, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, get, arginfo_vii_mvc_viewother_get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_ViewOther, _fetch, arginfo_vii_mvc_viewother__fetch, ZEND_ACC_PROTECTED)
	PHP_ME(Vii_Mvc_ViewOther, parseLayerout, arginfo_vii_mvc_viewother_parselayerout, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
