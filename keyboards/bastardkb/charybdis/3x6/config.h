/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

/* Trackball angle adjustment. */
#define ROTATIONAL_TRANSFORM_ANGLE -25

/* Removes the outer columns and keyboard goes from left hand to right hand, rather than rows.*/
#define LAYOUT_SPLIT(\
    L01, L02, L03, L04, L05,\
    L11, L12, L13, L14, L15,\
    L21, L22, L23, L24, L25,\
    L33, L34, L31,\
    R00, R01, R02, R03, R04,\
    R10, R11, R12, R13, R14,\
    R20, R21, R22, R23, R24,\
    R31, R33\
)\
LAYOUT(\
    KC_NO, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, KC_NO,\
    KC_NO, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, KC_NO,\
    KC_NO, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, KC_NO,\
    L33, L34, L31,\
    R31, R33\
)
