// Copyright 2026 Wayne Van Son (@waynevanson)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "home_row_mods.h"
#include "keymap_introspection.h"

#ifdef ENCODER_MAP_ENABLE
#    include "encoder.h"
#endif

#ifdef DIP_SWITCH_MAP_ENABLE
#    include "dip_switch.h"
#endif

static bool find_home_row_mod(uint8_t layer, keypos_t key, uint8_t *mod) {
    for (uint8_t i = 0; i < home_row_mods_count; ++i) {
        const home_row_mod_t *home_row_mod = &home_row_mods[i];
        if (layer_state_cmp(home_row_mod->layer_mask, layer) && KEYEQ(home_row_mod->pos, key)) {
            *mod = home_row_mod->mod;
            return true;
        }
    }

    return false;
}

uint16_t home_row_mods_apply(uint8_t layer, keypos_t key, uint16_t keycode) {
    uint8_t mod;

    // MT() only supports basic keycodes. Allow KC_NO as well so a configured
    // home-row position can act as a modifier-only key.
    if ((IS_BASIC_KEYCODE(keycode) || keycode == KC_NO) && find_home_row_mod(layer, key, &mod)) {
        return MT(mod, keycode);
    }

    return keycode;
}

uint16_t home_row_mods_keycode(uint8_t layer, keypos_t key) {
    if (key.row < MATRIX_ROWS && key.col < MATRIX_COLS) {
        return home_row_mods_apply(layer, key, keycode_at_keymap_location(layer, key.row, key.col));
    }

#ifdef ENCODER_MAP_ENABLE
    if (key.row == KEYLOC_ENCODER_CW && key.col < NUM_ENCODERS) {
        return keycode_at_encodermap_location(layer, key.col, true);
    } else if (key.row == KEYLOC_ENCODER_CCW && key.col < NUM_ENCODERS) {
        return keycode_at_encodermap_location(layer, key.col, false);
    }
#endif

#ifdef DIP_SWITCH_MAP_ENABLE
    if (key.row == KEYLOC_DIP_SWITCH_ON && key.col < NUM_DIP_SWITCHES) {
        return keycode_at_dip_switch_map_location(key.col, true);
    } else if (key.row == KEYLOC_DIP_SWITCH_OFF && key.col < NUM_DIP_SWITCHES) {
        return keycode_at_dip_switch_map_location(key.col, false);
    }
#endif

    return KC_NO;
}
