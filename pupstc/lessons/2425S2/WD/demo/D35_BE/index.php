<?php
include("connect.php");

$query = "SELECT * FROM users";
$result = executeQuery($query);

?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Bootstrap demo</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.6/dist/css/bootstrap.min.css" rel="stylesheet"
    integrity="sha384-4Q6Gf2aSP4eDXB8Miphtr37CMZZQ5oXLH2yaXMJ2w8e2ZtHTl7GptT4jmndRuHDT" crossorigin="anonymous">
</head>

<body>
  <div class="container mt-5">
    <div class="row">

      <?php while ($row = mysqli_fetch_assoc($result)) { ?>

        <div class="col-12 col-sm-6">
          <div class="card p-2 my-2">
            <div class="d-flex flex-row justify-content-between">
              <div>
                <?php echo $row['firstName'].' '.$row['lastName'] ?>
              </div>
              <div class="text-secondary">
                <?php echo $row['email'] ?>
              </div>
            </div>
          </div>
        </div>

      <?php } ?>

    </div>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.6/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-j1CDi7MgGQ12Z7Qab0qlWQ/Qqz24Gc6BM0thvEMVjHnfYGF0rmFCozFSxQBxwHKO"
    crossorigin="anonymous"></script>
</body>

</html>