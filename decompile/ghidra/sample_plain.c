
undefined8 main(void)
{
    uint32_t uVar1;
    int32_t iVar2;
    int32_t iVar3;
    code *pcVar4;
    uint32_t uVar5;
    uint32_t uVar6;
    int64_t iVar7;
    uint32_t uVar8;
    uint32_t uVar9;
    uint32_t uVar10;
    uint32_t uVar11;
    
    iVar3 = 0;
    pcVar4 = data.00002010;
    iVar7 = 0;
    uVar5 = 0;
    iVar2 = 0;
    do {
        uVar1 = *(uint32_t *)pcVar4;
        uVar9 = uVar1 ^ 0x193;
        uVar8 = uVar9 + 7;
        if ((uVar9 & 1) != 0) {
            uVar8 = uVar9 - 3;
        }
        uVar11 = -uVar8;
        uVar9 = uVar8;
        if ((int32_t)uVar8 < 1) {
            uVar9 = uVar11;
        }
        if (uVar1 == 0) {
            iVar2 = iVar2 + 3;
        } else {
            uVar6 = (uint32_t)iVar7;
            if (uVar9 * -0x33333333 < 0x33333334) {
                uVar10 = uVar8;
                if ((int32_t)uVar8 < (int32_t)uVar11) {
                    uVar10 = uVar11;
                }
                uVar10 = uVar10 + uVar6;
                if (uVar10 < 0x65) {
                    if ((int32_t)uVar8 < (int32_t)uVar11) {
                        uVar8 = uVar11;
                    }
                    uVar9 = uVar8 + uVar6 + 1;
                } else {
code_r0x000013bf:
                    uVar9 = uVar10 >> 1;
                }
            } else if (uVar9 * -0x55555555 < 0x55555556) {
                if ((int32_t)uVar8 < (int32_t)uVar11) {
                    uVar8 = uVar11;
                }
                uVar10 = uVar8 + iVar3;
                if (100 < (int32_t)uVar10) goto code_r0x000013bf;
                uVar9 = uVar9 + uVar6 * -2;
                if (-0x33 < (int32_t)uVar10) goto code_r0x000013d6;
                uVar9 = uVar9 + 0x19;
            } else {
                uVar9 = uVar9 ^ uVar6 + 0xb;
                if (uVar9 < 0x65) {
code_r0x000013d6:
                    uVar9 = uVar9 + 1;
                } else {
                    uVar9 = uVar9 >> 1;
                }
            }
            uVar5 = uVar5 + uVar9;
            uVar8 = uVar6;
            if ((uVar5 & 1) != 0) {
                uVar8 = uVar1 & 3;
            }
            iVar2 = iVar2 + uVar8;
            if (500 < (int32_t)uVar5) {
                if (uVar6 == 10) {
                    iVar2 = -iVar2;
                }
                uVar5 = uVar5 + iVar2;
                goto joined_r0x00001421;
            }
        }
        iVar7 = iVar7 + 1;
        iVar3 = iVar3 + -2;
        pcVar4 = (code *)((int64_t)pcVar4 + 4);
        if (iVar7 == 10) {
            uVar5 = uVar5 - iVar2;
joined_r0x00001421:
            if ((int32_t)uVar5 < 0) {
                iVar2 = -1;
            } else {
                iVar2 = 0;
                if (99 < uVar5) {
                    iVar2 = 2 - (uint32_t)(uVar5 < 300);
                }
            }
            printf("score = %d\n");
            printf("class = %d\n", iVar2);
            return 0;
        }
    } while( true );
}
