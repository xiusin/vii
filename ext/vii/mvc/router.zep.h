
extern zend_class_entry *vii_mvc_router_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_Router);

PHP_METHOD(Vii_Mvc_Router, setIoc);
PHP_METHOD(Vii_Mvc_Router, getIoc);
PHP_METHOD(Vii_Mvc_Router, __construct);
PHP_METHOD(Vii_Mvc_Router, add);
PHP_METHOD(Vii_Mvc_Router, handle);
PHP_METHOD(Vii_Mvc_Router, addGet);
PHP_METHOD(Vii_Mvc_Router, addPost);
PHP_METHOD(Vii_Mvc_Router, setDefaultModule);
PHP_METHOD(Vii_Mvc_Router, getDefaultModule);
PHP_METHOD(Vii_Mvc_Router, setDefaultNamespace);
PHP_METHOD(Vii_Mvc_Router, setDefaultController);
PHP_METHOD(Vii_Mvc_Router, setDefaultAction);
PHP_METHOD(Vii_Mvc_Router, getModuleName);
PHP_METHOD(Vii_Mvc_Router, getNamespaceName);
PHP_METHOD(Vii_Mvc_Router, getControllerName);
PHP_METHOD(Vii_Mvc_Router, getActionName);
PHP_METHOD(Vii_Mvc_Router, getParams);
PHP_METHOD(Vii_Mvc_Router, wasMatched);
PHP_METHOD(Vii_Mvc_Router, getRoutes);
PHP_METHOD(Vii_Mvc_Router, getMatchedRoute);
PHP_METHOD(Vii_Mvc_Router, setNotFound);
PHP_METHOD(Vii_Mvc_Router, getNotFound);
PHP_METHOD(Vii_Mvc_Router, getMatches);
zend_object *zephir_init_properties_Vii_Mvc_Router(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_setioc, 0, 0, 1)
	ZEND_ARG_INFO(0, _ioc)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, hasDefaultRouter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_add, 0, 0, 2)
	ZEND_ARG_INFO(0, pattren)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_handle, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_addget, 0, 0, 2)
	ZEND_ARG_INFO(0, pattren)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_addpost, 0, 0, 2)
	ZEND_ARG_INFO(0, pattren)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_setnotfound, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_router_method_entry) {
	PHP_ME(Vii_Mvc_Router, setIoc, arginfo_vii_mvc_router_setioc, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getIoc, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, __construct, arginfo_vii_mvc_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_Router, add, arginfo_vii_mvc_router_add, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, handle, arginfo_vii_mvc_router_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, addGet, arginfo_vii_mvc_router_addget, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, addPost, arginfo_vii_mvc_router_addpost, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, setDefaultModule, arginfo_vii_mvc_router_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, setDefaultNamespace, arginfo_vii_mvc_router_setdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, setDefaultController, arginfo_vii_mvc_router_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, setDefaultAction, arginfo_vii_mvc_router_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getNamespaceName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, wasMatched, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getMatchedRoute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, setNotFound, arginfo_vii_mvc_router_setnotfound, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getNotFound, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router, getMatches, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
