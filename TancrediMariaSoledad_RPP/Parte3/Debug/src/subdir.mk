################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Duenio.c \
../src/EstadiaDiaria.c \
../src/Fecha.c \
../src/Inputs.c \
../src/Nexo.c \
../src/Parte3.c \
../src/Perros.c 

OBJS += \
./src/Duenio.o \
./src/EstadiaDiaria.o \
./src/Fecha.o \
./src/Inputs.o \
./src/Nexo.o \
./src/Parte3.o \
./src/Perros.o 

C_DEPS += \
./src/Duenio.d \
./src/EstadiaDiaria.d \
./src/Fecha.d \
./src/Inputs.d \
./src/Nexo.d \
./src/Parte3.d \
./src/Perros.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


