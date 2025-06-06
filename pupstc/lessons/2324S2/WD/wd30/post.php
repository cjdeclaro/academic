<?php

if(!isset($_SESSION['username'])){
  header('Location: login.php');
}

if($_SESSION['access_level'] == 0){
  header('Location: index.php');
}

include "shared/head.php";
?>

<body>
  <?php
  $pagename = "post";
  include "shared/navigation.php";
  ?>
  <div class="container-fluid">
    <main class="tm-main">
      <!-- Search form -->
      <div class="row tm-row">
        <div class="col-12">
          <form method="GET" class="form-inline tm-mb-80 tm-search-form">
            <input class="form-control tm-search-input" name="query" type="text" placeholder="Search..."
              aria-label="Search">
            <button class="tm-search-button" type="submit">
              <i class="fas fa-search tm-search-icon" aria-hidden="true"></i>
            </button>
          </form>
        </div>
      </div>
      <div class="row tm-row">
        <div class="col-12">
          <hr class="tm-hr-primary tm-mb-55">
          <!-- Video player 1422x800 -->
          <video width="954" height="535" controls class="tm-mb-40">
            <source src="video/wheat-field.mp4" type="video/mp4">
            Your browser does not support the video tag.
          </video>
        </div>
      </div>
      <div class="row tm-row">
        <div class="col-lg-8 tm-post-col">
          <div class="tm-post-full">
            <div class="mb-4">
              <h2 class="pt-2 tm-color-primary tm-post-title">Single Post of Xtra Blog HTML Template</h2>
              <p class="tm-mb-40">June 16, 2020 posted by Admin Nat</p>
              <p>
                This is a description of the video post. You can also have an image instead of
                the video. You can free download
                <a rel="nofollow" href="https://templatemo.com/tm-553-xtra-blog" target="_blank">Xtra
                  Blog Template</a>
                from TemplateMo website. Phasellus maximus quis est sit amet maximus. Vestibulum vel
                rutrum
                lorem, ac sodales augue. Aliquam erat volutpat. Duis lectus orci, blandit in arcu
                est, elementum tincidunt lectus. Praesent vel justo tempor, varius lacus a,
                pharetra lacus.
              </p>
              <p>
                Duis pretium efficitur nunc. Mauris vehicula nibh nisi. Curabitur gravida neque
                dignissim, aliquet nulla sed, condimentum nulla. Pellentesque id venenatis
                quam, id cursus velit. Fusce semper tortor ac metus iaculis varius. Praesent
                aliquam ex vel lectus ornare tristique. Nunc et eros quis enim feugiat tincidunt
                et vitae dui.
              </p>
              <span class="d-block text-right tm-color-primary">Creative . Design . Business</span>
            </div>

            <!-- Comments -->
            <div>
              <h2 class="tm-color-primary tm-post-title">Comments</h2>
              <hr class="tm-hr-primary tm-mb-45">
              <div class="tm-comment tm-mb-45">
                <figure class="tm-comment-figure">
                  <img src="img/comment-1.jpg" alt="Image" class="mb-2 rounded-circle img-thumbnail">
                  <figcaption class="tm-color-primary text-center">Mark Sonny</figcaption>
                </figure>
                <div>
                  <p>
                    Praesent aliquam ex vel lectus ornare tritique. Nunc et eros
                    quis enim feugiat tincidunt et vitae dui. Nullam consectetur
                    justo ac ex laoreet rhoncus. Nunc id leo pretium, faucibus
                    sapien vel, euismod turpis.
                  </p>
                  <div class="d-flex justify-content-between">
                    <a href="#" class="tm-color-primary">REPLY</a>
                    <span class="tm-color-primary">June 14, 2020</span>
                  </div>
                </div>
              </div>
              <div class="tm-comment-reply tm-mb-45">
                <hr>
                <div class="tm-comment">
                  <figure class="tm-comment-figure">
                    <img src="img/comment-2.jpg" alt="Image" class="mb-2 rounded-circle img-thumbnail">
                    <figcaption class="tm-color-primary text-center">Jewel Soft</figcaption>
                  </figure>
                  <p>
                    Nunc et eros quis enim feugiat tincidunt et vitae dui.
                    Nullam consectetur justo ac ex laoreet rhoncus. Nunc
                    id leo pretium, faucibus sapien vel, euismod turpis.
                  </p>
                </div>
                <span class="d-block text-right tm-color-primary">June 21, 2020</span>
              </div>
              <form action="" class="mb-5 tm-comment-form">
                <h2 class="tm-color-primary tm-post-title mb-4">Your comment</h2>
                <div class="mb-4">
                  <input class="form-control" name="name" type="text">
                </div>
                <div class="mb-4">
                  <input class="form-control" name="email" type="text">
                </div>
                <div class="mb-4">
                  <textarea class="form-control" name="message" rows="6"></textarea>
                </div>
                <div class="text-right">
                  <button class="tm-btn tm-btn-primary tm-btn-small">Submit</button>
                </div>
              </form>
            </div>
          </div>
        </div>
        <aside class="col-lg-4 tm-aside-col">
          <div class="tm-post-sidebar">
            <hr class="mb-3 tm-hr-primary">
            <h2 class="mb-4 tm-post-title tm-color-primary">Categories</h2>
            <ul class="tm-mb-75 pl-5 tm-category-list">
              <li><a href="#" class="tm-color-primary">Visual Designs</a></li>
              <li><a href="#" class="tm-color-primary">Travel Events</a></li>
              <li><a href="#" class="tm-color-primary">Web Development</a></li>
              <li><a href="#" class="tm-color-primary">Video and Audio</a></li>
              <li><a href="#" class="tm-color-primary">Etiam auctor ac arcu</a></li>
              <li><a href="#" class="tm-color-primary">Sed im justo diam</a></li>
            </ul>
            <hr class="mb-3 tm-hr-primary">
            <h2 class="tm-mb-40 tm-post-title tm-color-primary">Related Posts</h2>
            <a href="#" class="d-block tm-mb-40">
              <figure>
                <img src="img/img-02.jpg" alt="Image" class="mb-3 img-fluid">
                <figcaption class="tm-color-primary">Duis mollis diam nec ex viverra scelerisque a sit
                </figcaption>
              </figure>
            </a>
            <a href="#" class="d-block tm-mb-40">
              <figure>
                <img src="img/img-05.jpg" alt="Image" class="mb-3 img-fluid">
                <figcaption class="tm-color-primary">Integer quis lectus eget justo ullamcorper
                  ullamcorper</figcaption>
              </figure>
            </a>
            <a href="#" class="d-block tm-mb-40">
              <figure>
                <img src="img/img-06.jpg" alt="Image" class="mb-3 img-fluid">
                <figcaption class="tm-color-primary">Nam lobortis nunc sed faucibus commodo</figcaption>
              </figure>
            </a>
          </div>
        </aside>
      </div>
      <?php
      include "shared/footer.php";
      ?>
    </main>
  </div>
  <script src="js/jquery.min.js"></script>
  <script src="js/templatemo-script.js"></script>
</body>

</html>