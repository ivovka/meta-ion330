# nvidia-display .bb build file
# Copyright (C) 2005-2006, Advanced Micro Devices, Inc.  All Rights Reserved
# Copyright (C) 2012, sleep(5) ltd
# Released under the MIT license (see /COPYING)

NVDISPLAYPR = "0"

DEFAULT_PREFERENCE = "-1"
DEFAULT_PREFERENCE_atom-nvidia = "1"

LIC_FILES_CHKSUM = "file://LICENSE;md5=60ad17cc726658e8cf73578bea47b85f"


SRC_URI="http://download.nvidia.com/XFree86/Linux-${NVIDIA_ARCH}/${PV}/${PKG_BASENAME}.run"
#SRC_URI += " file://0001-oe-cross-compile.patch \
#             file://gl.pc \
#             file://0002-define-GLAPI.patch \
#           "
SRC_URI += " file://0001-oe-cross-compile.patch \
           "

S="${WORKDIR}/${PKG_BASENAME}/kernel"

#PROVIDES = "virtual/libgl virtual/mesa"

PACKAGES += "libgl-nvidia libgl-nvidia-dev xf86-video-nvidia xf86-video-nvidia-dev"

# libgl-nvidia contains the libgl bits
FILES_libgl-nvidia = "${libdir}/*.so.* ${libdir}/tls ${libdir}/vdpau/*.so.*"
FILES_libgl-nvidia-dev = "${libdir}/*.so ${libdir}/vdpau/*.so"
#RPROVIDES_libgl-nvidia = "libgl"
RDEPENDS_libgl-nvidia += "${PN}"

# the xserver driver and glx extension
FILES_xf86-video-nvidia = "${libdir}/xorg/modules/drivers/*_drv.so \
			   ${libdir}/xorg/modules/extensions/*.so \
			  "
RDEPENDS_xf86-video-nvidia += "${PN}"

FILES_${PN}-doc = "${datadir}/doc/nvidia"

INSANE_SKIP_${PN} = "already-stripped ldflags"
INSANE_SKIP_libgl-nvidia = "textrel ldflags"
INSANE_SKIP_libgl-nvidia-dev = "textrel ldflags"
INSANE_SKIP_xf86-video-nvidia = "textrel ldflags"
INSANE_SKIP_xf86-video-nvidia-dev = "textrel ldflags"

do_install() {
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	oe_runmake INSTALL_MOD_PATH="${D}" CC="${KERNEL_CC}" LD="${KERNEL_LD}" install

	install -d ${D}/usr/lib/xorg/modules/drivers/
	install -d ${D}/usr/lib/xorg/modules/extensions/
	install -d ${D}/usr/share/doc/nvidia
        install -d ${D}/usr/lib/vdpau

	cp -pPR ${WORKDIR}/${PKG_BASENAME}/html ${D}/usr/share/doc/nvidia/

        # this is the driver package -- move these so they don't end up in the
        # libgl package as well.
        mv ${WORKDIR}/${PKG_BASENAME}/*_drv.so ${D}/usr/lib/xorg/modules/drivers
        mv ${WORKDIR}/${PKG_BASENAME}/libglx.so* ${D}/usr/lib/xorg/modules/extensions/libglx_nvidia.so

        mv ${WORKDIR}/${PKG_BASENAME}/libGL.so* ${D}/usr/lib/libGL_nvidia.so.1
        mv ${WORKDIR}/${PKG_BASENAME}/libvdpau_nvidia.so* ${D}/usr/lib/vdpau/libvdpau_nvidia.so.1
	cp -pPR ${WORKDIR}/${PKG_BASENAME}/*.so.* ${D}/usr/lib
	cp -pPR ${WORKDIR}/${PKG_BASENAME}/tls ${D}/usr/lib

        ln -sf libnvidia-ml.so.${PV} ${D}/usr/lib/libnvidia-ml.so.1
        ln -sf libvdpau_nvidia.so.1 ${D}/usr/lib/vdpau/libvdpau_nvidia.so

	ln -s libOpenCL.so.${PV} ${D}/usr/lib/libOpenCL.so
	ln -s libOpenCL.so.${PV} ${D}/usr/lib/libOpenCL.so.1
}
