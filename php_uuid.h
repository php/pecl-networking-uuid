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
  | Author: Hartmut Holzgraefe <hartmut@php.net>                         |
  +----------------------------------------------------------------------+

  $Id$ 
*/

#ifndef PHP_UUID_H
#define PHP_UUID_H

#ifdef PHP_WIN32
#define PHP_UUID_API __declspec(dllexport)
#else
#define PHP_UUID_API
#endif

extern zend_module_entry uuid_module_entry;
#define phpext_uuid_ptr &uuid_module_entry

PHP_MINIT_FUNCTION(uuid);
PHP_MINFO_FUNCTION(uuid);

PHP_FUNCTION(uuid_create);
PHP_FUNCTION(uuid_compare);
PHP_FUNCTION(uuid_is_null);
PHP_FUNCTION(uuid_is_valid);
PHP_FUNCTION(uuid_variant);
PHP_FUNCTION(uuid_type);
PHP_FUNCTION(uuid_time);
PHP_FUNCTION(uuid_mac);

#endif	/* PHP_UUID_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
