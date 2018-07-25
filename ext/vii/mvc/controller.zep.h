
extern zend_class_entry *vii_mvc_controller_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_Controller);

PHP_METHOD(Vii_Mvc_Controller, __construct);
PHP_METHOD(Vii_Mvc_Controller, display);
PHP_METHOD(Vii_Mvc_Controller, goHome);
PHP_METHOD(Vii_Mvc_Controller, redirect);
PHP_METHOD(Vii_Mvc_Controller, __get);
PHP_METHOD(Vii_Mvc_Controller, setIoc);
PHP_METHOD(Vii_Mvc_Controller, getIoc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_controller_display, 0, 0, 3)
	ZEND_ARG_INFO(0, module)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_controller___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_controller_setioc, 0, 0, 1)
	ZEND_ARG_INFO(0, _ioc)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_controller_method_entry) {
	PHP_ME(Vii_Mvc_Controller, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_Controller, display, arginfo_vii_mvc_controller_display, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Controller, goHome, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Controller, redirect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Controller, __get, arginfo_vii_mvc_controller___get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Controller, setIoc, arginfo_vii_mvc_controller_setioc, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Controller, getIoc, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
