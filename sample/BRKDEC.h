#ifndef BRKDEC
#define BRKDEC

#include <stdio.h>

void TRIGGER_FUNCTION() { printf("\r"); }
void RETURN_CALL() {
    void* TRIGGER = (void*)TRIGGER_FUNCTION;
    __asm__ volatile (
        // [ SAVE REGISTERS ]
        "pushq %%rax\n\t"
        "pushq %%rcx\n\t"
        "pushq %%rdx\n\t"
        "pushq %%rbx\n\t"
        "pushq %%rsi\n\t"
        "pushq %%rdi\n\t"
        "pushq %%r8\n\t"
        "pushq %%r9\n\t"
        "pushq %%r10\n\t"
        "pushq %%r11\n\t"
        "pushq %%rbp\n\t"
        "movq %%rsp, %%rbp\n\t"

        // [ STACK ALIGNMENT ]
        "andq $-16, %%rsp\n\t"

        // [ RETURN ADDRESS MANIPULATION ]
        "leaq 1f(%%rip), %%rax\n\t"
        "pushq %%rax\n\t"

        // [ JUMP TO TRIGGER ]
        "jmp *%0\n\t"

        "1:\n\t"

        // [ RECOVER REGISTERS ]
        "movq %%rbp, %%rsp\n\t"
        "popq %%rbp\n\t"
        "popq %%r11\n\t"
        "popq %%r10\n\t"
        "popq %%r9\n\t"
        "popq %%r8\n\t"
        "popq %%rdi\n\t"
        "popq %%rsi\n\t"
        "popq %%rbx\n\t"
        "popq %%rdx\n\t"
        "popq %%rcx\n\t"
        "popq %%rax\n\t"
        :
        : "r" (TRIGGER)
        : "rax", "memory", "cc"
    );
}

#define BRKDEC_FUNC_BOUNDARY { RETURN_CALL(); }

#endif