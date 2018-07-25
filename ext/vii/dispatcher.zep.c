
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/require.h"


/**
 * 路由分发类库
 */
ZEPHIR_INIT_CLASS(Vii_Dispatcher) {

	ZEPHIR_REGISTER_CLASS(Vii, Dispatcher, vii, dispatcher, vii_dispatcher_method_entry, 0);

	zend_declare_property_null(vii_dispatcher_ce, SL("ioc"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_dispatcher_ce, SL("actionName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_dispatcher_ce, SL("controllerName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_dispatcher_ce, SL("moduleName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_dispatcher_ce, SL("namespaceName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_dispatcher_ce, SL("application"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_dispatcher_ce, SL("actionSuffix"), "Action", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_dispatcher_ce, SL("controllerSuffix"), "Controller", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_dispatcher_ce, SL("_defaultController"), "Index", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_dispatcher_ce, SL("_defaultAction"), "index", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_dispatcher_ce, SL("_defaultModule"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_dispatcher_ce, SL("_defaultNamespace"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_dispatcher_ce, SL("_controllerInstance"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(vii_dispatcher_ce TSRMLS_CC, 1, vii_interfaces_iocinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_Dispatcher, setApp) {

	zval *appname, appname_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&appname_sub);

	zephir_fetch_params(0, 1, 0, &appname);



	zephir_update_property_zval(this_ptr, SL("application"), appname);
	RETURN_THISW();

}

PHP_METHOD(Vii_Dispatcher, getApp) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "application");

}

PHP_METHOD(Vii_Dispatcher, setActionSuffix) {

	zval *actionSuffix, actionSuffix_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix_sub);

	zephir_fetch_params(0, 1, 0, &actionSuffix);



	zephir_update_property_zval(this_ptr, SL("actionSuffix"), actionSuffix);
	RETURN_THISW();

}

PHP_METHOD(Vii_Dispatcher, getActionSuffix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "actionSuffix");

}

PHP_METHOD(Vii_Dispatcher, setControllerSuffix) {

	zval *controllerSuffix, controllerSuffix_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerSuffix_sub);

	zephir_fetch_params(0, 1, 0, &controllerSuffix);



	zephir_update_property_zval(this_ptr, SL("controllerSuffix"), controllerSuffix);
	RETURN_THISW();

}

PHP_METHOD(Vii_Dispatcher, getControllerSuffix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "controllerSuffix");

}

PHP_METHOD(Vii_Dispatcher, getHandlerController) {

	zval _controller, _0, _2, _4, _6, _8, _9, _10, _11, _12, _1$$3, _3$$4, _5$$5, _7$$6, _13$$7, _14$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_controller);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("namespaceName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("_defaultNamespace"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("namespaceName"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, SL("moduleName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		zephir_read_property(&_3$$4, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("moduleName"), &_3$$4);
	}
	zephir_read_property(&_4, this_ptr, SL("controllerName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_4))) {
		zephir_read_property(&_5$$5, this_ptr, SL("_defaultController"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("controllerName"), &_5$$5);
	}
	zephir_read_property(&_6, this_ptr, SL("actionName"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_6))) {
		zephir_read_property(&_7$$6, this_ptr, SL("_defaultAction"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("actionName"), &_7$$6);
	}
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_INIT_VAR(&_9);
	zephir_read_property(&_10, this_ptr, SL("controllerName"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_strtolower(&_9, &_10);
	zephir_ucfirst(&_8, &_9);
	zephir_read_property(&_11, this_ptr, SL("controllerSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_controller);
	ZEPHIR_CONCAT_VV(&_controller, &_8, &_11);
	zephir_read_property(&_12, this_ptr, SL("namespaceName"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING(&_12, "")) {
		zephir_read_property(&_13$$7, this_ptr, SL("namespaceName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_14$$7);
		ZEPHIR_CONCAT_VSV(&_14$$7, &_13$$7, "\\Controller\\", &_controller);
		ZEPHIR_CPY_WRT(&_controller, &_14$$7);
	}
	RETURN_CCTOR(&_controller);

}

/**
 * 分发路由
 * @return string
 */
PHP_METHOD(Vii_Dispatcher, dispatch) {

	zend_bool _4, _5;
	zval router, _url, _0, _1, _2, _3, _9, _10, _6$$3, _7$$4, _8$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&_url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "router");
	ZEPHIR_CALL_METHOD(&router, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_3, &_2, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_url");
	ZEPHIR_CALL_METHOD(&_url, &_3, "get", NULL, 0, &_1);
	zephir_check_call_status();
	_4 = !zephir_is_true(&_url);
	if (!(_4)) {
		_4 = ZEPHIR_IS_STRING(&_url, "/");
	}
	_5 = _4;
	if (!(_5)) {
		_5 = Z_TYPE_P(&_url) == IS_ARRAY;
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(&_6$$3, &router, "getdefaultmodule", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("moduleName"), &_6$$3);
	} else {
		ZEPHIR_CALL_METHOD(NULL, &router, "handle", NULL, 0, &_url);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$4, &router, "wasmatched", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_7$$4))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_httpexception_ce, "没有找到指定的路由信息", "vii/dispatcher.zep", 92);
			return;
		} else {
			ZEPHIR_CALL_METHOD(&_8$$6, &router, "getmatches", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmatches", NULL, 37, &_8$$6);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmodulehandleinfo", NULL, 38);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "gethandlercontroller", NULL, 39);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "_exec", NULL, 40, &_10);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "sendcontent", NULL, 41, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Dispatcher, setModuleHandleInfo) {

	zval handleModuleInfo, className, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handleModuleInfo);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&handleModuleInfo);
	array_init(&handleModuleInfo);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getapp", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("moduleName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&handleModuleInfo, &_0, "getregistermodulebymodulename", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("moduleName"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_2))) {
		zephir_read_property(&_3$$3, this_ptr, SL("moduleName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadmodulebyname", NULL, 42, &handleModuleInfo, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&className);
		zephir_array_fetch_string(&className, &handleModuleInfo, SL("className"), PH_NOISY, "vii/dispatcher.zep", 109 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "\\");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "strrpos", NULL, 43, &className, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$3, 0);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_substr(&_4$$3, &className, 0 , zephir_get_intval(&_5$$3), 0);
		zephir_update_property_zval(this_ptr, SL("namespaceName"), &_4$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Dispatcher, setMatches) {

	zval *matches_param = NULL, _0, _1, _2, _3;
	zval matches;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches_param);

	ZEPHIR_OBS_COPY_OR_DUP(&matches, matches_param);


	zephir_array_fetch_string(&_0, &matches, SL("namespace"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 115 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("namespaceName"), &_0);
	zephir_array_fetch_string(&_1, &matches, SL("module"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 116 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("moduleName"), &_1);
	zephir_array_fetch_string(&_2, &matches, SL("controller"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 117 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("controllerName"), &_2);
	zephir_array_fetch_string(&_3, &matches, SL("action"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 118 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("actionName"), &_3);
	RETURN_THIS();

}

PHP_METHOD(Vii_Dispatcher, setIoc) {

	zval *_ioc, _ioc_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_ioc_sub);

	zephir_fetch_params(0, 1, 0, &_ioc);



	zephir_update_property_zval(this_ptr, SL("ioc"), _ioc);
	RETURN_THISW();

}

PHP_METHOD(Vii_Dispatcher, getIoc) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "ioc");

}

PHP_METHOD(Vii_Dispatcher, getParams) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "router");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getparams", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Dispatcher, _exec) {

	zval _23$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handlerClass_param = NULL, *_REQUEST, _handler, _method, actionName, parameters, parameter, _methodParameter, _0, _1, _2, _3$$3, _5$$4, _6$$4, _7$$5, _8$$5, _9$$5, _12$$5, _13$$5, _14$$5, currcls$$5, clsType$$5, _15$$5, *_16$$5, _24$$5, _10$$7, _17$$9, _18$$8, _19$$11, _20$$11, _21$$12, _22$$13;
	zval handlerClass, _4$$3, _11$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handlerClass);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_handler);
	ZVAL_UNDEF(&_method);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&_methodParameter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&currcls$$5);
	ZVAL_UNDEF(&clsType$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$5);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 1, 0, &handlerClass_param);

	if (UNEXPECTED(Z_TYPE_P(handlerClass_param) != IS_STRING && Z_TYPE_P(handlerClass_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handlerClass' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(handlerClass_param) == IS_STRING)) {
		zephir_get_strval(&handlerClass, handlerClass_param);
	} else {
		ZEPHIR_INIT_VAR(&handlerClass);
		ZVAL_EMPTY_STRING(&handlerClass);
	}


	ZEPHIR_INIT_VAR(&_methodParameter);
	array_init(&_methodParameter);
	zephir_read_property(&_0, this_ptr, SL("actionName"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("actionSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_0, &_1);
	ZEPHIR_CPY_WRT(&actionName, &_2);
	if (!(zephir_class_exists(&handlerClass, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, vii_exceptions_httpexception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, "没有找到指定的类文件:[[", &handlerClass, "]]");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 3, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "vii/dispatcher.zep", 138 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_method);
	object_init_ex(&_method, zephir_get_internal_ce(SL("reflectionmethod")));
	ZEPHIR_CALL_METHOD(NULL, &_method, "__construct", NULL, 44, &handlerClass, &actionName);
	zephir_check_call_status();
	if (!(zephir_is_true(&_method))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, vii_exceptions_httpexception_ce);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_SVSVS(&_6$$4, "没有找到指定的方法:[[", &handlerClass, "::", &actionName, "]]");
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 3, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "vii/dispatcher.zep", 142 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else {
		ZEPHIR_CALL_METHOD(&_7$$5, &_method, "ispublic", NULL, 45);
		zephir_check_call_status();
		if (!(zephir_is_true(&_7$$5))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_httpexception_ce, "方法可见性不正确 必须为public", "vii/dispatcher.zep", 146);
			return;
		}
		ZEPHIR_INIT_VAR(&_handler);
		object_init_ex(&_handler, zephir_get_internal_ce(SL("reflectionclass")));
		ZEPHIR_CALL_METHOD(NULL, &_handler, "__construct", NULL, 13, &handlerClass);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "Vii\\Mvc\\Controller");
		ZEPHIR_CALL_METHOD(&_8$$5, &_handler, "issubclassof", NULL, 46, &_9$$5);
		zephir_check_call_status();
		if (!(zephir_is_true(&_8$$5))) {
			ZEPHIR_INIT_VAR(&_10$$7);
			object_init_ex(&_10$$7, vii_exceptions_runtimeexception_ce);
			ZEPHIR_INIT_VAR(&_11$$7);
			ZEPHIR_CONCAT_VS(&_11$$7, &handlerClass, " 没有继承Vii\\Mvc\\Controller");
			ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", NULL, 3, &_11$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$7, "vii/dispatcher.zep", 150 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&_9$$5);
		array_init(&_9$$5);
		ZEPHIR_CALL_METHOD(&_12$$5, &_handler, "newinstanceargs", NULL, 14, &_9$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_controllerInstance"), &_12$$5);
		zephir_read_property(&_13$$5, this_ptr, SL("_controllerInstance"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_14$$5, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_13$$5, "setioc", NULL, 0, &_14$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&parameters, &_method, "getparameters", NULL, 47);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&currcls$$5);
		ZVAL_STRING(&currcls$$5, "");
		ZEPHIR_INIT_VAR(&clsType$$5);
		zephir_create_array(&clsType$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_15$$5);
		ZVAL_STRING(&_15$$5, "array");
		zephir_array_fast_append(&clsType$$5, &_15$$5);
		ZEPHIR_INIT_NVAR(&_15$$5);
		ZVAL_STRING(&_15$$5, "string");
		zephir_array_fast_append(&clsType$$5, &_15$$5);
		zephir_is_iterable(&parameters, 0, "vii/dispatcher.zep", 172);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parameters), _16$$5)
		{
			ZEPHIR_INIT_NVAR(&parameter);
			ZVAL_COPY(&parameter, _16$$5);
			ZEPHIR_CALL_METHOD(&currcls$$5, &parameter, "getclass", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&currcls$$5)) {
				zephir_read_property(&_17$$9, &currcls$$5, SL("name"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_fast_in_array(&clsType$$5, &_17$$9 TSRMLS_CC))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_runtimeexception_ce, "操作可接收的参数类型只能为数组和字符串", "vii/dispatcher.zep", 160);
					return;
				}
			}
			zephir_read_property(&_18$$8, &parameter, SL("name"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(_REQUEST, &_18$$8)) {
				ZEPHIR_OBS_NVAR(&_20$$11);
				zephir_read_property(&_20$$11, &parameter, SL("name"), PH_NOISY_CC);
				zephir_array_fetch(&_19$$11, _REQUEST, &_20$$11, PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 164 TSRMLS_CC);
				zephir_array_append(&_methodParameter, &_19$$11, PH_SEPARATE, "vii/dispatcher.zep", 164);
			} else {
				ZEPHIR_CALL_METHOD(&_21$$12, &parameter, "isoptional", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_21$$12)) {
					ZEPHIR_CALL_METHOD(&_22$$13, &parameter, "getdefaultvalue", NULL, 0);
					zephir_check_call_status();
					zephir_array_append(&_methodParameter, &_22$$13, PH_SEPARATE, "vii/dispatcher.zep", 167);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&parameter);
		if (zephir_fast_count_int(&_methodParameter TSRMLS_CC) != zephir_fast_count_int(&parameters TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_runtimeexception_ce, "操作的参数个数不符", "vii/dispatcher.zep", 173);
			return;
		}
		ZEPHIR_INIT_VAR(&_23$$5);
		zephir_create_array(&_23$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_24$$5);
		zephir_read_property(&_24$$5, this_ptr, SL("_controllerInstance"), PH_NOISY_CC);
		zephir_array_fast_append(&_23$$5, &_24$$5);
		zephir_array_fast_append(&_23$$5, &actionName);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_23$$5, &_methodParameter);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Dispatcher, sendContent) {

	zend_bool _2, _4, condition1 = 0, condition2 = 0, condition3 = 0, _8$$7, _9$$7, _10$$7, _11$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, __$null, beforeBuffer, response, hasContent, hasHeader, _0, _1, _3, _5, _7, _6$$4, _12$$9, _13$$9, _14$$9, _15$$9, _16$$9, _17$$12, _18$$12, _19$$12, _20$$12, _21$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&beforeBuffer);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&hasContent);
	ZVAL_UNDEF(&hasHeader);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &content);

	if (!content) {
		content = &content_sub;
		ZEPHIR_CPY_WRT(content, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(content);
	}


	zephir_read_property(&_0, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "response");
	ZEPHIR_CALL_METHOD(&response, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_FALSE_IDENTICAL(content);
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3, &response, "getcontent", NULL, 0);
		zephir_check_call_status();
		_2 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "");
	}
	_4 = _2;
	if (_4) {
		ZEPHIR_CALL_METHOD(&_5, &response, "issend", NULL, 0);
		zephir_check_call_status();
		_4 = !zephir_is_true(&_5);
	}
	if (_4) {
		ZEPHIR_RETURN_CALL_METHOD(&response, "send", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&beforeBuffer, "ob_get_clean", NULL, 48);
	zephir_check_call_status();
	if (zephir_is_true(&beforeBuffer)) {
		ZEPHIR_CALL_METHOD(&_6$$4, &response, "getcontent", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_6$$4))) {
			ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &beforeBuffer);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &response, "appendcontent", NULL, 0, &beforeBuffer);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&_7, &response, "issend", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_7))) {
		ZEPHIR_CALL_METHOD(&hasContent, &response, "getcontent", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&hasHeader, &response, "hasheader", NULL, 0);
		zephir_check_call_status();
		_8$$7 = !zephir_is_true(&hasContent);
		if (_8$$7) {
			_8$$7 = !zephir_is_true(&hasHeader);
		}
		condition1 = _8$$7;
		_9$$7 = zephir_is_true(&hasContent);
		if (_9$$7) {
			_9$$7 = !zephir_is_true(&hasHeader);
		}
		condition2 = _9$$7;
		_10$$7 = !zephir_is_true(&hasContent);
		if (_10$$7) {
			_10$$7 = zephir_is_true(&hasHeader);
		}
		condition3 = _10$$7;
		_11$$7 = condition2;
		if (!(_11$$7)) {
			_11$$7 = condition3;
		}
		if (condition1) {
			if (Z_TYPE_P(content) == IS_NULL) {
				zephir_read_property(&_12$$9, this_ptr, SL("_controllerInstance"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_13$$9, this_ptr, SL("moduleName"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_14$$9, this_ptr, SL("controllerName"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_15$$9, this_ptr, SL("actionName"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(content, &_12$$9, "display", NULL, 0, &_13$$9, &_14$$9, &_15$$9);
				zephir_check_call_status();
				ZVAL_LONG(&_16$$9, 200);
				ZEPHIR_CALL_METHOD(NULL, &response, "setstatuscode", NULL, 0, &_16$$9);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, content);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, content);
				zephir_check_call_status();
			}
		} else if (_11$$7) {
			if (Z_TYPE_P(content) == IS_NULL) {
				zephir_read_property(&_17$$12, this_ptr, SL("_controllerInstance"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_18$$12, this_ptr, SL("moduleName"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_19$$12, this_ptr, SL("controllerName"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_20$$12, this_ptr, SL("actionName"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(content, &_17$$12, "display", NULL, 0, &_18$$12, &_19$$12, &_20$$12);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &response, "appendcontent", NULL, 0, content);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &response, "appendcontent", NULL, 0, content);
				zephir_check_call_status();
			}
			ZVAL_LONG(&_21$$11, 200);
			ZEPHIR_CALL_METHOD(NULL, &response, "setstatuscode", NULL, 0, &_21$$11);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 49);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&response, "send", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_RETURN_CALL_METHOD(&response, "getcontent", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}

}

PHP_METHOD(Vii_Dispatcher, loadModuleByName) {

	zend_class_entry *_19;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name, _12$$5;
	zval *module_param = NULL, *name_param = NULL, moduleClass, _1, _2, _3, _4, _5, _6, _10, _13, _14, className, _18, _22, _7$$4, _8$$4, _9$$4, _11$$5, _15$$6, _16$$6, _17$$6, _20$$7, _21$$7;
	zval module;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&moduleClass);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &module_param, &name_param);

	zephir_get_arrval(&module, module_param);
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


	_0 = !(zephir_array_isset_string(&module, SL("className")));
	if (!(_0)) {
		_0 = !(zephir_array_isset_string(&module, SL("path")));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_runtimeexception_ce, "registerModule参数结构错误：['模块名'=>['className'=>'模块名',‘path’=>'要载入的文件名']]", "vii/dispatcher.zep", 231);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "alias");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, &module, SL("path"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 233 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, &_2, "resolve", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&module, SL("path"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_6, &module, SL("path"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 234 TSRMLS_CC);
	if (!((zephir_file_exists(&_6 TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_7$$4);
		object_init_ex(&_7$$4, vii_exceptions_runtimeexception_ce);
		zephir_array_fetch_string(&_8$$4, &module, SL("path"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 235 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SVSVS(&_9$$4, "registerModule错误：", &name, "对应的文件[[", &_8$$4, "]]不存在");
		ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", NULL, 3, &_9$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$4, "vii/dispatcher.zep", 235 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_10, &module, SL("className"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 237 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(&_10)) {
		ZEPHIR_INIT_VAR(&_11$$5);
		object_init_ex(&_11$$5, vii_exceptions_runtimeexception_ce);
		ZEPHIR_INIT_VAR(&_12$$5);
		ZEPHIR_CONCAT_SVS(&_12$$5, "registerModule错误：", &name, "对应的className不能为空");
		ZEPHIR_CALL_METHOD(NULL, &_11$$5, "__construct", NULL, 3, &_12$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$5, "vii/dispatcher.zep", 238 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_13, &module, SL("path"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 241 TSRMLS_CC);
	if (zephir_require_zval(&_13 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_array_fetch_string(&_14, &module, SL("className"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 243 TSRMLS_CC);
	if (!(zephir_class_exists(&_14, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_15$$6);
		object_init_ex(&_15$$6, vii_exceptions_runtimeexception_ce);
		zephir_array_fetch_string(&_16$$6, &module, SL("className"), PH_NOISY | PH_READONLY, "vii/dispatcher.zep", 244 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_17$$6);
		ZEPHIR_CONCAT_SVS(&_17$$6, "[[", &_16$$6, "]] 不存在");
		ZEPHIR_CALL_METHOD(NULL, &_15$$6, "__construct", NULL, 3, &_17$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_15$$6, "vii/dispatcher.zep", 244 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&className);
	zephir_array_fetch_string(&className, &module, SL("className"), PH_NOISY, "vii/dispatcher.zep", 246 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&moduleClass);
	zephir_fetch_safe_class(&_18, &className);
	_19 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_18), Z_STRLEN_P(&_18), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&moduleClass, _19);
	if (zephir_has_constructor(&moduleClass TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &moduleClass, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!(zephir_instance_of_ev(&moduleClass, vii_interfaces_moduleinterface_ce TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_20$$7);
		object_init_ex(&_20$$7, vii_exceptions_runtimeexception_ce);
		ZEPHIR_INIT_VAR(&_21$$7);
		ZEPHIR_CONCAT_SVS(&_21$$7, "[[", &className, "]] 必须继承Vii\\Interfaces\\ModuleInterface");
		ZEPHIR_CALL_METHOD(NULL, &_20$$7, "__construct", NULL, 3, &_21$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_20$$7, "vii/dispatcher.zep", 249 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, &moduleClass, "registerautoloader", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_22, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &moduleClass, "registerservices", NULL, 0, &_22);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

