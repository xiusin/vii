
extern zend_class_entry *vii_config_json_ce;

ZEPHIR_INIT_CLASS(Vii_Config_Json);

PHP_METHOD(Vii_Config_Json, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_config_json___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, jsonFile)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_config_json_method_entry) {
	PHP_ME(Vii_Config_Json, __construct, arginfo_vii_config_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
