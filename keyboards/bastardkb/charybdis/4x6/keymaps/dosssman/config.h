/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#define EE_HANDS

/* RGB Matrix. */

#ifdef RGB_MATRIX_ENABLE
// Limit maximum brightness to keep power consumption reasonable and avoid
// disconnects.
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64

// Defaults used after an EEPROM reset. Layer changes are applied at runtime in
// config.c without writing to EEPROM.
#    undef RGB_MATRIX_DEFAULT_MODE
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING
#    undef RGB_MATRIX_DEFAULT_HUE
#    define RGB_MATRIX_DEFAULT_HUE 128 // Cyan
#    undef RGB_MATRIX_DEFAULT_SAT
#    define RGB_MATRIX_DEFAULT_SAT 255
#    undef RGB_MATRIX_DEFAULT_VAL
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    undef RGB_MATRIX_DEFAULT_SPD
#    define RGB_MATRIX_DEFAULT_SPD 64

// The keyboard definition enables every RGB Matrix animation. Keep the five
// effects used by this keymap and discard the rest to leave enough flash space
// for the additional FPS layers. SOLID_COLOR is always available.
#    undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#    undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    undef ENABLE_RGB_MATRIX_BAND_SAT
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    undef ENABLE_RGB_MATRIX_CYCLE_ALL
#    undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    undef ENABLE_RGB_MATRIX_DUAL_BEACON
#    undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    undef ENABLE_RGB_MATRIX_RAINDROPS
#    undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    undef ENABLE_RGB_MATRIX_HUE_BREATHING
#    undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#    undef ENABLE_RGB_MATRIX_HUE_WAVE
#    undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#    undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#    undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#    undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    undef ENABLE_RGB_MATRIX_MULTISPLASH
#    undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#endif  // RGB_MATRIX_ENABLE

/* Trackball angle adjustment override. */
#ifdef ROTATIONAL_TRANSFORM_ANGLE
    #undef ROTATIONAL_TRANSFORM_ANGLE
    #define ROTATIONAL_TRANSFORM_ANGLE -85
#endif

/** Invert X and Y axis on mouse reports overrides */
// #define POINTING_DEVICE_INVERT_X
// #define POINTING_DEVICE_INVERT_Y

// Mouse config overrides. These must be defined before charybdis.c supplies
// its fallback values.
#undef CHARYBDIS_MINIMUM_DEFAULT_DPI
#define CHARYBDIS_MINIMUM_DEFAULT_DPI 2100

#undef CHARYBDIS_DEFAULT_DPI_CONFIG_STEP
#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 300

#undef CHARYBDIS_MINIMUM_SNIPING_DPI
#define CHARYBDIS_MINIMUM_SNIPING_DPI 300

#undef CHARYBDIS_SNIPING_DPI_CONFIG_STEP
#define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100

// Charybdis custom keycodes extension for drag scroll and sniping modeS
/*
    I use QMK Configurator tool to design the layout. As of this writing, it does not
    seem to support custom keycodes.
    To use custom keycodes, we thus have to overwrite the keycodes in the JSON file
    to use our custom keycode. As it is confusing to edit the "raw" JSON files, I use
    F24, F23, etc... when configuring the layout on QMK config.
    Once the JSON file is generated and saved, I can then look for the "F24" key,
    then change it to a custom keycode, before genearting the "keymap.c" file, then
    flashing to the keyboard.

    The key codes are as follow:

    #define DPI_MOD POINTER_DEFAULT_DPI_FORWARD
    #define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
    #define S_D_MOD POINTER_SNIPING_DPI_FORWARD
    #define S_D_RMOD POINTER_SNIPING_DPI_REVERSE
    #define SNIPING SNIPING_MODE
    #define SNP_TOG SNIPING_MODE_TOGGLE
    #define DRGSCRL DRAGSCROLL_MODE
    #define DRG_TOG DRAGSCROLL_MODE_TOGGLE

    As of this writing:
    F24 -> DRGSCRL
    F23 -> DPI_MOD
    F22 -> S_D_MOD // SNIPING DPI FORWARD mode
    F21 -> SNP_TOG

    Note that for the DPI change, the "increase" command is set by default,
    but it suffices to hold "Shift" key while pressing that key to send the
    "decrease" command.

*/
