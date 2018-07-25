
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Vii_UploadFileInfo) {

	ZEPHIR_REGISTER_CLASS(Vii, UploadFileInfo, vii, uploadfileinfo, vii_uploadfileinfo_method_entry, 0);

	zend_declare_property_null(vii_uploadfileinfo_ce, SL("info"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(vii_uploadfileinfo_ce, SL("error"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	vii_uploadfileinfo_ce->create_object = zephir_init_properties_Vii_UploadFileInfo;
	return SUCCESS;

}

PHP_METHOD(Vii_UploadFileInfo, __construct) {

	zval *fileinfo, fileinfo_sub;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&fileinfo_sub);

	zephir_fetch_params(0, 1, 0, &fileinfo);



	if (!(zephir_array_isset_string(fileinfo, SL("tmp_name")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(vii_exceptions_uploadfileexception_ce, "上传文件信息传入错误", "vii/uploadfileinfo.zep", 13);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("info"), fileinfo);

}

PHP_METHOD(Vii_UploadFileInfo, isUploadFile) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("info"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("tmp_name"), PH_NOISY | PH_READONLY, "vii/uploadfileinfo.zep", 20 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("is_uploaded_file", NULL, 144, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_UploadFileInfo, hasError) {

	zval _0, _1, _2$$3, _3$$4, _4$$5, _5$$6, _6$$7, _7$$8;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("info"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_string(&_1, &_0, SL("error"), PH_NOISY, "vii/uploadfileinfo.zep", 25 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(&_1, 1)) {
			ZEPHIR_INIT_VAR(&_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "文件大小超出了服务器的空间大小");
			zephir_update_property_zval(this_ptr, SL("error"), &_2$$3);
			break;
		}
		if (ZEPHIR_IS_LONG(&_1, 2)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "文件超出了表单承载范围.");
			zephir_update_property_zval(this_ptr, SL("error"), &_3$$4);
			break;
		}
		if (ZEPHIR_IS_LONG(&_1, 3)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_INIT_NVAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "该文件只被部分上传");
			zephir_update_property_zval(this_ptr, SL("error"), &_4$$5);
			break;
		}
		if (ZEPHIR_IS_LONG(&_1, 4)) {
			ZEPHIR_INIT_VAR(&_5$$6);
			ZEPHIR_INIT_NVAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "没有找到要上传的文件");
			zephir_update_property_zval(this_ptr, SL("error"), &_5$$6);
			break;
		}
		if (ZEPHIR_IS_LONG(&_1, 5)) {
			ZEPHIR_INIT_VAR(&_6$$7);
			ZEPHIR_INIT_NVAR(&_6$$7);
			ZVAL_STRING(&_6$$7, "服务器临时文件夹丢失");
			zephir_update_property_zval(this_ptr, SL("error"), &_6$$7);
			break;
		}
		if (ZEPHIR_IS_LONG(&_1, 6)) {
			ZEPHIR_INIT_VAR(&_7$$8);
			ZEPHIR_INIT_NVAR(&_7$$8);
			ZVAL_STRING(&_7$$8, "文件写入到临时文件夹出错");
			zephir_update_property_zval(this_ptr, SL("error"), &_7$$8);
			break;
		}
		RETURN_MM_BOOL(0);
	} while(0);

	RETURN_MM_BOOL(1);

}

PHP_METHOD(Vii_UploadFileInfo, getSize) {

	zval _0, _1;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("info"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("size"), PH_NOISY | PH_READONLY, "vii/uploadfileinfo.zep", 52 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(Vii_UploadFileInfo, getName) {

	zval _0, _1;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("info"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("name"), PH_NOISY | PH_READONLY, "vii/uploadfileinfo.zep", 57 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(Vii_UploadFileInfo, getType) {

	zval _0, _1;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("info"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("type"), PH_NOISY | PH_READONLY, "vii/uploadfileinfo.zep", 62 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(Vii_UploadFileInfo, getExt) {

	zval finfo, _0;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&finfo);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&finfo);
	zephir_fast_explode_str(&finfo, SL("."), &_0, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(&finfo);
	ZEPHIR_RETURN_CALL_FUNCTION("end", NULL, 59, &finfo);
	ZEPHIR_UNREF(&finfo);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_UploadFileInfo, getTmpName) {

	zval _0, _1;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("info"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("tmp_name"), PH_NOISY | PH_READONLY, "vii/uploadfileinfo.zep", 73 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(Vii_UploadFileInfo, moveTo) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *destination_file, destination_file_sub, _1, _2, _3, _4, _5, _6;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&destination_file_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &destination_file);



	_0 = ZEPHIR_IS_EMPTY(destination_file);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "dirname", NULL, 97, destination_file);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2, "is_dir", NULL, 76, &_1);
		zephir_check_call_status();
		_0 = !zephir_is_true(&_2);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_uploadfileexception_ce, "移动临时文件到目标目录失败，原因：不存在", "vii/uploadfileinfo.zep", 79);
		return;
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "haserror", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gettmpname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "move_uploaded_file", NULL, 145, &_4, destination_file);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "移动文件失败");
	zephir_update_property_zval(this_ptr, SL("error"), &_6);
	RETURN_MM_BOOL(0);

}

static zend_object *zephir_init_properties_Vii_UploadFileInfo(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("info"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("info"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

