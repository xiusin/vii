
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
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Tiny) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc\\View\\Engine, Tiny, vii, mvc_view_engine_tiny, vii_mvc_view_engine_tiny_method_entry, 0);

	zend_declare_property_null(vii_mvc_view_engine_tiny_ce, SL("compileDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_ce, SL("compiler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_ce, SL("extension"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(vii_mvc_view_engine_tiny_ce TSRMLS_CC, 1, vii_interfaces_engineinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny, getCompileDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "compileDir");

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny, setOptions) {

	zval *options, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_zval(this_ptr, SL("options"), options);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "options");

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny, __construct) {

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
 * 获取编译组件
 */
PHP_METHOD(Vii_Mvc_View_Engine_Tiny, getComiler) {

	zval _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("compiler"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, vii_mvc_view_engine_tiny_compiler_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 132, this_ptr);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("compiler"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "compiler");

}

/**
 * 渲染模板
 * @type {Array}
 */
PHP_METHOD(Vii_Mvc_View_Engine_Tiny, render) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval data;
	zval *path_param = NULL, *data_param = NULL, __$true, compiled, compile_file, _0, _6, _7, _8, _9, _10, _1$$3, _2$$3, _3$$4, _5$$4, _11$$5;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&compiled);
	ZVAL_UNDEF(&compile_file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_11$$5);
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
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	}


	zephir_read_property(&_0, this_ptr, SL("compileDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&compile_file);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("compileDir"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_basename(&_2$$3, &path TSRMLS_CC);
		ZEPHIR_CONCAT_VSVS(&compile_file, &_1$$3, "/", &_2$$3, ".phtml");
	} else {
		ZEPHIR_CALL_FUNCTION(&_3$$4, "dirname", &_4, 94, &path);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_basename(&_5$$4, &path TSRMLS_CC);
		ZEPHIR_CONCAT_VSVS(&compile_file, &_3$$4, "/", &_5$$4, ".phtml");
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 49);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 0);
	ZEPHIR_MAKE_REF(&data);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 112, &data, &_6);
	ZEPHIR_UNREF(&data);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getcomiler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	zephir_file_get_contents(&_8, &path TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&compiled, &_7, "compile", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_9, "dirname", &_4, 94, &compile_file);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_10, "is_dir", NULL, 73, &_9);
	zephir_check_call_status();
	if (!(zephir_is_true(&_10))) {
		ZEPHIR_CALL_FUNCTION(&_11$$5, "dirname", &_4, 94, &compile_file);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 78, &_11$$5, &__$true);
		zephir_check_call_status();
	}
	zephir_file_put_contents(NULL, &compile_file, &compiled TSRMLS_CC);
	if (zephir_require_zval(&compile_file TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&compiled, "ob_get_clean", NULL, 48);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_6, "setcontent", NULL, 0, &compiled);
	zephir_check_call_status();
	RETURN_CCTOR(&compiled);

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny, partial) {

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

PHP_METHOD(Vii_Mvc_View_Engine_Tiny, getContent) {

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

