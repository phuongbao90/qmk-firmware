#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "g/keymap_combo.h"
#include "phuongbao90.h"

#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_wrapper(
    XXXXXXX,    FIVE_XX,                                      FIVE_XX,               XXXXXXX,
    XXXXXXX,    ROW4_LEFT_COLEMAK,                            ROW4_RGHT_COLEMAK,     XXXXXXX,
    XXXXXXX,    ROW3_LEFT_COLEMAK_SOFLE,                      ROW3_RGHT_COLEMAK,     XXXXXXX,
    XXXXXXX,    ROW2_LEFT_COLEMAK,   QK_BOOT,     QK_BOOT,    ROW2_RGHT_COLEMAK,     XXXXXXX,
    THREE_X,    ROW1_LEFT_COLEMAK,                            ROW1_RGHT_COLEMAK_SOFLE     
),

[_NAV] = LAYOUT_wrapper(
    XXXXXXX,    FIVE_XX,                                    FIVE_XX,               XXXXXXX,
    XXXXXXX,    ROW4_LEFT_NAV,                              ROW4_RGHT_NAV,         XXXXXXX,
    XXXXXXX,    ROW3_LEFT_NAV,                              ROW3_RGHT_NAV,         XXXXXXX,
    XXXXXXX,    ROW2_LEFT_NAV,    XXXXXXX,      XXXXXXX,    ROW2_RGHT_NAV,         XXXXXXX,
    THREE_X,    ROW1_LEFT_NAV,                              ROW1_RGHT_NAV,         THREE_X
),

[_SYM] = LAYOUT_wrapper(
    XXXXXXX,     FIVE_XX,                                   FIVE_XX,               XXXXXXX,
    XXXXXXX,     ROW4_LEFT_SYM,                             ROW4_RGHT_SYM,         XXXXXXX,
    XXXXXXX,     ROW3_LEFT_SYM,                             ROW3_RGHT_SYM,         XXXXXXX,
    XXXXXXX,     ROW2_LEFT_SYM,   XXXXXXX,      XXXXXXX,    ROW2_RGHT_SYM,         XXXXXXX,
    THREE_X,     ROW1_LEFT_SYM,                             ROW1_RGHT_SYM,         THREE_X
),

[_NUM] = LAYOUT_wrapper(
    XXXXXXX,     FIVE_XX,                                   FIVE_XX,               XXXXXXX,
    XXXXXXX,     ROW4_LEFT_NUM,                             ROW4_RGHT_NUM,         XXXXXXX,
    XXXXXXX,     ROW3_LEFT_NUM,                             ROW3_RGHT_NUM,         XXXXXXX,
    XXXXXXX,     ROW2_LEFT_NUM,   XXXXXXX,      XXXXXXX,    ROW2_RGHT_NUM,         XXXXXXX,
    THREE_X,     ROW1_LEFT_NUM,                             ROW1_RGHT_NUM,         THREE_X
),
[LAYER_POINTER] = LAYOUT_wrapper(
    XXXXXXX,     FIVE_XX,                                     FIVE_XX,               XXXXXXX,
    XXXXXXX,     ROW4_LEFT_MOUSE,                             ROW4_RGHT_MOUSE,         XXXXXXX,
    XXXXXXX,     ROW3_LEFT_MOUSE,                             ROW3_RGHT_MOUSE,         XXXXXXX,
    XXXXXXX,     ROW2_LEFT_MOUSE,   XXXXXXX,      XXXXXXX,    ROW2_RGHT_MOUSE,         XXXXXXX,
    THREE_X,     ROW1_LEFT_MOUSE,                             ROW1_RGHT_MOUSE,         THREE_X
),
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ P R O C E S S _ R E C O R D _ U S E R                                                                                                                               │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!tap_hold_process_record_user(keycode, record)) return false;
    // if (!one_shot_process_record_user(keycode, record)) return false;
    if (!custom_keys_process_record_user(keycode, record)) return false;
    if (!process_orbital_mouse(keycode, record)) { return false; }

    return true;
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A T R I X _ S C A N _ U S E R                                                                                                                               │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

void matrix_scan_user(void) {
  tap_hold_matrix_scan_user();
  orbital_mouse_task();
  // one_shot_matrix_scan_user();
}

