################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer.c \
../Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer_theme.c 

OBJS += \
./Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer.o \
./Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer_theme.o 

C_DEPS += \
./Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer.d \
./Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer_theme.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer.o: ../Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer_theme.o: ../Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer_theme.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/src/lv_demo_printer/lv_demo_printer_theme.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

