
extern zend_class_entry *vii_db_pdo_ce;

ZEPHIR_INIT_CLASS(Vii_Db_Pdo);

PHP_METHOD(Vii_Db_Pdo, __construct);
PHP_METHOD(Vii_Db_Pdo, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_pdo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_vii_db_pdo___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(vii_db_pdo_method_entry) {
	PHP_ME(Vii_Db_Pdo, __construct, arginfo_vii_db_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Vii_Db_Pdo, __call, arginfo_vii_db_pdo___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
