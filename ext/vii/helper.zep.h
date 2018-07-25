
extern zend_class_entry *vii_helper_ce;

ZEPHIR_INIT_CLASS(Vii_Helper);

PHP_METHOD(Vii_Helper, obj2arr);
PHP_METHOD(Vii_Helper, getOs);
PHP_METHOD(Vii_Helper, getHttpMethod);
PHP_METHOD(Vii_Helper, getFileExtension);
PHP_METHOD(Vii_Helper, start_with);
PHP_METHOD(Vii_Helper, _t);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_helper_obj2arr, 0, 0, 1)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_helper_getfileextension, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_helper_start_with, 0, 0, 2)
	ZEND_ARG_INFO(0, _string)
	ZEND_ARG_INFO(0, _find)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_helper__t, 0, 0, 1)
	ZEND_ARG_INFO(0, strOrId)
	ZEND_ARG_ARRAY_INFO(0, value, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_helper_method_entry) {
	PHP_ME(Vii_Helper, obj2arr, arginfo_vii_helper_obj2arr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vii_Helper, getOs, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vii_Helper, getHttpMethod, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vii_Helper, getFileExtension, arginfo_vii_helper_getfileextension, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vii_Helper, start_with, arginfo_vii_helper_start_with, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Vii_Helper, _t, arginfo_vii_helper__t, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
