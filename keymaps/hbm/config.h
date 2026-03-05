#pragma once

// Enable permissive hold.

#define PERMISSIVE_HOLD

// Set the tapping term.

#define TAPPING_TERM 180

// Reduce the caps word timeout.

#define CAPS_WORD_IDLE_TIMEOUT 6000

// Increase the combo term by a large margin so that oneshot modifier key
// presses can be combined.

#define COMBO_TERM 2000

// Do not auto shift numbers or symbols by default.

#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_SYMBOLS

// Enable key repeat behaviour for auto shifted keys that are shifted.

#define AUTO_SHIFT_REPEAT

// Enable auto shift on tap-hold keys.

#define RETRO_SHIFT 500
