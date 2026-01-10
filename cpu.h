#ifndef CPU_H
#define CPU_H
#include <stdio.h>
#include <stdint.h>

typedef enum
{
    ERROR_OK,
    ERROR_INVALID_OPCODE,
    ERROR_INVALID_MEMORY,
    ERROR_HALTED
} ErrorType;

typedef struct
{
    uint16_t registrador[16];
    uint16_t ir;
    uint8_t flag_zero;
    uint8_t flag_carry;
    uint8_t running;
} CPU;

//função que inicializa a cpu, de tal forma com que todos os registradores sejam zero
//e atualiza o estado da cpu para ativa, isto é running = 1
void cpu_init(CPU *cpu);

//funcao que dada uma palavra da memoria analisa o opcode e define qual ação irá ser realizada
//pelo processador
ErrorType cpu_step(CPU *cpu, uint16_t *memoria); 

#endif
