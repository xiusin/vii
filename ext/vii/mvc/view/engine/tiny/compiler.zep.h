
extern zend_class_entry *vii_mvc_view_engine_tiny_compiler_ce;

ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Tiny_Compiler);

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, __construct);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, compile);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, getContent);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, setVarPath);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, parseVarPath);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, setTagLibarys);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, parseTags);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, parseVar);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, parsePartial);
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, _partial);
static zend_object *zephir_init_properties_Vii_Mvc_View_Engine_Tiny_Compiler(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_compiler___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_compiler_compile, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_compiler_setvarpath, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, varpath, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_compiler_settaglibarys, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, taglibarys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_mvc_view_engine_tiny_compiler__partial, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, metchs, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_mvc_view_engine_tiny_compiler_method_entry) {
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Compiler, __construct, arginfo_vii_mvc_view_engine_tiny_compiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Compiler, compile, arginfo_vii_mvc_view_engine_tiny_compiler_compile, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Compiler, getContent, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Compiler, setVarPath, arginfo_vii_mvc_view_engine_tiny_compiler_setvarpath, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Compiler, parseVarPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Compiler, setTagLibarys, arginfo_vii_mvc_view_engine_tiny_compiler_settaglibarys, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Compiler, parseTags, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Compiler, parseVar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Compiler, parsePartial, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Mvc_View_Engine_Tiny_Compiler, _partial, arginfo_vii_mvc_view_engine_tiny_compiler__partial, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
