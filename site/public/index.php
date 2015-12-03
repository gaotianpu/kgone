<?php
require '../vendor/autoload.php';
define('ROOT_DIR', dirname(__FILE__) . '/..');
require ROOT_DIR . '/private/config.inc';
require ROOT_DIR . '/private/base.inc';


$app = new \Slim\Slim();
$app->config(array(
    'debug' => true,
    'templates.path' => '../private/templates',
    'view' => '\Slim\View',
    ));

$app->group('/register', function () use ($app) {
    $c = new RegisterController($app);
    $app -> get('',function() use($c,$app){ 
        $c->get(); 
    });

    $app -> post('',function() use($c,$app){ 
        $c->post(); 
    });
});

$app->group('/login', function () use ($app) {
    $c = new LoginController($app);
    $app -> get('',function() use($c,$app){ 
        $c->get(); 
    });

    $app -> post('',function() use($c,$app){ 
        $c->post(); 
    });
});


$app -> get('/entity/:id',function($id) use($app){
   (new EntityController($app))->get($id); 
});

$app -> get('/upload',function() use($app){
   (new UploadController($app))->get(); 
});

$app -> get('/feed/:name',function($name) use($app){
   (new FeedController($app))->get($name); 
});

$app -> get('/download/:name',function($name) use($app){
   (new DownloadController($app))->get($name); 
});

$app -> get('/schema/:name',function($name) use($app){
   (new SchemaController($app))->get($name); 
});

$app -> get('/type/:name',function($name) use($app){
   (new EntityTypeController($app))->get($name); 
});


$app -> get('/',function() use($app){ 
    (new IndexController($app))->get(); 
});


$app->run();

?>