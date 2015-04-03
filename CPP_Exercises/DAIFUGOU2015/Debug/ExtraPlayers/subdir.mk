################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ExtraPlayers/ThinkTA1.cpp 

CC_SRCS += \
../ExtraPlayers/GroupB.cc \
../ExtraPlayers/GroupC.cc \
../ExtraPlayers/GroupH.cc 

OBJS += \
./ExtraPlayers/GroupB.o \
./ExtraPlayers/GroupC.o \
./ExtraPlayers/GroupH.o \
./ExtraPlayers/ThinkTA1.o 

CC_DEPS += \
./ExtraPlayers/GroupB.d \
./ExtraPlayers/GroupC.d \
./ExtraPlayers/GroupH.d 

CPP_DEPS += \
./ExtraPlayers/ThinkTA1.d 


# Each subdirectory must supply rules for building sources it contributes
ExtraPlayers/%.o: ../ExtraPlayers/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/sin/Documents/CPP_Exercises/DAIFUGOU2015" -I"/Users/sin/Documents/CPP_Exercises/DAIFUGOU2015/ExtraPlayers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ExtraPlayers/%.o: ../ExtraPlayers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/sin/Documents/CPP_Exercises/DAIFUGOU2015" -I"/Users/sin/Documents/CPP_Exercises/DAIFUGOU2015/ExtraPlayers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


