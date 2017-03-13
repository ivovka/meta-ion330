FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

LINUX_VERSION_ion330 = "4.8.17"
COMPATIBLE_MACHINE_ion330 = "ion330"
KMACHINE_ion330 = "intel-core2-32"
KBRANCH_ion330 = "standard/base"
SRCREV_meta_ion330 ?= "bb6984f46b5a1a4fa85af23032d49d6a012bd5ab"
SRCREV_machine_ion330 ?= "9bcb4ea3fa107f1a8790c8c3408eb250e8d1d66e"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://defconfig \
      "
KERNEL_FEATURES_remove = "features/netfilter/netfilter.scc"
