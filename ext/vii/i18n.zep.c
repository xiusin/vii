
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"


/**
 * <code>
 * @创建
 * $i18n = Vii\I18n::getDefault([
 *      "lang"=>"zh",
 *      "dir"=>"app/lang/"
 * ]);
 *
 * @配置文件
 * app/lang/zh.php
 * return [
 *      "MESSAGE_ERROR"=>"消息错误",
 *      "CURR"  =>" :attr: 是替换出来的"
 * ];
 *
 * @使用
 * Vii\Httper::_t("MESSAGE_ERROR");
 * Vii\Httper::_t("CURR",['attr'=>'我是attr']);
 *
 * </code>
 */
ZEPHIR_INIT_CLASS(Vii_I18n) {

	ZEPHIR_REGISTER_CLASS(Vii, I18n, vii, i18n, vii_i18n_method_entry, 0);

	zend_declare_property_null(vii_i18n_ce, SL("i18n"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(vii_i18n_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_i18n_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	vii_i18n_ce->create_object = zephir_init_properties_Vii_I18n;
	return SUCCESS;

}

PHP_METHOD(Vii_I18n, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "setoptions", NULL, 0, options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_I18n, __clone) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	


}

PHP_METHOD(Vii_I18n, getDefault) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub, _0, _2, _1$$3;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	}


	zephir_read_static_property_ce(&_0, vii_i18n_ce, SL("i18n"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, vii_i18n_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 88, options);
		zephir_check_call_status();
		zephir_update_static_property_ce(vii_i18n_ce, SL("i18n"), &_1$$3);
	}
	zephir_read_static_property_ce(&_2, vii_i18n_ce, SL("i18n"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(_2);

}

/**
 * 获取语言配置
 */
PHP_METHOD(Vii_I18n, getMessage) {

	zend_bool _1;
	zval file, _0, _2, _3, _4, _5, _6, _7, _10, _11, _8$$4, _9$$4;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	_1 = !(zephir_array_isset_string(&_0, SL("lang")));
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3, &_2, SL("dir"), PH_NOISY | PH_READONLY, "vii/i18n.zep", 44 TSRMLS_CC);
		_1 = zephir_is_true(&_3);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有i18n对应的参数options[lang] or options[dir]", "vii/i18n.zep", 45);
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_5, &_4, SL("dir"), PH_NOISY | PH_READONLY, "vii/i18n.zep", 47 TSRMLS_CC);
	zephir_read_property(&_6, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_7, &_6, SL("lang"), PH_NOISY | PH_READONLY, "vii/i18n.zep", 47 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&file);
	ZEPHIR_CONCAT_VVS(&file, &_5, &_7, ".php");
	if (!((zephir_file_exists(&file TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_8$$4);
		object_init_ex(&_8$$4, vii_exceptions_filenotexistsexception_ce);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SVS(&_9$$4, "语言配置文件:", &file, "不存在");
		ZEPHIR_CALL_METHOD(NULL, &_8$$4, "__construct", NULL, 4, &_9$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$4, "vii/i18n.zep", 49 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_10);
	if (zephir_require_zval_ret(&_10, &file TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_update_property_zval(this_ptr, SL("_messages"), &_10);
	ZEPHIR_OBS_VAR(&_11);
	zephir_read_property(&_11, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(&_11) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "语言配置文件必须返回为数组", "vii/i18n.zep", 53);
		return;
	}
	RETURN_THIS();

}

/**
 * 设置配置参数
 */
PHP_METHOD(Vii_I18n, setOptions) {

	zval *options = NULL, options_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&options_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	}


	zephir_update_property_zval(this_ptr, SL("_options"), options);
	RETURN_THIS();

}

/**
 * 获取配置参数
 */
PHP_METHOD(Vii_I18n, getOptions) {

		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	

	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * 翻译
 * @param str string 要翻译的内容
 * @param value array 翻译内容内部占位符替换数组
 */
PHP_METHOD(Vii_I18n, translate) {

	zend_string *_4$$5;
	zend_ulong _3$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval value;
	zval *strOrId_param = NULL, *value_param = NULL, message, _0, _1$$3, k$$5, v$$5, tmp$$5, *_2$$5, _5$$6;
	zval strOrId;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&strOrId);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&k$$5);
	ZVAL_UNDEF(&v$$5);
	ZVAL_UNDEF(&tmp$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strOrId_param, &value_param);

	if (unlikely(Z_TYPE_P(strOrId_param) != IS_STRING && Z_TYPE_P(strOrId_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'strOrId' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(strOrId_param) == IS_STRING)) {
		zephir_get_strval(&strOrId, strOrId_param);
	} else {
		ZEPHIR_INIT_VAR(&strOrId);
		ZVAL_EMPTY_STRING(&strOrId);
	}
	if (!value_param) {
		ZEPHIR_INIT_VAR(&value);
		array_init(&value);
	} else {
	ZVAL_COPY_VALUE(&value, value_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_messages"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &strOrId)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_messages"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&message);
		zephir_array_fetch(&message, &_1$$3, &strOrId, PH_NOISY, "vii/i18n.zep", 79 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&message, &strOrId);
	}
	if (zephir_fast_count_int(&value TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&tmp$$5);
		array_init(&tmp$$5);
		zephir_is_iterable(&value, 0, "vii/i18n.zep", 88);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&value), _3$$5, _4$$5, _2$$5)
		{
			ZEPHIR_INIT_NVAR(&k$$5);
			if (_4$$5 != NULL) { 
				ZVAL_STR_COPY(&k$$5, _4$$5);
			} else {
				ZVAL_LONG(&k$$5, _3$$5);
			}
			ZEPHIR_INIT_NVAR(&v$$5);
			ZVAL_COPY(&v$$5, _2$$5);
			ZEPHIR_INIT_LNVAR(_5$$6);
			ZEPHIR_CONCAT_SVS(&_5$$6, ":", &k$$5, ":");
			zephir_array_update_zval(&tmp$$5, &_5$$6, &v$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v$$5);
		ZEPHIR_INIT_NVAR(&k$$5);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 21, &message, &tmp$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(message);

}

static zend_object *zephir_init_properties_Vii_I18n(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

