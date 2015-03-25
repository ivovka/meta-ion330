FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

COMPATIBLE_MACHINE_ion330 = "ion330"
KMACHINE_ion330 = "intel-core2-32"
KBRANCH_ion330 = "standard/common-pc"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://defconfig \
      "
KERNEL_FEATURES_remove = "features/netfilter/netfilter.scc"
