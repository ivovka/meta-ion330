DESCRIPTION = "JFS Filesystem Utilities"
HOMEPAGE = "http://jfs.sourceforge.net/"
SECTION = "base"
PR = "r0"
DEPENDS = "util-linux"

SRC_URI = "http://jfs.sourceforge.net/project/pub/${PN}-${PV}.tar.gz"
SRC_URI += "file://0001-add-sys-types-h-to-extract-c.patch"
SRC_URI[md5sum] = "8809465cd48a202895bc2a12e1923b5d"
SRC_URI[sha256sum] = "244a15f64015ce3ea17e49bdf6e1a0fb4f9af92b82fa9e05aa64cb30b5f07a4d"
LICENSE = "GPL"
LIC_FILES_CHKSUM = "file://COPYING;md5=d32239bcb673463ab874e80d47fae504"

inherit autotools

# Fix duplicates
do_install_append() {
  rm -f ${D}/usr/sbin/mkfs.jfs ${D}/usr/sbin/fsck.jfs
  ln -sf /usr/sbin/jfs_fsck ${D}/usr/sbin/fsck.jfs
  ln -sf /usr/sbin/jfs_mkfs ${D}/usr/sbin/mkfs.jfs
}
