
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
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_Model_Resultset) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc\\Model, Resultset, vii, mvc_model_resultset, vii_mvc_model_resultset_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Vii_Mvc_Model_Resultset, __construct) {

	zval *model = NULL, model_sub, __$null;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&model_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &model);

	if (!model) {
		model = &model_sub;
		model = &__$null;
	}



}

