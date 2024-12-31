# AVR_Interfacing_CMake 
## Interfacing AVR driver using CMake
### Project tree
 <img src="/COTS/tree.png" alt="My Photo" /> 

 ### I applied CMake in this project in a way that it will be generic, that means that anytime you finished or wrote a driver, all you need to do is just add it, you don't need to write CMakeLists.txt for every driver you make  

## Steps for adding new driver 
1. Open the Root CMakeLists.txt and call the macro **"create_driver_library(libraryNameYouWant Driver)"** to create your library for your new driver 
2. Open the Task CMakeLists.txt and call the macro **"add_driver(ExecutableProjectNameYouWant Driver)"**
      - Please take care of naming, Try to be all UPPERCASE as MDIO,ADC,UART,..... even the inc/src contents as MDIO.h,MDIO.c
##
## How to build? 
- cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=~/COTS/avr-gcc-toolchain.cmake
- cmake --build build 
## For flashing "Check Task1 CMakeLists.txt"
cmake --build build --target flash 
