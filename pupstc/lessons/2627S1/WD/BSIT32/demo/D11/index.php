<!doctype html>
<html lang="en">

<?php $pageName = "Home" ?>
<?php include("shared/head.php") ?>

<body>
  <?php include("shared/topnav.php") ?>
  <?php include("shared/ads.php") ?>
  <?php
    if(date("n") == "12"){
      include("shared/banner-christmas.php");
    } else {
      include("shared/banner.php");
    }
    ?>
  <?php include("shared/scripts.php") ?>
</body>

</html>