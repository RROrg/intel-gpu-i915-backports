# SPDX-License-Identifier: GPL-2.0-only
#
# Makefile for the i2c algorithms
#
ifneq ($(CONFIG_I2C_ALGOBIT),y)
obj-$(CPTCFG_I2C_ALGOBIT)	+= i2c-algo-bit.o
endif
ifneq ($(CONFIG_I2C_ALGOPCF),y)
obj-$(CPTCFG_I2C_ALGOPCF)	+= i2c-algo-pcf.o
endif
ifneq ($(CONFIG_I2C_ALGOPCA),y)
obj-$(CPTCFG_I2C_ALGOPCA)	+= i2c-algo-pca.o
endif
ccflags-$(CPTCFG_I2C_DEBUG_ALGO) := -DDEBUG
