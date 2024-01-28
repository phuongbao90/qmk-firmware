#include "quantum.h"
#include "action.h"
#include "phuongbao90.h"

bool custom_keys_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_SFT: 
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            return false;
        case OPT_SFT: 
            if (record->event.pressed) {
                register_code(KC_LOPT);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LOPT);
                unregister_code(KC_LSFT);
            }
            return false;
        case CMD_SFT: 
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LCMD);
                unregister_code(KC_LSFT);
            }
            return false;
        case SAFE_SHIFT:
            if (record->event.pressed) {
                unregister_code(KC_LCMD);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
            }
            return false;
    }
    return true;
}


/* -------------------------------------------------------------------------- */
/*                                   taphold                                  */
/* -------------------------------------------------------------------------- */
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
        case KC_Q:    return handle_tap_hold(keycode, record, 150);
        case KC_Z:    return handle_tap_hold(keycode, record, 200);
        case KC_X:    return handle_tap_hold(keycode, record, 200);
        case KC_C:    return handle_tap_hold(keycode, record, 200);
        case KC_V:    return handle_tap_hold(keycode, record, 200);
        
        default:   return true; // Process all other keycodes normally
    }
}

void tap_hold_matrix_scan_user(void) {
    if (tap_hold_held_key != 0 && timer_elapsed(tap_hold_key_timer) > TAPPING_TERM) {
        // If a key is being held and the tapping term has expired, send the corresponding modified key
        if      (tap_hold_held_key == KC_Q)     tap_code16(KC_ESC);
        else if (tap_hold_held_key == KC_Z)     tap_code16(LCMD(KC_S));
        else if (tap_hold_held_key == KC_X)     tap_code16(LCMD(KC_X));
        else if (tap_hold_held_key == KC_C)     tap_code16(LCMD(KC_C));
        else if (tap_hold_held_key == KC_V)     tap_code16(LCMD(KC_V));
        
        tap_hold_held_key = 0; // reset held_key after sending the modified key
    }
}


/* -------------------------------------------------------------------------- */
/*                                   oneshot                                  */
/* -------------------------------------------------------------------------- */
uint16_t one_shot_key_timer;
uint16_t one_shot_held_key;

bool one_shot_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:   return true; // Process all other keycodes normally
    }
}

void one_shot_matrix_scan_user(void) {
}
