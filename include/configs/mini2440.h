/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <garyj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * Configuation settings for the SAMSUNG SMDK2410 board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* #define DEBUG  */ /* DEBUG open modified!!!!! */
/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_S3C24X0		/* This is a SAMSUNG S3C24x0-type SoC */
#define CONFIG_S3C2440		/* specifically a SAMSUNG S3C2440 SoC */ /* modified!!! */
#define CONFIG_MINI2440		/* on a SAMSUNG MINI2440 Board */ /* modified!!! */

#define CONFIG_SYS_TEXT_BASE	0x33000000

#define CONFIG_SYS_GENERIC_BOARD

#define CONFIG_SYS_ARM_CACHE_WRITETHROUGH

/* input clock of PLL (the SMDK2410 has 12MHz input clock) */
#define CONFIG_SYS_CLK_FREQ	12000000

#define CONFIG_CMDLINE_TAG	/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG

/* spl build ******************************************************************/
#ifdef CONFIG_SPL_BUILD

#define CONFIG_SPL_LDSCRIPT "board/$(SYS_VENDOR)/$(SYS_BOARD)/u-boot-spl.lds" /* arch/arm/cpu/u-boot-spl.lds(default) */
#define CONFIG_SPL_TEXT_BASE 0
/* #define CONFIG_SPL_BOARD_INIT */

#define CONFIG_SPL_LIBGENERIC_SUPPORT
/* #define CONFIG_SPL_LIBCOMMON_SUPPORT */
/* #define CONFIG_SPL_FRAMEWORK */
#define CONFIG_SPL_NAND_SUPPORT 
/* #define CONFIG_SPL_SERIAL_SUPPORT */
/* #define CONFIG_SPL_NAND_INIT */
#define CONFIG_SPL_NAND_SIMPLE 
#define CONFIG_SPL_NAND_DRIVERS

#define CONFIG_SYS_NAND_U_BOOT_OFFS 0x1800
#define CONFIG_SYS_NAND_U_BOOT_DST CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_NAND_U_BOOT_SIZE 0x40000
#define CONFIG_SYS_NAND_U_BOOT_START CONFIG_SYS_TEXT_BASE

#define CONFIG_SPL_NAND_SOFTECC 
#define CONFIG_SPL_NAND_ECC
#define CONFIG_NAND_SPL
/* #define CONFIG_S3C2410_NAND_HWECC */

#define CONFIG_SYS_NAND_5_ADDR_CYCLE 
#define CONFIG_SYS_NAND_PAGE_COUNT       (CONFIG_SYS_NAND_BLOCK_SIZE / CONFIG_SYS_NAND_PAGE_SIZE)
#define CONFIG_SYS_NAND_PAGE_SIZE 2048
#define CONFIG_SYS_NAND_OOBSIZE 64
#define CONFIG_SYS_NAND_BLOCK_SIZE (128*1024)
#define CONFIG_SYS_NAND_BAD_BLOCK_POS  NAND_LARGE_BADBLOCK_POS

#ifdef CONFIG_SPL_NAND_SOFTECC
#define CONFIG_SYS_NAND_ECCSIZE 256
#define CONFIG_SYS_NAND_ECCBYTES 3 /* 256bytes -> 3bytes ecc */
#define CONFIG_SYS_NAND_ECCPOS   {\
                   40, 41, 42, 43, 44, 45, 46, 47,\
                   48, 49, 50, 51, 52, 53, 54, 55,\
                   56, 57, 58, 59, 60, 61, 62, 63}/* soft ecc config , ECCBYTES & ECCPOS can be found in nand_base.c */
#else 
#define CONFIG_SYS_NAND_ECCSIZE 2048
#define CONFIG_SYS_NAND_ECCBYTES 4
#define CONFIG_SYS_NAND_ECCPOS {60,61,62,63}
#endif


#endif /*end #ifdef CONFIG_SPL_BUILD */

/*
 * Hardware drivers
 */

#define CONFIG_DRIVER_DM9000
#define CONFIG_DM9000_BASE 0x20000300	/* nGCS4 */
#define DM9000_DATA	(CONFIG_DM9000_BASE+4)
#define DM9000_IO	CONFIG_DM9000_BASE
#define CONFIG_DM9000_NO_SROM
/* #define CONFIG_DM9000_DEBUG */



/*
 * select serial console configuration
 */
#define CONFIG_S3C24X0_SERIAL
#define CONFIG_SERIAL1		1	/* we use SERIAL 1 on SMDK2410 */

/************************************************************
 * USB support (currently only works with D-cache off)
 ************************************************************/
/*
#define CONFIG_USB_OHCI
#define CONFIG_USB_OHCI_S3C24XX
#define CONFIG_USB_KEYBOARD
#define CONFIG_USB_STORAGE
#define CONFIG_DOS_PARTITION
*/

/************************************************************
 * RTC
 ************************************************************/
#define CONFIG_RTC_S3C24X0


#define CONFIG_BAUDRATE		115200

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME

/*
 * Command line configuration.
 */
/* #define CONFIG_CMD_BSP */
/* #define CONFIG_CMD_CACHE */
/* #define CONFIG_CMD_DATE */
#define CONFIG_CMD_DHCP
/* #define CONFIG_CMD_ELF */
#define CONFIG_CMD_NAND
#define CONFIG_CMD_PING
#define CONFIG_CMD_REGINFO
/* #define CONFIG_CMD_USB */

#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_CMDLINE_EDITING

/* autoboot */
#define CONFIG_BOOTDELAY	5
#define CONFIG_BOOT_RETRY_TIME	-1
#define CONFIG_RESET_TO_RETRY
#define CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_BOOTCOMMAND "nand read 31000000 60000 300000 ;bootm 31000000"
#define CONFIG_BOOTARGS "console=ttySAC0,115200  root=/dev/mtdblock3 init=/linuxrc noinitrd"


#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_IPADDR		10.0.0.110
#define CONFIG_SERVERIP		10.0.0.1
#define CONFIG_ETHADDR		"da:15:db:01:01:01"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"ethaddr="	CONFIG_ETHADDR			"\0"


#if defined(CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200	/* speed to run kgdb serial port */
#endif

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_CBSIZE	256
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE	(CONFIG_SYS_CBSIZE + \
				sizeof(CONFIG_SYS_PROMPT)+16)
#define CONFIG_SYS_MAXARGS	16
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE

#define CONFIG_DISPLAY_CPUINFO				/* Display cpu info */

#define CONFIG_SYS_MEMTEST_START	0x30000000	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0x33F00000	/* 63 MB in DRAM */

#define CONFIG_SYS_LOAD_ADDR		0x30800000

/* support additional compression methods */
/* #define CONFIG_BZIP2 */
/* #define CONFIG_LZO */
/* #define CONFIG_LZMA */

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1          /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1		0x30000000 /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	0x04000000 /* 64 MB */

#define PHYS_FLASH_1		0x00000000 /* Flash Bank #0 */

#define CONFIG_SYS_FLASH_BASE	PHYS_FLASH_1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_FLASH_CFI_LEGACY
#define CONFIG_SYS_FLASH_LEGACY_512Kx16
#define CONFIG_FLASH_SHOW_PROGRESS	45

#define CONFIG_SYS_MAX_FLASH_BANKS	1
#define CONFIG_SYS_FLASH_BANKS_LIST     { CONFIG_SYS_FLASH_BASE }
#define CONFIG_SYS_MAX_FLASH_SECT	(35) 

#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_SIZE	0X20000 /* 128Kbytes - 1 blocks */
#define CONFIG_ENV_OFFSET 0x40000 /* block-aligned */
/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

/*
 * Size of malloc() pool
 * BZIP2 / LZO / LZMA need a lot of RAM
 */
#define CONFIG_SYS_MALLOC_LEN	(4 * 1024 * 1024)

#define CONFIG_SYS_MONITOR_LEN	(448 * 1024)
#define CONFIG_SYS_MONITOR_BASE	CONFIG_SYS_FLASH_BASE

/*
 * NAND configuration
 */
#ifdef CONFIG_CMD_NAND
#define CONFIG_NAND_S3C2410
#define CONFIG_SYS_S3C2410_NAND_HWECC
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0x4E000000
#endif

/*
 * File system
 */
/* #define CONFIG_CMD_FAT */
/* #define CONFIG_CMD_EXT2 */
/* #define CONFIG_CMD_UBI */
/* #define CONFIG_CMD_UBIFS */
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
/* #define CONFIG_YAFFS2 */
/* #define CONFIG_RBTREE */


/* additions for new relocation code, must be added to all boards */
#define CONFIG_SYS_SDRAM_BASE	PHYS_SDRAM_1
#define CONFIG_SYS_INIT_SP_ADDR	(CONFIG_SYS_SDRAM_BASE + 0x1000 - \
				GENERATED_GBL_DATA_SIZE)

#define CONFIG_BOARD_EARLY_INIT_F

#endif /* __CONFIG_H */
