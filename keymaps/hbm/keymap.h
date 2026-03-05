#pragma once

#include QMK_KEYBOARD_H

// Declare functions.

void debug(char *);

// Define layers.

enum {
  LAYER_BS,
  LAYER_BS_LX,
  LAYER_BS_RX,
  LAYER_SM_L,
  LAYER_SM_LX,
  LAYER_SM_R,
  LAYER_SM_RX,
  LAYER_NM_L,
  LAYER_NM_LX,
  LAYER_NV_R,
  LAYER_NV_RX,
  LAYER_FN_L,
  LAYER_FN_LX,
  LAYER_CT_R,

  // Modifier layers go last so that key presses on their transparent other
  // side will fall through to any other active layer.

  LAYER_MD_L,
  LAYER_MD_R
};

// Aliases for cut, copy and paste.

#define A_CX RCTL(KC_X)
#define A_CC RCTL(KC_C)
#define A_CV RCTL(KC_V)

// Aliases for modified keys and UK symbols (backslash and pipe).

#define A_ST S(KC_TAB)
#define A_BS KC_NUBS
#define A_PP S(KC_NUBS)

// 1Password shortcut for quick access.

#define A_QA C(S(KC_SPC))

// Aliases for macros (should be in custom keys module).

#define A_SS KC_PIPE
#define A_VC KC_ESC

// Aliases for modifiers.

#define M_LA KC_LALT
#define M_LC KC_LCTL
#define M_LG KC_LGUI
#define M_LS KC_LSFT
#define M_RA KC_RALT
#define M_RC KC_RCTL
#define M_RG KC_RGUI
#define M_RS KC_RSFT

// Aliases for Windows previous and next tab / window / desktop.

#define W_PT C(S(KC_TAB))
#define W_NT C(KC_TAB)
#define W_PW A(S(KC_TAB))
#define W_NW A(KC_TAB)
#define W_PD C(G(KC_LEFT))
#define W_ND C(G(KC_RIGHT))

// Layer keycodes. The other extended layers, function and controls layers are
// accessed by pressing combinations of layer key presses, as conditional
// layers.

#define LT_RS LT(LAYER_SM_R,  KC_R)
#define LT_RN LT(LAYER_NV_R,  KC_S)
#define LT_RX LT(LAYER_BS_RX, KC_T)
#define LT_LX LT(LAYER_BS_LX, KC_N)
#define LT_LN LT(LAYER_NM_L,  KC_E)
#define LT_LS LT(LAYER_SM_L,  KC_I)

// Modifier layers are toggled.

#define LT_RM LT(LAYER_MD_R, KC_SPC)
#define LT_LM LT(LAYER_MD_L, KC_ENT)
