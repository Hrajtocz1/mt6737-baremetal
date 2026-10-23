/*
 * boot.s - Startup code for MT6737 (ARMv7-A Cortex-A53)
 */

.syntax unified
.cpu cortex-a53
.fpu neon-vfpv4
.arch armv7-a

.global _start
.section .text.boot

_start:
    /* Disable interrupts (IRQ & FIQ) */
    cpsid if

    /* Read CPU ID (MPIDR) to ensure we only run on Core 0 */
    mrc p15, 0, r0, c0, c0, 5
    ands r0, r0, #0xFF
    beq core0_init

    /* Secondary cores go into infinite WFI loop for now */
secondary_loop:
    wfi
    b secondary_loop

core0_init:
    /* Setup stack pointer for Core 0 */
    ldr sp, =_stack_top

    /* Jump to C kernel main entry */
    bl kernel_main

    /* Hang if kernel returns */
halt:
    wfe
    b halt
