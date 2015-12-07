<?php
class UploadController extends BaseController {


  function get(){  

   $tdl=array('title'=>'数据上传',
    'keywords'=>'',
    'description'=>'');  

   $this->app->render('upload.inc', array('tdl' => $tdl, 'user'=>$this->currentUser ));

 }

 function post(){ 
  $userId = $this->currentUser['userId'];
  $typeId = $this->app->request()->params('typeId');
  $content = $this->app->request()->params('content');
  $notes  = $this->app->request()->params('notes');

  $dao = new UploadBatchesDAO();
  $batchId = $dao->insert($userId,$typeId,$notes,$content);
  

}


}
?>
