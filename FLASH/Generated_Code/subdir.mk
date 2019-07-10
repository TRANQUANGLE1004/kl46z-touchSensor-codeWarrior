################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/BitIoLdd2.c" \
"../Generated_Code/Button1.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/ExtIntLdd1.c" \
"../Generated_Code/LED_YELLOW.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/PWM1.c" \
"../Generated_Code/PwmLdd1.c" \
"../Generated_Code/TSS1.c" \
"../Generated_Code/TU1.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/myLCD.c" \
"../Generated_Code/sw1.c" \

C_SRCS += \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/Button1.c \
../Generated_Code/Cpu.c \
../Generated_Code/ExtIntLdd1.c \
../Generated_Code/LED_YELLOW.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PWM1.c \
../Generated_Code/PwmLdd1.c \
../Generated_Code/TSS1.c \
../Generated_Code/TU1.c \
../Generated_Code/Vectors.c \
../Generated_Code/myLCD.c \
../Generated_Code/sw1.c \

OBJS += \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/Button1.o \
./Generated_Code/Cpu.o \
./Generated_Code/ExtIntLdd1.o \
./Generated_Code/LED_YELLOW.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PWM1.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/TSS1.o \
./Generated_Code/TU1.o \
./Generated_Code/Vectors.o \
./Generated_Code/myLCD.o \
./Generated_Code/sw1.o \

C_DEPS += \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/Button1.d \
./Generated_Code/Cpu.d \
./Generated_Code/ExtIntLdd1.d \
./Generated_Code/LED_YELLOW.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PWM1.d \
./Generated_Code/PwmLdd1.d \
./Generated_Code/TSS1.d \
./Generated_Code/TU1.d \
./Generated_Code/Vectors.d \
./Generated_Code/myLCD.d \
./Generated_Code/sw1.d \

OBJS_QUOTED += \
"./Generated_Code/BitIoLdd2.o" \
"./Generated_Code/Button1.o" \
"./Generated_Code/Cpu.o" \
"./Generated_Code/ExtIntLdd1.o" \
"./Generated_Code/LED_YELLOW.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/PWM1.o" \
"./Generated_Code/PwmLdd1.o" \
"./Generated_Code/TSS1.o" \
"./Generated_Code/TU1.o" \
"./Generated_Code/Vectors.o" \
"./Generated_Code/myLCD.o" \
"./Generated_Code/sw1.o" \

C_DEPS_QUOTED += \
"./Generated_Code/BitIoLdd2.d" \
"./Generated_Code/Button1.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/ExtIntLdd1.d" \
"./Generated_Code/LED_YELLOW.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/PWM1.d" \
"./Generated_Code/PwmLdd1.d" \
"./Generated_Code/TSS1.d" \
"./Generated_Code/TU1.d" \
"./Generated_Code/Vectors.d" \
"./Generated_Code/myLCD.d" \
"./Generated_Code/sw1.d" \

OBJS_OS_FORMAT += \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/Button1.o \
./Generated_Code/Cpu.o \
./Generated_Code/ExtIntLdd1.o \
./Generated_Code/LED_YELLOW.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PWM1.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/TSS1.o \
./Generated_Code/TU1.o \
./Generated_Code/Vectors.o \
./Generated_Code/myLCD.o \
./Generated_Code/sw1.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/BitIoLdd2.o: ../Generated_Code/BitIoLdd2.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/BitIoLdd2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/BitIoLdd2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Button1.o: ../Generated_Code/Button1.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Button1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Button1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/ExtIntLdd1.o: ../Generated_Code/ExtIntLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/ExtIntLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/ExtIntLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/LED_YELLOW.o: ../Generated_Code/LED_YELLOW.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/LED_YELLOW.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/LED_YELLOW.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PWM1.o: ../Generated_Code/PWM1.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PWM1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PWM1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PwmLdd1.o: ../Generated_Code/PwmLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PwmLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PwmLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TSS1.o: ../Generated_Code/TSS1.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TSS1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TSS1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TU1.o: ../Generated_Code/TU1.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TU1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TU1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/myLCD.o: ../Generated_Code/myLCD.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/myLCD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/myLCD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/sw1.o: ../Generated_Code/sw1.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/sw1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/sw1.o"
	@echo 'Finished building: $<'
	@echo ' '


