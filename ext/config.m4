PHP_ARG_ENABLE(vii, whether to enable vii, [ --enable-vii   Enable Vii])

if test "$PHP_VII" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, VII_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_VII, 1, [Whether you have Vii])
	vii_sources="vii.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c vii/interfaces/iocinterface.zep.c
	vii/interfaces/configinterface.zep.c
	vii/interfaces/sessionadapterinterface.zep.c
	vii/config.zep.c
	vii/interfaces/engineinterface.zep.c
	vii/session/nativesession.zep.c
	vii/interfaces/applicationinterface.zep.c
	vii/interfaces/eventmanagerinterface.zep.c
	vii/interfaces/loaderinterface.zep.c
	vii/interfaces/loginterface.zep.c
	vii/interfaces/viewinterface.zep.c
	vii/ioc.zep.c
	vii/log/driver.zep.c
	vii/mvc/view/engine/tiny/taglibarys.zep.c
	vii/alias.zep.c
	vii/assets/collection.zep.c
	vii/assets/inlines.zep.c
	vii/assets/manager.zep.c
	vii/assets/resources.zep.c
	vii/config/json.zep.c
	vii/config/php.zep.c
	vii/cookie.zep.c
	vii/db.zep.c
	vii/db/pdo.zep.c
	vii/db/querybuilder.zep.c
	vii/dispatcher.zep.c
	vii/dump.zep.c
	vii/event.zep.c
	vii/eventmanager.zep.c
	vii/exceptions/assetsexception.zep.c
	vii/exceptions/configexception.zep.c
	vii/exceptions/databaseexception.zep.c
	vii/exceptions/eventexception.zep.c
	vii/exceptions/filenotexistsexception.zep.c
	vii/exceptions/httpexception.zep.c
	vii/exceptions/iocexception.zep.c
	vii/exceptions/loaderexception.zep.c
	vii/exceptions/logexception.zep.c
	vii/exceptions/routerexception.zep.c
	vii/exceptions/runtimeexception.zep.c
	vii/exceptions/templateexception.zep.c
	vii/exceptions/uploadfileexception.zep.c
	vii/exceptions/viewexception.zep.c
	vii/filesystem.zep.c
	vii/helper.zep.c
	vii/i18n.zep.c
	vii/interfaces/bootstrapinterface.zep.c
	vii/interfaces/cacheinterface.zep.c
	vii/interfaces/dbinterface.zep.c
	vii/interfaces/moduleinterface.zep.c
	vii/iocdefault.zep.c
	vii/loader.zep.c
	vii/log.zep.c
	vii/log/file.zep.c
	vii/mvc/application.zep.c
	vii/mvc/controller.zep.c
	vii/mvc/model.zep.c
	vii/mvc/model/resultset.zep.c
	vii/mvc/router.zep.c
	vii/mvc/router/route.zep.c
	vii/mvc/view.zep.c
	vii/mvc/view/engine/sleet.zep.c
	vii/mvc/view/engine/sleet/compiler.zep.c
	vii/mvc/view/engine/sleet/parser.zep.c
	vii/mvc/view/engine/tiny.zep.c
	vii/mvc/view/engine/tiny/compiler.zep.c
	vii/mvc/view/engine/tiny/tag.zep.c
	vii/registry.zep.c
	vii/request.zep.c
	vii/response.zep.c
	vii/session/adapter/file.zep.c
	vii/session/adapter/memcache.zep.c
	vii/uploadfileinfo.zep.c
	vii/urlmanager.zep.c
	vii/0__closure.zep.c
	vii/1__closure.zep.c "
	PHP_NEW_EXTENSION(vii, $vii_sources, $ext_shared,, )
	PHP_SUBST(VII_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([vii], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([vii], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/vii], [php_VII.h])

fi
