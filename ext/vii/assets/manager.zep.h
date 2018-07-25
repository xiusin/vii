
extern zend_class_entry *vii_assets_manager_ce;

ZEPHIR_INIT_CLASS(Vii_Assets_Manager);

PHP_METHOD(Vii_Assets_Manager, __construct);
PHP_METHOD(Vii_Assets_Manager, setOptions);
PHP_METHOD(Vii_Assets_Manager, getOptions);
PHP_METHOD(Vii_Assets_Manager, set);
PHP_METHOD(Vii_Assets_Manager, get);
PHP_METHOD(Vii_Assets_Manager, addCss);
PHP_METHOD(Vii_Assets_Manager, addJs);
PHP_METHOD(Vii_Assets_Manager, addInlineCss);
PHP_METHOD(Vii_Assets_Manager, addInlineJs);
PHP_METHOD(Vii_Assets_Manager, addResource);
PHP_METHOD(Vii_Assets_Manager, collection);
PHP_METHOD(Vii_Assets_Manager, hasCollection);
PHP_METHOD(Vii_Assets_Manager, getCss);
PHP_METHOD(Vii_Assets_Manager, getJs);
PHP_METHOD(Vii_Assets_Manager, output);
PHP_METHOD(Vii_Assets_Manager, outputinline);
PHP_METHOD(Vii_Assets_Manager, outputCss);
PHP_METHOD(Vii_Assets_Manager, outputInlineCss);
PHP_METHOD(Vii_Assets_Manager, outputJs);
PHP_METHOD(Vii_Assets_Manager, outputInlineJs);
PHP_METHOD(Vii_Assets_Manager, getCollections);
static zend_object *zephir_init_properties_Vii_Assets_Manager(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_set, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_OBJ_INFO(0, collection, Vii\\Assets\\Collection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_addcss, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_addjs, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_addinlinecss, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_addinlinejs, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_addresource, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, resources, Vii\\Assets\\Resources, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_collection, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_hascollection, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_output, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_outputinline, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_outputcss, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_outputinlinecss, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_outputjs, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_manager_outputinlinejs, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_assets_manager_method_entry) {
	PHP_ME(Vii_Assets_Manager, __construct, arginfo_vii_assets_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Assets_Manager, setOptions, arginfo_vii_assets_manager_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, set, arginfo_vii_assets_manager_set, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, get, arginfo_vii_assets_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, addCss, arginfo_vii_assets_manager_addcss, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, addJs, arginfo_vii_assets_manager_addjs, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, addInlineCss, arginfo_vii_assets_manager_addinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, addInlineJs, arginfo_vii_assets_manager_addinlinejs, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, addResource, arginfo_vii_assets_manager_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, collection, arginfo_vii_assets_manager_collection, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, hasCollection, arginfo_vii_assets_manager_hascollection, ZEND_ACC_PROTECTED)
	PHP_ME(Vii_Assets_Manager, getCss, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, getJs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, output, arginfo_vii_assets_manager_output, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, outputinline, arginfo_vii_assets_manager_outputinline, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, outputCss, arginfo_vii_assets_manager_outputcss, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, outputInlineCss, arginfo_vii_assets_manager_outputinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, outputJs, arginfo_vii_assets_manager_outputjs, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, outputInlineJs, arginfo_vii_assets_manager_outputinlinejs, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Manager, getCollections, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
