cmake_minimum_required(VERSION 3.10)
project(L3_Task1.elf C)

# Create an executable for Task1
add_executable(${PROJECT_NAME} main.c)

# Include the driver script
include(${CMAKE_SOURCE_DIR}/Drivers.cmake)

# Add drivers to the target executable ( layer --> MCAL ------- drivers --> MDIO-MPORT )
add_drivers(${PROJECT_NAME}  "MCAL" "MDIO;MPORT")

# Link the .elf to the specific libraries it need
target_link_libraries(${PROJECT_NAME} PRIVATE MDIO MPORT)


set(TARGET_ELF "${CMAKE_BINARY_DIR}/bin/L3_Task1.elf")
set(TARGET_HEX "${CMAKE_BINARY_DIR}/bin/L3_Task1.hex")

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
    L3_Task1_hex_file ALL
    DEPENDS ${TARGET_HEX}
)
# Use this to flash
add_custom_target(
    flash_l3_task1
    COMMAND avrdude -p ${MCU} -c ${PROGRAMMER} -P ${USB_PORT} -b ${BaudRate} -U flash:w:${TARGET_HEX}:i
    DEPENDS Task1_hex_file
    COMMENT "Flashing HEX to hardware"
    VERBATIM
)