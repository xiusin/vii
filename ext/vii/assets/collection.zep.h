
extern zend_class_entry *vii_assets_collection_ce;

ZEPHIR_INIT_CLASS(Vii_Assets_Collection);

PHP_METHOD(Vii_Assets_Collection, getPrefix);
PHP_METHOD(Vii_Assets_Collection, getLocal);
PHP_METHOD(Vii_Assets_Collection, getCss);
PHP_METHOD(Vii_Assets_Collection, getJs);
PHP_METHOD(Vii_Assets_Collection, getInline);
PHP_METHOD(Vii_Assets_Collection, getResources);
PHP_METHOD(Vii_Assets_Collection, add);
PHP_METHOD(Vii_Assets_Collection, addCss);
PHP_METHOD(Vii_Assets_Collection, addInlineCss);
PHP_METHOD(Vii_Assets_Collection, addJs);
PHP_METHOD(Vii_Assets_Collection, addInlineJs);
PHP_METHOD(Vii_Assets_Collection, setPrefix);
PHP_METHOD(Vii_Assets_Collection, setLocal);
PHP_METHOD(Vii_Assets_Collection, join);
PHP_METHOD(Vii_Assets_Collection, setTargetPath);
PHP_METHOD(Vii_Assets_Collection, setTatgetUri);
zend_object *zephir_init_properties_Vii_Assets_Collection(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_getinline, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, _resource, Vii\\Assets\\Resources, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_addcss, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_addinlinecss, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_addjs, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_addinlinejs, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_setlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_join, 0, 0, 1)
	ZEND_ARG_INFO(0, join)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_settargetpath, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_assets_collection_settatgeturi, 0, 0, 1)
	ZEND_ARG_INFO(0, targetUri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_assets_collection_method_entry) {
	PHP_ME(Vii_Assets_Collection, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, getLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, getCss, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, getJs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, getInline, arginfo_vii_assets_collection_getinline, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, getResources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, add, arginfo_vii_assets_collection_add, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, addCss, arginfo_vii_assets_collection_addcss, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, addInlineCss, arginfo_vii_assets_collection_addinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, addJs, arginfo_vii_assets_collection_addjs, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, addInlineJs, arginfo_vii_assets_collection_addinlinejs, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, setPrefix, arginfo_vii_assets_collection_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, setLocal, arginfo_vii_assets_collection_setlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, join, arginfo_vii_assets_collection_join, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, setTargetPath, arginfo_vii_assets_collection_settargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Assets_Collection, setTatgetUri, arginfo_vii_assets_collection_settatgeturi, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
