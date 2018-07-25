
extern zend_class_entry *vii_interfaces_eventmanagerinterface_ce;

ZEPHIR_INIT_CLASS(Vii_Interfaces_EventManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_eventmanagerinterface___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, ioc, Vii\\Interfaces\\IocInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_eventmanagerinterface_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_eventmanagerinterface_detachall, 0, 0, 0)
	ZEND_ARG_INFO(0, eventType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_eventmanagerinterface_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_eventmanagerinterface_getlistener, 0, 0, 1)
	ZEND_ARG_INFO(0, eventType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_interfaces_eventmanagerinterface_haslistener, 0, 0, 1)
	ZEND_ARG_INFO(0, eventType)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_interfaces_eventmanagerinterface_method_entry) {
	PHP_ABSTRACT_ME(Vii_Interfaces_EventManagerInterface, __construct, arginfo_vii_interfaces_eventmanagerinterface___construct)
	PHP_ABSTRACT_ME(Vii_Interfaces_EventManagerInterface, attach, arginfo_vii_interfaces_eventmanagerinterface_attach)
	PHP_ABSTRACT_ME(Vii_Interfaces_EventManagerInterface, detachAll, arginfo_vii_interfaces_eventmanagerinterface_detachall)
	PHP_ABSTRACT_ME(Vii_Interfaces_EventManagerInterface, fire, arginfo_vii_interfaces_eventmanagerinterface_fire)
	PHP_ABSTRACT_ME(Vii_Interfaces_EventManagerInterface, getListener, arginfo_vii_interfaces_eventmanagerinterface_getlistener)
	PHP_ABSTRACT_ME(Vii_Interfaces_EventManagerInterface, hasListener, arginfo_vii_interfaces_eventmanagerinterface_haslistener)
	PHP_FE_END
};
