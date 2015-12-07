<?php 
require 'common/header.inc' ;
require 'common/navbar.inc' ;
?>

<div class="container-fluid">
    <h1>上传数据 <small> </small></h1>
</div>

<form id="form_upload" class="form-horizontal" method="post">
  <div id="div_type" class="form-group">
    <label for="inputEmail3" class="col-sm-2 control-label">选择数据类型</label>
    <div class="col-sm-3">
      <select id="typeId" name="typeId" class="form-control" initval="<?php echo $typeId;?>">
        <option value="">选择数据类型</option>
        <?php foreach($rows as $key=>$o) {?><option value="<?php echo $o['name'];  ?>"><?php echo $o['name_cn'];  ?></option>
        <?php }?> 
    </select>
</div>
<div  class="col-sm-2"> 
<ul class="nav nav-pills"> 
      <li id="li_data_schema_link" style="display:none;" role="presentation"><a href="/schema/Country">数据规范</a></li>
      <li role="presentation"><a href="/doc/api">API方式提交</a></li>
      </ul> 
</div>
</div>
<div id="div_content" class="form-group">
    <label for="inputPassword3" class="col-sm-2 control-label">JSON数据</label>
    <div class="col-sm-9">
        <textarea id="content" name="content" class="form-control" style='min-height:300px;'></textarea>
    </div>
</div>
<div id="div_notes"  class="form-group">
    <label for="inputPassword3" class="col-sm-2 control-label">备注</label>
    <div class="col-sm-9">
    <input id="notes" type="text" name="notes" placeholder="" class="form-control"/>
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
