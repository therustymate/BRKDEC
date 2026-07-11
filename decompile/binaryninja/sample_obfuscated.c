int64_t sub_401150()
    int64_t rbp
    int64_t var_8 = rbp
    int64_t rbx
    int64_t var_30 = rbx
    void* const var_40 = &data_4014c0
    int64_t rdx
    int64_t var_48 = rdx
    int64_t var_50 = rbx
    int64_t rsi
    int64_t var_58 = rsi
    int64_t rdi
    int64_t var_60 = rdi
    int64_t r8
    int64_t var_68 = r8
    int64_t r9
    int64_t var_70 = r9
    int64_t var_88 = rbp
    int64_t (* var_98)(int64_t* arg1 @ rbp) = sub_401181
    return thrd_yield() __tailcall


int64_t sub_401181(int64_t* arg1 @ rbp)
    *arg1
    arg1[1]
    arg1[2]
    arg1[3]
    arg1[4]
    void* rdi = arg1[5]
    int32_t rsi = (arg1[6]).d
    int64_t rbx = arg1[7]
    int32_t rdx = (arg1[8]).d
    arg1[9]
    int64_t rax = arg1[0xa]
    
    if (rsi s<= 0)
        arg1[0xb]
        arg1[0xc]
        arg1[0xd]
        arg1[0xe]
        arg1[0xf]
        arg1[0x10]
        return 0
    
    *(arg1 + 0x54) = rsi
    uint64_t rbp_1 = zx.q(*rdi)
    arg1[0xa] = rax
    arg1[9] = zx.q(rsi)
    arg1[8] = 0
    arg1[7] = rbx
    arg1[6] = &data_4014c0
    arg1[5] = rdi
    arg1[4] = 0
    arg1[3] = zx.q(rdx * 0x1f)
    arg1[2] = 0xb
    arg1[1] = 0
    *arg1 = rbp_1
    *((arg1 & 0xfffffffffffffff0) - 8) = sub_401216
    return thrd_yield() __tailcall


uint64_t sub_4011d0(int64_t arg1, int64_t arg2, int64_t arg3, uint64_t arg4, int32_t arg5, int64_t arg6 @ rax, int32_t arg7 @ r10, 
  int32_t arg8 @ r11, int64_t arg9 @ r14, int64_t arg10, int64_t arg11, int64_t arg12, int64_t arg13, int64_t arg14)
    uint64_t r8 = zx.q(arg5 + arg6.d)
    
    if (arg3.d s> 0x1f4)
        arg4 = zx.q(arg9.d)
    else if (arg4 != arg9 + 1)
        int64_t var_8 = arg6
        uint64_t var_10 = arg4
        int64_t var_18 = arg3
        int64_t rbx
        int64_t var_20 = rbx
        int64_t var_28 = arg2
        int64_t var_30 = arg1
        uint64_t var_38 = r8
        int64_t r9
        int64_t var_40 = r9
        uint64_t var_48 = zx.q(arg7 + 1)
        uint64_t var_50 = zx.q(arg8 - 2)
        uint64_t var_58 = zx.q(*(arg1 + ((arg9 + 1) << 2)))
        uint64_t (* var_68)(int64_t* arg1 @ rbp, int64_t arg2 @ r14) = sub_401216
          jump(arg2)
    
    int32_t rax_1 = neg.d(r8.d)
    int32_t var_4
    
    if (arg4.d != var_4)
        rax_1 = r8.d
    
    return zx.q(rax_1 + arg3.d)


uint64_t sub_401216(int64_t* arg1 @ rbp, int64_t arg2 @ r14)
    int64_t rbp = *arg1
    int64_t r11 = arg1[1]
    int64_t r10 = arg1[2]
    int64_t r9 = arg1[3]
    int64_t r8 = arg1[4]
    int64_t rdi = arg1[5]
    int64_t rsi = arg1[6]
    int64_t rbx = arg1[7]
    int64_t rdx = arg1[8]
    int64_t rcx = arg1[9]
    uint64_t rax_1 = zx.q(rbp.d) ^ zx.q(r9.d)
    int32_t r12_1 = rax_1.d + 7
    
    if ((rax_1.b & 1) != 0)
        r12_1 = (rax_1 - 3).d
    
    int32_t r13_1 = neg.d(r12_1)
    int32_t r15_1 = r12_1
    
    if (r13_1 s>= 0)
        r15_1 = r13_1
    
    if (rbp.d == 0)
        uint64_t r8_1 = zx.q(r8.d + 3)
        
        if (rcx == arg2 + 1)
            int32_t rax_4 = neg.d(r8_1.d)
            
            if (rcx.d != *(arg1 + 0x54))
                rax_4 = r8_1.d
            
            arg1[0xb]
            arg1[0xc]
            arg1[0xd]
            arg1[0xe]
            arg1[0xf]
            arg1[0x10]
            return zx.q(rax_4 + rdx.d)
        
        uint64_t rbp_4 = zx.q(*(rdi + ((arg2 + 1) << 2)))
        arg1[0xa] = rax_1
        arg1[9] = rcx
        arg1[8] = rdx
        arg1[7] = rbx
        arg1[6] = rsi
        arg1[5] = rdi
        arg1[4] = r8_1
        arg1[3] = r9
        arg1[2] = zx.q(r10.d + 1)
        arg1[1] = zx.q(r11.d - 2)
        *arg1 = rbp_4
        *((arg1 & 0xfffffffffffffff0) - 8) = sub_401216
          jump(rsi)
    
    uint64_t rax_2 = zx.q(r15_1 * 0xcccccccd)
    
    if (rax_2.d u<= 0x33333333)
        arg1[0xa] = rax_2
        arg1[9] = rcx
        arg1[8] = rdx
        arg1[7] = rbx
        arg1[6] = rsi
        arg1[5] = rdi
        arg1[4] = r8
        arg1[3] = r9
        arg1[2] = r10
        arg1[1] = r11
        *arg1 = rbp
        *((arg1 & 0xfffffffffffffff0) - 8) = &data_4012e0
          jump(rsi)
    
    arg1[0xa] = rax_2
    arg1[9] = rcx
    arg1[8] = rdx
    arg1[7] = zx.q(r15_1 * 0xaaaaaaab)
    arg1[6] = rsi
    arg1[5] = rdi
    arg1[4] = r8
    arg1[3] = r9
    arg1[2] = r10
    arg1[1] = r11
    *arg1 = rbp
    *((arg1 & 0xfffffffffffffff0) - 8) = sub_401284
      jump(rsi)


int64_t sub_401284(int64_t* arg1 @ rbp, int32_t arg2 @ r12, int32_t arg3 @ r13, int32_t arg4 @ r14, int32_t arg5 @ r15)
    int32_t r11 = (arg1[1]).d
    int32_t r10 = (arg1[2]).d
    int64_t r8 = arg1[4]
    int64_t rdi = arg1[5]
    int64_t rsi = arg1[6]
    uint64_t rcx = arg1[9]
    arg1[0xa]
    uint8_t rax_3
    
    if ((arg1[7]).d u<= 0x55555555)
        int32_t rax_1 = arg2
        
        if (arg3 s> arg2)
            rax_1 = arg3
        
        int32_t rax_2 = rax_1 + r11
        
        if (rax_2 s>= 0x65)
            rax_3 = (rax_2 u>> 1).b
        else if (rax_2 s> 0xffffffcd)
            if (arg3 s> arg2)
                arg2 = arg3
            
            rax_3 = arg2.b + r11.b + 1
        else
            rax_3 = arg5.b - arg4.b * 2 + 0x19
    else
        int32_t r15 = arg5 ^ r10
        uint8_t r15_1
        
        r15_1 = r15 u< 0x65 ? r15.b + 1 : (r15 u>> 1).b
        
        rax_3 = r15_1
    
    char rdx_1 = (arg1[8]).b + rax_3
    
    if ((rdx_1 & 1) == 0)
        return sub_4011d0(rdi, rsi, rdx_1, rcx, r8, zx.q(arg4), r10, r11, arg4)
            __tailcall
    
    return sub_4011d0(rdi, rsi, rdx_1, rcx, r8, zx.q((*arg1).d) & 3, r10, r11, arg4)
        __tailcall


uint64_t sub_4013b7(int64_t* arg1 @ rbp)
    *arg1
    arg1[1]
    arg1[2]
    arg1[3]
    arg1[4]
    int32_t rdi = (arg1[5]).d
    arg1[6]
    arg1[7]
    arg1[8]
    arg1[9]
    arg1[0xa]
    
    if (rdi s< 0)
        return 0xffffffff
    
    if (rdi u< 0x64)
        return 0
    
    return zx.q(sbb.d(2, 0, rdi u< 0x12c))


int32_t main(int32_t argc, char** argv, char** envp)
    int64_t rcx
    int64_t var_18 = rcx
    char** envp_1 = envp
    void* const var_28 = &data_4014c0
    char** argv_1 = argv
    int64_t argc_1 = argc
    int64_t r8
    int64_t var_40 = r8
    int64_t r9
    int64_t var_48 = r9
    int64_t (* var_68)(int64_t* arg1 @ rbp) = sub_401418
    return thrd_yield() __tailcall


int64_t sub_401418(int64_t* arg1 @ rbp)
    *arg1
    arg1[1]
    arg1[2]
    arg1[3]
    arg1[4]
    int64_t rbx = arg1[7]
    arg1[9]
    arg1[0xa]
    int64_t rax_1
    int64_t rcx_1
    int64_t rdx_1
    int64_t rbp_1
    int64_t rdi_1
    int64_t r8_1
    int64_t r9_1
    int64_t r10_1
    int64_t r11_1
    rax_1, rcx_1, rdx_1, rbp_1, rdi_1, r8_1, r9_1, r10_1, r11_1 = sub_401150()
    arg1[0xa] = rax_1
    arg1[9] = rcx_1
    arg1[8] = rdx_1
    arg1[7] = rbx
    arg1[6] = zx.q(rax_1.d)
    arg1[5] = rdi_1
    arg1[4] = r8_1
    arg1[3] = r9_1
    arg1[2] = r10_1
    arg1[1] = r11_1
    *arg1 = rbp_1
    *((arg1 & 0xfffffffffffffff0) - 8) = sub_401462
      jump(rbx)

      
int64_t sub_401462(int64_t* arg1 @ rbp)
    *arg1
    arg1[1]
    arg1[2]
    arg1[5]
    int32_t rsi = (arg1[6]).d
    arg1[7]
    arg1[0xa]
    int32_t rbx_1
    
    if (rsi s< 0)
        rbx_1 = -1
    else
        rbx_1 = 0
        
        if (rsi u>= 0x64)
            rbx_1 = sbb.d(2, 0, rsi u< 0x12c)
    
    printf(format: "score = %d\n")
    printf(format: "class = %d\n", zx.q(rbx_1))
    arg1[0xb]
    return 0