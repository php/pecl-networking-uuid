dnl
dnl $ Id: $
dnl

PHP_ARG_WITH(uuid, whether uuid is available,[  --with-uuid[=DIR]    With uuid support])


if test "$PHP_UUID" != "no"; then
   PHP_CHECK_FUNC_LIB(uuid_type, uuid)
   PHP_CHECK_FUNC_LIB(uuid_variant, uuid)


  PHP_ADD_INCLUDE($PHP_UUID_DIR/include)

  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_UUID"
  AC_CHECK_HEADER([uuid/uuid.h], [], AC_MSG_ERROR('uuid/uuid.h' header not found))
  PHP_SUBST(UUID_SHARED_LIBADD)

  PHP_ADD_LIBRARY_WITH_PATH(uuid, $PHP_UUID_DIR/lib, UUID_SHARED_LIBADD)
  export CPPFLAGS="$OLD_CPPFLAGS"

  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_UUID"

  AC_MSG_CHECKING(PHP version)
  AC_TRY_COMPILE([#include <php_version.h>], [
#if PHP_VERSION_ID < 40000
#error  this extension requires at least PHP version 4.0.0
#endif
],
[AC_MSG_RESULT(ok)],
[AC_MSG_ERROR([need at least PHP 4.0.0])])

  export CPPFLAGS="$OLD_CPPFLAGS"


  PHP_SUBST(UUID_SHARED_LIBADD)
  AC_DEFINE(HAVE_UUID, 1, [ ])

  PHP_NEW_EXTENSION(uuid, uuid.c , $ext_shared)

fi

