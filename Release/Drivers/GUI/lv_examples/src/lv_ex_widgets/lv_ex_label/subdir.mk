################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_1.c \
../Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_2.c \
../Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_3.c 

OBJS += \
./Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_1.o \
./Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_2.o \
./Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_3.o 

C_DEPS += \
./Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_1.d \
./Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_2.d \
./Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_3.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_1.o: ../Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_1.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_1.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_2.o: ../Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_2.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_2.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_3.o: ../Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_3.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/src/lv_ex_widgets/lv_ex_label/lv_ex_label_3.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

