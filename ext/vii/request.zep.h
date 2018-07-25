
extern zend_class_entry *vii_request_ce;

ZEPHIR_INIT_CLASS(Vii_Request);

PHP_METHOD(Vii_Request, __construct);
PHP_METHOD(Vii_Request, setIoc);
PHP_METHOD(Vii_Request, getIoc);
PHP_METHOD(Vii_Request, server);
PHP_METHOD(Vii_Request, getReferer);
PHP_METHOD(Vii_Request, getCookie);
PHP_METHOD(Vii_Request, setCookie);
PHP_METHOD(Vii_Request, getMethod);
PHP_METHOD(Vii_Request, flashCookie);
PHP_METHOD(Vii_Request, clientIp);
PHP_METHOD(Vii_Request, getRequestTime);
PHP_METHOD(Vii_Request, isweixin);
PHP_METHOD(Vii_Request, pathinfo);
PHP_METHOD(Vii_Request, getPost);
PHP_METHOD(Vii_Request, get);
PHP_METHOD(Vii_Request, _get_post);
PHP_METHOD(Vii_Request, hasFiles);
PHP_METHOD(Vii_Request, getUploadedFiles);
void zephir_init_static_properties_Vii_Request(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_request_setioc, 0, 0, 1)
	ZEND_ARG_INFO(0, _ioc)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_request_server, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_request_getcookie, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_request_setcookie, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, _time)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_request_flashcookie, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_request_getpost, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, def)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_request_get, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, def)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_request__get_post, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, def)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_request_getuploadedfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, only_success)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_request_method_entry) {
	PHP_ME(Vii_Request, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Request, setIoc, arginfo_vii_request_setioc, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, getIoc, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, server, arginfo_vii_request_server, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Request, getReferer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, getCookie, arginfo_vii_request_getcookie, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, setCookie, arginfo_vii_request_setcookie, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, flashCookie, arginfo_vii_request_flashcookie, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, clientIp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, getRequestTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, isweixin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, pathinfo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, getPost, arginfo_vii_request_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, get, arginfo_vii_request_get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, _get_post, arginfo_vii_request__get_post, ZEND_ACC_PROTECTED)
	PHP_ME(Vii_Request, hasFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Request, getUploadedFiles, arginfo_vii_request_getuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
