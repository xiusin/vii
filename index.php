<?php
use Vii\Mvc\Application;
use Vii\IocDefault;
$register = new IocDefault();

//此处必须注入loader 否则代码 
$register->set("loader","Vii\\Loader");

$register['alias']->set([
    "@app"=>"applications",
    "@backend"=>"@app/backend",
    "@frontend"=> "@app/frontend"
]);

$application = new Application($register,"vendor/autoload.php");
$register["router"]
    ->setDefaultModule("frontend")
    ->add("/:module/:controller/:action/:params",[
      "module"=>1,
      "controller"=>2,
      "action"=>3,
      "params"=>4
    ]);

$application->registerModules([
    "backend"=>[
        "className"=>"Multi\\Backend\\Module",
        "path"=>"@backend/module.php"
    ],
    "frontend"=>[
        "className"=>"Multi\\Frontend\\Module",
        "path"=>"@frontend/module.php"
    ]
]);

$register->set("applications", $application);

echo $application->debug(true)->bootstrap("@app/bootstrap.php")->handle();
