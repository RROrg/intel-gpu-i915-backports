#ifndef _BACKPORT_DRM_ELD_H
#define _BACKPORT_DRM_ELD_H

#if LINUX_VERSION_IS_GEQ(6,8,0)
#include_next <drm/drm_eld.h>
#else
#include_next <drm/drm_edid.h>
#endif

#endif
