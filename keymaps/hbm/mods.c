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

#include "dynamic_mods.h"
#include "keymap.h"

// Return true if the given keycode should cancel all current dynamic mod
// behaviour.

bool is_dynamic_mod_cancel_key(uint16_t keycode) {
  return keycode == KC_ESC;
}

// Return true if the given keycode should be ignored by the dynamic mod
// processing.

bool is_dynamic_mod_ignored_key(uint16_t keycode) {
  return IS_QK_LAYER_TAP(keycode);
}
