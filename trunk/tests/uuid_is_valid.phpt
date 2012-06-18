--TEST--
uuid_is_valid() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');

 ?>
--FILE--
<?php
var_dump(uuid_is_valid("1b4e28ba-2fa1-11d2-883f-b9a761bde3fb"));
var_dump(uuid_is_valid("ffffffff-ffff-ffff-ffff-ffffffffffff"));
var_dump(uuid_is_valid("61616161-6161-6161-6161-616161616161"));
var_dump(uuid_is_valid("foobar"));

?>
--EXPECT--
bool(true)
bool(true)
bool(true)
bool(false)
