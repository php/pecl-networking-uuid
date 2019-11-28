PHP_ARG_WITH(uuid, whether uuid is available,[  --with-uuid[=DIR]         With uuid support])

if test "$PHP_UUID" != "no"; then

  AC_MSG_CHECKING([for the location of libuuid])
  for dir in $PHP_UUID /usr/local /usr; do
    if test -f "$dir/include/uuid/uuid.h"; then
      PHP_UUID_DIR="$dir"
    fi
  done
  if test -z "$PHP_UUID_DIR"; then
    AC_MSG_ERROR(not found)
  else
    AC_MSG_RESULT(found in $PHP_UUID_DIR)
  fi
  PHP_ADD_INCLUDE($PHP_UUID_DIR/include)
  PHP_CHECK_FUNC_LIB(uuid_type, uuid)
  PHP_CHECK_FUNC_LIB(uuid_variant, uuid)
  PHP_CHECK_FUNC_LIB(uuid_generate_md5, uuid)
  PHP_CHECK_FUNC_LIB(uuid_generate_sha1, uuid)

  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_UUID"
  AC_CHECK_HEADER([uuid/uuid.h], [], AC_MSG_ERROR('uuid/uuid.h' header not found))
  PHP_SUBST(UUID_SHARED_LIBADD)

  PHP_ADD_LIBRARY_WITH_PATH(uuid, $PHP_UUID_DIR/$PHP_LIBDIR, UUID_SHARED_LIBADD)
  export CPPFLAGS="$OLD_CPPFLAGS"

  PHP_SUBST(UUID_SHARED_LIBADD)
  AC_DEFINE(HAVE_UUID, 1, [ ])

  PHP_NEW_EXTENSION(uuid, uuid.c , $ext_shared)

fi

