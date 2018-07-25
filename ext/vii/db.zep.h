
extern zend_class_entry *vii_db_ce;

ZEPHIR_INIT_CLASS(Vii_Db);

PHP_METHOD(Vii_Db, getDriver);
PHP_METHOD(Vii_Db, setDriver);
PHP_METHOD(Vii_Db, __construct);
PHP_METHOD(Vii_Db, createBuilder);
PHP_METHOD(Vii_Db, begin);
PHP_METHOD(Vii_Db, rollback);
PHP_METHOD(Vii_Db, commit);
PHP_METHOD(Vii_Db, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_setdriver, 0, 0, 1)
	ZEND_ARG_INFO(0, driver)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, driver)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_db_method_entry) {
	PHP_ME(Vii_Db, getDriver, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db, setDriver, arginfo_vii_db_setdriver, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db, __construct, arginfo_vii_db___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Db, createBuilder, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Vii_Db, __call, arginfo_vii_db___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
