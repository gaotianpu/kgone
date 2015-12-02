<?php
class UploadController {
    protected  $app;

    function __construct($app) {
        $this->app = $app;
    }

    function get(){
     $r = $this->app->request();
     // $username = $r->params('username'); // $app->request()->params('username');

     $dao = new EntityTypesDAO(); 
     $rows = $dao->load();

     $tdl=array('title'=>'KGone',
        'keywords'=>'KGone',
        'description'=>'面向开发者的结构化数据分享平台'); 

       $rows = array();
       $rows[] = array('name' =>'星美国际影城(北京回龙观店)' ,'pk_id' =>'1', 'sites' =>'糯米 美团 大众点评 豆瓣');  

     $this->app->render('upload.inc', array('tdl' => $tdl,'rows'=>$rows));

 }
}
?>
