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
   +----------------------------------------------------------------------+
*/

/* $ Id: $ */ 

#ifndef PHP_UUID_H
#define PHP_UUID_H

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#ifdef HAVE_UUID
#define PHP_UUID_VERSION "1.0.3"


#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
#ifdef  __cplusplus
} // extern "C" 
#endif
#include <uuid/uuid.h>
#ifdef  __cplusplus
extern "C" {
#endif

extern zend_module_entry uuid_module_entry;
#define phpext_uuid_ptr &uuid_module_entry

#ifdef PHP_WIN32
#define PHP_UUID_API __declspec(dllexport)
#else
#define PHP_UUID_API
#endif

PHP_MINIT_FUNCTION(uuid);
PHP_MSHUTDOWN_FUNCTION(uuid);
PHP_RINIT_FUNCTION(uuid);
PHP_RSHUTDOWN_FUNCTION(uuid);
PHP_MINFO_FUNCTION(uuid);

#ifdef ZTS
#include "TSRM.h"
#endif

#define FREE_RESOURCE(resource) zend_list_delete(Z_LVAL_P(resource))

#define PROP_GET_LONG(name)    Z_LVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_LONG(name, l) zend_update_property_long(_this_ce, _this_zval, #name, strlen(#name), l TSRMLS_CC)

#define PROP_GET_DOUBLE(name)    Z_DVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_DOUBLE(name, d) zend_update_property_double(_this_ce, _this_zval, #name, strlen(#name), d TSRMLS_CC)

#define PROP_GET_STRING(name)    Z_STRVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_GET_STRLEN(name)    Z_STRLEN_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_STRING(name, s) zend_update_property_string(_this_ce, _this_zval, #name, strlen(#name), s TSRMLS_CC)
#define PROP_SET_STRINGL(name, s, l) zend_update_property_stringl(_this_ce, _this_zval, #name, strlen(#name), s, l TSRMLS_CC)


PHP_FUNCTION(uuid_create);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(uuid_create_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
  ZEND_ARG_INFO(0, uuid_type)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define uuid_create_arg_info NULL
#endif

PHP_FUNCTION(uuid_is_valid);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(uuid_is_valid_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define uuid_is_valid_arg_info NULL
#endif

PHP_FUNCTION(uuid_compare);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(uuid_compare_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 2)
  ZEND_ARG_INFO(0, uuid1)
  ZEND_ARG_INFO(0, uuid2)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define uuid_compare_arg_info NULL
#endif

PHP_FUNCTION(uuid_is_null);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(uuid_is_null_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define uuid_is_null_arg_info NULL
#endif

#if HAVE_UUID_TYPE
PHP_FUNCTION(uuid_type);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(uuid_type_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define uuid_type_arg_info NULL
#endif

#endif /* HAVE_UUID_TYPE */
#if HAVE_UUID_VARIANT
PHP_FUNCTION(uuid_variant);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(uuid_variant_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define uuid_variant_arg_info NULL
#endif

#endif /* HAVE_UUID_VARIANT */
PHP_FUNCTION(uuid_time);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(uuid_time_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define uuid_time_arg_info NULL
#endif

PHP_FUNCTION(uuid_mac);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(uuid_mac_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define uuid_mac_arg_info NULL
#endif

PHP_FUNCTION(uuid_parse);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(uuid_parse_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define uuid_parse_arg_info NULL
#endif

PHP_FUNCTION(uuid_unparse);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(uuid_unparse_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define uuid_unparse_arg_info NULL
#endif

#ifdef  __cplusplus
} // extern "C" 
#endif

/* mirrored PHP Constants */
#define UUID_TYPE_DEFAULT 0
#define UUID_TYPE_TIME UUID_TYPE_DCE_TIME
#define UUID_TYPE_DCE UUID_TYPE_DCE_RANDOM
#define UUID_TYPE_NAME UUID_TYPE_DCE_TIME
#define UUID_TYPE_RANDOM UUID_TYPE_DCE_RANDOM
#define UUID_TYPE_NULL -1
#define UUID_TYPE_INVALID -42

#endif /* PHP_HAVE_UUID */

#endif /* PHP_UUID_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
