#ifndef _BACKPORT_LINUX_MMZONE_H
#define _BACKPORT_LINUX_MMZONE_H

#include_next <linux/mmzone.h>

#if LINUX_VERSION_IS_LESS(6,8,0)
#define MAX_PAGE_ORDER (MAX_ORDER - 1)
#endif

#endif /* _BACKPORT_LINUX_MMZONE_H */
