#include "features/layers.h"
#include "features/key_modifiers.h"

#include QMK_KEYBOARD_H
// #include "g/keymap_engine.h"
#include "g/keymap_combo.h"
#include <stdio.h>
#include <string.h>

#include "features/custom_keys.c"
#include "features/taphold.c"
#include "features/one_shot.c"

/* -------------------------------------------------------------------------- */
/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 2
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

/* -------------------------------------------------------------------------- */



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
       QK_BOOT,     Q_ESC,       KC_W,       KC_F,       KC_P,         KC_B,                   KC_J,        KC_L,       RCMD_U,      KC_Y,       KC_SCLN,    QK_BOOT,    
       XXXXXXX,     CTL_A,       ALT_R,      GUI_S,      SHT_T,        HYP_G,                  HYP_M,       SHT_N,      GUI_E,       ALT_I,      CTL_O,      XXXXXXX,    
       XXXXXXX,     KC_Z,        KC_X,       KC_C,       NUM_D,        KC_V,                   KC_K,        NUM_H,      KC_COMM,     KC_DOT,     KC_SLSH,    XXXXXXX,    
                                                       SYM_BSP,    NAV_SPC,    XXXXXXX,        KC_ENT,     SHT_TAB
  ),
  [_NAV] = LAYOUT(
       XXXXXXX,     KC_ESC,     XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,               KC_PGUP,     C(KC_LEFT), KC_UP,       C(KC_RIGHT), KC_HOME,    XXXXXXX,
       XXXXXXX,     KC_LCTL,    KC_LOPT,    KC_LCMD,     KC_LSFT,       KC_HYPR,               KC_PGDN,     KC_LEFT,    KC_DOWN,     KC_RGHT,     KC_END,     XXXXXXX,
       XXXXXXX,     CTL_SFT,    OPT_SFT,    CMD_SFT,     XXXXXXX,       XXXXXXX,               G(KC_LBRC),  G(KC_RBRC), LAG(KC_LEFT),LAG(KC_RGHT),XXXXXXX,    XXXXXXX,
                                                       _______,     TG(_NAV),   XXXXXXX,       _______,     KC_RSFT
  ),
  [_SYM] = LAYOUT(
       XXXXXXX,     KC_EXLM,    KC_AT,      KC_HASH,     KC_DOLLAR,     KC_PERC,               KC_PAST,     KC_GRV,     KC_DOLLAR,   KC_PIPE,     KC_PPLS,    XXXXXXX,
       XXXXXXX,     KC_LCTL,    KC_LOPT,    KC_LCMD,     KC_LSFT,       KC_CIRC,               KC_EQUAL,    KC_LPRN,    KC_LCBR,     KC_LBRC,     KC_PMNS,    XXXXXXX,
       XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,     KC_BSLS,       KC_AMPR,               KC_TILD,     KC_RPRN,    KC_RCBR,     KC_RBRC,     LSFT(KC_MINS),XXXXXXX,
                                                       XXXXXXX,     XXXXXXX,     XXXXXXX,      XXXXXXX,     KC_RSFT // one-shot shift
  ),
//   [_SYM] = LAYOUT(
//        XXXXXXX,     KC_GRV,     XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,               KC_MINUS,    KC_EXLM,    KC_LBRC,     KC_RBRC,     KC_SCLN,    XXXXXXX,
//        XXXXXXX,     XXXXXXX,    XXXXXXX,    KC_AT,       KC_HASH,       XXXXXXX,               KC_EQUAL,    KC_AMPR,    KC_LPRN,     KC_RPRN,     KC_QUOT,    XXXXXXX,
//        XXXXXXX,     XXXXXXX,    XXXXXXX,    KC_PERC,     KC_ASTR,       KC_CIRC,               KC_BSLS,     KC_DOLLAR,  KC_COMM,     KC_DOT,      KC_SLSH,    XXXXXXX,
//                                                        _______,     _______,    XXXXXXX,       _______,     TG(_SYM)
//   ),
  [_NUM] = LAYOUT(
       XXXXXXX,     KC_F7  ,    KC_F8  ,    KC_F9  ,     KC_F12 ,       XXXXXXX,               KC_PAST,     KC_7,       KC_8,        KC_9,        KC_PPLS,    XXXXXXX,
       XXXXXXX,     KC_F4,      KC_F5 ,     KC_F6  ,     KC_F11 ,       XXXXXXX,               KC_EQUAL,    KC_4,       KC_5,        KC_6,        KC_PMNS,    XXXXXXX,
       XXXXXXX,     KC_F1,      KC_F2  ,    KC_F3  ,     KC_F10 ,       XXXXXXX,               KC_0,        KC_1,       KC_P2,       KC_P3,       LSFT(KC_MINS),XXXXXXX,
                                                       _______,     _______,    XXXXXXX,       KC_COMMA,    KC_RSFT
  ),
    [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    XXXXXXX, XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format 

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ P R O C E S S _ R E C O R D _ U S E R                                                                                                                               │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!tap_hold_process_record_user(keycode, record)) return false;
    if (!one_shot_process_record_user(keycode, record)) return false;
    if (!custom_keys_process_record_user(keycode, record)) return false;

    return true;
}


void general_matrix_scan_tasks(void) {
    tap_hold_matrix_scan_user();
    one_shot_matrix_scan_user();
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
    pointer_layer_scan_tasks();
}