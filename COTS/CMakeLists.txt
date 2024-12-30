# this is the root CMakeLists.txt, the entry point of the project that sets up the build environment and include subdirectories
###################################################################################
# Set minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project Name
project(COTS LANGUAGES C)

# Set AVR Toolchain
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/avr-gcc-toolchain.cmake) #set the toolchain to the .cmake file located in COTS directory
# Set output directories for the .elf and .hex to be in bin directory in the build file
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include the driver script
include(${CMAKE_SOURCE_DIR}/Drivers.cmake)

# Create MDIO library
create_driver_library(MDio MDIO)

# This tells cmake to add this directory that has CMakeLists.txt
add_subdirectory(APP/LABS/Task1)





