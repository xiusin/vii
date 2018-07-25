
extern zend_class_entry *vii_config_ce;

ZEPHIR_INIT_CLASS(Vii_Config);

PHP_METHOD(Vii_Config, __construct);
PHP_METHOD(Vii_Config, merge);
PHP_METHOD(Vii_Config, isValidKey);
PHP_METHOD(Vii_Config, toArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_config___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_config_merge, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, Vii\\Interfaces\\ConfigInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_config_isvalidkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_config_method_entry) {
	PHP_ME(Vii_Config, __construct, arginfo_vii_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Config, merge, arginfo_vii_config_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Config, isValidKey, arginfo_vii_config_isvalidkey, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Config, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
