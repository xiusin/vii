
extern zend_class_entry *vii_service_ce;

ZEPHIR_INIT_CLASS(Vii_Service);

PHP_METHOD(Vii_Service, __construct);
PHP_METHOD(Vii_Service, set);
PHP_METHOD(Vii_Service, get);
PHP_METHOD(Vii_Service, has);
PHP_METHOD(Vii_Service, setDefinition);
PHP_METHOD(Vii_Service, del);
PHP_METHOD(Vii_Service, getDefault);
PHP_METHOD(Vii_Service, __get);
PHP_METHOD(Vii_Service, __unset);
PHP_METHOD(Vii_Service, offsetExists);
PHP_METHOD(Vii_Service, offsetGet);
PHP_METHOD(Vii_Service, offsetSet);
PHP_METHOD(Vii_Service, offsetUnset);
PHP_METHOD(Vii_Service, setService);
PHP_METHOD(Vii_Service, getService);
PHP_METHOD(Vii_Service, count);
zend_object_value zephir_init_properties_Vii_Service(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service_setdefinition, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service_del, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_service_setservice, 0, 0, 1)
	ZEND_ARG_INFO(0, _service)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_service_method_entry) {
	PHP_ME(Vii_Service, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Service, set, arginfo_vii_service_set, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, get, arginfo_vii_service_get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, has, arginfo_vii_service_has, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, setDefinition, arginfo_vii_service_setdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, del, arginfo_vii_service_del, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, getDefault, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vii_Service, __get, arginfo_vii_service___get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, __unset, arginfo_vii_service___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, offsetExists, arginfo_vii_service_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, offsetGet, arginfo_vii_service_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, offsetSet, arginfo_vii_service_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, offsetUnset, arginfo_vii_service_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, setService, arginfo_vii_service_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, getService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Service, count, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
