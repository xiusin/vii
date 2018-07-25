
extern zend_class_entry *vii_session_nativesession_ce;

ZEPHIR_INIT_CLASS(Vii_Session_NativeSession);

PHP_METHOD(Vii_Session_NativeSession, __construct);
PHP_METHOD(Vii_Session_NativeSession, start);
PHP_METHOD(Vii_Session_NativeSession, setOptions);
PHP_METHOD(Vii_Session_NativeSession, getOptions);
PHP_METHOD(Vii_Session_NativeSession, setName);
PHP_METHOD(Vii_Session_NativeSession, getName);
PHP_METHOD(Vii_Session_NativeSession, regenerateId);
PHP_METHOD(Vii_Session_NativeSession, getIndex);
PHP_METHOD(Vii_Session_NativeSession, get);
PHP_METHOD(Vii_Session_NativeSession, set);
PHP_METHOD(Vii_Session_NativeSession, has);
PHP_METHOD(Vii_Session_NativeSession, remove);
PHP_METHOD(Vii_Session_NativeSession, getId);
PHP_METHOD(Vii_Session_NativeSession, setId);
PHP_METHOD(Vii_Session_NativeSession, isStarted);
PHP_METHOD(Vii_Session_NativeSession, destroy);
PHP_METHOD(Vii_Session_NativeSession, status);
PHP_METHOD(Vii_Session_NativeSession, __get);
PHP_METHOD(Vii_Session_NativeSession, __set);
PHP_METHOD(Vii_Session_NativeSession, __isset);
PHP_METHOD(Vii_Session_NativeSession, __unset);
PHP_METHOD(Vii_Session_NativeSession, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession_regenerateid, 0, 0, 0)
	ZEND_ARG_INFO(0, deleteOldSession)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession_getindex, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession_has, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession_destroy, 0, 0, 0)
	ZEND_ARG_INFO(0, removeCurrentSessionData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession___get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession___set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_nativesession___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_session_nativesession_method_entry) {
	PHP_ME(Vii_Session_NativeSession, __construct, arginfo_vii_session_nativesession___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Session_NativeSession, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, setOptions, arginfo_vii_session_nativesession_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, setName, arginfo_vii_session_nativesession_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, regenerateId, arginfo_vii_session_nativesession_regenerateid, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, getIndex, arginfo_vii_session_nativesession_getindex, ZEND_ACC_PROTECTED)
	PHP_ME(Vii_Session_NativeSession, get, arginfo_vii_session_nativesession_get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, set, arginfo_vii_session_nativesession_set, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, has, arginfo_vii_session_nativesession_has, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, remove, arginfo_vii_session_nativesession_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, setId, arginfo_vii_session_nativesession_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, isStarted, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, destroy, arginfo_vii_session_nativesession_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, status, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, __get, arginfo_vii_session_nativesession___get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, __set, arginfo_vii_session_nativesession___set, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, __isset, arginfo_vii_session_nativesession___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, __unset, arginfo_vii_session_nativesession___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_NativeSession, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
