
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "vii.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *vii_interfaces_iocinterface_ce;
zend_class_entry *vii_interfaces_configinterface_ce;
zend_class_entry *vii_interfaces_sessionadapterinterface_ce;
zend_class_entry *vii_interfaces_engineinterface_ce;
zend_class_entry *vii_interfaces_applicationinterface_ce;
zend_class_entry *vii_interfaces_eventmanagerinterface_ce;
zend_class_entry *vii_interfaces_loaderinterface_ce;
zend_class_entry *vii_interfaces_loginterface_ce;
zend_class_entry *vii_interfaces_viewinterface_ce;
zend_class_entry *vii_interfaces_bootstrapinterface_ce;
zend_class_entry *vii_interfaces_cacheinterface_ce;
zend_class_entry *vii_interfaces_dbinterface_ce;
zend_class_entry *vii_interfaces_moduleinterface_ce;
zend_class_entry *vii_config_ce;
zend_class_entry *vii_session_nativesession_ce;
zend_class_entry *vii_ioc_ce;
zend_class_entry *vii_log_driver_ce;
zend_class_entry *vii_mvc_view_engine_tiny_taglibarys_ce;
zend_class_entry *vii_0__closure_ce;
zend_class_entry *vii_1__closure_ce;
zend_class_entry *vii_alias_ce;
zend_class_entry *vii_assets_collection_ce;
zend_class_entry *vii_assets_inlines_ce;
zend_class_entry *vii_assets_manager_ce;
zend_class_entry *vii_assets_resources_ce;
zend_class_entry *vii_config_json_ce;
zend_class_entry *vii_config_php_ce;
zend_class_entry *vii_cookie_ce;
zend_class_entry *vii_db_ce;
zend_class_entry *vii_db_pdo_ce;
zend_class_entry *vii_db_querybuilder_ce;
zend_class_entry *vii_dispatcher_ce;
zend_class_entry *vii_dump_ce;
zend_class_entry *vii_event_ce;
zend_class_entry *vii_eventmanager_ce;
zend_class_entry *vii_exceptions_assetsexception_ce;
zend_class_entry *vii_exceptions_configexception_ce;
zend_class_entry *vii_exceptions_databaseexception_ce;
zend_class_entry *vii_exceptions_eventexception_ce;
zend_class_entry *vii_exceptions_filenotexistsexception_ce;
zend_class_entry *vii_exceptions_httpexception_ce;
zend_class_entry *vii_exceptions_iocexception_ce;
zend_class_entry *vii_exceptions_loaderexception_ce;
zend_class_entry *vii_exceptions_logexception_ce;
zend_class_entry *vii_exceptions_routerexception_ce;
zend_class_entry *vii_exceptions_runtimeexception_ce;
zend_class_entry *vii_exceptions_templateexception_ce;
zend_class_entry *vii_exceptions_uploadfileexception_ce;
zend_class_entry *vii_exceptions_viewexception_ce;
zend_class_entry *vii_filesystem_ce;
zend_class_entry *vii_helper_ce;
zend_class_entry *vii_i18n_ce;
zend_class_entry *vii_iocdefault_ce;
zend_class_entry *vii_loader_ce;
zend_class_entry *vii_log_ce;
zend_class_entry *vii_log_file_ce;
zend_class_entry *vii_mvc_application_ce;
zend_class_entry *vii_mvc_controller_ce;
zend_class_entry *vii_mvc_model_ce;
zend_class_entry *vii_mvc_model_resultset_ce;
zend_class_entry *vii_mvc_router_ce;
zend_class_entry *vii_mvc_router_route_ce;
zend_class_entry *vii_mvc_view_ce;
zend_class_entry *vii_mvc_view_engine_sleet_ce;
zend_class_entry *vii_mvc_view_engine_sleet_compiler_ce;
zend_class_entry *vii_mvc_view_engine_sleet_parser_ce;
zend_class_entry *vii_mvc_view_engine_tiny_ce;
zend_class_entry *vii_mvc_view_engine_tiny_compiler_ce;
zend_class_entry *vii_mvc_view_engine_tiny_tag_ce;
zend_class_entry *vii_registry_ce;
zend_class_entry *vii_request_ce;
zend_class_entry *vii_response_ce;
zend_class_entry *vii_session_adapter_file_ce;
zend_class_entry *vii_session_adapter_memcache_ce;
zend_class_entry *vii_uploadfileinfo_ce;
zend_class_entry *vii_urlmanager_ce;

ZEND_DECLARE_MODULE_GLOBALS(vii)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(vii)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Vii_Interfaces_IocInterface);
	ZEPHIR_INIT(Vii_Interfaces_ConfigInterface);
	ZEPHIR_INIT(Vii_Interfaces_SessionAdapterInterface);
	ZEPHIR_INIT(Vii_Interfaces_EngineInterface);
	ZEPHIR_INIT(Vii_Interfaces_ApplicationInterface);
	ZEPHIR_INIT(Vii_Interfaces_EventManagerInterface);
	ZEPHIR_INIT(Vii_Interfaces_LoaderInterface);
	ZEPHIR_INIT(Vii_Interfaces_LogInterface);
	ZEPHIR_INIT(Vii_Interfaces_ViewInterface);
	ZEPHIR_INIT(Vii_Interfaces_BootstrapInterface);
	ZEPHIR_INIT(Vii_Interfaces_CacheInterface);
	ZEPHIR_INIT(Vii_Interfaces_DbInterface);
	ZEPHIR_INIT(Vii_Interfaces_ModuleInterface);
	ZEPHIR_INIT(Vii_Config);
	ZEPHIR_INIT(Vii_Session_NativeSession);
	ZEPHIR_INIT(Vii_Ioc);
	ZEPHIR_INIT(Vii_Log_Driver);
	ZEPHIR_INIT(Vii_Mvc_View_Engine_Tiny_Taglibarys);
	ZEPHIR_INIT(Vii_Alias);
	ZEPHIR_INIT(Vii_Assets_Collection);
	ZEPHIR_INIT(Vii_Assets_Inlines);
	ZEPHIR_INIT(Vii_Assets_Manager);
	ZEPHIR_INIT(Vii_Assets_Resources);
	ZEPHIR_INIT(Vii_Config_Json);
	ZEPHIR_INIT(Vii_Config_Php);
	ZEPHIR_INIT(Vii_Cookie);
	ZEPHIR_INIT(Vii_Db);
	ZEPHIR_INIT(Vii_Db_Pdo);
	ZEPHIR_INIT(Vii_Db_QueryBuilder);
	ZEPHIR_INIT(Vii_Dispatcher);
	ZEPHIR_INIT(Vii_Dump);
	ZEPHIR_INIT(Vii_Event);
	ZEPHIR_INIT(Vii_EventManager);
	ZEPHIR_INIT(Vii_Exceptions_AssetsException);
	ZEPHIR_INIT(Vii_Exceptions_ConfigException);
	ZEPHIR_INIT(Vii_Exceptions_DatabaseException);
	ZEPHIR_INIT(Vii_Exceptions_EventException);
	ZEPHIR_INIT(Vii_Exceptions_FileNotExistsException);
	ZEPHIR_INIT(Vii_Exceptions_HttpException);
	ZEPHIR_INIT(Vii_Exceptions_IocException);
	ZEPHIR_INIT(Vii_Exceptions_LoaderException);
	ZEPHIR_INIT(Vii_Exceptions_LogException);
	ZEPHIR_INIT(Vii_Exceptions_RouterException);
	ZEPHIR_INIT(Vii_Exceptions_RunTimeException);
	ZEPHIR_INIT(Vii_Exceptions_TemplateException);
	ZEPHIR_INIT(Vii_Exceptions_UploadFileException);
	ZEPHIR_INIT(Vii_Exceptions_ViewException);
	ZEPHIR_INIT(Vii_FileSystem);
	ZEPHIR_INIT(Vii_Helper);
	ZEPHIR_INIT(Vii_I18n);
	ZEPHIR_INIT(Vii_IocDefault);
	ZEPHIR_INIT(Vii_Loader);
	ZEPHIR_INIT(Vii_Log);
	ZEPHIR_INIT(Vii_Log_File);
	ZEPHIR_INIT(Vii_Mvc_Application);
	ZEPHIR_INIT(Vii_Mvc_Controller);
	ZEPHIR_INIT(Vii_Mvc_Model);
	ZEPHIR_INIT(Vii_Mvc_Model_Resultset);
	ZEPHIR_INIT(Vii_Mvc_Router);
	ZEPHIR_INIT(Vii_Mvc_Router_Route);
	ZEPHIR_INIT(Vii_Mvc_View);
	ZEPHIR_INIT(Vii_Mvc_View_Engine_Sleet);
	ZEPHIR_INIT(Vii_Mvc_View_Engine_Sleet_Compiler);
	ZEPHIR_INIT(Vii_Mvc_View_Engine_Sleet_Parser);
	ZEPHIR_INIT(Vii_Mvc_View_Engine_Tiny);
	ZEPHIR_INIT(Vii_Mvc_View_Engine_Tiny_Compiler);
	ZEPHIR_INIT(Vii_Mvc_View_Engine_Tiny_Tag);
	ZEPHIR_INIT(Vii_Registry);
	ZEPHIR_INIT(Vii_Request);
	ZEPHIR_INIT(Vii_Response);
	ZEPHIR_INIT(Vii_Session_Adapter_File);
	ZEPHIR_INIT(Vii_Session_Adapter_Memcache);
	ZEPHIR_INIT(Vii_UploadFileInfo);
	ZEPHIR_INIT(Vii_UrlManager);
	ZEPHIR_INIT(vii_0__closure);
	ZEPHIR_INIT(vii_1__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(vii)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_vii_globals *vii_globals TSRMLS_DC)
{
	vii_globals->initialized = 0;

	/* Memory options */
	vii_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	vii_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	vii_globals->cache_enabled = 1;

	/* Recursive Lock */
	vii_globals->recursive_lock = 0;

	/* Static cache */
	memset(vii_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_vii_globals *vii_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(vii)
{
	zend_vii_globals *vii_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	vii_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(vii_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(vii_globals_ptr TSRMLS_CC);

		zephir_init_static_properties_Vii_Log_Driver(TSRMLS_C);
		zephir_init_static_properties_Vii_Request(TSRMLS_C);
	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(vii)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(vii)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_VII_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_VII_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_VII_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_VII_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_VII_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(vii)
{
	php_zephir_init_globals(vii_globals TSRMLS_CC);
	php_zephir_init_module_globals(vii_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(vii)
{
	
}


zend_function_entry php_vii_functions[] = {
	ZEND_FE_END

};

zend_module_entry vii_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_VII_EXTNAME,
	php_vii_functions,
	PHP_MINIT(vii),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(vii),
#else
	NULL,
#endif
	PHP_RINIT(vii),
	PHP_RSHUTDOWN(vii),
	PHP_MINFO(vii),
	PHP_VII_VERSION,
	ZEND_MODULE_GLOBALS(vii),
	PHP_GINIT(vii),
	PHP_GSHUTDOWN(vii),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(vii),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_VII
ZEND_GET_MODULE(vii)
#endif
