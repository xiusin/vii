
extern zend_class_entry *vii_mvc_application_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_Application);

PHP_METHOD(Vii_Mvc_Application, __construct);
PHP_METHOD(Vii_Mvc_Application, debug);
PHP_METHOD(Vii_Mvc_Application, handle);
PHP_METHOD(Vii_Mvc_Application, bootstrap);
PHP_METHOD(Vii_Mvc_Application, bulidBaseStruct);
PHP_METHOD(Vii_Mvc_Application, registerModules);
PHP_METHOD(Vii_Mvc_Application, getRegisterModuleByModuleName);
PHP_METHOD(Vii_Mvc_Application, getRegisterModules);
PHP_METHOD(Vii_Mvc_Application, setIoc);
PHP_METHOD(Vii_Mvc_Application, getIoc);
static zend_object *zephir_init_properties_Vii_Mvc_Application(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_application___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, ioc, Vii\\Interfaces\\IocInterface, 0)
	ZEND_ARG_INFO(0, composerAutoLoadFile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_application_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, debug)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_application_bootstrap, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_application_bulidbasestruct, 0, 0, 2)
	ZEND_ARG_INFO(0, applicationDirName)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_application_registermodules, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_application_getregistermodulebymodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_application_setioc, 0, 0, 1)
	ZEND_ARG_INFO(0, _ioc)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_application_method_entry) {
	PHP_ME(Vii_Mvc_Application, __construct, arginfo_vii_mvc_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_Application, debug, arginfo_vii_mvc_application_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Application, handle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Application, bootstrap, arginfo_vii_mvc_application_bootstrap, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Application, bulidBaseStruct, arginfo_vii_mvc_application_bulidbasestruct, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vii_Mvc_Application, registerModules, arginfo_vii_mvc_application_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Application, getRegisterModuleByModuleName, arginfo_vii_mvc_application_getregistermodulebymodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Application, getRegisterModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Application, setIoc, arginfo_vii_mvc_application_setioc, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Application, getIoc, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
