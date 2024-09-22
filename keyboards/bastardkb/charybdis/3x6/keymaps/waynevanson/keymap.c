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
#include "version.h"
#include "features/custom_shift_keys.h"

// https://github.com/manna-harbour/miryoku/tree/master/docs/reference
enum charybdis_keymap_layers {
  LAYER_BASE = 0,
  LAYER_NUMBER_FUNCTION,
  LAYER_SYMBOLS,
  LAYER_NAVIGATION,
  LAYER_POINTER,
};

enum custom_keycodes {
  KC_10 = SAFE_RANGE,
  KC_11,
  KC_12
};

const custom_shift_key_t custom_shift_keys[] = {
  // BASE
  {KC_QUESTION, KC_EXCLAIM}, //  ? -> !
  {KC_COMM, KC_SCLN}, // , -> ;
  {KC_KP_DOT,  KC_COLN}, // . -> :   
  {LT(LAYER_NUMBER_FUNCTION, KC_BSPC), KC_DELETE}, // Backspace -> Delete

  // NUM_FUN layer
  {KC_1, KC_F1},
  {KC_2, KC_F2},
  {KC_3, KC_F3},
  {KC_4, KC_F4},
  {KC_5, KC_F5},
  {KC_6, KC_F6},
  {KC_7, KC_F7},
  {KC_8, KC_F8},
  {KC_9, KC_F9},
  {KC_10, KC_F10},
  {KC_11, KC_F11},
  {KC_12, KC_F12},

  {KC_SLSH, KC_BSLS}, // / -> "\"

  {KC_EQUAL, KC_PERCENT}, // = -> %
  {KC_LEFT_CURLY_BRACE, KC_LEFT_BRACKET}, // { -> [
  {KC_RIGHT_CURLY_BRACE, KC_RIGHT_BRACKET}, // } -> ]
  {KC_PLUS, KC_MINUS}, // + -> -
  {KC_PIPE, KC_AT}, // | -> @
  {KC_ASTERISK, KC_HASH}, // * -> #
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Engram layout (mostly) for letters (https://engram.dev/)
  [LAYER_BASE] = LAYOUT_SPLIT(
    KC_B,
    KC_Y,
    KC_O,
    KC_U,
    KC_Z,

    LGUI(KC_C),
    LALT(KC_I),
    LCTL(KC_E),
    LSFT(KC_A),
    KC_COMM,

    KC_G,
    KC_X,
    KC_J,
    KC_K,
    KC_QUOTE,

    KC_ESC,
    LT(LAYER_NAVIGATION, KC_SPACE),
    LT(LAYER_POINTER, KC_TAB),

    KC_Q,
    KC_L,
    KC_D,
    KC_W,
    KC_V,

    KC_KP_DOT,
    RSFT(KC_H),
    RCTL(KC_T),
    RALT(KC_S),
    RGUI(KC_N),

    KC_QUESTION,
    KC_R,
    KC_M,
    KC_F,
    KC_P,

    LT(LAYER_SYMBOLS, KC_ENTER),
    LT(LAYER_NUMBER_FUNCTION, KC_BACKSPACE)
  ),
  
  [LAYER_NUMBER_FUNCTION] = LAYOUT_SPLIT(
    KC_12,
    KC_7,
    KC_8,
    KC_9,
    KC_NO,

    KC_11,
    KC_4,
    KC_5,
    KC_6,
    KC_NO,

    KC_10,
    KC_3,
    KC_2,
    KC_1,
    KC_NO,

    KC_DOT,
    KC_0,
    KC_MINUS,

    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    RSFT(KC_NO),
    RCTL(KC_NO),
    RALT(KC_NO),
    RGUI(KC_NO),

    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    KC_NO
  ),

  [LAYER_SYMBOLS] = LAYOUT_SPLIT(
    KC_SLASH,
    KC_EQUAL,
    KC_RIGHT_ANGLE_BRACKET,
    KC_LEFT_ANGLE_BRACKET,
    KC_NO,

    KC_LEFT_PAREN,
    KC_RIGHT_PAREN,
    KC_LEFT_CURLY_BRACE,
    KC_RIGHT_CURLY_BRACE,
    KC_PLUS,

    KC_GRAVE,
    KC_AMPERSAND,
    KC_PIPE,
    KC_ASTERISK,
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
    LGUI(KC_NO),
    LALT(KC_NO),
    LCTL(KC_NO),
    LSFT(KC_NO),

    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    KC_NO,
    KC_NO
  ),

  [LAYER_NAVIGATION] = LAYOUT_SPLIT(
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    LGUI(KC_NO),
    LALT(KC_NO),
    LCTL(KC_NO),
    LSFT(KC_NO),
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
    KC_HOME,
    KC_PGDN,
    KC_PGUP,
    KC_END,

    KC_CAPS,
    KC_LEFT,
    KC_DOWN,
    KC_UP,
    KC_RIGHT,

    KC_MS_L,
    KC_MS_D,
    KC_MS_U,
    KC_MS_R,
    KC_NO,

    KC_NO,
    KC_NO
  ),

  [LAYER_POINTER] = LAYOUT_SPLIT(
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,

    LSFT(KC_NO),
    LCTL(KC_NO),
    LALT(KC_NO),
    LGUI(KC_NO),
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
    KC_MEDIA_PLAY_PAUSE,
    KC_AUDIO_MUTE,
    KC_NO,

    KC_NO,
    KC_BTN2,
    KC_BTN1,
    KC_BTN3,
    KC_NO,

    KC_NO,
    KC_MEDIA_PREV_TRACK,
    KC_AUDIO_VOL_DOWN,
    KC_AUDIO_VOL_UP,
    KC_MEDIA_PREV_TRACK,

    KC_NO,
    KC_NO
  )
};
// clang-format on

void process_custom_keys(uint16_t keycode, keyrecord_t* record) {
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }

  process_custom_keys(keycode, record);


  return true;
}

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
