--TEST--
uuid_compare() function
--SKIPIF--
<?php 

if(!extension_loaded('uuid')) die('skip ');

 ?>
--FILE--
<?php
$uuids = array();
        $uuids[0] = "00000000-0000-0000-0000-000000000000";
        $uuids[1] = "878b258c-a9f1-467c-8e1d-47d79ca2c01b";
        $uuids[2] = "b691c99c-7fc5-11d8-9fa8-00065b896488";

        foreach ($uuids as $key1 => $uuid1) {
                foreach ($uuids as $key2 => $uuid2) {
                        echo "uuid$key1";

                        switch (uuid_compare($uuid1, $uuid2)) {
                        case -1: echo " < "; break;
                        case  0: echo " = "; break;
                        case  1: echo " > "; break;
                        }

                        echo "uuid$key2\n";
                }
                echo "\n";
        }

?>
--EXPECT--
uuid0 = uuid0
uuid0 < uuid1
uuid0 < uuid2

uuid1 > uuid0
uuid1 = uuid1
uuid1 < uuid2

uuid2 > uuid0
uuid2 > uuid1
uuid2 = uuid2
