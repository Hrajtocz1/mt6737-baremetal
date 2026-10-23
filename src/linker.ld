ENTRY(_start)

SECTIONS
{
    /* Standard MTK RAM base offset for custom payloads */
    . = 0x40008000;

    .text : {
        *(.text.boot)
        *(.text*)
    }

    .rodata : {
        *(.rodata*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        __bss_start = .;
        *(.bss*)
        *(COMMON)
        __bss_end = .;
    }

    /* Allocate 16KB stack */
    . = ALIGN(8);
    . = . + 0x4000;
    _stack_top = .;
}
