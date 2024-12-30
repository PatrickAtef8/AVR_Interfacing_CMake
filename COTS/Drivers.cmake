# Macro to add a driver (source + include directory) to the library or target
macro(add_driver target_name driver_name)
    # set paths to the driver source and include directory in two variables
    set(driver_src "${CMAKE_SOURCE_DIR}/MCAL/MDIO/src/${driver_name}.c")
    set(driver_src_cfg "${CMAKE_SOURCE_DIR}/MCAL/MDIO/src/${driver_name}_cfg.c")
    set(driver_inc "${CMAKE_SOURCE_DIR}/MCAL/MDIO/inc")
    set(Common_inc "${CMAKE_SOURCE_DIR}/Common")

    # Add the source file and include directory to the specified target for driver and common directories
    target_sources(${target_name} PRIVATE ${driver_src})
    target_sources(${target_name} PRIVATE ${driver_src_cfg})
    target_include_directories(${target_name} PRIVATE ${driver_inc})
    target_include_directories(${target_name} PRIVATE ${driver_inc} ${Common_inc})
endmacro()

# Another macro to create a static library for the drivers
macro(create_driver_library lib_name driver_name)
    # Create the static library
    add_library(${lib_name} STATIC)
    
    # Add all drivers to the wanted library
    add_driver(${lib_name} ${driver_name})
endmacro()