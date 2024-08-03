#include QMK_KEYBOARD_H
#include "version.h"

/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2024 Wayne Van Son <waynevanson@gmail.com> (@waynevanson)
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

// https://github.com/manna-harbour/miryoku/tree/master/docs/reference
enum charybdis_keymap_layers {
    BASE = 0,
    NMSY,
    FUNC,
    LAYER_POINTER,
};

// `>` and `<` can be accessed on other layers.
enum custom_keycodes {
    // `.`, or `!` with SHIFT.
    KC_EDOT,

    // `/`, or `?` with SHIFT.
    KC_QCOM
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

// TOP_LEFT,
// TOP_RIGHT, 
// MID_LEFT,
// MID_RIGHT,
// BOT_LEFT,
// BOT_RIGHT,
// THUMB_LEFT
// THUMB_RIGHT
//
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
       KC_LGUI,
       KC_Q,
       KC_D,
       KC_R,
       KC_W,
       KC_B,
       
       KC_J,
       KC_F,
       KC_U,
       KC_P,
       KC_SCLN,
       KC_RGUI,

       KC_LCTL,
       LGUI_T(KC_A),
       LALT_T(KC_S),
       LCTL_T(KC_H),
       LSFT_T(KC_T),
       KC_G,

       KC_Y,
       RSFT_T(KC_N),
       RCTL_T(KC_E),
       RALT_T(KC_O),
       RGUI_T(KC_I),
       KC_RCTL,

       KC_LSFT,
       KC_Z,
       KC_X,
       KC_M,
       KC_C,
       KC_V,

       KC_K,
       KC_L,
       LT(LAYER_POINTER, KC_QCOM),
       KC_EDOT,
       KC_QUOTE,
       KC_RSFT,

       KC_ESC,
       KC_SPC,
       KC_TAB,

       LT(FUNC, KC_ENT),
       LT(NMSY, KC_BSPC)
  ),

  [NMSY] = LAYOUT(
        KC_NO,
        KC_LBRC,
        KC_7,
        KC_8,
        KC_9,
        KC_RBRC,

        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,

        KC_NO,
        KC_SEMICOLON,
        KC_4,
        KC_5,
        KC_6,
        KC_EQL,

        KC_NO,
        KC_RSFT,
        KC_RCTL,
        KC_RALT,
        KC_RGUI,
        KC_NO,

        KC_NO,
        KC_GRAVE,
        KC_1,
        KC_2,
        KC_3,
        KC_BSLS,

        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,

        KC_DOT,
        KC_0,
        KC_MINS,

        KC_NO,
        KC_NO
  ),

  [FUNC] = LAYOUT(
        KC_NO,
        KC_F12,
        KC_F7,
        KC_F8,
        KC_F9,
        KC_PRINT_SCREEN,

        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,

        KC_NO,
        KC_F11,
        KC_F4,
        KC_F5,
        KC_F6,
        KC_SCROLL_LOCK,

        KC_NO,
        KC_RIGHT_SHIFT,
        KC_RIGHT_CTRL,
        KC_RIGHT_ALT,
        KC_RIGHT_GUI,
        KC_NO,

        KC_NO,
        KC_F11,
        KC_F1,
        KC_F2,
        KC_F3,
        KC_PAUSE,

        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,
        KC_NO,

        KC_MENU,
        KC_SPACE,
        KC_TAB,

        KC_NO,
        KC_NO
  ),

  [LAYER_POINTER] = LAYOUT(
        XXXXXXX,
        XXXXXXX,
        XXXXXXX,
        XXXXXXX,
        DPI_MOD,
        S_D_MOD,

        S_D_MOD,
        DPI_MOD,
        XXXXXXX,
        XXXXXXX,
        XXXXXXX,
        XXXXXXX,

        XXXXXXX,
        KC_LGUI,
        KC_LALT,
        KC_LCTL,
        KC_LSFT,
        XXXXXXX,

        XXXXXXX,
        KC_RSFT,
        KC_RCTL,
        KC_RALT,
        KC_RGUI,
        XXXXXXX,

        XXXXXXX,
        DRGSCRL,
        SNIPING,
        _______,
        EE_CLR,
        QK_BOOT,

        QK_BOOT,
        EE_CLR,
        _______,
        SNIPING,
        DRGSCRL,
        XXXXXXX,

        KC_BTN2,
        KC_BTN1,
        KC_BTN3,

        KC_BTN3,
        KC_BTN1
  )
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

int8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods() | get_oneshot_mods();

    switch (keycode) {
        // `.`, or `!` with SHIFT.
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
        // `/`, or `?` with SHIFT.
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