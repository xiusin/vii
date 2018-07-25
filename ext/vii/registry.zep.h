
extern zend_class_entry *vii_registry_ce;

ZEPHIR_INIT_CLASS(Vii_Registry);

PHP_METHOD(Vii_Registry, __construct);
PHP_METHOD(Vii_Registry, offsetExists);
PHP_METHOD(Vii_Registry, offsetGet);
PHP_METHOD(Vii_Registry, offsetSet);
PHP_METHOD(Vii_Registry, offsetUnset);
PHP_METHOD(Vii_Registry, count);
PHP_METHOD(Vii_Registry, current);
PHP_METHOD(Vii_Registry, key);
PHP_METHOD(Vii_Registry, next);
PHP_METHOD(Vii_Registry, rewind);
PHP_METHOD(Vii_Registry, valid);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_registry_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_registry_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_registry_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_registry_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_registry_method_entry) {
	PHP_ME(Vii_Registry, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(Vii_Registry, offsetExists, arginfo_vii_registry_offsetexists, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Vii_Registry, offsetGet, arginfo_vii_registry_offsetget, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Vii_Registry, offsetSet, arginfo_vii_registry_offsetset, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Vii_Registry, offsetUnset, arginfo_vii_registry_offsetunset, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Vii_Registry, count, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Vii_Registry, current, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Vii_Registry, key, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Vii_Registry, next, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Vii_Registry, rewind, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Vii_Registry, valid, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
