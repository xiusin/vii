
extern zend_class_entry *vii_mvc_view_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View);

PHP_METHOD(Vii_Mvc_View, setEngines);
PHP_METHOD(Vii_Mvc_View, setContent);
PHP_METHOD(Vii_Mvc_View, getContent);
PHP_METHOD(Vii_Mvc_View, setMainView);
PHP_METHOD(Vii_Mvc_View, getMainView);
PHP_METHOD(Vii_Mvc_View, setLayoutsDir);
PHP_METHOD(Vii_Mvc_View, getLayoutsDir);
PHP_METHOD(Vii_Mvc_View, setPartialsDir);
PHP_METHOD(Vii_Mvc_View, getPartialsDir);
PHP_METHOD(Vii_Mvc_View, setViewsDir);
PHP_METHOD(Vii_Mvc_View, getViewsDir);
PHP_METHOD(Vii_Mvc_View, setFile);
PHP_METHOD(Vii_Mvc_View, getFile);
PHP_METHOD(Vii_Mvc_View, setSilent);
PHP_METHOD(Vii_Mvc_View, setIoc);
PHP_METHOD(Vii_Mvc_View, getIoc);
PHP_METHOD(Vii_Mvc_View, getEngines);
PHP_METHOD(Vii_Mvc_View, render);
PHP_METHOD(Vii_Mvc_View, load);
PHP_METHOD(Vii_Mvc_View, partial);
PHP_METHOD(Vii_Mvc_View, layout);
PHP_METHOD(Vii_Mvc_View, setVar);
PHP_METHOD(Vii_Mvc_View, setVars);
PHP_METHOD(Vii_Mvc_View, getVars);
PHP_METHOD(Vii_Mvc_View, setLayout);
PHP_METHOD(Vii_Mvc_View, __toString);
static zend_object *zephir_init_properties_Vii_Mvc_View(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setengines, 0, 0, 1)
	ZEND_ARG_INFO(0, engines)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setmainview, 0, 0, 1)
	ZEND_ARG_INFO(0, mainView)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setlayoutsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, layoutsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setpartialsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, partialsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setsilent, 0, 0, 1)
	ZEND_ARG_INFO(0, silent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setioc, 0, 0, 1)
	ZEND_ARG_INFO(0, _ioc)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_render, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_load, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_layout, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setvars, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, vars, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_setlayout, 0, 0, 1)
	ZEND_ARG_INFO(0, layout)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_method_entry) {
	PHP_ME(Vii_Mvc_View, setEngines, arginfo_vii_mvc_view_setengines, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setContent, arginfo_vii_mvc_view_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setMainView, arginfo_vii_mvc_view_setmainview, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, getMainView, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setLayoutsDir, arginfo_vii_mvc_view_setlayoutsdir, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, getLayoutsDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setPartialsDir, arginfo_vii_mvc_view_setpartialsdir, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, getPartialsDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setViewsDir, arginfo_vii_mvc_view_setviewsdir, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, getViewsDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setFile, arginfo_vii_mvc_view_setfile, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, getFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setSilent, arginfo_vii_mvc_view_setsilent, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setIoc, arginfo_vii_mvc_view_setioc, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, getIoc, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, getEngines, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, render, arginfo_vii_mvc_view_render, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, load, arginfo_vii_mvc_view_load, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, partial, arginfo_vii_mvc_view_partial, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, layout, arginfo_vii_mvc_view_layout, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setVar, arginfo_vii_mvc_view_setvar, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setVars, arginfo_vii_mvc_view_setvars, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, getVars, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, setLayout, arginfo_vii_mvc_view_setlayout, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
