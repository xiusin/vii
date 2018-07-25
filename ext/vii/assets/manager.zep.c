
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Vii_Assets_Manager) {

	ZEPHIR_REGISTER_CLASS(Vii\\Assets, Manager, vii, assets_manager, vii_assets_manager_method_entry, 0);

	zend_declare_property_null(vii_assets_manager_ce, SL("collection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_assets_manager_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	vii_assets_manager_ce->create_object = zephir_init_properties_Vii_Assets_Manager;
	return SUCCESS;

}

PHP_METHOD(Vii_Assets_Manager, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, prefix_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = &prefix_sub;
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "");
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "css");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "collection", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_0, "setprefix", NULL, 0, prefix);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "css");
	zephir_update_property_array(this_ptr, SL("collection"), &_1, &_2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "js");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "collection", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_2, "setprefix", NULL, 0, prefix);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "js");
	zephir_update_property_array(this_ptr, SL("collection"), &_3, &_4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Assets_Manager, setOptions) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Assets_Manager, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "options");

}

PHP_METHOD(Vii_Assets_Manager, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, *collection, collection_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id, &collection);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hascollection", NULL, 0, id);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, vii_exceptions_assetsexception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "the collection key ", id, " is exists");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "vii/assets/manager.zep", 27 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("collection"), id, collection TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Manager, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, _0, _3, _4, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hascollection", NULL, 0, id);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, vii_exceptions_assetsexception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "the collection key ", id, " is not exists");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "vii/assets/manager.zep", 36 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("collection"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, id, PH_NOISY | PH_READONLY, "vii/assets/manager.zep", 38 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

PHP_METHOD(Vii_Assets_Manager, addCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, *local = NULL, local_sub, __$true, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&local_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path, &local);

	if (!local) {
		local = &local_sub;
		local = &__$true;
	}


	zephir_read_property(&_0, this_ptr, SL("collection"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("css"), PH_NOISY | PH_READONLY, "vii/assets/manager.zep", 44 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, vii_assets_resources_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "css");
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 22, &_3, path, local);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "add", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Manager, addJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, *local = NULL, local_sub, __$true, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&local_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path, &local);

	if (!local) {
		local = &local_sub;
		local = &__$true;
	}


	zephir_read_property(&_0, this_ptr, SL("collection"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("js"), PH_NOISY | PH_READONLY, "vii/assets/manager.zep", 50 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, vii_assets_resources_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "js");
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 22, &_3, path, local);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "add", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Manager, addInlineCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content, content_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	zephir_read_property(&_0, this_ptr, SL("collection"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("css"), PH_NOISY | PH_READONLY, "vii/assets/manager.zep", 56 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &_1, "addinlinecss", NULL, 0, content);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Manager, addInlineJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content, content_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	zephir_read_property(&_0, this_ptr, SL("collection"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("js"), PH_NOISY | PH_READONLY, "vii/assets/manager.zep", 62 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &_1, "addinlinejs", NULL, 0, content);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Manager, addResource) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resources, resources_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resources_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resources);



	zephir_read_property(&_0, this_ptr, SL("collection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CALL_METHOD(&_3, resources, "gettype", NULL, 0);
	zephir_check_call_status();
	zephir_fast_strtolower(&_2, &_3);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "vii/assets/manager.zep", 68 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &_1, "addresource", NULL, 0, resources);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Manager, collection) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _0, _2, _3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	if (!(zephir_is_true(name))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_assetsexception_ce, "the collection name is empty", "vii/assets/manager.zep", 81);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hascollection", NULL, 0, name);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, vii_assets_collection_ce);
		if (zephir_has_constructor(&_1$$4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("collection"), name, &_1$$4 TSRMLS_CC);
	}
	zephir_read_property(&_2, this_ptr, SL("collection"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, name, PH_NOISY | PH_READONLY, "vii/assets/manager.zep", 86 TSRMLS_CC);
	RETURN_CTOR(&_3);

}

PHP_METHOD(Vii_Assets_Manager, hasCollection) {

	zval *name, name_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &name);



	zephir_read_property(&_0, this_ptr, SL("collection"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, name));

}

PHP_METHOD(Vii_Assets_Manager, getCss) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "css");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "collection", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Assets_Manager, getJs) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "js");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "collection", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Assets_Manager, output) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName = NULL, collectionName_sub, *type = NULL, type_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName_sub);
	ZVAL_UNDEF(&type_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &collectionName, &type);

	if (!collectionName) {
		collectionName = &collectionName_sub;
		ZEPHIR_INIT_VAR(collectionName);
		ZVAL_STRING(collectionName, "");
	}
	if (!type) {
		type = &type_sub;
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "");
	}


	_0 = ZEPHIR_IS_STRING(type, "css");
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(type);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputcss", NULL, 0, collectionName);
		zephir_check_call_status();
	}
	_1 = ZEPHIR_IS_STRING(type, "js");
	if (!(_1)) {
		_1 = ZEPHIR_IS_EMPTY(type);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputjs", NULL, 0, collectionName);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Assets_Manager, outputinline) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName = NULL, collectionName_sub, *type = NULL, type_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName_sub);
	ZVAL_UNDEF(&type_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &collectionName, &type);

	if (!collectionName) {
		collectionName = &collectionName_sub;
		ZEPHIR_INIT_VAR(collectionName);
		ZVAL_STRING(collectionName, "");
	}
	if (!type) {
		type = &type_sub;
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "");
	}


	_0 = ZEPHIR_IS_STRING(type, "css");
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(type);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputinlinecss", NULL, 0, collectionName);
		zephir_check_call_status();
	}
	_1 = ZEPHIR_IS_STRING(type, "js");
	if (!(_1)) {
		_1 = ZEPHIR_IS_EMPTY(type);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputinlinejs", NULL, 0, collectionName);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Assets_Manager, outputCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName = NULL, collectionName_sub, collection, v, prefix, res, _0, _1, *_2, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName);

	if (!collectionName) {
		collectionName = &collectionName_sub;
		ZEPHIR_INIT_VAR(collectionName);
		ZVAL_STRING(collectionName, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(collectionName)) {
		ZEPHIR_CPY_WRT(&_0, collectionName);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "css");
	}
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "collection", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&prefix, &collection, "getprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&res, &collection, "getresources", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &res, SL("css"), PH_NOISY | PH_READONLY, "vii/assets/manager.zep", 130 TSRMLS_CC);
	zephir_is_iterable(&_1, 0, "vii/assets/manager.zep", 133);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
	{
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _2);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "/");
		zephir_fast_trim(&_3$$3, &prefix, &_4$$3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZEPHIR_CALL_METHOD(&_6$$3, &v, "getpath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "/");
		zephir_fast_trim(&_5$$3, &_6$$3, &_7$$3, ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_8$$3);
		ZEPHIR_CONCAT_SVSVSS(&_8$$3, "<link rel=\"stylesheet\" type=\"text/css\" href=\"", &_3$$3, "/", &_5$$3, "\">", "\r\n");
		zend_print_zval(&_8$$3, 0);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Assets_Manager, outputInlineCss) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName = NULL, collectionName_sub, v, collection, _0, res, _1, *_2, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName_sub);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName);

	if (!collectionName) {
		collectionName = &collectionName_sub;
		ZEPHIR_INIT_VAR(collectionName);
		ZVAL_STRING(collectionName, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(collectionName)) {
		ZEPHIR_CPY_WRT(&_0, collectionName);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "css");
	}
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "collection", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "css");
	ZEPHIR_CALL_METHOD(&res, &collection, "getinline", NULL, 0, &_1);
	zephir_check_call_status();
	php_printf("%s", "<style>");
	zephir_is_iterable(&res, 0, "vii/assets/manager.zep", 144);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&res), _2)
	{
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _2);
		ZEPHIR_CALL_METHOD(&_3$$3, &v, "getcontent", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(&_3$$3, 0);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	php_printf("%s", "</style>\r\n");
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Assets_Manager, outputJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName = NULL, collectionName_sub, v, collection, _0, prefix, res, *_1, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName_sub);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName);

	if (!collectionName) {
		collectionName = &collectionName_sub;
		ZEPHIR_INIT_VAR(collectionName);
		ZVAL_STRING(collectionName, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(collectionName)) {
		ZEPHIR_CPY_WRT(&_0, collectionName);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "js");
	}
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "collection", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&prefix, &collection, "getprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&res, &collection, "getjs", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&res, 0, "vii/assets/manager.zep", 156);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&res), _1)
	{
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _1);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "/");
		zephir_fast_trim(&_2$$3, &prefix, &_3$$3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZEPHIR_CALL_METHOD(&_5$$3, &v, "getpath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "/");
		zephir_fast_trim(&_4$$3, &_5$$3, &_6$$3, ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_7$$3);
		ZEPHIR_CONCAT_SVSVSS(&_7$$3, "<script type=\"text/javascript\" src=\"", &_2$$3, "/", &_4$$3, "\"></script>", "\r\n");
		zend_print_zval(&_7$$3, 0);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Assets_Manager, outputInlineJs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collectionName = NULL, collectionName_sub, v, collection, _0, res, _1, *_2, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collectionName_sub);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collectionName);

	if (!collectionName) {
		collectionName = &collectionName_sub;
		ZEPHIR_INIT_VAR(collectionName);
		ZVAL_STRING(collectionName, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(collectionName)) {
		ZEPHIR_CPY_WRT(&_0, collectionName);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "js");
	}
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "collection", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "js");
	ZEPHIR_CALL_METHOD(&res, &collection, "getinline", NULL, 0, &_1);
	zephir_check_call_status();
	php_printf("%s", "<script>");
	zephir_is_iterable(&res, 0, "vii/assets/manager.zep", 167);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&res), _2)
	{
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _2);
		ZEPHIR_CALL_METHOD(&_3$$3, &v, "getcontent", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(&_3$$3, 0);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	php_printf("%s", "</script>\r\n");
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Assets_Manager, getCollections) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "collection");

}

zend_object *zephir_init_properties_Vii_Assets_Manager(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("collection"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("collection"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

