<?php
function factorial($number) {
 if($number <= 1) {
     return 1;
 } else {
     return $number * factorial($number - 1);
 }
}

$number = $_POST['number'];
$fact = factorial($number);
echo "Factorial = $fact";
?>
