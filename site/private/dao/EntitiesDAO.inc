<?php
class EntitiesDAO extends BaseDAO {

    function get($pk_id) {
        $sql = "select pk_id,type_id,name,jsonld,status,create_date,last_update from entities where pk_id=:pk_id";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":pk_id"=>$pk_id));

        if(($r = $p->fetch(PDO::FETCH_ASSOC)) !== false){
            // print_r($r);
            return $r;
        }
        return false ;  
    }


    function load($typeName){
        $sql = "select a.pk_id,a.type_id,b.name as type_name,a.name,a.jsonld,a.status,a.create_date,a.last_update from entities a left join entity_types b on a.type_id=b.pk_id where b.name=:typeName order by last_update desc limit 0,100";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":typeName"=>$typeName));

        if(($rows = $p->fetchAll(PDO::FETCH_ASSOC)) !== false){
            return $rows ;
        } 

        return False ;

    }


    function save(&$vo) { if ($vo->pk_id == 0) { $this->insert($vo); } else { $this->update($vo); } }
    
     

    function delete(&$vo) {
        $sql = "update entities set status=1 where pk_id=:pk_id ";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":pk_id"=>$vo->pk_id));
        $p->rowCount(); 
    }

#-- private functions
    function getFromResult(&$vo, $result) {
        if(($r = $result->fetch(PDO::FETCH_ASSOC)) !== false){
            $vo->pk_id = $r["pk_id"];
            $vo->type_id = $r["type_id"];
            $vo->name = $r["name"];
            $vo->jsonld = $r["jsonld"];
            $vo->status = $r["status"];
            $vo->create_date = $r["create_date"];
            $vo->last_update = $r["last_update"];
        }}
        function update(&$vo) {
            $fields = array();
            $arr = array(":pk_id"=>$vo->pk_id);
            if(!is_null($vo->type_id)){$arr[":type_id"] = $vo->type_id;$fields[]="type_id=:type_id";  }
            if(!is_null($vo->name)){$arr[":name"] = $vo->name;$fields[]="name=:name";  }
            if(!is_null($vo->jsonld)){$arr[":jsonld"] = $vo->jsonld;$fields[]="jsonld=:jsonld";  }
            if(!is_null($vo->status)){$arr[":status"] = $vo->status;$fields[]="status=:status";  }
            $fields[]="last_update=now()";
            $sql = "update entities set ". join(",",$fields) ." where pk_id=:pk_id";
            $p = $this->dbW->prepare($sql);
            $p->execute($arr);
            $p->rowCount();  
        }
        function insert(&$vo) {
            $sql = "insert into entities (type_id,name,jsonld,status,create_date,last_update) values(:type_id,:name,:jsonld,0,now(),now())";
            $p = $this->dbW->prepare($sql);
            $p->execute(array(":type_id"=>$vo->type_id,":name"=>$vo->name,":jsonld"=>$vo->jsonld));
            $vo->pk_id = $this->dbW->lastinsertid();  
        }
    }
    ?>
