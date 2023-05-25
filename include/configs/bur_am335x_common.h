/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * bur_am335x_common.h
 *
 * common parts used by B&R AM335x based boards
 *
 * Copyright (C) 2016 Hannes Schmelzer <oe5hpm@oevsv.at> -
 * Bernecker & Rainer Industrieelektronik GmbH - http://www.br-automation.com
 */

#ifndef __BUR_AM335X_COMMON_H__
#define __BUR_AM335X_COMMON_H__
/* ------------------------------------------------------------------------- */

/* legacy #defines for non DM bur-board */
#ifndef CONFIG_DM
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		(48000000)
#define CONFIG_SYS_NS16550_COM1		0x44e09000

#endif /* CONFIG_DM */

#define CONFIG_MAX_RAM_BANK_SIZE	(1024 << 20)	/* 1GB */

/* Timer information */
#define CONFIG_SYS_TIMERBASE		0x48040000	/* Use Timer2 */

#include <asm/arch/omap.h>

/*
 * SPL related defines.  The Public RAM memory map the ROM defines the
 * area between 0x402F0400 and 0x4030B800 as a download area and
 * 0x4030B800 to 0x4030CE00 as a public stack area.  The ROM also
 * supports X-MODEM loading via UART, and we leverage this and then use
 * Y-MODEM to load u-boot.img, when booted over UART.  We must also include
 * the scratch space that U-Boot uses in SRAM.
 */

/*
 * Since SPL did pll and ddr initialization for us,
 * we don't need to do it twice.
 */
/*
 * ----------------------------------------------------------------------------
 * DDR information.  We say (for simplicity) that we have 1 bank,
 * always, even when we have more.  We always start at 0x80000000,
 * and we place the initial stack pointer in our SRAM.
 */
#define CONFIG_SYS_SDRAM_BASE		0x80000000

/*
 * Our platforms make use of SPL to initalize the hardware (primarily
 * memory) enough for full U-Boot to be loaded.  We also support Falcon
 * Mode so that the Linux kernel can be booted directly from SPL
 * instead, if desired.  We make use of the general SPL framework found
 * under common/spl/.  Given our generally common memory map, we set a
 * number of related defaults and sizes here.
 */
/*
 * Place the image at the start of the ROM defined image space.
 * We limit our size to the ROM-defined downloaded image area, and use the
 * rest of the space for stack.  We load U-Boot itself into memory at
 * 0x80800000 for legacy reasons (to not conflict with older SPLs).  We
 * have our BSS be placed 1MiB after this, to allow for the default
 * Linux kernel address of 0x80008000 to work, in the Falcon Mode case.
 * We have the SPL malloc pool at the end of the BSS area.
 *
 * ----------------------------------------------------------------------------
 */

/* General parts of the framework, required. */

#endif	/* ! __BUR_AM335X_COMMON_H__ */
