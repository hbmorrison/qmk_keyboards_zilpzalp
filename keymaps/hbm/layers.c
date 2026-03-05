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

// Add the conditional layers.

void add_conditional_layers() {

  // Add the extended number layer, extended nav layer and both extended symbol
  // layers as conditional layers.

  set_conditional_layer_mask(LAYER_NM_LX, MASK_NM_LX);
  set_conditional_layer_mask(LAYER_NV_RX, MASK_NV_RX);
  set_conditional_layer_mask(LAYER_SM_LX, MASK_SM_LX);
  set_conditional_layer_mask(LAYER_SM_RX, MASK_SM_RX);

  // Add the function layer and its extended layer as conditional layers.

  set_conditional_layer_mask(LAYER_FN_L,  MASK_FN_L);
  set_conditional_layer_mask(LAYER_FN_LX, MASK_FN_LX);

  // Add the controls layer as a conditional layer.

  set_conditional_layer_mask(LAYER_CT_R,  MASK_CT_R);
};
