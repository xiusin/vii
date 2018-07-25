
extern zend_class_entry *vii_registrydefault_ce;

ZEPHIR_INIT_CLASS(Vii_RegistryDefault);

PHP_METHOD(Vii_RegistryDefault, __construct);
PHP_METHOD(Vii_RegistryDefault, setAssets);
PHP_METHOD(Vii_RegistryDefault, setUrlManager);
PHP_METHOD(Vii_RegistryDefault, setCookie);
PHP_METHOD(Vii_RegistryDefault, setRequest);
PHP_METHOD(Vii_RegistryDefault, setResponse);
PHP_METHOD(Vii_RegistryDefault, setDispatcher);

ZEPHIR_INIT_FUNCS(vii_registrydefault_method_entry) {
	PHP_ME(Vii_RegistryDefault, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_RegistryDefault, setAssets, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_RegistryDefault, setUrlManager, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_RegistryDefault, setCookie, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_RegistryDefault, setRequest, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_RegistryDefault, setResponse, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_RegistryDefault, setDispatcher, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
