# SPDX-License-Identifier: MIT

obj-$(CPTCFG_DRM_DP_AUX_BUS) += drm_dp_aux_bus.o

drm_display_helper-y := drm_display_helper_mod.o
drm_display_helper-$(CPTCFG_DRM_DISPLAY_DP_HELPER) += \
	drm_dp_dual_mode_helper.o \
	drm_dp_helper.o \
	drm_dp_mst_topology.o \
	drm_dsc_helper.o
drm_display_helper-$(CPTCFG_DRM_DISPLAY_HDCP_HELPER) += drm_hdcp_helper.o
drm_display_helper-$(CPTCFG_DRM_DISPLAY_HDMI_HELPER) += \
	drm_hdmi_helper.o \
	drm_scdc_helper.o
drm_display_helper-$(CPTCFG_DRM_DP_AUX_CHARDEV) += drm_dp_aux_dev.o
drm_display_helper-$(CPTCFG_DRM_DP_CEC) += drm_dp_cec.o

obj-$(CPTCFG_DRM_DISPLAY_HELPER) += drm_display_helper.o
