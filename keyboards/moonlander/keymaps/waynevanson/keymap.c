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

#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB_NUM,  // symbols
    MDIA,  // media keys
    SWAG
};

// CTRL, SHIFT, ALT, GUI
enum custom_keycodes {
    KC_EDOT,
    KC_QCOM
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_wayne(
        KC_Q,   KC_D,   KC_R,   KC_W,   KC_B,               KC_J,   KC_F,   KC_U,       KC_P,       KC_SEMICOLON,
        KC_A,   KC_S,   KC_H,   KC_T,   KC_G,               KC_Y,   KC_N,   KC_E,       KC_O,       KC_I,
        KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,               KC_K,   KC_L,   KC_QCOM,    KC_EDOT,    KC_QUOTE,

        OSM(MOD_LCTL),  OSM(MOD_LSFT),  KC_SPC, TT(SYMB_NUM),
        TT(MDIA),       KC_ENT,         OSM(MOD_RGUI),  OSM(MOD_RALT)
    ),

    // [BASE] = LAYOUT_moonlander(
    //     KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    //     KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    //     KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), LGUI_T(KC_QUOT),
    //     KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    // LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
    //                                         KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    // ),

    //  numpad and symbols
    [SYMB_NUM] = LAYOUT_wayne(
        XXX,            XXX,            XXX,        XXX,            XXX,                XXX,    KC_7,   KC_8,   KC_9,   XXX,
        KC_PIPE,        KC_LARW,        RSFT(KC_9), RSFT(KC_LBRC),  KC_LBRC,            XXX,    KC_4,   KC_5,   KC_6,   XXX,
        KC_AMPERSAND,   RSFT(KC_DOT),   RSFT(KC_0), RSFT(KC_RBRC),  KC_RBRC,            XXX,    KC_1,   KC_2,   KC_3,   KC_0,
        XXX, XXX, XXX,TO(BASE),
        XXX,TT(SWAG), XXX,XXX
    ),

    [MDIA] = LAYOUT_moonlander(
        RESET,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, KC_BSPC, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, TO(BASE), _______
    ),

    [SWAG] = LAYOUT_moonlander(
        _______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,       _______,_______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,KC_BSPC,_______,                    _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,            _______,    _______,        _______,_______,_______,_______,_______,

                                            _______,OSL(BASE),_______,            _______,_______,_______
    )
};
uint8_t mod_state;
// todo - if shift + . = !, if shift + , = ?
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods() | get_oneshot_mods();

    switch (keycode) {
        // period, or exclamation mark on shift
        case KC_EDOT:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    register_code(KC_1);
                } else {
                    register_code(KC_DOT);
                }
            } else {
                unregister_code(KC_1);
                unregister_code(KC_DOT);
            }
            break;
        case KC_QCOM:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    register_code(KC_SLSH);
                } else {
                    register_code(KC_COMM);
                }
            } else {
                unregister_code(KC_SLSH);
                unregister_code(KC_COMM);
            }
            break;
        default:
            return true;
    }
    return true;
}
