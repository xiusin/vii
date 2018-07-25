
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(vii_1__closure) {

	ZEPHIR_REGISTER_CLASS(vii, 1__closure, vii, 1__closure, vii_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(vii_1__closure, __invoke) {

	zend_string *_8;
	zend_ulong _7;
	zend_bool _2, _9$$4, _16$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *match, match_sub, vars, _func, _var, arrayhtml, _default, func, str, v, size, _0, _1, _5, *_6, _11, _12, _3$$3, _4$$3, _10$$5, _13$$6, _14$$7, _15$$7, _17$$7, _18$$7, _19$$7, _20$$7, _21$$7, _22$$7, _23$$7, _24$$7, _25$$7, _26$$7, _27$$7, _28$$7, _29$$7, _30$$7, _31$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&match_sub);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&_func);
	ZVAL_UNDEF(&_var);
	ZVAL_UNDEF(&arrayhtml);
	ZVAL_UNDEF(&_default);
	ZVAL_UNDEF(&func);
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_31$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &match);



	if (zephir_array_isset_long(match, 2)) {
		ZEPHIR_OBS_VAR(&vars);
		zephir_array_fetch_long(&vars, match, 2, PH_NOISY, "vii/mvc/view/engine/tiny/compiler.zep", 94 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&vars);
		ZVAL_STRING(&vars, "");
	}
	if (zephir_array_isset_long(match, 3)) {
		zephir_array_fetch_long(&_0, match, 3, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/compiler.zep", 95 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_STRING(&_1, "|");
		ZEPHIR_INIT_VAR(&_func);
		zephir_fast_trim(&_func, &_0, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_func);
		ZVAL_STRING(&_func, "");
	}
	_2 = ZEPHIR_IS_STRING(&vars, "");
	if (_2) {
		_2 = !ZEPHIR_IS_STRING(&_func, "");
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "|");
		zephir_fast_trim(&_3$$3, &_func, &_4$$3, ZEPHIR_TRIM_LEFT TSRMLS_CC);
		ZEPHIR_CONCAT_SVS(return_value, "<?php echo ", &_3$$3, "; ?>");
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&size);
	zephir_fast_explode_str(&size, SL("."), &vars, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(&size);
	ZEPHIR_CALL_FUNCTION(&_var, "array_shift", NULL, 116, &size);
	ZEPHIR_UNREF(&size);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&arrayhtml);
	ZVAL_STRING(&arrayhtml, "");
	ZEPHIR_INIT_VAR(&_5);
	zephir_is_iterable(&size, 0, "vii/mvc/view/engine/tiny/compiler.zep", 107);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&size), _7, _8, _6)
	{
		ZEPHIR_INIT_NVAR(&_5);
		if (_8 != NULL) { 
			ZVAL_STR_COPY(&_5, _8);
		} else {
			ZVAL_LONG(&_5, _7);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _6);
		_9$$4 = ((zephir_get_intval(&v)) ? 1 : 0);
		if (!(_9$$4)) {
			_9$$4 = !ZEPHIR_IS_LONG(&v, 0);
		}
		if (_9$$4) {
			ZEPHIR_INIT_LNVAR(_10$$5);
			ZEPHIR_CONCAT_SVS(&_10$$5, "[", &v, "]");
			zephir_concat_self(&arrayhtml, &_10$$5 TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&_5);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "default=");
	ZEPHIR_INIT_VAR(&_12);
	zephir_fast_strpos(&_12, &_func, &_11, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_12)) {
		ZEPHIR_INIT_VAR(&_13$$6);
		zephir_fast_explode_str(&_13$$6, SL("="), &_func, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(&_func, &_13$$6);
		ZEPHIR_OBS_VAR(&_default);
		zephir_array_fetch_long(&_default, &_func, 1, PH_NOISY, "vii/mvc/view/engine/tiny/compiler.zep", 109 TSRMLS_CC);
		ZEPHIR_CONCAT_SVVSVSVVS(return_value, "<?php if(!isset(", &_var, &arrayhtml, ")) echo ", &_default, "; else echo ", &_var, &arrayhtml, "; ?>");
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&str);
	if (!(ZEPHIR_IS_EMPTY(&_func))) {
		ZEPHIR_INIT_VAR(&_14$$7);
		ZVAL_STRING(&_14$$7, "=");
		ZEPHIR_CALL_FUNCTION(&_15$$7, "strrpos", NULL, 43, &_func, &_14$$7);
		zephir_check_call_status();
		_16$$7 = ZEPHIR_IS_FALSE_IDENTICAL(&_15$$7);
		if (_16$$7) {
			ZEPHIR_INIT_NVAR(&_14$$7);
			ZVAL_STRING(&_14$$7, "(");
			ZEPHIR_CALL_FUNCTION(&_17$$7, "strrpos", NULL, 43, &_func, &_14$$7);
			zephir_check_call_status();
			_16$$7 = ZEPHIR_IS_FALSE_IDENTICAL(&_17$$7);
		}
		if (_16$$7) {
			ZEPHIR_INIT_VAR(&func);
			ZEPHIR_CONCAT_VS(&func, &_func, "=###");
		} else {
			ZEPHIR_CPY_WRT(&func, &_func);
		}
		ZEPHIR_INIT_VAR(&_18$$7);
		ZEPHIR_INIT_NVAR(&_14$$7);
		ZVAL_STRING(&_14$$7, "###");
		ZEPHIR_CALL_FUNCTION(&_19$$7, "strrpos", NULL, 43, &_func, &_14$$7);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_19$$7)) {
			ZEPHIR_INIT_NVAR(&_18$$7);
			ZEPHIR_CONCAT_VS(&_18$$7, &func, ",###");
		} else {
			ZEPHIR_CPY_WRT(&_18$$7, &func);
		}
		ZEPHIR_CPY_WRT(&func, &_18$$7);
		ZEPHIR_INIT_NVAR(&_14$$7);
		zephir_fast_explode_str(&_14$$7, SL("="), &func, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(&func, &_14$$7);
		ZEPHIR_INIT_NVAR(&_14$$7);
		zephir_array_fetch_long(&_20$$7, &func, 0, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/compiler.zep", 116 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_21$$7);
		ZVAL_STRING(&_21$$7, "|");
		ZEPHIR_INIT_VAR(&_22$$7);
		ZVAL_STRING(&_22$$7, "(");
		zephir_fast_str_replace(&_14$$7, &_21$$7, &_22$$7, &_20$$7 TSRMLS_CC);
		ZEPHIR_CONCAT_VS(&str, &_14$$7, "(");
		ZEPHIR_INIT_VAR(&_23$$7);
		ZEPHIR_INIT_LNVAR(_18$$7);
		ZEPHIR_CONCAT_VV(&_18$$7, &_var, &arrayhtml);
		zephir_array_fetch_long(&_24$$7, &func, 1, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/compiler.zep", 117 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_25$$7);
		ZVAL_STRING(&_25$$7, "###");
		zephir_fast_str_replace(&_23$$7, &_25$$7, &_18$$7, &_24$$7 TSRMLS_CC);
		zephir_array_fetch_long(&_26$$7, &func, 0, PH_NOISY | PH_READONLY, "vii/mvc/view/engine/tiny/compiler.zep", 117 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_27$$7);
		ZVAL_STRING(&_27$$7, "|");
		ZEPHIR_CALL_FUNCTION(&_28$$7, "substr_count", NULL, 114, &_26$$7, &_27$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_27$$7);
		ZVAL_STRING(&_27$$7, ")");
		ZVAL_LONG(&_29$$7, (zephir_get_numberval(&_28$$7) + 1));
		ZEPHIR_CALL_FUNCTION(&_30$$7, "str_repeat", NULL, 50, &_27$$7, &_29$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_31$$7);
		ZEPHIR_CONCAT_VV(&_31$$7, &_23$$7, &_30$$7);
		zephir_concat_self(&str, &_31$$7 TSRMLS_CC);
	} else {
		ZEPHIR_CONCAT_VV(&str, &_var, &arrayhtml);
	}
	ZEPHIR_CONCAT_SVS(return_value, "<?php  echo  ", &str, ";  ?>");
	RETURN_MM();

}

