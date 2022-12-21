/*
 * Copyright 2022 Rousslan Fernand Julien Dossa <dosssman@hotmail.fr> (@RousslanDossa)
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

#define LTK(x) LT(x, KC_NO)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
    // ╭────────────────────────────────────────────────────────╮      ╭──────────────────────────────────────────────────────────────╮
           KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS,
    // ├─────────────────────────────────────────────────────────├       ├──────────────────────────────────────────────────────────────┤
           KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_QUOT,
    // ├─────────────────────────────────────────────────────────├       ├──────────────────────────────────────────────────────────────┤
           KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN,    KC_RSFT,
    // ├─────────────────────────────────────────────────────────┤       ├──────────────────────────────────────────────────────────────┤
           KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH,    KC_RCTL,
    // ├─────────────────────────────────────────────────────────┤       ├──────────────────────────────────────────────────────────────┤
                   KC_LALT, KC_LGUI,  LTK(1),  KC_SPC,    KC_NO,            KC_BSPC,  KC_ENT,  LTK(1), KC_RALT,   KC_NO
    //╰─────────────────────────────────────────────────────────╯      ╰─────────────────────────────────────────────────────────────╯
    ),
    [1] = LAYOUT(
    // ╭────────────────────────────────────────────────────────╮      ╭──────────────────────────────────────────────────────────────╮
           KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    KC_F11,
    // ├─────────────────────────────────────────────────────────├       ├──────────────────────────────────────────────────────────────┤
           KC_GRV, KC_BTN4, KC_BTN2,   KC_UP, KC_BTN1, KC_LBRC,             KC_LBRC, KC_BTN1, KC_BTN3, KC_BTN2, KC_TRNS,    KC_EQL,
    // ├─────────────────────────────────────────────────────────├       ├──────────────────────────────────────────────────────────────┤
          KC_TRNS, KC_BTN3, KC_LEFT, KC_DOWN,KC_RIGHT,   KC_NO,             KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_BSLS,   KC_TRNS,
    // ├─────────────────────────────────────────────────────────┤       ├──────────────────────────────────────────────────────────────┤
          KC_TRNS, KC_BTN5, KC_PGDN,  KC_DOT, KC_PGUP, KC_HOME,              KC_END, KC_LALT,  KC_SPC,   KC_NO,   KC_NO,   KC_TRNS,
    // ├─────────────────────────────────────────────────────────┤       ├──────────────────────────────────────────────────────────────┤
                     KC_NO, KC_TRNS,   KC_NO,  LTK(2),   KC_NO,              KC_DEL,  LTK(2),   KC_NO, KC_RALT,   KC_NO
    //╰─────────────────────────────────────────────────────────╯      ╰─────────────────────────────────────────────────────────────╯
    ),
    [2] = LAYOUT(
    // ╭────────────────────────────────────────────────────────╮      ╭──────────────────────────────────────────────────────────────╮
            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,               KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   EE_CLR,
    // ├─────────────────────────────────────────────────────────├       ├──────────────────────────────────────────────────────────────┤
          KC_CAPS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,               KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
    // ├─────────────────────────────────────────────────────────├       ├──────────────────────────────────────────────────────────────┤
          KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,               KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_TRNS,
    // ├─────────────────────────────────────────────────────────┤       ├──────────────────────────────────────────────────────────────┤
          KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,               KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_TRNS,
    // ├─────────────────────────────────────────────────────────┤       ├──────────────────────────────────────────────────────────────┤
                     KC_NO,   KC_NO,   KC_NO,   KC_NO, QK_BOOT,             QK_BOOT,  KC_NO,   KC_NO,   KC_NO,    KC_NO
    //╰─────────────────────────────────────────────────────────╯      ╰─────────────────────────────────────────────────────────────╯
    )
};
// clang-format on
