<?php
class IndexController extends BaseController{


  function get(){

   $r = $this->app->request();
     // $username = $r->params('username'); // $app->request()->params('username');

   $tdl=array('title'=>'KGone',
    'keywords'=>'KGone',
    'description'=>'面向开发者的结构化数据分享平台');

   $dao = new EntityTypesDAO(); 
   $rows = $dao->load(); 

       // $rows = array();
       // $rows[] = array('name_cn' =>'省/州' ,'name' =>'State' ,'entity_count' =>'2' , 'property_count' =>'8' , 'sites' =>'糯米 美团 大众点评 豆瓣');  

   $this->app->render('index.inc', 
    array('tdl' => $tdl,
      'user'=>$this->currentUser,
      'rows'=>$rows));

 }

 
}
?>