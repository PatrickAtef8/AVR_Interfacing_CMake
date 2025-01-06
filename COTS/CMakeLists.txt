# This is the root CMakeLists.txt, the entry point of the project that sets up the build environment and include subdirectories
# Set minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(COTS LANGUAGES C)

# Set AVR Toolchain
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/avr-gcc-toolchain.cmake) # Set the toolchain to the .cmake file located in COTS directory
# Set output directories for the .elf and .hex to be in the bin directory in the build file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include the driver script
include(${CMAKE_SOURCE_DIR}/Drivers.cmake)

# Define the list of drivers for each layer
set(drivers "MDIO;MPORT")  # List of MCAL drivers
create_driver_libraries(MCAL "${drivers}")

# This tells CMake to add the directories that have their own CMakeLists.txt
add_subdirectory(APP/LAB2/Task1)
add_subdirectory(APP/LAB2/Task2)
add_subdirectory(APP/LAB3/Task1)
add_subdirectory(APP/SwitchLedTest_with_MPORT)

