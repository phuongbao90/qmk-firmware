SRC += phuongbao90.c
SRC += features/orbital_mouse.c
SRC += features/one_shot.c
SRC += features/custom_keys.c
SRC += features/taphold.c
SRC += features/tap_dances.c

VPATH += keyboards/gboards/
VPATH += combos.def


# RP2040-specific options
# ALLOW_WARNINGS = yes

# --------------------------------------------------------------------
SPLIT_KEYBOARD = yes
BOOTMAGIC_ENABLE = yes
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
PERMISSIVE_HOLD = yes
MOUSE_ENABLE = yes
TAP_DANCE_ENABLE = yes
REPEAT_KEY_ENABLE = yes

NKRO_ENABLE = no
LTO_ENABLE = no
EXTRAKEY_ENABLE = no
KEY_OVERRIDE_ENABLE = no

RGB_MATRIX_SUPPORTED = no  # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = no    # RGB underglow is supported, but not enabled by default
RGB_MATRIX_ENABLE = no     # Enable keyboard RGB matrix functionality