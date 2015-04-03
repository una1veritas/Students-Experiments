################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
/home/i/sin/Studex2013ab/Group_C/GroupC.cc 

OBJS += \
./Group_C/GroupC.o 

CC_DEPS += \
./Group_C/GroupC.d 


# Each subdirectory must supply rules for building sources it contributes
Group_C/GroupC.o: /home/i/sin/Studex2013ab/Group_C/GroupC.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/i/sin/DAIHUGOU2013" -I"/home/i/sin/Studex2013ab/Group_A" -I"/home/i/sin/Studex2013ab/Group_B" -I"/home/i/sin/Studex2013ab/Group_C" -I"/home/i/sin/Studex2013ab/Group_D" -I"/home/i/sin/Studex2013ab/Group_E" -I"/home/i/sin/Studex2013ab/Group_F" -I"/home/i/sin/Studex2013ab/Group_G" -I"/home/i/sin/Studex2013ab/Group_H" -I"/home/i/sin/Studex2013ab/Group_I" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


