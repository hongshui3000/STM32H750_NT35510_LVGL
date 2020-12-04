#include "mpu.h"

uint8_t MPU_Set_Protection(uint32_t baseaddr, uint32_t size, uint32_t rnum, uint8_t ap, uint8_t sen, uint8_t cen, uint8_t ben)
{
	MPU_Region_InitTypeDef MPU_Initure;
	
	HAL_MPU_Disable();

    MPU_Initure.Enable = MPU_REGION_ENABLE;
    MPU_Initure.Number = rnum;
    MPU_Initure.BaseAddress = baseaddr;
    MPU_Initure.Size = size;
    MPU_Initure.SubRegionDisable = 0X00;
    MPU_Initure.TypeExtField = MPU_TEX_LEVEL0;
    MPU_Initure.AccessPermission = (uint8_t)ap;
    MPU_Initure.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
    MPU_Initure.IsShareable = sen;
    MPU_Initure.IsCacheable = cen;   
    MPU_Initure.IsBufferable = ben;
    HAL_MPU_ConfigRegion(&MPU_Initure);
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
    return 0;
}

void MPU_Memory_Protection(void)
{
    //SRAM 512KB
    MPU_Set_Protection( 0x24000000,
                        MPU_REGION_SIZE_512KB,
                        MPU_REGION_NUMBER1,
                        MPU_REGION_FULL_ACCESS,
                        MPU_ACCESS_SHAREABLE,
                        MPU_ACCESS_CACHEABLE,
                        MPU_ACCESS_NOT_BUFFERABLE);
    
    //SRAM 32MB 
    MPU_Set_Protection( 0XC0000000,
                        MPU_REGION_SIZE_32MB,
                        MPU_REGION_NUMBER2,
                        MPU_REGION_FULL_ACCESS,
                        MPU_ACCESS_NOT_SHAREABLE,
                        MPU_ACCESS_CACHEABLE,
                        MPU_ACCESS_BUFFERABLE);
}


