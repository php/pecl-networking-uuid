--TEST--
uuid_variant() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');

if(!function_exists('uuid_variant')) die('skip not compiled in (HAVE_UUID_VARIANT)');

 ?>
--FILE--
<?php
echo uuid_variant("b691c99c-7fc5-11d8-9fa8-00065b896488")."\n";
echo uuid_variant("878b258c-a9f1-467c-8e1d-47d79ca2c01b")."\n";
echo uuid_variant("00000000-0000-0000-0000-000000000000")."\n";

?>
--EXPECT--
1
1
-1
