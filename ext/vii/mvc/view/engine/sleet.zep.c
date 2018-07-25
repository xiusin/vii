
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/require.h"


/**
 * Sleet template engine. Syntax is similar to Twig, Volt or Django.
 */
ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Sleet) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc\\View\\Engine, Sleet, vii, mvc_view_engine_sleet, vii_mvc_view_engine_sleet_method_entry, 0);

	zend_declare_property_null(vii_mvc_view_engine_sleet_ce, SL("compiler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_sleet_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_sleet_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_sleet_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(vii_mvc_view_engine_sleet_ce TSRMLS_CC, 1, vii_interfaces_engineinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_View_Engine_Sleet, getCompiler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "compiler");

}

PHP_METHOD(Vii_Mvc_View_Engine_Sleet, setOptions) {

	zval *options, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_zval(this_ptr, SL("options"), options);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View_Engine_Sleet, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *view, view_sub, *ioc = NULL, ioc_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);
	ZVAL_UNDEF(&ioc_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &view, &ioc);

	if (!ioc) {
		ioc = &ioc_sub;
		ioc = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("view"), view);
	if (!(zephir_is_true(ioc))) {
		ZEPHIR_CALL_CE_STATIC(&_0$$3, vii_ioc_ce, "getdefault", &_1, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("di"), &_0$$3);
	}
	zephir_update_property_zval(this_ptr, SL("di"), ioc);
	ZEPHIR_MM_RESTORE();

}

/**
 * Compile the .sleet file.
 *
 * @param string path 编译的文件
 * @return string Path 编译文件地址
 */
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, compile) {

	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, __$true, compileDir, compile, trim, dir, file, compiledPath, old, compiled, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10$$9, _11$$9, _12$$10, _13$$12, _16$$12, _14$$13;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&compileDir);
	ZVAL_UNDEF(&compile);
	ZVAL_UNDEF(&trim);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&compiledPath);
	ZVAL_UNDEF(&old);
	ZVAL_UNDEF(&compiled);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_14$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	ZEPHIR_OBS_VAR(&trim);
	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_string_fetch(&trim, &_0, SL("trimPath"), 0);
	ZEPHIR_OBS_VAR(&compileDir);
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_string_fetch(&compileDir, &_1, SL("compileDir"), 0);
	ZEPHIR_OBS_VAR(&compile);
	zephir_read_property(&_2, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_isset_string_fetch(&compile, &_2, SL("compile"), 0);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/");
	zephir_fast_trim(&_3, &compileDir, &_4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CALL_FUNCTION(&_6, "dirname", NULL, 94, &path);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "realpath", NULL, 107, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "");
	zephir_fast_str_replace(&_5, &trim, &_8, &_7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&dir);
	ZEPHIR_CONCAT_VV(&dir, &_3, &_5);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, ".sleet");
	ZEPHIR_CALL_FUNCTION(&file, "basename", NULL, 108, &path, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&compiledPath);
	ZEPHIR_CONCAT_VSVS(&compiledPath, &dir, "/", &file, ".phtml");
	do {
		if (ZEPHIR_IS_LONG(&compile, 0)) {
			ZEPHIR_INIT_NVAR(&compile);
			ZVAL_BOOL(&compile, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(&compile, 1)) {
			ZEPHIR_INIT_NVAR(&compile);
			ZVAL_BOOL(&compile, !((zephir_file_exists(&compiledPath TSRMLS_CC) == SUCCESS)));
			break;
		}
		if (ZEPHIR_IS_LONG(&compile, 2)) {
			if (!((zephir_file_exists(&compiledPath TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_NVAR(&compile);
				ZVAL_BOOL(&compile, 1);
			} else {
				ZEPHIR_CALL_FUNCTION(&compile, "md5_file", NULL, 109, &compiledPath);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_INIT_NVAR(&compile);
		ZVAL_BOOL(&compile, 1);
		break;
	} while(0);

	if (zephir_is_true(&compile)) {
		ZEPHIR_INIT_VAR(&_10$$9);
		object_init_ex(&_10$$9, vii_mvc_view_engine_sleet_compiler_ce);
		ZEPHIR_CALL_METHOD(NULL, &_10$$9, "__construct", NULL, 110, this_ptr);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("compiler"), &_10$$9);
		zephir_read_property(&_11$$9, this_ptr, SL("compiler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&compiled, &_11$$9, "compile", NULL, 0, &path);
		zephir_check_call_status();
		if (Z_TYPE_P(&compile) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_12$$10);
			zephir_md5(&_12$$10, &compiled);
			if (!ZEPHIR_IS_EQUAL(&compile, &_12$$10)) {
				ZEPHIR_INIT_NVAR(&compile);
				ZVAL_BOOL(&compile, 1);
			}
		}
		if (ZEPHIR_IS_TRUE_IDENTICAL(&compile)) {
			ZEPHIR_CALL_FUNCTION(&_13$$12, "is_dir", NULL, 73, &dir);
			zephir_check_call_status();
			if (!(zephir_is_true(&_13$$12))) {
				ZVAL_LONG(&_14$$13, 0);
				ZEPHIR_CALL_FUNCTION(&old, "umask", &_15, 111, &_14$$13);
				zephir_check_call_status();
				ZVAL_LONG(&_14$$13, 0777);
				ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 78, &dir, &_14$$13, &__$true);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "umask", &_15, 111, &old);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_VAR(&_16$$12);
			zephir_file_put_contents(&_16$$12, &compiledPath, &compiled TSRMLS_CC);
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_16$$12)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_viewexception_ce, "模板编译目录不可写", "vii/mvc/view/engine/sleet.zep", 87);
				return;
			}
		}
	}
	RETURN_CCTOR(&compiledPath);

}

PHP_METHOD(Vii_Mvc_View_Engine_Sleet, render) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *path_param = NULL, *data_param = NULL, _0;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "compile", NULL, 0, &path);
	zephir_check_call_status();
	zephir_get_strval(&path, &_0);
	ZEPHIR_MAKE_REF(&data);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 112, &data);
	ZEPHIR_UNREF(&data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 49);
	zephir_check_call_status();
	if (zephir_require_zval(&path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 48);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the view content.
 *
 * @return string
 */
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, getContent) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load some view.
 *
 * @param string path
 * @param array data
 */
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *path_param = NULL, *data_param = NULL, _0;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "load", NULL, 0, &path, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Load some partial view.
 *
 * @param string path
 * @param array data
 */
PHP_METHOD(Vii_Mvc_View_Engine_Sleet, partial) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *path_param = NULL, *data_param = NULL, _0;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "partial", NULL, 0, &path, &data);
	zephir_check_call_status();
	RETURN_MM();

}

