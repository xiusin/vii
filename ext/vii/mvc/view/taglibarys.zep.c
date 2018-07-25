
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_View_Taglibarys) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc\\View, Taglibarys, vii, mvc_view_taglibarys, vii_mvc_view_taglibarys_method_entry, 0);

	zend_declare_property_string(vii_mvc_view_taglibarys_ce, SL("left_delimiter"), "{", ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(vii_mvc_view_taglibarys_ce, SL("right_delimiter"), "}", ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_taglibarys_ce, SL("tags"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(vii_mvc_view_taglibarys_ce, SL("current_tag"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_taglibarys_ce, SL("tpl"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_mvc_view_taglibarys_ce, SL("service"), ZEND_ACC_PRIVATE TSRMLS_CC);

	vii_mvc_view_taglibarys_ce->create_object = zephir_init_properties_Vii_Mvc_View_Taglibarys;
	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_View_Taglibarys, __construct) {

	


}

PHP_METHOD(Vii_Mvc_View_Taglibarys, checkAttr) {

	HashTable *_11;
	HashPosition _10;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *attr, *currtag, *tagAttr = NULL, *v = NULL, *_0, *_2, *_3, *_6, *_7, *_8, *_9 = NULL, **_12, *_4$$3, *_5$$3, *_13$$5 = NULL, *_14$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attr, &currtag);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tags"), PH_NOISY_CC);
	_1 = !(zephir_array_isset(_0, currtag));
	if (!(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("tags"), PH_NOISY_CC);
		zephir_array_fetch(&_3, _2, currtag, PH_READONLY, "vii/mvc/view/taglibarys.zep", 18 TSRMLS_CC);
		_1 = !(zephir_array_isset_string(_3, SS("attr")));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SVS(_5$$3, "tag ", currtag, " is not fully defined");
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 4, _5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "vii/mvc/view/taglibarys.zep", 19 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("tags"), PH_NOISY_CC);
	zephir_array_fetch(&_7, _6, currtag, PH_NOISY | PH_READONLY, "vii/mvc/view/taglibarys.zep", 21 TSRMLS_CC);
	zephir_array_fetch_string(&_8, _7, SL("attr"), PH_NOISY | PH_READONLY, "vii/mvc/view/taglibarys.zep", 21 TSRMLS_CC);
	ZEPHIR_INIT_VAR(tagAttr);
	zephir_fast_explode_str(tagAttr, SL(","), _8, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	zephir_is_iterable(tagAttr, &_11, &_10, 0, 0, "vii/mvc/view/taglibarys.zep", 27);
	for (
	  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
	  ; zephir_hash_move_forward_ex(_11, &_10)
	) {
		ZEPHIR_GET_HMKEY(_9, _11, _10);
		ZEPHIR_GET_HVALUE(v, _12);
		if (!(zephir_fast_in_array(v, attr TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_13$$5);
			object_init_ex(_13$$5, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_LNVAR(_14$$5);
			ZEPHIR_CONCAT_SVSV(_14$$5, "tag ", currtag, " is not support attr:", v);
			ZEPHIR_CALL_METHOD(NULL, _13$$5, "__construct", NULL, 4, _14$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_13$$5, "vii/mvc/view/taglibarys.zep", 24 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_THIS();

}

PHP_METHOD(Vii_Mvc_View_Taglibarys, parse) {

	zval *_13$$4 = NULL, *_24$$7 = NULL;
	zend_bool _5$$3, _7$$3, _8$$3, _21$$6;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS, _22$$6;
	zephir_fcall_cache_entry *_16 = NULL;
	zval *content = NULL, *content_param = NULL, *tags = NULL, *key = NULL, *value = NULL, *_function = NULL, *param_attr = NULL, *arr = NULL, *attrs = NULL, *attr_str = NULL, *preg = NULL, *level = NULL, *_0, **_3, *_4$$3 = NULL, *_6$$3, *_9$$3 = NULL, *_10$$4 = NULL, *_11$$4 = NULL, *_12$$4 = NULL, *_14$$4 = NULL, *_15$$4 = NULL, *_17$$6 = NULL, *_18$$6 = NULL, *_19$$6 = NULL, *_20$$6 = NULL, *i$$6 = NULL, *_23$$6 = NULL, *_25$$7 = NULL, *_26$$7 = NULL;

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


	ZEPHIR_INIT_VAR(tags);
	array_init(tags);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tags"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(tags, _0);
	zephir_is_iterable(tags, &_2, &_1, 0, 0, "vii/mvc/view/taglibarys.zep", 58);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		ZEPHIR_INIT_NVAR(_function);
		ZEPHIR_CONCAT_SV(_function, "_", key);
		ZEPHIR_INIT_NVAR(param_attr);
		ZVAL_STRING(param_attr, "", 1);
		ZEPHIR_INIT_NVAR(arr);
		array_init(arr);
		ZEPHIR_INIT_NVAR(attrs);
		array_init(attrs);
		ZEPHIR_OBS_NVAR(_4$$3);
		zephir_read_static_property_ce(&_4$$3, vii_mvc_view_taglibarys_ce, SL("right_delimiter") TSRMLS_CC);
		ZEPHIR_INIT_NVAR(attr_str);
		ZEPHIR_CONCAT_SVS(attr_str, "[^\\", _4$$3, "]*");
		_5$$3 = zephir_array_isset_string(value, SS("block"));
		if (_5$$3) {
			zephir_array_fetch_string(&_6$$3, value, SL("block"), PH_NOISY | PH_READONLY, "vii/mvc/view/taglibarys.zep", 41 TSRMLS_CC);
			_5$$3 = !zephir_is_true(_6$$3);
		}
		_7$$3 = !(zephir_array_isset_string(value, SS("block")));
		if (!(_7$$3)) {
			_8$$3 = zephir_array_isset_string(value, SS("block"));
			if (_8$$3) {
				ZEPHIR_OBS_NVAR(_9$$3);
				zephir_array_fetch_string(&_9$$3, value, SL("block"), PH_NOISY, "vii/mvc/view/taglibarys.zep", 48 TSRMLS_CC);
				_8$$3 = zephir_is_true(_9$$3);
			}
			_7$$3 = _8$$3;
		}
		if (_5$$3) {
			zephir_update_property_this(this_ptr, SL("current_tag"), key TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_10$$4);
			zephir_read_static_property_ce(&_10$$4, vii_mvc_view_taglibarys_ce, SL("left_delimiter") TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_11$$4);
			zephir_read_static_property_ce(&_11$$4, vii_mvc_view_taglibarys_ce, SL("right_delimiter") TSRMLS_CC);
			ZEPHIR_INIT_NVAR(preg);
			ZEPHIR_CONCAT_SVVSVSVS(preg, "/\\", _10$$4, key, "\\s+(", attr_str, ")\\s*\\/\\", _11$$4, "/isU");
			ZEPHIR_INIT_NVAR(_12$$4);
			zephir_preg_match(_12$$4, preg, content, arr, 0, 0 , 0  TSRMLS_CC);
			if (!zephir_is_true(_12$$4)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(_13$$4);
			zephir_create_array(_13$$4, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_13$$4, this_ptr);
			ZEPHIR_INIT_NVAR(_14$$4);
			ZVAL_STRING(_14$$4, "callback", 1);
			zephir_array_fast_append(_13$$4, _14$$4);
			ZEPHIR_CALL_FUNCTION(&_15$$4, "preg_replace_callback", &_16, 5, preg, _13$$4, content);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(content, _15$$4);
		} else if (_7$$3) {
			if (zephir_array_isset_string(value, SS("level"))) {
				ZEPHIR_OBS_NVAR(level);
				zephir_array_fetch_string(&level, value, SL("level"), PH_NOISY, "vii/mvc/view/taglibarys.zep", 49 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(level);
				ZVAL_LONG(level, 1);
			}
			ZEPHIR_OBS_NVAR(_17$$6);
			zephir_read_static_property_ce(&_17$$6, vii_mvc_view_taglibarys_ce, SL("left_delimiter") TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_18$$6);
			zephir_read_static_property_ce(&_18$$6, vii_mvc_view_taglibarys_ce, SL("right_delimiter") TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_19$$6);
			zephir_read_static_property_ce(&_19$$6, vii_mvc_view_taglibarys_ce, SL("left_delimiter") TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_20$$6);
			zephir_read_static_property_ce(&_20$$6, vii_mvc_view_taglibarys_ce, SL("right_delimiter") TSRMLS_CC);
			ZEPHIR_INIT_NVAR(preg);
			ZEPHIR_CONCAT_SVVSVSVSVSVSVS(preg, "/\\", _17$$6, key, "\\s+(", attr_str, ")\\", _18$$6, "(.*?)\\", _19$$6, "\\/", key, "\\", _20$$6, "/is");
			zephir_update_property_this(this_ptr, SL("current_tag"), key TSRMLS_CC);
			ZEPHIR_CPY_WRT(_23$$6, level);
			_22$$6 = 0;
			_21$$6 = 0;
			if (ZEPHIR_GE_LONG(_23$$6, _22$$6)) {
				while (1) {
					if (_21$$6) {
						_22$$6++;
						if (!(ZEPHIR_GE_LONG(_23$$6, _22$$6))) {
							break;
						}
					} else {
						_21$$6 = 1;
					}
					ZEPHIR_INIT_NVAR(i$$6);
					ZVAL_LONG(i$$6, _22$$6);
					ZEPHIR_INIT_NVAR(_24$$7);
					zephir_create_array(_24$$7, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_24$$7, this_ptr);
					ZEPHIR_INIT_NVAR(_25$$7);
					ZVAL_STRING(_25$$7, "callback", 1);
					zephir_array_fast_append(_24$$7, _25$$7);
					ZEPHIR_CALL_FUNCTION(&_26$$7, "preg_replace_callback", &_16, 5, preg, _24$$7, content);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(content, _26$$7);
				}
			}
		}
	}
	RETURN_CCTOR(content);

}

PHP_METHOD(Vii_Mvc_View_Taglibarys, _attr) {

	zval *_7 = NULL;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *param_attr_param = NULL, *xml = NULL, *_array = NULL, *_2, *_5, *_6 = NULL, *_8, *_3$$4;
	zval *param_attr = NULL, *_0, *_4$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &param_attr_param);

	if (unlikely(Z_TYPE_P(param_attr_param) != IS_STRING && Z_TYPE_P(param_attr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'param_attr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(param_attr_param) == IS_STRING)) {
		zephir_get_strval(param_attr, param_attr_param);
	} else {
		ZEPHIR_INIT_VAR(param_attr);
		ZVAL_EMPTY_STRING(param_attr);
	}


	if (ZEPHIR_IS_STRING(param_attr, "")) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "<tpl><tag ", param_attr, "/></tpl>");
	ZEPHIR_CALL_FUNCTION(&xml, "simplexml_load_string", NULL, 6, _0);
	zephir_check_call_status();
	_1 = Z_TYPE_P(xml) != IS_OBJECT;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, xml, SL("tag"), PH_NOISY_CC);
		_1 = Z_TYPE_P(_2) != IS_OBJECT;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_3$$4);
		object_init_ex(_3$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_CONCAT_SV(_4$$4, "XML标签属性错误,", param_attr);
		ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", NULL, 4, _4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$4, "vii/mvc/view/taglibarys.zep", 69 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property(&_5, xml, SL("tag"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_6, _5, "attributes", NULL, 0);
	zephir_check_call_status();
	zephir_get_arrval(_7, _6);
	ZEPHIR_CPY_WRT(xml, _7);
	zephir_array_fetch_string(&_8, xml, SL("@attributes"), PH_NOISY | PH_READONLY, "vii/mvc/view/taglibarys.zep", 72 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_array, "array_change_key_case", NULL, 7, _8);
	zephir_check_call_status();
	RETURN_CCTOR(_array);

}

PHP_METHOD(Vii_Mvc_View_Taglibarys, callback) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arr_param = NULL, *_function = NULL, *param_attr = NULL, *param_content = NULL, *attrs = NULL, *attr_key = NULL, *_0, *_3 = NULL, *_4, *_1$$4, *_2$$4;
	zval *arr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arr_param);

	arr = arr_param;


	if (zephir_fast_count_int(arr TSRMLS_CC) == 0) {
		RETURN_MM_STRING("", 1);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("current_tag"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_function);
	ZEPHIR_CONCAT_SV(_function, "_", _0);
	ZEPHIR_OBS_VAR(param_attr);
	zephir_array_fetch_long(&param_attr, arr, 1, PH_NOISY, "vii/mvc/view/taglibarys.zep", 83 TSRMLS_CC);
	if (!(zephir_array_isset_long(arr, 2))) {
		ZEPHIR_INIT_VAR(param_content);
		ZVAL_STRING(param_content, "", 1);
	} else {
		ZEPHIR_OBS_NVAR(param_content);
		zephir_array_fetch_long(&param_content, arr, 2, PH_NOISY, "vii/mvc/view/taglibarys.zep", 84 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&attrs, this_ptr, "_attr", NULL, 8, param_attr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(attr_key);
	zephir_array_keys(attr_key, attrs TSRMLS_CC);
	if (!((zephir_method_exists(this_ptr, _function TSRMLS_CC)  == SUCCESS))) {
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SVS(_2$$4, "tag function ", _function, "not exists");
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 4, _2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$4, "vii/mvc/view/taglibarys.zep", 88 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("current_tag"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "checkattr", NULL, 0, attr_key, _4);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(_3, _function, NULL, 0, attrs, param_content);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object_value zephir_init_properties_Vii_Mvc_View_Taglibarys(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("tags"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("tags"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

