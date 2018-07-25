
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
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Vii_Assets_Inlines) {

	ZEPHIR_REGISTER_CLASS(Vii\\Assets, Inlines, vii, assets_inlines, vii_assets_inlines_method_entry, 0);

	zend_declare_property_null(vii_assets_inlines_ce, SL("type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_assets_inlines_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Vii_Assets_Inlines, getType) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "type");

}

PHP_METHOD(Vii_Assets_Inlines, getContent) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "content");

}

PHP_METHOD(Vii_Assets_Inlines, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type, type_sub, *content, content_sub, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type, &content);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "settype", NULL, 0, type);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "setcontent", NULL, 0, content);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Assets_Inlines, setType) {

	zval *type, type_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&type_sub);

	zephir_fetch_params(0, 1, 0, &type);



	zephir_update_property_zval(this_ptr, SL("type"), type);
	RETURN_THISW();

}

PHP_METHOD(Vii_Assets_Inlines, setContent) {

	zval *content, content_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&content_sub);

	zephir_fetch_params(0, 1, 0, &content);



	zephir_update_property_zval(this_ptr, SL("content"), content);
	RETURN_THISW();

}

