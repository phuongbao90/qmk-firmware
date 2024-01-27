#pragma once
#include "quantum.h" // This line includes the combo feature definitions
#include "features/layers.h"

// enum combos {
//     RS_COMBO,
//     ST_COMBO,
//     RT_COMBO,
//     SWITCH_TO_QWERTY,
//     SWITCH_TO_COLEMAK,
//     AZ_BOOT,
// };


// const uint16_t PROGMEM rs_combo[] = {OPT_T(KC_R), CMD_T(KC_S),  COMBO_END};
// const uint16_t PROGMEM st_combo[] = {CMD_T(KC_S), LSFT_T(KC_T), COMBO_END};
// const uint16_t PROGMEM rt_combo[] = {OPT_T(KC_R), LSFT_T(KC_T), COMBO_END};
// const uint16_t PROGMEM az_combo[] = {CTL_T(KC_A), KC_Z, COMBO_END};
// const uint16_t PROGMEM switch_to_qwerty[] = {KC_Y, KC_SCLN, COMBO_END};
// const uint16_t PROGMEM switch_to_colemak[] = {KC_Q, KC_P, COMBO_END};

// combo_t key_combos[] = {
//     [RS_COMBO] = COMBO(rs_combo, LCTL(KC_S)),
//     [ST_COMBO] = COMBO(st_combo, LCTL(KC_T)),
//     [RT_COMBO] = COMBO(rt_combo, LCTL(KC_A)),
//     [AZ_BOOT] =  COMBO(az_combo, QK_BOOT),
//     // [SWITCH_TO_QWERTY] = COMBO(switch_to_qwerty, set_single_persistent_default_layer(_QWERTY)),
//     // [SWITCH_TO_COLEMAK] = COMBO(switch_to_colemak, set_single_persistent_default_layer(_COLEMAK)),
// };

// bool combo_process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_X: return handle_combo(keycode, record, 300);
        
//         default:   return true; // Process all other keycodes normally
//     }
// }

// void combo_matrix_scan_user(void) {
//     if (combo_held_key != 0 && timer_elapsed(combo_key_timer) > TAPPING_TERM) {
//         // If a key is being held and the tapping term has expired, send the corresponding modified key
//         if      (combo_held_key == KC_Q)  tap_code16(KC_ESC);
//         // else if (combo_held_key == KC_X)  tap_code16(LCMD(KC_X));
        
//         combo_held_key = 0; // reset held_key after sending the modified key
//     }
// }



// RESTRICT on which layer combos are enabled
// void process_combo_event(uint16_t combo_index, bool pressed) {
//     if (layer_state_is(_COLEMAK)) { // check if _COLEMAK layer is active
//         switch (combo_index) {
//             case RS_COMBO:
//                 if (pressed) {
//                     register_code16(LCTL(KC_S));
//                 } else {
//                     unregister_code16(LCTL(KC_S));
//                 }
//                 break;
//             case ST_COMBO:
//                 if (pressed) {
//                     register_code16(LCTL(KC_T));
//                 } else {
//                     unregister_code16(LCTL(KC_T));
//                 }
//                 break;
//             case RT_COMBO:
//                 if (pressed) {
//                     register_code16(LCTL(KC_A));
//                 } else {
//                     unregister_code16(LCTL(KC_A));
//                 }
//                 break;
//             case AZ_BOOT:
//                 if (pressed) {
//                     register_code16(QK_BOOT);
//                 } else {
//                     unregister_code16(QK_BOOT);
//                 }
//                 break;
//             case SWITCH_TO_QWERTY:
//                 if (pressed) {
//                     layer_off(_COLEMAK);
//                     layer_on(_QWERTY);
//                     dprint("Successfully switched to _QWERTY layer.\n");
//                 }
//                 break;
//             default:
//                 // log an error
//                 break;
//         }
//     }
//     else if (layer_state_is(_QWERTY)) {
//           dprint("Switching to _COLEMAK layer...\n");
//         switch (combo_index) {
//           dprint("Switching to _COLEMAK layer...\n");
//           case SWITCH_TO_COLEMAK:
//             dprint("Switching to _COLEMAK layer...\n");
//             if (pressed) {
//                 layer_off(_QWERTY);
//                 layer_on(_COLEMAK);
//                 if (layer_state_is(_COLEMAK)) {
//                     dprint("Successfully switched to _COLEMAK layer.\n");
//                 } else {
//                     dprint("Failed to switch to _COLEMAK layer.\n");
//                 }
//             }
//             break;
//           default:
//             // log an error
//             dprint("Error: Invalid combo_index in _QWERTY layer.\n");
//             break;
//         }

//     }
// }

