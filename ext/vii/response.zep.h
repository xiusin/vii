
extern zend_class_entry *vii_response_ce;

ZEPHIR_INIT_CLASS(Vii_Response);

PHP_METHOD(Vii_Response, __construct);
PHP_METHOD(Vii_Response, setStatusCode);
PHP_METHOD(Vii_Response, setHeader);
PHP_METHOD(Vii_Response, setRawHeader);
PHP_METHOD(Vii_Response, redirect);
PHP_METHOD(Vii_Response, setContent);
PHP_METHOD(Vii_Response, setJsonContent);
PHP_METHOD(Vii_Response, appendContent);
PHP_METHOD(Vii_Response, getContent);
PHP_METHOD(Vii_Response, resetHeaders);
PHP_METHOD(Vii_Response, isSend);
PHP_METHOD(Vii_Response, sendHeaders);
PHP_METHOD(Vii_Response, sendContent);
PHP_METHOD(Vii_Response, send);
PHP_METHOD(Vii_Response, hasHeader);
zend_object *zephir_init_properties_Vii_Response(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_response_setstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_response_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_response_setrawheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_response_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_response_setjsoncontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, depth)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_response_appendcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_response_method_entry) {
	PHP_ME(Vii_Response, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Response, setStatusCode, arginfo_vii_response_setstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, setHeader, arginfo_vii_response_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, setRawHeader, arginfo_vii_response_setrawheader, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, redirect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, setContent, arginfo_vii_response_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, setJsonContent, arginfo_vii_response_setjsoncontent, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, appendContent, arginfo_vii_response_appendcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, resetHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, isSend, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, sendHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, sendContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Response, hasHeader, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
