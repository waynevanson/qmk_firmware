# Home-row mods feature

Keeps keymaps written as plain `LAYOUT(...)` while injecting `MT()` home-row
mods based on physical matrix positions.

The feature provides `home_row_mods_keycode()`. The keymap owns QMK's weak
`keymap_key_to_keycode()` hook and calls the feature from it. That runs before
tap-hold processing, so QMK still handles tapping terms, permissive hold,
chordal hold, etc.

## Setup

Add the source to `rules.mk`:

```make
SRC += features/home_row_mods/home_row_mods.c
```

Include the feature and define the table in `keymap.c`:

```c
#include "features/home_row_mods/home_row_mods.h"

const home_row_mod_t home_row_mods[] = {
    // Matrix row 1: left GUI/ALT/CTL/SFT
    {HMR_ALL_LAYERS, HMR_POS(1, 1), MOD_LGUI},
    {HMR_ALL_LAYERS, HMR_POS(1, 2), MOD_LALT},
    {HMR_ALL_LAYERS, HMR_POS(1, 3), MOD_LCTL},
    {HMR_ALL_LAYERS, HMR_POS(1, 4), MOD_LSFT},
    // Matrix row 5: right SFT/CTL/ALT/GUI
    {HMR_ALL_LAYERS, HMR_POS(5, 4), MOD_RSFT},
    {HMR_ALL_LAYERS, HMR_POS(5, 3), MOD_RCTL},
    {HMR_ALL_LAYERS, HMR_POS(5, 2), MOD_RALT},
    {HMR_ALL_LAYERS, HMR_POS(5, 1), MOD_RGUI},
};

const uint8_t home_row_mods_count =
    sizeof(home_row_mods) / sizeof(home_row_mod_t);

uint16_t keymap_key_to_keycode(uint8_t layer, keypos_t key) {
    return home_row_mods_keycode(layer, key);
}
```

To compose with another feature, use `home_row_mods_apply()` on a keycode you
already read:

```c
uint16_t keymap_key_to_keycode(uint8_t layer, keypos_t key) {
    uint16_t keycode = keycode_at_keymap_location(layer, key.row, key.col);
    keycode = home_row_mods_apply(layer, key, keycode);
    return other_feature(layer, key, keycode);
}
```

Positions are the `matrix` coordinates from the keyboard's
`info.json` / `keyboard.json`:

```json
{"matrix": [1, 1], ...}
```

Use `HMR_ALL_LAYERS` to apply an entry on every layer, or restrict it:

```c
{HMR_LAYER(LAYER_BASE), HMR_POS(1, 1), MOD_LGUI},
```

## Notes

- Only basic keycodes and `KC_NO` are wrapped. `MT()` does not support
  16-bit keycodes, shifted symbols, custom keycodes, etc.
- `KC_NO` is allowed so a configured position can act as a modifier-only key.
- Layer selection uses `HMR_ALL_LAYERS` or one or more `HMR_LAYER(...)` values.
