
extern zend_class_entry *vii_mvc_model_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_Model);

PHP_METHOD(Vii_Mvc_Model, __construct);
PHP_METHOD(Vii_Mvc_Model, find);
PHP_METHOD(Vii_Mvc_Model, getLastQuery);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_model___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, fields, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_model_find, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_model_method_entry) {
	PHP_ME(Vii_Mvc_Model, __construct, arginfo_vii_mvc_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_Model, find, arginfo_vii_mvc_model_find, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Model, getLastQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
