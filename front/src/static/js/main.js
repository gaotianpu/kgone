//1.require.config是可以单独放在一个文件中？
require.config({
  baseUrl: 'lib',
  shim:{
    'bootstrap': ['jquery'], 
  },
  paths: {
    jquery: 'jquery-1.11.3.min',
    mustache: 'mustache',
    bootstrap: 'bootstrap.min', 
  }
});


//文件个数太多，这样写也挺麻烦的
require(['jquery','pedit'], 
  function($,pedit) { 
    
    pedit.init();

  });

/*
1.使用requirejs
http://www.cnblogs.com/snandy/archive/2012/05/22/2513652.html
require函数的第一个参数是数组，数组中存放的是模块名（字符串类型），数组中的模块与回调函数的参数一一对应。
http://www.ibm.com/developerworks/cn/web/1209_shiwei_requirejs/#author1
http://www.cnblogs.com/snandy/archive/2012/06/04/2532997.html
http://www.cnblogs.com/snandy/archive/2012/06/06/2536969.html
r.js 压缩合并 (这个东西与gulp的联系？)


2.走通使用r.js合并reuirejs模块 (似乎gulp没办法很好的和这r.hs融合，gulp使用的是amdOptimize)
http://segmentfault.com/a/1190000000394849
http://segmentfault.com/a/1190000000395435
http://nomospace.com/posts/r.js-example.build.js.html


3. 使用gulp合并requirejs模块
项目编写的js需要打包合并成一个js，而对于jquery这样的js类库，无需打包？
https://www.npmjs.com/package/amd-optimize/
http://blog.csdn.net/ft6302244/article/details/44308215
http://stackoverflow.com/questions/23978361/using-gulp-to-build-requirejs-project-gulp-requirejs
http://segmentfault.com/a/1190000002876583
npm install amd-optimize --save-dev
var amdOptimize = require('amd-optimize');
var concat = require('gulp-concat');
gulp.task('bundle', function ()
{
    return gulp.src('*.js')
        .pipe(amdOptimize('main'))
        .pipe(concat('main-bundle.js'))
        .pipe(gulp.dest('dist'));
});

*/