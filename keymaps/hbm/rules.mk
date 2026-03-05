# QMK features.

AUTO_SHIFT_ENABLE = yes
CAPS_WORD_ENABLE  = yes
COMBO_ENABLE      = yes

# Enabling the console enables debug messages.

CONSOLE_ENABLE = yes

# Additional code.

SRC += bootmagic.c
SRC += capsword.c
SRC += layers.c

# Combos need to be part of the introspection logic.

ifeq ($(strip $(COMBO_ENABLE)), yes)
  INTROSPECTION_KEYMAP_C = introspection.c
endif
