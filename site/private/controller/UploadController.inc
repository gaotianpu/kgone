<?php
class UploadController extends BaseController {
    

    function get(){
       $r = $this->app->request();
     // $username = $r->params('username'); // $app->request()->params('username');

       $dao = new EntityTypesDAO(); 
       $rows = $dao->load();

       $tdl=array('title'=>'数据上传',
        'keywords'=>'',
        'description'=>'');  

       $this->app->render('upload.inc', array('tdl' => $tdl, 'user'=>$this->currentUser,'rows'=>$rows));

   }

   function post(){

   }
}
?>
