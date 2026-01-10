#include "cpu.h"
#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 256

int main()
{
    uint16_t memoria[MEM_SIZE];
    CPU cpu;

    for(int i = 0; i < MEM_SIZE; i++)
        memoria[i] = 0;

    memoria[0] = 0x1234;

    cpu_init(&cpu);
    
    printf("PC INICIAL: %u\n", cpu.registrador[15]);
    
    ErrorType err = cpu_step(&cpu, memoria);

    printf("Retorno cpu_step: %d\n", err);
    printf("PC após cpu_step: %u\n", cpu.registrador[15]);
    printf("IR após cpu_step: 0x%04X\n", cpu.ir);

    return 0;
}
