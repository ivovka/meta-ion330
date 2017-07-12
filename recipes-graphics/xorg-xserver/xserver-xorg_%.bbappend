#PACKAGECONFIG = "udev ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'glx', '', d)}"
# PACKAGECONFIG_remove_ion330 = "dri2 dri glx"
#PACKAGECONFIG[dri] = "--enable-dri,--disable-dri,glproto xf86driproto"
EXTRA_OECONF_remove_ion330 = "--disable-xinerama"
EXTRA_OECONF_append_ion330 = " --enable-xinerama"
#EXTRA_OECONF += "--with-fop=no \
#                 --with-pic \
#                 --disable-static \
#                 --enable-xinerama \
#                 --disable-record \
#                 --disable-dmx \
#                 --disable-xnest \
#                 --enable-xvfb \
#                 --enable-composite \
#                 --without-dtrace \
#                 --with-int10=x86emu \
#                 --sysconfdir=/etc/X11 \
#                 --localstatedir=/var \
#                 --with-xkb-output=/var/lib/xkb \
#                 --with-sha1=libcrypto \
#                 ac_cv_file__usr_share_sgml_X11_defs_ent=no \
#"

