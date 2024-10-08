# UUID extension

A wrapper around Universally Unique IDentifier library (libuuid).

# Sources

* Official git repository: https://github.com/php/pecl-networking-uuid
* Issue tracker: https://github.com/php/pecl-networking-uuid/issues

# Build

Compatible with PHP 7.0 or greater.

You need the libuuid library with development headers.

From the sources tree

    $ phpize
    $ ./configure --with-uuid
    $ make
    $ make test

From https://pecl.php.net/ using pecl command

    $ pecl install uuid

From https://packagist.org/ using PHP Installer for Extensions

    $ pie install pecl/uuid

# LICENSE

Authors: Hartmut Holzgraefe, Remi Collet

This extension is licensed under [LGPL-2.1-or-later](https://www.gnu.org/licenses/lgpl-2.1.html)

