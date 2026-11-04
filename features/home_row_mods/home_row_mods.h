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

#pragma once

#include "quantum.h"

#ifdef __cplusplus
extern "C" {
#endif

// Use all layers.
#define HMR_ALL_LAYERS ((layer_state_t)~0)

// Use a single layer, e.g. HMR_LAYER(LAYER_BASE).
#define HMR_LAYER(layer) ((layer_state_t)1 << (layer))

// Matrix position from info.json: HMR_POS(row, col).
#define HMR_POS(row_, col_) { .row = (row_), .col = (col_) }

typedef struct {
    layer_state_t layer_mask;
    keypos_t      pos;
    uint8_t       mod;
} home_row_mod_t;

// Defined by the keymap using matrix positions, e.g.
// {HMR_ALL_LAYERS, HMR_POS(1, 1), MOD_LGUI}.
extern const home_row_mod_t home_row_mods[];
extern const uint8_t        home_row_mods_count;

// Apply home-row mods to a keycode that was already read from a keymap.
// This is the composable entry point for use with other keycode transforms.
uint16_t home_row_mods_apply(uint8_t layer, keypos_t key, uint16_t keycode);

// Convenience wrapper that reads the keycode from the active keymap and
// applies home-row mods, including encoder/DIP-switch fallback handling.
// Call this from the keymap's own keymap_key_to_keycode() function.
uint16_t home_row_mods_keycode(uint8_t layer, keypos_t key);

#ifdef __cplusplus
}
#endif
