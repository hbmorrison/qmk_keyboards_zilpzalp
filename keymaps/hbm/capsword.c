#include "keymap.h"

// Only capitalise alpha characters and ignore some symbols and other keys.

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {

    // Alpha keys get capitalised.

    case KC_Q:
    case KC_W:
    case KC_F:
    case KC_P:
    case KC_B:
    case KC_A:
    case KC_R:
    case KC_S:
    case KC_T:
    case KC_G:
    case KC_Z:
    case KC_X:
    case KC_C:
    case KC_D:
    case KC_V:
    case KC_J:
    case KC_L:
    case KC_U:
    case KC_Y:
    case KC_M:
    case KC_N:
    case KC_E:
    case KC_I:
    case KC_O:
    case KC_K:
    case KC_H:
      add_weak_mods(MOD_BIT(KC_LSFT));
      return true;

    // Number keys, underscore, backspace and del continue caps word but are not
    // shifted themselves.

    case KC_1 ... KC_0:
    case KC_UNDS:
    case KC_BSPC:
    case KC_DEL:
      return true;

    // Allow tab to continue caps word for shell completion of variable names.

    case KC_TAB:
      return true;

    // Some  keys in higher layers also continue caps word so the layer keys
    // must also continue caps word.

    case LT_LX:
    case LT_RX:
    case LT_LS:
    case LT_RS:
    case LT_LN:
      return true;
  }
  return false;
}
