
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
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Vii_Mvc_Application) {

	ZEPHIR_REGISTER_CLASS(Vii\\Mvc, Application, vii, mvc_application, vii_mvc_application_method_entry, 0);

	zend_declare_property_null(vii_mvc_application_ce, SL("ioc"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(vii_mvc_application_ce, SL("debug"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(vii_mvc_application_ce, SL("_module"), ZEND_ACC_PUBLIC TSRMLS_CC);

	vii_mvc_application_ce->create_object = zephir_init_properties_Vii_Mvc_Application;
	zephir_declare_class_constant_string(vii_mvc_application_ce, SL("VERSION"), "DEV 0.1");

	zend_class_implements(vii_mvc_application_ce TSRMLS_CC, 1, vii_interfaces_applicationinterface_ce);
	zend_class_implements(vii_mvc_application_ce TSRMLS_CC, 1, vii_interfaces_iocinterface_ce);
	return SUCCESS;

}

/**
 *  @param ioc IocInterface 全局Ioc容器
 *  @param composerAutoLoadFile 传入的composer管理位置
 */
PHP_METHOD(Vii_Mvc_Application, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval composerAutoLoadFile;
	zval *ioc, ioc_sub, *composerAutoLoadFile_param = NULL, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&composerAutoLoadFile);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &ioc, &composerAutoLoadFile_param);

	if (!composerAutoLoadFile_param) {
		ZEPHIR_INIT_VAR(&composerAutoLoadFile);
		ZVAL_STRING(&composerAutoLoadFile, "");
	} else {
		zephir_get_strval(&composerAutoLoadFile, composerAutoLoadFile_param);
	}


	zephir_update_property_zval(this_ptr, SL("ioc"), ioc);
	zephir_read_property(&_0, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "loader");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "register", NULL, 0);
	zephir_check_call_status();
	if ((zephir_file_exists(&composerAutoLoadFile TSRMLS_CC) == SUCCESS)) {
		if (zephir_require_zval(&composerAutoLoadFile TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 调试开关
 * @param debug bool 状态
 * @return Application
 */
PHP_METHOD(Vii_Mvc_Application, debug) {

	zval *debug_param = NULL, __$true, __$false;
	zend_bool debug;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &debug_param);

	if (UNEXPECTED(Z_TYPE_P(debug_param) != IS_TRUE && Z_TYPE_P(debug_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'debug' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}
	debug = (Z_TYPE_P(debug_param) == IS_TRUE);


	if (debug) {
		zephir_update_property_zval(this_ptr, SL("debug"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("debug"), &__$false);
	}
	RETURN_THISW();

}

/**
 * 程序执行入口
 * @return string | Exception | RunTimeException | void
 */
PHP_METHOD(Vii_Mvc_Application, handle) {

	zval e, notFound, _4, _0$$3, _1$$3, _2$$3, _3$$3, _5$$4, _6$$5, _7$$5, _8$$6, _9$$6, _10$$6, _11$$7, _12$$7, _13$$10, _14$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&notFound);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 49);
	zephir_check_call_status();

	/* try_start_1: */

		zephir_read_property(&_0$$3, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "dispatcher");
		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "get", NULL, 0, &_2$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_3$$3, &_1$$3, "setapp", NULL, 0, this_ptr);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_RETURN_CALL_METHOD(&_3$$3, "dispatch", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_OBJ(&_4, EG(exception));
		Z_ADDREF_P(&_4);
		if (zephir_instance_of_ev(&_4, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_4);
			zephir_read_property(&_5$$4, this_ptr, SL("debug"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_5$$4)) {
				ZEPHIR_INIT_VAR(&_6$$5);
				object_init_ex(&_6$$5, spl_ce_RuntimeException);
				ZEPHIR_CALL_METHOD(&_7$$5, &e, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 98, &_7$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$5, "vii/mvc/application.zep", 50 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				zephir_read_property(&_8$$6, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_10$$6);
				ZVAL_STRING(&_10$$6, "router");
				ZEPHIR_CALL_METHOD(&_9$$6, &_8$$6, "get", NULL, 0, &_10$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&notFound, &_9$$6, "getnotfound", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&notFound) == IS_NULL) {
					ZEPHIR_INIT_VAR(&_11$$7);
					object_init_ex(&_11$$7, spl_ce_RuntimeException);
					ZEPHIR_CALL_METHOD(&_12$$7, &e, "getmessage", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_11$$7, "__construct", NULL, 98, &_12$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$7, "vii/mvc/application.zep", 54 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					if (zephir_instance_of_ev(&notFound, zend_ce_closure TSRMLS_CC)) {
						ZEPHIR_CALL_ZVAL_FUNCTION(NULL, &notFound, NULL, 0);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_VAR(&_13$$10);
						object_init_ex(&_13$$10, spl_ce_RuntimeException);
						ZEPHIR_CALL_METHOD(&_14$$10, &e, "getmessage", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &_13$$10, "__construct", NULL, 98, &_14$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_13$$10, "vii/mvc/application.zep", 59 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
	}

}

/**
 * 初始化启动文件方法 一般用于注册服务或其他判断
 * @param filename string 要初始化加载的Bootstrap类文件
 * @return ApplicationInterface | Application
 */
PHP_METHOD(Vii_Mvc_Application, bootstrap) {

	zval _8, _11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, bootstrap, methods, bootstrapClass, method, methodName, _0, _1, _2, _3, _6, _7, _9, _10, *_12, _4$$3;
	zval filename, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&bootstrap);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&bootstrapClass);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename_param);

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


	zephir_read_property(&_0, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CONCAT_SVS(&_5$$3, "the bootstrap:", &filename, " file is not exists!");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "vii/mvc/application.zep", 76 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_6, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "loader");
	ZEPHIR_CALL_METHOD(&_7, &_6, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_8, SL("Bootstrap"), &filename, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_7, "registerclass", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&bootstrap);
	object_init_ex(&bootstrap, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Bootstrap");
	ZEPHIR_CALL_METHOD(NULL, &bootstrap, "__construct", NULL, 13, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_9, 256);
	ZEPHIR_CALL_METHOD(&methods, &bootstrap, "getmethods", NULL, 99, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Vii\\Interfaces\\BootstrapInterface");
	ZEPHIR_CALL_METHOD(&_10, &bootstrap, "implementsinterface", NULL, 100, &_2);
	zephir_check_call_status();
	if (!(zephir_is_true(&_10))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(vii_exceptions_runtimeexception_ce, "bootstrapClass must implements Vii\\Interfaces\\BootstrapInterface", "vii/mvc/application.zep", 83);
		return;
	}
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 1, 0 TSRMLS_CC);
	zephir_read_property(&_9, this_ptr, SL("ioc"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fast_append(&_11, &_9);
	ZEPHIR_CALL_METHOD(&bootstrapClass, &bootstrap, "newinstanceargs", NULL, 14, &_11);
	zephir_check_call_status();
	zephir_is_iterable(&methods, 0, "vii/mvc/application.zep", 93);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _12)
	{
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_COPY(&method, _12);
		ZEPHIR_CALL_METHOD(&methodName, &method, "getname", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_start_with_str(&methodName, SL("init")))) {
			continue;
		}
		ZEPHIR_CALL_METHOD_ZVAL(NULL, &bootstrapClass, &methodName, NULL, 0);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&method);
	RETURN_THIS();

}

/**
 * 创建基本的模块结构
 * @applicationDirName 应用目录地址
 * @moduleName 应用模块名
 */
PHP_METHOD(Vii_Mvc_Application, bulidBaseStruct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL;
	zval *applicationDirName_param = NULL, *moduleName_param = NULL, __$true, value, moduleDir, _0, _1, new_app, _3, *_5, _6$$4, _8$$5;
	zval applicationDirName, moduleName, _4, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&applicationDirName);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&new_app);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &applicationDirName_param, &moduleName_param);

	zephir_get_strval(&applicationDirName, applicationDirName_param);
	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(&moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleName);
		ZVAL_EMPTY_STRING(&moduleName);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &applicationDirName, &_1, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_get_strval(&applicationDirName, &_0);
	ZEPHIR_CPY_WRT(&moduleDir, &applicationDirName);
	if (!(Z_TYPE_P(&moduleName) == IS_UNDEF) && Z_STRLEN_P(&moduleName)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VSV(&_2$$3, &applicationDirName, "/", &moduleName);
		ZEPHIR_CPY_WRT(&moduleDir, &_2$$3);
	}
	ZEPHIR_INIT_VAR(&new_app);
	zephir_create_array(&new_app, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, &moduleDir, "/views");
	zephir_array_fast_append(&new_app, &_3);
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_VS(&_3, &moduleDir, "/controllers");
	zephir_array_fast_append(&new_app, &_3);
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_VS(&_3, &moduleDir, "/models");
	zephir_array_fast_append(&new_app, &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &applicationDirName, "/config");
	zephir_array_fast_append(&new_app, &_4);
	zephir_is_iterable(&new_app, 0, "vii/mvc/application.zep", 120);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&new_app), _5)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _5);
		ZEPHIR_CALL_FUNCTION(&_6$$4, "is_dir", &_7, 73, &value);
		zephir_check_call_status();
		if (!zephir_is_true(&_6$$4)) {
			ZVAL_LONG(&_8$$5, 0777);
			ZEPHIR_CALL_FUNCTION(NULL, "mkdir", &_9, 78, &value, &_8$$5, &__$true);
			zephir_check_call_status();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_MM_RESTORE();

}

/**
 * 向应用内注册模块
 * @modules array 要注册的模块信息数组
 */
PHP_METHOD(Vii_Mvc_Application, registerModules) {

	zval *modules_param = NULL;
	zval modules;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modules);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modules_param);

	zephir_get_arrval(&modules, modules_param);


	zephir_update_property_zval(this_ptr, SL("_module"), &modules);
	ZEPHIR_MM_RESTORE();

}

/**
 * 根据获取的模块名获取注册的模块信息
 * @param name string 模块名称
 * @return array | RunTimeException
 */
PHP_METHOD(Vii_Mvc_Application, getRegisterModuleByModuleName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _3, _4, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("_module"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, vii_exceptions_runtimeexception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VS(&_2$$3, &name, "模块没有被注册");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "vii/mvc/application.zep", 139 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("_module"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "vii/mvc/application.zep", 141 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

/**
 * 获取当前注册的模块信息
 */
PHP_METHOD(Vii_Mvc_Application, getRegisterModules) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_module");

}

PHP_METHOD(Vii_Mvc_Application, setIoc) {

	zval *_ioc, _ioc_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_ioc_sub);

	zephir_fetch_params(0, 1, 0, &_ioc);



	zephir_update_property_zval(this_ptr, SL("ioc"), _ioc);

}

PHP_METHOD(Vii_Mvc_Application, getIoc) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "ioc");

}

zend_object *zephir_init_properties_Vii_Mvc_Application(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_module"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_module"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

