
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Tiny_DefaultTag) {

	ZEPHIR_REGISTER_CLASS_EX(Vii\\Mvc\\View\\Engine\\Tiny, DefaultTag, vii, mvc_view_engine_tiny_defaulttag, vii_mvc_view_engine_tiny_taglibarys_ce, vii_mvc_view_engine_tiny_defaulttag_method_entry, 0);

	zend_declare_property_null(vii_mvc_view_engine_tiny_defaulttag_ce, SL("tags"), ZEND_ACC_PUBLIC TSRMLS_CC);

	vii_mvc_view_engine_tiny_defaulttag_ce->create_object = zephir_init_properties_Vii_Mvc_View_Engine_Tiny_DefaultTag;
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _php) {

	zval *params, *content;

	zephir_fetch_params(0, 2, 0, &params, &content);



	ZEPHIR_CONCAT_SVS(return_value, "<?php ", content, "?>");
	return;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _if) {

	zval *params, *content = NULL, *condition = NULL, *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params, &content);

	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_array_isset_string(params, SS("condition"))) {
		ZEPHIR_OBS_VAR(condition);
		zephir_array_fetch_string(&condition, params, SL("condition"), PH_NOISY, "vii/mvc/view/engine/tiny/defaulttag.zep", 23 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(condition);
		ZVAL_BOOL(condition, 0);
	}
	if (zephir_is_true(condition)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "if标签内必须有condition属性", "vii/mvc/view/engine/tiny/defaulttag.zep", 25);
		return;
	}
	ZEPHIR_INIT_VAR(str);
	ZEPHIR_CONCAT_SVSVS(str, "<?php if(", condition, ") : ?>", content, "<?php endif; ?>");
	RETURN_CCTOR(str);

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _else) {

	

	RETURN_STRING("<?php  else:  ?>", 1);

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _js) {

	zval *params, *_0;

	zephir_fetch_params(0, 1, 0, &params);



	zephir_array_fetch_string(&_0, params, SL("src"), PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/defaulttag.zep", 38 TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "<script type=\"text/javascript\" src=\"", _0, "\"></script>");
	return;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _css) {

	zval *params, *_0;

	zephir_fetch_params(0, 1, 0, &params);



	zephir_array_fetch_string(&_0, params, SL("link"), PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/defaulttag.zep", 43 TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "<link rel=\"stylesheet\" type=\"text/css\" href=\"", _0, "\" />");
	return;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _foreach) {

	zval *params, *content;

	zephir_fetch_params(0, 2, 0, &params, &content);




}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_DefaultTag, _list) {

	zval *params, *content, *_0, *_1;

	zephir_fetch_params(0, 2, 0, &params, &content);



	zephir_array_fetch_string(&_0, params, SL("data"), PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/defaulttag.zep", 54 TSRMLS_CC);
	zephir_array_fetch_string(&_1, params, SL("item"), PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/defaulttag.zep", 54 TSRMLS_CC);
	ZEPHIR_CONCAT_SVSVSVS(return_value, "<?php foreach(", _0, " as  ", _1, "): ?>", content, "<?php endforeach;?>");
	return;

}

zend_object_value zephir_init_properties_Vii_Mvc_View_Engine_Tiny_DefaultTag(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3, *_2$$3 = NULL;
	zval *_0;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("tags"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 7, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_2$$3);
			zephir_create_array(_2$$3, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("attr"), SL(""), 1);
			add_assoc_long_ex(_2$$3, SS("block"), 0);
			zephir_array_update_string(&_1$$3, SL("else"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2$$3);
			zephir_create_array(_2$$3, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("attr"), SL("condition"), 1);
			add_assoc_long_ex(_2$$3, SS("block"), 0);
			zephir_array_update_string(&_1$$3, SL("elseif"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2$$3);
			zephir_create_array(_2$$3, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("attr"), SL("like"), 1);
			add_assoc_long_ex(_2$$3, SS("block"), 1);
			zephir_array_update_string(&_1$$3, SL("php"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2$$3);
			zephir_create_array(_2$$3, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("attr"), SL("condition"), 1);
			add_assoc_long_ex(_2$$3, SS("block"), 1);
			add_assoc_long_ex(_2$$3, SS("level"), 2);
			zephir_array_update_string(&_1$$3, SL("if"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2$$3);
			zephir_create_array(_2$$3, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("attr"), SL("item,value,key"), 1);
			add_assoc_long_ex(_2$$3, SS("block"), 1);
			add_assoc_long_ex(_2$$3, SS("level"), 2);
			zephir_array_update_string(&_1$$3, SL("foreach"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2$$3);
			zephir_create_array(_2$$3, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("attr"), SL("data,item"), 1);
			add_assoc_long_ex(_2$$3, SS("block"), 1);
			zephir_array_update_string(&_1$$3, SL("list"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_2$$3);
			zephir_create_array(_2$$3, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_2$$3, SS("attr"), SL("src"), 1);
			add_assoc_long_ex(_2$$3, SS("block"), 0);
			zephir_array_update_string(&_1$$3, SL("js"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_update_property_this(this_ptr, SL("tags"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

