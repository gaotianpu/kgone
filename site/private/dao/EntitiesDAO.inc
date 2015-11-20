<?php
class EntitiesDAO extends BaseDAO {
function save(&$vo) { if ($vo->pk_id == 0) { $this->insert($vo); } else { $this->update($vo); } }
function get($pk_id) {
$sql = "select * from entities where pk_id=:pk_id";
$p = $this->dbR->prepare($sql);
$p->execute(array(":pk_id"=>$pk_id));
$vo = new Entities();
$this->getFromResult($vo,$p) ; 
return $vo;
}
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
