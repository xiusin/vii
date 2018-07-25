
extern zend_class_entry *vii_router_ce;

ZEPHIR_INIT_CLASS(Vii_Router);

PHP_METHOD(Vii_Router, setService);
PHP_METHOD(Vii_Router, getService);
PHP_METHOD(Vii_Router, __construct);
PHP_METHOD(Vii_Router, add);
PHP_METHOD(Vii_Router, handle);
PHP_METHOD(Vii_Router, addGet);
PHP_METHOD(Vii_Router, addPost);
zend_object_value zephir_init_properties_Vii_Router(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_router_setservice, 0, 0, 1)
	ZEND_ARG_INFO(0, _service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_router___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, hasDefaultRouter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_router_add, 0, 0, 2)
	ZEND_ARG_INFO(0, pattren)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_router_addget, 0, 0, 2)
	ZEND_ARG_INFO(0, pattren)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_router_addpost, 0, 0, 2)
	ZEND_ARG_INFO(0, pattren)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_router_method_entry) {
	PHP_ME(Vii_Router, setService, arginfo_vii_router_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Router, getService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Router, __construct, arginfo_vii_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Router, add, arginfo_vii_router_add, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Router, handle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Router, addGet, arginfo_vii_router_addget, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Router, addPost, arginfo_vii_router_addpost, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
