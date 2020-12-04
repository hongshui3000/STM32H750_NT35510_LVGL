################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_1.c \
../Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_2.c 

OBJS += \
./Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_1.o \
./Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_2.o 

C_DEPS += \
./Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_1.d \
./Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_2.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_1.o: ../Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_1.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_1.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_2.o: ../Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_2.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_objmask/lv_ex_objmask_2.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

