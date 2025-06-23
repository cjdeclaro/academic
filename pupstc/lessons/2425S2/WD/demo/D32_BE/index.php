<?php

$titles = array(
  "Title 1","Title 2","Title 3","PUP","Title 5","Title 6","Title 7","Title 8","Title 9"
);

$content = array(
  "Content A","Content A","Content A","Content A","Content A","Content A","Content A","Content A","Content A"
);

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
  <div class="container py-5">
    <div class="h1 text-center">
      Gallery
    </div>
  </div>
  <div class="container m4-5">
    <div class="row">

      <?php for ($i = 0; $i < count($titles); $i++) { ?>

        <div class="col-12 col-md-6 col-lg-4 my-2">
          <div class="card rounded-4 p-4">
            <div class="h3"><?php echo $titles[$i]?></div>
            <div class="text-body">
              <?php echo $content[$i] ?>
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
