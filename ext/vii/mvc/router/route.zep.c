
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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


ZEPHIR_INIT_CLASS(Vii_Mvc_Router_Route) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc\\Router, Route, vii, mvc_router_route, vii_mvc_router_route_method_entry, 0);

	zend_declare_property_null(vii_mvc_router_route_ce, SL("_methods"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_mvc_router_route_ce, SL("pattern"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_mvc_router_route_ce, SL("compilePattern"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_route_ce, SL("path"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_mvc_router_route_ce, SL("name"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_route_ce, SL("match"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_route_ce, SL("beforeMatch"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_route_ce, SL("defaultMatchMap"), ZEND_ACC_PRIVATE TSRMLS_CC);

	vii_mvc_router_route_ce->create_object = zephir_init_properties_Vii_Mvc_Router_Route;
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_Router_Route, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, *httpMethods = NULL, httpMethods_sub, __$null;
	zval pattern;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&httpMethods_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &pattern_param, &paths, &httpMethods);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}
	if (!httpMethods) {
		httpMethods = &httpMethods_sub;
		httpMethods = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "compilepattern", NULL, 106, &pattern, paths);
	zephir_check_call_status();
	if (Z_TYPE_P(httpMethods) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_methods"), httpMethods);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_Router_Route, compilePattern) {

	zend_bool _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, routepath, _0, _1, _2, _3, _4, _5, _7, _8$$3, _9$$3;
	zval pattern;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&routepath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("pattern"), &pattern);
	ZEPHIR_CALL_METHOD(&routepath, this_ptr, "getroutepath", NULL, 107, paths);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("path"), &routepath);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, SL("defaultMatchMap"), PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(&_1, &_2 TSRMLS_CC);
	zephir_read_property(&_3, this_ptr, SL("defaultMatchMap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_4, "array_values", NULL, 36, &_3);
	zephir_check_call_status();
	zephir_fast_str_replace(&_0, &_1, &_4, &pattern TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("compilePattern"), &_0);
	zephir_read_property(&_5, this_ptr, SL("compilePattern"), PH_NOISY_CC | PH_READONLY);
	_6 = zephir_memnstr_str(&_5, SL("("), "vii/mvc/router/route.zep", 38);
	if (!(_6)) {
		zephir_read_property(&_7, this_ptr, SL("compilePattern"), PH_NOISY_CC | PH_READONLY);
		_6 = zephir_memnstr_str(&_7, SL("["), "vii/mvc/router/route.zep", 38);
	}
	if (_6) {
		zephir_read_property(&_8$$3, this_ptr, SL("compilePattern"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZEPHIR_CONCAT_SVS(&_9$$3, "#^", &_8$$3, "$#u");
		zephir_update_property_zval(this_ptr, SL("compilePattern"), &_9$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_Router_Route, via) {

	zval *httpMethods_param = NULL;
	zval httpMethods;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&httpMethods);

	zephir_fetch_params(0, 1, 0, &httpMethods_param);

	ZVAL_COPY_VALUE(&httpMethods, httpMethods_param);


	zephir_update_property_zval(this_ptr, SL("_methods"), &httpMethods);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_Router_Route, setName) {

	zval *name_param = NULL;
	zval name;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_zval(this_ptr, SL("name"), &name);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_Router_Route, getName) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "name");

}

PHP_METHOD(Vii_Mvc_Router_Route, match) {

	zval *callback, callback_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&callback_sub);

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_zval(this_ptr, SL("match"), callback);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_Router_Route, getMatch) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "match");

}

PHP_METHOD(Vii_Mvc_Router_Route, getPattern) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "pattern");

}

PHP_METHOD(Vii_Mvc_Router_Route, getMethods) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "_methods");

}

PHP_METHOD(Vii_Mvc_Router_Route, getCompiledPattern) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "compilePattern");

}

/**
 * Returns the paths
 */
PHP_METHOD(Vii_Mvc_Router_Route, getPaths) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "path");

}

PHP_METHOD(Vii_Mvc_Router_Route, getRoutePath) {

	int ZEPHIR_LAST_CALL_STATUS, _3$$4;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *paths = NULL, paths_sub, __$null, controllerInfo, module$$4, controller$$4, action$$4, _0$$4, _1$$4, parts$$4, routePaths$$4, _4$$11, _5$$11, _6$$13, _7$$13;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&controllerInfo);
	ZVAL_UNDEF(&module$$4);
	ZVAL_UNDEF(&controller$$4);
	ZVAL_UNDEF(&action$$4);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&parts$$4);
	ZVAL_UNDEF(&routePaths$$4);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$13);
	ZVAL_UNDEF(&_7$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &paths);

	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_INIT_VAR(&controllerInfo);
	array_init(&controllerInfo);
	if (Z_TYPE_P(paths) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	if (Z_TYPE_P(paths) == IS_STRING) {
		ZEPHIR_INIT_VAR(&module$$4);
		ZVAL_NULL(&module$$4);
		ZEPHIR_INIT_VAR(&controller$$4);
		ZVAL_NULL(&controller$$4);
		ZEPHIR_INIT_VAR(&action$$4);
		ZVAL_NULL(&action$$4);
		ZEPHIR_INIT_VAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "::");
		ZEPHIR_CALL_FUNCTION(&_1$$4, "stripos", &_2, 86, paths, &_0$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$4)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_routerexception_ce, "添加路由的第二个参数为字符串时必须含有 '::' ", "vii/mvc/router/route.zep", 100);
			return;
		}
		ZEPHIR_INIT_VAR(&parts$$4);
		zephir_fast_explode_str(&parts$$4, SL("::"), paths, LONG_MAX TSRMLS_CC);
		do {
			_3$$4 = zephir_fast_count_int(&parts$$4 TSRMLS_CC);
			if (_3$$4 == 3) {
				ZEPHIR_OBS_NVAR(&module$$4);
				zephir_array_fetch_long(&module$$4, &parts$$4, 0, PH_NOISY, "vii/mvc/router/route.zep", 105 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&controller$$4);
				zephir_array_fetch_long(&controller$$4, &parts$$4, 1, PH_NOISY, "vii/mvc/router/route.zep", 106 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&action$$4);
				zephir_array_fetch_long(&action$$4, &parts$$4, 2, PH_NOISY, "vii/mvc/router/route.zep", 107 TSRMLS_CC);
				break;
			}
			if (_3$$4 == 2) {
				ZEPHIR_OBS_NVAR(&controller$$4);
				zephir_array_fetch_long(&controller$$4, &parts$$4, 0, PH_NOISY, "vii/mvc/router/route.zep", 110 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&action$$4);
				zephir_array_fetch_long(&action$$4, &parts$$4, 1, PH_NOISY, "vii/mvc/router/route.zep", 111 TSRMLS_CC);
				break;
			}
			if (_3$$4 == 1) {
				ZEPHIR_OBS_NVAR(&controller$$4);
				zephir_array_fetch_long(&controller$$4, &parts$$4, 0, PH_NOISY, "vii/mvc/router/route.zep", 114 TSRMLS_CC);
				break;
			}
		} while(0);

		ZEPHIR_INIT_VAR(&routePaths$$4);
		array_init(&routePaths$$4);
		ZEPHIR_INIT_NVAR(&_0$$4);
		array_init(&_0$$4);
		zephir_array_update_string(&routePaths$$4, SL("params"), &_0$$4, PH_COPY | PH_SEPARATE);
		if (Z_TYPE_P(&module$$4) != IS_NULL) {
			zephir_array_update_string(&routePaths$$4, SL("module"), &module$$4, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&action$$4) != IS_NULL) {
			zephir_array_update_string(&routePaths$$4, SL("action"), &action$$4, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&controller$$4) != IS_NULL) {
			ZEPHIR_INIT_VAR(&_4$$11);
			ZVAL_STRING(&_4$$11, "\\");
			ZEPHIR_CALL_FUNCTION(&_5$$11, "stripos", &_2, 86, &controller$$4, &_4$$11);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$11)) {
				zephir_array_update_string(&routePaths$$4, SL("controller"), &controller$$4, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&controllerInfo);
				zephir_fast_explode_str(&controllerInfo, SL("\\"), &controller$$4, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_6$$13, &controllerInfo, (zephir_fast_count_int(&controllerInfo TSRMLS_CC) - 1), PH_NOISY | PH_READONLY, "vii/mvc/router/route.zep", 130 TSRMLS_CC);
				zephir_array_update_string(&routePaths$$4, SL("controller"), &_6$$13, PH_COPY | PH_SEPARATE);
				zephir_array_unset_long(&controllerInfo, (zephir_fast_count_int(&controllerInfo TSRMLS_CC) - 1), PH_SEPARATE);
				ZEPHIR_INIT_VAR(&_7$$13);
				zephir_fast_join_str(&_7$$13, SL("\\"), &controllerInfo TSRMLS_CC);
				zephir_array_update_string(&routePaths$$4, SL("namespace"), &_7$$13, PH_COPY | PH_SEPARATE);
			}
		}
		RETURN_CCTOR(routePaths$$4);
	} else {
		RETVAL_ZVAL(paths, 1, 0);
		RETURN_MM();
	}

}

PHP_METHOD(Vii_Mvc_Router_Route, setBeforeMatch) {

	zval *callback, callback_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&callback_sub);

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_zval(this_ptr, SL("beforeMatch"), callback);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_Router_Route, getBeforeMatch) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "beforeMatch");

}

static zend_object *zephir_init_properties_Vii_Mvc_Router_Route(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("defaultMatchMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 6, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("/:module"), SL("/([a-zA-Z0-9_-]+)"));
			add_assoc_stringl_ex(&_1$$3, SL("/:controller"), SL("/([a-zA-Z0-9_-]+)"));
			add_assoc_stringl_ex(&_1$$3, SL("/:action"), SL("/([a-zA-Z0-9_]+)"));
			add_assoc_stringl_ex(&_1$$3, SL("/:params"), SL("(/.*)*"));
			add_assoc_stringl_ex(&_1$$3, SL("/:namespace"), SL("/([a-zA-Z0-9_-]+)"));
			add_assoc_stringl_ex(&_1$$3, SL("/:int"), SL("/([0-9]+)"));
			zephir_update_property_zval(this_ptr, SL("defaultMatchMap"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("path"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

