<?php 
require 'common/header.inc' ;
require 'common/navbar.inc' ;
?>

<div class="container-fluid">
  <h1>数据上传记录 <small><a href="/upload"> 上传数据</a></small> </h1>
</div>

<div class="container-fluid"> 

  <div class="col-sm-9">
  </div>

  <table class="table table-hover table-responsive">
    <thead><tr><th>上传批次</th><th>类型</th><th>备注</th><th>实体数</th><th>属性数</th><th>状态</th> <th>融合入库日期</th> <th>报告</th> </tr></thead>
    <tbody>
      <?php foreach($rows as $key=>$o) { 
        ?>
        <tr><td><?php echo $o['pk_id'];?></td><td><?php echo $o['type_id'];?></td><td><?php echo $o['notes'];?></td><td><?php echo $o['entity_count'];?></td><td><?php echo $o['property_count'];?></td><td>融合中</td><td><?php echo $o['last_update'];?></td><td><a href="/upload/reports?id=<?php echo $o['pk_id'];?>">详情</a></td></tr>
        <?php } ?>  
      </tbody>
    </table>
  </div>

  <?php 
  require 'common/footer.inc' ;
  ?>
