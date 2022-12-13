--TEST--
uuid_time() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');
if(!function_exists('uuid_time')) die('skip not compiled in (HAVE_UUID_TIME)');

 ?>
--FILE--
<?php
var_dump(uuid_time("b691c99c-7fc5-11d8-9fa8-00065b896488"));
try {
	if (!uuid_time("878b258c-a9f1-467c-8e1d-47d79ca2c01b")) {
		echo "OK\n"; // PHP 7
	}
} catch (ValueError $e) {
	echo $e->getMessage() . "\n"; // PHP 8
	echo "OK\n";
}

?>
--EXPECTF--
int(1080374815)
%A UUID DCE TIME expecte%AOK
