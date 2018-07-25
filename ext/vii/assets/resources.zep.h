
extern zend_class_entry *vii_assets_resources_ce;

ZEPHIR_INIT_CLASS(Vii_Assets_Resources);

PHP_METHOD(Vii_Assets_Resources, __construct);
PHP_METHOD(Vii_Assets_Resources, getType);
PHP_METHOD(Vii_Assets_Resources, getPath);
PHP_METHOD(Vii_Assets_Resources, getLocal);
PHP_METHOD(Vii_Assets_Resources, setType);
PHP_METHOD(Vii_Assets_Resources, setPath);
PHP_METHOD(Vii_Assets_Resources, setLocal);
PHP_METHOD(Vii_Assets_Resources, checkType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_resources___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_resources_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_resources_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_resources_setlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_resources_checktype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_assets_resources_method_entry) {
	PHP_ME(Vii_Assets_Resources, __construct, arginfo_vii_assets_resources___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Assets_Resources, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Resources, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Resources, getLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Resources, setType, arginfo_vii_assets_resources_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Resources, setPath, arginfo_vii_assets_resources_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Resources, setLocal, arginfo_vii_assets_resources_setlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Resources, checkType, arginfo_vii_assets_resources_checktype, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
