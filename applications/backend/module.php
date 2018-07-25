<?php
namespace Multi\Backend;

use Vii\Interfaces\ModuleInterface;
use Vii\Interfaces\IocInterface;
use Vii\Loader;

class Module implements ModuleInterface
{
    public $loader;

    public function __construct()
    {
        $this->loader = new Loader();
    }

    //运行时不加上ServiceInterface定义会报不兼容错误
    public function registerServices(IocInterface $ioc)
    {

    }

    public function registerAutoloader()
    {
        $this->loader->registerNamespaces([
            "Multi\\Backend\\Controller" => "@backend/controllers",
            "Multi\\Backend\\Model" => "@backend/models",
        ])->register();
    }
}
