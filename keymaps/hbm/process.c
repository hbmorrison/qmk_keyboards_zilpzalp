// Copyright 2026 Hannah Blythe Morrison
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "keymap.h"

// True if Windows alt-tab behaviour is being processed.

static bool alt_tab_state = false;

// Process custom key behaviours.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // Process Windows alt-tab behaviour.

  switch (keycode) {

    // Manage Windows alt-tab behaviour by artificially holding the alt key down
    // while W_PW or W_NW are being pressed.

    case W_PW:
    case W_NW:
      if (record->event.pressed) {

        // When the W_PW or W_NW keys are first pressed, register the alt key.

        if (! alt_tab_state) {
          alt_tab_state = true;
          register_code(KC_LALT);
        }

        // Apply a oneshot shift modifier if W_PW was pressed, in order to cycle
        // backwards instead of forwards.

        if (keycode == W_PW)
          set_oneshot_mods(MOD_BIT(KC_LSFT));

        // Tap the tab key and immediately return false to indicate that no
        // further processing is required.

        tap_code(KC_TAB);
        return false;
      }

    // If another key is pressed while the Windows alt-tab behaviour is active,
    // unregister the alt key and reset the alt-tab state.

    default:
      if (record->event.pressed && alt_tab_state) {
        alt_tab_state = false;
        unregister_code(KC_LALT);
      }
  }

  // Process macros.

  if (record->event.pressed) {
    switch (keycode) {

      // Send the Vim command sequence - esc then colon - and immediately return
      // false to indicate that no further processing is required.

      case M_VC:
        tap_code16(KC_ESC);
        wait_ms(100);
        tap_code16(KC_COLN);
        return false;

      // Send the SSH suspend sequence and immediately return false to indicate
      // that no further processing is required.

      case M_SS:
        tap_code16(KC_ENT);
        tap_code16(KC_PIPE);
        tap_code16(RCTL(KC_Z));
        return false;
    }
  }

  // Continue processing the key.

  return true;
}
