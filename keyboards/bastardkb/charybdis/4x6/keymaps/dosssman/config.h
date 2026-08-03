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
// Limit maximum brightness to keep power consumption reasonable, and avoid
// disconnects.
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64

// Rainbow swirl as startup mode.
// Charybdis' default
// #    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

// Slow swirl at startup.
#    define RGB_MATRIX_STARTUP_SPD 64 // Default: 32

// Startup values.
#    define RGB_MATRIX_STARTUP_HUE 0
#    define RGB_MATRIX_STARTUP_SAT 255
#    define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_STARTUP_HSV RGB_MATRIX_STARTUP_HUE, RGB_MATRIX_STARTUP_SAT, RGB_MATRIX_STARTUP_VAL

// Additional RGB profiles
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// Typing related RGB matrix setings
#    define ENABLE_RGB_MATRIX_SPLASH
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH

// dosssman's override: startup default
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_BREATHING

#endif  // RGB_MATRIX_ENABLE

/* Trackball angle adjustment override. */
#ifdef ROTATIONAL_TRANSFORM_ANGLE
    #undef ROTATIONAL_TRANSFORM_ANGLE
    #define ROTATIONAL_TRANSFORM_ANGLE -85
#endif

/** Invert X and Y axis on mouse reports overrides */
// #define POINTING_DEVICE_INVERT_X
// #define POINTING_DEVICE_INVERT_Y

// Mouse config overrides
#ifdef CHARYBDIS_MINIMUM_DEFAULT_DPI
    #undef CHARYBDIS_MINIMUM_DEFAULT_DPI
    #define CHARYBDIS_MINIMUM_DEFAULT_DPI 2100
#endif

#ifdef CHARYBDIS_DEFAULT_DPI_CONFIG_STEP
    #undef CHARYBDIS_DEFAULT_DPI_CONFIG_STEP
    #define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 300
#endif

#ifdef CHARYBDIS_MINIMUM_SNIPING_DPI
    #define CHARYBDIS_MINIMUM_SNIPING_DPI 300
#endif

#ifdef CHARYBDIS_SNIPING_DPI_CONFIG_STEP
    #undef CHARYBDIS_SNIPING_DPI_CONFIG_STEP
    #define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100
#endif

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
