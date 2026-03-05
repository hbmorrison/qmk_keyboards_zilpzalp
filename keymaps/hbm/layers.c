#include QMK_KEYBOARD_H

#include "conditional_layers.h"
#include "keymap.h"

// Layer masks for higher layers.

#define MASK_NM_LX (LAYER_BIT(LAYER_NM_L) | LAYER_BIT(LAYER_BS_LX))
#define MASK_SM_LX (LAYER_BIT(LAYER_SM_L) | LAYER_BIT(LAYER_BS_LX))

#define MASK_FN_L  (LAYER_BIT(LAYER_SM_L) | LAYER_BIT(LAYER_NM_L))
#define MASK_FN_LX (LAYER_BIT(LAYER_SM_L) | LAYER_BIT(LAYER_NM_L) | LAYER_BIT(LAYER_BS_LX))

#define MASK_NV_RX (LAYER_BIT(LAYER_NV_R) | LAYER_BIT(LAYER_BS_RX))
#define MASK_SM_RX (LAYER_BIT(LAYER_SM_R) | LAYER_BIT(LAYER_BS_RX))

#define MASK_CT_R  (LAYER_BIT(LAYER_SM_R) | LAYER_BIT(LAYER_NV_R))

// Set the conditional layers.

void conditional_layer_set() {

  // Extended layers for number layer and left symbol layer.

  conditional_layer_set_mask(LAYER_NM_LX, MASK_NM_LX);
  conditional_layer_set_mask(LAYER_SM_LX, MASK_SM_LX);

  // Function layer and extended layer.

  conditional_layer_set_mask(LAYER_FN_L,  MASK_FN_L);
  conditional_layer_set_mask(LAYER_FN_LX, MASK_FN_LX);

  // Extended layers for navigation layer and right symbol layer.

  conditional_layer_set_mask(LAYER_NV_RX, MASK_NV_RX);
  conditional_layer_set_mask(LAYER_SM_RX, MASK_SM_RX);

  // Controls layer.

  conditional_layer_set_mask(LAYER_CT_R,  MASK_CT_R);
};
