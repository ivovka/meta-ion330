FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

LINUX_VERSION_ion330 = "4.10.9"
COMPATIBLE_MACHINE_ion330 = "ion330"
KMACHINE_ion330 = "intel-core2-32"
KBRANCH_ion330 = "standard/base"
#SRCREV_meta_ion330 ?= "bb6984f46b5a1a4fa85af23032d49d6a012bd5ab"
SRCREV_machine_ion330 ?= "f6392b77fb91b650eb9e470c142160857f10ed70"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://defconfig \
  file://usb-keyboard.cfg \
  file://cgroups.cfg \
      "
KERNEL_FEATURES_remove = "features/netfilter/netfilter.scc"
