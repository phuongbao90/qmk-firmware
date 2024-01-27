#pragma once
#include QMK_KEYBOARD_H
// #include "XXXX.h"

uint16_t XXXX_key_timer;
uint16_t XXXX_held_key;

static bool handle_XXXX(uint16_t keycode, keyrecord_t *record, uint16_t timer_threshold) {
    if (record->event.pressed) {
        XXXX_key_timer = timer_read();
        XXXX_held_key = keycode;
    } else {
        if (timer_elapsed(XXXX_key_timer) < timer_threshold) {
            tap_code(keycode);
        }
        XXXX_held_key = 0;
    }
    return false;
}


bool XXXX_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_X: return handle_XXXX(keycode, record, 300);
        default:   return true; // Process all other keycodes normally
    }
}

void XXXX_matrix_scan_user(void) {
    if (XXXX_held_key != 0 && timer_elapsed(XXXX_key_timer) > TAPPING_TERM) {
        // If a key is being held and the tapping term has expired, send the corresponding modified key
        if      (XXXX_held_key == KC_Q)  tap_code16(KC_ESC);
        else if (XXXX_held_key == KC_X)  tap_code16(LCMD(KC_X));

        XXXX_held_key = 0; // reset held_key after sending the modified key
    }
}
