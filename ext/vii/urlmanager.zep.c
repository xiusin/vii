
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
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Vii_UrlManager) {

	ZEPHIR_REGISTER_CLASS(Vii, UrlManager, vii, urlmanager, vii_urlmanager_method_entry, 0);

	zend_declare_property_string(vii_urlmanager_ce, SL("baseUri"), "/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(vii_urlmanager_ce, SL("staticBaseUri"), "/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(vii_urlmanager_ce, SL("basePath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param $baseUri string 所有地址的前缀不包含host
 */
PHP_METHOD(Vii_UrlManager, setBaseUri) {

	zval *baseUri, baseUri_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseUri_sub);

	zephir_fetch_params(0, 1, 0, &baseUri);



	zephir_update_property_zval(this_ptr, SL("baseUri"), baseUri);
	RETURN_THISW();

}

/**
 * @param $staticBaseUri string 设置静态文件的基本URI
 */
PHP_METHOD(Vii_UrlManager, setStaticBaseUri) {

	zval *staticBaseUri, staticBaseUri_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticBaseUri_sub);

	zephir_fetch_params(0, 1, 0, &staticBaseUri);



	zephir_update_property_zval(this_ptr, SL("staticBaseUri"), staticBaseUri);
	RETURN_THISW();

}

PHP_METHOD(Vii_UrlManager, getBaseUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "baseUri");

}

PHP_METHOD(Vii_UrlManager, getStaticBaseUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "staticBaseUri");

}

/**
 * 设置本地文件绝对路径前缀
 * @param $basePath string 本地文件的绝对路径前缀
 * @return $this
 */
PHP_METHOD(Vii_UrlManager, setBasePath) {

	zval *basePath, basePath_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath_sub);

	zephir_fetch_params(0, 1, 0, &basePath);



	zephir_update_property_zval(this_ptr, SL("basePath"), basePath);
	RETURN_THISW();

}

PHP_METHOD(Vii_UrlManager, getBasePath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "basePath");

}

/**
 * 获取本地文件地址字符串
 * @param $path string 本地文件字符串地址
 */
PHP_METHOD(Vii_UrlManager, path) {

	zval *path, path_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("basePath"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_trim(&_0, &_1, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CONCAT_VV(return_value, &_0, path);
	RETURN_MM();

}

/**
 * 获取静态文件网络资源地址
 * @param $uri string|array 静态文件URI字符串
 */
PHP_METHOD(Vii_UrlManager, getStatic) {

	zval *uri, uri_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &uri);



	zephir_read_property(&_0, this_ptr, SL("staticBaseUri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_0, uri);
	return;

}

/**
 * 获取URI地址
 * @param $uri  string 需要拼接的字符串
 * @param array $params 其他额外参数
 * @return string
 */
PHP_METHOD(Vii_UrlManager, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *uri, uri_sub, *params_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri, &params_param);

	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	zephir_read_property(&_0, this_ptr, SL("baseUri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildparams", NULL, 0, &params);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &_0, uri, &_1);
	RETURN_MM();

}

/**
 * 组建参数字符串
 * @param array $params 参数数组
 * @return string
 */
PHP_METHOD(Vii_UrlManager, buildParams) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, _0;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(&params, params_param);


	if (ZEPHIR_IS_EMPTY(&params)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_CALL_FUNCTION(&_0, "http_build_query", NULL, 142, &params);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "?", &_0);
	RETURN_MM();

}

