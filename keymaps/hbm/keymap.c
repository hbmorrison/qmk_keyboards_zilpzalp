#include QMK_KEYBOARD_H

#include "hbm_keymaps.h"

// Generic thumb keymap for zilpzalp.

#define KM_TH KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

// Define the base keymap for zilpzalp.

#define KM_BASE_T BASE_LT, LI_T,    RI_T, BASE_RT
#define KM_BASE_M LO_M,    BASE_LM, LI_M, RI_M,   BASE_RM, RO_M
#define KM_BASE_B BASE_LB, BASE_RB

#define KM_BASE_TH LO_TH, BASE_LTH, BASE_RTH, RO_TH

#define KM_BASE KM_BASE_T, KM_BASE_M, KM_BASE_B, KM_BASE_TH

// Define the base modifier keymaps for zilpzalp.

#define KM_LBASEM_T BASEM_LT, KC_NO,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define KM_LBASEM_M KC_NO,    BASEM_LM, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define KM_LBASEM_B BASEM_LB, KC_TRNS,  KC_TRNS, KC_TRNS

#define KM_LBASEM_TH KC_TRNS, BASEM_LTH, KC_TRNS, KC_TRNS

#define KM_LBASEM KM_LBASEM_T, KM_LBASEM_M, KM_LBASEM_B, KM_LBASEM_TH

#define KM_RBASEM_T KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   BASEM_RT
#define KM_RBASEM_M KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   BASEM_RM, KC_NO
#define KM_RBASEM_B KC_TRNS, KC_TRNS, KC_TRNS, BASEM_RB

#define KM_RBASEM_TH KC_TRNS, KC_TRNS,   BASEM_RTH, KC_TRNS

#define KM_RBASEM KM_RBASEM_T, KM_RBASEM_M, KM_RBASEM_B, KM_RBASEM_TH

// Define the base extension keymaps for zilpzalp.

#define KM_LBASEX_T BASEX_LT, KC_NO,    KC_NO, KC_NO, KC_NO,    KC_NO
#define KM_LBASEX_M KC_NO,    BASEX_LM, KC_NO, KC_NO, BASEX_RO, KC_NO
#define KM_LBASEX_B BASEX_LB, KC_NO,    KC_NO, KC_NO

#define KM_LBASEX KM_LBASEX_T, KM_LBASEX_M, KM_LBASEX_B, KM_TH

#define KM_RBASEX_T KC_NO, KC_NO,    KC_NO, KC_NO,   KC_NO,    BASEX_RT
#define KM_RBASEX_M KC_NO, BASEX_LO, KC_NO, KC_NO,   BASEX_RM, KC_NO
#define KM_RBASEX_B KC_NO, KC_NO,    KC_NO, BASEX_RB

#define KM_RBASEX KM_RBASEX_T, KM_RBASEX_M, KM_RBASEX_B, KM_TH

// Define the symbol keymaps for zilpzalp.

#define KM_LSYM_T SYM_LT, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO
#define KM_LSYM_M KC_NO,  SYM_LM, KC_NO, KC_NO, SYM_RO, KC_NO
#define KM_LSYM_B SYM_LB, KC_NO,  KC_NO, KC_NO

#define KM_LSYM KM_LSYM_T, KM_LSYM_M, KM_LSYM_B, KM_TH

#define KM_RSYM_T KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  SYM_RT
#define KM_RSYM_M KC_NO, SYM_LO, KC_NO, KC_NO, SYM_RM, KC_NO
#define KM_RSYM_B KC_NO, KC_NO,  KC_NO, SYM_RB

#define KM_RSYM KM_RSYM_T, KM_RSYM_M, KM_RSYM_B, KM_TH

#define KM_LSYMX_T SYMX_LT, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO
#define KM_LSYMX_M KC_NO,   SYMX_LM, KC_NO, KC_NO, SYMX_RO, KC_NO
#define KM_LSYMX_B SYMX_LB, KC_NO,   KC_NO, KC_NO

#define KM_LSYMX KM_LSYMX_T, KM_LSYMX_M, KM_LSYMX_B, KM_TH

#define KM_RSYMX_T KC_NO, KC_NO,   KC_NO, KC_NO,  KC_NO,   SYMX_RT
#define KM_RSYMX_M KC_NO, SYMX_LO, KC_NO, KC_NO,  SYMX_RM, KC_NO
#define KM_RSYMX_B KC_NO, KC_NO,   KC_NO, SYMX_RB

#define KM_RSYMX KM_RSYMX_T, KM_RSYMX_M, KM_RSYMX_B, KM_TH

// Define the number keymaps for zilpzalp.

#define KM_NUM_T NUM_LT, KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO
#define KM_NUM_M KC_NO,  NUM_LM, KC_NO, KC_NO, NUM_RO, KC_NO
#define KM_NUM_B NUM_LB, KC_NO,  KC_NO, KC_NO

#define KM_NUM KM_NUM_T, KM_NUM_M, KM_NUM_B, KM_TH

#define KM_NUMX_T NUMX_LT, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO
#define KM_NUMX_M KC_NO,   NUMX_LM, KC_NO, KC_NO, NUMX_RO, KC_NO
#define KM_NUMX_B NUMX_LB, KC_NO,   KC_NO, KC_NO

#define KM_NUMX KM_NUMX_T, KM_NUMX_M, KM_NUMX_B, KM_TH

// Define the number keymaps for zilpzalp.

#define KM_NAV_T KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,  NAV_RT
#define KM_NAV_M KC_NO, NAV_LO, KC_NO, KC_NO, NAV_RM, KC_NO
#define KM_NAV_B KC_NO, KC_NO,  KC_NO, NAV_RB

#define KM_NAV KM_NAV_T, KM_NAV_M, KM_NAV_B, KM_TH

#define KM_NAVX_T KC_NO, KC_NO,   KC_NO, KC_NO,  KC_NO,   NAVX_RT
#define KM_NAVX_M KC_NO, NAVX_LO, KC_NO, KC_NO,  NAVX_RM, KC_NO
#define KM_NAVX_B KC_NO, KC_NO,   KC_NO, NAVX_RB

#define KM_NAVX KM_NAVX_T, KM_NAVX_M, KM_NAVX_B, KM_TH

// Define the function key keymaps for zilpzalp.

#define KM_FUNC_T FUNC_LT, KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO
#define KM_FUNC_M KC_NO,   FUNC_LM, KC_NO, KC_NO, FUNC_RO, KC_NO
#define KM_FUNC_B FUNC_LB, KC_NO,   KC_NO, KC_NO

#define KM_FUNC KM_FUNC_T, KM_FUNC_M, KM_FUNC_B, KM_TH

#define KM_FUNCX_T FUNCX_LT, KC_NO,    KC_NO, KC_NO, KC_NO,    KC_NO
#define KM_FUNCX_M KC_NO,    FUNCX_LM, KC_NO, KC_NO, FUNCX_RO, KC_NO
#define KM_FUNCX_B FUNCX_LB, KC_NO,    KC_NO, KC_NO

#define KM_FUNCX KM_FUNCX_T, KM_FUNCX_M, KM_FUNCX_B, KM_TH

// Define the controls keymaps for zilpzalp.

#define KM_CTLS_T KC_NO, KC_NO,   KC_NO, KC_NO,  KC_NO,   CTLS_RT
#define KM_CTLS_M KC_NO, CTLS_LO, KC_NO, KC_NO,  CTLS_RM, KC_NO
#define KM_CTLS_B KC_NO, KC_NO,   KC_NO, CTLS_RB

#define KM_CTLS KM_CTLS_T, KM_CTLS_M, KM_CTLS_B, KM_TH

// Define the layers.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE]   = LAYOUT_zilpzalp( KM_BASE ),
  [LAYER_LBASEM] = LAYOUT_zilpzalp( KM_LBASEM ),
  [LAYER_RBASEM] = LAYOUT_zilpzalp( KM_RBASEM ),
  [LAYER_LBASEX] = LAYOUT_zilpzalp( KM_LBASEX ),
  [LAYER_RBASEX] = LAYOUT_zilpzalp( KM_RBASEX ),
  [LAYER_LSYM]   = LAYOUT_zilpzalp( KM_LSYM ),
  [LAYER_LSYMX]  = LAYOUT_zilpzalp( KM_LSYMX ),
  [LAYER_RSYM]   = LAYOUT_zilpzalp( KM_RSYM ),
  [LAYER_RSYMX]  = LAYOUT_zilpzalp( KM_RSYMX ),
  [LAYER_NUM]    = LAYOUT_zilpzalp( KM_NUM ),
  [LAYER_NUMX]   = LAYOUT_zilpzalp( KM_NUMX ),
  [LAYER_NAV]    = LAYOUT_zilpzalp( KM_NAV ),
  [LAYER_NAVX]   = LAYOUT_zilpzalp( KM_NAVX ),
  [LAYER_FUNC]   = LAYOUT_zilpzalp( KM_FUNC ),
  [LAYER_FUNCX]  = LAYOUT_zilpzalp( KM_FUNCX ),
  [LAYER_CTLS]   = LAYOUT_zilpzalp( KM_CTLS ),
};
