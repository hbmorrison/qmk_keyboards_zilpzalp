#include QMK_KEYBOARD_H

// Override the default bootmagic_should_restart() function to decide whether to
// reboot based on whether any key in the first row is held down at power on.

bool bootmagic_should_reset(void) {
  uint8_t row = BOOTMAGIC_ROW;

  // If the keyboard is a split, find the row that corresponds to the top row on
  // the right side of the keyboard.

# if defined(SPLIT_KEYBOARD) && defined(BOOTMAGIC_ROW_RIGHT)
  if (! is_keyboard_left())
    row = BOOTMAGIC_ROW_RIGHT;
# endif

  // Return the bits for the entire row. If any keys are held down there will be
  // at least one bit set, which will make the row value not zero.

  return matrix_get_row(row) > 0;
}
