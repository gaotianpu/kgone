<?php
class EntityController extends BaseController {
    
    function get($id){
       $r = $this->app->request();

       $dao = new EntitiesDAO();
       $main = $dao->get($id); 

       $tdl=array('title'=>'KGone',
        'keywords'=>'',
        'description'=>'');  

       $this->app->render('entity.inc', array('tdl' => $tdl,'user'=>$this->currentUser,'main'=>$main));

   }
}
?>
