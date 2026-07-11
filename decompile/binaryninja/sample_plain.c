int32_t main(int32_t argc, char** argv, char** envp)
    int64_t rcx = 0
    int32_t* rdx = &data_402010
    int64_t rdi = 0
    int32_t rsi = 0
    int32_t rax = 0
    int32_t rbx_3
    int32_t rsi_1
    
    while (true)
        int32_t r8_1 = *rdx
        int32_t r9_3 = r8_1 ^ 0x193
        int32_t r10_2 = r9_3 + 7
        
        if ((r9_3.b & 1) != 0)
            r10_2 = r9_3 - 3
        
        int32_t r11_3 = neg.d(r10_2)
        int32_t r9_4 = r10_2
        
        if (r11_3 s>= 0)
            r9_4 = r11_3
        
        if (r8_1 == 0)
            rax += 3
        label_4012ef:
            rdi += 1
            rcx -= 2
            rdx = &rdx[1]
            
            if (rdi == 0xa)
                int32_t rax_1 = neg.d(rax)
                rsi_1 = rsi + rax_1
                
                if (rsi + rax_1 s< 0)
                    rbx_3 = -1
                    break
            else
                continue
        else
            uint32_t r10_7
            int32_t r10_5
            
            if (r9_4 * 0xcccccccd u<= 0x33333333)
                int64_t r11_4 = sx.q(r11_3)
                int64_t r9_7 = sx.q(r10_2)
                int32_t r10_4 = r9_7.d
                
                if (r11_4 s> r9_7)
                    r10_4 = r11_4.d
                
                r10_5 = r10_4 + rdi.d
                
                if (r10_5 u>= 0x65)
                    r10_7 = r10_5 u>> 1
                else
                    if (r11_4 s> r9_7)
                        r9_7 = r11_4
                    
                    r10_7 = (r9_7 + rdi).d + 1
            else
                int32_t r9_5
                
                if (r9_4 * 0xaaaaaaab u<= 0x55555555)
                    int64_t r11_5 = sx.q(r11_3)
                    int64_t r10_8 = sx.q(r10_2)
                    
                    if (r11_5 s> r10_8)
                        r10_8 = r11_5
                    
                    r10_5 = r10_8.d + rcx.d
                    
                    if (r10_5 s< 0x65)
                        r9_5 = r9_4 - rdi.d * 2
                        
                        r10_7 = r10_5 s> 0xffffffcd ? r9_5 + 1 : r9_5 + 0x19
                    else
                        r10_7 = r10_5 u>> 1
                else
                    r9_5 = r9_4 ^ (rdi + 0xb).d
                    
                    r10_7 = r9_5 u< 0x65 ? r9_5 + 1 : r9_5 u>> 1
            rsi += r10_7
            int32_t r9_1 = rdi.d
            
            if ((rsi.b & 1) != 0)
                r9_1 = r8_1 & 3
            
            rax += r9_1
            
            if (rsi s<= 0x1f4)
                goto label_4012ef
            
            if (rdi.d == 0xa)
                rax = neg.d(rax)
            
            rsi_1 = rsi + rax
            
            if (rsi + rax s< 0)
                rbx_3 = -1
                break
        
        rbx_3 = 0
        
        if (rsi_1 u>= 0x64)
            rbx_3 = sbb.d(2, 0, rsi_1 u< 0x12c)
        
        break
    
    printf(format: "score = %d\n", rsi_1)
    printf(format: "class = %d\n", zx.q(rbx_3))
    return 0