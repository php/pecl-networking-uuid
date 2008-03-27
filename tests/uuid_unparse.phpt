--TEST--
uuid_unparse() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');

 ?>
--FILE--
<?php
var_dump(uuid_unparse("aaaaaaaaaaaaaaaa"));

?>
--EXPECT--
string(36) "61616161-6161-6161-6161-616161616161"
