
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Vii_Response) {

	ZEPHIR_REGISTER_CLASS(Vii, Response, vii, response, vii_response_method_entry, 0);

	zend_declare_property_string(vii_response_ce, SL("content"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(vii_response_ce, SL("issent"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_response_ce, SL("rawHeader"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(vii_response_ce, SL("statuses"), ZEND_ACC_PROTECTED TSRMLS_CC);

	vii_response_ce->create_object = zephir_init_properties_Vii_Response;
	return SUCCESS;

}

PHP_METHOD(Vii_Response, __construct) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 59, 0 TSRMLS_CC);
	add_index_stringl(&_0, 100, SL("Continue"));
	add_index_stringl(&_0, 101, SL("Switching Protocols"));
	add_index_stringl(&_0, 102, SL("Processing"));
	add_index_stringl(&_0, 200, SL("OK"));
	add_index_stringl(&_0, 201, SL("Created"));
	add_index_stringl(&_0, 202, SL("Accepted"));
	add_index_stringl(&_0, 203, SL("Non-Authoritative Information"));
	add_index_stringl(&_0, 204, SL("No Content"));
	add_index_stringl(&_0, 205, SL("Reset Content"));
	add_index_stringl(&_0, 206, SL("Partial Content"));
	add_index_stringl(&_0, 207, SL("Multi-Status"));
	add_index_stringl(&_0, 208, SL("Already Reported"));
	add_index_stringl(&_0, 226, SL("IM Used"));
	add_index_stringl(&_0, 300, SL("Multiple Choices"));
	add_index_stringl(&_0, 301, SL("Moved Permanently"));
	add_index_stringl(&_0, 302, SL("Found"));
	add_index_stringl(&_0, 303, SL("See Other"));
	add_index_stringl(&_0, 304, SL("Not Modified"));
	add_index_stringl(&_0, 305, SL("Use Proxy"));
	add_index_stringl(&_0, 307, SL("Temporary Redirect"));
	add_index_stringl(&_0, 308, SL("Permanent Redirect"));
	add_index_stringl(&_0, 400, SL("Bad Request"));
	add_index_stringl(&_0, 401, SL("Unauthorized"));
	add_index_stringl(&_0, 402, SL("Payment Required"));
	add_index_stringl(&_0, 403, SL("Forbidden"));
	add_index_stringl(&_0, 404, SL("Not Found"));
	add_index_stringl(&_0, 405, SL("Method Not Allowed"));
	add_index_stringl(&_0, 406, SL("Not Acceptable"));
	add_index_stringl(&_0, 407, SL("Proxy Authentication Required"));
	add_index_stringl(&_0, 408, SL("Request Timeout"));
	add_index_stringl(&_0, 409, SL("Conflict"));
	add_index_stringl(&_0, 410, SL("Gone"));
	add_index_stringl(&_0, 411, SL("Length Required"));
	add_index_stringl(&_0, 412, SL("Precondition Failed"));
	add_index_stringl(&_0, 413, SL("Request Entity Too Large"));
	add_index_stringl(&_0, 414, SL("Request-URI Too Long"));
	add_index_stringl(&_0, 415, SL("Unsupported Media Type"));
	add_index_stringl(&_0, 416, SL("Requested Range Not Satisfiable"));
	add_index_stringl(&_0, 417, SL("Expectation Failed"));
	add_index_stringl(&_0, 418, SL("I\"m a Teapot"));
	add_index_stringl(&_0, 422, SL("Unprocessable Entity"));
	add_index_stringl(&_0, 423, SL("Locked"));
	add_index_stringl(&_0, 424, SL("Failed Dependency"));
	add_index_stringl(&_0, 426, SL("Upgrade Required"));
	add_index_stringl(&_0, 428, SL("Precondition Required"));
	add_index_stringl(&_0, 429, SL("Too Many Requests"));
	add_index_stringl(&_0, 431, SL("Request Header Fields Too Large"));
	add_index_stringl(&_0, 500, SL("Internal Server Error"));
	add_index_stringl(&_0, 501, SL("Not Implemented"));
	add_index_stringl(&_0, 502, SL("Bad Gateway"));
	add_index_stringl(&_0, 503, SL("Ioc Unavailable"));
	add_index_stringl(&_0, 504, SL("Gateway Timeout"));
	add_index_stringl(&_0, 505, SL("HTTP Version Not Supported"));
	add_index_stringl(&_0, 506, SL("Variant Also Negotiates"));
	add_index_stringl(&_0, 507, SL("Insufficient Storage"));
	add_index_stringl(&_0, 508, SL("Loop Detected"));
	add_index_stringl(&_0, 509, SL("Bandwidth Limit Exceeded"));
	add_index_stringl(&_0, 510, SL("Not Extended"));
	add_index_stringl(&_0, 511, SL("Network Authentication Required"));
	zephir_update_property_zval(this_ptr, SL("statuses"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Response, setStatusCode) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);



	zephir_read_property(&_0, this_ptr, SL("statuses"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_1, &_0, code, PH_NOISY | PH_READONLY, "vii/response.zep", 76 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVV(&_2, "HTTP/1.1  ", code, &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrawheader", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Response, setHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VSV(&_0, name, ": ", value);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrawheader", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Vii_Response, setRawHeader) {

	zval *header, header_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header_sub);

	zephir_fetch_params(0, 1, 0, &header);



	zephir_update_property_array_append(this_ptr, SL("rawHeader"), header TSRMLS_CC);

}

PHP_METHOD(Vii_Response, redirect) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Vii_Response, setContent) {

	zval *content, content_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);

	zephir_fetch_params(0, 1, 0, &content);



	zephir_update_property_zval(this_ptr, SL("content"), content);
	RETURN_THISW();

}

PHP_METHOD(Vii_Response, setJsonContent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content, content_sub, *option = NULL, option_sub, *depth = NULL, depth_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&depth_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content, &option, &depth);

	if (!option) {
		option = &option_sub;
		ZEPHIR_INIT_VAR(option);
		ZVAL_LONG(option, 0);
	}
	if (!depth) {
		depth = &depth_sub;
		ZEPHIR_INIT_VAR(depth);
		ZVAL_LONG(depth, 512);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Content-type");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "application/json");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	zephir_json_encode(&_0, content, zephir_get_intval(option) );
	zephir_update_property_zval(this_ptr, SL("content"), &_0);
	RETURN_THIS();

}

PHP_METHOD(Vii_Response, appendContent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content, content_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, content);
	zephir_update_property_zval(this_ptr, SL("content"), &_1);
	RETURN_THIS();

}

PHP_METHOD(Vii_Response, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "content");

}

PHP_METHOD(Vii_Response, resetHeaders) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("rawHeader"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Vii_Response, isSend) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "issent");

}

PHP_METHOD(Vii_Response, sendHeaders) {

	zval v, _0, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("rawHeader"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "vii/response.zep", 124);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _1);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_2, 138, &v);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	RETURN_THIS();

}

PHP_METHOD(Vii_Response, sendContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "content");

}

PHP_METHOD(Vii_Response, send) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false, _0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	if (1) {
		zephir_update_property_zval(this_ptr, SL("issent"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("issent"), &__$false);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "sendheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "sendcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Vii_Response, hasHeader) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("rawHeader"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

zend_object *zephir_init_properties_Vii_Response(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("statuses"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("statuses"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("rawHeader"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("rawHeader"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

