
extern zend_class_entry *vii_event_ce;

ZEPHIR_INIT_CLASS(Vii_Event);

PHP_METHOD(Vii_Event, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_event___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, handlerFun)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_event_method_entry) {
	PHP_ME(Vii_Event, __construct, arginfo_vii_event___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
