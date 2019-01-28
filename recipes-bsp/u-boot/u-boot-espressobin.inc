#
# Patches for Mender auto-configuration scripts
#

FILESEXTRAPATHS_prepend := "${THISDIR}/mender:"
SRC_URI += "file://0001-Include-menuconfig-options-when-checking-for-Kconfig.menderpatch"
SRC_URI += "file://0001-Set-HOSTARCH-and-ARCH-when-making-env-target.menderpatch"

do_mender_uboot_auto_configure_fix () {
    patch ${WORKDIR}/uboot_auto_patch.sh ${WORKDIR}/0001-Include-menuconfig-options-when-checking-for-Kconfig.menderpatch
    patch ${WORKDIR}/uboot_auto_configure.sh ${WORKDIR}/0001-Set-HOSTARCH-and-ARCH-when-making-env-target.menderpatch
    sed -i 's/${ARCH}/'${TUNE_ARCH_32}'/g' ${WORKDIR}/uboot_auto_configure.sh
}

python () {
    if bb.utils.contains('MENDER_UBOOT_AUTO_CONFIGURE', '1', True, False, d):
        bb.build.addtask('do_mender_uboot_auto_configure_fix', 'do_mender_uboot_auto_configure', 'do_patch', d)
}
