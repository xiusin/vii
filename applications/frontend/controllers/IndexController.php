<?php
namespace Multi\Frontend\Controller;

use Vii\Mvc\Controller;

use Vii\Mvc\Application;

class IndexController extends Controller
{
    public function indexAction()
    {
        $this->view->setVar("name", " framework vii " . Application::VERSION);
    }
}
