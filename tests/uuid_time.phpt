--TEST--
uuid_time() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');

 ?>
--FILE--
<?php
var_dump(uuid_time("b691c99c-7fc5-11d8-9fa8-00065b896488"));
var_dump(uuid_time("878b258c-a9f1-467c-8e1d-47d79ca2c01b"));

?>
--EXPECT--
int(1080374815)
bool(false)
