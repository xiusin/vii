
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Vii_Loader) {

	ZEPHIR_REGISTER_CLASS(Vii, Loader, vii, loader, vii_loader_method_entry, 0);

	zend_declare_property_null(vii_loader_ce, SL("registerNamespaces"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_loader_ce, SL("classmap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_loader_ce, SL("registerDirs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_loader_ce, SL("registerPrefixes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_loader_ce, SL("cachefile"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(vii_loader_ce, SL("ioc"), ZEND_ACC_PROTECTED TSRMLS_CC);

	vii_loader_ce->create_object = zephir_init_properties_Vii_Loader;

	zend_class_implements(vii_loader_ce TSRMLS_CC, 1, vii_interfaces_loaderinterface_ce);
	zend_class_implements(vii_loader_ce TSRMLS_CC, 1, vii_interfaces_iocinterface_ce);
	return SUCCESS;

}

/**
 * 构造函数
 */
PHP_METHOD(Vii_Loader, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classFileName = NULL, classFileName_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classFileName_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &classFileName);

	if (!classFileName) {
		classFileName = &classFileName_sub;
		classFileName = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setclassmapfile", NULL, 0, classFileName);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置Ioc
 */
PHP_METHOD(Vii_Loader, setIoc) {

	zval *_ioc, _ioc_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_ioc_sub);

	zephir_fetch_params(0, 1, 0, &_ioc);



	zephir_update_property_zval(this_ptr, SL("ioc"), _ioc);

}

/**
 * 获取Ioc
 */
PHP_METHOD(Vii_Loader, getIoc) {

	zval _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_CE_STATIC(&_1$$3, vii_ioc_ce, "getdefault", &_2, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setioc", NULL, 0, &_1$$3);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "ioc");

}

/**
 * 注册类名映射缓存地址
 */
PHP_METHOD(Vii_Loader, setClassMapFile) {

	zval *classFileName = NULL, classFileName_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classFileName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &classFileName);

	if (!classFileName) {
		classFileName = &classFileName_sub;
		ZEPHIR_CPY_WRT(classFileName, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(classFileName);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(classFileName)) {
		ZEPHIR_CPY_WRT(&_0, classFileName);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "classmap.php");
	}
	ZEPHIR_CPY_WRT(classFileName, &_0);
	zephir_update_property_zval(this_ptr, SL("cachefile"), classFileName);
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册名称空间
 * @param $namespace
 * @demo array('namespace'=>'dirs')
 */
PHP_METHOD(Vii_Loader, registerNamespaces) {

	zval *namespaceName_param = NULL, _0, _1;
	zval namespaceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaceName_param);

	ZEPHIR_OBS_COPY_OR_DUP(&namespaceName, namespaceName_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("registerNamespaces"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &namespaceName TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("registerNamespaces"), &_0);
	RETURN_THIS();

}

/**
 * 注册类名
 * @param array $array
 * @demo array('namespace\classname'=>'dirs/classfile','class'=>'dir/classfile')
 */
PHP_METHOD(Vii_Loader, registerClass) {

	zval *classArr_param = NULL, _0, _1;
	zval classArr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classArr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classArr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&classArr, classArr_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("classmap"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &classArr TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("classmap"), &_0);
	RETURN_THIS();

}

/**
 * @method 监听自动注册
 * @param $className  string 自动加载类名称
 */
PHP_METHOD(Vii_Loader, register) {

	zval _1;
	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "registerAutoload");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 91, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册自动载入
 */
PHP_METHOD(Vii_Loader, registerAutoload) {

	zend_bool noNamespaceName;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, fileName, info, controller_name, onlyClassName, classNamespace, dirkeys, _0, _3, _1$$3, _4$$5, _5$$5, _6$$5, _7$$5, _8$$6, *_9$$6, _10$$7, _11$$7;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&controller_name);
	ZVAL_UNDEF(&onlyClassName);
	ZVAL_UNDEF(&classNamespace);
	ZVAL_UNDEF(&dirkeys);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	if (UNEXPECTED(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(&className, className_param);
	} else {
		ZEPHIR_INIT_VAR(&className);
		ZVAL_EMPTY_STRING(&className);
	}


	noNamespaceName = 0;
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmap", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_key_exists(&_0, &className TSRMLS_CC)) {
		zephir_read_property(&_1$$3, this_ptr, SL("classmap"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&fileName);
		zephir_array_fetch(&fileName, &_1$$3, &className, PH_NOISY, "vii/loader.zep", 94 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "loadfile", &_2, 0, &fileName, &className);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (!(zephir_memnstr_str(&className, SL("\\"), "vii/loader.zep", 99))) {
		noNamespaceName = 1;
		ZEPHIR_CPY_WRT(&onlyClassName, &className);
	}
	ZEPHIR_INIT_VAR(&info);
	zephir_fast_explode_str(&info, SL("\\"), &className, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(&info);
	ZEPHIR_CALL_FUNCTION(&controller_name, "end", NULL, 56, &info);
	ZEPHIR_UNREF(&info);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&info);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 92, &info);
	ZEPHIR_UNREF(&info);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&classNamespace);
	zephir_fast_join_str(&classNamespace, SL("\\"), &info TSRMLS_CC);
	zephir_read_property(&_3, this_ptr, SL("registerNamespaces"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_3, &classNamespace TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_4$$5);
		zephir_read_property(&_5$$5, this_ptr, SL("registerNamespaces"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6$$5, &_5$$5, &classNamespace, PH_NOISY | PH_READONLY, "vii/loader.zep", 110 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "/");
		zephir_fast_trim(&_4$$5, &_6$$5, &_7$$5, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&fileName);
		ZEPHIR_CONCAT_VSVS(&fileName, &_4$$5, "/", &controller_name, ".php");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "loadfile", &_2, 0, &fileName, &className);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (noNamespaceName) {
		zephir_read_property(&_8$$6, this_ptr, SL("registerDirs"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_8$$6, 0, "vii/loader.zep", 122);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_8$$6), _9$$6)
		{
			ZEPHIR_INIT_NVAR(&dirkeys);
			ZVAL_COPY(&dirkeys, _9$$6);
			ZEPHIR_INIT_NVAR(&_10$$7);
			ZEPHIR_INIT_NVAR(&_11$$7);
			ZVAL_STRING(&_11$$7, "/");
			zephir_fast_trim(&_10$$7, &dirkeys, &_11$$7, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&fileName);
			ZEPHIR_CONCAT_VSVS(&fileName, &_10$$7, "/", &onlyClassName, ".php");
			if ((zephir_file_exists(&fileName TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "loadfile", &_2, 0, &fileName, &className);
				zephir_check_call_status();
				RETURN_MM();
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&dirkeys);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 载入文件 并且记录映射关系
 * @param $filename  string 载入文件的方式
 * @param $className string 名称
 */
PHP_METHOD(Vii_Loader, loadFile) {

	zend_bool _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, *className = NULL, className_sub, result, _0, _1, _2, _3, _6, _4$$3;
	zval filename, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filename_param, &className);

	if (UNEXPECTED(Z_TYPE_P(filename_param) != IS_STRING && Z_TYPE_P(filename_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filename' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filename_param) == IS_STRING)) {
		zephir_get_strval(&filename, filename_param);
	} else {
		ZEPHIR_INIT_VAR(&filename);
		ZVAL_EMPTY_STRING(&filename);
	}
	if (!className) {
		className = &className_sub;
		ZEPHIR_INIT_VAR(className);
		ZVAL_STRING(className, "");
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getioc", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "alias");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &_1, "resolve", NULL, 0, &filename);
	zephir_check_call_status();
	zephir_get_strval(&filename, &_3);
	if (!((zephir_file_exists(&filename TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, vii_exceptions_filenotexistsexception_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SVS(&_5$$3, "file [", &filename, "] not exists");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "vii/loader.zep", 135 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_6);
	if (zephir_require_zval_ret(&_6, &filename TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(&result, &_6);
	_7 = zephir_is_true(&result);
	if (_7) {
		_7 = !(ZEPHIR_IS_EMPTY(className));
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "savemap", NULL, 0, className, &filename);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * 注册自动载入目录,注册的目录为自动扫描的目录
 * @param $dir_str array|string
 * @demo registerDirs(['a','b','c']);
 * @demo new Demo(); a/demo.php loaded
 */
PHP_METHOD(Vii_Loader, registerDirs) {

	zval *dir_str = NULL, dir_str_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir_str_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_str);

	ZEPHIR_SEPARATE_PARAM(dir_str);


	if (Z_TYPE_P(dir_str) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(dir_str);
		zephir_create_array(dir_str, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(dir_str, dir_str);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("registerDirs"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, dir_str TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("registerDirs"), &_0);
	RETURN_THIS();

}

/**
 * 获取注册的命名空间
 */
PHP_METHOD(Vii_Loader, getNamespaces) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "registerNamespaces");

}

/**
 * 保存匹配到的文件
 */
PHP_METHOD(Vii_Loader, saveMap) {

	zval *className_param = NULL, *filePath_param = NULL;
	zval className, filePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&filePath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &filePath_param);

	if (UNEXPECTED(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(&className, className_param);
	} else {
		ZEPHIR_INIT_VAR(&className);
		ZVAL_EMPTY_STRING(&className);
	}
	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(&filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(&filePath);
		ZVAL_EMPTY_STRING(&filePath);
	}


	zephir_update_property_array(this_ptr, SL("classmap"), &className, &filePath TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取最终的class映射
 */
PHP_METHOD(Vii_Loader, getMap) {

	zval _0, _1$$3, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("cachefile"), PH_NOISY_CC | PH_READONLY);
	if ((zephir_file_exists(&_0 TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("classmap"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3$$3, this_ptr, SL("cachefile"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_4$$3);
		if (zephir_require_zval_ret(&_4$$3, &_3$$3 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		zephir_fast_array_merge(&_1$$3, &_2$$3, &_4$$3 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("classmap"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "classmap");

}

zend_object *zephir_init_properties_Vii_Loader(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("registerPrefixes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("registerPrefixes"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("registerDirs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("registerDirs"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("classmap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("classmap"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("registerNamespaces"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("registerNamespaces"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

