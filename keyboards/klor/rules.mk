# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
SPLIT_KEYBOARD = yes
SWAP_HANDS_ENABLE = no

# OLED_ENABLE = yes
# OLED_DRIVER = SSD1306
# ENCODER_ENABLE = yes

#HAPTIC FEEDBACK
HAPTIC_DRIVER = DRV2605L

#PER KEY RGB
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = no      # Enable keyboard RGB matrix (do not use together with RGBLIGHT_ENABLE)
RGB_MATRIX_DRIVER = WS2812  # RGB matrix driver support
RGB_MATRIX_SUPPORTED = no