#include <common.h>
#include <spl.h>
#include <nand.h>
#include <linux/compiler.h>
#include <image.h>
#include <asm/u-boot.h>
#include <asm/io.h>
#include <linux/mtd/nand_ecc.h>
#include <asm/arch/s3c24x0_cpu.h>

u32 spl_boot_device(void)
{
	return BOOT_DEVICE_NAND;
}


void spl_board_init(void)
{
	preloader_console_init();	
}

/*
*refer:
* arch/arm/lib/spl.c
* driver/mtd/nand/nand_spl_simple.c
* common/spl/spl.c
* mini2440.c
*/
void board_early_init_f_spl(void); /* defined in  mini2440.c */
void board_init_f(ulong dummy)                                                              
{        
	/* copy from arch/arm/lib/spl.c - clear the BSS (important)*/
        memset(__bss_start, 0, __bss_end - __bss_start);

	board_early_init_f_spl();

	/* copy from nand_spl_simple.c - init the nand flash contoler, load the u-boot to SDRAM */
        nand_init();                                                                        
        nand_spl_load_image(CONFIG_SYS_NAND_U_BOOT_OFFS,0x40000, (void *)(unsigned long)CONFIG_SYS_NAND_U_BOOT_DST);

	/* debug - light the led */
	(*((volatile unsigned int *)0x56000014)) &= ~(1<<5);

	/* go to the u-boot */
        unsigned long * uboot_addr = (void*)(unsigned long)(CONFIG_SYS_NAND_U_BOOT_START);  
        ((void (*)(void))uboot_addr)();
} 

