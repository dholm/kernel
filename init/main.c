#include <stdio.h>
#include <stddef.h>
#include <serial.h>
#include <command.h>

#include "multiboot.h"

static void command_loop(void)
{
    struct Command apa = {{NULL, NULL}, "apa", 1};
    struct Command banan = {{NULL, NULL}, "banan", 2};
    struct Command cykel = {{NULL, NULL}, "cykel", 3};

    command_add(&apa);
    command_add(&banan);
    command_add(&cykel);

    for (;;) {
        static char read_buffer[1024] = {0, };
        static int buffer_position = 0;

        if (serial_data_buffered()) {
            char c = serial_read8();
            switch (c) {
                 case 0x0d:
                 {
                      read_buffer[buffer_position++] = '\0';
                      printf("\n");
                      struct Command* command = NULL;
                      if ((command = command_find(read_buffer)) != NULL) {
                           printf("Executing %d\n", command->x);
                      }
                      buffer_position = 0;
                      break;
                 }

                 default:
                      serial_write8(c);
                      read_buffer[buffer_position++] = c;
                      break;
            }
        }
    }
}

void kmain(const multiboot_info_t* multi_boot_info, unsigned int multiboot_magic)
{
    if (MULTIBOOT_BOOTLOADER_MAGIC != multiboot_magic) {
        return;
    }
    (void) multi_boot_info;

    serial_init();
    printf("Welcome to the future!\n");
    command_init();
    command_loop();
}
