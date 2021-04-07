################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/dac_ui.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/main.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_api.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_config.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_interface.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_math.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_parameters.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_tasks.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/motor_control_protocol.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/motorcontrol.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/regular_conversion_manager.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/stm32g4xx_hal_msp.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/stm32g4xx_it.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/stm32g4xx_mc_it.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/ui_task.c \
D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/user_interface.c 

OBJS += \
./Application/User/dac_ui.o \
./Application/User/main.o \
./Application/User/mc_api.o \
./Application/User/mc_config.o \
./Application/User/mc_interface.o \
./Application/User/mc_math.o \
./Application/User/mc_parameters.o \
./Application/User/mc_tasks.o \
./Application/User/motor_control_protocol.o \
./Application/User/motorcontrol.o \
./Application/User/regular_conversion_manager.o \
./Application/User/stm32g4xx_hal_msp.o \
./Application/User/stm32g4xx_it.o \
./Application/User/stm32g4xx_mc_it.o \
./Application/User/ui_task.o \
./Application/User/user_interface.o 

C_DEPS += \
./Application/User/dac_ui.d \
./Application/User/main.d \
./Application/User/mc_api.d \
./Application/User/mc_config.d \
./Application/User/mc_interface.d \
./Application/User/mc_math.d \
./Application/User/mc_parameters.d \
./Application/User/mc_tasks.d \
./Application/User/motor_control_protocol.d \
./Application/User/motorcontrol.d \
./Application/User/regular_conversion_manager.d \
./Application/User/stm32g4xx_hal_msp.d \
./Application/User/stm32g4xx_it.d \
./Application/User/stm32g4xx_mc_it.d \
./Application/User/ui_task.d \
./Application/User/user_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/dac_ui.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/dac_ui.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/mc_api.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_api.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/mc_config.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_config.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/mc_interface.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_interface.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/mc_math.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_math.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/mc_parameters.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_parameters.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/mc_tasks.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/mc_tasks.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/motor_control_protocol.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/motor_control_protocol.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/motorcontrol.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/motorcontrol.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/regular_conversion_manager.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/regular_conversion_manager.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32g4xx_hal_msp.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/stm32g4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32g4xx_it.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/stm32g4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32g4xx_mc_it.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/stm32g4xx_mc_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/ui_task.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/ui_task.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/user_interface.o: D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Src/user_interface.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32G431xx -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/Any/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/MCLib/G4xx/Inc" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/MCSDK_v5.4.4/MotorControl/MCSDK/UILibrary/Inc" -I../../../MCSDK_v5.4.4/MotorControl/MCSDK/SystemDriveParams -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/Include" -I"D:/work/bastet/BldcBench-master/BG431MC/BG431MC/Drivers/CMSIS/DSP/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


