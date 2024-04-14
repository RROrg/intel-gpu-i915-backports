# Intel® Graphics Driver Backports for Linux® OS (intel-gpu-i915-backports)

Contains the backported kernel module source code of intel GPUs on [Proxmox VE](https://pve.proxmox.com/) and DSM for SA6400. You can create Dynamic Kernel Module Support (DKMS) as well as precompiled Out of Tree modules packages, which can be installed on supported OS distributions.

We are using [backport project](https://backports.wiki.kernel.org/index.php/Main_Page) to generate out of tree i915 kernel module source codes.

This repo is a code snapshot of https://github.com/intel/mainline-tracking/tree/linux/v6.5 and does not contain individual git change history.


## Out of tree kernel drivers
This repository contains following drivers.
1. Intel® Graphics Driver Backports(i915) - The main graphics driver (includes a compatible DRM subsystem and dmabuf if necessary)


## Dependencies

  These drivers have dependency on Intel® GPU firmware and few more kernel mode drivers may be needed based on specific use cases, platform, and distributions. Source code of additional drivers should be available at https://github.com/intel-gpu

- [Intel® GPU firmware](https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/tree/i915) - Firmware required by intel GPUs.

Each project is tagged consistently, so when pulling these repos, pull the same tag.

## Supported OS Kernel/Distribution
  Our current backport supports the following OS Distribution.

| OS Distribution | OS Version | Kernel Version  | Installation Instructions |
|---  |---  |---  |--- |
| Proxmox VE | 8.1--8.2 | 6.5, 6.8 | Install the released .deb via `apt install` |
| DSM for SA6400 | 7.1.x / 7.2.x | 5.10.55 | Shipped by supported loaders |


## Product Releases:
Please refer [Releases](https://dgpu-docs.intel.com/releases/index.html)
