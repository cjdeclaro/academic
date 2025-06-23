<?php
  include("connect.php");

  session_start();

  $userID = $_SESSION['userID'];
  $username = $_SESSION['username'];
  $password = $_SESSION['password'];
  $email = $_SESSION['email'];
  $firstName = $_SESSION['firstName'];
  $lastName = $_SESSION['lastName'];

  if(!isset($username)){
    header("Location: login.php");
  }
  
  $petQuery = "SELECT * FROM pets WHERE userID = '$userID'";
  $petResult = executeQuery($petQuery);
?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Bootstrap demo</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.7/dist/css/bootstrap.min.css" rel="stylesheet"
    integrity="sha384-LN+7fdVzj6u52u30Kp6M/trliBMCMKTyK833zpbD+pXdCLuTusPj697FH4R/5mcr" crossorigin="anonymous">
</head>

<body>
  <div class="container-fluid position-sticky top-0 shadow z-1 py-3">
    <div class="row">
      <div class="col">
        <div class="d-flex flex-row justify-content-end">
          <a href="login.php" class="btn btn-outline-secondary">Logout</a>
        </div>
      </div>
    </div>
  </div>
  <div class="container p-5 bg-secondary text-center">
    <div class="row">
      <div class="col">
        <div class="h1">
          Hello <?php echo $firstName." ".$lastName ?>!
        </div>
      </div>
    </div>
  </div>
  <div class="container">
    <div class="row">
      <div class="col">
        <div class="display-6 my-3">
          Pets
        </div>
      </div>
    </div>
    <div class="row">

      <?php while($row = mysqli_fetch_assoc($petResult)) {?>

      <div class="col-3">
        <div class="card p-4 my-2">
          <strong><?php echo $row['name'] ?></strong>
          <div class="text-secondary"><?php echo $row['kind'] ?></div>
        </div>
      </div>

      <?php } ?>

    </div>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.7/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-ndDqU0Gzau9qJ1lfW4pNLlhNTkCfHzAVBReH9diLvGRem5+R9g2FzA8ZGN954O5Q"
    crossorigin="anonymous"></script>
</body>

</html>
