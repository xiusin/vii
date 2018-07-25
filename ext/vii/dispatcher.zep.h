
extern zend_class_entry *vii_dispatcher_ce;

ZEPHIR_INIT_CLASS(Vii_Dispatcher);

PHP_METHOD(Vii_Dispatcher, setApp);
PHP_METHOD(Vii_Dispatcher, getApp);
PHP_METHOD(Vii_Dispatcher, setActionSuffix);
PHP_METHOD(Vii_Dispatcher, getActionSuffix);
PHP_METHOD(Vii_Dispatcher, setControllerSuffix);
PHP_METHOD(Vii_Dispatcher, getControllerSuffix);
PHP_METHOD(Vii_Dispatcher, getHandlerController);
PHP_METHOD(Vii_Dispatcher, dispatch);
PHP_METHOD(Vii_Dispatcher, setModuleHandleInfo);
PHP_METHOD(Vii_Dispatcher, setMatches);
PHP_METHOD(Vii_Dispatcher, setIoc);
PHP_METHOD(Vii_Dispatcher, getIoc);
PHP_METHOD(Vii_Dispatcher, getParams);
PHP_METHOD(Vii_Dispatcher, _exec);
PHP_METHOD(Vii_Dispatcher, sendContent);
PHP_METHOD(Vii_Dispatcher, loadModuleByName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dispatcher_setapp, 0, 0, 1)
	ZEND_ARG_INFO(0, appname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dispatcher_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dispatcher_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dispatcher_setmatches, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, matches, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dispatcher_setioc, 0, 0, 1)
	ZEND_ARG_INFO(0, _ioc)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dispatcher__exec, 0, 0, 1)
	ZEND_ARG_INFO(0, handlerClass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dispatcher_sendcontent, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_dispatcher_loadmodulebyname, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, module, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_dispatcher_method_entry) {
	PHP_ME(Vii_Dispatcher, setApp, arginfo_vii_dispatcher_setapp, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dispatcher, getApp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dispatcher, setActionSuffix, arginfo_vii_dispatcher_setactionsuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dispatcher, getActionSuffix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dispatcher, setControllerSuffix, arginfo_vii_dispatcher_setcontrollersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dispatcher, getControllerSuffix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dispatcher, getHandlerController, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Dispatcher, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dispatcher, setModuleHandleInfo, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Dispatcher, setMatches, arginfo_vii_dispatcher_setmatches, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Dispatcher, setIoc, arginfo_vii_dispatcher_setioc, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dispatcher, getIoc, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dispatcher, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Dispatcher, _exec, arginfo_vii_dispatcher__exec, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Dispatcher, sendContent, arginfo_vii_dispatcher_sendcontent, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Dispatcher, loadModuleByName, arginfo_vii_dispatcher_loadmodulebyname, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
