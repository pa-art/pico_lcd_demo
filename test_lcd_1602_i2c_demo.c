/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
 * Modified by Pa@ART Feb.15, 2021
 *  - Driver functions for I2C LCD is separated from main function.
 *  - Driver functions are in lcd_1602_i2c_lib.c.
 */

#include <stdio.h>
#include <string.h>
#include "lcd_1602_i2c_lib.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"

int main() {

    // This example will use I2C0 on GPIO4 (SDA) and GPIO5 (SCL)
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);
    // Make the I2C pins available to picotool
    bi_decl( bi_2pins_with_func(4, 5, GPIO_FUNC_I2C));

    lcd_init();

    static uint8_t *message[] =
            {
                    "RP2040 by", "Raspberry Pi",
                    "A brand new", "microcontroller",
                    "Twin core M0", "Full C SDK",
                    "More power in", "your product",
                    "More beans", "than Heinz!"
            };

    while (1) {

        for (int m = 0; m < sizeof(message) / sizeof(message[0]); m += MAX_LINES) {
            for (int line = 0; line < MAX_LINES; line++) {
                lcd_set_cursor(line, (MAX_CHARS / 2) - strlen(message[m + line]) / 2);
                lcd_string(message[m + line]);
            }
            sleep_ms(2000);
            lcd_clear();
        }

    }

    return 0;
}
