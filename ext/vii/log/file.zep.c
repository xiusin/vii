
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Vii_Log_File) {

	ZEPHIR_REGISTER_CLASS_EX(Vii\\Log, File, vii, log_file, vii_log_driver_ce, vii_log_file_method_entry, 0);

	zend_declare_property_null(vii_log_file_ce, SL("_file"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_log_file_ce, SL("_timeFormat"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_log_file_ce, SL("_logformat"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(vii_log_file_ce TSRMLS_CC, 1, vii_interfaces_loginterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Log_File, __construct) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, filename, ext, _1, _2, _10, _11, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;
	zval filePath, _12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(&filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(&filePath);
		ZVAL_EMPTY_STRING(&filePath);
	}


	_0 = (zephir_file_exists(&filePath TSRMLS_CC) == SUCCESS);
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "filesize", NULL, 72, &filePath);
		zephir_check_call_status();
		zephir_read_static_property_ce(&_2, vii_log_driver_ce, SL("_logFileSize"), PH_NOISY_CC | PH_READONLY);
		_0 = ZEPHIR_GE_LONG(&_1, (1048576 * zephir_get_numberval(&_2)));
	}
	if (_0) {
		zephir_read_property(&_3$$3, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, ".");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "strrpos", NULL, 43, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&ext);
		zephir_substr(&ext, &filePath, zephir_get_intval(&_5$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "");
		ZEPHIR_CALL_FUNCTION(&filename, "strtr", NULL, 20, &filePath, &ext, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_VS(&_6$$3, &filename, "*");
		ZEPHIR_CALL_FUNCTION(&_7$$3, "glob", NULL, 76, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_8$$3);
		ZVAL_LONG(&_8$$3, zephir_fast_count_int(&_7$$3 TSRMLS_CC));
		ZEPHIR_INIT_VAR(&_9$$3);
		ZEPHIR_CONCAT_VVV(&_9$$3, &filename, &_8$$3, &ext);
		ZEPHIR_CALL_FUNCTION(NULL, "rename", NULL, 68, &filePath, &_9$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "createlogfile", NULL, 93, &filePath);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_file"), &filePath);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "Y-m-d H:i:s");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "settimeformat", NULL, 0, &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_SSSSSS(&_12, "[", "{{TIME}}", "] ", "{{LEVEL}}", ": ", "{{MESSAGE}}");
	ZEPHIR_CALL_METHOD(NULL, &_10, "setlogformat", NULL, 0, &_12);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Log_File, setTimeFormat) {

	zval *timeFormat_param = NULL;
	zval timeFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&timeFormat);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &timeFormat_param);

	if (UNEXPECTED(Z_TYPE_P(timeFormat_param) != IS_STRING && Z_TYPE_P(timeFormat_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'timeFormat' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(timeFormat_param) == IS_STRING)) {
		zephir_get_strval(&timeFormat, timeFormat_param);
	} else {
		ZEPHIR_INIT_VAR(&timeFormat);
		ZVAL_EMPTY_STRING(&timeFormat);
	}


	zephir_update_property_zval(this_ptr, SL("_timeFormat"), &timeFormat);
	RETURN_THIS();

}

PHP_METHOD(Vii_Log_File, createLogFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, __$true, _dirname, _0, _2, _5, _1$$3, _3$$4, _6$$5;
	zval filePath, _4$$4, _7$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_dirname);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(&filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(&filePath);
		ZVAL_EMPTY_STRING(&filePath);
	}


	ZEPHIR_CALL_FUNCTION(&_dirname, "dirname", NULL, 94, &filePath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 73, &_dirname);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZVAL_LONG(&_1$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 78, &_dirname, &_1$$3, &__$true);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "touch", NULL, 95, &filePath);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, vii_exceptions_logexception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_SVS(&_4$$4, "日志文件[", &filePath, "]创建失败");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 3, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "vii/log/file.zep", 39 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_5, "is_writable", NULL, 74, &filePath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, vii_exceptions_logexception_ce);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZEPHIR_CONCAT_SVS(&_7$$5, "日志文件", &filePath, "]无写权限");
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 3, &_7$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$5, "vii/log/file.zep", 42 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Log_File, setLogFormat) {

	zval *logformat_param = NULL;
	zval logformat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logformat);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &logformat_param);

	if (UNEXPECTED(Z_TYPE_P(logformat_param) != IS_STRING && Z_TYPE_P(logformat_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'logformat' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(logformat_param) == IS_STRING)) {
		zephir_get_strval(&logformat, logformat_param);
	} else {
		ZEPHIR_INIT_VAR(&logformat);
		ZVAL_EMPTY_STRING(&logformat);
	}


	zephir_update_property_zval(this_ptr, SL("_logformat"), &logformat);
	RETURN_THIS();

}

PHP_METHOD(Vii_Log_File, debug) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *message_param = NULL, *placeholders_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &placeholders_param);

	zephir_get_strval(&message, message_param);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DEBUG");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &placeholders);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Log_File, info) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *message_param = NULL, *placeholders_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &placeholders_param);

	zephir_get_strval(&message, message_param);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "INFO");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &placeholders);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Log_File, alert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *message_param = NULL, *placeholders_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &placeholders_param);

	zephir_get_strval(&message, message_param);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ALERT");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &placeholders);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Log_File, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *message_param = NULL, *placeholders_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &placeholders_param);

	zephir_get_strval(&message, message_param);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ERROR");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &placeholders);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Log_File, notice) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *message_param = NULL, *placeholders_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &placeholders_param);

	zephir_get_strval(&message, message_param);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "NOTICE");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &placeholders);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Log_File, warning) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *message_param = NULL, *placeholders_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &placeholders_param);

	zephir_get_strval(&message, message_param);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "WARNING");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &placeholders);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Log_File, _replacePlaceholders) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval *message_param = NULL, *placeholders_param = NULL, k, v, _replacePlaceholders, *_0, _3$$3;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_replacePlaceholders);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&placeholders);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &placeholders_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	zephir_is_iterable(&placeholders, 0, "vii/log/file.zep", 80);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&placeholders), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&k, _2);
		} else {
			ZVAL_LONG(&k, _1);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "{", &k, "}");
		zephir_array_update_zval(&_replacePlaceholders, &_3$$3, &v, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_CALL_FUNCTION(NULL, "strtr", NULL, 20, &message, &_replacePlaceholders);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Log_File, log) {

	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders, _5;
	zval *logLevel_param = NULL, *message_param = NULL, *placeholders_param = NULL, _0, _1, _3, line, _4, _6, _7, _8, _9, _10;
	zval logLevel, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logLevel);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&placeholders);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &logLevel_param, &message_param, &placeholders_param);

	if (UNEXPECTED(Z_TYPE_P(logLevel_param) != IS_STRING && Z_TYPE_P(logLevel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'logLevel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(logLevel_param) == IS_STRING)) {
		zephir_get_strval(&logLevel, logLevel_param);
	} else {
		ZEPHIR_INIT_VAR(&logLevel);
		ZVAL_EMPTY_STRING(&logLevel);
	}
	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}


	zephir_read_static_property_ce(&_0, vii_log_driver_ce, SL("_enable"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	zephir_read_static_property_ce(&_1, vii_log_driver_ce, SL("_recordLevel"), PH_NOISY_CC | PH_READONLY);
	_2 = !(zephir_fast_in_array(&_1, &logLevel TSRMLS_CC));
	if (_2) {
		zephir_read_static_property_ce(&_3, vii_log_driver_ce, SL("_recordLevel"), PH_NOISY_CC | PH_READONLY);
		_2 = !(ZEPHIR_IS_EMPTY(&_3));
	}
	if (_2) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_4, this_ptr, SL("_logformat"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 3, 0 TSRMLS_CC);
	zephir_read_property(&_6, this_ptr, SL("_timeFormat"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_7, "date", NULL, 96, &_6);
	zephir_check_call_status();
	zephir_array_update_string(&_5, SL("{{TIME}}"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_8);
	zephir_fast_strtoupper(&_8, &logLevel);
	zephir_array_update_string(&_5, SL("{{LEVEL}}"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "_replaceplaceholders", NULL, 97, &message, &placeholders);
	zephir_check_call_status();
	zephir_array_update_string(&_5, SL("{{MESSAGE}}"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_7, "strtr", NULL, 20, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_8);
	ZEPHIR_GET_CONSTANT(&_8, "PHP_EOL");
	ZEPHIR_INIT_VAR(&line);
	ZEPHIR_CONCAT_VV(&line, &_7, &_8);
	zephir_read_property(&_9, this_ptr, SL("_file"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_10, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 66, &_9, &line, &_10);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

