<?php
class UploadRecordsDAO extends BaseDAO {
    function insert($user_id,$type_id,$notes,$jsonld,$batch_no) {
        $sql = "insert into upload_records (user_id,type_id,batch_no,jsonld,notes,status,create_date) values(:user_id,:type_id,:batch_no,:jsonld,:notes,0,now())";
        $p = $this->dbW->prepare($sql);
        $p->execute(
            array(":user_id"=>$user_id,
                ":type_id"=>$type_id,
                ":batch_no"=>$batch_no, //?
                ":notes"=>$notes,
                ":jsonld"=>$jsonld));
        return  $this->dbW->lastinsertid();  
    }

    function load_by_userId($userId){
        $sql = "select pk_id,user_id,type_id,batch_no,notes,jsonld,status,create_date,last_update,entity_count,property_count from upload_records where user_id=:user_id order by pk_id desc";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":user_id"=>$userId));

        if(($rows = $p->fetchAll(PDO::FETCH_ASSOC)) !== false){ 
            return $rows;
        }
        return false ; 
    }


    function save(&$vo) { if ($vo->pk_id == 0) { $this->insert($vo); } else { $this->update($vo); } }
    function get($pk_id) {
        $sql = "select pk_id,user_id,batch_no,jsonld,status,create_date,last_update from upload_records where pk_id=:pk_id";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":pk_id"=>$pk_id));
        $vo = new UploadBatches();
        $this->getFromResult($vo,$p) ; 
        return $vo;
    }

    function delete(&$vo) {
        $sql = "update upload_records set status=1 where pk_id=:pk_id ";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":pk_id"=>$vo->pk_id));
        $p->rowCount(); 
    }


#-- private functions
    function getFromResult(&$vo, $result) {
        if(($r = $result->fetch(PDO::FETCH_ASSOC)) !== false){
            $vo->pk_id = $r["pk_id"];
            $vo->user_id = $r["user_id"];
            $vo->batch_no = $r["batch_no"];
            $vo->jsonld = $r["jsonld"];
            $vo->status = $r["status"];
            $vo->create_date = $r["create_date"];
            $vo->last_update = $r["last_update"];
        }}
        function update(&$vo) {
            $fields = array();
            $arr = array(":pk_id"=>$vo->pk_id);
            if(!is_null($vo->user_id)){$arr[":user_id"] = $vo->user_id;$fields[]="user_id=:user_id";  }
            if(!is_null($vo->batch_no)){$arr[":batch_no"] = $vo->batch_no;$fields[]="batch_no=:batch_no";  }
            if(!is_null($vo->jsonld)){$arr[":jsonld"] = $vo->jsonld;$fields[]="jsonld=:jsonld";  }
            if(!is_null($vo->status)){$arr[":status"] = $vo->status;$fields[]="status=:status";  }
            $fields[]="last_update=now()";
            $sql = "update upload_batches set ". join(",",$fields) ." where pk_id=:pk_id";
            $p = $this->dbW->prepare($sql);
            $p->execute($arr);
            $p->rowCount();  
        }

    }
    ?>
