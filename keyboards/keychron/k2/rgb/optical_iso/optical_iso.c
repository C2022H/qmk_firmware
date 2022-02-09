/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 * Copyright 2022 Dimitris Mantzouranis <d3xter93@gmail.com>
 * Copyright 2022 Harrison Chan (Xelus)
 * Copyright 2022 Pablo Ramirez <jp.ramangulo@gmail.com>
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

#include "optical_iso.h"

#define XX NO_LED

/* ISO keymap LEDs */
__attribute__ ((weak))
led_config_t g_led_config = {
  {
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15 },
    { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, XX, 30 },
    { 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, XX, XX, 44 },
    { 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, XX, 59 },
    { 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, XX, 72, 73, 74 },
    { 75, 76, 77, XX, XX, XX, 78, XX, XX, XX, 79, 80, 81, 82, 83, 84 }
  },
  {
    {7  , 0}, {21 , 0}, {35 , 0}, {49 , 0}, {63 , 0}, {77 , 0}, {91 , 0}, {105, 0}, {119, 0}, {133, 0}, {147, 0}, {161, 0}, {175, 0}, {189, 0}, {203, 0}, {217, 0},
    {7  ,13}, {21 ,13}, {35 ,13}, {49 ,13}, {63 ,13}, {77 ,13}, {91 ,13}, {105,13}, {119,13}, {133,13}, {147,13}, {161,13}, {175,13}, {196,13},           {217,13},
    {11 ,26}, {28 ,26}, {42 ,26}, {56 ,26}, {70 ,26}, {84 ,26}, {98 ,26}, {112,26}, {126,26}, {140,26}, {154,26}, {168,26}, {182,26},                     {217,26},
    {12 ,38}, {32 ,38}, {46 ,38}, {60 ,38}, {74 ,38}, {88 ,38}, {102,38}, {116,38}, {130,38}, {144,38}, {158,38}, {172,38}, {182,38}, {194,38},           {217,38},
    {9  ,51}, {26 ,51}, {39 ,51}, {53 ,51}, {67 ,51}, {81 ,51}, {95 ,51}, {109,51}, {123,51}, {137,51}, {151,51}, {165,51},           {184,51}, {203,51}, {217,51},
    {9  ,64}, {26 ,64}, {44 ,64},                               {97 ,64},                               {147,64}, {161,64}, {175,64}, {189,64}, {203,64}, {217,64},
  },
  {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,       4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 4,
    4, 4, 4,          4,          4, 4, 4, 4, 4, 4,
  }
};
