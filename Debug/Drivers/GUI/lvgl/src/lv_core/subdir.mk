################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GUI/lvgl/src/lv_core/lv_disp.c \
../Drivers/GUI/lvgl/src/lv_core/lv_group.c \
../Drivers/GUI/lvgl/src/lv_core/lv_indev.c \
../Drivers/GUI/lvgl/src/lv_core/lv_obj.c \
../Drivers/GUI/lvgl/src/lv_core/lv_refr.c \
../Drivers/GUI/lvgl/src/lv_core/lv_style.c 

OBJS += \
./Drivers/GUI/lvgl/src/lv_core/lv_disp.o \
./Drivers/GUI/lvgl/src/lv_core/lv_group.o \
./Drivers/GUI/lvgl/src/lv_core/lv_indev.o \
./Drivers/GUI/lvgl/src/lv_core/lv_obj.o \
./Drivers/GUI/lvgl/src/lv_core/lv_refr.o \
./Drivers/GUI/lvgl/src/lv_core/lv_style.o 

C_DEPS += \
./Drivers/GUI/lvgl/src/lv_core/lv_disp.d \
./Drivers/GUI/lvgl/src/lv_core/lv_group.d \
./Drivers/GUI/lvgl/src/lv_core/lv_indev.d \
./Drivers/GUI/lvgl/src/lv_core/lv_obj.d \
./Drivers/GUI/lvgl/src/lv_core/lv_refr.d \
./Drivers/GUI/lvgl/src/lv_core/lv_style.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GUI/lvgl/src/lv_core/lv_disp.o: ../Drivers/GUI/lvgl/src/lv_core/lv_disp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_core/lv_disp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_core/lv_group.o: ../Drivers/GUI/lvgl/src/lv_core/lv_group.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_core/lv_group.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_core/lv_indev.o: ../Drivers/GUI/lvgl/src/lv_core/lv_indev.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_core/lv_indev.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_core/lv_obj.o: ../Drivers/GUI/lvgl/src/lv_core/lv_obj.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_core/lv_obj.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_core/lv_refr.o: ../Drivers/GUI/lvgl/src/lv_core/lv_refr.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_core/lv_refr.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_core/lv_style.o: ../Drivers/GUI/lvgl/src/lv_core/lv_style.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_core/lv_style.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

