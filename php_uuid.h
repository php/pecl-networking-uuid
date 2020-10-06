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
#define PHP_UUID_VERSION    "1.2.0"
#define PHP_UUID_RELEASED   "2020-10-06"
#define PHP_UUID_STATE      "stable"
#define PHP_UUID_AUTHORS    "Hartmut Holzgraefe, Remi Collet"


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
