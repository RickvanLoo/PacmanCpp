################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Game.cpp \
../src/GameObject.cpp \
../src/Movable.cpp \
../src/Pacman.cpp \
../src/UI.cpp \
../src/main.cpp 

OBJS += \
./src/Game.o \
./src/GameObject.o \
./src/Movable.o \
./src/Pacman.o \
./src/UI.o \
./src/main.o 

CPP_DEPS += \
./src/Game.d \
./src/GameObject.d \
./src/Movable.d \
./src/Pacman.d \
./src/UI.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


