################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.c 

OBJS += \
./STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.o 

C_DEPS += \
./STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.o: ../STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit7_lesson4_lab1/STM32_F103C6_Drivers/EXTI_DRIVER" -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit7_lesson4_lab1/STM32_F103C6_Drivers/GPIO" -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit7_lesson4_lab1/STM32_F103C6_Drivers/Inc" -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit7_lesson4_lab1/STM32_F103C6_Drivers/KEYPAD_DRIVER" -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit7_lesson4_lab1/STM32_F103C6_Drivers/LCD_DRIVER" -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit7_lesson4_lab1/STM32_F103C6_Drivers/Seven_Segment" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/KEYPAD_DRIVER/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

