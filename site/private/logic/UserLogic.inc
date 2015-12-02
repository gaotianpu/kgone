<?php
class UserLogic {

    protected $dao;

    function __construct() { 
        $this->dao = new UsersDAO();
    }


    function login($mobile,$password){
        $user = $this->dao->load_by_mobile($mobile);



        if( isset($user)){
            //md5 ?
            if ($user['password']==$password){
                return $user['pk_id'];
            }
        }

        return false;

    }

    function register($mobile,$password,$validateCode){
        //validateCode? save it to redis, 并设置过期时间

        //$password md5 
        $nick_name = $mobile;

        // print_r($this->dao);

        $dao = new UsersDAO();
        $userId = $dao->insert($mobile,$password,$nick_name);

        // $userId = $this->dao->insert($mobile,$password,$nick_name);

        return $userId; 
    }

}
?>
