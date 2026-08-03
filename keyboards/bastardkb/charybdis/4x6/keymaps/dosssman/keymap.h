// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

enum dosssman_layers {
    /* General layout:
     * - mainly productivity, but can handle some gaming
     */
    DOS_GENERAL_BASE = 0,
    DOS_GENERAL_FUNCTION,
    DOS_GENERAL_CONTROL,

    /* RTS Optimized layout:
     * - Sacrifices desktop navigation to provide more access to control groups.
     * - Provides convenient Shift and Control positions for creating control groups.
     * - Replaces left-side mouse keys with mirrored right-side keys for more shortcut access.
     */
    DOS_RTS_BASE,
    DOS_RTS_FUNCTION,
    DOS_RTS_CONTROL,

    /* FPS Optimized layout:
     * - Replaces left-side mouse keys with mirrored right-side keys for more shortcut access.
     */
    DOS_FPS_BASE,
    DOS_FPS_FUNCTION,
    DOS_FPS_CONTROL
};

enum dosssman_keycodes {
    DOS_RGB_SOLID = QK_USER_0,
    DOS_RGB_BREATHE,
};
