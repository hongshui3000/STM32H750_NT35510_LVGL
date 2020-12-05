#include "sys.h"


#if defined(__clang__) //К№УГV6±аТлЖч(clang)
//THUMBЦёБоІ»Ц§іЦ»г±аДЪБЄ
//ІЙУГИзПВ·Ѕ·ЁКµПЦЦґРР»г±аЦёБоWFI
void __attribute__((noinline)) WFI_SET(void)
{
    __asm__("wfi");
}

//№Ш±ХЛщУРЦР¶П(µ«КЗІ»°ьАЁfaultєНNMIЦР¶П)
void __attribute__((noinline)) INTX_DISABLE(void)
{
    __asm__("cpsid i \t\n"
            "bx lr");
}

//їЄЖфЛщУРЦР¶П
void __attribute__((noinline)) INTX_ENABLE(void)
{
    __asm__("cpsie i \t\n"
            "bx lr");
}

//ЙиЦГХ»¶ҐµШЦ·
//addr:Х»¶ҐµШЦ·
void __attribute__((noinline)) MSR_MSP(u32 addr)
{
    __asm__("msr msp, r0 \t\n"
            "bx r14");
}
#elif defined (__CC_ARM)    //К№УГV5±аТлЖч(ARMCC)

//THUMBЦёБоІ»Ц§іЦ»г±аДЪБЄ
//ІЙУГИзПВ·Ѕ·ЁКµПЦЦґРР»г±аЦёБоWFI
__asm void WFI_SET(void)
{
	WFI;
}
//№Ш±ХЛщУРЦР¶П(µ«КЗІ»°ьАЁfaultєНNMIЦР¶П)
__asm void INTX_DISABLE(void)
{
	CPSID   I
	BX      LR
}
//їЄЖфЛщУРЦР¶П
__asm void INTX_ENABLE(void)
{
	CPSIE   I
	BX      LR
}
//ЙиЦГХ»¶ҐµШЦ·
//addr:Х»¶ҐµШЦ·
__asm void MSR_MSP(u32 addr)
{
	MSR MSP, r0 			//set Main Stack value
	BX r14
}
#endif
