
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
#include "ext/spl/spl_iterators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * 全局可用注册类库,不共享实例
 */
ZEPHIR_INIT_CLASS(Vii_Registry) {

	ZEPHIR_REGISTER_CLASS(Vii, Registry, vii, registry, vii_registry_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(vii_registry_ce, SL("_data"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(vii_registry_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(vii_registry_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(vii_registry_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

PHP_METHOD(Vii_Registry, __construct) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("_data"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Registry, offsetExists) {

	zval *offset, offset_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &offset);



	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, offset));

}

PHP_METHOD(Vii_Registry, offsetGet) {

	zval *offset, offset_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params(0, 1, 0, &offset);



	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, offset, PH_NOISY | PH_READONLY, "vii/registry.zep", 18 TSRMLS_CC);
	RETURN_CTORW(&_1);

}

PHP_METHOD(Vii_Registry, offsetSet) {

	zval *offset, offset_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params(0, 2, 0, &offset, &value);



	zephir_update_property_array(this_ptr, SL("_data"), offset, value TSRMLS_CC);

}

PHP_METHOD(Vii_Registry, offsetUnset) {

	zval *offset, offset_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &offset);



	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, offset, PH_SEPARATE);

}

PHP_METHOD(Vii_Registry, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

PHP_METHOD(Vii_Registry, current) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("current", NULL, 36, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Registry, key) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("key", NULL, 35, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Registry, next) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&_0);
	ZEPHIR_RETURN_CALL_FUNCTION("next", NULL, 133, &_0);
	ZEPHIR_UNREF(&_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Registry, rewind) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&_0);
	ZEPHIR_RETURN_CALL_FUNCTION("reset", NULL, 134, &_0);
	ZEPHIR_UNREF(&_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Registry, valid) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "key", NULL, 35, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(&_1) != IS_NULL);

}

