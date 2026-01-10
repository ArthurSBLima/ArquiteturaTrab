#include "CPU.c"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MEM_SIZE (8192)
#define PILHA_INV (8192) //so q e endereco 

#define JMP 0x0
#define JEQ 0x1 
#define JNE 0x1 //condicional
#define JLT 0x1 //condicional
#define JGE 0x1 //condicional
#define LDR 0x2
#define STR 0x3
#define MOV 0x4
#define ADD 0x5
#define ADDI 0x6
#define SUB 0x7
#define SUBI 0x8
#define AND 0x9
#define OR 0xA
#define SHR 0xB
#define SHL 0xC
#define CMP 0xD
#define PUSH 0xE
#define POP 0xF

typedef struct {
    uint16_t regs[16];
    uint16_t memoria[MEM_SIZE];
    bool flag_zero;
    bool flag_carry;
    bool instrucoes_carregadas[MEM_SIZE]; //endereços de instruções usada
    bool dados_enderecos[MEM_SIZE];  //enderecos dados
    bool dados_pilhas[MEM_SIZE]; //enderecos pilha
    bool breakP[MEM_SIZE];
} simul;

static inline bool escopo(uint16_t endereco){
    return endereco < MEM_SIZE;
}

static void push(simul *sim, uint16_t val){
    uint16_t pilha_usada = sim->regs[14];
    if(pilha_usada  == 0){
        return;
    }
    pilha_usada--;
    sim->regs[14] = pilha_usada; 

    if(escopo(pilha_usada)){
        sim->mem[pilha_usada] = val;
    }
}

static void pop(simul *sim){
    uint16_t pilha_usada = sim->regs[14];

    if(pilha_usada = PILHA_INV){
        return 0;
    }
    uint16_t val = 0;
    if(escopo(pilha_usada)){
        val = sim->memoria[pilha_usada];
    }
    sim->regs[14] = pilha_usada++;
    return val; 
}

static void att_flags(simul *sim, uint16_t val){
    if(result == 0)[
        sim->flag_zero = true;
    ]
    if(result < 0){
        sim->flag_carry = true;
    }

}

static void printa_estado(simul *sim){
    for(int i = 0; i < 16; i++){
        printf("R%d = 0x%04hX\n", i, sim->regs[i]);        
    }
    printf("Z = %d\n", sim->flag_zero);
    printf("C = %d\n", sim->flag_carry);

    uint16_t pilha_usada = sim->regs[14];
    bool pilha_em_uso = (pilha_usada != 8192);

    for(uint16_t i = 0; i < MEM_SIZE; i++){
        if(sim->dados_enderecos && !sim->dados_pilhas[i] && (!pilha_em_uso || i < pilha_usada)){
            printf("[ 0x%04hX ] = 0x%04hX\n", a, s->memoria[a]);
        }
    }
    if(pilha_em_uso){
        for(uint16_t j = 0x1FFF; j >= pilha_usada; j--){
          printf("[ 0x%04hX ] = 0x%04hX\n", a, sim->memoria[j]);
            if(j == 0){
                break;
            }  
        }
    }
   
}
