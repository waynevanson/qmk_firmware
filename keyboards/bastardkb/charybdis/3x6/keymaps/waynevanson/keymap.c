#include QMK_KEYBOARD_H
#include "version.h"
#include "features/custom_shift_keys.h"

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

// https://github.com/manna-harbour/miryoku/tree/master/docs/reference
enum charybdis_keymap_layers {
    BASE = 0,
    NMSY,
    FUNC,
    LAYER_POINTER,
    MEDIA,
    NAV
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

const custom_shift_key_t custom_shift_keys[] = {
  {KC_QUESTION, KC_EXCLAIM}, // Shift ? is !
  {KC_COMM, KC_SCLN}, // Shift , is ;
  {KC_DOT,  KC_COLN}, // Shift . is :   
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Engram layout (mostly) for letters (https://engram.dev/)
  [BASE] = LAYOUT(
       KC_NO,
       KC_B,
       KC_Y,
       KC_O,
       KC_U,
       KC_Z,
       
       KC_Q,
       KC_L,
       KC_D,
       KC_W,
       KC_V,
       KC_Z,

       KC_NO,
       LGUI_T(KC_C),
       LALT_T(KC_I),
       LCTL_T(KC_E),
       LSFT_T(KC_A),
       KC_COMM,

       KC_DOT,
       RSFT_T(KC_H),
       RCTL_T(KC_T),
       RALT_T(KC_S),
       RGUI_T(KC_N),
       KC_Q,  

       KC_NO,
       KC_G,
       KC_X,
       KC_J,
       KC_K,
       KC_QUOT,

       KC_QUESTION,
       KC_R,
       LT(LAYER_POINTER, KC_M),
       KC_F,
       KC_P,
       KC_NO,

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

  [NAV] = LAYOUT(
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    KC_HOME,
    KC_PGUP,
    KC_PGDN,
    KC_END,
    KC_NO,

    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    KC_LEFT,
    KC_UP,
    KC_DOWN,
    KC_RIGHT,
    KC_NO,

    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    KC_MEDIA_PREV_TRACK,
    KC_AUDIO_VOL_UP,
    KC_AUDIO_VOL_DOWN,
    KC_MEDIA_NEXT_TRACK,
    KC_NO,

    KC_NO,
    KC_NO,
    KC_NO,

    KC_MEDIA_STOP,
    KC_MEDIA_PLAY_PAUSE
  ),

  [LAYER_POINTER] = LAYOUT(
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_BTN2,
    KC_BTN1,
    KC_BTN3,

    KC_NO,
    KC_NO
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
