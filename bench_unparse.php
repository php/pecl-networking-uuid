<?php

var_dump($uuid = uuid_create());
var_dump(bin2hex($p = uuid_parse($uuid)));
var_dump(uuid_unparse($p));
var_dump(uuid_unparse_fast($p));

$t = microtime(true);
for ($i=0 ; $i<100000 ; $i++) {
	$x = uuid_unparse($p);
}
printf ("Old: %.3f\n", microtime(true) - $t);

$t = microtime(true);
for ($i=0 ; $i<100000 ; $i++) {
	$x = uuid_unparse_fast($p);
}
printf ("New: %.3f\n", microtime(true) - $t);


