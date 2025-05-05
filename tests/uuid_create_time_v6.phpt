--TEST--
uuid_create() function for UUID_TYPE_TIME_V6
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');
if(!defined('UUID_TYPE_TIME_V6')) die('skip no UUID_TYPE_TIME_V6');

 ?>
--FILE--
<?php
        // check basic format of generated UUIDs
        $uuid = uuid_create(UUID_TYPE_TIME_V6);
        if (preg_match("/[[:xdigit:]]{8}-[[:xdigit:]]{4}-[[:xdigit:]]{4}-[[:xdigit:]]{4}-[[:xdigit:]]{12}/", $uuid)) {
                echo "basic format ok\n";
        } else {
                echo "basic UUID format check failed, generated UUID was $uuid\n";
        }
        $type = uuid_type($uuid);
        if ($type === UUID_TYPE_TIME_V6) {
                echo "type check ok\n";
        } else {
                echo "UUID type check failed, found $uuid\n";
        }
		
?>
--EXPECT--
basic format ok
type check ok

