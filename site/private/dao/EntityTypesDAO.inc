<?php
class EntityTypesDAO extends BaseDAO {
function save(&$vo) { if ($vo->pk_id == 0) { $this->insert($vo); } else { $this->update($vo); } }
function get($pk_id) {
$sql = "select * from entity_types where pk_id=:pk_id";
$p = $this->dbR->prepare($sql);
$p->execute(array(":pk_id"=>$pk_id));
$vo = new EntityTypes();
$this->getFromResult($vo,$p) ; 
return $vo;
}
function delete(&$vo) {
$sql = "update entity_types set status=1 where pk_id=:pk_id ";
$p = $this->dbR->prepare($sql);
$p->execute(array(":pk_id"=>$vo->pk_id));
$p->rowCount(); 
}
#-- private functions
function getFromResult(&$vo, $result) {
if(($r = $result->fetch(PDO::FETCH_ASSOC)) !== false){
$vo->pk_id = $r["pk_id"];
$vo->name = $r["name"];
$vo->schema = $r["schema"];
$vo->status = $r["status"];
$vo->create_date = $r["create_date"];
$vo->last_update = $r["last_update"];
}}
function update(&$vo) {
$fields = array();
$arr = array(":pk_id"=>$vo->pk_id);
if(!is_null($vo->name)){$arr[":name"] = $vo->name;$fields[]="name=:name";  }
if(!is_null($vo->schema)){$arr[":schema"] = $vo->schema;$fields[]="schema=:schema";  }
if(!is_null($vo->status)){$arr[":status"] = $vo->status;$fields[]="status=:status";  }
$fields[]="last_update=now()";
$sql = "update entity_types set ". join(",",$fields) ." where pk_id=:pk_id";
$p = $this->dbW->prepare($sql);
$p->execute($arr);
$p->rowCount();  
}
function insert(&$vo) {
$sql = "insert into entity_types (name,schema,status,create_date,last_update) values(:name,:schema,0,now(),now())";
$p = $this->dbW->prepare($sql);
$p->execute(array(":name"=>$vo->name,":schema"=>$vo->schema));
$vo->pk_id = $this->dbW->lastinsertid();  
}
}
?>
