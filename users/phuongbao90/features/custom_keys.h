// custom_keys.h
#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    CTL_SFT = SAFE_RANGE,
    OPT_SFT,
    CMD_SFT,
    SAFE_SHIFT,
    KC_LCLICK
};

bool custom_keys_process_record_user(uint16_t keycode, keyrecord_t *record);