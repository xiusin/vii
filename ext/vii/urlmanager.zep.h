
extern zend_class_entry *vii_urlmanager_ce;

ZEPHIR_INIT_CLASS(Vii_UrlManager);

PHP_METHOD(Vii_UrlManager, setBaseUri);
PHP_METHOD(Vii_UrlManager, setStaticBaseUri);
PHP_METHOD(Vii_UrlManager, getBaseUri);
PHP_METHOD(Vii_UrlManager, getStaticBaseUri);
PHP_METHOD(Vii_UrlManager, setBasePath);
PHP_METHOD(Vii_UrlManager, getBasePath);
PHP_METHOD(Vii_UrlManager, path);
PHP_METHOD(Vii_UrlManager, getStatic);
PHP_METHOD(Vii_UrlManager, get);
PHP_METHOD(Vii_UrlManager, buildParams);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_urlmanager_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_urlmanager_setstaticbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, staticBaseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_urlmanager_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_urlmanager_path, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_urlmanager_getstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_urlmanager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_urlmanager_buildparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_urlmanager_method_entry) {
	PHP_ME(Vii_UrlManager, setBaseUri, arginfo_vii_urlmanager_setbaseuri, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UrlManager, setStaticBaseUri, arginfo_vii_urlmanager_setstaticbaseuri, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UrlManager, getBaseUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UrlManager, getStaticBaseUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UrlManager, setBasePath, arginfo_vii_urlmanager_setbasepath, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UrlManager, getBasePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UrlManager, path, arginfo_vii_urlmanager_path, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UrlManager, getStatic, arginfo_vii_urlmanager_getstatic, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UrlManager, get, arginfo_vii_urlmanager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UrlManager, buildParams, arginfo_vii_urlmanager_buildparams, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
