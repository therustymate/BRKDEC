#ifndef BRKDEC
#define BRKDEC

#include <stdio.h>
#if defined(_WIN32)
    #include <windows.h>
    #define thrd_yield() SwitchToThread()
#else
    #include <threads.h>
#endif

static inline void TRIGGER_FUNCTION() { thrd_yield(); }
static inline void RETURN_CALL() {
    void* TRIGGER = (void*)TRIGGER_FUNCTION;
    __asm__ volatile (
        // FUNCTION_ENTRY (rsp % 16 == 8)
        // [ SAVE REGISTERS ]
        "pushq %%rax\n\t"       // rsp % 16 == 0
        "pushq %%rcx\n\t"       // rsp % 16 == 8
        "pushq %%rdx\n\t"       // rsp % 16 == 0
        "pushq %%rbx\n\t"       // rsp % 16 == 8
        "pushq %%rsi\n\t"       // rsp % 16 == 0
        "pushq %%rdi\n\t"       // rsp % 16 == 8
        "pushq %%r8\n\t"        // rsp % 16 == 0
        "pushq %%r9\n\t"        // rsp % 16 == 8
        "pushq %%r10\n\t"       // rsp % 16 == 0
        "pushq %%r11\n\t"       // rsp % 16 == 8
        "pushq %%rbp\n\t"       // rsp % 16 == 0
        "movq %%rsp, %%rbp\n\t"

        // [ STACK ALIGNMENT ]
        // "andq $-16, %%rsp\n\t"  // not needed

        // [ RETURN ADDRESS MANIPULATION ]
        "leaq 1f(%%rip), %%rax\n\t"
        "pushq %%rax\n\t"       // rsp % 16 == 8

        // [ JUMP TO TRIGGER ]
        "jmp *%0\n\t"           // ABI calling convention is correct

        "1:\n\t"
        // FUNCTION_ENTRY (rsp % 16 == 0) | THE FUNCTION IS RETURN (NOT CALL)

        // [ RECOVER REGISTERS ]
        "movq %%rbp, %%rsp\n\t"
        "popq %%rbp\n\t"        // rsp % 16 == 8
        "popq %%r11\n\t"        // rsp % 16 == 0
        "popq %%r10\n\t"        // rsp % 16 == 8
        "popq %%r9\n\t"         // rsp % 16 == 0
        "popq %%r8\n\t"         // rsp % 16 == 8
        "popq %%rdi\n\t"        // rsp % 16 == 0
        "popq %%rsi\n\t"        // rsp % 16 == 8
        "popq %%rbx\n\t"        // rsp % 16 == 0
        "popq %%rdx\n\t"        // rsp % 16 == 8
        "popq %%rcx\n\t"        // rsp % 16 == 0
        "popq %%rax\n\t"        // rsp % 16 == 8

        // MUST BE: rsp % 16 == 8 (currently aligned)
        :
        : "r" (TRIGGER)
        : "rax", "memory", "cc"
    );
}

#define BRKDEC_FUNC_BOUNDARY { RETURN_CALL(); }

#endif