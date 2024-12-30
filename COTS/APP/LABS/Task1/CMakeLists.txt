cmake_minimum_required(VERSION 3.10)
project(Task1.elf C)

# Create an executable for Task1
add_executable(${PROJECT_NAME} main.c)


# Include the driver script
include(${CMAKE_SOURCE_DIR}/Drivers.cmake)

# Add the MDIO driver as it will be used in this task
add_driver(${PROJECT_NAME} MDIO)

# Link Task1 with the MDio library
target_link_libraries(${PROJECT_NAME} PRIVATE MDio)


set(TARGET_ELF "${CMAKE_BINARY_DIR}/bin/Task1.elf")
set(TARGET_HEX "${CMAKE_BINARY_DIR}/bin/Task1.hex")

# Add a custom command to generate the .hex file
add_custom_command(
    OUTPUT ${TARGET_HEX}
    COMMAND avr-objcopy -O ihex ${TARGET_ELF} ${TARGET_HEX}
    DEPENDS ${TARGET_ELF}  # Ensures .elf is built before .hex
    COMMENT "Converting ELF to HEX"
    VERBATIM
)

# Add a custom target for the .hex file
add_custom_target(
    hex_file ALL
    DEPENDS ${TARGET_HEX}
)

add_custom_target(
    flash
    COMMAND avrdude -p ${MCU} -c ${PROGRAMMER} -P ${USB_PORT} -b ${BaudRate} -U flash:w:${TARGET_HEX}:i
    DEPENDS hex_file
    COMMENT "Flashing HEX to hardware"
    VERBATIM
)
