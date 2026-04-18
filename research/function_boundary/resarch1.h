#ifndef BRKDEC
#define BRKDEC

#include <stdio.h>

void TRIGGER_FUNCTION() { printf("\r"); }
void RETURN_CALL() {
    void* TRIGGER = (void*)TRIGGER_FUNCTION;
    __asm__ volatile (
        "leaq 1f(%%rip), %%rax\n\t"
        "pushq %%rax\n\t"
        "pushq %0\n\t"
        "retq\n\t"
        "1:\n\t"
        :
        : "r" (TRIGGER)
        : "rax", "memory"
    );
}

#define BRKDEC_FUNC_BOUNDARY { RETURN_CALL(); }

#endif