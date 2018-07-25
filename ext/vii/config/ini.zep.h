
extern zend_class_entry *vii_config_ini_ce;

ZEPHIR_INIT_CLASS(Vii_Config_Ini);

PHP_METHOD(Vii_Config_Ini, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_config_ini___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, inipath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_config_ini_method_entry) {
	PHP_ME(Vii_Config_Ini, __construct, arginfo_vii_config_ini___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
