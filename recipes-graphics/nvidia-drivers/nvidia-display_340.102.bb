# nvidia-display .bb build file
# Copyright (C) 2005-2006, Advanced Micro Devices, Inc.  All Rights Reserved
# Copyright (C) 2012, sleep(5) ltd
# Released under the MIT license (see /COPYING)

require nvidia-drivers.inc
require nvidia-display.inc

PR = "r0.${NVDRIVERPR}.${NVDISPLAYPR}"

SRC_URI[distro.md5sum] = "61aad6a98238bc61466e6a9e392cfd08"
SRC_URI[distro.sha256sum] = "61b13d5dae0f6f5d788a4d8c4c98e8d971d19cb90b606058060d007946248828"

