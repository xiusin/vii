
extern zend_class_entry *vii_log_driver_ce;

ZEPHIR_INIT_CLASS(Vii_Log_Driver);

PHP_METHOD(Vii_Log_Driver, setRecordLevel);
PHP_METHOD(Vii_Log_Driver, disable);
PHP_METHOD(Vii_Log_Driver, setLogFileSize);
PHP_METHOD(Vii_Log_Driver, log);
void zephir_init_static_properties_Vii_Log_Driver(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_driver_setrecordlevel, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, recordLevel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_driver_setlogfilesize, 0, 0, 0)
	ZEND_ARG_INFO(0, _size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_driver_log, 0, 0, 2)
	ZEND_ARG_INFO(0, logLevel)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_log_driver_method_entry) {
	PHP_ME(Vii_Log_Driver, setRecordLevel, arginfo_vii_log_driver_setrecordlevel, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_Driver, disable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_Driver, setLogFileSize, arginfo_vii_log_driver_setlogfilesize, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_Driver, log, arginfo_vii_log_driver_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
