<?php
class UploadRecordsController extends BaseController {
    function get(){
        $userId = $this->currentUser['userId'];

        $dao = new UploadRecordsDAO();

        $rows = $dao->load_by_userId($userId);

        $tdl=array('title' =>'数据上传记录' , 'description'=>'','keywords'=>'' );
        return $this->app->render('uploadRecords.inc', 
            array('tdl' =>$tdl , 'user'=>$this->currentUser,'rows'=>$rows ));
    }
}
?>
