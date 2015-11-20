<?php
class EntityPagesDAO extends BaseDAO {
function save(&$vo) { if ($vo->pk_id == 0) { $this->insert($vo); } else { $this->update($vo); } }
function get($pk_id) {
$sql = "select * from entity_pages where pk_id=:pk_id";
$p = $this->dbR->prepare($sql);
$p->execute(array(":pk_id"=>$pk_id));
$vo = new EntityPages();
$this->getFromResult($vo,$p) ; 
return $vo;
}
function delete(&$vo) {
$sql = "update entity_pages set status=1 where pk_id=:pk_id ";
$p = $this->dbR->prepare($sql);
$p->execute(array(":pk_id"=>$vo->pk_id));
$p->rowCount(); 
}
#-- private functions
function getFromResult(&$vo, $result) {
if(($r = $result->fetch(PDO::FETCH_ASSOC)) !== false){
$vo->pk_id = $r["pk_id"];
$vo->entity_id = $r["entity_id"];
$vo->domain_main = $r["domain_main"];
$vo->domain = $r["domain"];
$vo->url = $r["url"];
$vo->uid = $r["uid"];
$vo->target_device = $r["target_device"];
$vo->status = $r["status"];
$vo->create_date = $r["create_date"];
$vo->last_update = $r["last_update"];
}}
function update(&$vo) {
$fields = array();
$arr = array(":pk_id"=>$vo->pk_id);
if(!is_null($vo->entity_id)){$arr[":entity_id"] = $vo->entity_id;$fields[]="entity_id=:entity_id";  }
if(!is_null($vo->domain_main)){$arr[":domain_main"] = $vo->domain_main;$fields[]="domain_main=:domain_main";  }
if(!is_null($vo->domain)){$arr[":domain"] = $vo->domain;$fields[]="domain=:domain";  }
if(!is_null($vo->url)){$arr[":url"] = $vo->url;$fields[]="url=:url";  }
if(!is_null($vo->uid)){$arr[":uid"] = $vo->uid;$fields[]="uid=:uid";  }
if(!is_null($vo->target_device)){$arr[":target_device"] = $vo->target_device;$fields[]="target_device=:target_device";  }
if(!is_null($vo->status)){$arr[":status"] = $vo->status;$fields[]="status=:status";  }
$fields[]="last_update=now()";
$sql = "update entity_pages set ". join(",",$fields) ." where pk_id=:pk_id";
$p = $this->dbW->prepare($sql);
$p->execute($arr);
$p->rowCount();  
}
function insert(&$vo) {
$sql = "insert into entity_pages (entity_id,domain_main,domain,url,uid,target_device,status,create_date,last_update) values(:entity_id,:domain_main,:domain,:url,:uid,:target_device,0,now(),now())";
$p = $this->dbW->prepare($sql);
$p->execute(array(":entity_id"=>$vo->entity_id,":domain_main"=>$vo->domain_main,":domain"=>$vo->domain,":url"=>$vo->url,":uid"=>$vo->uid,":target_device"=>$vo->target_device));
$vo->pk_id = $this->dbW->lastinsertid();  
}
}
?>
