<?php
class LoginController extends BaseController{ 

    function get(){ 
       $r = $this->app->request(); 

       $tdl=array('title'=>'用户登录',
        'keywords'=>'keywords',
        'description'=>'description'); 

       $this->app->render('login.inc', array('tdl' => $tdl));

   }

   function post(){ 
    $mobile = $this->app->request()->params('mobile');
    $password = $this->app->request()->params('password');

    $logic = new UserLogic();
    $userId = $logic->login($mobile,$password);

    $_SESSION['userId']=$userId;
    $_SESSION['mobile']=$mobile;


    $this->app->response->redirect('/',302);
}


}
?>