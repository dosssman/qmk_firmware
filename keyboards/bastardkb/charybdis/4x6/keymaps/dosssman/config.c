// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap.h"

#define LAYER_EFFECT_SPEED 64

static void set_layer_color(layer_state_t state) {
    const uint8_t active_layer = get_highest_layer(state | default_layer_state);

    switch (active_layer) {
        case DOS_RTS_BASE ... DOS_RTS_CONTROL:
            rgb_matrix_sethsv_noeeprom(HSV_SPRINGGREEN);
            break;

        case DOS_FPS_BASE ... DOS_FPS_CONTROL:
            rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            break;

        case DOS_GENERAL_BASE ... DOS_GENERAL_CONTROL:
        default:
            rgb_matrix_sethsv_noeeprom(HSV_CYAN);
            break;
    }
}

static void apply_layer_rgb(layer_state_t state) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
    rgb_matrix_set_speed_noeeprom(LAYER_EFFECT_SPEED);
    set_layer_color(state);
}

void keyboard_post_init_user(void) {
    apply_layer_rgb(layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    apply_layer_rgb(state);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case DOS_RGB_SOLID:
            rgb_matrix_enable_noeeprom();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            set_layer_color(layer_state);
            return false;

        case DOS_RGB_BREATHE:
            rgb_matrix_enable_noeeprom();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            set_layer_color(layer_state);
            return false;

        default:
            return true;
    }
}
