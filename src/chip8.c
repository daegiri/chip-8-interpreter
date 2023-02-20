#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

#include "chip8.h"
#include "configuration.h"

static inline void is_valid_index(uint32_t index) {
    assert(index >= 0 || index < CHIP_8_MEMORY_SIZE);
}

void chip8_memory_set(struct chip8 *chip8, uint32_t index, uint8_t val) {
    is_valid_index(index);
    chip8->memory[index] = val;
}

uint8_t chip8_memory_get(struct chip8 *chip8, uint32_t index) {
    is_valid_index(index);
    return chip8->memory[index];
}