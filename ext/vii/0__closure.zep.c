
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
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(vii_0__closure) {

	ZEPHIR_REGISTER_CLASS(vii, 0__closure, vii, 0__closure, vii_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(vii_0__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file, file_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);



	ZEPHIR_CALL_FUNCTION(&_0, "filetype", NULL, 71, file);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "file"));

}

