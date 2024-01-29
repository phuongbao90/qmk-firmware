#include "custom_keys.h"

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

