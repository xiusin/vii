
extern zend_class_entry *vii_interfaces_cacheinterface_ce;

ZEPHIR_INIT_CLASS(Vii_Interfaces_CacheInterface);

ZEPHIR_INIT_FUNCS(vii_interfaces_cacheinterface_method_entry) {
	PHP_ABSTRACT_ME(Vii_Interfaces_CacheInterface, get, NULL)
	PHP_FE_END
};
