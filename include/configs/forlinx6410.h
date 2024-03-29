#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_S3C6410		1	/* in a SAMSUNG S3C6410 SoC     */
#define CONFIG_S3C64XX		1	/* in a SAMSUNG S3C64XX Family  */
#define CONFIG_FORLINX6410	1

#define CONFIG_PERIPORT_REMAP
#define CONFIG_PERIPORT_BASE	0x70000000
#define CONFIG_PERIPORT_SIZE	0x13

#define CONFIG_SYS_IRAM_BASE    0x0c000000  /* Internal SRAM base address */
#define CONFIG_SYS_IRAM_SIZE    0x2000      /* 8 KB of internal SRAM memory */
#define CONFIG_SYS_IRAM_END     (CONFIG_SYS_IRAM_BASE + CONFIG_SYS_IRAM_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR (CONFIG_SYS_IRAM_END - GENERATED_GBL_DATA_SIZE)

#define CONFIG_SYS_SDRAM_BASE	0x50000000

/* input clock of PLL: FORLINX6410 has 12MHz crystal */
#define CONFIG_SYS_CLK_FREQ	12000000

#define CONFIG_NAND_SPL

#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG

/*
 * Architecture magic and machine type
 */
/*
 * reference linux kernel/include/asm/mach-types.h
 * 1004 is generic S3C6400
 */
#define CONFIG_MACH_TYPE		1004 /*S3C6400*/

#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 1024 * 1024)

/*
 * Hardware drivers
 */
#define CONFIG_DRIVER_DM9000		1
/*
 * CSN1 for CS#
 * ADDR2 for CMD
 * so any address between 0x18000000 and 1FFFFFFF is OK
 */
#define CONFIG_DM9000_BASE		0x18000000
#define DM9000_IO			CONFIG_DM9000_BASE
#define DM9000_DATA			(CONFIG_DM9000_BASE+4)

/*
 * select serial console configuration
 */
#define CONFIG_SERIAL1          1	/* we use SERIAL 1 on FORLINX6410 */

#define CONFIG_SYS_HUSH_PARSER			/* use "hush" command parser	*/
#ifdef CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#endif

#define CONFIG_CMDLINE_EDITING

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE		115200

/***********************************************************
 * Command definition
 ***********************************************************/
#include <config_cmd_default.h>

#define CONFIG_CMD_CACHE
#define CONFIG_CMD_REGINFO
#define CONFIG_CMD_LOADS
#define CONFIG_CMD_LOADB
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_NAND
#define CONFIG_CMD_PING
#define CONFIG_CMD_ELF
#define CONFIG_CMD_FAT
#define CONFIG_CMD_EXT2

#define CONFIG_BOOTDELAY	3

#define CONFIG_ZERO_BOOTDELAY_CHECK

#if (CONFIG_COMMANDS & CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200	/* speed to run kgdb serial port */
#define CONFIG_KGDB_SER_INDEX	1	/* which serial port to use	 */
#endif

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP				/* undef to save memory	      */
#define CONFIG_SYS_PROMPT		"FORLINX6410 # "	/* Monitor Command Prompt     */
#define CONFIG_SYS_CBSIZE		256		/* Console I/O Buffer Size    */
#define CONFIG_SYS_PBSIZE		384		/* Print Buffer Size          */
#define CONFIG_SYS_MAXARGS		16		/* max number of command args */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size  */

#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE	/* memtest works on	      */
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x7e00000) /* 126MB in DRAM */

#define CONFIG_SYS_LOAD_ADDR		CONFIG_SYS_SDRAM_BASE	/* default load address	*/

#define CONFIG_SYS_HZ			1000

/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

#define CONFIG_SYS_NO_FLASH
#undef CONFIG_CMD_BOOTM
/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	0x40000		/* regular stack 256KB */

#define CONFIG_ACLK_667

#define CONFIG_NR_DRAM_BANKS	1
#define PHYS_SDRAM_1		CONFIG_SYS_SDRAM_BASE	/* SDRAM Bank #1	*/
#define PHYS_SDRAM_1_SIZE	0x10000000	/* 256 MB in Bank #1	*/

#define CONFIG_SYS_FLASH_BASE		0x10000000
#define CONFIG_SYS_MONITOR_BASE	0x00000000

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* max number of memory banks	*/
/* AM29LV160B has 35 sectors, AM29LV800B - 19 */
#define CONFIG_SYS_MAX_FLASH_SECT	40

/* timeout values are in ticks */
#define CONFIG_SYS_FLASH_ERASE_TOUT	(5 * CONFIG_SYS_HZ) /* Timeout for Flash Erase	*/
#define CONFIG_SYS_FLASH_WRITE_TOUT	(5 * CONFIG_SYS_HZ) /* Timeout for Flash Write	*/

#define CONFIG_ENV_SIZE		0x4000	/* Total Size of Environment Sector */

/*
 * FORLINX6410 board specific data
 */

#define CONFIG_IDENT_STRING	" for FORLINX6410"

/* base address for uboot */
#define CONFIG_SYS_PHY_UBOOT_BASE	(CONFIG_SYS_SDRAM_BASE + 0x07e00000)
/* total memory available to uboot */
#define CONFIG_SYS_UBOOT_SIZE		(1024 * 1024)

/* Put environment copies after the end of U-Boot owned RAM */
#define CONFIG_NAND_ENV_DST	(CONFIG_SYS_UBOOT_BASE + CONFIG_SYS_UBOOT_SIZE)

#ifdef CONFIG_ENABLE_MMU
#define CONFIG_SYS_MAPPED_RAM_BASE	0xc0000000
#define CONFIG_BOOTCOMMAND	"nand read 0xc0018000 0x60000 0x1c0000;" \
				"bootm 0xc0018000"
#else
#define CONFIG_SYS_MAPPED_RAM_BASE	CONFIG_SYS_SDRAM_BASE
#define CONFIG_BOOTCOMMAND	"nand read 0x50018000 0x60000 0x1c0000;" \
				"bootm 0x50018000"
#endif

/* NAND U-Boot load and start address */
#define CONFIG_SYS_UBOOT_BASE		(CONFIG_SYS_MAPPED_RAM_BASE + 0x07e00000)

#define CONFIG_ENV_OFFSET		0x0040000

/* NAND configuration */
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0x70200010
#define CONFIG_SYS_S3C_NAND_HWECC

#define CONFIG_SYS_NAND_SKIP_BAD_DOT_I	1  /* ".i" read skips bad blocks	      */
#define CONFIG_SYS_NAND_WP		1
#define CONFIG_SYS_NAND_YAFFS_WRITE	1  /* support yaffs write		      */
#define CONFIG_SYS_NAND_BBT_2NDPAGE	1  /* bad-block markers in 1st and 2nd pages  */

#define CONFIG_SYS_NAND_U_BOOT_DST	CONFIG_SYS_PHY_UBOOT_BASE	/* NUB load-addr      */
#define CONFIG_SYS_NAND_U_BOOT_START	CONFIG_SYS_NAND_U_BOOT_DST	/* NUB start-addr     */

#define CONFIG_SYS_NAND_U_BOOT_OFFS	(4 * 1024)	/* Offset to RAM U-Boot image */
#define CONFIG_SYS_NAND_U_BOOT_SIZE	(252 * 1024)	/* Size of RAM U-Boot image   */

/* NAND chip page size		*/
#define CONFIG_SYS_NAND_PAGE_SIZE	2048
/* NAND chip page per block count  */
#define CONFIG_SYS_NAND_PAGE_COUNT	128
/* NAND chip block size		*/
#define CONFIG_SYS_NAND_BLOCK_SIZE	(CONFIG_SYS_NAND_PAGE_SIZE * CONFIG_SYS_NAND_PAGE_COUNT)
/* Location of the bad-block label */
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	0
/* Extra address cycle for > 128MiB */
#define CONFIG_SYS_NAND_5_ADDR_CYCLE

/* Size of the block protected by one OOB (Spare Area in Samsung terminology) */
#define CONFIG_SYS_NAND_ECCSIZE	CONFIG_SYS_NAND_PAGE_SIZE
/* Number of ECC bytes per OOB - S3C6400 calculates 4 bytes ECC in 1-bit mode */
#define CONFIG_SYS_NAND_ECCBYTES	4
/* Size of a single OOB region */
#define CONFIG_SYS_NAND_OOBSIZE	64
/* ECC byte positions */
#define CONFIG_SYS_NAND_ECCPOS		{40, 41, 42, 43, 44, 45, 46, 47, \
				 48, 49, 50, 51, 52, 53, 54, 55, \
				 56, 57, 58, 59, 60, 61, 62, 63}

/* Boot configuration (define only one of next 3) */
#define CONFIG_BOOT_NAND
/* None of these are currently implemented. Left from the original Samsung
 * version for reference
#define CONFIG_BOOT_NOR
#define CONFIG_BOOT_MOVINAND
#define CONFIG_BOOT_ONENAND
*/

#define CONFIG_NAND
#define CONFIG_NAND_S3C64XX
/* Unimplemented or unsupported. See comment above.
#define CONFIG_ONENAND
#define CONFIG_MOVINAND
*/

/* Settings as above boot configuration */
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_BOOTARGS		"console=ttySAC,115200"

#if !defined(CONFIG_ENABLE_MMU)
#define CONFIG_CMD_USB			1
#define CONFIG_USB_S3C64XX
#define CONFIG_USB_OHCI_NEW		1
#define CONFIG_SYS_USB_OHCI_REGS_BASE		0x74300000
#define CONFIG_SYS_USB_OHCI_SLOT_NAME		"s3c6410"
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	3
#define CONFIG_SYS_USB_OHCI_CPU_INIT		1

#define CONFIG_USB_STORAGE	1
#endif
#define CONFIG_DOS_PARTITION	1

#if defined(CONFIG_USB_OHCI_NEW) && defined(CONFIG_ENABLE_MMU)
# error "usb_ohci.c is currently broken with MMU enabled."
#endif

#endif	/* __CONFIG_H */
