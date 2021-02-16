# Overrides

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"

# Additions

FILESEXTRAPATHS_prepend := "${THISDIR}/patches-espressobin:"
SRC_URI_append = " \
    file://0001-Added-rootwait-to-CONFIG_MENDER_BOOTCOMMAND.patch \
    file://0002-Removed-default-environment-vars.patch \
    file://0003-Added-fdt_addr_r-and-kernel_addr_r-to-CONFIG_EXTRA_E.patch \
"

do_mender_uboot_auto_configure_prepend () {
    export ARCH="${TUNE_ARCH_32}"
}
