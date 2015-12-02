<?php 
require 'common/header.inc' ;
require 'common/navbar.inc' ;
?>

<div class="container-fluid">
  <h1><?php echo $main['name_cn'].''. $main['name']?> <small> <span class="glyphicon glyphicon-heart" aria-hidden="true"></span> </small></h1>
  <?php 
  require 'common/typeNav.inc' ;
  ?>
</div> 


<div class="container-fluid"> 
 <table class="table table-hover table-responsive">
  <thead><tr> <th>名称</th><th>融合站点</th></tr></thead>
  <tbody>
   <?php 
   foreach ($rows as $key => $o) { 
    ?> 
    <tr><td><a href="/entity/<?php echo $o['pk_id'];?>"><?php echo $o['name'];?></a></td><td><a href="http://www.nuomi.com/cinema/2e00c5dde9607d05d7851f50">糯米</a> <a href="http://bj.meituan.com/shop/286187">美团</a> <a href="http://t.dianping.com/movie/cinema/2479618">大众点评</a> <a href="http://site.douban.com/113784/">豆瓣</a></td></tr> 
    <?php 
  } 
  ?>    
</tbody>
</table>
</div>

<?php 
require 'common/footer.inc' ;
?>
