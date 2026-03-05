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

#include QMK_KEYBOARD_H

#include "keymap.h"

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // Auto shift the symbol keys present in the base layer.

    case KC_COMM:
    case KC_DOT:
    case KC_SLSH:
      return true;

    // Auto shift the tap keycodes in the layer-tap keys.

    case LT_RS:
    case LT_RN:
    case LT_RX:
    case LT_LX:
    case LT_LN:
    case LT_LS:
      return true;

    // Auto shift left brace, parenthesis and curly brace to issue [],() or {}.

    case KC_LBRC:
    case KC_LPRN:
    case KC_LCBR:
      return true;
  }
  return false;
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch (keycode) {

    // When the left brace, parenthesis and curly brace is shifted, a pair of
    // open and closed keycodes are issued, followed by a left keycode to put
    // the cursor between them.

    case KC_LBRC:
    case KC_LPRN:
    case KC_LCBR:
      if (shifted) {
        tap_code16(keycode);
        tap_code16(keycode + 1);
        tap_code16(KC_LEFT);
      } else {
        register_code16(keycode);
      }
      break;

    // By default, add a weak shift modifier and only register the lower eight
    // bits of the keycode if the key is retro shifted - removing the upper
    // eight bits that mod tap uses - so that retro shift will work correctly.

    default:
      if (shifted)
        add_weak_mods(MOD_BIT(KC_LSFT));
      register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch (keycode) {

    // Release the key if these special cases were not shifted.

    case KC_LBRC:
    case KC_LPRN:
    case KC_LCBR:
      if (! shifted)
        unregister_code16(keycode);
      break;

    // Only unregister the lower eight bits of the keycode if the key is retro
    // shifted - removing the upper eight bits that mod tap uses - so that retro
    // shift will work correctly.

    default:
      unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}
