--TEST--
uuid_mac() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');

 ?>
--FILE--
<?php
var_dump(uuid_mac("b691c99c-7fc5-11d8-9fa8-00065b896488"));
try {
	if (!uuid_mac("878b258c-a9f1-467c-8e1d-47d79ca2c01b")) {
		echo "OK\n"; // PHP 7
	}
} catch (ValueError $e) {
	echo $e->getMessage() . "\n"; // PHP 8
	echo "OK\n";
}

?>
--EXPECTF--
string(12) "00065b896488"
%A Argument #1 ($uuid) UUID DCE TIME expecte%AOK
