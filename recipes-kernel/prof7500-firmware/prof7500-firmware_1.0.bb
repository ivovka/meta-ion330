SUMMARY = "Prof 7500 dvb card firmware for use with Linux kernel"
SECTION = "kernel"
LICENSE = "Firmware-prof7500"
LIC_FILES_CHKSUM = "file://LICENSE.prof7500;md5=000"
#NO_GENERIC_LICENSE
PE = "1"
PV = "1.0"
SRC_URI = "file://dvb-usb-p7500.fw"

do_compile() {
  :
}
do_install() {
  install -d ${D}/lib/firmware/
  install -m 0644 ${WORKDIR}/dvb-usb-p7500.fw ${D}/lib/firmware/dvb-usb-p7500.fw
}

FILES_${PN} += "/lib/firmware/*"

