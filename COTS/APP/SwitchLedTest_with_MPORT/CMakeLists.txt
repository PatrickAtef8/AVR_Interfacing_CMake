cmake_minimum_required(VERSION 3.10)
project(SW_LED_TEST.elf C)

# Create an executable for Task1
add_executable(${PROJECT_NAME} main.c)

include(${CMAKE_SOURCE_DIR}/Drivers.cmake)

# Add drivers to the target executable ( layer --> MCAL ------- drivers --> MDIO-MPORT )
add_drivers(${PROJECT_NAME}  "MCAL" "MDIO;MPORT")

# Include sources and includes of the HAL layer 
target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/HAL/LED/src/LED.c ${CMAKE_SOURCE_DIR}/HAL/LED/src/LED_cfg.c)
target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/HAL/SWITCH/src/SWITCH.c ${CMAKE_SOURCE_DIR}/HAL/SWITCH/src/SWITCH_cfg.c)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/HAL/LED/inc ${Common_inc})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/HAL/SWITCH/inc)

# Link the .elf to the specific libraries it need
target_link_libraries(${PROJECT_NAME} PRIVATE MDIO MPORT)

set(TARGET_ELF "${CMAKE_BINARY_DIR}/bin/SW_LED_TEST.elf")
set(TARGET_HEX "${CMAKE_BINARY_DIR}/bin/SW_LED_TEST.hex")

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
    SW_LED_TEST_hex_file ALL
    DEPENDS ${TARGET_HEX}
)

add_custom_target(
    SW_LED_TEST_flash_task1
    COMMAND avrdude -p ${MCU} -c ${PROGRAMMER} -P ${USB_PORT} -b ${BaudRate} -U flash:w:${TARGET_HEX}:i
    DEPENDS SW_LED_TEST_hex_file
    COMMENT "Flashing HEX to hardware"
    VERBATIM
)
