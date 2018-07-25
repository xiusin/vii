
extern zend_class_entry *vii_eventmanager_ce;

ZEPHIR_INIT_CLASS(Vii_EventManager);

PHP_METHOD(Vii_EventManager, __construct);
PHP_METHOD(Vii_EventManager, setPriorityState);
PHP_METHOD(Vii_EventManager, collectResponses);
PHP_METHOD(Vii_EventManager, attach);
PHP_METHOD(Vii_EventManager, detachAll);
PHP_METHOD(Vii_EventManager, iscollect);
PHP_METHOD(Vii_EventManager, getResponses);
PHP_METHOD(Vii_EventManager, hasListener);
PHP_METHOD(Vii_EventManager, getListener);
PHP_METHOD(Vii_EventManager, fire);
zend_object *zephir_init_properties_Vii_EventManager(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_eventmanager___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, ioc, Vii\\Interfaces\\IocInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_eventmanager_setprioritystate, 0, 0, 1)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_eventmanager_collectresponses, 0, 0, 1)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_eventmanager_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_eventmanager_detachall, 0, 0, 0)
	ZEND_ARG_INFO(0, eventType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_eventmanager_haslistener, 0, 0, 1)
	ZEND_ARG_INFO(0, eventType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_eventmanager_getlistener, 0, 0, 1)
	ZEND_ARG_INFO(0, eventType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_eventmanager_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_eventmanager_method_entry) {
	PHP_ME(Vii_EventManager, __construct, arginfo_vii_eventmanager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_EventManager, setPriorityState, arginfo_vii_eventmanager_setprioritystate, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_EventManager, collectResponses, arginfo_vii_eventmanager_collectresponses, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_EventManager, attach, arginfo_vii_eventmanager_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_EventManager, detachAll, arginfo_vii_eventmanager_detachall, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_EventManager, iscollect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_EventManager, getResponses, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_EventManager, hasListener, arginfo_vii_eventmanager_haslistener, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_EventManager, getListener, arginfo_vii_eventmanager_getlistener, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_EventManager, fire, arginfo_vii_eventmanager_fire, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
