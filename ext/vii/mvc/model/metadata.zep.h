
extern zend_class_entry *vii_mvc_model_metadata_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_Model_MetaData);

PHP_METHOD(Vii_Mvc_Model_MetaData, setOldData);
PHP_METHOD(Vii_Mvc_Model_MetaData, setNewData);
PHP_METHOD(Vii_Mvc_Model_MetaData, getOldData);
PHP_METHOD(Vii_Mvc_Model_MetaData, getNewData);
PHP_METHOD(Vii_Mvc_Model_MetaData, getData);
zend_object_value zephir_init_properties_Vii_Mvc_Model_MetaData(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_model_metadata_getdata, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_model_metadata_method_entry) {
	PHP_ME(Vii_Mvc_Model_MetaData, setOldData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Model_MetaData, setNewData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Model_MetaData, getOldData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Model_MetaData, getNewData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Model_MetaData, getData, arginfo_vii_mvc_model_metadata_getdata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
