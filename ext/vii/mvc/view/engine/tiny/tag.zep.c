
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


ZEPHIR_INIT_CLASS(Vii_Mvc_View_Engine_Tiny_Tag) {

	ZEPHIR_REGISTER_CLASS_EX(Vii\\Mvc\\View\\Engine\\Tiny, Tag, vii, mvc_view_engine_tiny_tag, vii_mvc_view_engine_tiny_taglibarys_ce, vii_mvc_view_engine_tiny_tag_method_entry, 0);

	zend_declare_property_null(vii_mvc_view_engine_tiny_tag_ce, SL("tags"), ZEND_ACC_PUBLIC TSRMLS_CC);

	vii_mvc_view_engine_tiny_tag_ce->create_object = zephir_init_properties_Vii_Mvc_View_Engine_Tiny_Tag;
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _php) {

	zval *params, params_sub, *content, content_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&content_sub);

	zephir_fetch_params(0, 2, 0, &params, &content);



	ZEPHIR_CONCAT_SVS(return_value, "<?php ", content, "?>");
	return;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _if) {

	zval *params, params_sub, *content = NULL, content_sub, __$null, condition, str;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&condition);
	ZVAL_UNDEF(&str);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params, &content);

	if (!content) {
		content = &content_sub;
		content = &__$null;
	}


	if (zephir_array_isset_string(params, SL("condition"))) {
		ZEPHIR_OBS_VAR(&condition);
		zephir_array_fetch_string(&condition, params, SL("condition"), PH_NOISY, "vii/mvc/view/engine/tiny/tag.zep", 22 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&condition);
		ZVAL_BOOL(&condition, 0);
	}
	if (zephir_is_true(&condition)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "if标签内必须有condition属性", "vii/mvc/view/engine/tiny/tag.zep", 24);
		return;
	}
	ZEPHIR_INIT_VAR(&str);
	ZEPHIR_CONCAT_SVSVS(&str, "<?php if(", &condition, ") : ?>", content, "<?php endif; ?>");
	RETURN_CCTOR(str);

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _else) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_STRING("<?php  else:  ?>");

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _js) {

	zval *params, params_sub, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &params);



	zephir_array_fetch_string(&_0, params, SL("src"), PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/tag.zep", 37 TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "<script type=\"text/javascript\" src=\"", &_0, "\"></script>");
	return;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _css) {

	zval *params, params_sub, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &params);



	zephir_array_fetch_string(&_0, params, SL("link"), PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/tag.zep", 42 TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "<link rel=\"stylesheet\" type=\"text/css\" href=\"", &_0, "\" />");
	return;

}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _foreach) {

	zval *params, params_sub, *content, content_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&content_sub);

	zephir_fetch_params(0, 2, 0, &params, &content);




}

PHP_METHOD(Vii_Mvc_View_Engine_Tiny_Tag, _list) {

	zval *params, params_sub, *content, content_sub, _0, _1;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params(0, 2, 0, &params, &content);



	zephir_array_fetch_string(&_0, params, SL("data"), PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/tag.zep", 53 TSRMLS_CC);
	zephir_array_fetch_string(&_1, params, SL("item"), PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/tag.zep", 53 TSRMLS_CC);
	ZEPHIR_CONCAT_SVSVSVS(return_value, "<?php foreach(", &_0, " as  ", &_1, "): ?>", content, "<?php endforeach;?>");
	return;

}

static zend_object *zephir_init_properties_Vii_Mvc_View_Engine_Tiny_Tag(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3, _2$$3;
	zval _0;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("tags"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 7, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_create_array(&_2$$3, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("attr"), SL(""));
			add_assoc_long_ex(&_2$$3, SL("block"), 0);
			zephir_array_update_string(&_1$$3, SL("else"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("attr"), SL("condition"));
			add_assoc_long_ex(&_2$$3, SL("block"), 0);
			zephir_array_update_string(&_1$$3, SL("elseif"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("attr"), SL("like"));
			add_assoc_long_ex(&_2$$3, SL("block"), 1);
			zephir_array_update_string(&_1$$3, SL("php"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("attr"), SL("condition"));
			add_assoc_long_ex(&_2$$3, SL("block"), 1);
			add_assoc_long_ex(&_2$$3, SL("level"), 2);
			zephir_array_update_string(&_1$$3, SL("if"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("attr"), SL("item,value,key"));
			add_assoc_long_ex(&_2$$3, SL("block"), 1);
			add_assoc_long_ex(&_2$$3, SL("level"), 2);
			zephir_array_update_string(&_1$$3, SL("foreach"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("attr"), SL("data,item"));
			add_assoc_long_ex(&_2$$3, SL("block"), 1);
			zephir_array_update_string(&_1$$3, SL("list"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_create_array(&_2$$3, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_2$$3, SL("attr"), SL("src"));
			add_assoc_long_ex(&_2$$3, SL("block"), 0);
			zephir_array_update_string(&_1$$3, SL("js"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("tags"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

