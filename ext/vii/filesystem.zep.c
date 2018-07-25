
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/require.h"
#include "kernel/main.h"
#include "ext/spl/spl_directory.h"


/**
 * 文件管理类库
 *
 */
ZEPHIR_INIT_CLASS(Vii_FileSystem) {

	ZEPHIR_REGISTER_CLASS(Vii, FileSystem, vii, filesystem, vii_filesystem_method_entry, 0);

	zend_declare_property_null(vii_filesystem_ce, SL("_self"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Vii_FileSystem, __construct) {

	zval _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, vii_filesystem_ce, SL("_self"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, vii_filesystem_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 64);
		zephir_check_call_status();
		zend_update_static_property(vii_filesystem_ce, ZEND_STRL("_self"), &_1$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_FileSystem, exception) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, vii_exceptions_filenotexistsexception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "file ", path, " is not exists");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 3, &_1);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "vii/filesystem.zep", 20 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Vii_FileSystem, exists) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

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


	RETURN_MM_BOOL((zephir_file_exists(&path TSRMLS_CC) == SUCCESS));

}

PHP_METHOD(Vii_FileSystem, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0, &path);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_file_get_contents(return_value, &path TSRMLS_CC);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "exception", NULL, 65, &path);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_FileSystem, requireFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1$$3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0, &path);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_1$$3);
		if (zephir_require_zval_ret(&_1$$3, &path TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_CCTOR(&_1$$3);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "exception", NULL, 65, &path);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_FileSystem, put) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *content_param = NULL, *flag = NULL, flag_sub;
	zval path, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&flag_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &path_param, &content_param, &flag);

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
	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_EMPTY_STRING(&content);
	}
	if (!flag) {
		flag = &flag_sub;
		ZEPHIR_INIT_VAR(flag);
		ZVAL_LONG(flag, 0);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 66, &path, &content, flag);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_FileSystem, prepend) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *content_param = NULL, _0, _3, _4, _5, _1$$3;
	zval path, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &content_param);

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
	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_EMPTY_STRING(&content);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0, &path);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZVAL_LONG(&_1$$3, 2);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "put", &_2, 0, &path, &content, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "get", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &content, &_3);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "put", &_2, 0, &path, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_FileSystem, delete) {

	zend_string *_3;
	zend_ulong _2;
	zend_bool success = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *paths = NULL, paths_sub, path, _0, *_1, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths_sub);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paths);

	ZEPHIR_SEPARATE_PARAM(paths);


	success = 1;
	if (Z_TYPE_P(paths) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(paths);
		zephir_get_args(paths);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_is_iterable(paths, 0, "vii/filesystem.zep", 65);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(paths), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&_0);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&_0, _3);
		} else {
			ZVAL_LONG(&_0, _2);
		}
		ZEPHIR_INIT_NVAR(&path);
		ZVAL_COPY(&path, _1);
		ZEPHIR_CALL_FUNCTION(&_4$$4, "unlink", &_5, 67, &path);
		zephir_check_call_status();
		if (!(zephir_is_true(&_4$$4))) {
			success = 0;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&path);
	ZEPHIR_INIT_NVAR(&_0);
	RETURN_MM_BOOL(success);

}

/**
 * 将一个文件移动到一个新的位置。
 *
 * @param  string  $path
 * @param  string  $target
 * @return bool
 */
PHP_METHOD(Vii_FileSystem, move) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, *target, target_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&target_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path, &target);



	ZEPHIR_RETURN_CALL_FUNCTION("rename", NULL, 68, path, target);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 将一个文件复制到一个新的位置。
 *
 * @param  string  $path
 * @param  string  $target
 * @return bool
 */
PHP_METHOD(Vii_FileSystem, copy) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, *target, target_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&target_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path, &target);



	ZEPHIR_RETURN_CALL_FUNCTION("copy", NULL, 69, path, target);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 从文件路径提取文件名。
 *
 * @param  string  $path
 * @return string
 */
PHP_METHOD(Vii_FileSystem, name) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	ZVAL_LONG(&_0, 8);
	ZEPHIR_RETURN_CALL_FUNCTION("pathinfo", NULL, 70, path, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 从文件路径提取文件扩展名。
 *
 * @param  string  $path
 * @return string
 */
PHP_METHOD(Vii_FileSystem, extension) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	ZVAL_LONG(&_0, 4);
	ZEPHIR_RETURN_CALL_FUNCTION("pathinfo", NULL, 70, path, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取给定文件的文件类型。
 *
 * @param  string  $path
 * @return string
 */
PHP_METHOD(Vii_FileSystem, type) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	ZEPHIR_RETURN_CALL_FUNCTION("filetype", NULL, 71, path);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取给定文件的文件大小。
 *
 * @param  string  $path
 * @return int
 */
PHP_METHOD(Vii_FileSystem, size) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	ZEPHIR_RETURN_CALL_FUNCTION("filesize", NULL, 72, path);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取文件的最后修改时间。
 *
 * @param  string  $path
 * @return int
 */
PHP_METHOD(Vii_FileSystem, lastModified) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params(0, 1, 0, &path);



	zephir_filemtime(return_value, path TSRMLS_CC);
	return;

}

/**
 * 确定给定的路径是否是一个目录。
 *
 * @param  string  $directory
 * @return bool
 */
PHP_METHOD(Vii_FileSystem, isDirectory) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *directory, directory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory);



	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 73, directory);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 确定路径目录是否可写
 *
 * @param  string  $path
 * @return bool
 */
PHP_METHOD(Vii_FileSystem, isWritable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 74, path);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 确定给定的路径是否是一个文件。
 *
 * @param  string  $file
 * @return bool
 */
PHP_METHOD(Vii_FileSystem, isFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file, file_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);



	ZEPHIR_RETURN_CALL_FUNCTION("is_file", NULL, 75, file);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Find path names matching a given pattern.
 *
 * @param  string  $pattern
 * @param  int     $flags
 * @return array
 */
PHP_METHOD(Vii_FileSystem, glob) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern, pattern_sub, *flags = NULL, flags_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&flags_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern, &flags);

	if (!flags) {
		flags = &flags_sub;
		ZEPHIR_INIT_VAR(flags);
		ZVAL_LONG(flags, 0);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("glob", NULL, 76, pattern, flags);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取目录中的所有文件的数组。
 *
 * @param  string  $directory
 * @return array
 */
PHP_METHOD(Vii_FileSystem, files) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *directory, directory_sub, glob, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory_sub);
	ZVAL_UNDEF(&glob);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VS(&_0, directory, "/*");
	ZEPHIR_CALL_FUNCTION(&glob, "glob", NULL, 76, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&glob))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, vii_0__closure_ce, SL("__invoke"));
	ZEPHIR_RETURN_CALL_FUNCTION("array_filter", NULL, 77, &glob, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Create a directory.
 * @param  string  $path    路径
 * @param  int     $mode    权限
 * @param  bool    $recursive   是否递归创建
 * @return bool
 */
PHP_METHOD(Vii_FileSystem, makeDirectory) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, *mode = NULL, mode_sub, *recursive = NULL, recursive_sub, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&mode_sub);
	ZVAL_UNDEF(&recursive_sub);
	ZVAL_BOOL(&__$false, 0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path, &mode, &recursive);

	if (!mode) {
		mode = &mode_sub;
		ZEPHIR_INIT_VAR(mode);
		ZVAL_LONG(mode, 0755);
	}
	if (!recursive) {
		recursive = &recursive_sub;
		recursive = &__$false;
	}


	ZEPHIR_RETURN_CALL_FUNCTION("mkdir", NULL, 78, path, mode, recursive);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 将目录从一个位置复制到另一个位置。
 *
 * @param  string  $directory
 * @param  string  $destination
 * @param  int     $options
 * @return bool
 */
PHP_METHOD(Vii_FileSystem, copyDirectory) {

	zend_string *_9;
	zend_ulong _8;
	zephir_fcall_cache_entry *_1 = NULL, *_13 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *directory, directory_sub, *destination, destination_sub, *options = NULL, options_sub, __$null, _0, _2, _3, item, items, target, path, _6, *_7, _4$$4, _5$$4, _10$$5, _11$$5, _12$$6, _14$$8, _15$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory_sub);
	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &directory, &destination, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_CPY_WRT(options, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isdirectory", &_1, 0, directory);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_2);
	if (zephir_is_true(options)) {
		ZEPHIR_CPY_WRT(&_2, options);
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_LONG(&_2, 4096);
	}
	ZEPHIR_CPY_WRT(options, &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "isdirectory", &_1, 0, destination);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZVAL_LONG(&_4$$4, 0777);
		ZVAL_BOOL(&_5$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "makedirectory", NULL, 0, destination, &_4$$4, &_5$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&items);
	object_init_ex(&items, spl_ce_FilesystemIterator);
	ZEPHIR_CALL_METHOD(NULL, &items, "__construct", NULL, 79, directory, options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_is_iterable(&items, 0, "vii/filesystem.zep", 258);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&items), _8, _9, _7)
	{
		ZEPHIR_INIT_NVAR(&_6);
		if (_9 != NULL) { 
			ZVAL_STR_COPY(&_6, _9);
		} else {
			ZVAL_LONG(&_6, _8);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _7);
		ZEPHIR_CALL_METHOD(&_10$$5, &item, "getbasename", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&target);
		ZEPHIR_CONCAT_VSV(&target, destination, "/", &_10$$5);
		ZEPHIR_CALL_METHOD(&_11$$5, &item, "isdir", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_11$$5)) {
			ZEPHIR_CALL_METHOD(&path, &item, "getpathname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "copydirectory", &_13, 80, &path, &target, options);
			zephir_check_call_status();
			if (!(zephir_is_true(&_12$$6))) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_CALL_METHOD(&_15$$8, &item, "getpathname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "copy", &_16, 0, &_15$$8, &target);
			zephir_check_call_status();
			if (!(zephir_is_true(&_14$$8))) {
				RETURN_MM_BOOL(0);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&_6);
	RETURN_MM_BOOL(1);

}

/**
 * 递归删除目录。 目录本身可以选择保留
 * @param  string  $directory
 * @param  bool    $preserve 是否保留目录
 * @return bool
 */
PHP_METHOD(Vii_FileSystem, deleteDirectory) {

	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool preserve;
	zval *directory, directory_sub, *preserve_param = NULL, item, items, _0, _1, *_2, _5$$4, _6$$5, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directory, &preserve_param);

	if (!preserve_param) {
		preserve = 0;
	} else {
		preserve = zephir_get_boolval(preserve_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isdirectory", NULL, 0, directory);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&items);
	object_init_ex(&items, spl_ce_FilesystemIterator);
	ZEPHIR_CALL_METHOD(NULL, &items, "__construct", NULL, 79, directory);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(&items, 0, "vii/filesystem.zep", 281);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&items), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&_1);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&_1, _4);
		} else {
			ZVAL_LONG(&_1, _3);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _2);
		ZEPHIR_CALL_METHOD(&_5$$4, &item, "isdir", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$4)) {
			ZEPHIR_CALL_METHOD(&_6$$5, &item, "getpathname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "deletedirectory", &_7, 81, &_6$$5);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&_8$$6, &item, "getpathname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_9, 0, &_8$$6);
			zephir_check_call_status();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&_1);
	if (!preserve) {
		ZEPHIR_CALL_FUNCTION(NULL, "rmdir", NULL, 82, directory);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * 清空文件夹下所有的文件和文件夹
 * @param  string  $directory
 * @return bool
 */
PHP_METHOD(Vii_FileSystem, cleanDirectory) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *directory, directory_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory);



	ZVAL_BOOL(&_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "deletedirectory", NULL, 0, directory, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

