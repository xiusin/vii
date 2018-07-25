
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Tiny_Compiler) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc\\View\\Engine\\Tiny, Compiler, vii, mvc_view_engine_tiny_compiler, vii_mvc_view_engine_tiny_compiler_method_entry, 0);

	zend_declare_property_string(vii_mvc_view_engine_tiny_compiler_ce, SL("left_delimiter"), "{", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(vii_mvc_view_engine_tiny_compiler_ce, SL("right_delimiter"), "}", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(vii_mvc_view_engine_tiny_compiler_ce, SL("content"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_compiler_ce, SL("view"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_compiler_ce, SL("block"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_compiler_ce, SL("nocache"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_compiler_ce, SL("varPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_compiler_ce, SL("ioc"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_compiler_ce, SL("taglibarys"), ZEND_ACC_PROTECTED TSRMLS_CC);

	vii_mvc_view_engine_tiny_compiler_ce->create_object = zephir_init_properties_Vii_Mvc_View_Engine_Tiny_Compiler;
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, __construct) {

	zval *view, view_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);

	zephir_fetch_params(0, 1, 0, &view);



	zephir_update_property_zval(this_ptr, SL("view"), view);

}

/**
 * 编译模板内容
 */
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, compile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, _0, _1, _2, _3;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_EMPTY_STRING(&content);
	}


	zephir_update_property_zval(this_ptr, SL("content"), &content);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parsepartial", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "parsevar", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "parsevarpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &_2, "parsetags", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_3, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回解析完成以后的内容
 */
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "content");

}

/**
 * 设置模板替换变量
 */
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, setVarPath) {

	zval *varpath_param = NULL;
	zval varpath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&varpath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &varpath_param);

	ZEPHIR_OBS_COPY_OR_DUP(&varpath, varpath_param);


	zephir_update_property_zval(this_ptr, SL("varPath"), &varpath);
	RETURN_THIS();

}

/**
 * 解析替换模板变量
 */
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, parseVarPath) {

	zend_string *_3;
	zend_ulong _2;
	zval key, value, _0, *_1, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("varPath"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "vii/mvc/view/engine/tiny/compiler.zep", 58);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_read_property(&_5$$3, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_str_replace(&_4$$3, &key, &value, &_5$$3 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("content"), &_4$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, setTagLibarys) {

	zval *taglibarys_param = NULL;
	zval taglibarys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&taglibarys);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taglibarys_param);

	ZEPHIR_OBS_COPY_OR_DUP(&taglibarys, taglibarys_param);


	zephir_update_property_zval(this_ptr, SL("taglibarys"), &taglibarys);
	ZEPHIR_MM_RESTORE();

}

/**
 * 解析模板标签
 */
PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, parseTags) {

	zend_string *_6;
	zend_ulong _5;
	zval tagHandler, v, _0, _2, _3, *_4, _1$$3, _7$$4, _8$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tagHandler);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("taglibarys"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_ZVAL_NREF(_1$$3);
		ZVAL_STRING(&_1$$3, "Vii\\Mvc\\View\\Engine\\Tiny\\Tag");
		zephir_update_property_array_append(this_ptr, SL("taglibarys"), &_1$$3 TSRMLS_CC);
	}
	zephir_read_property(&_2, this_ptr, SL("taglibarys"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	zephir_is_iterable(&_2, 0, "vii/mvc/view/engine/tiny/compiler.zep", 83);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&_3);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&_3, _6);
		} else {
			ZVAL_LONG(&_3, _5);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _4);
		ZEPHIR_CALL_ZVAL_FUNCTION(&tagHandler, &v, NULL, 0);
		zephir_check_call_status();
		if (!(zephir_instance_of_ev(&tagHandler, vii_mvc_view_engine_tiny_taglibarys_ce TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_templateexception_ce, "标签解析类库必须继承Taglibarys类", "vii/mvc/view/engine/tiny/compiler.zep", 78);
			return;
		}
		zephir_read_property(&_8$$4, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7$$4, &tagHandler, "parse", NULL, 0, &_8$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("content"), &_7$$4);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&_3);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, parseVar) {

	zval preg, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&preg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("left_delimiter"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("right_delimiter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&preg);
	ZEPHIR_CONCAT_SVSVS(&preg, "#\\", &_0, "((\\$.+){0,1}(\\|.+){0,1})\\", &_1, "#U");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_closure_ex(&_2, NULL, vii_1__closure_ce, SL("__invoke"));
	zephir_read_property(&_3, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_replace_callback", NULL, 15, &preg, &_2, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("content"), &_4);
	ZEPHIR_INIT_VAR(&_5);
	zephir_read_property(&_6, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "?><?php");
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "");
	zephir_fast_str_replace(&_5, &_7, &_8, &_6 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("content"), &_5);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, parsePartial) {

	zval _2;
	zval preg, _0, _1, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&preg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("left_delimiter"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("right_delimiter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&preg);
	ZEPHIR_CONCAT_SVSVS(&preg, "#\\", &_0, "partial\\s+([\\'|\"])(.*?)\\1\\s*\\/\\", &_1, "#U");
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "_partial");
	zephir_array_fast_append(&_2, &_3);
	zephir_read_property(&_4, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_5, "preg_replace_callback", NULL, 15, &preg, &_2, &_4);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("content"), &_5);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Compiler, _partial) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metchs_param = NULL, _0, _2, _3, _4;
	zval metchs;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metchs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &metchs_param);

	ZEPHIR_OBS_COPY_OR_DUP(&metchs, metchs_param);


	zephir_array_fetch_long(&_0, &metchs, 0, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/compiler.zep", 136 TSRMLS_CC);
	_1 = ZEPHIR_IS_EMPTY(&_0);
	if (!(_1)) {
		zephir_array_fetch_long(&_2, &metchs, 2, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/compiler.zep", 136 TSRMLS_CC);
		_1 = ZEPHIR_IS_EMPTY(&_2);
	}
	if (_1) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_3, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_4, &metchs, 2, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/compiler.zep", 139 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(&_3, "partial", NULL, 0, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Vii_Mvc_View_Engine_Tiny_Compiler(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("taglibarys"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("taglibarys"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("varPath"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("varPath"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("nocache"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("nocache"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("block"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("block"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

