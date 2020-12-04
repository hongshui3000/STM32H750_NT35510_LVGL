################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GUI/lvgl/src/lv_draw/lv_draw_arc.c \
../Drivers/GUI/lvgl/src/lv_draw/lv_draw_blend.c \
../Drivers/GUI/lvgl/src/lv_draw/lv_draw_img.c \
../Drivers/GUI/lvgl/src/lv_draw/lv_draw_label.c \
../Drivers/GUI/lvgl/src/lv_draw/lv_draw_line.c \
../Drivers/GUI/lvgl/src/lv_draw/lv_draw_mask.c \
../Drivers/GUI/lvgl/src/lv_draw/lv_draw_rect.c \
../Drivers/GUI/lvgl/src/lv_draw/lv_draw_triangle.c \
../Drivers/GUI/lvgl/src/lv_draw/lv_img_buf.c \
../Drivers/GUI/lvgl/src/lv_draw/lv_img_cache.c \
../Drivers/GUI/lvgl/src/lv_draw/lv_img_decoder.c 

OBJS += \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_arc.o \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_blend.o \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_img.o \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_label.o \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_line.o \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_mask.o \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_rect.o \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_triangle.o \
./Drivers/GUI/lvgl/src/lv_draw/lv_img_buf.o \
./Drivers/GUI/lvgl/src/lv_draw/lv_img_cache.o \
./Drivers/GUI/lvgl/src/lv_draw/lv_img_decoder.o 

C_DEPS += \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_arc.d \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_blend.d \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_img.d \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_label.d \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_line.d \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_mask.d \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_rect.d \
./Drivers/GUI/lvgl/src/lv_draw/lv_draw_triangle.d \
./Drivers/GUI/lvgl/src/lv_draw/lv_img_buf.d \
./Drivers/GUI/lvgl/src/lv_draw/lv_img_cache.d \
./Drivers/GUI/lvgl/src/lv_draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GUI/lvgl/src/lv_draw/lv_draw_arc.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_draw_arc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_draw_arc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_draw/lv_draw_blend.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_draw_blend.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_draw_blend.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_draw/lv_draw_img.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_draw_img.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_draw_img.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_draw/lv_draw_label.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_draw_label.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_draw_label.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_draw/lv_draw_line.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_draw_line.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_draw_line.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_draw/lv_draw_mask.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_draw_mask.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_draw_mask.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_draw/lv_draw_rect.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_draw_rect.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_draw_rect.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_draw/lv_draw_triangle.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_draw_triangle.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_draw_triangle.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_draw/lv_img_buf.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_img_buf.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_img_buf.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_draw/lv_img_cache.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_img_cache.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_img_cache.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lvgl/src/lv_draw/lv_img_decoder.o: ../Drivers/GUI/lvgl/src/lv_draw/lv_img_decoder.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DSTM32H750xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lvgl/src/lv_draw/lv_img_decoder.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

