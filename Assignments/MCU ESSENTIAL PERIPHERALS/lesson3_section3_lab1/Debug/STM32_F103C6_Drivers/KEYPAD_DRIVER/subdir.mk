################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.c 

OBJS += \
./STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.o 

C_DEPS += \
./STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/KEYPAD_DRIVER/%.o STM32_F103C6_Drivers/KEYPAD_DRIVER/%.su STM32_F103C6_Drivers/KEYPAD_DRIVER/%.cyclo: ../STM32_F103C6_Drivers/KEYPAD_DRIVER/%.c STM32_F103C6_Drivers/KEYPAD_DRIVER/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/fadye/OneDrive/Desktop/Embedded_C/My_workspace/host/unit7_lesson3_section3_lab1/STM32_F103C6_Drivers/Seven_Segment" -I"C:/Users/fadye/OneDrive/Desktop/Embedded_C/My_workspace/host/unit7_lesson3_section3_lab1/STM32_F103C6_Drivers/KEYPAD_DRIVER" -I"C:/Users/fadye/OneDrive/Desktop/Embedded_C/My_workspace/host/unit7_lesson3_section3_lab1/STM32_F103C6_Drivers/LCD_DRIVER" -I"C:/Users/fadye/OneDrive/Desktop/Embedded_C/My_workspace/host/unit7_lesson3_section3_lab1/STM32_F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32_F103C6_Drivers-2f-KEYPAD_DRIVER

clean-STM32_F103C6_Drivers-2f-KEYPAD_DRIVER:
	-$(RM) ./STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.cyclo ./STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.d ./STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.o ./STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.su

.PHONY: clean-STM32_F103C6_Drivers-2f-KEYPAD_DRIVER

