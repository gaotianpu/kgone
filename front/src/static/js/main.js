require.config({
  baseUrl: 'lib',
  shim:{
    'bootstrap': ['jquery'], 
  },
  paths: {
    jquery: 'jquery-1.11.3.min',
    mustache: 'mustache',
    bootstrap: 'bootstrap', 
  }
});


//文件个数太多，这样写也挺麻烦的
require(['jquery','bootstrap','upload'], 
  function($,bootstrap,upload) {
    var path = window.location.pathname; 

    var urls = ["/upload$",upload];

    var len = urls.length/2;
    for(var i=0;i<=len;i=i+2){
      if( (new RegExp(urls[i]).test(path) )){ 
        urls[i+1].init();
        break;
      }

    } 

    // if( (new RegExp("/upload")).test(path) ){ 
    //   upload.init();
    // }

    // if( (new RegExp("/type/[^/]+")).test(path) ){ 
    //   alert('type');
    // }

    // if( (new RegExp("/schema/[^/]+")).test(path) ){ 
    //   alert('schema');
    // }
    // if( (new RegExp("/download/[^/]+")).test(path) ){ 
    //   alert('download');
    // }
    // if( (new RegExp("/feed/[^/]+")).test(path) ){ 
    //   alert('feed');
    // }



  });
