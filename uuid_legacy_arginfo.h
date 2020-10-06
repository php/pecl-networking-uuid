/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: c42576a38350ab4b21889bc077e8a414311653cd */

ZEND_BEGIN_ARG_INFO_EX(arginfo_uuid_create, 0, 0, 0)
	ZEND_ARG_INFO(0, uuid_type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_uuid_is_valid, 0, 0, 1)
	ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_uuid_compare, 0, 0, 2)
	ZEND_ARG_INFO(0, uuid1)
	ZEND_ARG_INFO(0, uuid2)
ZEND_END_ARG_INFO()

#define arginfo_uuid_is_null arginfo_uuid_is_valid

#if defined(HAVE_UUID_GENERATE_MD5)
ZEND_BEGIN_ARG_INFO_EX(arginfo_uuid_generate_md5, 0, 0, 2)
	ZEND_ARG_INFO(0, uuid_ns)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()
#endif

#if defined(HAVE_UUID_GENERATE_SHA1)
ZEND_BEGIN_ARG_INFO_EX(arginfo_uuid_generate_sha1, 0, 0, 2)
	ZEND_ARG_INFO(0, uuid_ns)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()
#endif

#if defined(HAVE_UUID_TYPE)
ZEND_BEGIN_ARG_INFO_EX(arginfo_uuid_type, 0, 0, 1)
	ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()
#endif

#if defined(HAVE_UUID_VARIANT)
ZEND_BEGIN_ARG_INFO_EX(arginfo_uuid_variant, 0, 0, 1)
	ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()
#endif

#define arginfo_uuid_time arginfo_uuid_is_valid

#define arginfo_uuid_mac arginfo_uuid_is_valid

#define arginfo_uuid_parse arginfo_uuid_is_valid

#define arginfo_uuid_unparse arginfo_uuid_is_valid


ZEND_FUNCTION(uuid_create);
ZEND_FUNCTION(uuid_is_valid);
ZEND_FUNCTION(uuid_compare);
ZEND_FUNCTION(uuid_is_null);
#if defined(HAVE_UUID_GENERATE_MD5)
ZEND_FUNCTION(uuid_generate_md5);
#endif
#if defined(HAVE_UUID_GENERATE_SHA1)
ZEND_FUNCTION(uuid_generate_sha1);
#endif
#if defined(HAVE_UUID_TYPE)
ZEND_FUNCTION(uuid_type);
#endif
#if defined(HAVE_UUID_VARIANT)
ZEND_FUNCTION(uuid_variant);
#endif
ZEND_FUNCTION(uuid_time);
ZEND_FUNCTION(uuid_mac);
ZEND_FUNCTION(uuid_parse);
ZEND_FUNCTION(uuid_unparse);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(uuid_create, arginfo_uuid_create)
	ZEND_FE(uuid_is_valid, arginfo_uuid_is_valid)
	ZEND_FE(uuid_compare, arginfo_uuid_compare)
	ZEND_FE(uuid_is_null, arginfo_uuid_is_null)
#if defined(HAVE_UUID_GENERATE_MD5)
	ZEND_FE(uuid_generate_md5, arginfo_uuid_generate_md5)
#endif
#if defined(HAVE_UUID_GENERATE_SHA1)
	ZEND_FE(uuid_generate_sha1, arginfo_uuid_generate_sha1)
#endif
#if defined(HAVE_UUID_TYPE)
	ZEND_FE(uuid_type, arginfo_uuid_type)
#endif
#if defined(HAVE_UUID_VARIANT)
	ZEND_FE(uuid_variant, arginfo_uuid_variant)
#endif
	ZEND_FE(uuid_time, arginfo_uuid_time)
	ZEND_FE(uuid_mac, arginfo_uuid_mac)
	ZEND_FE(uuid_parse, arginfo_uuid_parse)
	ZEND_FE(uuid_unparse, arginfo_uuid_unparse)
	ZEND_FE_END
};
