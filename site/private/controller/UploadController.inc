<?php
class UploadController extends BaseController {


  function get(){  
    $typeId = $this->app->request()->params('type');

   $tdl=array('title'=>'数据上传',
    'keywords'=>'',
    'description'=>'');  

   $dao = new EntityTypesDAO();
   $rows = $dao->load();

   $this->app->render('upload.inc', array('tdl' => $tdl, 'user'=>$this->currentUser,'rows'=>$rows,'typeId'=>$typeId ));

 }

 function post(){ 
  $userId = $this->currentUser['userId'];
  $typeId = $this->app->request()->params('typeId');
  $content = $this->app->request()->params('content');
  $notes  = $this->app->request()->params('notes');

  $logic = new UploadRecordsLogic();
  $batchId = $logic->upload($userId,$typeId,$notes,$content);

  $this->app->redirect('/upload/records');

}


}
?>
