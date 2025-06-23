<?php
include("connect.php");

//LOGOUT
session_start();
session_destroy();
session_start();

if (isset($_POST['username'])) {
  $username = $_POST['username'];
  $password = $_POST['password'];

  // CHECK IF USER IS IN DATABASE
  $loginquery = "SELECT * FROM users JOIN userInfo ON users.userID = userInfo.userID WHERE username = '$username' AND password = '$password'";
  $loginresult = executeQuery($loginquery);

  if (mysqli_num_rows($loginresult) > 0) {

    while ($row = mysqli_fetch_assoc($loginresult)) {
      $_SESSION['userID'] = $row['userID'];
      $_SESSION['username'] = $row['username'];
      $_SESSION['password'] = $row['password'];
      $_SESSION['email'] = $row['email'];
      $_SESSION['firstName'] = $row['firstName'];
      $_SESSION['lastName'] = $row['lastName'];
    }
    header("Location: index.php");
  } else {
    echo "NO USER FOUND";
  }
}
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
  <div class="container">
    <div class="row">
      <div class="col">
        <div class="card p-5 rounded-5 mt-5">
          <div class="h4 text-center">Login</div>

          <form method="post">
            <div class="my-3">
              <label for="username">Username</label>
              <input id="username" class="form-control" type="text" name="username" required>
            </div>

            <div class="my-3">
              <label for="password">Password</label>
              <input id="password" class="form-control" type="password" name="password" required>
            </div>

            <div class="mt-5 text-center">
              <input class="btn btn-secondary" type="submit" value="Login">
            </div>
          </form>
        </div>
      </div>
    </div>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.7/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-ndDqU0Gzau9qJ1lfW4pNLlhNTkCfHzAVBReH9diLvGRem5+R9g2FzA8ZGN954O5Q"
    crossorigin="anonymous"></script>
</body>

</html>