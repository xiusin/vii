
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "ext/spl/spl_heap.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Vii_EventManager) {

	ZEPHIR_REGISTER_CLASS(Vii, EventManager, vii, eventmanager, vii_eventmanager_method_entry, 0);

	zend_declare_property_null(vii_eventmanager_ce, SL("_ioc"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_eventmanager_ce, SL("_events"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(vii_eventmanager_ce, SL("_collect"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(vii_eventmanager_ce, SL("_priority"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_eventmanager_ce, SL("_responses"), ZEND_ACC_PROTECTED TSRMLS_CC);

	vii_eventmanager_ce->create_object = zephir_init_properties_Vii_EventManager;

	zend_class_implements(vii_eventmanager_ce TSRMLS_CC, 1, vii_interfaces_eventmanagerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Vii_EventManager, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *ioc = NULL, ioc_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &ioc);

	if (!ioc) {
		ioc = &ioc_sub;
		ioc = &__$null;
	}


	if (!(zephir_is_true(ioc))) {
		ZEPHIR_CALL_CE_STATIC(&_0$$3, vii_ioc_ce, "getdefault", &_1, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_ioc"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("_ioc"), ioc);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置是否启用优先级
 */
PHP_METHOD(Vii_EventManager, setPriorityState) {

	zval *priority_param = NULL, __$true, __$false;
	zend_bool priority;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &priority_param);

	if (UNEXPECTED(Z_TYPE_P(priority_param) != IS_TRUE && Z_TYPE_P(priority_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'priority' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	priority = (Z_TYPE_P(priority_param) == IS_TRUE);


	if (priority) {
		zephir_update_property_zval(this_ptr, SL("_priority"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_priority"), &__$false);
	}
	RETURN_THISW();

}

/**
 * 是否收集每个事件的返回值
 */
PHP_METHOD(Vii_EventManager, collectResponses) {

	zval *collect_param = NULL, __$true, __$false;
	zend_bool collect;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &collect_param);

	if (UNEXPECTED(Z_TYPE_P(collect_param) != IS_TRUE && Z_TYPE_P(collect_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'collect' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	collect = (Z_TYPE_P(collect_param) == IS_TRUE);


	if (collect) {
		zephir_update_property_zval(this_ptr, SL("_collect"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_collect"), &__$false);
	}
	RETURN_THISW();

}

/**
 * 附上一个侦听者
 * @param eventType string 事件类型 可以多个使用同一个
 * @param handler object 事件处理对象 闭包函数
 * @param priority int 处理优先级
 */
PHP_METHOD(Vii_EventManager, attach) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, *handler, handler_sub, *priority_param = NULL, priorityQueue, _0, _1$$3, _2$$3, _4$$4, _5$$4;
	zval eventType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&priorityQueue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &eventType_param, &handler, &priority_param);

	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(&eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(&eventType);
		ZVAL_EMPTY_STRING(&eventType);
	}
	if (!priority_param) {
		priority = 100;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_priority"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&priorityQueue);
	if (zephir_is_true(&_0)) {
		object_init_ex(&priorityQueue, spl_ce_SplPriorityQueue);
		if (zephir_has_constructor(&priorityQueue TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZVAL_LONG(&_1$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "setextractflags", NULL, 61, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, vii_event_ce);
		ZVAL_LONG(&_1$$3, priority);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", &_3, 62, handler, &_1$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_1$$3, priority);
		ZEPHIR_CALL_METHOD(NULL, &priorityQueue, "insert", NULL, 63, &_2$$3, &_1$$3);
		zephir_check_call_status();
	} else {
		array_init(&priorityQueue);
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, vii_event_ce);
		ZVAL_LONG(&_5$$4, priority);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", &_3, 62, handler, &_5$$4);
		zephir_check_call_status();
		zephir_array_append(&priorityQueue, &_4$$4, PH_SEPARATE, "vii/eventmanager.zep", 60);
		zephir_update_property_array(this_ptr, SL("_events"), &eventType, &priorityQueue TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 注销eventType下的所有事件
 */
PHP_METHOD(Vii_EventManager, detachAll) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, _0$$3, _1$$4, _4$$4, _2$$5;
	zval eventType, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &eventType_param);

	if (!eventType_param) {
		ZEPHIR_INIT_VAR(&eventType);
		ZVAL_STRING(&eventType, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(&eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(&eventType);
		ZVAL_EMPTY_STRING(&eventType);
	}
	}


	if (!(!(Z_TYPE_P(&eventType) == IS_UNDEF) && Z_STRLEN_P(&eventType))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_zval(this_ptr, SL("_events"), &_0$$3);
	} else {
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "haslistener", NULL, 0, &eventType);
		zephir_check_call_status();
		if (!(zephir_is_true(&_1$$4))) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, vii_exceptions_eventexception_ce);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZEPHIR_CONCAT_SVS(&_3$$5, "事件类型:", &eventType, "没有被注册");
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 3, &_3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "vii/eventmanager.zep", 73 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_4$$4, this_ptr, SL("_events"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_4$$4, &eventType, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回收集事件信息的状态
 */
PHP_METHOD(Vii_EventManager, iscollect) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_collect");

}

/**
 * 返回事件收集的信息
 */
PHP_METHOD(Vii_EventManager, getResponses) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_responses");

}

/**
 * 检查监听器是否存在
 * @param eventType string 事件类型
 */
PHP_METHOD(Vii_EventManager, hasListener) {

	zval *eventType_param = NULL, _0;
	zval eventType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventType_param);

	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(&eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(&eventType);
		ZVAL_EMPTY_STRING(&eventType);
	}


	zephir_read_property(&_0, this_ptr, SL("_events"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &eventType));

}

/**
 * 获取监听事件
 * @param eventType string 事件类型
 */
PHP_METHOD(Vii_EventManager, getListener) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventType_param = NULL, _0, _1$$4, _2$$4;
	zval eventType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventType_param);

	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(&eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(&eventType);
		ZVAL_EMPTY_STRING(&eventType);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "haslistener", NULL, 0, &eventType);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		array_init(return_value);
		RETURN_MM();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("_events"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$4, &_1$$4, &eventType, PH_NOISY | PH_READONLY, "vii/eventmanager.zep", 109 TSRMLS_CC);
		RETURN_CTOR(&_2$$4);
	}

}

/**
 * 触发监听
 * @param eventType string 事件类型
 * @param source
 */
PHP_METHOD(Vii_EventManager, fire) {

	zend_bool cancelable;
	zval *eventType_param = NULL, *source, source_sub, *data = NULL, data_sub, *cancelable_param = NULL, __$null;
	zval eventType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventType);
	ZVAL_UNDEF(&source_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &eventType_param, &source, &data, &cancelable_param);

	if (UNEXPECTED(Z_TYPE_P(eventType_param) != IS_STRING && Z_TYPE_P(eventType_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventType' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventType_param) == IS_STRING)) {
		zephir_get_strval(&eventType, eventType_param);
	} else {
		ZEPHIR_INIT_VAR(&eventType);
		ZVAL_EMPTY_STRING(&eventType);
	}
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancelable_param) {
		cancelable = 1;
	} else {
		cancelable = zephir_get_boolval(cancelable_param);
	}



}

zend_object *zephir_init_properties_Vii_EventManager(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_events"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_events"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

