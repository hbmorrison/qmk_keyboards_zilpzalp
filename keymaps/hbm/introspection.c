#include QMK_KEYBOARD_H

#include "keymap.h"

// Use combos to combine modifier keys.

const uint16_t PROGMEM alt_sft_combo[]     = {OS_LALT, OS_LSFT, COMBO_END};
const uint16_t PROGMEM ctl_sft_combo[]     = {OS_LCTL, OS_LSFT, COMBO_END};
const uint16_t PROGMEM ctl_alt_combo[]     = {OS_LCTL, OS_LALT, COMBO_END};
const uint16_t PROGMEM ctl_sft_alt_combo[] = {OS_LCTL, OS_LSFT, OS_LALT, COMBO_END};
const uint16_t PROGMEM gui_sft_combo[]     = {OS_LGUI, OS_LSFT, COMBO_END};
const uint16_t PROGMEM gui_ctl_combo[]     = {OS_LGUI, OS_LCTL, COMBO_END};
const uint16_t PROGMEM gui_alt_combo[]     = {OS_LGUI, OS_LALT, COMBO_END};

combo_t key_combos[] = {
  COMBO(alt_sft_combo,     OS_LSA),
  COMBO(ctl_sft_combo,     OS_LCS),
  COMBO(ctl_alt_combo,     OS_LCA),
  COMBO(ctl_sft_alt_combo, OS_MEH),
  COMBO(gui_sft_combo,     OS_LSG),
  COMBO(gui_ctl_combo,     OS_LCG),
  COMBO(gui_alt_combo,     OS_LAG)
};
