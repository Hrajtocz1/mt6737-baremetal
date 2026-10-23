#
# Makefile for MT6737 Bare-Metal Kernel
#

CROSS_COMPILE ?= arm-none-eabi-
CC            = $(CROSS_COMPILE)gcc
LD            = $(CROSS_COMPILE)ld
OBJCOPY       = $(CROSS_COMPILE)objcopy

CFLAGS        = -Wall -Wextra -O2 -ffreestanding -nostdlib -mcpu=cortex-a53 -marm
LDFLAGS       = -T src/linker.ld

BUILD_DIR     = build
SRC_DIR       = src

OBJECTS       = $(BUILD_DIR)/boot.o \
                $(BUILD_DIR)/kernel.o

TARGET        = $(BUILD_DIR)/kernel.elf
BIN_TARGET    = $(BUILD_DIR)/kernel.bin

all: $(BIN_TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/boot.o: $(SRC_DIR)/boot.s | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/kernel.o: $(SRC_DIR)/kernel.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

$(BIN_TARGET): $(TARGET)
	$(OBJCOPY) -O binary $< $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
