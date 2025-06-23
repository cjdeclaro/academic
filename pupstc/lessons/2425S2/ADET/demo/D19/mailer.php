<?php
use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\Exception;

require 'PHPMailer-master/src/Exception.php';
require 'PHPMailer-master/src/PHPMailer.php';
require 'PHPMailer-master/src/SMTP.php';

$email = $_POST['email'];

$mail = new PHPMailer(true);

try {
    // Server settings
    $mail->isSMTP();
    $mail->Host       = 'smtp.gmail.com';
    $mail->SMTPAuth   = true;
    $mail->Username   = '';
    $mail->Password   = '';
    $mail->SMTPSecure = 'tls';
    $mail->Port       = 587;

    // Recipients
    $mail->setFrom('no-reply.pupstb.computersociety@gmail.com', 'COMSOC');
    $mail->addAddress($email, 'RECEPIENT: '.$email);

    // Content
    $mail->isHTML(true);
    $mail->Subject = 'Hello from PHPMailer';
    $mail->Body    = "<h1>Hello $email!</h1> This is a test email.";

    $mail->send();
    echo 'Email has been sent successfully!';
} catch (Exception $e) {
    echo "Email failed. Error: {$mail->ErrorInfo}";
}
?>
