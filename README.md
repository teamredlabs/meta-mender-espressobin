# meta-mender-espressobin

This Yocto layer contains recipes which enable support for building the Mender client for Globalscale's Marvell ESPRESSObin Board.

## Dependencies

This layer depends on the following layers:

    repo: https://github.com/mendersoftware/meta-mender
    branch: dunfell
    layer: meta-mender-core
    revision: HEAD

    repo: https://github.com/teamredlabs/meta-espressobin
    branch: dunfell
    layer: meta-espressobin
    revision: HEAD
