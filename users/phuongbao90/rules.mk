SRC += phuongbao90.c
VPATH += keyboards/gboards/
VPATH += combos.def

# RP2040-specific options
# ALLOW_WARNINGS = yes

# --------------------------------------------------------------------
LTO_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = yes   
CAPS_WORD_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
REPEAT_KEY_ENABLE = no
EXTRAKEY_ENABLE = no
KEY_OVERRIDE_ENABLE = no

TAP_DANCE_ENABLE = no
NKRO_ENABLE = yes
PERMISSIVE_HOLD = yes
LTO_ENABLE = yes

