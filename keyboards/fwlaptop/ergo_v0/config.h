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

#pragma once

#include "config_common.h"

/* Key matrix configuration. */
#define MATRIX_COLS 12 // 6 for each side
#define MATRIX_ROWS 10 // 5 for each side

#define MATRIX_COL_PINS { B0, F4, F5, F6, F7, B1, D7, C6, D4, D0, D1, D3 }
#define MATRIX_ROW_PINS { B3, B2, B6, F0, F1, E6, B4, B5, B7, D5 }

#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed. */
#define DEBOUNCE 5
