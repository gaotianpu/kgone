<?php
class BaseController{
    protected  $app; 
    protected $currentUser;

    function __construct($app) {
        $this->app = $app;

        $this->currentUser = $this->getCurrentUser();
    }

    protected function getCurrentUser(){
        if(isset($_SESSION['userId']) &&  isset($_SESSION['mobile'])){
            return array('userId'=>$_SESSION['userId'],'mobile'=>$_SESSION['mobile'] ); 
        }
        return false;
    }
}
?>