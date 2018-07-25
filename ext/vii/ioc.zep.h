
extern zend_class_entry *vii_ioc_ce;

ZEPHIR_INIT_CLASS(Vii_Ioc);

PHP_METHOD(Vii_Ioc, __construct);
PHP_METHOD(Vii_Ioc, set);
PHP_METHOD(Vii_Ioc, get);
PHP_METHOD(Vii_Ioc, has);
PHP_METHOD(Vii_Ioc, setDefinition);
PHP_METHOD(Vii_Ioc, del);
PHP_METHOD(Vii_Ioc, getDefault);
PHP_METHOD(Vii_Ioc, __get);
PHP_METHOD(Vii_Ioc, __unset);
PHP_METHOD(Vii_Ioc, offsetExists);
PHP_METHOD(Vii_Ioc, offsetGet);
PHP_METHOD(Vii_Ioc, offsetSet);
PHP_METHOD(Vii_Ioc, offsetUnset);
PHP_METHOD(Vii_Ioc, setIoc);
PHP_METHOD(Vii_Ioc, getIoc);
PHP_METHOD(Vii_Ioc, count);
static zend_object *zephir_init_properties_Vii_Ioc(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc_setdefinition, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc_del, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_ioc_setioc, 0, 0, 1)
	ZEND_ARG_INFO(0, _ioc)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_ioc_method_entry) {
	PHP_ME(Vii_Ioc, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Ioc, set, arginfo_vii_ioc_set, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, get, arginfo_vii_ioc_get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, has, arginfo_vii_ioc_has, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, setDefinition, arginfo_vii_ioc_setdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, del, arginfo_vii_ioc_del, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, getDefault, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vii_Ioc, __get, arginfo_vii_ioc___get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, __unset, arginfo_vii_ioc___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, offsetExists, arginfo_vii_ioc_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, offsetGet, arginfo_vii_ioc_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, offsetSet, arginfo_vii_ioc_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, offsetUnset, arginfo_vii_ioc_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, setIoc, arginfo_vii_ioc_setioc, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, getIoc, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Ioc, count, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
