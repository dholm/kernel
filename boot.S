global loader
extern main

;; Multiboot header
MULTIBOOT_PAGE_ALIGN  	equ 1 << 0
MULTIBOOT_MEMORY_INFO 	equ 1 << 1
MULTIBOOT_HEADER_MAGIC 	equ 0x1BADB002
MULTIBOOT_HEADER_FLAGS 	equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO
MULTIBOOT_CHECKSUM     	equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

section .text
align 4
	dd MULTIBOOT_HEADER_MAGIC
	dd MULTIBOOT_HEADER_FLAGS
	dd MULTIBOOT_CHECKSUM

KERNEL_STACK_SIZE equ 0x4000

loader:
	;; Load kernel stack
	mov esp, stack + KERNEL_STACK_SIZE
	;; Load multiboot magic number
	push eax
	;; Load multiboot info structure
	push ebx
	call main

	cli
.hang:
	hlt
	jmp .hang

section .bss
stack:
	resb KERNEL_STACK_SIZE
