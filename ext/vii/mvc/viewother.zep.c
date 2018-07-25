
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_ViewOther) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc, ViewOther, vii, mvc_viewother, vii_mvc_viewother_method_entry, 0);

	zend_declare_property_null(vii_mvc_viewother_ce, SL("tvars"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(vii_mvc_viewother_ce, SL("tplFile"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(vii_mvc_viewother_ce, SL("compileFile"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_viewother_ce, SL("cachePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_viewother_ce, SL("beforeBuffer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(vii_mvc_viewother_ce, SL("htmlFile"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_viewother_ce, SL("compileDir"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_viewother_ce, SL("htmlDir"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(vii_mvc_viewother_ce, SL("content"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(vii_mvc_viewother_ce, SL("layout"), "layout", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(vii_mvc_viewother_ce, SL("viewDir"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_viewother_ce, SL("service"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_viewother_ce, SL("config"), ZEND_ACC_PUBLIC TSRMLS_CC);

	vii_mvc_viewother_ce->create_object = zephir_init_properties_Vii_Mvc_ViewOther;
	zend_declare_class_constant_string(vii_mvc_viewother_ce, SL("VIEW_DISPLAY_FILE"), "FILE" TSRMLS_CC);

	zend_declare_class_constant_string(vii_mvc_viewother_ce, SL("VIEW_DISPLAY_PHP"), "PHP" TSRMLS_CC);

	zend_class_implements(vii_mvc_viewother_ce TSRMLS_CC, 1, vii_interfaces_serviceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_ViewOther, setService) {

	zval *_service;

	zephir_fetch_params(0, 1, 0, &_service);



	zephir_update_property_this(this_ptr, SL("service"), _service TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_ViewOther, getService) {

	

	RETURN_MEMBER(this_ptr, "service");

}

PHP_METHOD(Vii_Mvc_ViewOther, setConfig) {

	zval *key, *value;

	zephir_fetch_params(0, 2, 0, &key, &value);



	zephir_update_property_array(this_ptr, SL("config"), key, value TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_ViewOther, getTplExt) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("TPL_SUFFIX"), PH_NOISY | PH_READONLY, "vii/mvc/viewother.zep", 40 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(Vii_Mvc_ViewOther, setViewDir) {

	zval *dirpath_param = NULL;
	zval *dirpath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dirpath_param);

	if (unlikely(Z_TYPE_P(dirpath_param) != IS_STRING && Z_TYPE_P(dirpath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dirpath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(dirpath_param) == IS_STRING)) {
		zephir_get_strval(dirpath, dirpath_param);
	} else {
		ZEPHIR_INIT_VAR(dirpath);
		ZVAL_EMPTY_STRING(dirpath);
	}


	zephir_update_property_this(this_ptr, SL("viewDir"), dirpath TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_ViewOther, getViewDir) {

	

	RETURN_MEMBER(this_ptr, "viewDir");

}

PHP_METHOD(Vii_Mvc_ViewOther, __construct) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zval *config_param = NULL, *k = NULL, *v = NULL, **_2$$3, *_3$$4, *_4$$5 = NULL;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config_param);

	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
	config = config_param;
	}


	if (!(ZEPHIR_IS_EMPTY(config))) {
		zephir_is_iterable(config, &_1$$3, &_0$$3, 0, 0, "vii/mvc/viewother.zep", 61);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(k, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(v, _2$$3);
			_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			if (zephir_array_key_exists(_3$$4, k TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(_4$$5);
				zephir_fast_strtoupper(_4$$5, k);
				zephir_update_property_array(this_ptr, SL("config"), _4$$5, v TSRMLS_CC);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_ViewOther, assign) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zval *_var, *_value = NULL, *k = NULL, *v = NULL, **_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &_var, &_value);

	if (!_value) {
		_value = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(_var) == IS_ARRAY) {
		zephir_is_iterable(_var, &_1$$3, &_0$$3, 0, 0, "vii/mvc/viewother.zep", 73);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(k, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(v, _2$$3);
			if (zephir_is_numeric(k)) {
				continue;
			}
			zephir_update_property_array(this_ptr, SL("tvars"), k, v TSRMLS_CC);
		}
		RETURN_MM_NULL();
	}
	zephir_update_property_array(this_ptr, SL("tvars"), _var, _value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_ViewOther, start) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 38);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_ViewOther, render) {

	zend_bool _2;
	zephir_fcall_cache_entry *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *templateName, *base_cache_dir = NULL, *_0, *_1 = NULL, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13, *_14$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &templateName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(base_cache_dir);
	zephir_array_fetch_string(&base_cache_dir, _0, SL("BASE_CACHE_PATH"), PH_NOISY, "vii/mvc/viewother.zep", 85 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "is_dir", NULL, 64, base_cache_dir);
	zephir_check_call_status();
	_2 = !zephir_is_true(_1);
	if (_2) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_4, _3, SL("CACHE_TYPE"), PH_NOISY | PH_READONLY, "vii/mvc/viewother.zep", 86 TSRMLS_CC);
		_2 = ZEPHIR_IS_STRING(_4, "FILE");
	}
	if (_2) {
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 65, base_cache_dir, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("cachePath"), base_cache_dir TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("cachePath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, _5, "/compile");
	zephir_update_property_this(this_ptr, SL("compileDir"), _6 TSRMLS_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("cachePath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VS(_8, _7, "/cache");
	zephir_update_property_this(this_ptr, SL("htmlDir"), _8 TSRMLS_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("compileDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_10);
	zephir_md5(_10, templateName);
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_VSVS(_11, _9, "/", _10, ".php");
	zephir_update_property_this(this_ptr, SL("compileFile"), _11 TSRMLS_CC);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_13, _12, SL("CACHE_TYPE"), PH_NOISY | PH_READONLY, "vii/mvc/viewother.zep", 93 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_13, "PHP")) {
		ZEPHIR_CALL_METHOD(&_14$$4, this_ptr, "_fetch", &_15, 0, templateName);
		zephir_check_call_status();
		zend_print_zval(_14$$4, 0);
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_fetch", &_15, 0, templateName);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_ViewOther, finish) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 37);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Mvc_ViewOther, display) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *templateName;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &templateName);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "start", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "render", NULL, 0, templateName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "finish", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Mvc_ViewOther, parse) {

	zval *parseEngine = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(parseEngine);
	object_init_ex(parseEngine, vii_mvc_view_template_ce);
	ZEPHIR_CALL_METHOD(NULL, parseEngine, "__construct", NULL, 107, this_ptr);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(parseEngine, "run", NULL, 108, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Mvc_ViewOther, setLayout) {

	zval *str;

	zephir_fetch_params(0, 1, 0, &str);



	zephir_update_property_this(this_ptr, SL("layout"), str TSRMLS_CC);

}

PHP_METHOD(Vii_Mvc_ViewOther, getContent) {

	zval *_0 = NULL, *_1, *_2;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("tplFile"), PH_NOISY_CC);
	zephir_file_get_contents(_1, _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parselayerout", NULL, 0, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("content"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 获取模板路径
 * @demo index => index.tpl
 */
PHP_METHOD(Vii_Mvc_ViewOther, getTpl) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *template = NULL, *_return = NULL, *_0, *_1, *_2, *_3, *_4$$3, *_5$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &template, &_return);

	ZEPHIR_SEPARATE_PARAM(template);
	if (!_return) {
		_return = ZEPHIR_GLOBAL(global_false);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("viewDir"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("TPL_SUFFIX"), PH_NOISY | PH_READONLY, "vii/mvc/viewother.zep", 134 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VVV(_3, _0, template, _2);
	ZEPHIR_CPY_WRT(template, _3);
	if (!((zephir_file_exists(template TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, vii_exceptions_templateexception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SVS(_5$$3, "模板文件:", template, "不存在");
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 4, _5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "vii/mvc/viewother.zep", 136 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("tplFile"), template TSRMLS_CC);
	if (!(zephir_is_true(_return))) {
		RETURN_THIS();
	} else {
		RETVAL_ZVAL(template, 1, 0);
		RETURN_MM();
	}

}

PHP_METHOD(Vii_Mvc_ViewOther, get) {

	zval *_var = NULL, *_0, *_1$$4, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &_var);

	if (!_var) {
		ZEPHIR_INIT_VAR(_var);
		ZVAL_STRING(_var, "", 1);
	}


	if (ZEPHIR_IS_STRING(_var, "")) {
		RETURN_MM_MEMBER(this_ptr, "tvars");
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tvars"), PH_NOISY_CC);
	if (zephir_array_isset(_0, _var)) {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("tvars"), PH_NOISY_CC);
		zephir_array_fetch(&_2$$4, _1$$4, _var, PH_NOISY | PH_READONLY, "vii/mvc/viewother.zep", 152 TSRMLS_CC);
		RETURN_CTOR(_2$$4);
	} else {
		RETURN_MM_NULL();
	}

}

PHP_METHOD(Vii_Mvc_ViewOther, _fetch) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *templateFile, *content = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_7 = NULL, *_10, *_11, *_8$$3, *_9$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &templateFile);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tvars"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 85, _0, _1);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "gettpl", NULL, 0, templateFile);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, _2, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&content, _3, "parse", NULL, 0);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("compileFile"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_5, "dirname", &_6, 63, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "is_dir", NULL, 64, _5);
	zephir_check_call_status();
	if (!(zephir_is_true(_7))) {
		_8$$3 = zephir_fetch_nproperty_this(this_ptr, SL("compileFile"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_9$$3, "dirname", &_6, 63, _8$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 65, _9$$3, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("compileFile"), PH_NOISY_CC);
	zephir_file_put_contents(NULL, _10, content TSRMLS_CC);
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property_this(&_11, this_ptr, SL("compileFile"), PH_NOISY_CC);
	if (zephir_require_zval(_11 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_ViewOther, parseLayerout) {

	zval *content, *layoutPath = NULL, *layoutStr = NULL, *layout_content = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	ZEPHIR_INIT_VAR(layoutStr);
	ZVAL_STRING(layoutStr, "{__CONTENT__}", 1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("viewDir"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("layout"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(layoutPath);
	ZEPHIR_CONCAT_VVS(layoutPath, _0, _1, ".html");
	if (!((zephir_file_exists(layoutPath TSRMLS_CC) == SUCCESS))) {
		RETVAL_ZVAL(content, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(layout_content);
	zephir_file_get_contents(layout_content, layoutPath TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_str_replace(&_2, layoutStr, content, layout_content TSRMLS_CC);
	RETURN_CCTOR(_2);

}

zend_object_value zephir_init_properties_Vii_Mvc_ViewOther(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0, *_2, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("CACHE_TYPE"), SL("FILE"), 1);
			add_assoc_stringl_ex(_1$$3, SS("BASE_CACHE_PATH"), SL("cache"), 1);
			add_assoc_stringl_ex(_1$$3, SS("TPL_SUFFIX"), SL(".tpl"), 1);
			zephir_update_property_this(this_ptr, SL("config"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("tvars"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("tvars"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

