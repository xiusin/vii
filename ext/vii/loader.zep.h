
extern zend_class_entry *vii_loader_ce;

ZEPHIR_INIT_CLASS(Vii_Loader);

PHP_METHOD(Vii_Loader, __construct);
PHP_METHOD(Vii_Loader, setIoc);
PHP_METHOD(Vii_Loader, getIoc);
PHP_METHOD(Vii_Loader, setClassMapFile);
PHP_METHOD(Vii_Loader, registerNamespaces);
PHP_METHOD(Vii_Loader, registerClass);
PHP_METHOD(Vii_Loader, register);
PHP_METHOD(Vii_Loader, registerAutoload);
PHP_METHOD(Vii_Loader, loadFile);
PHP_METHOD(Vii_Loader, registerDirs);
PHP_METHOD(Vii_Loader, getNamespaces);
PHP_METHOD(Vii_Loader, saveMap);
PHP_METHOD(Vii_Loader, getMap);
static zend_object *zephir_init_properties_Vii_Loader(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_loader___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, classFileName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_loader_setioc, 0, 0, 1)
	ZEND_ARG_INFO(0, _ioc)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_loader_setclassmapfile, 0, 0, 0)
	ZEND_ARG_INFO(0, classFileName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_loader_registernamespaces, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, namespaceName, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_loader_registerclass, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, classArr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_loader_registerautoload, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_loader_loadfile, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_loader_registerdirs, 0, 0, 1)
	ZEND_ARG_INFO(0, dir_str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_loader_savemap, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_loader_method_entry) {
	PHP_ME(Vii_Loader, __construct, arginfo_vii_loader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Loader, setIoc, arginfo_vii_loader_setioc, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Loader, getIoc, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Loader, setClassMapFile, arginfo_vii_loader_setclassmapfile, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Loader, registerNamespaces, arginfo_vii_loader_registernamespaces, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Loader, registerClass, arginfo_vii_loader_registerclass, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Loader, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Loader, registerAutoload, arginfo_vii_loader_registerautoload, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Loader, loadFile, arginfo_vii_loader_loadfile, ZEND_ACC_PROTECTED)
	PHP_ME(Vii_Loader, registerDirs, arginfo_vii_loader_registerdirs, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Loader, getNamespaces, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Loader, saveMap, arginfo_vii_loader_savemap, ZEND_ACC_PROTECTED)
	PHP_ME(Vii_Loader, getMap, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
