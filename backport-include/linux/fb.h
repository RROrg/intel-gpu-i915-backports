#ifndef _BACKPORT_LINUX_FB_H
#define _BACKPORT_LINUX_FB_H
#include_next<linux/fb.h>
#ifdef BPM_FB_ACTIVATE_KD_TEXT_NOT_PRESENT
#define FB_ACTIVATE_KD_TEXT   512       /* for KDSET vt ioctl */
#endif

#if LINUX_VERSION_IS_LESS(6,6,0)
#define FB_GEN_DEFAULT_DEFERRED_IOMEM_OPS FB_GEN_DEFAULT_DEFERRED_IO_OPS
#endif

#endif

