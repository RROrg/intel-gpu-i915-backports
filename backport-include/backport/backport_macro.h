#ifndef BP_LINUX_BACKPORT_MACRO_H
#define BP_LINUX_BACKPORT_MACRO_H
#include <linux/version.h>
#include <backport/autoconf.h>

#ifdef CONFIG_SYNO_EPYC7002
// These modules are declared in kernel .config but not actually present on the
// system. Undef the flags to avoid introducing unnecessary dependencies.
#undef CONFIG_FB_MODULE
#undef CONFIG_ACPI_VIDEO_MODULE
#undef CONFIG_BACKLIGHT_CLASS_DEVICE_MODULE
#endif

#if LINUX_VERSION_IS_GEQ(6,7,0)
/*
 * 583cc9e4109529
 *  drm/i915: dynamically allocate the i915_gem_mm shrinker
 */
#define BPM_I915_GEM_MM_SHRINKER_DYNAMIC
#endif

#if LINUX_VERSION_IS_GEQ(6,4,0)
/*
 * 673aa1ed1c9b6 of: Rename of_modalias_node()
 */
#define BPM_OF_MODALIAS_NODE_RENAMED
#endif

#if LINUX_VERSION_IS_GEQ(6,3,0)
/*
 * 4d70c74659d974
 *  i915: Move list_count() to list.h as list_count_nodes() for broader use
 */
#define BPM_LIST_COUNT_NODES_AVAILABLE

/*
 * 2a81ada32f0e58
 *  driver core: make struct bus_type.uevent() take a const *
 */
#define BPM_STRUCT_BUS_TYPE_UEVENT_CONST

/*
 * 9cbad37ce8122d
 *  of: Add of_property_present() helper
 */
#define BPM_OF_PROPERTY_PRESENT_AVAILABLE
#endif

#if (LINUX_VERSION_IS_GEQ(6,3,0) || \
		LINUX_VERSION_IS_LESS(4,10,0) || \
			REDHAT_RELEASE_VERSION_IS_GEQ(8,9))
/*
 * 5e7b9a6ae8c3 swiotlb: remove swiotlb_max_segment
 */
#define BPM_SWIOTLB_MAX_SEGMENT_NOT_PRESENT
#endif

#if LINUX_VERSION_IS_GEQ(6,2,0)
/*
 * 4b21d25bf519c9
 *  overflow: Introduce overflows_type() and castable_to_type()
 */
#define BPM_OVERFLOWS_TYPE_AVAILABLE

/*
 * f571faf6e443b6
 *  timers: Provide timer_shutdown[_sync]()
 */
#define BPM_TIMER_SHUTDOWN_SYNC_AVAILABLE

/*
 * e9a688bcb1934
 * random: use rejection sampling for uniform bounded random integers
 */
#define BPM_GET_RANDOM_U32_BELOW_AVAILABLE

/*
 * 64f6a5d1922bf
 *  container_of: add container_of_const() that preserves const-ness of the pointer
 */
#define BPM_CONTAINER_OF_CONST_AVAILABLE
#endif

#if (LINUX_VERSION_IS_GEQ(6,2,0) || \
		REDHAT_RELEASE_VERSION_IS_GEQ(8,9))
/*
 * ff62b8e6588fb driver core: make struct class.devnode() take a const *
 */
#define BPM_DMA_HEAP_AND_DRM_DEVNODE_CONST_ARG_NOT_PRESENT

/*
 * 9a758d8756da drm: Move nomodeset kernel parameter to drivers/video
 */
#define BPM_VIDEO_FIRMWARE_DRIVERS_ONLY_NOT_EXPORTED
#endif

#if LINUX_VERSION_IS_GEQ(6,1,0)
/*
 * 0f60d28828dd dynamic_dname(): drop unused dentry argument
 */
#define BPM_DYNAMIC_DNAME_DENTRY_ARG_NOT_PRESENT

/*
 * aad0214f30264c
 *  dyndbg: add DECLARE_DYNDBG_CLASSMAP macro
 */
#define BPM_DECLARE_DYNDBG_CLASSMAP_AVAILABLE

/*
 * 3dbc80a3e4c55c
 *   ACPI: video: Make backlight class device registration a separate step (v2)
 */
#define BPM_ACPI_VIDEO_REGISTER_BACKLIGHT_AVAILABLE

/*
 * f39af05949a4 mm: add VMA iterator
 */
#define BPM_VMA_ITERATOR_AVAILABLE
#endif

#if LINUX_VERSION_IS_GEQ(6,0,0)
/*
 * 77414d195f90 vmscan: Add check_move_unevictable_folios()
 */
#define BPM_CHECK_MOVE_UNEVICTABLE_FOLIOS_AVAILABLE

/*
 * e33c267ab70d mm: shrinkers: provide shrinkers with names
 */
#define BPM_REGISTER_SHRINKER_NAME_AVAILABLE

/*
 * 73b4b53276a1 Revert "workqueue: remove unused cancel_work()"
 */
#define BPM_CANCEL_WORK_AVAILABLE
#endif

#if LINUX_VERSION_IS_GEQ(5,19,0)

/*
 * da68386d9edb1f57a drm: Rename dp/ to display/
 */
#define BPM_DRM_DP_HELPER_DIR_DISPLAY_PRESENT

/*
 * 84a1041c60ff fs: Remove pagecache_write_begin() and pagecache_write_end()
 */
#define BPM_PAGECACHE_WRITE_BEGIN_AND_END_NOT_PRESENT

/*
 * 0192c25c03cd2f drm/dp: add 128b/132b link status helpers from DP 2.0 E11
 */

#define BPM_DRM_DP_128B132B_API_PRESENT
/*
 * 68189fef88c7 fs: Change try_to_free_buffers() to take a folio
 */
#define BPM_CANCEL_DIRTY_PAGE_NOT_PRESENT
#endif

#if (LINUX_VERSION_IS_GEQ(5,19,0) || \
                REDHAT_RELEASE_VERSION_IS_GEQ(9,2) || \
                SUSE_RELEASE_VERSION_IS_GEQ(1,15,5,0))
/*
 * 912ff2ebd695 drm/i915: use the new iterator in i915_gem_busy_ioctl v2
 */
#define BPM_DMA_RESV_ITER_BEGIN_PRESENT

/*
 * 73511edf8b19 dma-buf: specify usage while adding fences to dma_resv obj v7
 * 842d9346b2fd drm/i915: Individualize fences before adding to dma_resv obj
 */
#define BPM_DMA_RESV_ADD_EXCL_FENCE_NOT_PRESENT
#endif

#if LINUX_VERSION_IS_LESS(5,19,0)
/*
 * 6a99099 drm/display: Move HDCP helpers into display-helper module
 */
#define BPM_HDCP_HELPERS_NOT_IN_DISPLAY_DIRECTORY

/*
 * ea4692c lib/string_helpers: Consolidate string helpers implementation
 */
#define BPM_CONSOLIDATE_STRING_HELPERS_NOT_PRESENT
#endif

#if LINUX_VERSION_IS_LESS(5,17,0)

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(9,1))
/*
 * 9dd3d069406c mm/filemap: Add filemap_add_folio()
 */
#define BPM_ADD_PAGE_CACHE_LOCKED_NOT_PRESENT
/*
 * 97cecb5a254f mm: introduce delete_from_page_cache()
 */
#define BPM_DELETE_FROM_PAGE_CACHE_NOT_PRESENT
#endif

/*
 * ec288a2cf7ca bitmap: unify find_bit operations
 */
#define BPM_FOR_EACH_CLEAR_BITRANGE_NOT_PRESENT
#endif

#if LINUX_VERSION_IS_GEQ(5,16,0)
/* DP 2.0 E11 feature */
/*
 * d6c6a76f80a1c9 drm: Update MST First Link Slot Information
 * Based on Encoding Format
 */
#define BPM_DRM_DP_MST_UPDATE_SLOTS_PRESENT
#endif

#if (LINUX_VERSION_IS_GEQ(5,17,0) || \
		REDHAT_RELEASE_VERSION_IS_GEQ(8,7))
/*
 * 6a2d2ddf2c345e0 drm: Move nomodeset kernel parameter to the DRM subsystem
 */
#define BPM_VGACON_TEXT_FORCE_NOT_PRESENT
#endif

#if (LINUX_VERSION_IS_GEQ(5,16,0) || \
		REDHAT_RELEASE_VERSION_IS_GEQ(8,7))
/*
 *12235da8c80a1 kernel/locking: Add context to ww_mutex_trylock()
 */
#define BPM_WW_MUTEX_TRYLOCK_WITH_CTX_PRESENT
 
/* c921ff373b469 dma-buf: add dma_resv_for_each_fence_unlocked v8
 *
 */
#define BPM_DMA_RESV_ITER_UNLOCKED_PRESENT
#endif

#if LINUX_VERSION_IS_GEQ(5,16,0) || REDHAT_RELEASE_VERSION_IS_GEQ(9,0) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,5,0)

/*
 * 16b0314aa746be dma-buf: move dma-buf symbols into the DMA_BUF module namespace
 */
#define BPM_MODULE_IMPORT_NS_SUPPORT
#endif

#if (LINUX_VERSION_IS_GEQ(5,16,0) || \
                REDHAT_RELEASE_VERSION_IS_GEQ(9,2) || \
                SUSE_RELEASE_VERSION_IS_GEQ(1,15,5,0))
/*
 * ab09243aa95a7 mm/migrate.c: remove MIGRATE_PFN_LOCKED
 */
#define BPM_MIGRATE_PFN_LOCKED_REMOVED

#endif

#if LINUX_VERSION_IS_LESS(5,15,46)
#if !(SUSE_RELEASE_VERSION_IS_GEQ(1,15,4,0) || \
	UBUNTU_RELEASE_VERSION_IS_GEQ(20,04)|| \
	REDHAT_RELEASE_VERSION_IS_GEQ(8,9))
/*
 * 0425473037db list: introduce list_is_head() helper and re-use it in list.h
 */
#define BPM_LIST_IS_HEAD_NOT_PRESENT
#endif
#endif

#if LINUX_VERSION_IS_LESS(5,17,0)
#if !(SUSE_RELEASE_VERSION_IS_GEQ(1,15,4,0) || \
	REDHAT_RELEASE_VERSION_IS_GEQ(8,7))

/*
 * 365481e42a8a driver core: auxiliary bus: Add driver data helpers
 */
#define BPM_AUXILIARY_BUS_HELPERS_NOT_PRESENT

#endif
#endif

#if (LINUX_VERSION_IS_GEQ(5,15,0) || \
                REDHAT_RELEASE_VERSION_IS_GEQ(9,1) || \
                SUSE_RELEASE_VERSION_IS_GEQ(1,15,5,0))

/*
 * ac1723c16b drm/i915: Track IRQ state in local device state.
 */
#define BPM_DRM_DEVICE_IRQ_ENABLED_INSIDE_LEGACY_ADDED

#endif

#if LINUX_VERSION_IS_LESS(5,15,8)

#if !((REDHAT_RELEASE_VERSION_IS_RANGE(8,7, 8,9) || REDHAT_RELEASE_VERSION_IS_GEQ(9,1)) || \
		(SUSE_RELEASE_VERSION_IS_GEQ(1,15,4,0) && SUSE_LOCAL_VERSION_IS_GEQ(24,41)))
/*
 * e4779015fd5d timers: implement usleep_idle_range()
 */
#define BPM_USLEEP_RANGE_STATE_NOT_PRESENT
#endif

#endif

#if LINUX_VERSION_IS_LESS(5,15,0)
#if !(SUSE_RELEASE_VERSION_IS_GEQ(1,15,4,0))

/*
 * f0ab00174eb7 PCI: Make saved capability state private to core
 * 621f7e354fd8 PCI: Make pci_set_of_node(), etc private
 */
#define BPM_PCI_INTERFACES_NOT_PRESENT

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(9,2))
/*
 * fc7a620 bus: Make remove callback return void
 *
 * In file bus.h in bus_type sturct, return type of remove function 
 * changed from int to void
 */
#define BPM_BUS_REMOVE_FUNCTION_RETURN_TYPE_CHANGED
#endif
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6))
/*
 * d19c81378829e locking/lockdep: Provide lockdep_assert{,_once}() helpers
 *
 */
#define BPM_LOCKDEP_ASSERT_API_NOT_PRESENT
#endif


#if !(UBUNTU_RELEASE_VERSION_IS_GEQ(20,04) || \
		REDHAT_RELEASE_VERSION_IS_GEQ(8,7))
/*
 * bf44e8cecc03c vgaarb: don't pass a cookie to vga_client_register
 *
 */
#define BPM_VGA_SET_DECODE_ARG_PCI_DEV_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6) || \
	UBUNTU_RELEASE_VERSION_IS_GEQ(20,04))

/*
 * 90e7a6de62781 lib/scatterlist: Provide a dedicated function to support table append
 *
 */
#define BPM_SG_ALLOC_TABLE_FROM_PAGES_SEGMENT_NOT_PRESENT
#ifdef BPM_SG_ALLOC_TABLE_FROM_PAGES_SEGMENT_NOT_PRESENT
#if !(REDHAT_RELEASE_VERSION_IS_LEQ(8,4) || \
         SUSE_RELEASE_VERSION_IS_GEQ(1,15,2,0) || \
	 LINUX_VERSION_IN_RANGE(5,4,0, 5,5,0))
/*
 * 89d8589cd72c6 Introduce and export __sg_alloc_table_from_pages
 */
#define BPM_SG_ALLOC_TABLE_FROM_PAGES_RETURNS_SCATTERLIST
#endif
#endif
#endif

#if !(SUSE_RELEASE_VERSION_IS_GEQ(1,15,4,0) || \
	UBUNTU_RELEASE_VERSION_IS_GEQ(20,04) || \
	REDHAT_RELEASE_VERSION_IS_GEQ(8,7))

#define BPM_VGA_CLIENT_UNREGISTER_NOT_PRESENT
#endif


#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6) || \
	SUSE_RELEASE_VERSION_IS_GEQ(1,15,4,0))

/*
 * 6f2beb268a5d swiotlb: Update is_swiotlb_active to add a struct device argument
 *
 */
#define BPM_IS_SWIOTLB_ACTIVE_ARG_DEV_NOT_PRESENT
#endif

/*
 * 1072ed3431f5ba2 drm/dp: Move panel DP AUX backlight support to
 * drm_dp_helper
 * 10f7b40e4f3050 drm/panel: add basic DP AUX backlight support
 */
#define BPM_AUX_BACKLIGHT_SUPPORT_TO_DRM_DP_NOT_PRESENT

#if !((LINUX_VERSION_IN_RANGE(5,14,0, 5,15,0) && UBUNTU_RELEASE_VERSION_IS_GEQ(1011,0)) || \
		(REDHAT_RELEASE_VERSION_IS_RANGE(8,6, 8,7) && REDHAT_BACKPORT_MINOR_VERSION_IS_GEQ(372,70,1)) || \
		REDHAT_RELEASE_VERSION_IS_GEQ(8,7))
/*
 * 59dc33252ee7
 * PCI: VMD: ACPI: Make ACPI companion lookup work for VMD bus
 */
#define BPM_PCI_FIND_HOST_BRIDGE_NOT_EXPORTED
#endif
#endif /*#if LINUX_VERSION_IS_LESS(5,15,0) */

#if LINUX_VERSION_IS_LESS(5,14,19)
#if !(LINUX_VERSION_IN_RANGE(5,10,80, 5,11,0) || \
		REDHAT_RELEASE_VERSION_IS_RANGE(8,7, 9,0) || \
		REDHAT_RELEASE_VERSION_IS_GEQ(9,1))
/*
 * 74ba917cfddd
 * arch/cc: Introduce a function to check for confidential computing features
 */
#define BPM_CC_PLATFORM_H_NOT_PRESENT
#endif
#endif

#if LINUX_VERSION_IS_LESS(5,14,0)

/* TBD: Need to check if its generic or controllable with version */
#define BPM_PTRACE_MAY_ACCESS_NOT_PRESENT

/*
 * 43e76d463c09a0
 *   driver core: add a helper to setup both the of_node and fwnode of a device
 */
#define BPM_DEVICE_SET_NODE_NOT_PRESENT

#endif

#if LINUX_VERSION_IS_LESS(5,13,0)
#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6))

/*
 * eb2dafbba8b82 tasklets: Prevent tasklet_unlock_spin_wait() deadlock on RT
 *
 */
#define BPM_TASKLET_UNLOCK_SPIN_WAIT_NOT_PRESENT
/*
 * dma-buf/dmabuf: Don't export dma_fence symbols
 *
 */
#define BPM_DMA_FENCE_PRIVATE_STUB_NOT_PRESENT

/*
 * f21ffe9f6da6d swiotlb: Expose swiotlb_nr_tlb function to modules
 *
 */
#define BPM_SWIOTLB_NR_TBL_NO_ARG_PRESENT

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,5))

/*
 * 3e31f94752e4 lockdep: Add lockdep_assert_not_held()
 */
#define BPM_LOCKDEP_ASSERT_NOT_HELD_NOT_PRESENT
#endif
#endif

#if !(LINUX_VERSION_IN_RANGE(5,10,70, 5,11,0) || CUSTOM_KERN_1_RELEASE_VERSION_IS_GEQ(8,6656) || CUSTOM_KERN_3_RELEASE_VERSION_IS_GEQ(136,12,0))
/*
 * 4f0f586bf0c8 treewide: Change list_sort to use const pointers
 *
 */
#define BPM_LIST_CMP_FUNC_T_NOT_PRESENT
#endif
#endif

#if (LINUX_VERSION_IS_GEQ(5,12,0) || \
		REDHAT_RELEASE_VERSION_IS_GEQ(8,9))
/*
 * a28a6e860c6c string.h: move fortified functions definitions in a dedicated header
 */
#define BPM_FORTIFY_STRING_H_NOT_PRESENT
#endif

#if LINUX_VERSION_IS_LESS(5,12,0)

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,5))

/*
 * dma-buf/dmabuf: Don't export dma_fence symbols
 */
#define BPM_DMA_FENCE_TIMESTAMP_NOT_PRESENT

/*
 * 276b738deb5bf PCI: Add resizable BAR infrastructure
 * 192f1bf7559e8 PCI: Add pci_rebar_bytes_to_size()
 *
 */
#define BPM_PCI_REBAR_SIZE_NOT_PRESENT

/*
 * 2d24dd5798d0 rbtree: Add generic add and find helpers
 */
#define RB_FIND_NOT_PRESENT

/*
 * 97a7e4733b9b mm: introduce page_needs_cow_for_dma() for deciding whether cow
 */
#define BPM_IS_COW_MAPPING_NOT_PRESENT

#endif


#endif

#if LINUX_VERSION_IS_LESS(5,11,0)

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,9))
/*
 * aa6159ab99a9ab kernel.h: split out mathematical helpers
 */
#define BPM_MATH_H_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,5))

/*
 * f0dbd2bd1c22c66 mm: slab: provide krealloc_array()
 *
 * Backport krealloc_array() api.
 *
 */
#define BPM_KREALLOC_ARRAY_NOT_PRESENT

/*
 * 23c887522e91 Relay: add CPU hotplug support
 *
 */
#define BPM_CONST_STRUCT_RCHAN_CALLBACKS_NOT_PRESENT

/*
 *cfc78dfd9b36 iommu/sva: Add PASID helpers
 */
#define BPM_IOMMU_SVA_LIB_H_NOT_PRESENT
#endif
/*
 * 295992fb815e7 mm: introduce vma_set_file function v5
 *
 */
#ifndef CPTCFG_I915_NO_DRM
#define BPM_VMA_SET_FILE_NOT_PRESENT
#endif

/*
 * ab22dd46b60 Backport "drm/i915: Change shrink ordering to use locking
 * around unbinding" and deps
 *
 */
#define BPM_MIGHT_ALLOC_NOT_PRESENT

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6) || \
		REDHAT_RELEASE_VERSION_IS_LEQ(8,3) || \
		SUSE_RELEASE_VERSION_IS_GEQ(1,15,2,0) || \
		LINUX_VERSION_IN_RANGE(5,4,0, 5,5,0))
/*
 * ab440b2c604b seqlock: Rename __seqprop() users
 */
#define BPM_SEQPROP_SEQUENCE_NOT_PRESENT
#endif

#if !(SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))

/* Need to check the need of panel_orientatio_quirks */
#define BPM_DRM_GET_PANEL_ORIENTATION_QUIRK_DONT_EXPORT
#endif

#if (REDHAT_RELEASE_VERSION_IS_GEQ(8,4) && REDHAT_RELEASE_VERSION_IS_LESS(8,5))
/*
 * f0c0c115fb81 mm: memcontrol: account pagetables per node
 */
#define BPM_MOD_LRUVEC_PAGE_STATE_NOT_EXPORTED
#endif

/*
 * f3ba3c710ac5 mm/highmem: Provide kmap_local*
 */
#define BPM_KMAP_LOCAL_NOT_PRESENT
#endif

#if LINUX_VERSION_IS_LESS(5,10,0)


#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,5))

/*
 * 4f6ec8602341e mm/vmalloc: separate put pages and flush VM flags
 *
 */
#define BPM_VM_MAP_PUT_PAGES_NOT_PRESENT

/*
 * Resolve issues of minmax.h
 */
#define BPM_LINUX_MINMAX_H_PRESENT

/*
 * 3e9a9e256b1e mm: add a vmap_pfn function
 *
 */
#define BPM_VMAP_PFN_NOT_PRESENT

/*
*48526a0f4ca2b4 genetlink: bring back per op policy
*/
#define BPM_GENL_OPS_POLICY_MEMBER_NOT_PRESENT

/*
 * 07da1223ec93 lib/scatterlist: Add support in dynamic allocation of SG table from pages
 */
#define BPM_SG_CHAIN_NOT_PRESENT

#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6) || \
	REDHAT_RELEASE_VERSION_IS_LEQ(8,3) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,2,0) || \
	LINUX_VERSION_IN_RANGE(5,4,0, 5,5,0))
/*
 * 8117ab508f9c476 seqlock: seqcount_LOCKNAME_t: Introduce PREEMPT_RT support
 *
 */
#define BPM_SEQCOUNT_SEQUENCE_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))

/*
 * b7b3c01b19159 mm/memremap_pages: support multiple ranges per invocation
 *
 */
#define BPM_PAGEMAP_RANGE_START_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,7))
/*
 * 7a9f50a05843 irq_work: Cleanup
 *
 */
#define BPM_IRQ_WORK_NODE_LLIST_NOT_PRESENT
#endif

/*
 * 8af2fa888eaf0e Show slab cache occupancy for debug
 */
#define BPM_KMEM_CACHE_SLABINFO_API_NOT_PRESENT

#if (LINUX_VERSION_IN_RANGE(4,19,249, 4,20,0) || \
                LINUX_VERSION_IN_RANGE(5,4,200, 5,5,0) || \
                LINUX_VERSION_IN_RANGE(5,10,119, 5,11,0) || \
                LINUX_VERSION_IN_RANGE(5,15,44, 5,16,0))
/*
 *0cc41e2c73f70 x86/tsc: Use fallback for random_get_entropy() instead of zero
 */
#define BPM_INCLUDE_CPUFEATURE_IN_TSC
#endif

#if !(LINUX_VERSION_IN_RANGE(5,4,103, 5,4,224) || LINUX_VERSION_IN_RANGE(4,19,179, 4,19,266))
/*
 * 48e2e013dc71602 drm/i915: Expose list of clients in sysfs
 *
 */
#ifndef CPTCFG_I915_NO_DRM
#define BPM_SYSFS_EMIT_NOT_PRESENT
#endif

#endif

/*
 * 1967f71267742 hwmon: (core) Add support for rated attributes
 */

#define POWER1_RATED_MAX_NOT_PRESENT

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))
/*
 * e130816164e include/linux/list.h: add a macro to test if entry is pointing to the head
 */
#define BPM_LIST_ENTRY_IS_HEAD_NOT_PRESENT
#endif

/*
 * aedcade6f4fa debugobjects: Allow debug_obj_descr to be const
 *
 */
#define BPM_DEBUG_OBJECT_ACTIVATE_NO_CONST_ARG

#endif /* LINUX_VERSION_IS_LESS(5,10,0) */


#if LINUX_VERSION_IS_LESS(5,9,11)
#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6) || \
	LINUX_VERSION_IN_RANGE(5,4,86, 5,5,0) || \
	   SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0) || \
		(SUSE_RELEASE_VERSION_IS_GEQ(1,15,2,0) && \
		 SUSE_LOCAL_VERSION_IS_GEQ(24,61)))
/*
 * dd8088d5a896 PM: runtime: Add pm_runtime_resume_and_get
 * to deal with usage counter
 */
#define BPM_PM_RUNTIME_RESUME_AND_GET_NOT_PRESENT
#endif

#endif

#if LINUX_VERSION_IN_RANGE(5,9,0, 5,11,0) && !(CUSTOM_KERN_3_RELEASE_VERSION_IS_GEQ(136,12,0))
/*
 * c47d5032ed30 mm: move lruvec stats update functions to vmstat.h
 */
#define BPM_MOD_LRUVEC_STATE_NOT_EXPORTED
#endif

#if LINUX_VERSION_IS_LESS(5,9,0)

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))

#define BPM_MIGRATE_VMA_PAGE_OWNER_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4))
/*
 * 267580db047ef428 seqlock: Unbreak lockdep
 */
#define BPM_SEQCOUNT_WW_MUTEX_INIT_NOT_PRESESNT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))

/* 8b700983de82f sched: Remove sched_set_*() return value */
#define BPM_SCHED_SET_FIFO_NOT_PRESENT
#endif
#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0) || \
	(SUSE_RELEASE_VERSION_IS_GEQ(1,15,2,0) && \
	SUSE_LOCAL_VERSION_IS_GEQ(24,24)))

/* 3022c6a1b4b7 driver-core: Introduce DEVICE_ATTR_ADMIN_{RO,RW} */
#define BPM_DEVICE_ATTR_ADMIN_RX_NOT_PRESENT
#endif
/*
 * 229f5879facf96e5 Defined PTR_ALIGN_DOWN() in kernel.h
 *
 */
#define BPM_PTR_ALIGN_DOWN_NOT_PRESENT

/*
 * 12cc923f1ccc tasklet: Introduce new initialization API
 *
 */
#define BPM_TASKLET_STRUCT_CALLBACK_NOT_PRESENT
#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,2))
/*
 * eedc4e5a142c
 * mm: memcg: factor out memcg- and lruvec-level changes out of __mod_lruvec_state()
 */
#define BPM_MOD_MEMCG_LRUVEC_STATE_NOT_PRESENT
#endif
#endif

#if LINUX_VERSION_IS_LESS(5,8,0)

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))

#if !(LINUX_VERSION_IS_GEQ(5,4,0)) 
/*
 * 709d6d73c7561 scatterlist: add generic wrappers for iterating over sgtable objects
 *
 */
#define BPM_FOR_EACH_SGTABLE_PAGE_NOT_PRESENT
/* d9d200bcebc1f6e dma-mapping: add generic helpers
 * for mapping sgtable objects
 */
#define BPM_DMA_MAP_UNMAP_SGTABLE_NOT_PRESENT
#endif

/*
 * 999a22890cb1 uaccess: Add user_read_access_begin/end and
 * user_write_access_begin/end
 *
 */
#define BPM_USER_WRITE_ACCESS_BEGIN_NOT_PRESENT

/* 3f50f132d8400e1 bpf: Verifier, do explicit ALU32 bounds tracking */
#define BPM_U32_MIN_NOT_PRESESNT

/* dc5bdb68b5b drm/fb-helper: Fix vt restore */
#define BPM_FB_ACTIVATE_KD_TEXT_NOT_PRESENT

/* e07515563d010d8b PM: sleep: core: Rename DPM_FLAG_NEVER_SKIP */
#define BPM_DPM_FLAG_NEVER_SKIP_RENAMED
#endif
#if !(LINUX_VERSION_IN_RANGE(5,4,207, 5,5,0) || \
		REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
			SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))
/* 9740ca4e95b43b mmap locking API: initial implementation as rwsem wrappers */
#define BPM_MMAP_WRITE_LOCK_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
       SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0) || \
	(SUSE_RELEASE_VERSION_IS_GEQ(1,15,2,0) && \
               SUSE_LOCAL_VERSION_IS_GEQ(24,43)))
/*
 * f5678e7f2ac3 kernel: better document the use_mm/unuse_mm API contract
 *
 */
#define BPM_KTHREAD_USE_MM_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))
/*3d2d827f5ca5e3  mm: move use_mm/unuse_mm from aio.c to mm */
#define BPM_KTHREAD_HEADER_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))
/*
 * f45ce9336ff0640 video/hdmi: Add Unpack only function for DRM infoframe
 *
 */
#define BPM_HDMI_DRM_INFOFRAME_UNPACK_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6))
/*
 * 479da1f538a2 backlight: Add backlight_device_get_by_name()
 */
#define BPM_BACKLIGHT_DEV_GET_BY_NAME_NOT_PRESENT
/*
 * 9807372 capabilities: Introduce CAP_PERFMON to kernel and user space
 *
 */
#define BPM_PERFMON_CAPABLE_NOT_PRESENT
#endif

/*
 * ca5999f mm: introduce include/linux/pgtable.h
 * 64fa30f Backport and fix intel-gtt split
 *
 */
#define BPM_ASM_PGTABLE_H_NOT_PRESENT

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,5))

/* 
 * 42fc541404f2 mmap locking API: add mmap_assert_locked() and mmap_assert_write_locked()
 */
#define BPM_MMAP_ASSERT_LOCKED_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4))

/*
 * 6058eaec816f mm: fold and remove lru_cache_add_anon() and lru_cache_add_file()
 */
#define BPM_LRU_CACHE_ADD_NOT_PRESENT
/*
 * 376a34efa4ee mm/gup: refactor and de-duplicate gup_fast() code
 */
#define BPM_FOLL_FAST_ONLY_NOT_PRESENT
#endif

#endif

#if LINUX_VERSION_IS_LESS(5,7,0)
#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,5))

/*
 * c111566bea7c PM: runtime: Add pm_runtime_get_if_active()
 */
#define BPM_PM_RUNTIME_GET_IF_ACTIVE_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,2,0) || \
	LINUX_VERSION_IN_RANGE(5,4,57, 5,5,0))
/*
 * c0842fbc1b18 random32: move the pseudo-random 32-bit
 * definitions to prandom.h
 */
#define BPM_PRANDOM_H_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))
/* 67b06ba01857 PM: QoS: Drop PM_QOS_CPU_DMA_LATENCY and rename
 * related functions
 */

#define BPM_CPU_LATENCY_QOS_NOT_PRESENT
#endif
/*
 * 132ccc0422814203ca64 INTEL_DII: drm/i915/spi: refcount spi object lifetime
 */
#define BPM_MTD_PART_NOT_PRESENT
#endif

#if LINUX_VERSION_IS_LESS(5,6,0)

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6))

/*
 * a392d26f32cdd87 include/bitmap.h: add new functions to documentation
 *
 */
#define BPM_BITMAP_CLEAR_REGION_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4))

/*
 * bf9e25ec1287 video: fbdev: make fbops member of struct fb_info a const pointer
 *
 */
#define BPM_PIN_USER_PAGES_FAST_NOT_PRESENT

/*
 * f1f6a7dd9b53 mm, tree-wide: rename put_user_page*() to unpin_user_page*()
 */
#define BPM_PIN_OR_UNPIN_USER_PAGE_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))

/*
 * b6ff753a0ca0d drm: constify fb ops across all drivers
 *
 */
#define BPM_CONST_STRUCT_FB_OPS_NOT_PRESENT

/* c72bed23b9e45ac pinctrl: Allow modules to
 * use pinctrl_[un]register_mappings
 */
#define BPM_PINCTRL_UNREGISTER_MAPPINGS_NOT_PRESENT

/* 
 * 28ca0d6d39ab list: introduce list_for_each_continue()
 */
#define BPM_LIST_FOR_EACH_CONTINUE_NOT_PRESENT
#endif


/*
 * e692b4021a2e4 lockdep: add might_lock_nested()
 *
 */
#define BPM_MIGHT_LOCK_NESTED_NOT_PRESENT

#endif

#if LINUX_VERSION_IS_LESS(5,5,0)
#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
	SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))

/*
 * a63fc6b75cca9 rcu: Upgrade rcu_swap_protected() to rcu_replace_pointer()
 *
 */
#define BPM_RCU_REPLACE_POINTER_NOT_PRESENT

/* c9c13ba428ef9 PCI: Add PCI_STD_NUM_BARS for the number of standard BARs */
#define BPM_PCI_STD_NUM_BARS_NOT_DEFINED

/* 
 * 0a8459693238a339 fbdev: drop res_id parameter from 
 * remove_conflicting_pci_framebuffers
 */
#define BPM_REMOVE_CONF_PCI_FB_ARG_NOT_PRESENT

/* 5facae4f354 locking/lockdep: Remove unused
 * @nested argument from lock_release()
 */
#define BPM_LOCKING_NESTED_ARG_NOT_PRESENT

/* 8c9312a925ad8 i2c: add helper to check if a client has a driver attached */
#define BPM_I2C_CLIENT_HAS_DRIVER_NOT_PRESENT

/*
 * fa83433c92e3 iommu: Add I/O ASID allocator
 */
#define BPM_IOASID_H_NOT_PRESENT
#endif

#if (REDHAT_RELEASE_VERSION_IS_GEQ(8,5) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))

/*
 * 99cb252f5e68d72  mm/mmu_notifier: add an interval tree notifier
 *
 */
#define BPM_HMM_RANGE_NOTIFIER_NOT_PRESENT
#endif

/*
 * 8c2a2b8c2ff68 nvmem: core: add nvmem_device_find
 *
 */
#define BPM_NVMEM_DEVICE_FIND_NOT_PRESENT
#endif

#if LINUX_VERSION_IS_LESS(5,4,0)
#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4))
/*
 * 4495dfd drivers: Introduce device lookup variants by device type
 */
#define BPM_FIND_BY_DEVICE_TYPE_NOT_AVAILABLE
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4) || \
	SUSE_RELEASE_VERSION_IS_GEQ(1,15,2,0))
/*
 * 8896dd968 compat_ioctl: add compat_ptr_ioctl()
 */
#define BPM_COMPAT_PTR_IOCTL_NOT_PRESENT

/*
 * 8973ea47901c driver core: platform: Introduce platform_get_irq_optional()
 */
#define BPM_PLATFORM_GET_IRQ_OPTIONAL_NOT_PRESENT

/*
 * 315cc066b8ae augmented rbtree: add new RB_DECLARE_CALLBACKS_MAX macro
 */
#define BPM_RB_DECLARE_CALLBACKS_MAX_NOT_PRESENT

/*
 * 2d15eb31b50 mm/gup: add make_dirty arg to put_user_pages_dirty_lock()
 */
#define BPM_PUT_USER_PAGES_DIRTY_LOCK_ARG_NOT_PRESENT

#endif

#if !(SUSE_RELEASE_VERSION_IS_GEQ(1,15,2,0) && \
	SUSE_LOCAL_VERSION_IS_GEQ(24,46))
/* 294f69e662d1 compiler_attributes.h:
 *Add 'fallthrough' pseudo keyword for switch/case use
 */
#define BPM_FALLTHROUGH_API_NOT_PRESENT
#endif

/*
 * 12c88d840b45 module: add support for symbol namespaces (jsc#SLE-10158).
 *
 */
#define BPM_MODULE_IMPORT_NS_NOT_PRESENT
#endif

#if LINUX_VERSION_IS_LESS(5,3,0)
#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,5))

/*
 * d2a8ebbf8192b kernel.h: split out container_of() and typeof_member() macros
 *
 */
#define BPM_TYPEOF_MEMBER_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4))

/*
 * 5213d7efc8ec2 i2c: acpi: export i2c_acpi_find_adapter_by_handle
 *
 */
#define BPM_I2C_ACPI_FIND_ADAPTER_BY_HANDLE_EXPORT_NOT_PRESENT

/*
 * 6471384af2a6 mm: security: introduce init_on_alloc=1 and init_on_free=1 boot options
 */
#define BPM_WANT_INIT_ON_ALLOC_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,3))

/* 31d6d5ce5340 vfs: Provide a mount_pseudo-replacement
 * for the new mount API
 */
#define BPM_PSEUDO_H_NOT_PRESENT

#endif
#endif

#if LINUX_VERSION_IS_LESS(5,2,0)
#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,4))

/* f3a09c92018a introduce fs_context methods */
#define BPM_INIT_FS_CONTEXT_NOT_PRESENT

/*
 * a49294eac27c7 Add wait_var_event_interruptible()
 *
 */
#define BPM_WAIT_VAR_EVENT_INTERRUPTIBLE_NOT_PRESENT

/*
 * aa30f47cf66 kobject: Add support for default attribute groups to kobj_type
 */
#define BPM_DEFAULT_GROUPS_NOT_PRESENT
#endif

#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,6))

/*
 * bf198b2b34bf mm/mmu_notifier: pass down vma and reasons why mmu notifier is happening
 */
#define BPM_MMU_NOTIFIER_RANGE_VMA_MEMBER_NOT_PRESENT
#endif


#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,3))

/*
 * 54d50897d544 linux/kernel.h: split *_MAX and *_MIN macros into <linux/limits.h>
 */
#define BPM_LIMITS_H_NOT_PRESENT

/*
 * 7159dbdae3 i2c: core: improve return value handling of
 * i2c_new_device and i2c_new_dummy
 */
#define BPM_I2C_NEW_CLIENT_DEVICE_NOT_PRESENT

/*
 * c43a113ca2c hwmon: Add convience macro to define simple static sensors
 */
#define BPM_HWMON_CHANNEL_INFO_NOT_PRESENT
#endif

#endif 

#if LINUX_VERSION_IS_LESS(5,0,0) && \
	!(REDHAT_RELEASE_VERSION_IS_GEQ(8,4))

/*
 * b33a02aadcc63 i2c: acpi: Move I2C bits from acpi.h to i2c.h
 *
 */
#define BPM_I2C_ACPI_GET_I2C_RESOURCE_NOT_PRESENT

/*
 * 72921427d46 string.h: Add str_has_prefix() helper function
 */
#define BPM_STR_HAS_PREFIX_NOT_PRESENT
/*
 * ca79b0c211af mm: convert totalram_pages and totalhigh_pages
 * variables to atomic
 */
#define BPM_TOTALRAM_PAGES_FUNC_NOT_PRESENT
#endif

#if LINUX_VERSION_IS_LESS(4,20,0)
#if !(REDHAT_RELEASE_VERSION_IS_GEQ(8,9))
/*
 * a3f8a30f3f00 Compiler Attributes: use feature
 * checks instead of version checks
 */
#define BPM_COMPILER_ATTRIBUTES_HEADER_NOT_PRESENT
#endif
#endif

#if LINUX_VERSION_IS_LESS(4,19,0)

/*
 * 14d32b2 Defined jiffies_delta_to_msecs() function
 *
 */
#define BPM_JIFFIES_DELTA_TO_MSECS_NOT_PRESENT
#endif

/*
 * REDHAT
 */
#if REDHAT_RELEASE_VERSION_IS_RANGE(8,4, 9,0)
#define BPM_RH_DRM_BACKPORT_MMU_NOTIFIER_WRAPPER
#ifdef BPM_RH_DRM_BACKPORT_MMU_NOTIFIER_WRAPPER
#if REDHAT_RELEASE_VERSION_IS_LEQ(8,5)
#define BPM_RH_DRM_BACKPORT_MMU_NOTIFIER_WRAPPER_1
#endif
#endif
#endif

#if (REDHAT_RELEASE_VERSION_IS_LESS(9,0) || CUSTOM_KERN_1_RELEASE_VERSION_IS_GEQ(8,6656))
/* TBD : Need to check further need of ATTR Macro */
#define BPM_DEVICE_ATTR_NOT_PRESENT
#endif

#if SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0)
#define BPM_DRM_GET_PANEL_ORIENTATION_QUIRK_RENAME
#endif

#if (REDHAT_RELEASE_VERSION_IS_RANGE(8,4, 9,0) || \
        SUSE_RELEASE_VERSION_IS_GEQ(1,15,3,0))

#define BPM_BP_MTD_MAGIC_NUMBER
#endif

/* Hack section */
#if SUSE_RELEASE_VERSION_IS_LESS(1,15,4,0)
/* aeef8b5089b7 x86/pat: Pass valid address to sanitize_phys()*/
#define BPM_ROUND_DOWN_IOMEM_RESOURCE_END
/*SLES 15sp3 is based on MFD, it doesn't support AUX bus and
 RC6 related changes are not present in mei. */
#define BPM_RC6_DISABLED
#endif

#if (SUSE_RELEASE_VERSION_IS_LESS(1,15,4,0) || \
	REDHAT_RELEASE_VERSION_IS_LEQ(8,3) || \
	LINUX_VERSION_IN_RANGE(5,4,0, 5,5,0))
/*
 * 8117ab508f9c476 seqlock: seqcount_LOCKNAME_t: Introduce PREEMPT_RT support
 *
 */
#define BPM_SEQCOUNT_MUTEX_INIT_NOT_PRESENT
#endif

#if (SUSE_RELEASE_VERSION_IS_LESS(1,15,3,0) || \
        REDHAT_RELEASE_VERSION_IS_LEQ(8,3) || \
	LINUX_VERSION_IN_RANGE(5,4,0, 5,5,0))
#define BPM_MMU_INTERVAL_NOTIFIER_NOTIFIER_NOT_PRESENT
#define BPM_DRM_MIPI_DSI_DISABLED
/* __kmalloc is not exported only in sp2 */
#define BPM_KMALLOC_TRACK_CALLER_NOT_EXPORTED

#endif

/*sp2 only section */
#if (SUSE_RELEASE_VERSION_IS_LESS(1,15,3,0))
/* Declaring traces are causing issue during macro expansion.
   Temporarily disable traces for SP2. */
#define BPM_DISABLE_TRACES
#endif

#if (REDHAT_RELEASE_VERSION_IS_LEQ(8,3))
#define BPM_MMU_NOTIFIER_EVENT_NOT_PRESENT
#define BPM_I915_MMU_OBJECT_NOT_PRESENT
#endif
/* upstream changes not landed in mainline kernel yet.
 *
 * c1a01f290103d drm: constify sysrq_key_op
 */
#define BPM_CONST_SYSRQ_KEY_OP_NOT_PRESENT

/* upstream changes not landed in mainline kernel yet.
 * 9299148acf5422 VFIO - SR-IOV VF migration
 */
#define BPM_VFIO_SR_IOV_VF_MIGRATION_NOT_PRESENT

/*
 * MISCELLANEOUS
 */

/* Align Header path between i915-include and drm-include */
#define BPM_HEADER_PATH_ALIGN

/* Add backport Macro for all the symbols of dma-buf. */
#ifndef CPTCFG_I915_NO_DRM
#define BPM_ADD_BACKPORT_MACRO_TO_DMA_BUF_SYMBOLS
#endif

/* Resolve issues of dma-buf and add to compat module */

#define BPM_DMA_BUF_MOVE_FOPS_TO_DENTRY_OPS

#define BPM_LOWMEM_FOR_DG1_NOT_SUPPORTED

#define BPM_INTEL_MEI_PXP_GSC_ASSUME_ALWAYS_ENABLED
#define BPM_TRACE_INCLUDE_PATH_NOT_PRESENT
#define BPM_ADD_DEBUG_PRINTS_BKPT_MOD
#define BPM_ADD_MODULE_VERSION_MACRO_IN_ALL_MOD

#if IS_ENABLED(CONFIG_AUXILIARY_BUS)
#define CPTCFG_INTEL_VSEC

/* 
 * Added macro for MEI to switch between <linux/mei_aux.h> and  
 * <linux/platform_device.h> depending on which one is available 
 */
#define BPM_MEI_AUX_BUS_AVAILABLE
#endif

#ifdef CPTCFG_I915_NO_DRM

/*
 * Add macro to disable DGLUT 24bit support for MTL+ onwards 
 * Introduced in DII_6514
 * a82ae9f6b7d716 Support 24 bit DGLUT for MTL+
 */
#define BPM_DGLUT_24BIT_MTL_NOT_SUPPORTED

#if LINUX_VERSION_IN_RANGE(6,8,12, 6,8,99)
#if PVE_RELEASE_VERSION_IS_GEQ(1)
/*
 * 5a507b7d2be15f
 *  drm/mst: Fix NULL pointer dereference at drm_dp_add_payload_part2
 */
#define BPM_DRM_DP_ADD_PAYLOAD_PART2_STATE_ARG_NOT_PRESENT
#endif

#if PVE_RELEASE_VERSION_IS_GEQ(5)
/*
 * c0ef3df8dbaef5
 *  PM: runtime: Simplify pm_runtime_get_if_active() usage
 */
#define BPM_PM_RUNTIME_GET_IF_ACTIVE_IGN_USAGE_COUNT_ARG_NOT_PRESENT
#endif
#endif

#if LINUX_VERSION_IS_LESS(6,8,0) && \
	!(LINUX_VERSION_IN_RANGE(6,5,13, 6,5,99) && PVE_RELEASE_VERSION_IS_GEQ(4))
/*
 * 7707dd6022593f
 *  drm/dp_mst: Fix fractional DSC bpp handling
 */
#define BPM_DRM_DP_CALC_PBN_MODE_DSC_PRESENT
#endif

#if LINUX_VERSION_IS_LESS(6,7,0)
/*
 * 7218779efc46 drm/edid: add drm_edid_is_digital()
 */
#define DRM_EDID_IS_DIGITAL_NOT_PRESENT

/*
 * 82b599ece3b8 drm/edid: parse source physical address
 */
#define DRM_DISPLAY_INFO_SOURCE_PHYSICAL_ADDRESS_NOT_PRESENT

/*
 * e2272bfb18ee70
 *  drm/dp: switch drm_dp_downstream_*() helpers to struct drm_edid
 */
#define BPM_DRM_DP_DOWNSTREAM_STRUCT_EDID

/*
 * fc93835bb0d7e2
 *  drm: Add HPD state to drm_connector_oob_hotplug_event()
 */
#define BPM_DRM_CONNECTOR_OOB_HOTPLUG_EVENT_STATUS_NOT_PRESENT

/*
 * 5aa1dfcdf0a429
 *  drm/mst: Refactor the flow for payload allocation/removement
 */
#define BPM_DRM_DP_REMOVE_PAYLOAD_AVAILABLE
#endif

#define BPM_DISABLE_DRM_DMABUF
/*
 * f58a435311672 drm/dp, drm/i915: Add support for VESA backlights using PWM for brightness control
 *
 */
#define DRM_EDP_BACKLIGHT_NOT_PRESENT
#define API_ARG_DRM_DRIVER_REMOVED
/*
 * Introduced in DII_5943
 * 00b5f7aad3d989: Post-migration driver recovery
 */
#define DRM_MM_FOR_EACH_NODE_IN_RANGE_SAFE_NOT_PRESENT
#define DRM_LUMINANCE_RANGE_INFO_NOT_PRESENT
#define BPM_EDID_HDMI_RGB444_DC_MODES_NOT_PRESENT
#define DP_LINK_TRAINING_CR_DELAY_PRESENT
#define MSO_PIXEL_OVERLAP_DISPLAY_NOT_PRESENT
#define BPM_DGLUT_24BIT_MTL_NOT_SUPPORTED
#define BPM_DRM_PAYLOAD_PART1_START_SLOT_NOT_PRESENT
#define DRM_DP_GET_ADJUST_NOT_PRESENT
#define DRM_EDP_BACKLIGHT_NOT_PRESENT
#if LINUX_VERSION_IS_LESS(6,4,0)
#define BPM_DRM_DP_DSC_SINK_SUPPORTS_FORMAT_NOT_PRESENT
#endif
#endif

#endif /* BP_LINUX_BACKPORT_MACRO_H */
