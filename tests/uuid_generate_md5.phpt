--TEST--
uuid_generate_md5() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');
if(!function_exists('uuid_generate_md5')) die('skip not compiled in (HAVE_UUID_GENERATE_MD5)');

 ?>
--FILE--
<?php
$uuid = uuid_create();
var_dump($uuid);
var_dump(uuid_generate_md5("not a uuid", "foo"));
var_dump($a = uuid_generate_md5($uuid, "foo"));
var_dump($b = uuid_generate_md5($uuid, "bar"));
var_dump($a === $b);
var_dump(uuid_type($a) == UUID_TYPE_MD5);
var_dump(uuid_type($b) == UUID_TYPE_MD5);
?>
Done
--EXPECTF--
string(36) "%s"
bool(false)
string(36) "%s"
string(36) "%s"
bool(false)
bool(true)
bool(true)
Done
