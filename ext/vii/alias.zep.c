
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Vii_Alias) {

	ZEPHIR_REGISTER_CLASS(Vii, Alias, vii, alias, vii_alias_method_entry, 0);

	zend_declare_property_null(vii_alias_ce, SL("_aliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	vii_alias_ce->create_object = zephir_init_properties_Vii_Alias;
	return SUCCESS;

}

/**
 * 设置别名变量
 * @param string name 别名称
 * @param string value 别名值
 * @return void
 */
PHP_METHOD(Vii_Alias, set) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value;
	zval *name, name_sub, *value_param = NULL, k, v, *_0$$3, _4$$5, _5$$7, _6$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &value_param);

	if (!value_param) {
		ZEPHIR_INIT_VAR(&value);
		ZVAL_STRING(&value, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(value_param) != IS_STRING && Z_TYPE_P(value_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(value_param) == IS_STRING)) {
		zephir_get_strval(&value, value_param);
	} else {
		ZEPHIR_INIT_VAR(&value);
		ZVAL_EMPTY_STRING(&value);
	}
	}


	if (Z_TYPE_P(name) == IS_ARRAY) {
		zephir_is_iterable(name, 0, "vii/alias.zep", 18);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(name), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&k, _2$$3);
			} else {
				ZVAL_LONG(&k, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _0$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 19, &k, &v);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
	} else {
		if (!(zephir_start_with_str(name, SL("@")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Alias::set 别名必须以 '@' 开始", "vii/alias.zep", 20);
			return;
		}
		ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "has", NULL, 0, name);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$5)) {
			ZEPHIR_INIT_VAR(&_5$$7);
			object_init_ex(&_5$$7, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(&_6$$7);
			ZEPHIR_CONCAT_SVS(&_6$$7, "别名: ", name, " 已经存在");
			ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", NULL, 3, &_6$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$7, "vii/alias.zep", 24 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_array(this_ptr, SL("_aliases"), name, &value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Alias, has) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("_aliases"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Vii_Alias, resolve) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1, _2, pathinfo, alias, _3, _6, _7, _4$$4, _5$$4;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&pathinfo);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	if (!(zephir_start_with_str(&path, SL("@")))) {
		RETURN_CTOR(&path);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 20, &path, &_0, &_1);
	zephir_check_call_status();
	zephir_get_strval(&path, &_2);
	ZEPHIR_INIT_VAR(&pathinfo);
	zephir_fast_explode_str(&pathinfo, SL("/"), &path, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(&alias);
	zephir_array_fetch_long(&alias, &pathinfo, 0, PH_NOISY, "vii/alias.zep", 44 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "has", NULL, 0, &alias);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "Alias::resolve 别名:", &alias, " 没有被设置");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 3, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "vii/alias.zep", 46 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	zephir_read_property(&_6, this_ptr, SL("_aliases"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_7, &_6, &alias, PH_NOISY | PH_READONLY, "vii/alias.zep", 49 TSRMLS_CC);
	zephir_fast_str_replace(&_0, &alias, &_7, &path TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resolve", NULL, 21, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Vii_Alias(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_aliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_aliases"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

