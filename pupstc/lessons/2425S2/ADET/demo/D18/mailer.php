<?php
use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\Exception;

require 'PHPMailer-master/src/Exception.php';
require 'PHPMailer-master/src/PHPMailer.php';
require 'PHPMailer-master/src/SMTP.php';

$emails = array(
  "allianaabello27@gmail.com",
  "kissyaguilar1@gmail.com",
  "theaalberto89@gmail.com",
  "althealasat@gmail.com",
  "angelesemanuelvincent@gmail.com",
  "schann0209@gmail.com",
  "najilabatistil@outlook.com",
  "austinejadebernardo0801@gmail.com",
  "blancochristyn3@gmail.com",
  "jeromecarandang011@gmail.com",
  "jomaricastillo8@gmail.com",
  "catomarielle@gmail.com",
  "coronadochristian44@gmail.com"
);

$mail = new PHPMailer(true);

for ($i = 0; $i < count($emails); $i++) {
  try {
    // Server settings
    $mail->isSMTP();
    $mail->Host = 'smtp.gmail.com';
    $mail->SMTPAuth = true;
    $mail->Username = '';
    $mail->Password = '';
    $mail->SMTPSecure = 'tls';
    $mail->Port = 587;

    // Recipients
    $mail->setFrom('no-reply.pupstb.computersociety@gmail.com', 'COMSOC');
    $mail->addAddress($emails[$i], 'RECEPIENT: ' . $emails[$i]);

    // Content
    $mail->isHTML(true);
    $mail->Subject = 'Hello '.$emails[$i];
    $mail->Body = "Notification about our upcoming final examination.";

    $mail->send();
    echo 'Email has been sent to '.$emails[$i].'!';
  } catch (Exception $e) {
    echo "Email failed. Error: {$mail->ErrorInfo}";
  }
}
?>