<?php
class FeedController {
    protected  $app;

    function __construct($app) {
        $this->app = $app;
    }

     function get($name){
     $r = $this->app->request();
     // $username = $r->params('username'); // $app->request()->params('username');

     $dao = new EntityTypesDAO(); 

     $entdao = new EntitiesDAO();


     $main = $dao->get_by_name($name);

     // print_r($main);

     $tdl=array('title'=> $main['name_cn'] . ' '. $main['name'],
        'keywords'=>' ',
        'description'=>' '); 

       $rows = array();
       $rows[] = array('name' =>'星美国际影城' ,'pk_id' =>'1', 'sites' =>'糯米 美团 大众点评 豆瓣');  
       $rows = $entdao->load($name);

     $this->app->render('entityType.inc', array('tdl' => $tdl, 'main'=>$main, 'rows'=>$rows));

 }
}
?>
