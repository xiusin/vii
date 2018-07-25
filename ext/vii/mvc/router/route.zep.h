
extern zend_class_entry *vii_mvc_router_route_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_Router_Route);

PHP_METHOD(Vii_Mvc_Router_Route, __construct);
PHP_METHOD(Vii_Mvc_Router_Route, compilePattern);
PHP_METHOD(Vii_Mvc_Router_Route, via);
PHP_METHOD(Vii_Mvc_Router_Route, setName);
PHP_METHOD(Vii_Mvc_Router_Route, getName);
PHP_METHOD(Vii_Mvc_Router_Route, match);
PHP_METHOD(Vii_Mvc_Router_Route, getMatch);
PHP_METHOD(Vii_Mvc_Router_Route, getPattern);
PHP_METHOD(Vii_Mvc_Router_Route, getMethods);
PHP_METHOD(Vii_Mvc_Router_Route, getCompiledPattern);
PHP_METHOD(Vii_Mvc_Router_Route, getPaths);
PHP_METHOD(Vii_Mvc_Router_Route, getRoutePath);
PHP_METHOD(Vii_Mvc_Router_Route, setBeforeMatch);
PHP_METHOD(Vii_Mvc_Router_Route, getBeforeMatch);
static zend_object *zephir_init_properties_Vii_Mvc_Router_Route(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_route___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_route_compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_route_via, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, httpMethods, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_route_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_route_match, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_route_getroutepath, 0, 0, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_router_route_setbeforematch, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_router_route_method_entry) {
	PHP_ME(Vii_Mvc_Router_Route, __construct, arginfo_vii_mvc_router_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_Router_Route, compilePattern, arginfo_vii_mvc_router_route_compilepattern, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Mvc_Router_Route, via, arginfo_vii_mvc_router_route_via, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router_Route, setName, arginfo_vii_mvc_router_route_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router_Route, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router_Route, match, arginfo_vii_mvc_router_route_match, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router_Route, getMatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router_Route, getPattern, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router_Route, getMethods, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router_Route, getCompiledPattern, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router_Route, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router_Route, getRoutePath, arginfo_vii_mvc_router_route_getroutepath, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Mvc_Router_Route, setBeforeMatch, arginfo_vii_mvc_router_route_setbeforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_Router_Route, getBeforeMatch, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
