################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../12231003/c++program/kadai7/babanuki1.cc \
../12231003/c++program/kadai7/babastate.cc \
../12231003/c++program/kadai7/cardset.cc 

OBJS += \
./12231003/c++program/kadai7/babanuki1.o \
./12231003/c++program/kadai7/babastate.o \
./12231003/c++program/kadai7/cardset.o 

CC_DEPS += \
./12231003/c++program/kadai7/babanuki1.d \
./12231003/c++program/kadai7/babastate.d \
./12231003/c++program/kadai7/cardset.d 


# Each subdirectory must supply rules for building sources it contributes
12231003/c++program/kadai7/%.o: ../12231003/c++program/kadai7/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


