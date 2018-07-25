srcdir = /Users/Macx/www/zephir/ext
builddir = /Users/Macx/www/zephir/ext
top_srcdir = /Users/Macx/www/zephir/ext
top_builddir = /Users/Macx/www/zephir/ext
EGREP = /usr/bin/grep -E
SED = /usr/bin/sed
CONFIGURE_COMMAND = './configure' '--enable-vii'
CONFIGURE_OPTIONS = '--enable-vii'
SHLIB_SUFFIX_NAME = dylib
SHLIB_DL_SUFFIX_NAME = so
ZEND_EXT_TYPE = zend_extension
RE2C = re2c
AWK = awk
shared_objects_vii = vii.lo kernel/main.lo kernel/memory.lo kernel/exception.lo kernel/hash.lo kernel/debug.lo kernel/backtrace.lo kernel/object.lo kernel/array.lo kernel/extended/array.lo kernel/string.lo kernel/fcall.lo kernel/extended/fcall.lo kernel/require.lo kernel/file.lo kernel/operators.lo kernel/math.lo kernel/concat.lo kernel/variables.lo kernel/filter.lo kernel/iterator.lo kernel/time.lo kernel/exit.lo vii/interfaces/iocinterface.lo vii/interfaces/configinterface.lo vii/interfaces/sessionadapterinterface.lo vii/config.lo vii/interfaces/engineinterface.lo vii/session/nativesession.lo vii/interfaces/applicationinterface.lo vii/interfaces/eventmanagerinterface.lo vii/interfaces/loaderinterface.lo vii/interfaces/loginterface.lo vii/interfaces/viewinterface.lo vii/ioc.lo vii/log/driver.lo vii/mvc/view/engine/tiny/taglibarys.lo vii/alias.lo vii/assets/collection.lo vii/assets/inlines.lo vii/assets/manager.lo vii/assets/resources.lo vii/config/json.lo vii/config/php.lo vii/cookie.lo vii/db.lo vii/db/pdo.lo vii/db/querybuilder.lo vii/dispatcher.lo vii/dump.lo vii/event.lo vii/eventmanager.lo vii/exceptions/assetsexception.lo vii/exceptions/configexception.lo vii/exceptions/databaseexception.lo vii/exceptions/eventexception.lo vii/exceptions/filenotexistsexception.lo vii/exceptions/httpexception.lo vii/exceptions/iocexception.lo vii/exceptions/loaderexception.lo vii/exceptions/logexception.lo vii/exceptions/routerexception.lo vii/exceptions/runtimeexception.lo vii/exceptions/templateexception.lo vii/exceptions/uploadfileexception.lo vii/exceptions/viewexception.lo vii/filesystem.lo vii/helper.lo vii/i18n.lo vii/interfaces/bootstrapinterface.lo vii/interfaces/cacheinterface.lo vii/interfaces/dbinterface.lo vii/interfaces/moduleinterface.lo vii/iocdefault.lo vii/loader.lo vii/log.lo vii/log/file.lo vii/mvc/application.lo vii/mvc/controller.lo vii/mvc/model.lo vii/mvc/model/resultset.lo vii/mvc/router.lo vii/mvc/router/route.lo vii/mvc/view.lo vii/mvc/view/engine/sleet.lo vii/mvc/view/engine/sleet/compiler.lo vii/mvc/view/engine/sleet/parser.lo vii/mvc/view/engine/tiny.lo vii/mvc/view/engine/tiny/compiler.lo vii/mvc/view/engine/tiny/tag.lo vii/registry.lo vii/request.lo vii/response.lo vii/session/adapter/file.lo vii/session/adapter/memcache.lo vii/uploadfileinfo.lo vii/urlmanager.lo vii/0__closure.lo vii/1__closure.lo
PHP_PECL_EXTENSION = vii
VII_SHARED_LIBADD =
PHP_MODULES = $(phplibdir)/vii.la
PHP_ZEND_EX =
all_targets = $(PHP_MODULES) $(PHP_ZEND_EX)
install_targets = install-modules install-headers
prefix = /usr/local/Cellar/php71/7.1.3_15
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /usr/local/Cellar/php71/7.1.3_15
phplibdir = /Users/Macx/www/zephir/ext/modules
phpincludedir = /usr/local/Cellar/php71/7.1.3_15/include/php
CC = gcc
CFLAGS = -O2 -fvisibility=hidden -Wparentheses -flto -DZEPHIR_RELEASE=1
CFLAGS_CLEAN = $(CFLAGS)
CPP = gcc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX =
CXXFLAGS =
CXXFLAGS_CLEAN = $(CXXFLAGS)
EXTENSION_DIR = /usr/local/Cellar/php71/7.1.3_15/lib/php/extensions/no-debug-non-zts-20160303
PHP_EXECUTABLE = /usr/local/Cellar/php71/7.1.3_15/bin/php
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/usr/local/Cellar/php71/7.1.3_15/include/php -I/usr/local/Cellar/php71/7.1.3_15/include/php/main -I/usr/local/Cellar/php71/7.1.3_15/include/php/TSRM -I/usr/local/Cellar/php71/7.1.3_15/include/php/Zend -I/usr/local/Cellar/php71/7.1.3_15/include/php/ext -I/usr/local/Cellar/php71/7.1.3_15/include/php/ext/date/lib
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/sh
INSTALL_HEADERS = ext/vii/php_VII.h
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -DPHP_ATOM_INC -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)

all: $(all_targets) 
	@echo
	@echo "Build complete."
	@echo "Don't forget to run 'make test'."
	@echo

build-modules: $(PHP_MODULES) $(PHP_ZEND_EX)

build-binaries: $(PHP_BINARIES)

libphp$(PHP_MAJOR_VERSION).la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp $@ $(phptempdir)/$@ >/dev/null 2>&1

libs/libphp$(PHP_MAJOR_VERSION).bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp$(PHP_MAJOR_VERSION).so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-binaries: build-binaries $(install_binary_targets)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-headers:
	-@if test "$(INSTALL_HEADERS)"; then \
		for i in `echo $(INSTALL_HEADERS)`; do \
			i=`$(top_srcdir)/build/shtool path -d $$i`; \
			paths="$$paths $(INSTALL_ROOT)$(phpincludedir)/$$i"; \
		done; \
		$(mkinstalldirs) $$paths && \
		echo "Installing header files:          $(INSTALL_ROOT)$(phpincludedir)/" && \
		for i in `echo $(INSTALL_HEADERS)`; do \
			if test "$(PHP_PECL_EXTENSION)"; then \
				src=`echo $$i | $(SED) -e "s#ext/$(PHP_PECL_EXTENSION)/##g"`; \
			else \
				src=$$i; \
			fi; \
			if test -f "$(top_srcdir)/$$src"; then \
				$(INSTALL_DATA) $(top_srcdir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			elif test -f "$(top_builddir)/$$src"; then \
				$(INSTALL_DATA) $(top_builddir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			else \
				(cd $(top_srcdir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i; \
				cd $(top_builddir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i) 2>/dev/null || true; \
			fi \
		done; \
	fi

PHP_TEST_SETTINGS = -d 'open_basedir=' -d 'output_buffering=0' -d 'memory_limit=-1'
PHP_TEST_SHARED_EXTENSIONS =  ` \
	if test "x$(PHP_MODULES)" != "x"; then \
		for i in $(PHP_MODULES)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d extension=$$dlname"; \
		done; \
	fi; \
	if test "x$(PHP_ZEND_EX)" != "x"; then \
		for i in $(PHP_ZEND_EX)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d $(ZEND_EXT_TYPE)=$(top_builddir)/modules/$$dlname"; \
		done; \
	fi`
PHP_DEPRECATED_DIRECTIVES_REGEX = '^(magic_quotes_(gpc|runtime|sybase)?|(zend_)?extension(_debug)?(_ts)?)[\t\ ]*='

test: all
	@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		INI_FILE=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r 'echo php_ini_loaded_file();' 2> /dev/null`; \
		if test "$$INI_FILE"; then \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_FILE" > $(top_builddir)/tmp-php.ini; \
		else \
			echo > $(top_builddir)/tmp-php.ini; \
		fi; \
		INI_SCANNED_PATH=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r '$$a = explode(",\n", trim(php_ini_scanned_files())); echo $$a[0];' 2> /dev/null`; \
		if test "$$INI_SCANNED_PATH"; then \
			INI_SCANNED_PATH=`$(top_srcdir)/build/shtool path -d $$INI_SCANNED_PATH`; \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_SCANNED_PATH"/*.ini >> $(top_builddir)/tmp-php.ini; \
		fi; \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(PHP_EXECUTABLE) -n -c $(top_builddir)/tmp-php.ini $(PHP_TEST_SETTINGS) $(top_srcdir)/run-tests.php -n -c $(top_builddir)/tmp-php.ini -d extension_dir=$(top_builddir)/modules/ $(PHP_TEST_SHARED_EXTENSIONS) $(TESTS); \
		TEST_RESULT_EXIT_CODE=$$?; \
		rm $(top_builddir)/tmp-php.ini; \
		exit $$TEST_RESULT_EXIT_CODE; \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.gcno -o -name \*.gcda | xargs rm -f
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	rm -f libphp$(PHP_MAJOR_VERSION).la $(SAPI_CLI_PATH) $(SAPI_CGI_PATH) $(SAPI_MILTER_PATH) $(SAPI_LITESPEED_PATH) $(SAPI_FPM_PATH) $(OVERALL_TARGET) modules/* libs/*

distclean: clean
	rm -f Makefile config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h main/internal_functions_cli.c main/internal_functions.c stamp-h sapi/apache/libphp$(PHP_MAJOR_VERSION).module sapi/apache_hooks/libphp$(PHP_MAJOR_VERSION).module buildmk.stamp Zend/zend_dtrace_gen.h Zend/zend_dtrace_gen.h.bak Zend/zend_config.h TSRM/tsrm_config.h
	rm -f php7.spec main/build-defs.h scripts/phpize
	rm -f ext/date/lib/timelib_config.h ext/mbstring/oniguruma/config.h ext/mbstring/libmbfl/config.h ext/oci8/oci8_dtrace_gen.h ext/oci8/oci8_dtrace_gen.h.bak
	rm -f scripts/man1/phpize.1 scripts/php-config scripts/man1/php-config.1 sapi/cli/php.1 sapi/cgi/php-cgi.1 ext/phar/phar.1 ext/phar/phar.phar.1
	rm -f sapi/fpm/php-fpm.conf sapi/fpm/init.d.php-fpm sapi/fpm/php-fpm.service sapi/fpm/php-fpm.8 sapi/fpm/status.html
	rm -f ext/iconv/php_have_bsd_iconv.h ext/iconv/php_have_glibc_iconv.h ext/iconv/php_have_ibm_iconv.h ext/iconv/php_have_iconv.h ext/iconv/php_have_libiconv.h ext/iconv/php_iconv_aliased_libiconv.h ext/iconv/php_iconv_supports_errno.h ext/iconv/php_php_iconv_h_path.h ext/iconv/php_php_iconv_impl.h
	rm -f ext/phar/phar.phar ext/phar/phar.php
	if test "$(srcdir)" != "$(builddir)"; then \
	  rm -f ext/phar/phar/phar.inc; \
	fi
	$(EGREP) define'.*include/php' $(top_srcdir)/configure | $(SED) 's/.*>//'|xargs rm -f

prof-gen:
	CCACHE_DISABLE=1 $(MAKE) PROF_FLAGS=-fprofile-generate all

prof-clean:
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	rm -f libphp$(PHP_MAJOR_VERSION).la $(SAPI_CLI_PATH) $(SAPI_CGI_PATH) $(SAPI_MILTER_PATH) $(SAPI_LITESPEED_PATH) $(SAPI_FPM_PATH) $(OVERALL_TARGET) modules/* libs/*

prof-use:
	CCACHE_DISABLE=1 $(MAKE) PROF_FLAGS=-fprofile-use all


.PHONY: all clean install distclean test prof-gen prof-clean prof-use
.NOEXPORT:
vii.lo: /Users/Macx/www/zephir/ext/vii.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii.c -o vii.lo 
kernel/main.lo: /Users/Macx/www/zephir/ext/kernel/main.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/main.c -o kernel/main.lo 
kernel/memory.lo: /Users/Macx/www/zephir/ext/kernel/memory.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/memory.c -o kernel/memory.lo 
kernel/exception.lo: /Users/Macx/www/zephir/ext/kernel/exception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/exception.c -o kernel/exception.lo 
kernel/hash.lo: /Users/Macx/www/zephir/ext/kernel/hash.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/hash.c -o kernel/hash.lo 
kernel/debug.lo: /Users/Macx/www/zephir/ext/kernel/debug.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/debug.c -o kernel/debug.lo 
kernel/backtrace.lo: /Users/Macx/www/zephir/ext/kernel/backtrace.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/backtrace.c -o kernel/backtrace.lo 
kernel/object.lo: /Users/Macx/www/zephir/ext/kernel/object.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/object.c -o kernel/object.lo 
kernel/array.lo: /Users/Macx/www/zephir/ext/kernel/array.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/array.c -o kernel/array.lo 
kernel/extended/array.lo: /Users/Macx/www/zephir/ext/kernel/extended/array.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/extended/array.c -o kernel/extended/array.lo 
kernel/string.lo: /Users/Macx/www/zephir/ext/kernel/string.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/string.c -o kernel/string.lo 
kernel/fcall.lo: /Users/Macx/www/zephir/ext/kernel/fcall.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/fcall.c -o kernel/fcall.lo 
kernel/extended/fcall.lo: /Users/Macx/www/zephir/ext/kernel/extended/fcall.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/extended/fcall.c -o kernel/extended/fcall.lo 
kernel/require.lo: /Users/Macx/www/zephir/ext/kernel/require.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/require.c -o kernel/require.lo 
kernel/file.lo: /Users/Macx/www/zephir/ext/kernel/file.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/file.c -o kernel/file.lo 
kernel/operators.lo: /Users/Macx/www/zephir/ext/kernel/operators.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/operators.c -o kernel/operators.lo 
kernel/math.lo: /Users/Macx/www/zephir/ext/kernel/math.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/math.c -o kernel/math.lo 
kernel/concat.lo: /Users/Macx/www/zephir/ext/kernel/concat.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/concat.c -o kernel/concat.lo 
kernel/variables.lo: /Users/Macx/www/zephir/ext/kernel/variables.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/variables.c -o kernel/variables.lo 
kernel/filter.lo: /Users/Macx/www/zephir/ext/kernel/filter.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/filter.c -o kernel/filter.lo 
kernel/iterator.lo: /Users/Macx/www/zephir/ext/kernel/iterator.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/iterator.c -o kernel/iterator.lo 
kernel/time.lo: /Users/Macx/www/zephir/ext/kernel/time.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/time.c -o kernel/time.lo 
kernel/exit.lo: /Users/Macx/www/zephir/ext/kernel/exit.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/kernel/exit.c -o kernel/exit.lo 
vii/interfaces/iocinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/iocinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/iocinterface.zep.c -o vii/interfaces/iocinterface.lo 
vii/interfaces/configinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/configinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/configinterface.zep.c -o vii/interfaces/configinterface.lo 
vii/interfaces/sessionadapterinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/sessionadapterinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/sessionadapterinterface.zep.c -o vii/interfaces/sessionadapterinterface.lo 
vii/config.lo: /Users/Macx/www/zephir/ext/vii/config.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/config.zep.c -o vii/config.lo 
vii/interfaces/engineinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/engineinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/engineinterface.zep.c -o vii/interfaces/engineinterface.lo 
vii/session/nativesession.lo: /Users/Macx/www/zephir/ext/vii/session/nativesession.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/session/nativesession.zep.c -o vii/session/nativesession.lo 
vii/interfaces/applicationinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/applicationinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/applicationinterface.zep.c -o vii/interfaces/applicationinterface.lo 
vii/interfaces/eventmanagerinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/eventmanagerinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/eventmanagerinterface.zep.c -o vii/interfaces/eventmanagerinterface.lo 
vii/interfaces/loaderinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/loaderinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/loaderinterface.zep.c -o vii/interfaces/loaderinterface.lo 
vii/interfaces/loginterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/loginterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/loginterface.zep.c -o vii/interfaces/loginterface.lo 
vii/interfaces/viewinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/viewinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/viewinterface.zep.c -o vii/interfaces/viewinterface.lo 
vii/ioc.lo: /Users/Macx/www/zephir/ext/vii/ioc.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/ioc.zep.c -o vii/ioc.lo 
vii/log/driver.lo: /Users/Macx/www/zephir/ext/vii/log/driver.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/log/driver.zep.c -o vii/log/driver.lo 
vii/mvc/view/engine/tiny/taglibarys.lo: /Users/Macx/www/zephir/ext/vii/mvc/view/engine/tiny/taglibarys.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/view/engine/tiny/taglibarys.zep.c -o vii/mvc/view/engine/tiny/taglibarys.lo 
vii/alias.lo: /Users/Macx/www/zephir/ext/vii/alias.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/alias.zep.c -o vii/alias.lo 
vii/assets/collection.lo: /Users/Macx/www/zephir/ext/vii/assets/collection.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/assets/collection.zep.c -o vii/assets/collection.lo 
vii/assets/inlines.lo: /Users/Macx/www/zephir/ext/vii/assets/inlines.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/assets/inlines.zep.c -o vii/assets/inlines.lo 
vii/assets/manager.lo: /Users/Macx/www/zephir/ext/vii/assets/manager.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/assets/manager.zep.c -o vii/assets/manager.lo 
vii/assets/resources.lo: /Users/Macx/www/zephir/ext/vii/assets/resources.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/assets/resources.zep.c -o vii/assets/resources.lo 
vii/config/json.lo: /Users/Macx/www/zephir/ext/vii/config/json.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/config/json.zep.c -o vii/config/json.lo 
vii/config/php.lo: /Users/Macx/www/zephir/ext/vii/config/php.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/config/php.zep.c -o vii/config/php.lo 
vii/cookie.lo: /Users/Macx/www/zephir/ext/vii/cookie.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/cookie.zep.c -o vii/cookie.lo 
vii/db.lo: /Users/Macx/www/zephir/ext/vii/db.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/db.zep.c -o vii/db.lo 
vii/db/pdo.lo: /Users/Macx/www/zephir/ext/vii/db/pdo.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/db/pdo.zep.c -o vii/db/pdo.lo 
vii/db/querybuilder.lo: /Users/Macx/www/zephir/ext/vii/db/querybuilder.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/db/querybuilder.zep.c -o vii/db/querybuilder.lo 
vii/dispatcher.lo: /Users/Macx/www/zephir/ext/vii/dispatcher.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/dispatcher.zep.c -o vii/dispatcher.lo 
vii/dump.lo: /Users/Macx/www/zephir/ext/vii/dump.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/dump.zep.c -o vii/dump.lo 
vii/event.lo: /Users/Macx/www/zephir/ext/vii/event.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/event.zep.c -o vii/event.lo 
vii/eventmanager.lo: /Users/Macx/www/zephir/ext/vii/eventmanager.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/eventmanager.zep.c -o vii/eventmanager.lo 
vii/exceptions/assetsexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/assetsexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/assetsexception.zep.c -o vii/exceptions/assetsexception.lo 
vii/exceptions/configexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/configexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/configexception.zep.c -o vii/exceptions/configexception.lo 
vii/exceptions/databaseexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/databaseexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/databaseexception.zep.c -o vii/exceptions/databaseexception.lo 
vii/exceptions/eventexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/eventexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/eventexception.zep.c -o vii/exceptions/eventexception.lo 
vii/exceptions/filenotexistsexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/filenotexistsexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/filenotexistsexception.zep.c -o vii/exceptions/filenotexistsexception.lo 
vii/exceptions/httpexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/httpexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/httpexception.zep.c -o vii/exceptions/httpexception.lo 
vii/exceptions/iocexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/iocexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/iocexception.zep.c -o vii/exceptions/iocexception.lo 
vii/exceptions/loaderexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/loaderexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/loaderexception.zep.c -o vii/exceptions/loaderexception.lo 
vii/exceptions/logexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/logexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/logexception.zep.c -o vii/exceptions/logexception.lo 
vii/exceptions/routerexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/routerexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/routerexception.zep.c -o vii/exceptions/routerexception.lo 
vii/exceptions/runtimeexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/runtimeexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/runtimeexception.zep.c -o vii/exceptions/runtimeexception.lo 
vii/exceptions/templateexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/templateexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/templateexception.zep.c -o vii/exceptions/templateexception.lo 
vii/exceptions/uploadfileexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/uploadfileexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/uploadfileexception.zep.c -o vii/exceptions/uploadfileexception.lo 
vii/exceptions/viewexception.lo: /Users/Macx/www/zephir/ext/vii/exceptions/viewexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/exceptions/viewexception.zep.c -o vii/exceptions/viewexception.lo 
vii/filesystem.lo: /Users/Macx/www/zephir/ext/vii/filesystem.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/filesystem.zep.c -o vii/filesystem.lo 
vii/helper.lo: /Users/Macx/www/zephir/ext/vii/helper.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/helper.zep.c -o vii/helper.lo 
vii/i18n.lo: /Users/Macx/www/zephir/ext/vii/i18n.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/i18n.zep.c -o vii/i18n.lo 
vii/interfaces/bootstrapinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/bootstrapinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/bootstrapinterface.zep.c -o vii/interfaces/bootstrapinterface.lo 
vii/interfaces/cacheinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/cacheinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/cacheinterface.zep.c -o vii/interfaces/cacheinterface.lo 
vii/interfaces/dbinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/dbinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/dbinterface.zep.c -o vii/interfaces/dbinterface.lo 
vii/interfaces/moduleinterface.lo: /Users/Macx/www/zephir/ext/vii/interfaces/moduleinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/interfaces/moduleinterface.zep.c -o vii/interfaces/moduleinterface.lo 
vii/iocdefault.lo: /Users/Macx/www/zephir/ext/vii/iocdefault.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/iocdefault.zep.c -o vii/iocdefault.lo 
vii/loader.lo: /Users/Macx/www/zephir/ext/vii/loader.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/loader.zep.c -o vii/loader.lo 
vii/log.lo: /Users/Macx/www/zephir/ext/vii/log.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/log.zep.c -o vii/log.lo 
vii/log/file.lo: /Users/Macx/www/zephir/ext/vii/log/file.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/log/file.zep.c -o vii/log/file.lo 
vii/mvc/application.lo: /Users/Macx/www/zephir/ext/vii/mvc/application.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/application.zep.c -o vii/mvc/application.lo 
vii/mvc/controller.lo: /Users/Macx/www/zephir/ext/vii/mvc/controller.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/controller.zep.c -o vii/mvc/controller.lo 
vii/mvc/model.lo: /Users/Macx/www/zephir/ext/vii/mvc/model.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/model.zep.c -o vii/mvc/model.lo 
vii/mvc/model/resultset.lo: /Users/Macx/www/zephir/ext/vii/mvc/model/resultset.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/model/resultset.zep.c -o vii/mvc/model/resultset.lo 
vii/mvc/router.lo: /Users/Macx/www/zephir/ext/vii/mvc/router.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/router.zep.c -o vii/mvc/router.lo 
vii/mvc/router/route.lo: /Users/Macx/www/zephir/ext/vii/mvc/router/route.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/router/route.zep.c -o vii/mvc/router/route.lo 
vii/mvc/view.lo: /Users/Macx/www/zephir/ext/vii/mvc/view.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/view.zep.c -o vii/mvc/view.lo 
vii/mvc/view/engine/sleet.lo: /Users/Macx/www/zephir/ext/vii/mvc/view/engine/sleet.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/view/engine/sleet.zep.c -o vii/mvc/view/engine/sleet.lo 
vii/mvc/view/engine/sleet/compiler.lo: /Users/Macx/www/zephir/ext/vii/mvc/view/engine/sleet/compiler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/view/engine/sleet/compiler.zep.c -o vii/mvc/view/engine/sleet/compiler.lo 
vii/mvc/view/engine/sleet/parser.lo: /Users/Macx/www/zephir/ext/vii/mvc/view/engine/sleet/parser.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/view/engine/sleet/parser.zep.c -o vii/mvc/view/engine/sleet/parser.lo 
vii/mvc/view/engine/tiny.lo: /Users/Macx/www/zephir/ext/vii/mvc/view/engine/tiny.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/view/engine/tiny.zep.c -o vii/mvc/view/engine/tiny.lo 
vii/mvc/view/engine/tiny/compiler.lo: /Users/Macx/www/zephir/ext/vii/mvc/view/engine/tiny/compiler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/view/engine/tiny/compiler.zep.c -o vii/mvc/view/engine/tiny/compiler.lo 
vii/mvc/view/engine/tiny/tag.lo: /Users/Macx/www/zephir/ext/vii/mvc/view/engine/tiny/tag.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/mvc/view/engine/tiny/tag.zep.c -o vii/mvc/view/engine/tiny/tag.lo 
vii/registry.lo: /Users/Macx/www/zephir/ext/vii/registry.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/registry.zep.c -o vii/registry.lo 
vii/request.lo: /Users/Macx/www/zephir/ext/vii/request.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/request.zep.c -o vii/request.lo 
vii/response.lo: /Users/Macx/www/zephir/ext/vii/response.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/response.zep.c -o vii/response.lo 
vii/session/adapter/file.lo: /Users/Macx/www/zephir/ext/vii/session/adapter/file.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/session/adapter/file.zep.c -o vii/session/adapter/file.lo 
vii/session/adapter/memcache.lo: /Users/Macx/www/zephir/ext/vii/session/adapter/memcache.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/session/adapter/memcache.zep.c -o vii/session/adapter/memcache.lo 
vii/uploadfileinfo.lo: /Users/Macx/www/zephir/ext/vii/uploadfileinfo.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/uploadfileinfo.zep.c -o vii/uploadfileinfo.lo 
vii/urlmanager.lo: /Users/Macx/www/zephir/ext/vii/urlmanager.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/urlmanager.zep.c -o vii/urlmanager.lo 
vii/0__closure.lo: /Users/Macx/www/zephir/ext/vii/0__closure.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/0__closure.zep.c -o vii/0__closure.lo 
vii/1__closure.lo: /Users/Macx/www/zephir/ext/vii/1__closure.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/Macx/www/zephir/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/Macx/www/zephir/ext/vii/1__closure.zep.c -o vii/1__closure.lo 
$(phplibdir)/vii.la: ./vii.la
	$(LIBTOOL) --mode=install cp ./vii.la $(phplibdir)

./vii.la: $(shared_objects_vii) $(VII_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(EXTRA_LDFLAGS) $(shared_objects_vii) $(VII_SHARED_LIBADD)

