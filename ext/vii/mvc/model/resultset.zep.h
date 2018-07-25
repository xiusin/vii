
extern zend_class_entry *vii_mvc_model_resultset_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_Model_Resultset);

PHP_METHOD(Vii_Mvc_Model_Resultset, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_model_resultset___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_model_resultset_method_entry) {
	PHP_ME(Vii_Mvc_Model_Resultset, __construct, arginfo_vii_mvc_model_resultset___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
