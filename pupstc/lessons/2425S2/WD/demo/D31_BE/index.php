<?php
$isAdmin = false;
function getFullName($fname, $lname)
{
  return $fname . " " . $lname;
}

$fname = "Steve";
$lname = "Jobs";
$fullname = getFullName($fname, $lname);
?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Home | <?php echo $fullname ?></title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.6/dist/css/bootstrap.min.css" rel="stylesheet"
    integrity="sha384-4Q6Gf2aSP4eDXB8Miphtr37CMZZQ5oXLH2yaXMJ2w8e2ZtHTl7GptT4jmndRuHDT" crossorigin="anonymous">
</head>

<body>
  <div class="container-fluid shadow">
    <div class="container">
      <div class="row">
        <div class="col py-3">
          <strong>
            <?php echo $fullname ?>
          </strong>
        </div>
      </div>
    </div>
  </div>
  <div class="container-fluid border">
    <div class="row">
      <div class="col">
        <div class="h3 text-center p-5">
          Hello <?php echo $fname ?>!
        </div>
      </div>
    </div>
  </div>

  <?php
  if ($isAdmin) {
    ?>

    <div class="container-fluid border">
      <div class="row">
        <div class="col">
          <div class="py-3">
            <strong>Admin control</strong>
          </div>
        </div>
      </div>
    </div>

    <?php
  }
  ?>


  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.6/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-j1CDi7MgGQ12Z7Qab0qlWQ/Qqz24Gc6BM0thvEMVjHnfYGF0rmFCozFSxQBxwHKO" crossorigin="anonymous">
    </script>
</body>

</html>