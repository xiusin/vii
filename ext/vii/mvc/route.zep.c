
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_Route) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc, Route, vii, mvc_route, vii_mvc_route_method_entry, 0);

	zend_declare_property_null(vii_mvc_route_ce, SL("_methods"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_mvc_route_ce, SL("pattern"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_mvc_route_ce, SL("compilePattern"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_route_ce, SL("path"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_mvc_route_ce, SL("name"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_route_ce, SL("match"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_route_ce, SL("defaultMatchMap"), ZEND_ACC_PRIVATE TSRMLS_CC);

	vii_mvc_route_ce->create_object = zephir_init_properties_Vii_Mvc_Route;
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_Route, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *httpMethods = NULL;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}
	if (!httpMethods) {
		httpMethods = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "compilepattern", NULL, 31, pattern, paths);
	zephir_check_call_status();
	if (Z_TYPE_P(httpMethods) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_methods"), httpMethods TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_Route, compilePattern) {

	zend_bool _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, *routepath = NULL, *_0, *_1, *_2, *_3, *_4 = NULL, *_5, _6, *_7, *_9, _10, *_11, *_12$$3, *_13$$3;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("pattern"), pattern TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&routepath, this_ptr, "getroutepath", NULL, 32, paths);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("path"), routepath TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("defaultMatchMap"), PH_NOISY_CC);
	zephir_array_keys(_1, _2 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("defaultMatchMap"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "array_values", NULL, 33, _3);
	zephir_check_call_status();
	zephir_fast_str_replace(&_0, _1, _4, pattern TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("compilePattern"), _0 TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("compilePattern"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "(", 0);
	ZEPHIR_INIT_VAR(_7);
	zephir_fast_strpos(_7, _5, &_6, 0 );
	_8 = Z_TYPE_P(_7) != IS_BOOL;
	if (!(_8)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("compilePattern"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_STRING(&_10, "[", 0);
		ZEPHIR_INIT_VAR(_11);
		zephir_fast_strpos(_11, _9, &_10, 0 );
		_8 = Z_TYPE_P(_11) != IS_BOOL;
	}
	if (_8) {
		_12$$3 = zephir_fetch_nproperty_this(this_ptr, SL("compilePattern"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_13$$3);
		ZEPHIR_CONCAT_SVS(_13$$3, "#^", _12$$3, "$#u");
		zephir_update_property_this(this_ptr, SL("compilePattern"), _13$$3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_Route, via) {

	zval *httpMethods_param = NULL;
	zval *httpMethods = NULL;

	zephir_fetch_params(0, 1, 0, &httpMethods_param);

	httpMethods = httpMethods_param;


	zephir_update_property_this(this_ptr, SL("_methods"), httpMethods TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_Route, setName) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_Route, getName) {

	

	RETURN_MEMBER(this_ptr, "name");

}

PHP_METHOD(Vii_Mvc_Route, match) {

	zval *callback;

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_this(this_ptr, SL("match"), callback TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_Route, getMatch) {

	

	RETURN_MEMBER(this_ptr, "match");

}

PHP_METHOD(Vii_Mvc_Route, getPattern) {

	

	RETURN_MEMBER(this_ptr, "pattern");

}

PHP_METHOD(Vii_Mvc_Route, getCompiledPattern) {

	

	RETURN_MEMBER(this_ptr, "compilePattern");

}

/**
 * Returns the paths
 */
PHP_METHOD(Vii_Mvc_Route, getPaths) {

	

	RETURN_MEMBER(this_ptr, "path");

}

PHP_METHOD(Vii_Mvc_Route, getRoutePath) {

	int ZEPHIR_LAST_CALL_STATUS, _3$$4;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *paths = NULL, *module$$4 = NULL, *controller$$4 = NULL, *action$$4 = NULL, _0$$4, *_1$$4 = NULL, *parts$$4 = NULL, *routePaths$$4 = NULL, _4$$11, *_5$$11 = NULL, *controllerInfo$$13 = NULL, *_6$$13, *_7$$13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &paths);

	if (!paths) {
		paths = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(paths) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	if (Z_TYPE_P(paths) == IS_STRING) {
		ZEPHIR_INIT_VAR(module$$4);
		ZVAL_NULL(module$$4);
		ZEPHIR_INIT_VAR(controller$$4);
		ZVAL_NULL(controller$$4);
		ZEPHIR_INIT_VAR(action$$4);
		ZVAL_NULL(action$$4);
		ZEPHIR_SINIT_VAR(_0$$4);
		ZVAL_STRING(&_0$$4, "::", 0);
		ZEPHIR_CALL_FUNCTION(&_1$$4, "stripos", &_2, 21, paths, &_0$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1$$4)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_routerexception_ce, "添加路由的第二个参数为字符串时必须含有 '::' ", "vii/mvc/route.zep", 96);
			return;
		}
		ZEPHIR_INIT_VAR(parts$$4);
		zephir_fast_explode_str(parts$$4, SL("::"), paths, LONG_MAX TSRMLS_CC);
		do {
			_3$$4 = zephir_fast_count_int(parts$$4 TSRMLS_CC);
			if (_3$$4 == 3) {
				ZEPHIR_OBS_NVAR(module$$4);
				zephir_array_fetch_long(&module$$4, parts$$4, 0, PH_NOISY, "vii/mvc/route.zep", 101 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(controller$$4);
				zephir_array_fetch_long(&controller$$4, parts$$4, 1, PH_NOISY, "vii/mvc/route.zep", 102 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(action$$4);
				zephir_array_fetch_long(&action$$4, parts$$4, 2, PH_NOISY, "vii/mvc/route.zep", 103 TSRMLS_CC);
				break;
			}
			if (_3$$4 == 2) {
				ZEPHIR_OBS_NVAR(controller$$4);
				zephir_array_fetch_long(&controller$$4, parts$$4, 0, PH_NOISY, "vii/mvc/route.zep", 106 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(action$$4);
				zephir_array_fetch_long(&action$$4, parts$$4, 1, PH_NOISY, "vii/mvc/route.zep", 107 TSRMLS_CC);
				break;
			}
			if (_3$$4 == 1) {
				ZEPHIR_OBS_NVAR(controller$$4);
				zephir_array_fetch_long(&controller$$4, parts$$4, 0, PH_NOISY, "vii/mvc/route.zep", 110 TSRMLS_CC);
				break;
			}
		} while(0);

		ZEPHIR_INIT_VAR(routePaths$$4);
		array_init(routePaths$$4);
		if (Z_TYPE_P(module$$4) != IS_NULL) {
			zephir_array_update_string(&routePaths$$4, SL("module"), &module$$4, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(action$$4) != IS_NULL) {
			zephir_array_update_string(&routePaths$$4, SL("action"), &action$$4, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(controller$$4) != IS_NULL) {
			ZEPHIR_SINIT_VAR(_4$$11);
			ZVAL_STRING(&_4$$11, "\\", 0);
			ZEPHIR_CALL_FUNCTION(&_5$$11, "stripos", &_2, 21, controller$$4, &_4$$11);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_5$$11)) {
				zephir_array_update_string(&routePaths$$4, SL("controller"), &controller$$4, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_VAR(controllerInfo$$13);
				zephir_fast_explode_str(controllerInfo$$13, SL("\\"), controller$$4, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_6$$13, controllerInfo$$13, (zephir_fast_count_int(controllerInfo$$13 TSRMLS_CC) - 1), PH_NOISY | PH_READONLY, "vii/mvc/route.zep", 126 TSRMLS_CC);
				zephir_array_update_string(&routePaths$$4, SL("controller"), &_6$$13, PH_COPY | PH_SEPARATE);
				zephir_array_unset_long(&controllerInfo$$13, (zephir_fast_count_int(controllerInfo$$13 TSRMLS_CC) - 1), PH_SEPARATE);
				ZEPHIR_INIT_VAR(_7$$13);
				zephir_fast_join_str(_7$$13, SL("\\"), controllerInfo$$13 TSRMLS_CC);
				zephir_array_update_string(&routePaths$$4, SL("namespace"), &_7$$13, PH_COPY | PH_SEPARATE);
			}
		}
		RETURN_CCTOR(routePaths$$4);
	} else {
		RETVAL_ZVAL(paths, 1, 0);
		RETURN_MM();
	}

}

zend_object_value zephir_init_properties_Vii_Mvc_Route(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("defaultMatchMap"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 6, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("/:module"), SL("/([a-zA-Z0-9_-]+)"), 1);
			add_assoc_stringl_ex(_1$$3, SS("/:controller"), SL("/([a-zA-Z0-9_-]+)"), 1);
			add_assoc_stringl_ex(_1$$3, SS("/:action"), SL("/([a-zA-Z0-9_]+)"), 1);
			add_assoc_stringl_ex(_1$$3, SS("/:params"), SL("(/.*)*"), 1);
			add_assoc_stringl_ex(_1$$3, SS("/:namespace"), SL("/([a-zA-Z0-9_-]+)"), 1);
			add_assoc_stringl_ex(_1$$3, SS("/:int"), SL("/([0-9]+)"), 1);
			zephir_update_property_this(this_ptr, SL("defaultMatchMap"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

