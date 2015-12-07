<?php
class UploadRecordsLogic {
    function upload($userId,$type,$notes,$content){
        $dao = new UploadRecordsDAO();

        date_default_timezone_set('PRC');
        $batch_no =  date('YmdHis');  //date_format(date(),'YmdHisu'); //

        $batchId = $dao->insert( $userId,$type,$notes,$content,$batch_no);
        return $batchId;
    }
}
?>
