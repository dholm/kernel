#include "multiboot.h"

void kmain(const multiboot_info_t* multi_boot_info, unsigned int multiboot_magic)
{
     if (MULTIBOOT_BOOTLOADER_MAGIC != multiboot_magic)
     {
	  return;
     }

     (void) multi_boot_info;
}
