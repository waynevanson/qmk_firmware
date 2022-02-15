/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#define ORYX_CONFIGURATOR
#define ONESHOT_TAP_TOGGLE 2 /* Tapping this number of times holds the key until tapped once again. */
#define TAPPING_TOGGLE 1

#define KC_LEFT_ARROW LSFT(KC_COMMA)
#define KC_LARW KC_LEFT_ARROW

#define XXX KC_NO

#define LAYOUT_wayne(\
    K00, K01, K02, K03, K04,        K05, K06, K07, K08, K09,\
    K10, K11, K12, K13, K14,        K15, K16, K17, K18, K19,\
    K20, K21, K22, K23, K24,        K25, K26, K27, K28, K29,\
    K30, K31,      K32, K33,        K34, K35,      K36, K37\
)\
LAYOUT_moonlander(\
    XXX, XXX, XXX, XXX, XXX, XXX, XXX,        XXX, XXX, XXX, XXX, XXX, XXX, XXX,\
    XXX, XXX, K01, K02, K03, K04, XXX,        XXX, K05, K06, K07, K08, XXX, XXX,\
    K30, K00, K11, K12, K13, K14, XXX,        XXX, K15, K16, K17, K18, K09, K37,\
    K31, K10, K21, K22, K23, K24,                  K25, K26, K27, K28, K19, K37,\
    XXX, K20, XXX, XXX, XXX,      XXX,        XXX,      XXX, XXX, XXX, K29, XXX,\
                        K32, K33, XXX,        XXX, K34, K35\
)
