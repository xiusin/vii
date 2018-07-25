
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * 资源对象
 * Class Resources
 * @package Slothful\Assets
 */
ZEPHIR_INIT_CLASS(Vii_Assets_Resources) {

	ZEPHIR_REGISTER_CLASS(Vii\\Assets, Resources, vii, assets_resources, vii_assets_resources_method_entry, 0);

	zend_declare_property_null(vii_assets_resources_ce, SL("type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(vii_assets_resources_ce, SL("path"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(vii_assets_resources_ce, SL("local"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Resources constructor.
 * @param $type string
 * @param $path string
 * @param bool $local
 * @demo new Resource();
 */
PHP_METHOD(Vii_Assets_Resources, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type, type_sub, *path, path_sub, *local = NULL, local_sub, __$true, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&local_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &type, &path, &local);

	if (!local) {
		local = &local_sub;
		local = &__$true;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktype", NULL, 24, type);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "settype", NULL, 0, type);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "setpath", NULL, 0, path);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "setlocal", NULL, 0, local);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Assets_Resources, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

PHP_METHOD(Vii_Assets_Resources, getPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "path");

}

PHP_METHOD(Vii_Assets_Resources, getLocal) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "local");

}

PHP_METHOD(Vii_Assets_Resources, setType) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type, type_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktype", NULL, 24, type);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("type"), type);
	RETURN_THIS();

}

PHP_METHOD(Vii_Assets_Resources, setPath) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_zval(this_ptr, SL("path"), path);
	RETURN_THISW();

}

PHP_METHOD(Vii_Assets_Resources, setLocal) {

	zval *local, local_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&local_sub);

	zephir_fetch_params(0, 1, 0, &local);



	zephir_update_property_zval(this_ptr, SL("local"), local);
	RETURN_THISW();

}

PHP_METHOD(Vii_Assets_Resources, checkType) {

	zend_bool _0;
	zval *type, type_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);

	zephir_fetch_params(0, 1, 0, &type);



	_0 = !ZEPHIR_IS_STRING(type, "js");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING(type, "css");
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(vii_exceptions_assetsexception_ce, "the resource key $type is not support!", "vii/assets/resources.zep", 70);
		return;
	}

}

