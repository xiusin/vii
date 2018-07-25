
extern zend_class_entry *vii_session_adapter_memcache_ce;

ZEPHIR_INIT_CLASS(Vii_Session_Adapter_Memcache);

PHP_METHOD(Vii_Session_Adapter_Memcache, __construct);
PHP_METHOD(Vii_Session_Adapter_Memcache, addServer);
PHP_METHOD(Vii_Session_Adapter_Memcache, addServers);
PHP_METHOD(Vii_Session_Adapter_Memcache, open);
PHP_METHOD(Vii_Session_Adapter_Memcache, read);
PHP_METHOD(Vii_Session_Adapter_Memcache, write);
PHP_METHOD(Vii_Session_Adapter_Memcache, destroy);
PHP_METHOD(Vii_Session_Adapter_Memcache, gc);
PHP_METHOD(Vii_Session_Adapter_Memcache, close);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_adapter_memcache___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_adapter_memcache_addserver, 0, 0, 2)
	ZEND_ARG_INFO(0, ip)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_adapter_memcache_addservers, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, servers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_adapter_memcache_open, 0, 0, 2)
	ZEND_ARG_INFO(0, save_path)
	ZEND_ARG_INFO(0, session_name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_adapter_memcache_read, 0, 0, 1)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_adapter_memcache_write, 0, 0, 2)
	ZEND_ARG_INFO(0, session_id)
	ZEND_ARG_INFO(0, session_data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_adapter_memcache_destroy, 0, 0, 0)
	ZEND_ARG_INFO(0, session_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_session_adapter_memcache_gc, 0, 0, 1)
	ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_session_adapter_memcache_method_entry) {
	PHP_ME(Vii_Session_Adapter_Memcache, __construct, arginfo_vii_session_adapter_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Session_Adapter_Memcache, addServer, arginfo_vii_session_adapter_memcache_addserver, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_Adapter_Memcache, addServers, arginfo_vii_session_adapter_memcache_addservers, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_Adapter_Memcache, open, arginfo_vii_session_adapter_memcache_open, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_Adapter_Memcache, read, arginfo_vii_session_adapter_memcache_read, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_Adapter_Memcache, write, arginfo_vii_session_adapter_memcache_write, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_Adapter_Memcache, destroy, arginfo_vii_session_adapter_memcache_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_Adapter_Memcache, gc, arginfo_vii_session_adapter_memcache_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Session_Adapter_Memcache, close, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
