#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_5x6(
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_UNDERSCORE,
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOTE,
        KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_RIGHT_SHIFT,
        KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RIGHT_CTRL,
        KC_SPACE, KC_SPACE, KC_SPACE, KC_SPACE, KC_SPACE, KC_SPACE
    )
};
