/* Copyright 2021 IsaacDynamo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "white.h"
#include "config.h"

// Manage Windows and Mac LEDs
// - Show status of mode switch
// - Turn LEDs off durring USB suspend
static bool mode_leds_show = true;
static bool mode_leds_windows;

static void mode_leds_update(void) {
    writePin(LED_WIN_PIN, mode_leds_show && mode_leds_windows);
    writePin(LED_MAC_PIN, mode_leds_show && !mode_leds_windows);
}

bool dip_switch_update_kb(uint8_t index, bool active){
    if(index == 0) {
        if(active) { // Windows mode
            layer_move(WIN_BASE);
        } else { // Mac mode
            layer_move(MAC_BASE);
        }

        // Update mode and update leds
        mode_leds_windows = active;
        mode_leds_update();
    }

    dip_switch_update_user(index, active);
    return true;
}

void keyboard_pre_init_kb(void) {
    // Setup Win & Mac LED Pins as output
    setPinOutput(LED_WIN_PIN);
    setPinOutput(LED_MAC_PIN);
    writePinLow(LED_WIN_PIN);
    writePinLow(LED_MAC_PIN);

    // Set status leds pins
    setPinOutput(LED_NUM_LOCK_PIN);
    setPinOutput(LED_CAPS_LOCK_PIN);

    keyboard_pre_init_user();
}

void suspend_power_down_kb(void) {
    // Turn leds off
    mode_leds_show = false;
    mode_leds_update();

    // Suspend backlight
    led_matrix_set_suspend_state(true);

    suspend_power_down_user();
}

#define XX NO_LED

// Mark keys that are black with the default keychron keycaps.
// This is used but the custom rgb matrix effect to create a high contrast mode that only lights up black keys. To make them better readable.
#define B (128 | 4)

/// Force g_led_config into flash, because there is no space in RAM.
/// This should be safe because g_led_config should never be written to.
/// We cannot make g_led_config const, because rgb_matrix.h, exports it as mutable.
__attribute__(( section(".rodata.g_led_config") ))
led_config_t g_led_config = {
{
  {  XX,   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,  XX,  XX,  XX,  XX },
  {  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36 },
  {  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57 },
  {  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,  68,  69,  XX,  70,  XX,  XX,  XX,  71,  72,  73,  XX },
  {  74,  XX,  75,  76,  77,  78,  79,  80,  81,  82,  83,  84,  XX,  85,  XX,  86,  XX,  87,  88,  89,  90 },
  {  91,  92,  93,  XX,  XX,  94,  XX,  XX,  XX,  XX,  95,  96,  97,  98,  99, 100, 101, 102,  XX, 103,  XX }
}, {
                   { 2 *12, 0  }, { 3 *12, 0  }, { 4 *12, 0  }, { 5 *12, 0  }, { 6 *12, 0  }, { 7 *12, 0  }, { 8 *12, 0  }, { 9 *12, 0  }, { 10*12, 0  }, { 11*12, 0  }, { 12*12, 0  }, { 13*12, 0  }, { 14*12, 0  }, { 15*12, 0  }, { 16*12, 0  }, { 17*12, 0  },
    { 1 *12, 13 }, { 2 *12, 13 }, { 3 *12, 13 }, { 4 *12, 13 }, { 5 *12, 13 }, { 6 *12, 13 }, { 7 *12, 13 }, { 8 *12, 13 }, { 9 *12, 13 }, { 10*12, 13 }, { 11*12, 13 }, { 12*12, 13 }, { 13*12, 13 }, { 14*12, 13 }, { 15*12, 13 }, { 16*12, 13 }, { 17*12, 13 }, { 18*12, 13 }, { 19*12, 13 }, { 20*12, 13 }, { 21*12, 13 },
    { 1 *12, 26 }, { 2 *12, 26 }, { 3 *12, 26 }, { 4 *12, 26 }, { 5 *12, 26 }, { 6 *12, 26 }, { 7 *12, 26 }, { 8 *12, 26 }, { 9 *12, 26 }, { 10*12, 26 }, { 11*12, 26 }, { 12*12, 26 }, { 13*12, 26 }, { 14*12, 26 }, { 15*12, 26 }, { 16*12, 26 }, { 17*12, 26 }, { 18*12, 26 }, { 19*12, 26 }, { 20*12, 26 }, { 21*12, 26 },
    { 1 *12, 38 }, { 2 *12, 38 }, { 3 *12, 38 }, { 4 *12, 38 }, { 5 *12, 38 }, { 6 *12, 38 }, { 7 *12, 38 }, { 8 *12, 38 }, { 9 *12, 38 }, { 10*12, 38 }, { 11*12, 38 }, { 12*12, 38 },                { 14*12, 38 },                                              { 18*12, 38 }, { 19*12, 38 }, { 20*12, 38 },
    { 1 *12, 51 },                { 3 *12, 51 }, { 4 *12, 51 }, { 5 *12, 51 }, { 6 *12, 51 }, { 7 *12, 51 }, { 8 *12, 51 }, { 9 *12, 51 }, { 10*12, 51 }, { 11*12, 51 }, { 12*12, 51 },                { 14*12, 51 },                { 16*12, 51 },                { 18*12, 51 }, { 19*12, 51 }, { 20*12, 51 }, { 21*12, 51 },
    { 1 *12, 64 }, { 2 *12, 64 }, { 3 *12, 64 },                               { 6 *12, 64 },                                                             { 11*12, 64 }, { 12*12, 64 }, { 13*12, 64 }, { 14*12, 64 }, { 15*12, 64 }, { 16*12, 64 }, { 17*12, 64 }, { 18*12, 64 },                { 20*12, 64 }
}, {
      B, 4, 4, 4, 4, B, B, B, B, 4, 4, 4, 4, B, B, B,
   B, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, B, B, B, B, 4, 4, 4, 4,
   B, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, B, B, B, B, 4, 4, 4, 4,
   B, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    B,          4, 4, 4,
   B,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    B,    4,    4, 4, 4, 4,
   B, B, B,       4,             B, B, B, B, 4, 4, 4, 4,    4
}
};
