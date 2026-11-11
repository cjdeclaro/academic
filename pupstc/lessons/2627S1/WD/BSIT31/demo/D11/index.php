<!doctype html>
<html lang="en">

<?php $pageName = "Home" ?>

<?php include("shared/head.php") ?>

<body>
  <?php include("shared/topnav.php") ?>
  <?php include("shared/ads.php") ?>
  <?php
    if(date("m") == "12"){
      include("shared/banner-christmas.php");
    } else {
      include("shared/banner.php");
    }
  ?>
  
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI"
    crossorigin="anonymous"></script>
</body>

</html>