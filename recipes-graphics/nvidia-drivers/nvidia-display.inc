# nvidia-display .bb build file
# Copyright (C) 2005-2006, Advanced Micro Devices, Inc.  All Rights Reserved
# Copyright (C) 2012, sleep(5) ltd
# Released under the MIT license (see /COPYING)

NVDISPLAYPR = "0"

DEFAULT_PREFERENCE = "-1"
DEFAULT_PREFERENCE_atom-nvidia = "1"

LIC_FILES_CHKSUM = "file://LICENSE;md5=60ad17cc726658e8cf73578bea47b85f"


SRC_URI="http://download.nvidia.com/XFree86/Linux-${NVIDIA_ARCH}/${PV}/${PKG_BASENAME}.run;name=distro"
#SRC_URI += " file://0001-oe-cross-compile.patch \
#             file://gl.pc \
#             file://0002-define-GLAPI.patch \
#           "
SRC_URI += " file://0001-oe-cross-compile.patch \
  file://0009-nv340on410.patch \
  http://http.download.nvidia.com/XFree86/vdpau/include/vdpau/vdpau_x11.h;name=vdpau_x11 \
  http://http.download.nvidia.com/XFree86/vdpau/include/vdpau/vdpau.h;name=vdpau \
  https://www.khronos.org/registry/EGL/api/EGL/egl.h;name=egl \
  https://www.khronos.org/registry/EGL/api/EGL/eglext.h;name=eglext \
  https://www.khronos.org/registry/EGL/api/EGL/eglplatform.h;name=eglplatform \
  https://www.khronos.org/registry/EGL/api/KHR/khrplatform.h;name=khrplatform \ 
  https://khronos.org/registry/OpenGL/api/GL/glext.h;name=glext \
  https://khronos.org/registry/OpenGL/api/GL/glxext.h;name=glxext \
  https://khronos.org/registry/OpenGL/api/GL/glcorearb.h;name=glcorearb \
  file://gl.pc \
  file://egl.pc \
  file://vdpau.pc \
  "
#	     file://0005-nvidia-fix-compile-gcc6.patch 

SRC_URI[vdpau_x11.md5sum] = "6b950995a6b742d236087bf0a97b15d5"
SRC_URI[vdpau_x11.sha256sum] = "d29bf9dda3961cfd8ec3c391cad3e3a3294f419cab566a1cce48969dcd534a34"
SRC_URI[vdpau.md5sum] = "098ec61321177e81b52e3d0c1b4a0223"
SRC_URI[vdpau.sha256sum] = "a0c12541b26934ef55e2b951d4b9c5d2e42832bf987c5ace34dae406db58611a"
#SRC_URI[egl.md5sum] = "3165120316419eca041fc7f1ae33a51e"
#SRC_URI[egl.sha256sum] = "26a4496ae48549b858de9e9ceadee8dc1c65dd020a3cf852e55367d4e16ce86e"
SRC_URI[egl.md5sum] = "647e0537660f4954f8f48faeb03c6928"
SRC_URI[egl.sha256sum] = "c3dc71d18dd4f2e4c7277876a2d6ae0b5c7f189933826e6bc0b0f8f2e2e94588"
#SRC_URI[eglext.md5sum] = "e62928dacbf58e98a675b0e12a2ef8b2"
#SRC_URI[eglext.sha256sum] = "a2e10144e44035461a0cf4ce68969f3b2f734147d910215b3dd556ffb4dbedf9"
SRC_URI[eglext.md5sum] = "4206d90339aa4a553b32e9e5d1e08311"
SRC_URI[eglext.sha256sum] = "7613ec1daf1538c559d30f08c9ea986c70e89debab83056a34c349611a8aa513"
SRC_URI[eglplatform.md5sum] = "6c8a1dbeb4d7d60ea46eea572df0cbff"
SRC_URI[eglplatform.sha256sum] = "e65cb25136676afa1207704437c3cd3fab92e507dd8d220171306814db66b133"
SRC_URI[khrplatform.md5sum] = "b1b3e1eecabd608e3d05f1e338dc1bed"
SRC_URI[khrplatform.sha256sum] = "fe7725728dc40d46134d9838d29e3bbbc95a70e77a1182a2be9ded6470a2378d"
#SRC_URI[glext.md5sum] = "366d62af3b3ba69a9e554333349c9a37"
#SRC_URI[glext.sha256sum] = "0d078c50889b0a91be4f3414a529480b613db1d6534c250503f9110ac322c383"
SRC_URI[glext.md5sum] = "ffe0a2fb8e424c117d62f09dd50a8861"
SRC_URI[glext.sha256sum] = "c34ab66205c2ab299ce1e1fb3d62bd8b53858c1605859f8ea5848bc70b89b8a2"
#SRC_URI[glxext.md5sum] = "8e766bb79bf536f7c87041c35f42f10e"
#SRC_URI[glxext.sha256sum] = "dfcdfbd520a995d69a3dc485e540138b5bb2bb0f202e0b727e0fe7a934f570f6"
SRC_URI[glxext.md5sum] = "23e6bae572d8b926b10475a400d4ff46"
SRC_URI[glxext.sha256sum] = "7e03c7de912418525c24c039d0166b211c0501f585e0c1bb942ea5370d654afa"
#SRC_URI[glcorearb.md5sum] = "cd9af4217b30fdcf45111aff7b7710a0"
#SRC_URI[glcorearb.sha256sum] = "db9285e9d43355f1547413740a86d940298a57a06cadc43d6de15a93121da148"
SRC_URI[glcorearb.md5sum] = "e5ab9c335849e6fe2b8050396c200b15"
SRC_URI[glcorearb.sha256sum] = "04bd6fbabb3638d481d029f852ed00d2ffdc716040d2d0c28325274cd7210dc6"

S="${WORKDIR}/${PKG_BASENAME}/kernel"

PROVIDES += " virtual/libgl virtual/egl virtual/libvdpau"
# add virtual/mesa dependency to make sure we install GL headers
DEPENDS += " virtual/mesa"
do_install() {
	# install kernel modules
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	oe_runmake INSTALL_MOD_PATH="${D}" CC="${KERNEL_CC}" LD="${KERNEL_LD}" install

	# install directories
	install -m 0755 -d ${D}/usr/lib/xorg/modules/{drivers,extensions} ${D}/usr/lib/vdpau ${D}/usr/lib/vendors ${D}/usr/share/doc/nvidia ${D}/usr/bin
	#install -m 0755 -d ${D}/usr/include/{GL,EGL} 

	#install documentation
	cp -pPR ${WORKDIR}/${PKG_BASENAME}/html ${D}/usr/share/doc/nvidia/

	#install libraries
	#install xorg bits
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/*_drv.so ${D}/usr/lib/xorg/modules/drivers
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libglx.so* ${D}/usr/lib/xorg/modules/extensions/libglx_nvidia.so
	# no need to install libnvidia-wfb, because xorg server already contains it
	#install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-wfb.so.${PV} ${D}/usr/lib/xorg/modules
	#ln -s libnvidia-wfb.so.${PV} ${D}/usr/lib/xorg/modules/libwfb.so
	#install GL library
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libGL.so.${PV} ${D}/usr/lib
	install -m 0644 ${WORKDIR}/${PKG_BASENAME}/libGL.la ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-glcore.so.${PV} ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-tls.so.${PV} ${D}/usr/lib
	install -m 0755 -d ${D}/usr/lib/tls
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/tls/* ${D}/usr/lib/tls
	ln -s libGL.so.${PV} ${D}/usr/lib/libGL_nvidia.so.1 
	ln -s libGL.so.${PV} ${D}/usr/lib/libGL.so.1
	ln -s libGL.so.1 ${D}/usr/lib/libGL.so
	install -m 0755 -d ${D}/usr/lib/pkgconfig
	install -m 0644 ${WORKDIR}/gl.pc ${D}/usr/lib/pkgconfig
	#use headers from mesa library
	#install -m 0644 ${WORKDIR}/${PKG_BASENAME}/gl.h ${D}/usr/include/GL
	#install -m 0644 ${WORKDIR}/${PKG_BASENAME}/glx.h ${D}/usr/include/GL
	#install -m 0644 ${WORKDIR}/glext.h ${D}/usr/include/GL
	#install -m 0644 ${WORKDIR}/glxext.h ${D}/usr/include/GL
	#install -m 0644 ${WORKDIR}/glcorearb.h ${D}/usr/include/GL
	#install VDPAU library
	install -m 0755 -d ${D}/usr/include/vdpau
	install -m 0644 ${WORKDIR}/vdpau.h ${D}/usr/include/vdpau
	install -m 0644 ${WORKDIR}/vdpau_x11.h ${D}/usr/include/vdpau
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libvdpau.so.${PV} ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libvdpau_trace.so.${PV} ${D}/usr/lib/vdpau
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libvdpau_nvidia.so.${PV} ${D}/usr/lib/vdpau
	ln -sf libvdpau_nvidia.so.${PV} ${D}/usr/lib/vdpau/libvdpau_nvidia.so.1
        ln -sf libvdpau_nvidia.so.${PV} ${D}/usr/lib/vdpau/libvdpau_nvidia.so
	ln -sf libvdpau.so.${PV} ${D}/usr/lib/libvdpau.so.1
	ln -sf libvdpau.so.1 ${D}/usr/lib/libvdpau.so
	install -m 0755 -d ${D}/usr/lib/pkgconfig
	install -m 0644 ${WORKDIR}/vdpau.pc ${D}/usr/lib/pkgconfig
	#install CUDA library
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libcuda.so.${PV} ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvcuvid.so.${PV} ${D}/usr/lib
	ln -s libcuda.so.${PV} ${D}/usr/lib/libcuda.so.1
	ln -s libcuda.so.1 ${D}/usr/lib/libcuda.so
	#install OpenCL libraries
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libOpenCL.so.1.0.0 ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-opencl.so.${PV} ${D}/usr/lib
	install -m 0644 ${WORKDIR}/${PKG_BASENAME}/nvidia.icd ${D}/usr/lib/vendors
	ln -s libOpenCL.so.1.0.0 ${D}/usr/lib/libOpenCL.so.1
	ln -s libOpenCL.so.1 ${D}/usr/lib/libOpenCL.so
	#install nvidia-ml library
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-ml.so.${PV} ${D}/usr/lib
        ln -sf libnvidia-ml.so.${PV} ${D}/usr/lib/libnvidia-ml.so.1
	#install NvEncodeAPI, NvIFROpenGL, NvFBC
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-encode.so.${PV} ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-ifr.so.${PV} ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-fbc.so.${PV} ${D}/usr/lib
	#install EGL libraries
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libEGL.so.${PV} ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-eglcore.so.${PV} ${D}/usr/lib
	#use headers from mesa
	#install -m 0755 -d ${D}/usr/include/EGL
	#install -m 0755 -d ${D}/usr/include/KHR
	#install -m 0644 ${WORKDIR}/egl.h ${D}/usr/include/EGL
	#install -m 0644 ${WORKDIR}/eglext.h ${D}/usr/include/EGL
	#install -m 0644 ${WORKDIR}/eglplatform.h ${D}/usr/include/EGL
	#install -m 0644 ${WORKDIR}/khrplatform.h ${D}/usr/include/KHR
	install -m 0755 -d ${D}/usr/lib/pkgconfig
	install -m 0644 ${WORKDIR}/egl.pc ${D}/usr/lib/pkgconfig
	#libraries not stated in nvidia README
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libGLESv1_CM.so.${PV} ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libGLESv2.so.${PV} ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-glsi.so.${PV} ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-compiler.so.${PV} ${D}/usr/lib
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/libnvidia-cfg.so.${PV} ${D}/usr/lib
	ln -s libEGL.so.${PV} ${D}/usr/lib/libEGL.so.1
	ln -s libEGL.so.1 ${D}/usr/lib/libEGL.so
	#install applications
	install -m 0755 ${WORKDIR}/${PKG_BASENAME}/{nvidia-settings,nvidia-xconfig,nvidia-smi,nvidia-persistenced} ${D}/usr/bin
	#fix libGL.la
	sed -i -e 's:__GENERATED_BY__:Yocto:' ${D}/usr/lib/libGL.la
	sed -i -e 's:__LIBGL_PATH__:/usr/lib:' ${D}/usr/lib/libGL.la
}

PACKAGES += " libgl-nvidia \
  libgl-nvidia-dev \
  libegl-nvidia \
  libegl-nvidia-dev \
  libvdpau-nvidia \
  libvdpau-nvidia-dev \
  xf86-video-nvidia \
  xf86-video-nvidia-dev \
  libcuda-nvidia-dev \
  libcuda-nvidia \
  opencl-nvidia-dev \
  opencl-nvidia \
  libgles1-nvidia \
  libgles2-nvidia \
  "

FILES_${PN} = "${bindir} \
  ${libdir}/libnvidia-ml.so.* \
  ${libdir}/libnvidia-encode.so.* \
  ${libdir}/libnvidia-ifr.so.* \
  ${libdir}/libnvidia-fbc.so.* \
  ${libdir}/libnvidia-compiler.so.* \
  ${libdir}/libnvidia-glsi.so.* \
  ${libdir}/libnvidia-cfg.so.* \
  "
FILES_${PN}-doc = "${datadir}/doc/nvidia"
FILES_${PN}-dev = ""
#FILES_libgl-nvidia-dev = "${includedir}/GL 
FILES_libgl-nvidia-dev = " \
  ${libdir}/libGL.la \
  ${libdir}/libGL.so \
  ${libdir}/pkgconfig/gl.pc \
  "
FILES_libgl-nvidia = "${libdir}/libGL.so.* \
  ${libdir}/libGL_nvidia.so.* \
  ${libdir}/libnvidia-glcore.so.${PV} \
  ${libdir}/libnvidia-tls.so.${PV} \
  ${libdir}/tls \
  ${libdir}/vdpau/*.so.* \
  "
FILES_libvdpau-nvidia-dev = "${includedir}/vdpau \
  ${libdir}/vdpau/libvdpau*.so \
  ${libdir}/pkgconfig/vdpau.pc \
  ${libdir}/libvdpau.so \
  "
FILES_libvdpau-nvidia = "${libdir}/vdpau/libvdpau*.so.* \
  ${libdir}/libvdpau.so.* \
  "
#FILES_libegl-nvidia-dev = "${includedir}/EGL \
#  ${includedir}/KHR 
FILES_libegl-nvidia-dev = " \
  ${libdir}/libEGL.so \
  ${libdir}/pkgconfig/egl.pc \
  "
FILES_libegl-nvidia = "${libdir}/libEGL.so.* \
  ${libdir}/libnvidia-eglcore.so.${PV} \
  "
FILES_xf86-video-nvidia = "${libdir}/xorg/modules/drivers/*_drv.so \
  ${libdir}/xorg/modules/extensions/*.so \
  "
FILES_libcuda-nvidia-dev = "${libdir}/libcuda.so"
FILES_libcuda-nvidia = "${libdir}/libcuda.so.* \
  ${libdir}/libnvcuvid.so.${PV} \
  "
FILES_opencl-nvidia-dev = "${libdir}/libOpenCL.so"
FILES_opencl-nvidia = "${libdir}/libOpenCL.so.* \
  ${libdir}/libnvidia-opencl.so.* \
  ${libdir}/vendors \
  "
FILES_libgles1-nvidia = "${libdir}/libGLESv1_CM.so.*"
FILES_libgles2-nvidia = "${libdir}/libGLESv2.so.*"

RPROVIDES_libgl-nvidia = "libgl"
RPROVIDES_libegl-nvidia = "egl"
RPROVIDES_libvdpau-nvidia = "libvdpau"

RDEPENDS_libgl-nvidia += "${PN}"
RDEPENDS_libvdpau-nvidia += "${PN}"
RDEPENDS_libegl-nvidia += "${PN}"
RDEPENDS_xf86-video-nvidia += "${PN}"
RDEPENDS_libcuda-nvidia += "${PN}"
RDEPENDS_opencl-nvidia += "${PN}"
RDEPENDS_libgles1-nvidia += "${PN}"
RDEPENDS_libgles2-nvidia += "${PN}"

INSANE_SKIP_${PN} = "already-stripped textrel ldflags"
INSANE_SKIP_libgl-nvidia = "textrel ldflags"
INSANE_SKIP_libgl-nvidia-dev = "textrel ldflags"
INSANE_SKIP_xf86-video-nvidia = "textrel ldflags"
INSANE_SKIP_xf86-video-nvidia-dev = "textrel ldflags"
INSANE_SKIP_libcuda-nvidia = "textrel ldflags"
INSANE_SKIP_libcuda-nvidia-dev = "textrel ldflags"
INSANE_SKIP_libgles1-nvidia = "textrel ldflags"
INSANE_SKIP_libgles2-nvidia = "textrel ldflags"
INSANE_SKIP_libegl-nvidia = "textrel ldflags"
INSANE_SKIP_opencl-nvidia = "textrel ldflags"
INSANE_SKIP_libvdpau-nvidia = "textrel ldflags"
