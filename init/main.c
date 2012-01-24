#include <serial.h>
#include "multiboot.h"

static void welcome_message(void)
{
     const char welcome[] = "Welcome to the future!";
     serial_write_buffer((const unsigned char*) &welcome[0], sizeof(welcome));
}

void kmain(const multiboot_info_t* multi_boot_info, unsigned int multiboot_magic)
{
     if (MULTIBOOT_BOOTLOADER_MAGIC != multiboot_magic)
     {
	  return;
     }
     (void) multi_boot_info;

     serial_init();
     welcome_message();
}
