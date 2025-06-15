#include QMK_KEYBOARD_H

#include <stdio.h>
#include <string.h>
#include "g/keymap_combo.h"
#include "phuongbao90.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)


/* -------------------------------------------------------------------------- */
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_wrapper(
        QK_BOOT,      ROW4_LEFT_COLEMAK,           ROW4_RGHT_COLEMAK,     QK_BOOT,
        KC_LEFT,      ROW3_LEFT_COLEMAK,           ROW3_RGHT_COLEMAK,     KC_UP,
        KC_RGHT,      ROW2_LEFT_COLEMAK,           ROW2_RGHT_COLEMAK,     KC_DOWN,
                      ROW1_LEFT_COLEMAK_CHA,       ROW1_RGHT_COLEMAK
  ),
  [_NAV] = LAYOUT_wrapper(
        XXXXXXX,      ROW4_LEFT_NAV,               ROW4_RGHT_NAV,         XXXXXXX,
        XXXXXXX,      ROW3_LEFT_NAV,               ROW3_RGHT_NAV,         XXXXXXX,
        XXXXXXX,      ROW2_LEFT_NAV,               ROW2_RGHT_NAV,         XXXXXXX,
                      ROW1_LEFT_NAV_CHA_CHA,       ROW1_RGHT_NAV
  ),
  [_SYM] = LAYOUT_wrapper(
        XXXXXXX,      ROW4_LEFT_SYM,               ROW4_RGHT_SYM,         XXXXXXX,
        XXXXXXX,      ROW3_LEFT_SYM,               ROW3_RGHT_SYM,         XXXXXXX,
        XXXXXXX,      ROW2_LEFT_SYM,               ROW2_RGHT_SYM,         XXXXXXX,
                      ROW1_LEFT_SYM_CHA_CHA,       ROW1_RGHT_SYM
  ),
  [_NUM] = LAYOUT_wrapper(
        XXXXXXX,      ROW4_LEFT_NUM,               ROW4_RGHT_NUM,         XXXXXXX,
        XXXXXXX,      ROW3_LEFT_NUM,               ROW3_RGHT_NUM,         XXXXXXX,
        XXXXXXX,      ROW2_LEFT_NUM,               ROW2_RGHT_NUM,         XXXXXXX,
                      ROW1_LEFT_NUM_CHA_CHA,       ROW1_RGHT_NUM
  ),
  [LAYER_POINTER] = LAYOUT_wrapper(
        XXXXXXX,      ROW4_LEFT_MOUSE,             ROW4_RGHT_MOUSE,       XXXXXXX,
        XXXXXXX,      ROW3_LEFT_MOUSE,             ROW3_RGHT_MOUSE,       XXXXXXX,
        XXXXXXX,      ROW2_LEFT_MOUSE,             ROW2_RGHT_MOUSE,       XXXXXXX,
                      ROW1_LEFT_MOUSE_CHA,         ROW1_RGHT_MOUSE
  ),
  [VSCODE] = LAYOUT_wrapper(
        XXXXXXX,      ROW4_LEFT_VSCODE,             ROW4_RGHT_VSCODE,       XXXXXXX,
        XXXXXXX,      ROW3_LEFT_VSCODE,             ROW3_RGHT_VSCODE,       XXXXXXX,
        XXXXXXX,      ROW2_LEFT_VSCODE,             ROW2_RGHT_VSCODE,       XXXXXXX,
            _______,  ROW1_LEFT_VSCODE,             ROW1_RGHT_VSCODE
  ),
};
// clang-format 

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ P R O C E S S _ R E C O R D _ U S E R                                                                                                                               │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!tap_hold_process_record_user(keycode, record)) return false;
    // if (!one_shot_process_record_user(keycode, record)) return false;
    if (!custom_keys_process_record_user(keycode, record)) return false;
    // if (!process_orbital_mouse(keycode, record)) { return false; }

    return true;
}


void general_matrix_scan_tasks(void) {
    tap_hold_matrix_scan_user();
    // orbital_mouse_task();
    // one_shot_matrix_scan_user();
    // Add other general matrix scan tasks here
}

/* -------------------------------------------------------------------------- */
/** \brief Automatically enable sniping-mode on the pointer layer. */
#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void pointer_layer_scan_tasks(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE


void matrix_scan_user(void) {
    general_matrix_scan_tasks();
    // pointer_layer_scan_tasks();
}
