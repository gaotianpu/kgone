<?php
class CharEntitiesDAO extends BaseDAO {
function save(&$vo) { if ($vo->pk_id == 0) { $this->insert($vo); } else { $this->update($vo); } }
function get($pk_id) {
$sql = "select * from char_entities where pk_id=:pk_id";
$p = $this->dbR->prepare($sql);
$p->execute(array(":pk_id"=>$pk_id));
$vo = new CharEntities();
$this->getFromResult($vo,$p) ; 
return $vo;
}
function delete(&$vo) {
$sql = "update char_entities set status=1 where pk_id=:pk_id ";
$p = $this->dbR->prepare($sql);
$p->execute(array(":pk_id"=>$vo->pk_id));
$p->rowCount(); 
}
#-- private functions
function getFromResult(&$vo, $result) {
if(($r = $result->fetch(PDO::FETCH_ASSOC)) !== false){
$vo->pk_id = $r["pk_id"];
$vo->char = $r["char"];
$vo->entity_type_id = $r["entity_type_id"];
$vo->entity_id = $r["entity_id"];
$vo->status = $r["status"];
$vo->create_date = $r["create_date"];
$vo->last_update = $r["last_update"];
}}
function update(&$vo) {
$fields = array();
$arr = array(":pk_id"=>$vo->pk_id);
if(!is_null($vo->char)){$arr[":char"] = $vo->char;$fields[]="char=:char";  }
if(!is_null($vo->entity_type_id)){$arr[":entity_type_id"] = $vo->entity_type_id;$fields[]="entity_type_id=:entity_type_id";  }
if(!is_null($vo->entity_id)){$arr[":entity_id"] = $vo->entity_id;$fields[]="entity_id=:entity_id";  }
if(!is_null($vo->status)){$arr[":status"] = $vo->status;$fields[]="status=:status";  }
$fields[]="last_update=now()";
$sql = "update char_entities set ". join(",",$fields) ." where pk_id=:pk_id";
$p = $this->dbW->prepare($sql);
$p->execute($arr);
$p->rowCount();  
}
function insert(&$vo) {
$sql = "insert into char_entities (char,entity_type_id,entity_id,status,create_date,last_update) values(:char,:entity_type_id,:entity_id,0,now(),now())";
$p = $this->dbW->prepare($sql);
$p->execute(array(":char"=>$vo->char,":entity_type_id"=>$vo->entity_type_id,":entity_id"=>$vo->entity_id));
$vo->pk_id = $this->dbW->lastinsertid();  
}
}
?>
