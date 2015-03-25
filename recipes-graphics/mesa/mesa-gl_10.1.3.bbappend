PACKAGECONFIG = "dri vdpau ${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'x11', '', d)}"
PACKAGECONFIG[vdpau] = "--enable-vdpau,--disable-vdpau,libvdpau"
PACKAGECONFIG[dri] = "--enable-dri --with-dri-drivers=swrast, --disable-dri, dri2proto libdrm"
