<?php
class RegisterController{
    protected  $app;

    function __construct($app) {
        $this->app = $app;
    }

    function get(){ 
     $r = $this->app->request();
        // $username = $r->params('username'); // $app->request()->params('username');

     $tdl=array('title'=>'新用户注册',
        'keywords'=>'',
        'description'=>'');
        // echo "hello,world";

     $this->app->render('register.inc', array('tdl' => $tdl));

 }

 function post(){
    $logic = new UserLogic();

    $mobile = $this->app->request()->params('mobile');
    $password = $this->app->request()->params('password');
    $smsCode = 1000; // $this->app->request()->params('smsCode'); 

    echo $mobile,$password;

    $userId = $logic->register($mobile,$password,$smsCode);
    echo $userId;
}

}
?>