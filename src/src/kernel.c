/*

kernel.c - Bare-metal Kernel Entry Point for MT6737
*/

#include <stdint.h>

/* Volatile register access helper /
#define REG32(addr) (((volatile uint32_t *)(addr)))

/*

MT6737 UART Registers (Base: 0x11002000 - UART0)

Note: Memory mapping depends on MMU state / physical mapping
/
#define UART0_BASE       0x11002000
#define UART_THR         (UART0_BASE + 0x00) / Transmit Holding Register /
#define UART_LSR         (UART0_BASE + 0x14) / Line Status Register /
#define UART_LSR_THRE    (1 << 5)            / Transmit Data Request */

/* Simple UART putc implementation for debug output /
void uart_putc(char c) {
/ Wait until THR is empty */
while (!(REG32(UART_LSR) & UART_LSR_THRE));
REG32(UART_THR) = c;
}

void uart_puts(const char *str) {
while (*str) {
if (*str == '\n') {
uart_putc('\r');
}
uart_putc(*str++);
}
}

/* Kernel Entry Point called from boot.s /
void kernel_main(void) {
/ Send early boot banner via UART */
uart_puts("\n====================================\n");
uart_puts("   MT6737 Bare-Metal OS Kernel      \n");
uart_puts("   Target: Ulefone Note 8P          \n");
uart_puts("====================================\n\n");

/* Main Kernel Loop */
while (1) {
    /* Idle loop */
    asm volatile("wfi");
}


}
