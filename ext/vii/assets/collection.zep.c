
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Vii_Assets_Collection) {

	ZEPHIR_REGISTER_CLASS(Vii\\Assets, Collection, vii, assets_collection, vii_assets_collection_method_entry, 0);

	zend_declare_property_string(vii_assets_collection_ce, SL("prefix"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(vii_assets_collection_ce, SL("join"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(vii_assets_collection_ce, SL("local"), 1, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_assets_collection_ce, SL("css"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_assets_collection_ce, SL("js"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_assets_collection_ce, SL("_inline"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_assets_collection_ce, SL("targetPath"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_assets_collection_ce, SL("targetUri"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	vii_assets_collection_ce->create_object = zephir_init_properties_Vii_Assets_Collection;
	return SUCCESS;

}

PHP_METHOD(Vii_Assets_Collection, getPrefix) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "prefix");

}

PHP_METHOD(Vii_Assets_Collection, getLocal) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "local");

}

PHP_METHOD(Vii_Assets_Collection, getCss) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "css");

}

PHP_METHOD(Vii_Assets_Collection, getJs) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "js");

}

PHP_METHOD(Vii_Assets_Collection, getInline) {

	zval *type = NULL, type_sub, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type);

	if (!type) {
		type = &type_sub;
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "");
	}


	if (zephir_is_true(type)) {
		zephir_read_property(&_0$$3, this_ptr, SL("_inline"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_1$$3, &_0$$3, type, PH_NOISY | PH_READONLY, "vii/assets/collection.zep", 35 TSRMLS_CC);
		RETURN_CTOR(&_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "_inline");

}

PHP_METHOD(Vii_Assets_Collection, getResources) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("css"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("css"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("js"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("js"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_inline"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("inline"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(Vii_Assets_Collection, add) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_resource, _resource_sub, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_resource_sub);
	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_resource);



	ZEPHIR_CALL_METHOD(&type, _resource, "gettype", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&type, "js")) {
		zephir_update_property_array_append(this_ptr, SL("js"), _resource TSRMLS_CC);
	}
	if (ZEPHIR_IS_STRING(&type, "css")) {
		zephir_update_property_array_append(this_ptr, SL("css"), _resource TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Collection, addCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, *local = NULL, local_sub, __$true, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&local_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path, &local);

	if (!local) {
		local = &local_sub;
		local = &__$true;
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, vii_assets_resources_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "css");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 22, &_1, path, local);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("css"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Collection, addInlineCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content, content_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, vii_assets_inlines_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "css");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 23, &_1, content);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("_inline"), &_0 TSRMLS_CC, SL("sa"), 3, SL("css"));
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Collection, addJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, *local = NULL, local_sub, __$true, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&local_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path, &local);

	if (!local) {
		local = &local_sub;
		local = &__$true;
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, vii_assets_resources_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "js");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 22, &_1, path, local);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("js"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Collection, addInlineJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content, content_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, vii_assets_inlines_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "js");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 23, &_1, content);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("_inline"), &_0 TSRMLS_CC, SL("sa"), 3, SL("js"));
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Collection, setPrefix) {

	zval *prefix, prefix_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_sub);

	zephir_fetch_params(0, 1, 0, &prefix);



	zephir_update_property_zval(this_ptr, SL("prefix"), prefix);
	RETURN_THISW();

}

PHP_METHOD(Vii_Assets_Collection, setLocal) {

	zval *local, local_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&local_sub);

	zephir_fetch_params(0, 1, 0, &local);



	zephir_update_property_zval(this_ptr, SL("local"), local);
	RETURN_THISW();

}

PHP_METHOD(Vii_Assets_Collection, join) {

	zval *join, join_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&join_sub);

	zephir_fetch_params(0, 1, 0, &join);



	zephir_update_property_zval(this_ptr, SL("join"), join);
	RETURN_THISW();

}

PHP_METHOD(Vii_Assets_Collection, setTargetPath) {

	zval *targetPath, targetPath_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath_sub);

	zephir_fetch_params(0, 1, 0, &targetPath);



	zephir_update_property_zval(this_ptr, SL("targetPath"), targetPath);
	RETURN_BOOL(1);

}

PHP_METHOD(Vii_Assets_Collection, setTatgetUri) {

	zval *targetUri, targetUri_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetUri_sub);

	zephir_fetch_params(0, 1, 0, &targetUri);



	zephir_update_property_zval(this_ptr, SL("targetUri"), targetUri);
	RETURN_THISW();

}

zend_object *zephir_init_properties_Vii_Assets_Collection(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _3, _5, _2$$3, _4$$4, _6$$5;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_inline"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("css"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("js"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("_inline"), &_1$$3);
		}
		zephir_read_property(&_3, this_ptr, SL("js"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_3) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_4$$4);
			array_init(&_4$$4);
			zephir_update_property_zval(this_ptr, SL("js"), &_4$$4);
		}
		zephir_read_property(&_5, this_ptr, SL("css"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_5) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_6$$5);
			array_init(&_6$$5);
			zephir_update_property_zval(this_ptr, SL("css"), &_6$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

