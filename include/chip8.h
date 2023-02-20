#pragma once

#include <stdint.h>
#include <stddef.h>
#include "configuration.h"

struct chip8 {
    uint8_t memory[CHIP_8_MEMORY_SIZE]; // 4K memory
    uint16_t stack[CHIP_8_STACK_SIZE];  // 16 levels of stack
    
    struct chip8registers {
        uint8_t V[CHIP_8_REGISTERS];    // 16 8-bit registers
        uint16_t I;                     // 16-bit register
        uint8_t delay_timer;            // 8-bit delay timer
        uint8_t sound_timer;            // 8-bit sound timer
        uint16_t PC;                    // 16-bit program counter (current instruction)
        uint8_t SP;                     // 8-bit stack pointer (points to topmost level of stack)
    } registers;
};

void chip8_memory_set(struct chip8 *chip8, uint32_t index, uint8_t val);
uint8_t chip8_memory_get(struct chip8 *chip8, uint32_t index);