/*
   +----------------------------------------------------------------------+
   | This library is free software; you can redistribute it and/or        |
   | modify it under the terms of the GNU Lesser General Public           |
   | License as published by the Free Software Foundation; either         |
   | version 2.1 of the License, or (at your option) any later version.   | 
   |                                                                      |
   | This library is distributed in the hope that it will be useful,      |
   | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
   | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    |
   | Lesser General Public License for more details.                      | 
   |                                                                      |
   | You should have received a copy of the GNU Lesser General Public     |
   | License in the file LICENSE along with this library;                 |
   | if not, write to the                                                 | 
   |                                                                      |
   |   Free Software Foundation, Inc.,                                    |
   |   59 Temple Place, Suite 330,                                        |
   |   Boston, MA  02111-1307  USA                                        |
   +----------------------------------------------------------------------+
   | Authors: Hartmut Holzgraefe <hartmut@php.net>                        |
   |          Remi Collet <remi@php.net>                                  |
   +----------------------------------------------------------------------+
*/

#include "php_uuid.h"

#ifdef HAVE_UUID

#if PHP_VERSION_ID < 80000
#define VALUE_ERROR(n,name,msg) php_error_docref(NULL, E_WARNING, "Argument #%d (%s) %s", n, name, msg); RETURN_FALSE
#define RETURN_THROWS() return

#include "uuid_legacy_arginfo.h"
#else
#define VALUE_ERROR(n,name,msg) zend_argument_value_error(n, msg); RETURN_THROWS()

#include "uuid_arginfo.h"
#endif


/* {{{ uuid_module_entry
 */
zend_module_entry uuid_module_entry = {
	STANDARD_MODULE_HEADER,
	"uuid",
	ext_functions,
	PHP_MINIT(uuid),     /* Replace with NULL if there is nothing to do at php startup   */ 
	NULL,                /* Replace with NULL if there is nothing to do at php shutdown  */
	NULL,                /* Replace with NULL if there is nothing to do at request start */
	NULL,                /* Replace with NULL if there is nothing to do at request end   */
	PHP_MINFO(uuid),
	PHP_UUID_VERSION, 
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_UUID
ZEND_GET_MODULE(uuid)
#endif


/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(uuid)
{
#ifdef UUID_VARIANT_NCS
	REGISTER_LONG_CONSTANT("UUID_VARIANT_NCS", UUID_VARIANT_NCS, CONST_PERSISTENT | CONST_CS);
#endif /* UUID_VARIANT_NCS */
#ifdef UUID_VARIANT_DCE
	REGISTER_LONG_CONSTANT("UUID_VARIANT_DCE", UUID_VARIANT_DCE, CONST_PERSISTENT | CONST_CS);
#endif /* UUID_VARIANT_DCE */
#ifdef UUID_VARIANT_MICROSOFT
	REGISTER_LONG_CONSTANT("UUID_VARIANT_MICROSOFT", UUID_VARIANT_MICROSOFT, CONST_PERSISTENT | CONST_CS);
#endif /* UUID_VARIANT_MICROSOFT */
#ifdef UUID_VARIANT_OTHER
	REGISTER_LONG_CONSTANT("UUID_VARIANT_OTHER", UUID_VARIANT_OTHER, CONST_PERSISTENT | CONST_CS);
#endif /* UUID_VARIANT_OTHER */
	REGISTER_LONG_CONSTANT("UUID_TYPE_DEFAULT", 0, CONST_PERSISTENT | CONST_CS);
/* deprecated alias */
	REGISTER_LONG_CONSTANT("UUID_TYPE_DCE", UUID_TYPE_DCE_RANDOM, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("UUID_TYPE_NAME", UUID_TYPE_DCE_TIME, CONST_PERSISTENT | CONST_CS);
/* library types */
	REGISTER_LONG_CONSTANT("UUID_TYPE_TIME", UUID_TYPE_DCE_TIME, CONST_PERSISTENT | CONST_CS);
#ifdef UUID_TYPE_DCE_SECURITY
	REGISTER_LONG_CONSTANT("UUID_TYPE_SECURITY", UUID_TYPE_DCE_SECURITY, CONST_PERSISTENT | CONST_CS);
#endif
#ifdef UUID_TYPE_DCE_MD5
	REGISTER_LONG_CONSTANT("UUID_TYPE_MD5", UUID_TYPE_DCE_MD5, CONST_PERSISTENT | CONST_CS);
#endif
	REGISTER_LONG_CONSTANT("UUID_TYPE_RANDOM", UUID_TYPE_DCE_RANDOM, CONST_PERSISTENT | CONST_CS);
#ifdef UUID_TYPE_DCE_SHA1
	REGISTER_LONG_CONSTANT("UUID_TYPE_SHA1", UUID_TYPE_DCE_SHA1, CONST_PERSISTENT | CONST_CS);
#endif
/* extension specific types */
	REGISTER_LONG_CONSTANT("UUID_TYPE_NULL", -1, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("UUID_TYPE_INVALID", -42, CONST_PERSISTENT | CONST_CS);

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(uuid)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "UUID extension", "enabled");
	php_info_print_table_row(2, "Version",  PHP_UUID_VERSION " (" PHP_UUID_STATE ")");
	php_info_print_table_row(2, "Released", PHP_UUID_RELEASED);
	php_info_print_table_row(2, "Authors",  PHP_UUID_AUTHORS);
	php_info_print_table_end();
	/* add your stuff here */

}
/* }}} */


/* {{{ proto string uuid_create([int uuid_type])
  Generate a new UUID */
PHP_FUNCTION(uuid_create)
{

	zend_long uuid_type = UUID_TYPE_DEFAULT;
	uuid_t uuid;
	char uuid_str[37];



	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|l", &uuid_type) == FAILURE) {
		RETURN_THROWS();
	}

	switch(uuid_type) {
	  case UUID_TYPE_DCE_TIME:
		uuid_generate_time(uuid);
		break;
	  case UUID_TYPE_DCE_RANDOM:
		uuid_generate_random(uuid);
		break;
	  case UUID_TYPE_DEFAULT:
		uuid_generate(uuid);
		break;
	  default:
#if PHP_VERSION_ID < 80000
		php_error_docref(NULL,
				 E_WARNING,
				 "Unknown/invalid UUID type '%ld' requested, using default type instead",
				 uuid_type);
		uuid_generate(uuid);
#else
		zend_argument_value_error(1, "Unknown/invalid UUID type '" ZEND_LONG_FMT "'", uuid_type);
		RETURN_THROWS();
#endif
		break;        
	}

	uuid_unparse(uuid, uuid_str);

	RETURN_STRING(uuid_str);
}
/* }}} uuid_create */


/* {{{ proto bool uuid_is_valid(string uuid)
  Check whether a given UUID string is a valid UUID */
PHP_FUNCTION(uuid_is_valid)
{

	const char * uuid = NULL;
	size_t uuid_len = 0;
	uuid_t u; 



	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &uuid, &uuid_len) == FAILURE) {
		RETURN_THROWS();
	}

	RETURN_BOOL(0 == uuid_parse(uuid, u));
}
/* }}} uuid_is_valid */


/* {{{ proto int uuid_compare(string uuid1, string uuid2)
  Compare two UUIDs */
PHP_FUNCTION(uuid_compare)
{

	const char * uuid1 = NULL;
	size_t uuid1_len = 0;
	const char * uuid2 = NULL;
	size_t uuid2_len = 0;
	uuid_t u1, u2;



	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &uuid1, &uuid1_len, &uuid2, &uuid2_len) == FAILURE) {
		RETURN_THROWS();
	}
	if (uuid_parse(uuid1, u1)) {
		VALUE_ERROR(1, "$uuid1", "UUID expected");
	}
	if (uuid_parse(uuid2, u2)) {
		VALUE_ERROR(2, "$uuid2", "UUID expected");
	}

	RETURN_LONG(uuid_compare(u1, u2));
}
/* }}} uuid_compare */


/* {{{ proto bool uuid_is_null(string uuid)
  Check wheter an UUID is the NULL UUID 00000000-0000-0000-0000-000000000000 */
PHP_FUNCTION(uuid_is_null)
{

	const char * uuid = NULL;
	size_t uuid_len = 0;
	uuid_t u;



	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &uuid, &uuid_len) == FAILURE) {
		RETURN_THROWS();
	}


	if (uuid_parse(uuid, u)) {
		VALUE_ERROR(1, "$uuid", "UUID expected");
	}

	RETURN_BOOL(uuid_is_null(u));
}
/* }}} uuid_is_null */


#ifdef HAVE_UUID_GENERATE_MD5
/* {{{ proto int uuid_generate_md5(string uuid_ns, string name)
  Generate a MD5 hashed (predictable) UUID based on a well-known UUID */
PHP_FUNCTION(uuid_generate_md5)
{

	const char * uuid, * name;
	size_t uuid_len, name_len;
	uuid_t ns, out;
	char uuid_str[37];

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &uuid, &uuid_len, &name, &name_len) == FAILURE) {
		RETURN_THROWS();
	}

	if (uuid_parse(uuid, ns)) {
		VALUE_ERROR(1, "$uuid_ns", "UUID expected");
	}
	uuid_generate_md5(out, ns, name, name_len);
	uuid_unparse(out, uuid_str);

	RETURN_STRING(uuid_str);
}
/* }}} uuid_generate_md5 */
#endif /* HAVE_UUID_GENERATE_MD5 */


#ifdef HAVE_UUID_GENERATE_SHA1
/* {{{ proto int uuid_generate_sha1(string uuid_ns, string name)
  Generate a SHA1 hashed (predictable) UUID based on a well-known UUID */
PHP_FUNCTION(uuid_generate_sha1)
{

	const char * uuid, * name;
	size_t uuid_len, name_len;
	uuid_t ns, out;
	char uuid_str[37];

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &uuid, &uuid_len, &name, &name_len) == FAILURE) {
		RETURN_THROWS();
	}

	if (uuid_parse(uuid, ns)) {
		VALUE_ERROR(1, "$uuid_ns",  "UUID expected");
	}
	uuid_generate_sha1(out, ns, name, name_len);
	uuid_unparse(out, uuid_str);

	RETURN_STRING(uuid_str);
}
/* }}} uuid_generate_sha1 */
#endif /* HAVE_UUID_GENERATE_SHA1 */


#ifdef HAVE_UUID_TYPE
/* {{{ proto int uuid_type(string uuid)
  Return the UUIDs type */
PHP_FUNCTION(uuid_type)
{

	const char * uuid = NULL;
	size_t uuid_len = 0;
	uuid_t u;



	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &uuid, &uuid_len) == FAILURE) {
		RETURN_THROWS();
	}

	if (uuid_parse(uuid, u)) {
		VALUE_ERROR(1, "$uuid", "UUID expected");
	}
	if (uuid_is_null(u)) {
		RETURN_LONG(UUID_TYPE_NULL);
	}

	RETURN_LONG(uuid_type(u));
}
/* }}} uuid_type */

#endif /* HAVE_UUID_TYPE */

#ifdef HAVE_UUID_VARIANT
/* {{{ proto int uuid_variant(string uuid)
  Return the UUIDs variant */
PHP_FUNCTION(uuid_variant)
{

	const char * uuid = NULL;
	size_t uuid_len = 0;
	uuid_t u;



	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &uuid, &uuid_len) == FAILURE) {
		RETURN_THROWS();
	}

	if (uuid_parse(uuid, u)) {
		VALUE_ERROR(1, "$uuid", "UUID expected");
	}
	if (uuid_is_null(u)) {
		RETURN_LONG(UUID_TYPE_NULL);
	}

	RETURN_LONG(uuid_variant(u));
}
/* }}} uuid_variant */

#endif /* HAVE_UUID_VARIANT */

/* {{{ proto int uuid_time(string uuid)
  Extract creation time from a time based UUID as UNIX timestamp */
PHP_FUNCTION(uuid_time)
{

	const char * uuid = NULL;
	size_t uuid_len = 0;
	uuid_t u;



	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &uuid, &uuid_len) == FAILURE) {
		RETURN_THROWS();
	}

	if (uuid_parse(uuid, u)
#ifdef HAVE_UUID_VARIANT
		|| (uuid_variant(u) != 1)
#endif
#ifdef HAVE_UUID_TYPE
		|| (uuid_type(u) != 1)
#endif 
		) {
		VALUE_ERROR(1, "$uuid", "UUID DCE TIME expected");
	}

	RETURN_LONG(uuid_time(u, NULL));
}
/* }}} uuid_time */


/* {{{ proto string uuid_mac(string uuid)
  Get UUID creator network MAC address */
PHP_FUNCTION(uuid_mac)
{

	const char * uuid = NULL;
	size_t uuid_len = 0;
	uuid_t u;
	char uuid_str[37];



	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &uuid, &uuid_len) == FAILURE) {
		RETURN_THROWS();
	}

	if (uuid_parse(uuid, u)
#ifdef HAVE_UUID_VARIANT
		|| (uuid_variant(u) != 1)
#endif
#ifdef HAVE_UUID_TYPE
		|| (uuid_type(u) != 1)
#endif 
		) {
		VALUE_ERROR(1, "$uuid", "UUID DCE TIME expected");
	}

	uuid_unparse(u, uuid_str);
	RETURN_STRING((char *)(uuid_str + 24));
}
/* }}} uuid_mac */


/* {{{ proto string uuid_parse(string uuid)
   */
PHP_FUNCTION(uuid_parse)
{

	const char * uuid = NULL;
	size_t uuid_len = 0;
	uuid_t uuid_bin;



	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &uuid, &uuid_len) == FAILURE) {
		RETURN_THROWS();
	}

	if (uuid_parse(uuid, uuid_bin)) {
		VALUE_ERROR(1, "$uuid", "UUID expected");
	}
	
	RETURN_STRINGL((char *)uuid_bin, sizeof(uuid_t));
}
/* }}} uuid_parse */


/* {{{ proto string uuid_unparse(string uuid)
   */
PHP_FUNCTION(uuid_unparse)
{

	const char * uuid = NULL;
	size_t uuid_len = 0;
	char uuid_txt[37];



	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &uuid, &uuid_len) == FAILURE) {
		RETURN_THROWS();
	}

	if (uuid_len != sizeof(uuid_t)) {
		VALUE_ERROR(1, "$uuid", "UUID expected");
	}
		
	uuid_unparse((unsigned char *)uuid, uuid_txt);
		
	RETURN_STRINGL(uuid_txt, 36);
}
/* }}} uuid_unparse */

#endif /* HAVE_UUID */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
