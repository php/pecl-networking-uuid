dnl $Id$
dnl config.m4 for extension uuid

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(uuid, for uuid support,
 [  --with-uuid             Include uuid support])

if test "$PHP_UUID" != "no"; then
  AC_DEFINE(HAVE_UUID, 1, [ ])
	PHP_ADD_LIBRARY(uuid)  
  PHP_NEW_EXTENSION(uuid, uuid.c, $ext_shared)
fi
