
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_Model_MetaData) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc\\Model, MetaData, vii, mvc_model_metadata, vii_mvc_model_metadata_method_entry, 0);

	zend_declare_property_null(vii_mvc_model_metadata_ce, SL("_oldAttr"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_model_metadata_ce, SL("_newAttr"), ZEND_ACC_PRIVATE TSRMLS_CC);

	vii_mvc_model_metadata_ce->create_object = zephir_init_properties_Vii_Mvc_Model_MetaData;
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_Model_MetaData, setOldData) {

	


}

PHP_METHOD(Vii_Mvc_Model_MetaData, setNewData) {

	


}

PHP_METHOD(Vii_Mvc_Model_MetaData, getOldData) {

	

	RETURN_MEMBER(this_ptr, "_oldAttr");

}

PHP_METHOD(Vii_Mvc_Model_MetaData, getNewData) {

	

	RETURN_MEMBER(this_ptr, "_newAttr");

}

PHP_METHOD(Vii_Mvc_Model_MetaData, getData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_0, *_1$$3, *_2$$3, *_3$$4, *_4$$5, *_5$$5, *_6$$6, *_7$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_newAttr"), PH_NOISY_CC);
	if (zephir_array_isset(_0, key)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_newAttr"), PH_NOISY_CC);
		zephir_array_fetch(&_2$$3, _1$$3, key, PH_NOISY | PH_READONLY, "vii/mvc/model/metadata.zep", 29 TSRMLS_CC);
		RETURN_CTOR(_2$$3);
	} else {
		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_oldAttr"), PH_NOISY_CC);
		if (zephir_array_isset(_3$$4, key)) {
			_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_oldAttr"), PH_NOISY_CC);
			zephir_array_fetch(&_5$$5, _4$$5, key, PH_NOISY | PH_READONLY, "vii/mvc/model/metadata.zep", 32 TSRMLS_CC);
			RETURN_CTOR(_5$$5);
		} else {
			ZEPHIR_INIT_VAR(_6$$6);
			object_init_ex(_6$$6, vii_exceptions_databaseexception_ce);
			ZEPHIR_INIT_VAR(_7$$6);
			ZEPHIR_CONCAT_SV(_7$$6, "元数据内不存在字段：", key);
			ZEPHIR_CALL_METHOD(NULL, _6$$6, "__construct", NULL, 4, _7$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$6, "vii/mvc/model/metadata.zep", 34 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}

}

zend_object_value zephir_init_properties_Vii_Mvc_Model_MetaData(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_newAttr"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_newAttr"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_oldAttr"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("_oldAttr"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

