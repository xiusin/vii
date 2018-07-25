
extern zend_class_entry *vii_uploadfileinfo_ce;

ZEPHIR_INIT_CLASS(Vii_UploadFileInfo);

PHP_METHOD(Vii_UploadFileInfo, __construct);
PHP_METHOD(Vii_UploadFileInfo, isUploadFile);
PHP_METHOD(Vii_UploadFileInfo, hasError);
PHP_METHOD(Vii_UploadFileInfo, getSize);
PHP_METHOD(Vii_UploadFileInfo, getName);
PHP_METHOD(Vii_UploadFileInfo, getType);
PHP_METHOD(Vii_UploadFileInfo, getExt);
PHP_METHOD(Vii_UploadFileInfo, getTmpName);
PHP_METHOD(Vii_UploadFileInfo, moveTo);
static zend_object *zephir_init_properties_Vii_UploadFileInfo(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_uploadfileinfo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, fileinfo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_uploadfileinfo_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, destination_file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_uploadfileinfo_method_entry) {
	PHP_ME(Vii_UploadFileInfo, __construct, arginfo_vii_uploadfileinfo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_UploadFileInfo, isUploadFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UploadFileInfo, hasError, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Vii_UploadFileInfo, getSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UploadFileInfo, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UploadFileInfo, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UploadFileInfo, getExt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UploadFileInfo, getTmpName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_UploadFileInfo, moveTo, arginfo_vii_uploadfileinfo_moveto, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
