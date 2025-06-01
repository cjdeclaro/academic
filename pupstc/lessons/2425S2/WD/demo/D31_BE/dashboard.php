<?php
date_default_timezone_set('Asia/Manila');
$isAdmin = true;
function getFullName($fname, $lname)
{
  return $fname . " " . $lname;
}

$fname = "Steve";
$lname = "Jobs";
$fullname = getFullName($fname, $lname);

$currentTime = date("H");
$greeting = "";

if($currentTime > 18){
  $greeting = "Good Evening";
} else if ($currentTime >= 12) {
  $greeting = "Good Afternoon";
} else {
  $greeting = "Good Morning";
}

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
          <div class="d-flex flex-row justify-content-between">
            <div>
              <strong>
                <?php echo $fullname ?>
              </strong>
              <?php if ($isAdmin) { ?>
                <span class="badge rounded-pill text-bg-secondary">Admin</span>
              <?php } ?>
            </div>
            <div>
              <?php echo date("M d, Y h:i a") ?>
              <!-- <?php echo date("mdYHis").".jpg" ?> -->
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div class="container">
    <div class="row">
      <div class="col-2 border-end" style="height: 90vh">
        <div class="h4 my-4">Nav</div>
        <div class="my-2">Home</div>
        <div class="my-2">Settings</div>
        <?php if ($isAdmin) { ?>
          <div class="my-2">Users</div>
        <?php } ?>
        <?php if ($isAdmin) { ?>
          <div class="my-2">Reports</div>
        <?php } ?>
      </div>
      <div class="col-10">
        <div class="h3 my-4 text-center"><?php echo $greeting ?>, <?php echo $fname ?>!</div>
      </div>
    </div>
  </div>


  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.6/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-j1CDi7MgGQ12Z7Qab0qlWQ/Qqz24Gc6BM0thvEMVjHnfYGF0rmFCozFSxQBxwHKO" crossorigin="anonymous">
    </script>
</body>

</html>