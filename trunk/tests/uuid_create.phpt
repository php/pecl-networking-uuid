--TEST--
uuid_create() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');

 ?>
--FILE--
<?php
        // check basic format of generated UUIDs
        $uuid = uuid_create();
        if (ereg("[[:xdigit:]]{8}-[[:xdigit:]]{4}-[[:xdigit:]]{4}-[[:xdigit:]]{4}-[[:xdigit:]]{12}", $uuid)) {
                echo "basic format ok\n";
        } else {
                echo "basic UUID format check failed, generated UUID was $uuid\n";
        }

?>
--EXPECT--
basic format ok
