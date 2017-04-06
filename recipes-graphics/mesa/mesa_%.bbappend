SUMMARY += " (Minimized version only headers and libs necesarry to compile xorg server)"
FILESEXTRAPATHS =. "${FILE_DIRNAME}/mesa:"
#PROVIDES = "mesa-mini"
PROVIDES = "virtual/mesa"
PACKAGECONFIG = "gbm egl dri xvmc ${MESA_CRYPTO} ${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'x11', '', d)}"
PACKAGECONFIG[vdpau] = "--enable-vdpau,--disable-vdpau,virtual/libvdpau"
PACKAGECONFIG[dri] = "--enable-dri --without-dri-drivers, --disable-dri, dri2proto libdrm"

PACKAGES = "${PN}-dev"
FILES_${PN}-dev = "${includedir}"
do_install_append () {
  rm -rf ${D}${libdir}
  rm -rf ${D}${sysconfdir}
}
