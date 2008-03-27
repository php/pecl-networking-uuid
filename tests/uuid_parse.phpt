--TEST--
uuid_parse() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');

 ?>
--FILE--
<?php
var_dump(uuid_parse("61616161-6161-6161-6161-616161616161"));

?>
--EXPECT--
string(16) "aaaaaaaaaaaaaaaa"
