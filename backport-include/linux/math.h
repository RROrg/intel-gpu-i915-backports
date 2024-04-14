/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _BACKPORT_LINUX_MATH_H
#define _BACKPORT_LINUX_MATH_H

#ifdef BPM_MATH_H_NOT_PRESENT
#include <linux/kernel.h>
#else
#include_next <linux/math.h>
#endif

#if LINUX_VERSION_IS_LESS(6,6,0)
/**
 * abs_diff - return absolute value of the difference between the arguments
 * @a: the first argument
 * @b: the second argument
 *
 * @a and @b have to be of the same type. With this restriction we compare
 * signed to signed and unsigned to unsigned. The result is the subtraction
 * the smaller of the two from the bigger, hence result is always a positive
 * value.
 *
 * Return: an absolute value of the difference between the @a and @b.
 */
#define abs_diff(a, b) ({			\
	typeof(a) __a = (a);			\
	typeof(b) __b = (b);			\
	(void)(&__a == &__b);			\
	__a > __b ? (__a - __b) : (__b - __a);	\
})
#endif

#endif /* _LINUX_MATH_H */
                              
