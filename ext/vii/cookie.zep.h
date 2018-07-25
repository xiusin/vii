
extern zend_class_entry *vii_cookie_ce;

ZEPHIR_INIT_CLASS(Vii_Cookie);

PHP_METHOD(Vii_Cookie, __construct);
PHP_METHOD(Vii_Cookie, encryption);
PHP_METHOD(Vii_Cookie, useEncryption);
PHP_METHOD(Vii_Cookie, set);
PHP_METHOD(Vii_Cookie, setValue);
PHP_METHOD(Vii_Cookie, get);
PHP_METHOD(Vii_Cookie, getValue);
PHP_METHOD(Vii_Cookie, clear);
PHP_METHOD(Vii_Cookie, flashGet);
PHP_METHOD(Vii_Cookie, del);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_cookie___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, salt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_cookie_encryption, 0, 0, 1)
	ZEND_ARG_INFO(0, _string)
	ZEND_ARG_INFO(0, aciton)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_cookie_useencryption, 0, 0, 0)
	ZEND_ARG_INFO(0, isuse)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_cookie_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, _time)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_cookie_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_cookie_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_cookie_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_cookie_flashget, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_cookie_del, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_cookie_method_entry) {
	PHP_ME(Vii_Cookie, __construct, arginfo_vii_cookie___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Cookie, encryption, arginfo_vii_cookie_encryption, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Cookie, useEncryption, arginfo_vii_cookie_useencryption, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Cookie, set, arginfo_vii_cookie_set, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Cookie, setValue, arginfo_vii_cookie_setvalue, ZEND_ACC_PROTECTED)
	PHP_ME(Vii_Cookie, get, arginfo_vii_cookie_get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Cookie, getValue, arginfo_vii_cookie_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Cookie, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Cookie, flashGet, arginfo_vii_cookie_flashget, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Cookie, del, arginfo_vii_cookie_del, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
