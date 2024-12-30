# avr-gcc-toolchain.cmake
set(CMAKE_SYSTEM_NAME Generic)

set(MCU atmega32) 	# to choose your mcu
set(PROGRAMMER usbasp) # to set the programmer if changed
set(USB_PORT /dev/ttyUSB0) # to set the USB port that you are connecting
set(BaudRate 9600) # to specify the baud rate



# Set the cross-compilers
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)

# Set the assembler and linker
set(CMAKE_ASM_COMPILER avr-as)
set(CMAKE_LINKER avr-ld)
set(CMAKE_AR avr-ar)
set(CMAKE_OBJCOPY avr-objcopy)
set(CMAKE_OBJDUMP avr-objdump)

# Set the target MCU and the compiler flags
set(CMAKE_C_FLAGS "-mmcu=atmega32")
set(CMAKE_CXX_FLAGS "-mmcu=atmega32")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=atmega32")
