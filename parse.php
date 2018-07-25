<?php


$path   = __DIR__ . '/vii/i18n.zep';
$retval = zephir_parse_file(file_get_contents($path), $path);

var_export($retval);