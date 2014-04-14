 /*
 * usb-joystick, (C) 2014 Juha Turunen
 * Adapted from "Keyboard example for Teensy USB Development Board"
 * http://www.pjrc.com/teensy/usb_keyboard.html
 * Copyright (c) 2008 PJRC.COM, LLC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "usb_keyboard.h"

#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))

int main(void)
{
	// set for 16 MHz clock
	CPU_PRESCALE(0);

    DDRF = 0x00;
    PORTF = 0xFF;

    usb_init();
    while (!usb_configured());

	_delay_ms(1000);


    while (1) {
        _delay_ms(15);

        keyboard_keys[0] = 0;
        keyboard_keys[1] = 0;
        keyboard_keys[2] = 0;
        keyboard_keys[3] = 0;
        keyboard_keys[4] = 0;

        if ((PINF & 1) == 0)        // pin F0, fire
            keyboard_keys[0] = KEY_SPACE;

        if ((PINF & 2) == 0)       // pin F1, up
            keyboard_keys[1] = KEY_UP;

        if ((PINF & 16) == 0)       // pin F4, right
            keyboard_keys[2] = KEY_RIGHT;

        if ((PINF & 32) == 0)       // pin F5, left
            keyboard_keys[3] = KEY_LEFT;

        if ((PINF & 64) == 0)       // pin F6, down
            keyboard_keys[4] = KEY_DOWN;
        usb_keyboard_send();
    }
}

