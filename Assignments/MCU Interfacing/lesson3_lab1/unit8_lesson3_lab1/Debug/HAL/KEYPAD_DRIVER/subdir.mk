################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD_DRIVER/keypad.c 

OBJS += \
./HAL/KEYPAD_DRIVER/keypad.o 

C_DEPS += \
./HAL/KEYPAD_DRIVER/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KEYPAD_DRIVER/keypad.o: ../HAL/KEYPAD_DRIVER/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit8_lesson3_lab1/HAL/Inc" -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit8_lesson3_lab1/STM32_F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KEYPAD_DRIVER/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

