/*
  +----------------------------------------------------------------------+
  | PHP Version 4                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2003 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.02 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available at through the world-wide-web at                           |
  | http://www.php.net/license/2_02.txt.                                 |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: HArtmut Holzgraefe <hartmut@six.de>                          |
  +----------------------------------------------------------------------+

  $Id$ 
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_uuid.h"

#include <uuid/uuid.h>

#define UUID_TYPE_TIME    1
#define UUID_TYPE_DCE     2
#define UUID_TYPE_NAME    3
#define UUID_TYPE_RANDOM  4


/* {{{ uuid_functions[] */
function_entry uuid_functions[] = {
	PHP_FE(uuid_create,	NULL)
	PHP_FE(uuid_compare,	NULL)
	PHP_FE(uuid_is_null,	NULL)
	PHP_FE(uuid_variant,	NULL)
	PHP_FE(uuid_type,	NULL)
	PHP_FE(uuid_time,	NULL)
	PHP_FE(uuid_mac,	NULL)
	{NULL, NULL, NULL}
};
/* }}} */

/* {{{ uuid_module_entry
 */
zend_module_entry uuid_module_entry = {
	STANDARD_MODULE_HEADER,
	"uuid",
	uuid_functions,
	PHP_MINIT(uuid),
	NULL,
	NULL,
	NULL,
	PHP_MINFO(uuid),
	"0.1", 
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_UUID
ZEND_GET_MODULE(uuid)
#endif

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(uuid)
{
	REGISTER_LONG_CONSTANT("UUID_VARIANT_NCS",       UUID_VARIANT_NCS,       CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("UUID_VARIANT_DCE",       UUID_VARIANT_DCE,       CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("UUID_VARIANT_MICROSOFT", UUID_VARIANT_MICROSOFT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("UUID_VARIANT_OTHER",     UUID_VARIANT_OTHER,     CONST_CS | CONST_PERSISTENT);

	REGISTER_LONG_CONSTANT("UUID_TYPE_TIME",      UUID_TYPE_NAME,   CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("UUID_TYPE_DCE",       UUID_TYPE_DCE,    CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("UUID_TYPE_NAME",      UUID_TYPE_NAME,   CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("UUID_TYPE_RANDOM",    UUID_TYPE_RANDOM, CONST_CS | CONST_PERSISTENT);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(uuid)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "uuid support", "enabled");
	php_info_print_table_end();
}
/* }}} */


/* {{{ proto string uuid_create([int flags])
   Create a UUID */
PHP_FUNCTION(uuid_create)
{
	int argc = ZEND_NUM_ARGS();
	long flags;
	uuid_t uuid;
	char uuid_str[37];

	if (zend_parse_parameters(argc TSRMLS_CC, "|l", &flags) == FAILURE) 
		return;

	if (flags == UUID_TYPE_TIME || flags == UUID_TYPE_NAME) {		
		/* Generate Time/System Name based UUID */
		uuid_generate_time(uuid);
	} else if (flags == UUID_TYPE_DCE || flags == UUID_TYPE_RANDOM) {
		/* Generate Random based UUID, much better */
		uuid_generate_random(uuid);
	} else {
		/* Fall back and use the system default. In most cases this
		   is the Random Based one. */
		uuid_generate(uuid);
	}
	uuid_unparse(uuid, uuid_str);

	RETURN_STRING(uuid_str, 1);
}
/* }}} */

/* {{{ proto int uuid_compare(string uuid1, string uuid2)
   Compare two UUIDs */
PHP_FUNCTION(uuid_compare)
{
	int argc = ZEND_NUM_ARGS();
	char *uuid1 = NULL, *uuid2 = NULL;
	int uuid1_len, uuid2_len;
	uuid_t u1, u2;

	if (zend_parse_parameters(argc TSRMLS_CC, "ss", &uuid1, &uuid1_len, &uuid2, &uuid2_len) == FAILURE) 
		return;

	if(uuid_parse(uuid1, u1)) RETURN_FALSE;
	if(uuid_parse(uuid2, u2)) RETURN_FALSE;

	RETURN_LONG(uuid_compare(u1, u2));
}
/* }}} */

/* {{{ proto bool uuid_is_null(string uuid)
   Check for NULL UUID */
PHP_FUNCTION(uuid_is_null)
{
	int argc = ZEND_NUM_ARGS();
	char *uuid = NULL;
	int uuid_len;
	uuid_t u;

	if (zend_parse_parameters(argc TSRMLS_CC, "s", &uuid, &uuid_len) == FAILURE) 
		return;
	
	if(uuid_parse(uuid, u)) RETURN_FALSE;
	
	if(uuid_is_null(u)) RETURN_TRUE;

	RETURN_FALSE;
}
/* }}} */

/* {{{ proto int uuid_variant(string uuid)
   Get UUID variant */
PHP_FUNCTION(uuid_variant)
{
	int argc = ZEND_NUM_ARGS();
	char *uuid = NULL;
	int uuid_len;
	uuid_t u;

	if (zend_parse_parameters(argc TSRMLS_CC, "s", &uuid, &uuid_len) == FAILURE) 
		return;

	if(uuid_parse(uuid, u)) RETURN_FALSE;

	RETURN_LONG(uuid_variant(u));
}
/* }}} */

/* {{{ proto int uuid_type(string uuid)
   Get UUID type */
PHP_FUNCTION(uuid_type)
{
	int argc = ZEND_NUM_ARGS();
	char *uuid = NULL;
	int uuid_len;
	uuid_t u;

	if (zend_parse_parameters(argc TSRMLS_CC, "s", &uuid, &uuid_len) == FAILURE) 
		return;

	if(uuid_parse(uuid, u)) RETURN_FALSE;

	RETURN_LONG(uuid_type(u));
}
/* }}} */

/* {{{ proto int uuid_time(string uuid)
   Get UUID creation time as UNIX timestamp */
PHP_FUNCTION(uuid_time)
{
	int argc = ZEND_NUM_ARGS();
	char *uuid = NULL;
	int uuid_len;
	uuid_t u;

	if (zend_parse_parameters(argc TSRMLS_CC, "s", &uuid, &uuid_len) == FAILURE) 
		return;

	if(uuid_parse(uuid, u)) RETURN_FALSE;
	if(uuid_variant(u) != 1) RETURN_FALSE;
	if(uuid_type(u) != 1) RETURN_FALSE;

	RETURN_LONG(uuid_time(u, NULL));
}
/* }}} */

/* {{{ proto string uuid_mac(string uuid)
   Get UUID creator network MAC address */
PHP_FUNCTION(uuid_mac)
{
	int argc = ZEND_NUM_ARGS();
	char *uuid = NULL;
	int uuid_len;
	uuid_t u;
	char uuid_str[37];

	if (zend_parse_parameters(argc TSRMLS_CC, "s", &uuid, &uuid_len) == FAILURE) 
		return;

	if(uuid_parse(uuid, u)) RETURN_FALSE;
	if(uuid_variant(u) != 1) RETURN_FALSE;
	if(uuid_type(u) != 1) RETURN_FALSE;
	if(uuid[10]&0x80) RETURN_FALSE;

	uuid_unparse(u, uuid_str);
	RETURN_STRING(uuid_str+24, 1);
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
