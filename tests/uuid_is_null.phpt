--TEST--
uuid_is_null() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');

 ?>
--FILE--
<?php
var_dump(uuid_is_null("00000000-0000-0000-0000-000000000000"));
var_dump(uuid_is_null("b691c99c-7fc5-11d8-9fa8-00065b896488"));
try {
	if (!uuid_is_null("xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx")) {
		echo "OK\n";
	}
} catch (ValueError $e) {
	echo $e->getMessage() . "\n"; // PHP 8
	echo "OK\n";
}

?>
--EXPECTF--
bool(true)
bool(false)
%A Argument #1 ($uuid) UUID expected%AOK
