# QMK features.

AUTO_SHIFT_ENABLE = yes
CAPS_WORD_ENABLE  = yes

# Additional code.

SRC += bootmagic.c
SRC += layers.c
SRC += mods.c
SRC += process.c

# Optional code.

ifeq ($(strip $(AUTO_SHIFT_ENABLE)), yes)
  SRC += autoshift.c
endif

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
  SRC += capsword.c
endif
