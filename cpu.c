#include "cpu.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// struct CPU
// {
//     uint16_t registrador[16];
//     uint16_t ir;
//     uint8_t flag_zero;
//     uint8_t flag_carry;
//     uint8_t running;
// };

void cpu_init(CPU *cpu)
{
    for(int i = 0; i < 16; i++)
    {
        cpu->registrador[i] = 0;
    }

    cpu->ir = 0;
    cpu->flag_zero = 0;
    cpu->flag_carry = 0;
    cpu->running = 1;
}

ErrorType cpu_step(CPU *cpu, uint16_t *memoria)
{
    if(cpu->running != 1)    
        return ERROR_HALTED;

    uint16_t pc = cpu->registrador[15];
    cpu->ir = memoria[pc];
    cpu->registrador[15]++;

    return ERROR_OK;
}



