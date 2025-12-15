<?php
include("connect.php");

if(isset($_POST['fname'])){
  $fname = $_POST['fname'];
  $lname = $_POST['lname'];

  $postQuery = "INSERT INTO `students`(`firstName`, `lastName`) VALUES ('$fname','$lname')";
  executeQuery($postQuery);
}

if(isset($_POST['deleteID'])){
  $deleteID = $_POST['deleteID'];
  $deleteQuery = "DELETE FROM students WHERE studentID = '$deleteID'";

  executeQuery($deleteQuery);
}

$getQuery = "SELECT * FROM students LEFT JOIN locations ON students.locationID = locations.locationID;";
$result = executeQuery($getQuery);
?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Bootstrap demo</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet"
    integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
</head>

<body>
  <div class="container">
    <div class="row">
      <div class="col">
        <div class="card m-4 rounded-4 p-5 shadow">
          <form method="POST">
            <input class="form-control mb-2" type="text" name="fname" placeholder="First Name">
            <input class="form-control mb-2" type="text" name="lname" placeholder="Last Name">
            <input type="submit" class="btn btn-primary" value="Submit">
          </form>
        </div>
      </div>
    </div>
  </div>
  <div class="container mt-5">
    <div class="row">
      <div class="col">
        <div class="card m-4 rounded-4 p-5 shadow">
          <div class="h4">Students</div>
          <table class="table table-striped">
            <thead>
              <tr>
                <th scope="col"></th>
                <th scope="col">First</th>
                <th scope="col">Last</th>
                <th scope="col">Location</th>
                <th scope="col"></th>
              </tr>
            </thead>
            <tbody>

              <?php while($row = mysqli_fetch_assoc($result)) { ?>
              <tr>
                <th scope="row"><?php echo $row['studentID'] ?></th>
                <td><?php echo $row['firstName'] ?></td>
                <td><?php echo $row['lastName'] ?></td>
                <td><?php echo $row['locationName'] ?></td>
                <td class="text-end">
                  
                  <form method="POST">
                    <input type="hidden" value="<?php echo $row['studentID'] ?>" name="deleteID">
                    <input class="btn btn-outline-danger btn-sm" type="submit" value="X">
                  </form>
                
                </td>
              </tr>
              <?php } ?>

            </tbody>
          </table>
        </div>
      </div>
    </div>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI"
    crossorigin="anonymous"></script>
</body>

</html>