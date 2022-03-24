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
#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _MO, // mouse
    _FU  // function keys
};

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//     QMKBEST = SAFE_RANGE,
//     QMKURL
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT( \
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,  KC_PSCR,     KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,  KC_INS,      KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_P0,   \
        KC_LCAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_END,      KC_BSLS, KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_PGUP, KC_PGDN,     _______, TG(_MO), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
        KC_LCTL, KC_LWIN, _______, KC_LALT,                            KC_UP,       KC_MPLY,                            KC_RALT, KC_LEFT, KC_RGHT, KC_RCTL, \
                                                              TG(_MO), KC_SPC,                                                                          \
                                                     KC_MUTE, MO(_FU), KC_DOWN                                                                          \
    ),

    /* Mouse */
    [_MO] = LAYOUT( \
         _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, \
         _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_CPI1, KC_CPI2, KC_CPI3, _______, _______, \
         _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, KC_SCRL, _______, \
         _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_WBAK, KC_WFWD, _______, _______, _______, \
         _______, _______, _______, _______,                   _______, _______,                                         _______, _______, _______, _______, \
                                                               _______, _______,                                                                             \
                                                      _______, _______, _______                                                                              \
    ),

    /* Function */
    [_FU] = LAYOUT( \
         RESET,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
         _______, _______, _______, _______, _______, RGB_M_R, RGB_HUI, RGB_HUD,     _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______, \
         _______, _______, KC_SLEP, _______, _______, RGB_TOG, RGB_SAI, RGB_SAD,     _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, \
         _______, _______, _______, _______, _______, RGB_M_P, RGB_VAI, RGB_VAD,     _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, \
         _______, _______, _______, _______,                   _______, _______,                                         KC_P0,   KC_PDOT, KC_PPLS, _______, \
                                                               _______, _______,                                                                             \
                                                      _______, _______, _______                                                                              \
    )
};

/* Template layer */
/*[_TEMPLATE] = LAYOUT( \
     _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, \
     _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, \
     _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, \
     _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, \
     _______, _______, _______, _______,                   _______, _______,                                _______, _______, _______, _______,          \
                                                           _______, _______,                                                                             \
                                                  _______, _______, _______                                                                              \
)*/


void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code16(C(KC_TAB));
        } else {
            tap_code16(S(C(KC_TAB)));
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case QMKBEST:
//             if (record->event.pressed) {
//                 // when keycode QMKBEST is pressed
//                 SEND_STRING("QMK is the best thing ever!");
//             } else {
//                 // when keycode QMKBEST is released
//             }
//             break;
//         case QMKURL:
//             if (record->event.pressed) {
//                 // when keycode QMKURL is pressed
//                 SEND_STRING("https://qmk.fm/\n");
//             } else {
//                 // when keycode QMKURL is released
//             }
//             break;
//     }
//     return true;
// }
