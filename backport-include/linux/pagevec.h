/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __BACKPORT_PAGEVEC_H
#define __BACKPORT_PAGEVEC_H
#include_next <linux/pagevec.h>

#if LINUX_VERSION_IS_LESS(6,3,0)
static inline void folio_batch_reinit(struct folio_batch *fbatch)
{
	fbatch->nr = 0;
}
#endif /* < 6.3 */

#if LINUX_VERSION_IS_LESS(6,5,0)
static inline void __folio_batch_release(struct folio_batch *fbatch)
{
	__pagevec_release((struct pagevec *)fbatch);
}

static inline unsigned int folio_batch_space(struct folio_batch *fbatch)
{
        return fbatch_space(fbatch);
}
#endif /* < 6.5 */

#endif /* __BACKPORT_PAGEVEC_H */
