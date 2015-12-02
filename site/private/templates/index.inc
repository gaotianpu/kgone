<?php 
require 'common/header.inc' ;
require 'common/navbar.inc' ;
?>


<div class="jumbotron">
  <ol>
   <li> 这是一个互联网公开<strong>结构化数据</strong>的开放分享平台; </li>
   <li> 会员可以通过手工或API的形式上传、下载数据;  </li>
   <li> 不同站点的相同实体以及实体属性会被融合；</li>
   <li> 已包含xx个类目，xxx个实体，xxx个属性；</li>
   <li> 已有xxx个数据贡献者，xxx次提交，也期待您的参与;  </li>
 </ol>
</div>

<div class="container-fluid"> 
 <table class="table table-hover table-responsive">
  <thead><tr> <th>类型</th><th>实体数</th><th>属性数</th><th>融合站点</th> </tr></thead>
  <tbody>
    <?php 
    foreach ($rows as $key => $o) { 
      ?> 
      <tr><td><a href="/type/<?php echo $o['name'];?>"><?php echo $o['name_cn'];?></a></td><td><?php echo $o['entity_count'];?></td><td><?php echo $o['property_count'];?></td><td><?php echo $o['sites'];?></td></tr>
      <?php 
    } 
    ?> 
  </tbody>
</table>
</div>

<div class="container-fluid">
 <div class="row">
  <div class="col-md-2"><a href="#">想要的数据还没有？</a></div>
  <div class="col-md-2"><a href="#">订阅每日数据更新通知</a></div>
</div>
</div>
<?php 
require 'common/footer.inc' ;
?>
