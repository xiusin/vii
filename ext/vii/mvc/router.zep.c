
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_Router) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc, Router, vii, mvc_router, vii_mvc_router_method_entry, 0);

	zend_declare_property_null(vii_mvc_router_ce, SL("ioc"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("routes"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("namespaceName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("moduleName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("controllerName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("actionName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("defaultNamespaceName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("defaultModuleName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("defaultControllerName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("defaultActionName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("_group"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("_notFound"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("matchedRoute"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("_params"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(vii_mvc_router_ce, SL("_wasMatched"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_router_ce, SL("_uriSource"), ZEND_ACC_PRIVATE TSRMLS_CC);

	vii_mvc_router_ce->create_object = zephir_init_properties_Vii_Mvc_Router;

	zend_class_implements(vii_mvc_router_ce TSRMLS_CC, 1, vii_interfaces_iocinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_Router, setIoc) {

	zval *_ioc, _ioc_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_ioc_sub);

	zephir_fetch_params(0, 1, 0, &_ioc);



	zephir_update_property_zval(this_ptr, SL("ioc"), _ioc);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_Router, getIoc) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "ioc");

}

PHP_METHOD(Vii_Mvc_Router, __construct) {

	zval _1$$3, _4$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *hasDefaultRouter_param = NULL, _0$$3, _2$$3;
	zend_bool hasDefaultRouter;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &hasDefaultRouter_param);

	if (!hasDefaultRouter_param) {
		hasDefaultRouter = 1;
	} else {
	if (unlikely(Z_TYPE_P(hasDefaultRouter_param) != IS_TRUE && Z_TYPE_P(hasDefaultRouter_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hasDefaultRouter' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	hasDefaultRouter = (Z_TYPE_P(hasDefaultRouter_param) == IS_TRUE);
	}


	if (hasDefaultRouter) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, vii_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(&_1$$3, SL("controller"), 1);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "/([\\w0-9\\_\\-]+)[/]{0,1}");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", &_3, 104, &_2$$3, &_1$$3);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("routes"), &_0$$3 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_0$$3);
		object_init_ex(&_0$$3, vii_mvc_router_route_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(&_4$$3, SL("controller"), 1);
		add_assoc_long_ex(&_4$$3, SL("action"), 2);
		add_assoc_long_ex(&_4$$3, SL("params"), 3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "/([\\w0-9\\_\\-]+)/([\\w0-9\\.\\_]+)(/.*)*");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", &_3, 104, &_2$$3, &_4$$3);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("routes"), &_0$$3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_Router, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattren_param = NULL, *path, path_sub, _route;
	zval pattren;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&pattren);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_route);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pattren_param, &path);

	if (unlikely(Z_TYPE_P(pattren_param) != IS_STRING && Z_TYPE_P(pattren_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattren' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattren_param) == IS_STRING)) {
		zephir_get_strval(&pattren, pattren_param);
	} else {
		ZEPHIR_INIT_VAR(&pattren);
		ZVAL_EMPTY_STRING(&pattren);
	}


	ZEPHIR_INIT_VAR(&_route);
	object_init_ex(&_route, vii_mvc_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, &_route, "__construct", NULL, 104, &pattren, path);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("routes"), &_route TSRMLS_CC);
	RETURN_CCTOR(_route);

}

PHP_METHOD(Vii_Mvc_Router, handle) {

	zend_string *_13$$12;
	zend_ulong _12$$12;
	zval _8$$7;
	zend_bool _6$$7, _9$$7, _18$$18;
	zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, __$true, __$false, v, paths, methods, matches, matchMethod, beforeMatch, pattren, _0, *_1, _24, _26, _28, _30, _32, _2$$4, _3$$3, _4$$8, _7$$7, k$$12, params$$12, *_11$$12, _14$$14, _15$$15, _16$$16, _17$$17, _19$$19, _20$$19, _21$$19, _22$$19, _23$$20, _25$$21, _27$$22, _29$$23, _31$$24, _33$$25;
	zval url;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&url);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&matchMethod);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&pattren);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&k$$12);
	ZVAL_UNDEF(&params$$12);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_27$$22);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_8$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(&url, url_param);
	} else {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_EMPTY_STRING(&url);
	}


	ZEPHIR_INIT_VAR(&methods);
	ZVAL_NULL(&methods);
	zephir_read_property(&_0, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "vii/mvc/router.zep", 124);
	ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _1);
		ZEPHIR_INIT_NVAR(&matches);
		ZVAL_NULL(&matches);
		ZEPHIR_CALL_METHOD(&pattren, &v, "getcompiledpattern", NULL, 0);
		zephir_check_call_status();
		if (zephir_memnstr_str(&pattren, SL("^"), "vii/mvc/router.zep", 66)) {
			ZEPHIR_INIT_NVAR(&_2$$4);
			zephir_preg_match(&_2$$4, &pattren, &url, &matches, 0, 0 , 0  TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_wasMatched"), &_2$$4);
		} else {
			if (ZEPHIR_IS_EQUAL(&pattren, &url)) {
				zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("_wasMatched"), &__$false);
			}
		}
		zephir_read_property(&_3$$3, this_ptr, SL("_wasMatched"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_3$$3))) {
			continue;
		} else {
			ZEPHIR_CALL_METHOD(&matchMethod, &v, "getmatch", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&methods, &v, "getmethods", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&methods) != IS_NULL) {
				ZEPHIR_CALL_CE_STATIC(&_4$$8, vii_helper_ce, "gethttpmethod", &_5, 0);
				zephir_check_call_status();
				if (!(zephir_fast_in_array(&_4$$8, &methods TSRMLS_CC))) {
					continue;
				}
			}
			ZEPHIR_CALL_METHOD(&beforeMatch, &v, "getbeforematch", NULL, 0);
			zephir_check_call_status();
			_6$$7 = zephir_is_callable(&beforeMatch TSRMLS_CC);
			if (_6$$7) {
				ZEPHIR_INIT_NVAR(&_7$$7);
				ZEPHIR_INIT_NVAR(&_8$$7);
				zephir_create_array(&_8$$7, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(&_8$$7, &url);
				zephir_array_fast_append(&_8$$7, this_ptr);
				ZEPHIR_CALL_USER_FUNC_ARRAY(_7$$7, &beforeMatch, &_8$$7);
				zephir_check_call_status();
				_6$$7 = !zephir_is_true(&_7$$7);
			}
			if (_6$$7) {
				continue;
			}
			_9$$7 = Z_TYPE_P(&matchMethod) != IS_NULL;
			if (_9$$7) {
				_9$$7 = zephir_is_callable(&matchMethod TSRMLS_CC);
			}
			if (_9$$7) {
				ZEPHIR_CALL_FUNCTION(NULL, "call_user_func_array", &_10, 105, &matchMethod);
				zephir_check_call_status();
			}
			zephir_update_property_zval(this_ptr, SL("matchedRoute"), &v);
			if (!(ZEPHIR_IS_EMPTY(&matches))) {
				ZEPHIR_CALL_METHOD(&paths, &v, "getpaths", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&paths, 0, "vii/mvc/router.zep", 119);
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _12$$12, _13$$12, _11$$12)
				{
					ZEPHIR_INIT_NVAR(&k$$12);
					if (_13$$12 != NULL) { 
						ZVAL_STR_COPY(&k$$12, _13$$12);
					} else {
						ZVAL_LONG(&k$$12, _12$$12);
					}
					ZEPHIR_INIT_NVAR(&params$$12);
					ZVAL_COPY(&params$$12, _11$$12);
					do {
						if (ZEPHIR_IS_STRING(&k$$12, "controller")) {
							ZEPHIR_INIT_LNVAR(_14$$14);
							if (zephir_is_numeric(&params$$12)) {
								ZEPHIR_OBS_NVAR(&_14$$14);
								zephir_array_fetch(&_14$$14, &matches, &params$$12, PH_NOISY, "vii/mvc/router.zep", 99 TSRMLS_CC);
							} else {
								ZEPHIR_CPY_WRT(&_14$$14, &params$$12);
							}
							zephir_update_property_zval(this_ptr, SL("controllerName"), &_14$$14);
							break;
						}
						if (ZEPHIR_IS_STRING(&k$$12, "action")) {
							ZEPHIR_INIT_LNVAR(_15$$15);
							if (zephir_is_numeric(&params$$12)) {
								ZEPHIR_OBS_NVAR(&_15$$15);
								zephir_array_fetch(&_15$$15, &matches, &params$$12, PH_NOISY, "vii/mvc/router.zep", 102 TSRMLS_CC);
							} else {
								ZEPHIR_CPY_WRT(&_15$$15, &params$$12);
							}
							zephir_update_property_zval(this_ptr, SL("actionName"), &_15$$15);
							break;
						}
						if (ZEPHIR_IS_STRING(&k$$12, "module")) {
							ZEPHIR_INIT_LNVAR(_16$$16);
							if (zephir_is_numeric(&params$$12)) {
								ZEPHIR_OBS_NVAR(&_16$$16);
								zephir_array_fetch(&_16$$16, &matches, &params$$12, PH_NOISY, "vii/mvc/router.zep", 105 TSRMLS_CC);
							} else {
								ZEPHIR_CPY_WRT(&_16$$16, &params$$12);
							}
							zephir_update_property_zval(this_ptr, SL("moduleName"), &_16$$16);
							break;
						}
						if (ZEPHIR_IS_STRING(&k$$12, "namespace")) {
							ZEPHIR_INIT_LNVAR(_17$$17);
							if (zephir_is_numeric(&params$$12)) {
								ZEPHIR_OBS_NVAR(&_17$$17);
								zephir_array_fetch(&_17$$17, &matches, &params$$12, PH_NOISY, "vii/mvc/router.zep", 108 TSRMLS_CC);
							} else {
								ZEPHIR_CPY_WRT(&_17$$17, &params$$12);
							}
							zephir_update_property_zval(this_ptr, SL("namespaceName"), &_17$$17);
							break;
						}
						if (ZEPHIR_IS_STRING(&k$$12, "params")) {
							_18$$18 = zephir_is_numeric(&params$$12);
							if (_18$$18) {
								_18$$18 = zephir_array_isset(&matches, &params$$12);
							}
							if (_18$$18) {
								ZEPHIR_INIT_NVAR(&_19$$19);
								ZEPHIR_INIT_NVAR(&_20$$19);
								zephir_array_fetch(&_21$$19, &matches, &params$$12, PH_NOISY | PH_READONLY, "vii/mvc/router.zep", 112 TSRMLS_CC);
								ZEPHIR_INIT_NVAR(&_22$$19);
								ZVAL_STRING(&_22$$19, "/");
								zephir_fast_trim(&_20$$19, &_21$$19, &_22$$19, ZEPHIR_TRIM_BOTH TSRMLS_CC);
								zephir_fast_explode_str(&_19$$19, SL("/"), &_20$$19, LONG_MAX TSRMLS_CC);
								zephir_update_property_zval(this_ptr, SL("_params"), &_19$$19);
							} else {
								ZEPHIR_INIT_NVAR(&_23$$20);
								array_init(&_23$$20);
								zephir_update_property_zval(this_ptr, SL("_params"), &_23$$20);
							}
							break;
						}
					} while(0);

				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&params$$12);
				ZEPHIR_INIT_NVAR(&k$$12);
			}
			break;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	zephir_read_property(&_24, this_ptr, SL("namespaceName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_24))) {
		zephir_read_property(&_25$$21, this_ptr, SL("defaultNamespaceName"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("namespaceName"), &_25$$21);
	}
	zephir_read_property(&_26, this_ptr, SL("moduleName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_26))) {
		zephir_read_property(&_27$$22, this_ptr, SL("defaultModuleName"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("moduleName"), &_27$$22);
	}
	zephir_read_property(&_28, this_ptr, SL("controllerName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_28))) {
		zephir_read_property(&_29$$23, this_ptr, SL("defaultControllerName"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("controllerName"), &_29$$23);
	}
	zephir_read_property(&_30, this_ptr, SL("actionName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_30))) {
		zephir_read_property(&_31$$24, this_ptr, SL("defaultActionName"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("actionName"), &_31$$24);
	}
	zephir_read_property(&_32, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_32))) {
		ZEPHIR_INIT_VAR(&_33$$25);
		array_init(&_33$$25);
		zephir_update_property_zval(this_ptr, SL("_params"), &_33$$25);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_Router, addGet) {

	zval _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattren_param = NULL, *path, path_sub, _0, _2;
	zval pattren;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&pattren);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pattren_param, &path);

	if (unlikely(Z_TYPE_P(pattren_param) != IS_STRING && Z_TYPE_P(pattren_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattren' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattren_param) == IS_STRING)) {
		zephir_get_strval(&pattren, pattren_param);
	} else {
		ZEPHIR_INIT_VAR(&pattren);
		ZVAL_EMPTY_STRING(&pattren);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "add", NULL, 0, &pattren, path);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "get");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_CALL_METHOD(NULL, &_0, "via", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_Router, addPost) {

	zval _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattren_param = NULL, *path, path_sub, _0, _2;
	zval pattren;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&pattren);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pattren_param, &path);

	if (unlikely(Z_TYPE_P(pattren_param) != IS_STRING && Z_TYPE_P(pattren_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattren' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattren_param) == IS_STRING)) {
		zephir_get_strval(&pattren, pattren_param);
	} else {
		ZEPHIR_INIT_VAR(&pattren);
		ZVAL_EMPTY_STRING(&pattren);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "add", NULL, 0, &pattren, path);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "post");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_CALL_METHOD(NULL, &_0, "via", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_Router, setDefaultModule) {

	zval *moduleName_param = NULL;
	zval moduleName;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&moduleName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(&moduleName, moduleName_param);


	zephir_update_property_zval(this_ptr, SL("defaultModuleName"), &moduleName);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_Router, getDefaultModule) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "defaultModuleName");

}

PHP_METHOD(Vii_Mvc_Router, setDefaultNamespace) {

	zval *namespaceName_param = NULL;
	zval namespaceName;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&namespaceName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	zephir_get_strval(&namespaceName, namespaceName_param);


	zephir_update_property_zval(this_ptr, SL("defaultNamespaceName"), &namespaceName);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_Router, setDefaultController) {

	zval *controllerName_param = NULL;
	zval controllerName;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&controllerName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerName_param);

	zephir_get_strval(&controllerName, controllerName_param);


	zephir_update_property_zval(this_ptr, SL("defaultControllerName"), &controllerName);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_Router, setDefaultAction) {

	zval *actionName_param = NULL;
	zval actionName;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&actionName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	zephir_get_strval(&actionName, actionName_param);


	zephir_update_property_zval(this_ptr, SL("defaultActionName"), &actionName);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_Router, getModuleName) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "moduleName");

}

PHP_METHOD(Vii_Mvc_Router, getNamespaceName) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "namespaceName");

}

PHP_METHOD(Vii_Mvc_Router, getControllerName) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "controllerName");

}

PHP_METHOD(Vii_Mvc_Router, getActionName) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "actionName");

}

PHP_METHOD(Vii_Mvc_Router, getParams) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "_params");

}

PHP_METHOD(Vii_Mvc_Router, wasMatched) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "_wasMatched");

}

PHP_METHOD(Vii_Mvc_Router, getRoutes) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "routes");

}

PHP_METHOD(Vii_Mvc_Router, getMatchedRoute) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "matchedRoute");

}

PHP_METHOD(Vii_Mvc_Router, setNotFound) {

	zval *callback, callback_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&callback_sub);

	zephir_fetch_params(0, 1, 0, &callback);



	zephir_update_property_zval(this_ptr, SL("_notFound"), callback);

}

PHP_METHOD(Vii_Mvc_Router, getNotFound) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "_notFound");

}

PHP_METHOD(Vii_Mvc_Router, getMatches) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 5, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("namespaceName"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("namespace"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("moduleName"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("module"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("controllerName"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("controller"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("actionName"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("action"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getparams", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("params"), &_1, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

static zend_object *zephir_init_properties_Vii_Mvc_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_params"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("routes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

