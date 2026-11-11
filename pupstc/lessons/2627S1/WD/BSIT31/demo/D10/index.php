<?php
  $names = array("John", "Bill", "Steve", "Jane");
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

<body data-bs-theme="light" id="body">

  <div class="container-fluid shadow py-3">
    <div class="row">
      <div class="col d-flex flex-row justify-content-between align-items-center">
        <div>App Title</div>
        <div class="btn btn-sm btn-outline-secondary" onclick="changeMode()">Change Mode</div>
      </div>
    </div>
  </div>

  <div class="container p-5">
    <div class="row">
      <div class="col-12">
        <div class="card p-4 shadow-sm rounded-4">
          <table class="table table-striped">
            <thead>
              <tr>
                <th scope="col">#</th>
                <th scope="col">First</th>
                <th scope="col">Last</th>
              </tr>
            </thead>
            <tbody>
              <?php foreach($names as $name) { ?>
              <tr>
                <th scope="row">1</th>
                <td><?php echo $name ?></td>
                <td>Otto</td>
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
  <script>
    var elBody = document.getElementById("body");
    var isLight = true;
    var mode = "light";

    function changeMode(){
      isLight = !isLight; // negation
      mode = isLight ? "light" : "dark"; // ternary operator
      elBody.setAttribute("data-bs-theme", mode); // setter
    }
  </script>
</body>

</html>