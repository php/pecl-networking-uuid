--TEST--
UUID creation
--SKIPIF--
<?php if (!extension_loaded("uuid")) print "skip"; ?>
--POST--
--GET--
--INI--
--FILE--
<?php
	// check basic format of generated UUIDs
	$uuid = uuid_create();
	if (ereg("[[:xdigit:]]{8}-[[:xdigit:]]{4}-[[:xdigit:]]{4}-[[:xdigit:]]{4}-[[:xdigit:]]{12}", $uuid)) {
		echo "basic format ok\n";

		echo "NULL UUID ";
		$uuid = uuid_create(UUID_TYPE_NULL);
		echo uuid_is_null($uuid) ? "ok\n" : "failed: $uuid\n";

		echo "Time based UUID ";
		$uuid = uuid_create(UUID_TYPE_TIME);
		echo uuid_type($uuid) == UUID_TYPE_TIME ? "ok\n" : "failed: $uuid (".uuid_type($uuid).",".UUID_TYPE_TIME.")\n";

		echo "Random UUID ";
		$uuid = uuid_create(UUID_TYPE_RANDOM);
		echo uuid_type($uuid) == UUID_TYPE_RANDOM ? "ok\n" : "failed: $uuid\n";

	} else {
		echo "basic UUID format check failed, generated UUID was $uuid\n";
	}
?>
--EXPECT--
basic format ok
NULL UUID ok
Time based UUID ok
Random UUID ok


