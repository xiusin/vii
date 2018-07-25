
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_VII_H
#define PHP_VII_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_VII_NAME        "vii"
#define PHP_VII_VERSION     "0.0.1"
#define PHP_VII_EXTNAME     "vii"
#define PHP_VII_AUTHOR      ""
#define PHP_VII_ZEPVERSION  "0.9.1a-dev"
#define PHP_VII_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(vii)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(vii)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(vii)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(vii_globals_id, zend_vii_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (vii_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_vii_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(vii_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(vii_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def vii_globals
#define zend_zephir_globals_def zend_vii_globals

extern zend_module_entry vii_module_entry;
#define phpext_vii_ptr &vii_module_entry

#endif
