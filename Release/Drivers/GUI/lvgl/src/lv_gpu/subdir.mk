################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.c \
../Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.c \
../Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.c \
../Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.c 

OBJS += \
./Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.o \
./Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.o \
./Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.o \
./Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.o 

C_DEPS += \
./Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.d \
./Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.d \
./Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.d \
./Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.o: ../Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.o: ../Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_pxp_osa.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.o: ../Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_nxp_vglite.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.o: ../Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_gpu/lv_gpu_stm32_dma2d.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

