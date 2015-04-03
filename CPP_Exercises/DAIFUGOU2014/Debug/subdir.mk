################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Card.o \
../CardSet.o \
../Dealer.o \
../GroupB.o \
../GroupC.o \
../GroupH.o \
../LittleThinkPlayer.o \
../Player.o \
../ThinkTA1.o \
../main.o 

CPP_SRCS += \
../ThinkDifferent.cpp 

CC_SRCS += \
../Card.cc \
../CardSet.cc \
../Dealer.cc \
../LittleThinkPlayer.cc \
../Player.cc \
../main.cc \
../taikai_main.cc 

OBJS += \
./Card.o \
./CardSet.o \
./Dealer.o \
./LittleThinkPlayer.o \
./Player.o \
./ThinkDifferent.o \
./main.o \
./taikai_main.o 

CC_DEPS += \
./Card.d \
./CardSet.d \
./Dealer.d \
./LittleThinkPlayer.d \
./Player.d \
./main.d \
./taikai_main.d 

CPP_DEPS += \
./ThinkDifferent.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/i/sin/DAIFUGOU2014/ExtraPlayers" -I"/home/i/sin/DAIFUGOU2014" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/i/sin/DAIFUGOU2014/ExtraPlayers" -I"/home/i/sin/DAIFUGOU2014" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


