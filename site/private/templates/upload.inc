<?php 
require 'common/header.inc' ;
require 'common/navbar.inc' ;
?>

<div class="container-fluid">
    <h1>上传数据 <small> </small></h1>
</div>

<form class="form-horizontal" method="post">
  <div class="form-group">
    <label for="inputEmail3" class="col-sm-2 control-label">选择数据类型</label>
    <div class="col-sm-3">
      <select name="typeId" class="form-control" >
        <option value="1">电影院</option>
        <option value="2">电影</option>
    </select>
</div>
<div class="col-sm-2"> 
<ul class="nav nav-pills"> 
      <li role="presentation"><a href="schema.html">数据规范</a></li>
      <li role="presentation"><a href="post.html">API方式提交</a></li>
      </ul> 
</div>
</div>
<div class="form-group">
    <label for="inputPassword3" class="col-sm-2 control-label">JSON数据</label>
    <div class="col-sm-9">
        <textarea name="content" class="form-control" style='min-height:300px;'>[{"schemaVersion":"0.1","type":"MovieTheater","siteEntityId":"36d8ee0cd94332f66240a9e4","name":"艾米1895电影街北京世茂店","url":"http://bj.nuomi.com/cinema/36d8ee0cd94332f66240a9e4"},{"schemaVersion":"0.1","type":"MovieTheater","siteEntityId":"36d8ee0cd94332f66240a9e4","name":"艾米1895电影街北京世茂店","url":"http://bj.nuomi.com/cinema/36d8ee0cd94332f66240a9e4"}]
  </textarea>
    </div>
</div>
<div class="form-group">
    <label for="inputPassword3" class="col-sm-2 control-label">备注</label>
    <div class="col-sm-9">
    <input type="text" name="notes" class="form-control"/>
    </div>
</div>


<div class="form-group">
    <div class="col-sm-offset-2 col-sm-9">
      <button type="submit" class="btn btn-default">提交</button>
  </div>
</div>
</form>


<?php 
require 'common/footer.inc' ;
?>
