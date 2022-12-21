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

#include "quantum.h"

#define kNO KC_NO

// clang-format off
#define LAYOUT( \
    k00, k01, k02, k03, k04, k05,    k29, k30, k31, k32, k33, k34,  \
    k06, k07, k08, k09, k10, k11,    k35, k36, k37, k38, k39, k40,  \
    k12, k13, k14, k15, k16, k17,    k41, k42, k43, k44, k45, k46,  \
    k18, k19, k20, k21, k22, k23,    k47, k48, k49, k50, k51, k52,  \
         k24, k25, k26, k27, k28,    k53, k54, k55, k56, k57        \
) \
{ \
    /* Left side */                                                 \
    {k00, k01, k02, k03, k04, k05,   kNO, kNO, kNO, kNO, kNO, kNO}, \
    {k06, k07, k08, k09, k10, k11,   kNO, kNO, kNO, kNO, kNO, kNO}, \
    {k12, k13, k14, k15, k16, k17,   kNO, kNO, kNO, kNO, kNO, kNO}, \
    {k18, k19, k20, k21, k22, k23,   kNO, kNO, kNO, kNO, kNO, kNO}, \
    {kNO, k24, k25, k26, k27, k28,   kNO, kNO, kNO, kNO, kNO, kNO}, \
    /* Right side  */                                               \
    {kNO, kNO, kNO, kNO, kNO, kNO,   k29, k30, k31, k32, k33, k34}, \
    {kNO, kNO, kNO, kNO, kNO, kNO,   k35, k36, k37, k38, k39, k40}, \
    {kNO, kNO, kNO, kNO, kNO, kNO,   k41, k42, k43, k44, k45, k46}, \
    {kNO, kNO, kNO, kNO, kNO, kNO,   k47, k48, k49, k50, k51, k52}, \
    {kNO, kNO, kNO, kNO, kNO, kNO,   k53, k54, k55, k56, k57, kNO}  \
}
// clang-format on
