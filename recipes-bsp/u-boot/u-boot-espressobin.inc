#
# Patches for Mender u-boot
#

FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"
SRC_URI_append = " file://0001-Added-rootwait-to-CONFIG_MENDER_BOOTCOMMAND.patch"

#
# Patches for Mender auto-configuration scripts
#

FILESEXTRAPATHS_prepend := "${THISDIR}/mender:"
SRC_URI_append = " file://0001-Include-menuconfig-options-when-checking-for-Kconfig.patch.mender"
SRC_URI_append = " file://0002-Set-HOSTARCH-and-ARCH-when-making-env-target.patch.mender"

do_mender_uboot_auto_configure_fix () {
    patch "${WORKDIR}/uboot_auto_patch.sh" "${WORKDIR}/0001-Include-menuconfig-options-when-checking-for-Kconfig.patch.mender"
    patch "${WORKDIR}/uboot_auto_configure.sh" "${WORKDIR}/0002-Set-HOSTARCH-and-ARCH-when-making-env-target.patch.mender"
    sed -i 's/${ARCH}/'${TUNE_ARCH_32}'/g' "${WORKDIR}/uboot_auto_configure.sh"
}

python () {
    if bb.utils.contains('MENDER_UBOOT_AUTO_CONFIGURE', '1', True, False, d):
        bb.build.addtask('do_mender_uboot_auto_configure_fix', 'do_mender_uboot_auto_configure', 'do_patch', d)
}
