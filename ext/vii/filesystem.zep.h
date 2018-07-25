
extern zend_class_entry *vii_filesystem_ce;

ZEPHIR_INIT_CLASS(Vii_FileSystem);

PHP_METHOD(Vii_FileSystem, __construct);
PHP_METHOD(Vii_FileSystem, exception);
PHP_METHOD(Vii_FileSystem, exists);
PHP_METHOD(Vii_FileSystem, get);
PHP_METHOD(Vii_FileSystem, requireFile);
PHP_METHOD(Vii_FileSystem, put);
PHP_METHOD(Vii_FileSystem, prepend);
PHP_METHOD(Vii_FileSystem, delete);
PHP_METHOD(Vii_FileSystem, move);
PHP_METHOD(Vii_FileSystem, copy);
PHP_METHOD(Vii_FileSystem, name);
PHP_METHOD(Vii_FileSystem, extension);
PHP_METHOD(Vii_FileSystem, type);
PHP_METHOD(Vii_FileSystem, size);
PHP_METHOD(Vii_FileSystem, lastModified);
PHP_METHOD(Vii_FileSystem, isDirectory);
PHP_METHOD(Vii_FileSystem, isWritable);
PHP_METHOD(Vii_FileSystem, isFile);
PHP_METHOD(Vii_FileSystem, glob);
PHP_METHOD(Vii_FileSystem, files);
PHP_METHOD(Vii_FileSystem, makeDirectory);
PHP_METHOD(Vii_FileSystem, copyDirectory);
PHP_METHOD(Vii_FileSystem, deleteDirectory);
PHP_METHOD(Vii_FileSystem, cleanDirectory);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_exception, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_get, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_requirefile, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_put, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_prepend, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_move, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_copy, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_name, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_extension, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_type, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_size, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_lastmodified, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_isdirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_iswritable, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_isfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_glob, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_files, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_makedirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, mode)
	ZEND_ARG_INFO(0, recursive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_copydirectory, 0, 0, 2)
	ZEND_ARG_INFO(0, directory)
	ZEND_ARG_INFO(0, destination)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_deletedirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
	ZEND_ARG_INFO(0, preserve)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_filesystem_cleandirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_filesystem_method_entry) {
	PHP_ME(Vii_FileSystem, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_FileSystem, exception, arginfo_vii_filesystem_exception, ZEND_ACC_PRIVATE)
	PHP_ME(Vii_FileSystem, exists, arginfo_vii_filesystem_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, get, arginfo_vii_filesystem_get, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, requireFile, arginfo_vii_filesystem_requirefile, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, put, arginfo_vii_filesystem_put, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, prepend, arginfo_vii_filesystem_prepend, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, delete, arginfo_vii_filesystem_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, move, arginfo_vii_filesystem_move, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, copy, arginfo_vii_filesystem_copy, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, name, arginfo_vii_filesystem_name, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, extension, arginfo_vii_filesystem_extension, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, type, arginfo_vii_filesystem_type, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, size, arginfo_vii_filesystem_size, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, lastModified, arginfo_vii_filesystem_lastmodified, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, isDirectory, arginfo_vii_filesystem_isdirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, isWritable, arginfo_vii_filesystem_iswritable, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, isFile, arginfo_vii_filesystem_isfile, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, glob, arginfo_vii_filesystem_glob, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, files, arginfo_vii_filesystem_files, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, makeDirectory, arginfo_vii_filesystem_makedirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, copyDirectory, arginfo_vii_filesystem_copydirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, deleteDirectory, arginfo_vii_filesystem_deletedirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_FileSystem, cleanDirectory, arginfo_vii_filesystem_cleandirectory, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
