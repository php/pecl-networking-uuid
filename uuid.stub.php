<?php

/**
 * @generate-function-entries
 * @generate-legacy-arginfo
 */

function uuid_create(int $uuid_type=UUID_TYPE_DEFAULT): string {}

function uuid_is_valid(string $uuid): bool {}

function uuid_compare(string $uuid1, string $uuid2): int {}

function uuid_is_null(string $uuid): bool {}

#ifdef HAVE_UUID_GENERATE_MD5
function uuid_generate_md5(string $uuid_ns, string $name): string {}
#endif

#ifdef HAVE_UUID_GENERATE_SHA1
function uuid_generate_sha1(string $uuid_ns, string $name): string {}
#endif

#ifdef HAVE_UUID_TYPE
function uuid_type(string $uuid): int {}
#endif

#ifdef HAVE_UUID_VARIANT
function uuid_variant(string $uuid): int {}
#endif

function uuid_time(string $uuid): int {}

function uuid_mac(string $uuid): string {}

function uuid_parse(string $uuid): string {}

function uuid_unparse(string $uuid): string {}

