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
 *
 * We are using Engram key layout with Miryoku layers. 
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
  KC_12,
  KC_DOT_COMMA,
};

const custom_shift_key_t custom_shift_keys[] = {
  // BASE
  {KC_QUESTION, KC_EXCLAIM}, //  ? -> !
  {KC_COMM, KC_SCLN}, // , -> ;
  {KC_DOT_COMMA,  KC_COLN}, // . -> :   
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

 
// LAYOUT wrapper that embeds the home-row mods. Each layer only supplies the
// base keycodes; the GUI/ALT/CTL/SFT (and mirrored SFT/CTL/ALT/GUI) taps are
// added here so they stay consistent across every layer.
#define LAYOUT_WAYNEVANSON( \
    r0c0, r0c1, r0c2, r0c3, r0c4, r0c5, r0c6, r0c7, r0c8, r0c9, r0ca, r0cb, \
    r1c0, r1c1, r1c2, r1c3, r1c4, r1c5, r1c6, r1c7, r1c8, r1c9, r1ca, r1cb, \
    r2c0, r2c1, r2c2, r2c3, r2c4, r2c5, r2c6, r2c7, r2c8, r2c9, r2ca, r2cb, \
    r3c0, r3c1, r3c2, r3c3, r3c4) \
    LAYOUT( \
        r0c0, r0c1, r0c2, r0c3, r0c4, r0c5, r0c6, r0c7, r0c8, r0c9, r0ca, r0cb, \
        r1c0, LGUI_T(r1c1), LALT_T(r1c2), LCTL_T(r1c3), LSFT_T(r1c4), r1c5, \
        r1c6, RSFT_T(r1c7), RCTL_T(r1c8), RALT_T(r1c9), RGUI_T(r1ca), r1cb, \
        r2c0, r2c1, r2c2, r2c3, r2c4, r2c5, r2c6, r2c7, r2c8, r2c9, r2ca, r2cb, \
        r3c0, r3c1, r3c2, r3c3, r3c4)

// todo: What about those sexy mouse modes?
// todo: What about SHIFT + ESCAPE = CAPSLOCK?
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Engram layout (mostly) for letters https://engram-layouts.xyz/engram-en/
  // The outer column of the 3x6 PCB is not populated: KC_NO on matrix col 0.
  [LAYER_BASE] = LAYOUT_WAYNEVANSON(
    KC_NO,
    KC_B,
    KC_Y,
    KC_O,
    KC_U,
    // todo: There's gotta be a better spot for unused keys, rather than in a more accesible space?
    KC_Z,
    KC_Q,
    KC_D,
    KC_N,
    KC_G,
    KC_V,
    KC_NO,
    KC_NO,
    KC_H,
    KC_I,
    KC_A,
    KC_E,
    KC_COMM,
    KC_DOT_COMMA,
    KC_T,
    KC_R,
    KC_S,
    KC_C,
    KC_NO,
    KC_NO,
    KC_K,
    KC_J,
    KC_X,
    KC_W,
    KC_QUOTE,
    KC_QUESTION,
    KC_M,
    KC_L,
    KC_F,
    KC_P,
    KC_NO,
    LT(LAYER_NUMBER_FUNCTION, KC_ESC),
    LT(LAYER_NAVIGATION, KC_SPACE),
    LT(LAYER_POINTER, KC_TAB),
    LT(LAYER_SYMBOLS, KC_ENTER),
    KC_BACKSPACE
  ),
  
  // Enter by holding backspace (right hand, thumb right) 
  //
  // todo: put the numbers on the right keyboard; Why they on left?
  // Probably because navigation is there.   
  [LAYER_NUMBER_FUNCTION] = LAYOUT_WAYNEVANSON(
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_7,
    KC_8,
    KC_9,
    KC_10,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_4,
    KC_5,
    KC_6,
    KC_11,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_1,
    KC_2,
    KC_3,
    KC_12,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_DOT,
    KC_0
  ),

  [LAYER_SYMBOLS] = LAYOUT_WAYNEVANSON(
    KC_NO,
    KC_SLASH,
    KC_EQUAL,
    KC_RIGHT_ANGLE_BRACKET,
    KC_LEFT_ANGLE_BRACKET,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_LEFT_PAREN,
    KC_RIGHT_PAREN,
    KC_LEFT_CURLY_BRACE,
    KC_RIGHT_CURLY_BRACE,
    KC_PLUS,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
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
    KC_NO,
    KC_NO
  ),

  [LAYER_NAVIGATION] = LAYOUT_WAYNEVANSON(
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
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_CAPS,
    KC_LEFT,
    KC_DOWN,
    KC_UP,
    KC_RIGHT,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    MS_WHLL,
    MS_WHLD,
    MS_WHLU,
    MS_WHLR,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO,
    KC_NO
  ),

  [LAYER_POINTER] = LAYOUT_WAYNEVANSON(
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
    KC_MEDIA_PREV_TRACK,
    KC_AUDIO_VOL_DOWN,
    KC_AUDIO_VOL_UP,
    KC_MEDIA_NEXT_TRACK,
    KC_NO,
    MS_BTN2,
    MS_BTN1,
    MS_BTN3,
    KC_NO,
    KC_NO
  )
};
// clang-format on

void process_custom_keys(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case KC_DOT_COMMA:
      if (record->event.pressed) {
        register_code(KC_DOT);
      } else {
        unregister_code(KC_DOT);
      }
    default:
  };
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
