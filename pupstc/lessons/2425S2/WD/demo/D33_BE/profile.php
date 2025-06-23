<?php

function getFullName($f, $l){
  return $f." ".$l;
}

function getLegalFullName($f, $l){
  return $l.", ".$f;
}

//FROM DATABASE
$fname = "Jane";
$lname = "Air";
$bio = "Hello World";
$theme = "light";

?>

<!doctype html>
<html lang="en">

<?php include("shared/head.php") ?>

<body data-bs-theme="<?php echo $theme ?>">
  <?php include("shared/nav.php") ?>

  <div class="container bg-secondary p-5">
    <div class="p-5">
    </div>
  </div>

  <div class="container my-5 text-center">
    <div class="h4">
      <?php echo getLegalFullName($fname, $lname); ?>
    </div>
    <div class="text-secondary">
      <?php echo $bio ?>
    </div>
  </div>

  <div class="container my-3">
    <div class="card m-5 p-4">
      <div class="h6">
        <?php echo getFullName($fname, $lname); ?>
      </div>
      <div>
        Lorem ipsum dolor sit amet consectetur adipisicing elit. Ipsam porro libero ullam. Sint esse velit odit sit illum enim expedita, tenetur, ut ad reprehenderit ea asperiores quisquam reiciendis magnam dolor.
      </div>
    </div>
  </div>

  <div class="container my-3">
    <div class="card m-5 p-4">
      <div class="h6">
        <?php echo getFullName($fname, $lname); ?>
      </div>
      <div>
        Lorem ipsum dolor sit amet consectetur adipisicing elit. Ipsam porro libero ullam. Sint esse velit odit sit illum enim expedita, tenetur, ut ad reprehenderit ea asperiores quisquam reiciendis magnam dolor.
      </div>
    </div>
  </div>

  <div class="container my-3">
    <div class="card m-5 p-4">
      <div class="h6">
        <?php echo getFullName($fname, $lname); ?>
      </div>
      <div>
        Lorem ipsum dolor sit amet consectetur adipisicing elit. Ipsam porro libero ullam. Sint esse velit odit sit illum enim expedita, tenetur, ut ad reprehenderit ea asperiores quisquam reiciendis magnam dolor.
      </div>
    </div>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.6/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-j1CDi7MgGQ12Z7Qab0qlWQ/Qqz24Gc6BM0thvEMVjHnfYGF0rmFCozFSxQBxwHKO"
    crossorigin="anonymous"></script>
</body>

</html>