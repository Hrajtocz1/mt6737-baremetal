# MT6737 Bare-Metal & Custom Kernel Experiments

Experimental low-level kernel bring-up project for the **MediaTek MT6737M** SoC, targeted at the **Ulefone Note 8P**.

## 📱 Hardware Target

| Component | Specification |
| :--- | :--- |
| **Device** | Ulefone Note 8P |
| **SoC** | MediaTek MT6737M |
| **CPU** | 4× ARM Cortex-A53 @ 1.25 GHz |
| **Architecture** | ARMv7-A (32-bit execution mode) |
| **GPU** | ARM Mali-T720 MP1 |
| **RAM** | 2 GB LPDDR3 |
| **Storage** | 16 GB eMMC 5.0 (MSDC0) |

## 📡 HW Telemetry & Interrupt Mapping (Extracted via ADB)

Derived from live system metrics (`/proc/interrupts`):

* **ARM Generic Timer (`arch_timer`):** IRQ 27
* **MTK I2C Controllers (`mt-i2c`):** IRQ 116–119
* **UART Controller (`mtk-uart`):** IRQ 123
* **eMMC / SD Controller (`mtk-msdc`):** IRQ 111–112
* **Display System (`DISPSYS`):** IRQ 218, 225, 227, 229, 231, 232, 236
* **Mali GPU (`13040000.MALI`):** IRQ 242–244
* **Touch Panel EINT:** IRQ 291

## 🎯 Project Roadmap

- [x] Extract hardware properties and IRQ layout via ADB
- [ ] Implement initial low-level boot code (`boot.s`) & Linker script
- [ ] Setup UART / Serial console logging output
- [ ] Memory Management Unit (MMU) & Page Table Initialization
- [ ] Display Framebuffer Bring-up
