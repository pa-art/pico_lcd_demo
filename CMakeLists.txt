cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(test_project)

pico_sdk_init()

add_executable(test_lcd_1602_i2c_demo
        test_lcd_1602_i2c_demo.c lcd_1602_i2c_lib.c
        )

# Pull in our (to be renamed) simple get you started dependencies
target_link_libraries(test_lcd_1602_i2c_demo pico_stdlib hardware_i2c)

# create map/bin/hex file etc.
pico_add_extra_outputs(test_lcd_1602_i2c_demo)

pico_enable_stdio_usb(test_lcd_1602_i2c_demo 1)

pico_enable_stdio_uart(test_lcd_1602_i2c_demo 1)
