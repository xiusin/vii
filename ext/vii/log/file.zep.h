
extern zend_class_entry *vii_log_file_ce;

ZEPHIR_INIT_CLASS(Vii_Log_File);

PHP_METHOD(Vii_Log_File, __construct);
PHP_METHOD(Vii_Log_File, setTimeFormat);
PHP_METHOD(Vii_Log_File, createLogFile);
PHP_METHOD(Vii_Log_File, setLogFormat);
PHP_METHOD(Vii_Log_File, debug);
PHP_METHOD(Vii_Log_File, info);
PHP_METHOD(Vii_Log_File, alert);
PHP_METHOD(Vii_Log_File, error);
PHP_METHOD(Vii_Log_File, notice);
PHP_METHOD(Vii_Log_File, warning);
PHP_METHOD(Vii_Log_File, _replacePlaceholders);
PHP_METHOD(Vii_Log_File, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file_settimeformat, 0, 0, 1)
	ZEND_ARG_INFO(0, timeFormat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file_createlogfile, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file_setlogformat, 0, 0, 1)
	ZEND_ARG_INFO(0, logformat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file__replaceplaceholders, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_log_file_log, 0, 0, 2)
	ZEND_ARG_INFO(0, logLevel)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_log_file_method_entry) {
	PHP_ME(Vii_Log_File, __construct, arginfo_vii_log_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Log_File, setTimeFormat, arginfo_vii_log_file_settimeformat, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_File, createLogFile, arginfo_vii_log_file_createlogfile, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Log_File, setLogFormat, arginfo_vii_log_file_setlogformat, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_File, debug, arginfo_vii_log_file_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_File, info, arginfo_vii_log_file_info, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_File, alert, arginfo_vii_log_file_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_File, error, arginfo_vii_log_file_error, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_File, notice, arginfo_vii_log_file_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_File, warning, arginfo_vii_log_file_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Log_File, _replacePlaceholders, arginfo_vii_log_file__replaceplaceholders, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Log_File, log, arginfo_vii_log_file_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
