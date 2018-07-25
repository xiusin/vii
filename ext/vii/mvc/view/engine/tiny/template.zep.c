
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/time.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Tiny_Template) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc\\View\\Engine\\Tiny, Template, vii, mvc_view_engine_tiny_template, vii_mvc_view_engine_tiny_template_method_entry, 0);

	zend_declare_property_string(vii_mvc_view_engine_tiny_template_ce, SL("left_delimiter"), "{", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(vii_mvc_view_engine_tiny_template_ce, SL("right_delimiter"), "}", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(vii_mvc_view_engine_tiny_template_ce, SL("content"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_template_ce, SL("view"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_template_ce, SL("block"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_template_ce, SL("nocache"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_template_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_engine_tiny_template_ce, SL("service"), ZEND_ACC_PROTECTED TSRMLS_CC);

	vii_mvc_view_engine_tiny_template_ce->create_object = zephir_init_properties_Vii_Mvc_View_Engine_Tiny_Template;
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, __construct) {

	zval *view;

	zephir_fetch_params(0, 1, 0, &view);



	zephir_update_property_this(this_ptr, SL("view"), view TSRMLS_CC);

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, setConfig) {

	zval *key, *value;

	zephir_fetch_params(0, 2, 0, &key, &value);



	zephir_update_property_array(this_ptr, SL("config"), key, value TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, getConfig) {

	zval *key, *_0, *_1;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, key, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/template.zep", 26 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, run) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	if (unlikely(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(content, content_param);
	} else {
		ZEPHIR_INIT_VAR(content);
		ZVAL_EMPTY_STRING(content);
	}


	zephir_update_property_this(this_ptr, SL("content"), content TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseload", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, _0, "replace_blockcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _1, "parsevar", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, _2, "parsevarpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _3, "nocache", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, _4, "parsetags", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_5, "replace_nocachetovar", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, parseVarPath) {

	HashTable *_2;
	HashPosition _1;
	zval *key = NULL, *value = NULL, *_0, **_3, *_4$$3 = NULL, *_5$$3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "vii/mvc/view/engine/tiny/template.zep", 47);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_INIT_NVAR(_4$$3);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
		zephir_fast_str_replace(&_4$$3, key, value, _5$$3 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("content"), _4$$3 TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, parseTags) {

	zval *tagHandler = NULL, *_0 = NULL, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(tagHandler);
	object_init_ex(tagHandler, vii_mvc_view_engine_tiny_defaulttag_ce);
	if (zephir_has_constructor(tagHandler TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, tagHandler, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, tagHandler, "parse", NULL, 107, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("content"), _0 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, parseVar) {

	zval *preg = NULL, *_0, *_1, *_2 = NULL, *_3, *_4 = NULL, *_5, *_6, _7, _8;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("left_delimiter"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("right_delimiter"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(preg);
	ZEPHIR_CONCAT_SVSVS(preg, "#\\", _0, "((\\$.+){0,1}(\\|.+){0,1})\\", _1, "#U");
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_INIT_NVAR(_2);
	zephir_create_closure_ex(_2, NULL, vii_0__closure_ce, SS("__invoke") TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_replace_callback", NULL, 5, preg, _2, _3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("content"), _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "?><?php", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "", 0);
	zephir_fast_str_replace(&_5, &_7, &_8, _6 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("content"), _5 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, parseLoad) {

	zval *_4$$3, *_10$$4;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, *preg = NULL, *_0, *_1, *_2$$3, *_5$$3, *_6$$3, *_7$$3 = NULL, *_9$$4, *_11$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &content);

	if (!content) {
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "", 1);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, vii_mvc_view_engine_tiny_taglibarys_ce, SL("left_delimiter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, vii_mvc_view_engine_tiny_taglibarys_ce, SL("right_delimiter") TSRMLS_CC);
	ZEPHIR_INIT_VAR(preg);
	ZEPHIR_CONCAT_SVSVS(preg, "#\\", _0, "\\s*include\\s+file=([\\'|\"])(.*?)\\1\\s*\\/\\", _1, "#U");
	if (!zephir_is_true(content)) {
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseblock", &_3, 0, _2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_create_array(_4$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_4$$3, this_ptr);
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_STRING(_5$$3, "loadDpr", 1);
		zephir_array_fast_append(_4$$3, _5$$3);
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "preg_replace_callback", &_8, 5, preg, _4$$3, _6$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("content"), _7$$3 TSRMLS_CC);
		RETURN_THIS();
	} else {
		_9$$4 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseblock", &_3, 0, _9$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_10$$4);
		zephir_create_array(_10$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_10$$4, this_ptr);
		ZEPHIR_INIT_VAR(_11$$4);
		ZVAL_STRING(_11$$4, "loadDpr", 1);
		zephir_array_fast_append(_10$$4, _11$$4);
		ZEPHIR_RETURN_CALL_FUNCTION("preg_replace_callback", &_8, 5, preg, _10$$4, content);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, parseBlock) {

	zval *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, *preg = NULL, *_0, *_1, *_2, *_3, *_5, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);

	ZEPHIR_SEPARATE_PARAM(content);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, vii_mvc_view_engine_tiny_taglibarys_ce, SL("left_delimiter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, vii_mvc_view_engine_tiny_taglibarys_ce, SL("right_delimiter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_static_property_ce(&_2, vii_mvc_view_engine_tiny_taglibarys_ce, SL("left_delimiter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_static_property_ce(&_3, vii_mvc_view_engine_tiny_taglibarys_ce, SL("right_delimiter") TSRMLS_CC);
	ZEPHIR_INIT_VAR(preg);
	ZEPHIR_CONCAT_SVSVSVSVS(preg, "#\\", _0, "block\\s+name=([\\'|\"])(.*?)\\1\\", _1, "(.*?)\\", _2, "\\/block\\", _3, "#is");
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_4, this_ptr);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "_block", 1);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_CALL_FUNCTION(&_6, "preg_replace_callback", NULL, 5, preg, _4, content);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(content, _6);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, _block) {

	zval *matchs, *blockRep = NULL, *_0, *_1, *_2$$3, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matchs);



	zephir_array_fetch_long(&_0, matchs, 2, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/template.zep", 122 TSRMLS_CC);
	ZEPHIR_INIT_VAR(blockRep);
	ZEPHIR_CONCAT_SVS(blockRep, "[block", _0, "block]");
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("block"), PH_NOISY_CC);
	if (zephir_array_isset(_1, blockRep)) {
		zephir_array_fetch_long(&_2$$3, matchs, 3, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/template.zep", 125 TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("block"), blockRep, _2$$3 TSRMLS_CC);
		RETURN_MM_STRING("", 1);
	} else {
		zephir_array_fetch_long(&_3$$4, matchs, 3, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/template.zep", 128 TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("block"), blockRep, _3$$4 TSRMLS_CC);
	}
	RETURN_CCTOR(blockRep);

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, loadDpr) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *path = NULL, *content = NULL, *preg = NULL, *_0, *_1, *_2 = NULL, *_5, *_6, *_7, *_3$$3, *_4$$3, *_8$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("view"), PH_NOISY_CC);
	zephir_array_fetch_long(&_1, data, 2, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/template.zep", 135 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(&path, _0, "gettpl", NULL, 0, _1, _2);
	zephir_check_call_status();
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(_3$$3);
		object_init_ex(_3$$3, vii_exceptions_templateexception_ce);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_SVS(_4$$3, "Template File[", path, "] not exists!!");
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 4, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$3, "vii/mvc/view/engine/tiny/template.zep", 137 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(content);
	zephir_file_get_contents(content, path TSRMLS_CC);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_static_property_ce(&_5, vii_mvc_view_engine_tiny_taglibarys_ce, SL("left_delimiter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_6);
	zephir_read_static_property_ce(&_6, vii_mvc_view_engine_tiny_taglibarys_ce, SL("right_delimiter") TSRMLS_CC);
	ZEPHIR_INIT_VAR(preg);
	ZEPHIR_CONCAT_SVSVS(preg, "/\\", _5, "\\s*include\\s+file=([\\'|\"])(.*?)\\1\\s*\\/\\", _6, "/U");
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_INIT_NVAR(_2);
	zephir_preg_match(_2, preg, content, _7, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_2)) {
		ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "parseload", NULL, 0, content);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(content, _8$$4);
	}
	RETURN_CCTOR(content);

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, nocache) {

	zval *_4;
	zval *preg = NULL, *_0, *_1, *_2, *_3, *_5, *_6, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, vii_mvc_view_engine_tiny_taglibarys_ce, SL("left_delimiter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, vii_mvc_view_engine_tiny_taglibarys_ce, SL("right_delimiter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_static_property_ce(&_2, vii_mvc_view_engine_tiny_taglibarys_ce, SL("left_delimiter") TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_static_property_ce(&_3, vii_mvc_view_engine_tiny_taglibarys_ce, SL("right_delimiter") TSRMLS_CC);
	ZEPHIR_INIT_VAR(preg);
	ZEPHIR_CONCAT_SVSVSVSVS(preg, "/\\", _0, "nocache\\", _1, "(.*)\\", _2, "\\/nocache\\", _3, "/isU");
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_4, this_ptr);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "_nocache", 1);
	zephir_array_fast_append(_4, _5);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_7, "preg_replace_callback", NULL, 5, preg, _4, _6);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("content"), _7 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, _nocache) {

	zval *data, *block = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(_0);
	zephir_time(_0);
	ZEPHIR_INIT_VAR(block);
	ZEPHIR_CONCAT_SVS(block, "<!######nocache_block_", _0, "######>");
	zephir_array_fetch_long(&_1, data, 1, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/template.zep", 158 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("nocache"), block, _1 TSRMLS_CC);
	RETURN_CCTOR(block);

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, replace_nocacheToVar) {

	HashTable *_2;
	HashPosition _1;
	zval *k = NULL, *v = NULL, *_0, **_3, *_4$$3 = NULL, *_5$$3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("nocache"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "vii/mvc/view/engine/tiny/template.zep", 168);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		ZEPHIR_INIT_NVAR(_4$$3);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
		zephir_fast_str_replace(&_4$$3, k, v, _5$$3 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("content"), _4$$3 TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "content");

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Template, replace_blockContent) {

	HashTable *_2;
	HashPosition _1;
	zval *k = NULL, *v = NULL, *_0, **_3, *_4$$3 = NULL, *_5$$3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("block"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "vii/mvc/view/engine/tiny/template.zep", 176);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		ZEPHIR_INIT_NVAR(_4$$3);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("content"), PH_NOISY_CC);
		zephir_fast_str_replace(&_4$$3, k, v, _5$$3 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("content"), _4$$3 TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("block"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THIS();

}

zend_object_value zephir_init_properties_Vii_Mvc_View_Engine_Tiny_Template(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_1$$3, *_3$$4, *_5$$5;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("config"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("nocache"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("nocache"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("block"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(this_ptr, SL("block"), _5$$5 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

