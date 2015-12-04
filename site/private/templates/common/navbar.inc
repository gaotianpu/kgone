<nav class="navbar navbar-default navbar-static-top">
  <div class="container-fluid">
    <div class="navbar-header">
      <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
      <a class="navbar-brand" href="/"><strong>KGOne</strong></a>
    </div>
    <div id="navbar" class="navbar-collapse collapse">
      <ul class="nav navbar-nav"> 
        <li> 
            <form class="navbar-form">
              <input type="text" class="form-control" placeholder="Search...">
            </form>
        </li>  
    </ul>
      <ul class="nav navbar-nav navbar-right">
      <?php if($user===false){ ?> 
        <li><a href="/register">注册</a></li>
        <li><a href="/login">登录</a></li> 
        <?php }else {?>
      <li><a href="/upload/records">数据上传</a></li> 
         <li class="dropdown">
         <a href="#"><?php echo $user['mobile'] ?><span class="caret"></span></a>
               
              <ul class="dropdown-menu">
                <li><a href="#">Setting</a></li>
                <li><a href="#">Logout</a></li> 
              </ul>
            </li> 

        <?php }?>
      </ul>
    </div>
  </div>
</nav>