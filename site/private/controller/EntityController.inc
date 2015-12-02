<?php
class EntityController {
    protected  $app;

    function __construct($app) {
        $this->app = $app;
    }

    function get($id){
       $r = $this->app->request();

       $dao = new EntitiesDAO();
       $main = $dao->get($id); 

       $tdl=array('title'=>'KGone',
        'keywords'=>'',
        'description'=>'');  

       $this->app->render('entity.inc', array('tdl' => $tdl,'main'=>$main));

   }
}
?>
