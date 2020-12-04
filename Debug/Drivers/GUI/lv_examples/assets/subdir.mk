################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/GUI/lv_examples/assets/img_cogwheel_alpha16.c \
../Drivers/GUI/lv_examples/assets/img_cogwheel_argb.c \
../Drivers/GUI/lv_examples/assets/img_cogwheel_chroma_keyed.c \
../Drivers/GUI/lv_examples/assets/img_cogwheel_indexed16.c \
../Drivers/GUI/lv_examples/assets/img_cogwheel_rgb.c \
../Drivers/GUI/lv_examples/assets/img_hand.c \
../Drivers/GUI/lv_examples/assets/lv_font_montserrat_12_compr_az.c \
../Drivers/GUI/lv_examples/assets/lv_font_montserrat_16_compr_az.c \
../Drivers/GUI/lv_examples/assets/lv_font_montserrat_28_compr_az.c 

OBJS += \
./Drivers/GUI/lv_examples/assets/img_cogwheel_alpha16.o \
./Drivers/GUI/lv_examples/assets/img_cogwheel_argb.o \
./Drivers/GUI/lv_examples/assets/img_cogwheel_chroma_keyed.o \
./Drivers/GUI/lv_examples/assets/img_cogwheel_indexed16.o \
./Drivers/GUI/lv_examples/assets/img_cogwheel_rgb.o \
./Drivers/GUI/lv_examples/assets/img_hand.o \
./Drivers/GUI/lv_examples/assets/lv_font_montserrat_12_compr_az.o \
./Drivers/GUI/lv_examples/assets/lv_font_montserrat_16_compr_az.o \
./Drivers/GUI/lv_examples/assets/lv_font_montserrat_28_compr_az.o 

C_DEPS += \
./Drivers/GUI/lv_examples/assets/img_cogwheel_alpha16.d \
./Drivers/GUI/lv_examples/assets/img_cogwheel_argb.d \
./Drivers/GUI/lv_examples/assets/img_cogwheel_chroma_keyed.d \
./Drivers/GUI/lv_examples/assets/img_cogwheel_indexed16.d \
./Drivers/GUI/lv_examples/assets/img_cogwheel_rgb.d \
./Drivers/GUI/lv_examples/assets/img_hand.d \
./Drivers/GUI/lv_examples/assets/lv_font_montserrat_12_compr_az.d \
./Drivers/GUI/lv_examples/assets/lv_font_montserrat_16_compr_az.d \
./Drivers/GUI/lv_examples/assets/lv_font_montserrat_28_compr_az.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/GUI/lv_examples/assets/img_cogwheel_alpha16.o: ../Drivers/GUI/lv_examples/assets/img_cogwheel_alpha16.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/assets/img_cogwheel_alpha16.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/assets/img_cogwheel_argb.o: ../Drivers/GUI/lv_examples/assets/img_cogwheel_argb.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/assets/img_cogwheel_argb.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/assets/img_cogwheel_chroma_keyed.o: ../Drivers/GUI/lv_examples/assets/img_cogwheel_chroma_keyed.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/assets/img_cogwheel_chroma_keyed.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/assets/img_cogwheel_indexed16.o: ../Drivers/GUI/lv_examples/assets/img_cogwheel_indexed16.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/assets/img_cogwheel_indexed16.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/assets/img_cogwheel_rgb.o: ../Drivers/GUI/lv_examples/assets/img_cogwheel_rgb.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/assets/img_cogwheel_rgb.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/assets/img_hand.o: ../Drivers/GUI/lv_examples/assets/img_hand.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/assets/img_hand.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/assets/lv_font_montserrat_12_compr_az.o: ../Drivers/GUI/lv_examples/assets/lv_font_montserrat_12_compr_az.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/assets/lv_font_montserrat_12_compr_az.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/assets/lv_font_montserrat_16_compr_az.o: ../Drivers/GUI/lv_examples/assets/lv_font_montserrat_16_compr_az.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/assets/lv_font_montserrat_16_compr_az.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/GUI/lv_examples/assets/lv_font_montserrat_28_compr_az.o: ../Drivers/GUI/lv_examples/assets/lv_font_montserrat_28_compr_az.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lvgl" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/GUI/lv_examples" -I"D:/Programming_STM32/test_LCD_FMC_v3/Drivers/NT35510 Driver" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/GUI/lv_examples/assets/lv_font_montserrat_28_compr_az.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

