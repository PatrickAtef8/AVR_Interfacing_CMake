# AVR_Interfacing_CMake 
## Interfacing AVR driver using CMake
### Project tree
├── COTS
│   ├── APP
│   │   ├── LAB1
│   │   ├── LAB2
│   │   │   ├── Task1
│   │   │   │   ├── CMakeLists.txt
│   │   │   │   └── main.c
│   │   │   └── Task2
│   │   │       ├── CMakeLists.txt
│   │   │       └── main.c
│   │   ├── LAB3
│   │   │   └── Task1
│   │   │       ├── CMakeLists.txt
│   │   │       └── main.c
│   │   └── SwitchLedTest_with_MPORT
│   │       ├── CMakeLists.txt
│   │       └── main.c
│   ├── avr-gcc-toolchain.cmake
│   ├── CMakeLists.txt
│   ├── Common
│   │   ├── BIT_MATH.h
│   │   ├── MemMap.h
│   │   └── STD_TYPES.h
│   ├── Drivers.cmake
│   ├── HAL
│   │   ├── LED
│   │   │   ├── inc
│   │   │   │   ├── LED_cfg.h
│   │   │   │   └── LED.h
│   │   │   └── src
│   │   │       ├── LED.c
│   │   │       └── LED_cfg.c
│   │   └── SWITCH
│   │       ├── inc
│   │       │   ├── SWITCH_cfg.h
│   │       │   └── SWITCH.h
│   │       └── src
│   │           ├── SWITCH.c
│   │           └── SWITCH_cfg.c
│   ├── MCAL
│   │   ├── MDIO
│   │   │   ├── inc
│   │   │   │   ├── MDIO_cfg.h
│   │   │   │   └── MDIO.h
│   │   │   └── src
│   │   │       ├── MDIO.c
│   │   │       └── MDIO_cfg.c
│   │   └── MPORT
│   │       ├── inc
│   │       │   ├── MPORT_cfg.h
│   │       │   └── MPORT.h
│   │       └── src
│   │           ├── MPORT.c
│   │           └── MPORT_cfg.c
│   ├── STD_LIB
│   └── tree.png
└── README.md

 ### I applied CMake in this project in a way that it will be generic, that means that anytime you finished or wrote a driver, all you need to do just add it, you don't need to write CMakeLists.txt for every driver you will make 😉✌️ 
## Steps for adding new driver 
1. Open the Root CMakeLists.txt then create your driver
    - set(drivers "MDIO;MPORT;ExampleDriver1;ExampleDriver2")
    - create_driver_libraries(MCAL "${drivers}")
2. Open the Task CMakeLists.txt and add the drivers you will use in this task
    - **add_drivers(${PROJECT_NAME}  "MCAL" "MDIO;MPORT;ExampleDriver1;ExampleDriver2")**
    - **target_link_libraries(${PROJECT_NAME} PRIVATE MDIO MPORT ExampleDriver1 ExampleDriver2)**
    
**Please take care of naming, Try to be all UPPERCASE as MDIO,ADC,UART,..... even the inc/src contents as MDIO.h,MDIO.c**
##
## How to build? 
- cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=~/COTS/avr-gcc-toolchain.cmake
- cmake --build build 
##
## For flashing "Check Task CMakeLists.txt"
- For example if you want to flash the hex of Task1 in LAB2
   cmake --build build --target flash_l2_task1 