
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "Zend/zend_closures.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_View) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc, View, vii, mvc_view, vii_mvc_view_method_entry, 0);

	zend_declare_property_null(vii_mvc_view_ce, SL("engines"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(vii_mvc_view_ce, SL("mainView"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(vii_mvc_view_ce, SL("layoutsDir"), "layouts/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(vii_mvc_view_ce, SL("partialsDir"), "partials/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_ce, SL("viewsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_ce, SL("file"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(vii_mvc_view_ce, SL("silent"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_ce, SL("viewVar"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_ce, SL("ioc"), ZEND_ACC_PROTECTED TSRMLS_CC);

	vii_mvc_view_ce->create_object = zephir_init_properties_Vii_Mvc_View;

	zend_class_implements(vii_mvc_view_ce TSRMLS_CC, 1, vii_interfaces_viewinterface_ce);
	zend_class_implements(vii_mvc_view_ce TSRMLS_CC, 1, vii_interfaces_iocinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_View, setEngines) {

	zval *engines, engines_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines_sub);

	zephir_fetch_params(0, 1, 0, &engines);



	zephir_update_property_zval(this_ptr, SL("engines"), engines);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View, setContent) {

	zval *content, content_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);

	zephir_fetch_params(0, 1, 0, &content);



	zephir_update_property_zval(this_ptr, SL("content"), content);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "content");

}

PHP_METHOD(Vii_Mvc_View, setMainView) {

	zval *mainView, mainView_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mainView_sub);

	zephir_fetch_params(0, 1, 0, &mainView);



	zephir_update_property_zval(this_ptr, SL("mainView"), mainView);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View, getMainView) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "mainView");

}

PHP_METHOD(Vii_Mvc_View, setLayoutsDir) {

	zval *layoutsDir, layoutsDir_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&layoutsDir_sub);

	zephir_fetch_params(0, 1, 0, &layoutsDir);



	zephir_update_property_zval(this_ptr, SL("layoutsDir"), layoutsDir);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View, getLayoutsDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "layoutsDir");

}

PHP_METHOD(Vii_Mvc_View, setPartialsDir) {

	zval *partialsDir, partialsDir_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialsDir_sub);

	zephir_fetch_params(0, 1, 0, &partialsDir);



	zephir_update_property_zval(this_ptr, SL("partialsDir"), partialsDir);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View, getPartialsDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "partialsDir");

}

PHP_METHOD(Vii_Mvc_View, setViewsDir) {

	zval *viewsDir, viewsDir_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewsDir_sub);

	zephir_fetch_params(0, 1, 0, &viewsDir);



	zephir_update_property_zval(this_ptr, SL("viewsDir"), viewsDir);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View, getViewsDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "viewsDir");

}

PHP_METHOD(Vii_Mvc_View, setFile) {

	zval *file, file_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);

	zephir_fetch_params(0, 1, 0, &file);



	zephir_update_property_zval(this_ptr, SL("file"), file);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View, getFile) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "file");

}

PHP_METHOD(Vii_Mvc_View, setSilent) {

	zval *silent, silent_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&silent_sub);

	zephir_fetch_params(0, 1, 0, &silent);



	zephir_update_property_zval(this_ptr, SL("silent"), silent);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View, setIoc) {

	zval *_ioc, _ioc_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_ioc_sub);

	zephir_fetch_params(0, 1, 0, &_ioc);



	zephir_update_property_zval(this_ptr, SL("ioc"), _ioc);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View, getIoc) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "ioc");

}

/**
 * 获取注册的模板引擎
 */
PHP_METHOD(Vii_Mvc_View, getEngines) {

	zval _9$$6, _12$$8;
	zend_string *_7;
	zend_ulong _6;
	zval ext, engine, _0, _4, *_5, _1$$3, _2$$3, _3$$3, _8$$6, _10$$6, _11$$8, _13$$8, _14$$9, _15$$9, _16$$9;
	zephir_fcall_cache_entry *_17 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$8);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("engines"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, vii_mvc_view_engine_sleet_ce);
		zephir_read_property(&_2$$3, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 105, this_ptr, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, ".sleet");
		zephir_update_property_array(this_ptr, SL("engines"), &_3$$3, &_1$$3 TSRMLS_CC);
	}
	zephir_read_property(&_4, this_ptr, SL("engines"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "vii/mvc/view.zep", 51);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_4), _6, _7, _5)
	{
		ZEPHIR_INIT_NVAR(&ext);
		if (_7 != NULL) { 
			ZVAL_STR_COPY(&ext, _7);
		} else {
			ZVAL_LONG(&ext, _6);
		}
		ZEPHIR_INIT_NVAR(&engine);
		ZVAL_COPY(&engine, _5);
		if (Z_TYPE_P(&engine) == IS_OBJECT) {
			if (zephir_instance_of_ev(&engine, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(&_8$$6);
				ZEPHIR_INIT_NVAR(&_9$$6);
				zephir_create_array(&_9$$6, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&_9$$6, this_ptr);
				zephir_read_property(&_10$$6, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fast_append(&_9$$6, &_10$$6);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_8$$6, &engine, &_9$$6);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("engines"), &ext, &_8$$6 TSRMLS_CC);
			}
		} else {
			if (Z_TYPE_P(&engine) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_11$$8);
				ZEPHIR_INIT_NVAR(&_12$$8);
				zephir_create_array(&_12$$8, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&_12$$8, this_ptr);
				zephir_read_property(&_13$$8, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fast_append(&_12$$8, &_13$$8);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(&_11$$8, &engine, &_12$$8 TSRMLS_CC);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("engines"), &ext, &_11$$8 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(&_14$$9);
				object_init_ex(&_14$$9, vii_exceptions_viewexception_ce);
				ZEPHIR_INIT_NVAR(&_15$$9);
				ZVAL_STRING(&_15$$9, "不可用的模板引擎：%s");
				ZEPHIR_CALL_FUNCTION(&_16$$9, "sprintf", &_17, 106, &_15$$9, &ext);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_14$$9, "__construct", &_18, 3, &_16$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$9, "vii/mvc/view.zep", 47 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&engine);
	ZEPHIR_INIT_NVAR(&ext);
	RETURN_MM_MEMBER(getThis(), "engines");

}

/**
 * 通过变量渲染模板
 *
 * @param string 文件名
 * @param array 变量数组
 * @return string
 */
PHP_METHOD(Vii_Mvc_View, render) {

	zend_string *_4;
	zend_ulong _3;
	zend_bool exists = 0, _11;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file = NULL, file_sub, *data_param = NULL, __$null, ext, engine, engines, path, dir, dirs, content, _1, *_2, _10, _0$$3, _5$$5, *_7$$5, _6$$7, _8$$8, _12$$10, _13$$10, _14$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&dirs);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		file = &file_sub;
		file = &__$null;
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	exists = 0;
	ZEPHIR_INIT_VAR(&content);
	ZVAL_NULL(&content);
	if (Z_TYPE_P(file) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fast_strtolower(&_0$$3, file);
		zephir_update_property_zval(this_ptr, SL("file"), &_0$$3);
	}
	zephir_read_property(&_1, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_viewexception_ce, "渲染模板之前请先设置一个模板", "vii/mvc/view.zep", 73);
		return;
	}
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "getengines", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&engines, 0, "vii/mvc/view.zep", 94);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&ext);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&ext, _4);
		} else {
			ZVAL_LONG(&ext, _3);
		}
		ZEPHIR_INIT_NVAR(&engine);
		ZVAL_COPY(&engine, _2);
		ZEPHIR_OBS_NVAR(&_5$$5);
		zephir_read_property(&_5$$5, this_ptr, SL("viewsDir"), PH_NOISY_CC);
		if (Z_TYPE_P(&_5$$5) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&dirs);
			zephir_read_property(&dirs, this_ptr, SL("viewsDir"), PH_NOISY_CC);
		} else {
			ZEPHIR_INIT_NVAR(&dirs);
			zephir_create_array(&dirs, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_6$$7);
			zephir_read_property(&_6$$7, this_ptr, SL("viewsDir"), PH_NOISY_CC);
			zephir_array_fast_append(&dirs, &_6$$7);
		}
		zephir_is_iterable(&dirs, 0, "vii/mvc/view.zep", 93);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&dirs), _7$$5)
		{
			ZEPHIR_INIT_NVAR(&dir);
			ZVAL_COPY(&dir, _7$$5);
			zephir_read_property(&_8$$8, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&path);
			ZEPHIR_CONCAT_VVV(&path, &dir, &_8$$8, &ext);
			if ((zephir_file_exists(&path TSRMLS_CC) == SUCCESS)) {
				exists = 1;
				ZEPHIR_CALL_METHOD(&content, &engine, "render", &_9, 0, &path, &data);
				zephir_check_call_status();
				break;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&dir);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&engine);
	ZEPHIR_INIT_NVAR(&ext);
	zephir_read_property(&_10, this_ptr, SL("silent"), PH_NOISY_CC | PH_READONLY);
	_11 = !zephir_is_true(&_10);
	if (_11) {
		_11 = !exists;
	}
	if (_11) {
		ZEPHIR_INIT_VAR(&_12$$10);
		object_init_ex(&_12$$10, vii_exceptions_viewexception_ce);
		ZEPHIR_INIT_VAR(&_13$$10);
		ZVAL_STRING(&_13$$10, "模板文件 %s 不能被找到");
		ZEPHIR_CALL_FUNCTION(&_14$$10, "sprintf", NULL, 106, &_13$$10, &path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_12$$10, "__construct", NULL, 3, &_14$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$10, "vii/mvc/view.zep", 95 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&content);

}

/**
 * 加载模板
 *
 * @param string file 来自模板文件夹的没有扩展名的文件名
 * @param array data 要发送的数据
 * @return string
 */
PHP_METHOD(Vii_Mvc_View, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file_param = NULL, *data_param = NULL;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_EMPTY_STRING(&file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, &file, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 加载片段
 *
 * @param string file 来自片段文件夹的没有扩展名的文件名
 * @param array data Vars to send
 * @return string
 */
PHP_METHOD(Vii_Mvc_View, partial) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file_param = NULL, *data_param = NULL, _0, _1;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(&file, file_param);
	} else {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_EMPTY_STRING(&file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_read_property(&_0, this_ptr, SL("partialsDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, &_1, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 加载布局
 *
 * @param string file 相对于布局文件的布局名称
 * @param array data Vars to send
 * @return string
 */
PHP_METHOD(Vii_Mvc_View, layout) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *file = NULL, file_sub, *data_param = NULL, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &file, &data_param);

	if (!file) {
		file = &file_sub;
		ZEPHIR_CPY_WRT(file, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(file);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	if (!(zephir_is_true(file))) {
		ZEPHIR_OBS_NVAR(file);
		zephir_read_property(file, this_ptr, SL("mainView"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, SL("layoutsDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0, &_1, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置模板变量
 *
 * @param string name
 * @param mixed value
 */
PHP_METHOD(Vii_Mvc_View, setVar) {

	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_array(this_ptr, SL("viewVar"), &name, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 一次设置多个变量
 *
 * @param array vars
 */
PHP_METHOD(Vii_Mvc_View, setVars) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *vars_param = NULL, key, value, *_0;
	zval vars;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vars_param);

	ZEPHIR_OBS_COPY_OR_DUP(&vars, vars_param);


	zephir_is_iterable(&vars, 0, "vii/mvc/view.zep", 161);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&vars), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvar", &_3, 0, &key, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_View, getVars) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "viewVar");

}

/**
 * 设置布局文件
 * @param array vars
 */
PHP_METHOD(Vii_Mvc_View, setLayout) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *layout_param = NULL;
	zval layout;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&layout);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &layout_param);

	zephir_get_strval(&layout, layout_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmainview", NULL, 0, &layout);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_View, __toString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Vii_Mvc_View(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("viewVar"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("viewVar"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

