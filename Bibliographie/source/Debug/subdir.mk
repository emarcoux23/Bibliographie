################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Bibliographie.cpp \
../ContratException.cpp \
../Journal.cpp \
../Ouvrage.cpp \
../Reference.cpp \
../validationFormat.cpp 

OBJS += \
./Bibliographie.o \
./ContratException.o \
./Journal.o \
./Ouvrage.o \
./Reference.o \
./validationFormat.o 

CPP_DEPS += \
./Bibliographie.d \
./ContratException.d \
./Journal.d \
./Ouvrage.d \
./Reference.d \
./validationFormat.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++03 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


