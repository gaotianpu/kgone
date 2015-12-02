var gulp = require('gulp'),
sass = require('gulp-ruby-sass'),
autoprefixer = require('gulp-autoprefixer'),
minifycss = require('gulp-minify-css'),
jshint = require('gulp-jshint'),
uglify = require('gulp-uglify'),
imagemin = require('gulp-imagemin'),
rename = require('gulp-rename'),
concat = require('gulp-concat'),
notify = require('gulp-notify'),
cache = require('gulp-cache'),
contentIncluder = require('gulp-content-includer'),
livereload = require('gulp-livereload'),
del = require('del');

/*
npm install gulp-content-includer gulp-ruby-sass gulp-autoprefixer gulp-minify-css gulp-jshint gulp-concat gulp-uglify gulp-imagemin gulp-notify gulp-rename gulp-livereload gulp-cache del --save-dev
*/
// 

//js语法检查
gulp.task('jshint',function () {
  return gulp.src('./src/static/js/*.js')
  .pipe(jshint())
  .pipe(jshint.reporter('default'));
});

gulp.task('js', function ()
{
  return gulp.src('./src/static/js/*.js')
  // .pipe(amdOptimize('main', { 
  //   paths:{
  //     "jquery":'./src/static/js/lib/jquery-1.11.3.min',
  //     "Mustache":'./src/static/js/lib/mustache',
  //     "bootstrap":'./src/static/js/lib/bootstrap'
  //   },
  //   findNestedDependencies: true,
  //   include: false
  // }))
  // .pipe(concat('main.js'))
  .pipe(gulp.dest('./dist/static/js/'))  
  .pipe(rename("main.min.js")) 
  //.pipe(uglify()) 
  .pipe(gulp.dest('./dist/static/js/'));
});


//合并按模块引入的html文件
gulp.task('html',function() {
  return gulp.src("./src/*.html")
  .pipe(contentIncluder({
    includerReg:/<!\-\-include\s+"([^"]+)"\-\->/g
}))
  .pipe(gulp.dest('./dist/'));
});

//压缩css
gulp.task('css',function() {
    return gulp.src('./src/static/css/*.css')    //需要操作的文件
        .pipe(gulp.dest('./dist/static/css'))       //输出到文件夹
        .pipe(rename({suffix: '.min'}))   //rename压缩后的文件名
        .pipe(minifycss())   //执行压缩
        .pipe(gulp.dest('./dist/static/css'))   //输出文件夹
        .pipe(gulp.dest('../site/public/static/css'));   //输出文件夹
    });

gulp.task('clean', function(cb) {
  del(['./dist/static/css', './dist/static/js'], cb)
});

//gulp 默认命令，在cmd中输入gulp后，执行的就是这个任务(压缩js需要在检查js之后操作)
gulp.task('default',['jshint'],function() {
    gulp.start('html','css','js'); // 'clean',
});

//gulp watch
gulp.task('watch', function() {  
  gulp.watch('src/**', ['html','css','j']); 
  livereload.listen();

  gulp.watch(['src/**']).on('change', function(file) {
    livereload.changed(file.path);
});

});

