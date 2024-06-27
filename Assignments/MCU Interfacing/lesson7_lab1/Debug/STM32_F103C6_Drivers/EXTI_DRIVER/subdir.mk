################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/EXTI_DRIVER/STM32_F103C6_EXTI_Driver.c 

OBJS += \
./STM32_F103C6_Drivers/EXTI_DRIVER/STM32_F103C6_EXTI_Driver.o 

C_DEPS += \
./STM32_F103C6_Drivers/EXTI_DRIVER/STM32_F103C6_EXTI_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/EXTI_DRIVER/STM32_F103C6_EXTI_Driver.o: ../STM32_F103C6_Drivers/EXTI_DRIVER/STM32_F103C6_EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit8_lesson7_lab1/Inc" -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit8_lesson7_lab1/HAL/Inc" -I"C:/Users/fadye/STM32CubeIDE/workspace_1.4.0/unit8_lesson7_lab1/STM32_F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/EXTI_DRIVER/STM32_F103C6_EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

