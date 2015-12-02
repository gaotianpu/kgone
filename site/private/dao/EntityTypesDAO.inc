<?php
class EntityTypesDAO extends BaseDAO {

    function get($pk_id) {
        $sql = "select pk_id,name,name_cn,category_1,category_2,schema_txt,status,create_date,last_update,entity_count,property_count,site_count,sites,last_stati from entity_types where pk_id=:pk_id";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":pk_id"=>$pk_id));
        $vo = new EntityTypes();
        $this->getFromResult($vo,$p) ; 
        return $vo;
    }

    function get_by_name($name){
        $sql = "select pk_id,name,name_cn,category_1,category_2,schema_txt,status,create_date,last_update,entity_count,property_count,site_count,sites,last_stati from entity_types where name=:name";
        $p = $this->dbR->prepare($sql);
        $p->execute(array(":name"=>$name));

        if(($r = $p->fetch(PDO::FETCH_ASSOC)) !== false){
            // print_r($r);
            return $r;
        }
        return false ; 
    }

    function load(){
        $sql = "select pk_id,name,name_cn,entity_count,property_count,sites from entity_types order by category_1,category_2,pk_id";
        $p = $this->dbR->prepare($sql);
        $p->execute();

        if(($rows = $p->fetchAll(PDO::FETCH_ASSOC)) !== false){
            return $rows ;
        } 

        return False ;

    }


    function save(&$vo) { if ($vo->pk_id == 0) { $this->insert($vo); } else { $this->update($vo); } }
    
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
            $vo->name_cn = $r["name_cn"];
            $vo->category_1 = $r["category_1"];
            $vo->category_2 = $r["category_2"];
            $vo->schema = $r["schema"];
            $vo->status = $r["status"];
            $vo->create_date = $r["create_date"];
            $vo->last_update = $r["last_update"];
            $vo->entity_count = $r["entity_count"];
            $vo->property_count = $r["property_count"];
            $vo->site_count = $r["site_count"];
            $vo->sites = $r["sites"];
            $vo->last_stati = $r["last_stati"];
        }}
        function update(&$vo) {
            $fields = array();
            $arr = array(":pk_id"=>$vo->pk_id);
            if(!is_null($vo->name)){$arr[":name"] = $vo->name;$fields[]="name=:name";  }
            if(!is_null($vo->name_cn)){$arr[":name_cn"] = $vo->name_cn;$fields[]="name_cn=:name_cn";  }
            if(!is_null($vo->category_1)){$arr[":category_1"] = $vo->category_1;$fields[]="category_1=:category_1";  }
            if(!is_null($vo->category_2)){$arr[":category_2"] = $vo->category_2;$fields[]="category_2=:category_2";  }
            if(!is_null($vo->schema)){$arr[":schema"] = $vo->schema;$fields[]="schema=:schema";  }
            if(!is_null($vo->status)){$arr[":status"] = $vo->status;$fields[]="status=:status";  }
            if(!is_null($vo->entity_count)){$arr[":entity_count"] = $vo->entity_count;$fields[]="entity_count=:entity_count";  }
            if(!is_null($vo->property_count)){$arr[":property_count"] = $vo->property_count;$fields[]="property_count=:property_count";  }
            if(!is_null($vo->site_count)){$arr[":site_count"] = $vo->site_count;$fields[]="site_count=:site_count";  }
            if(!is_null($vo->sites)){$arr[":sites"] = $vo->sites;$fields[]="sites=:sites";  }
            if(!is_null($vo->last_stati)){$arr[":last_stati"] = $vo->last_stati;$fields[]="last_stati=:last_stati";  }
            $fields[]="last_update=now()";
            $sql = "update entity_types set ". join(",",$fields) ." where pk_id=:pk_id";
            $p = $this->dbW->prepare($sql);
            $p->execute($arr);
            $p->rowCount();  
        }
        function insert(&$vo) {
            $sql = "insert into entity_types (name,name_cn,category_1,category_2,schema,status,create_date,last_update,entity_count,property_count,site_count,sites,last_stati) values(:name,:name_cn,:category_1,:category_2,:schema,0,now(),now(),:entity_count,:property_count,:site_count,:sites,:last_stati)";
            $p = $this->dbW->prepare($sql);
            $p->execute(array(":name"=>$vo->name,":name_cn"=>$vo->name_cn,":category_1"=>$vo->category_1,":category_2"=>$vo->category_2,":schema"=>$vo->schema,":entity_count"=>$vo->entity_count,":property_count"=>$vo->property_count,":site_count"=>$vo->site_count,":sites"=>$vo->sites,":last_stati"=>$vo->last_stati));
            $vo->pk_id = $this->dbW->lastinsertid();  
        }
    }
    ?>
