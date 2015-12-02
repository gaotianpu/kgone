<?php 
require 'common/header.inc' ; 
?>


 <div class="container">

  <form class="form-signin" method="post">
  <h2 class="form-signin-heading"><a href="/">KGOne</a> 登录</h2>
    
    <label for="inputMobile" class="sr-only">Email address</label>
    <input type="text" id="inputEmail" name="mobile" class="form-control" placeholder="手机号" required autofocus>
    
    <label for="inputPassword" class="sr-only">Password</label>
    <input type="password" id="inputPassword" name="password" class="form-control" placeholder="登录密码" required>
    
    <div class="checkbox">
      <label>
        <input type="checkbox" value="remember-me" checked> 下次直接访问
      </label>
    </div>
    
    <button class="btn btn-lg btn-primary btn-block" type="submit">登录</button>

    <a class="btn-block" href="/register">还没有帐号，去注册</a>



  </form>

</div>
<?php 
require 'common/footer.inc' ;
?>
