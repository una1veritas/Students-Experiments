################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ThinkTA1.cpp 

CC_SRCS += \
../Card.cc \
../CardSet.cc \
../Dealer.cc \
../LittleThinkPlayer.cc \
../Player.cc \
../competition.cc 

OBJS += \
./Card.o \
./CardSet.o \
./Dealer.o \
./LittleThinkPlayer.o \
./Player.o \
./ThinkTA1.o \
./competition.o 

CC_DEPS += \
./Card.d \
./CardSet.d \
./Dealer.d \
./LittleThinkPlayer.d \
./Player.d \
./competition.d 

CPP_DEPS += \
./ThinkTA1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/i/sin/DAIHUGOU2013" -I"/home/i/sin/Studex2013ab/Group_A" -I"/home/i/sin/Studex2013ab/Group_B" -I"/home/i/sin/Studex2013ab/Group_C" -I"/home/i/sin/Studex2013ab/Group_D" -I"/home/i/sin/Studex2013ab/Group_E" -I"/home/i/sin/Studex2013ab/Group_F" -I"/home/i/sin/Studex2013ab/Group_G" -I"/home/i/sin/Studex2013ab/Group_H" -I"/home/i/sin/Studex2013ab/Group_I" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/i/sin/DAIHUGOU2013" -I"/home/i/sin/Studex2013ab/Group_A" -I"/home/i/sin/Studex2013ab/Group_B" -I"/home/i/sin/Studex2013ab/Group_C" -I"/home/i/sin/Studex2013ab/Group_D" -I"/home/i/sin/Studex2013ab/Group_E" -I"/home/i/sin/Studex2013ab/Group_F" -I"/home/i/sin/Studex2013ab/Group_G" -I"/home/i/sin/Studex2013ab/Group_H" -I"/home/i/sin/Studex2013ab/Group_I" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


