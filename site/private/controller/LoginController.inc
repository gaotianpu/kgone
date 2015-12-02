<?php
class LoginController{
    protected  $app;

    function __construct($app) {
        $this->app = $app;
    }

    function get(){

       $r = $this->app->request();
     // $username = $r->params('username'); // $app->request()->params('username');

       $tdl=array('title'=>'用户登录',
        'keywords'=>'keywords',
        'description'=>'description');
        // echo "hello,world";

       $this->app->render('login.inc', array('tdl' => $tdl));

   }

   function post(){
    $logic = new UserLogic();

    $mobile = $this->app->request()->params('mobile');
    $password = $this->app->request()->params('password');
     

    $userId = $logic->login($mobile,$password);

    echo $userId;
}


}
?>