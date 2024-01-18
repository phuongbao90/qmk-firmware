#pragma once
#include QMK_KEYBOARD_H
#include "taphold.h"
#include "key_modifiers.h"
#include "layers.h"

uint16_t tap_hold_key_timer;
uint16_t tap_hold_held_key;

static bool handle_tap_hold(uint16_t keycode, keyrecord_t *record, uint16_t timer_threshold) {
    if (record->event.pressed) {
        tap_hold_key_timer = timer_read();
        tap_hold_held_key = keycode;
    } else {
        if (timer_elapsed(tap_hold_key_timer) < timer_threshold) {
            tap_code16(keycode);
        }
        tap_hold_held_key = 0;
    }
    return false;
}

bool tap_hold_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case Q_ESC:   return handle_tap_hold(keycode, record, 150);
        case KC_X:    return handle_tap_hold(keycode, record, 200);
        case KC_C:    return handle_tap_hold(keycode, record, 200);
        case KC_V:    return handle_tap_hold(keycode, record, 200);
        case PARENS:  return handle_tap_hold(keycode, record, 200);
        // case NAV_SPC: return handle_tap_hold(keycode, record, 150);
        // case SYM_BSP: return handle_tap_hold(keycode, record, 150);
        // case AT_HASH: return handle_tap_hold(keycode, record, 150);
        default:   return true; // Process all other keycodes normally
    }
}

void tap_hold_matrix_scan_user(void) {
    if (tap_hold_held_key != 0 && timer_elapsed(tap_hold_key_timer) > TAPPING_TERM) {
        // If a key is being held and the tapping term has expired, send the corresponding modified key
        if      (tap_hold_held_key == Q_ESC)    tap_code16(KC_ESC);
        else if (tap_hold_held_key == KC_X)     tap_code16(LCMD(KC_X));
        else if (tap_hold_held_key == KC_C)     tap_code16(LCMD(KC_C));
        else if (tap_hold_held_key == KC_V)     tap_code16(LCMD(KC_V));
        else if (tap_hold_held_key == PARENS)   tap_code16(KC_RPRN);
        // else if (tap_hold_held_key == NAV_SPC)  layer_invert(_NAV);
        // else if (tap_hold_held_key == SYM_BSP)  layer_invert(_SYM);
        // else if (tap_hold_held_key == AT_HASH)  tap_code16(KC_HASH);
        tap_hold_held_key = 0; // reset held_key after sending the modified key
    }
}


