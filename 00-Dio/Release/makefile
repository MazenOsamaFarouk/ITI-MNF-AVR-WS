################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
00-Dio.lss \

FLASH_IMAGE += \
00-Dio.hex \

EEPROM_IMAGE += \
00-Dio.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 00-Dio.elf secondary-outputs

# Tool invocations
00-Dio.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,00-Dio.map -mmcu=atmega32 -o "00-Dio.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

00-Dio.lss: 00-Dio.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 00-Dio.elf  >"00-Dio.lss"
	@echo 'Finished building: $@'
	@echo ' '

00-Dio.hex: 00-Dio.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 00-Dio.elf  "00-Dio.hex"
	@echo 'Finished building: $@'
	@echo ' '

00-Dio.eep: 00-Dio.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 00-Dio.elf  "00-Dio.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 00-Dio.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 00-Dio.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 00-Dio.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
