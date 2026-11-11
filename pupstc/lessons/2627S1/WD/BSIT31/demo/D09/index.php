<?php
  $isAdmin = true;
?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>People</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet"
    integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
</head>

<body>
  <?php if($isAdmin) { ?>
  <div class="container p-5">
    <div class="row">
      <div class="col-12 p-5">
        <div class="card p-5">
          <div class="h4">
            Welcome back, Admin!
          </div>
        </div>
      </div>
    </div>
    <div class="row">
      <div class="col-6 p-5">
        <div class="card p-5">
          <div class="h4">
            PHP 100,000.00
          </div>
        </div>
      </div>
      <div class="col-6 p-5">
        <div class="card p-5">
          <div class="h4">
            Server status: OK!
          </div>
        </div>
      </div>
    </div>
  </div>

  <?php } else { 
    
    header("location: login.php");

   } ?>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI"
    crossorigin="anonymous"></script>
</body>

</html>