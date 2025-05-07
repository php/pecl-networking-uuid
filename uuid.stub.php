<?php

/**
 * @generate-function-entries
 * @generate-class-entries
 * @generate-legacy-arginfo
 */

#ifdef UUID_VARIANT_NCS
/**
 * @var int
 * @cvalue UUID_VARIANT_NCS
 */
const UUID_VARIANT_NCS = UNKNOWN;
#endif

#ifdef UUID_VARIANT_DCE
/**
 * @var int
 * @cvalue UUID_VARIANT_DCE
 */
const UUID_VARIANT_DCE = UNKNOWN;
#endif

#ifdef UUID_VARIANT_MICROSOFT
/**
 * @var int
 * @cvalue UUID_VARIANT_MICROSOFT
 */
const UUID_VARIANT_MICROSOFT = UNKNOWN;
#endif

#ifdef UUID_VARIANT_OTHER
/**
 * @var int
 * @cvalue UUID_VARIANT_OTHER
 */
const UUID_VARIANT_OTHER = UNKNOWN;
#endif

/**
 * @var int
 */
const UUID_TYPE_DEFAULT = 0;

/* ---------- deprecated alias ---------- */

/**
 * @var int
 * @cvalue UUID_TYPE_DCE
 */
const UUID_TYPE_DCE = UNKNOWN;

/**
 * @var int
 * @cvalue UUID_TYPE_NAME
 */
const UUID_TYPE_NAME = UNKNOWN;

/* ---------- library types ---------- */

/**
 * @var int
 * @cvalue UUID_TYPE_TIME
 */
const UUID_TYPE_TIME = UNKNOWN;

#ifdef UUID_TYPE_DCE_TIME_V6
/**
 * @var int
 * @cvalue UUID_TYPE_DCE_TIME_V6
 */
const UUID_TYPE_TIME_V6 = UNKNOWN;
#endif

#ifdef UUID_TYPE_DCE_TIME_V7
/**
 * @var int
 * @cvalue UUID_TYPE_DCE_TIME_V7
 */
const UUID_TYPE_TIME_V7 = UNKNOWN;
#endif

#ifdef UUID_TYPE_DCE_SECURITY
/**
 * @var int
 * @cvalue UUID_TYPE_DCE_SECURITY
 */
const UUID_TYPE_SECURITY = UNKNOWN;
#endif

#ifdef UUID_TYPE_DCE_MD5
/**
 * @var int
 * @cvalue UUID_TYPE_DCE_MD5
 */
const UUID_TYPE_MD5 = UNKNOWN;
#endif

/**
 * @var int
 * @cvalue UUID_TYPE_DCE_RANDOM
 */
const UUID_TYPE_RANDOM = UNKNOWN;

#ifdef UUID_TYPE_DCE_SHA1
/**
 * @var int
 * @cvalue UUID_TYPE_DCE_SHA1
 */
const UUID_TYPE_SHA1 = UNKNOWN;
#endif

/* ---------- extension specific types ---------- */

/**
 * @var int
 */
const UUID_TYPE_NULL = -1;

/**
 * @var int
 */
const UUID_TYPE_INVALID = -42;

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

#if defined(HAVE_UUID_TIME) || defined(HAVE_UUID_TIME64)
function uuid_time(string $uuid): int {}
#endif

function uuid_mac(string $uuid): string {}

function uuid_parse(string $uuid): string {}

function uuid_unparse(string $uuid): string {}

