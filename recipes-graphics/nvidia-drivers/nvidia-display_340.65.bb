# nvidia-display .bb build file
# Copyright (C) 2005-2006, Advanced Micro Devices, Inc.  All Rights Reserved
# Copyright (C) 2012, sleep(5) ltd
# Released under the MIT license (see /COPYING)

require nvidia-drivers.inc
require nvidia-display.inc

PR = "r0.${NVDRIVERPR}.${NVDISPLAYPR}"

SRC_URI[md5sum] = "4aa6039b8543312b41a924bb87b0b2db"
SRC_URI[sha256sum] = "e78511435d7794cac09916b98857d98d0c36607ac4dfde0b05ea4aef26ecd973"

