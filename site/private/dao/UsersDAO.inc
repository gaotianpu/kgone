<?php
class UsersDAO extends BaseDAO {
    function load_by_mobile($mobile){
        $sql = "select pk_id,mobile,nick_name,password,creation_date,last_update from users where mobile=:mobile";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":mobile"=>$mobile));

        if(($r = $p->fetch(PDO::FETCH_ASSOC)) !== false){ 
             
            return $r;
        }
        return false ;  

    } 

    function insert($mobile,$password,$nick_name) {
        $sql = "insert into users (mobile,password,nick_name,creation_date) values(:mobile,:password,:nick_name,now())";
        $p = $this->dbW->prepare($sql);
        $p->execute(array(":mobile"=>$mobile,":password"=>$password,':nick_name'=>$nick_name));
        return $this->dbW->lastinsertid();  
    }


        ///

    function save(&$vo) { if ($vo->pk_id == 0) { $this->insert($vo); } else { $this->update($vo); } }
    function get($pk_id) {
        $sql = "select pk_id,mobile,email,nick_name,password,creation_date,last_update,last_login from users where pk_id=:pk_id";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":pk_id"=>$pk_id));
        $vo = new Users();
        $this->getFromResult($vo,$p) ; 
        return $vo;
    }
    function delete(&$vo) {
        $sql = "update users set status=1 where pk_id=:pk_id ";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":pk_id"=>$vo->pk_id));
        $p->rowCount(); 
    }
#-- private functions
    function getFromResult(&$vo, $result) {
        if(($r = $result->fetch(PDO::FETCH_ASSOC)) !== false){
            $vo->pk_id = $r["pk_id"];
            $vo->mobile = $r["mobile"];
            $vo->email = $r["email"];
            $vo->nick_name = $r["nick_name"];
            $vo->password = $r["password"];
            $vo->creation_date = $r["creation_date"];
            $vo->last_update = $r["last_update"];
            $vo->last_login = $r["last_login"];
        }}
        function update(&$vo) {
            $fields = array();
            $arr = array(":pk_id"=>$vo->pk_id);
            if(!is_null($vo->mobile)){$arr[":mobile"] = $vo->mobile;$fields[]="mobile=:mobile";  }
            if(!is_null($vo->email)){$arr[":email"] = $vo->email;$fields[]="email=:email";  }
            if(!is_null($vo->nick_name)){$arr[":nick_name"] = $vo->nick_name;$fields[]="nick_name=:nick_name";  }
            if(!is_null($vo->password)){$arr[":password"] = $vo->password;$fields[]="password=:password";  }
            if(!is_null($vo->creation_date)){$arr[":creation_date"] = $vo->creation_date;$fields[]="creation_date=:creation_date";  }
            if(!is_null($vo->last_login)){$arr[":last_login"] = $vo->last_login;$fields[]="last_login=:last_login";  }
            $fields[]="last_update=now()";
            $sql = "update users set ". join(",",$fields) ." where pk_id=:pk_id";
            $p = $this->dbW->prepare($sql);
            $p->execute($arr);
            $p->rowCount();  
        }
        
    }
    ?>
