<?php
namespace Multi\Frontend;

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
    public function registerServices(IocInterface $di)
    {
      $di->view->setViewsDir($di->get("view")->getViewsDir() . "frontend/");

    }

    public function registerAutoloader()
    {
        $this->loader->registerNamespaces([
            "Multi\\Frontend\\Controller" => "@frontend/controllers",
            "Multi\\Frontend\\Model" => "@frontend/models",
        ])->register();
    }

}
