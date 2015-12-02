 <?php 
require 'common/header.inc' ; 
?>


 <div class="container">

  <form class="form-signin" method="post">
  <h2 class="form-signin-heading"><a href="/">KGOne</a> 用户注册</h2>
    
    <label for="inputMobile" class="sr-only">Email address</label>
    <input type="text" id="inputMobile" name="mobile" class="form-control" placeholder="手机号" required autofocus>
    
    <label for="inputPassword" class="sr-only">Password</label>
    <input type="text" id="inputPassword" name="password" class="form-control" placeholder="登录密码" required> 
     
    <button class="btn btn-lg btn-primary btn-block" type="submit">注册</button>

    <a class="btn-block" href="/login">已有帐号，去登录</a>



  </form>

</div>
<?php 
require 'common/footer.inc' ;
?>
