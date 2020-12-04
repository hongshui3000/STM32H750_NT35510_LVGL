################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GUI/lvgl/src/lv_misc/lv_anim.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_area.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_async.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_bidi.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_color.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_debug.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_fs.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_gc.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_ll.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_log.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_math.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_mem.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_printf.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_task.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_templ.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_txt.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_txt_ap.c \
../Drivers/GUI/lvgl/src/lv_misc/lv_utils.c 

OBJS += \
./Drivers/GUI/lvgl/src/lv_misc/lv_anim.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_area.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_async.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_bidi.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_color.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_debug.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_fs.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_gc.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_ll.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_log.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_math.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_mem.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_printf.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_task.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_templ.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_txt.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_txt_ap.o \
./Drivers/GUI/lvgl/src/lv_misc/lv_utils.o 

C_DEPS += \
./Drivers/GUI/lvgl/src/lv_misc/lv_anim.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_area.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_async.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_bidi.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_color.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_debug.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_fs.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_gc.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_ll.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_log.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_math.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_mem.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_printf.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_task.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_templ.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_txt.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_txt_ap.d \
./Drivers/GUI/lvgl/src/lv_misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GUI/lvgl/src/lv_misc/lv_anim.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_anim.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_anim.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_area.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_area.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_area.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_async.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_async.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_async.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_bidi.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_bidi.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_bidi.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_color.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_color.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_color.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_debug.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_debug.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_debug.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_fs.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_fs.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_fs.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_gc.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_gc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_gc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_ll.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_ll.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_ll.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_log.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_log.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_log.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_math.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_math.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_math.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_mem.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_mem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_mem.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_printf.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_printf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_printf.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_task.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_task.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_task.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_templ.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_templ.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_templ.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_txt.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_txt.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_txt.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_txt_ap.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_txt_ap.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_txt_ap.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_misc/lv_utils.o: ../Drivers/GUI/lvgl/src/lv_misc/lv_utils.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_misc/lv_utils.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

