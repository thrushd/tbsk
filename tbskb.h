/* Copyright 2021 Dylan
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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT(                                                                       \
      L00, L01, L02, L03, L04, L05, L06, L07, R00, R01, R02, R03, R04, R05, R06, R07, \
      L10, L11, L12, L13, L14, L15, L16, L17, R10, R11, R12, R13, R14, R15, R16, R17, \
      L20, L21, L22, L23, L24, L25, L26, L27, R20, R21, R22, R23, R24, R25, R26, R27, \
      L30, L31, L32, L33, L34, L35, L36, L37, R30, R31, R32, R33, R34, R35, R36, R37, \
      L40, L41, L42, L43,                L47, R40,                R44, R45, R46, R47, \
                                    L56, L57,                                         \
                               L65, L66, L67                                          \
)                                                               \
{                                                               \
    { L00,   L01,   L02,   L03,   L04,   L05,   L06,   L07   }, \
    { L10,   L11,   L12,   L13,   L14,   L15,   L16,   L17   }, \
    { L20,   L21,   L22,   L23,   L24,   L25,   L26,   L27   }, \
    { L30,   L31,   L32,   L33,   L34,   L35,   L36,   L37   }, \
    { L40,   L41,   L42,   L43,   KC_NO, KC_NO, KC_NO, L47   }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, L56,   L57   }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, L65,   L66,   L67   }, \
    { R00,   R01,   R02,   R03,   R04,   R05,   R06,   R07   }, \
    { R10,   R11,   R12,   R13,   R14,   R15,   R16,   R17   }, \
    { R20,   R21,   R22,   R23,   R24,   R25,   R26,   R27   }, \
    { R30,   R31,   R32,   R33,   R34,   R35,   R36,   R37   }, \
    { R40,   KC_NO, KC_NO, KC_NO, R44,   R45,   R46,   R47   }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }  \
}

// below from https://github.com/qmk/qmk_firmware/blob/master/keyboards/oddball/oddball.h

#include "pmw/pmw.h"
#define config_optical_sensor_t config_pmw_t
#define report_optical_sensor_t report_pmw_t
#define optical_sensor_init pmw_init
#define optical_sensor_get_config pmw_get_config
#define optical_sensor_set_config pmw_set_config
#define optical_sensor_get_report pmw_get_report

enum custom_keycodes {
    KC_SCRL = SAFE_RANGE,
    KC_CPI1,
    KC_CPI2,
    KC_CPI3
};

typedef union {
  uint32_t raw;
  struct {
    uint16_t cpi;
  };
} config_oddball_t;
