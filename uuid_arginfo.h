/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d6443ac36cb354cca5638d7f002c18a6c7ae02b0 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_uuid_create, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, uuid_type, IS_LONG, 0, "UUID_TYPE_DEFAULT")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_uuid_is_valid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, uuid, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_uuid_compare, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uuid1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uuid2, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_uuid_is_null arginfo_uuid_is_valid

#if defined(HAVE_UUID_GENERATE_MD5)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_uuid_generate_md5, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uuid_ns, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

#if defined(HAVE_UUID_GENERATE_SHA1)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_uuid_generate_sha1, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uuid_ns, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

#if defined(HAVE_UUID_TYPE)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_uuid_type, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uuid, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

#if defined(HAVE_UUID_VARIANT)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_uuid_variant, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uuid, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

#if defined(HAVE_UUID_TIME)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_uuid_time, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uuid, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_uuid_mac, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uuid, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_uuid_parse arginfo_uuid_mac

#define arginfo_uuid_unparse arginfo_uuid_mac


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
#if defined(HAVE_UUID_TIME)
ZEND_FUNCTION(uuid_time);
#endif
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
#if defined(HAVE_UUID_TIME)
	ZEND_FE(uuid_time, arginfo_uuid_time)
#endif
	ZEND_FE(uuid_mac, arginfo_uuid_mac)
	ZEND_FE(uuid_parse, arginfo_uuid_parse)
	ZEND_FE(uuid_unparse, arginfo_uuid_unparse)
	ZEND_FE_END
};

static void register_uuid_symbols(int module_number)
{
#if defined(UUID_VARIANT_NCS)
	REGISTER_LONG_CONSTANT("UUID_VARIANT_NCS", UUID_VARIANT_NCS, CONST_PERSISTENT | CONST_CS);
#endif
#if defined(UUID_VARIANT_DCE)
	REGISTER_LONG_CONSTANT("UUID_VARIANT_DCE", UUID_VARIANT_DCE, CONST_PERSISTENT | CONST_CS);
#endif
#if defined(UUID_VARIANT_MICROSOFT)
	REGISTER_LONG_CONSTANT("UUID_VARIANT_MICROSOFT", UUID_VARIANT_MICROSOFT, CONST_PERSISTENT | CONST_CS);
#endif
#if defined(UUID_VARIANT_OTHER)
	REGISTER_LONG_CONSTANT("UUID_VARIANT_OTHER", UUID_VARIANT_OTHER, CONST_PERSISTENT | CONST_CS);
#endif
	REGISTER_LONG_CONSTANT("UUID_TYPE_DEFAULT", 0, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("UUID_TYPE_DCE", UUID_TYPE_DCE, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("UUID_TYPE_NAME", UUID_TYPE_NAME, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("UUID_TYPE_TIME", UUID_TYPE_TIME, CONST_PERSISTENT | CONST_CS);
#if defined(UUID_TYPE_DCE_SECURITY)
	REGISTER_LONG_CONSTANT("UUID_TYPE_SECURITY", UUID_TYPE_DCE_SECURITY, CONST_PERSISTENT | CONST_CS);
#endif
#if defined(UUID_TYPE_DCE_MD5)
	REGISTER_LONG_CONSTANT("UUID_TYPE_MD5", UUID_TYPE_DCE_MD5, CONST_PERSISTENT | CONST_CS);
#endif
	REGISTER_LONG_CONSTANT("UUID_TYPE_RANDOM", UUID_TYPE_DCE_RANDOM, CONST_PERSISTENT | CONST_CS);
#if defined(UUID_TYPE_DCE_SHA1)
	REGISTER_LONG_CONSTANT("UUID_TYPE_SHA1", UUID_TYPE_DCE_SHA1, CONST_PERSISTENT | CONST_CS);
#endif
	REGISTER_LONG_CONSTANT("UUID_TYPE_NULL", -1, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("UUID_TYPE_INVALID", -42, CONST_PERSISTENT | CONST_CS);
}
