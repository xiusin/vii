<?php
use Vii\Config;
use Vii\Interfaces\BootstrapInterface;
use Vii\Interfaces\IocInterface;
use Vii\Mvc\View\Engine\Tiny;
use Vii\Db;
//use Illuminate\Contracts\Events\Dispatcher;
//use Illuminate\Container\Container;
use Illuminate\Database\Capsule\Manager as Capsule;

class Bootstrap implements BootstrapInterface
{
    public $ioc;
    public function __construct(IocInterface $ioc)
    {
        $this->ioc = $ioc;
    }

    public function initconfig()
    {
        $config = new Config([
            "db" => [
                "driver" => 'mysql',
                "server" => 'qdm19508111.my3w.com',
                "port" => '3306',
                "dbname" => 'qdm19508111_db',
                "user" => 'qdm19508111',
                "password" => 'ccb159781',
                "charset" => "utf8",
                "collation"=>'utf8_unicode_ci',
                "prefix"=>""
            ]
        ]);
        $this->ioc->set("config", $config);
    }

    public function initdb(){
        $config = $this->ioc->config;
        $this->ioc->set("db",function () use ($config){
            return new Db(
                $config->db->driver,
                $config->db->server,
                $config->db->port,
                $config->db->dbname,
                $config->db->user,
                $config->db->password
            );
        });
    }

    public function initview(){
        $this->ioc->get("view")->setViewsDir("applications/views/");
        $this->ioc->get("view")->setPartialsDir("partials/");
        $this->ioc->get("view")->setEngines([
            ".sleet" => function ($view,$service){
                $sleet = new Vii\Mvc\View\Engine\Sleet($view,$service);

                $sleet->setOptions([
                    "compile"=> true
                ]);
                return $sleet;
            },
            // ".twig" => function ($view,$service){
            //     $loader = new Twig_Loader_Filesystem('applications/templates');
            //     $cacheDir = "applications/runtime";
            //     return new Twig_Environment($loader, array(
            //             'cache' => $cacheDir,
            //     ));
            // },
            // ".tiny" => function ($view,$service){
            //     $tiny = new Tiny($view,$service);
            //     $tiny->getComiler()->setVarString();    //设置模板替换变量
            //     return $tiny;
            // },
        ]);
    }

    public function initwhoops(){
        // $whoops = new \Whoops\Run;
        // $whoops->pushHandler(new \Whoops\Handler\PrettyPageHandler);
        // $whoops->register();
    }

    public function initi18n(){
        $this->ioc->set("i18n",function (){
            return Vii\I18n::getDefault([
                  "lang"=>"zh",
                  "dir"=>"app/lang/"
             ]);
         });
    }

    public function initnotfound(){
        $this->ioc->get("router")->setNotFound(function (){
            die("我是初始化定義的notfound");
        });
    }

    public function initorm(){
        // $config = $this->ioc->config;
        // $capsule = new Capsule;
        // $capsule->addConnection([
        //     'driver'    => $config->db->driver,
        //     'host'      => $config->db->server,
        //     'database'  => $config->db->dbname,
        //     'username'  => $config->db->user,
        //     'password'  => $config->db->password,
        //     'charset'   => $config->db->charset,
        //     'collation' => $config->db->collation,
        //     'prefix'    => $config->db->prefix,
        // ]);
        // $capsule->setAsGlobal();
        // $capsule->bootEloquent();
    }

    public function initmyorm(){
        // use Vii\Mvc\Application;
        // use Vii\ServiceDefault;
        // use Vii\Db;
        // $register = new ServiceDefault();
        // $register->set("db",function (){
        //     return new Db("mysql","qdm19508111.my3w.com","3306","qdm19508111_db","qdm19508111","ccb159781");
        // });
        // var_dump($register
        // ->get("db")
        // ->createBuilder()->delete("test",[
        //     "condition1"=>"条件1",
        //     "or"=>[
        //         ["id"=>1],
        //         ["username"=>"45"],
        //         ["age"=>[">"=>"18"]]
        //     ]
        // ]));
    }
}
