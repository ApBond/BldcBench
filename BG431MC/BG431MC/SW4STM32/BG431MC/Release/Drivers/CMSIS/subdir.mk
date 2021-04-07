################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/system_stm32g4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32g4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32g4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32g4xx.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/system_stm32g4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


