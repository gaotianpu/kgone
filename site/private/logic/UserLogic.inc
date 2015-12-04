<?php
class UserLogic {

    protected $dao;

    function __construct() { 
        $this->dao = new UsersDAO();
    }


    function login($mobile,$password){ 

        $user = $this->dao->load_by_mobile($mobile); 

        if(isset($user)){ 

            if ( password_verify($password,$user['password']) ===true ){ 
                return $user['pk_id'];

            }else{

                return false;
            }
        }
    }



    function register($mobile,$password,$validateCode){
        $passwordHash = password_hash($password,PASSWORD_DEFAULT, ['cost' => 12]);
        if($passwordHash===false){
            throw new Exception('Password hash failed');
        } 

        $nick_name = $mobile; 

        $dao = new UsersDAO();
        $userId = $dao->insert($mobile,$passwordHash,$nick_name); 

        return $userId; 
    }

}
?>
