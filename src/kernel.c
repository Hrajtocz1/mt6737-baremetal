/*
 * kernel.c - Bare-metal C entry point for MT6737
 */

#include <stdint.h>

/* MediaTek MT6737 UART0 Base Address */
#define MT6737_UART0_BASE 0x11002000

#define UART_THR          (*(volatile uint32_t *)(MT6737_UART0_BASE + 0x00))
#define UART_LSR          (*(volatile uint32_t *)(MT6737_UART0_BASE + 0x14))
#define UART_LSR_THRE     (1 << 5)

/**
 * Send a single character over UART0
 */
void uart_putc(char c) {
    while (!(UART_LSR & UART_LSR_THRE));
    UART_THR = c;
}

/**
 * Send a null-terminated string over UART0
 */
void uart_puts(const char *str) {
    while (*str) {
        if (*str == '\n') {
            uart_putc('\r');
        }
        uart_putc(*str++);
    }
}

/**
 * Main kernel entry point called from boot.s
 */
void kernel_main(void) {
    uart_puts("\n========================================\n");
    uart_puts("   TurusOS / MT6737 Bare-Metal Kernel   \n");
    uart_puts("   Running on ARM Cortex-A53 (ARMv7-A)  \n");
    uart_puts("========================================\n\n");

    /* Infinite loop / Low-power state */
    while (1) {
        __asm__ volatile("wfi");
    }
}
