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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
       XXXXXXX,     Q_ESC,       KC_W,       KC_F,       KC_P,         KC_B,                   KC_J,        KC_L,       KC_U,        KC_Y,       KC_SCLN,    XXXXXXX,    
       XXXXXXX,     CTL_A,       ALT_R,      GUI_S,      SHT_T,        HYP_G,                  HYP_M,       SHT_N,      GUI_E,       ALT_I,      CTL_O,      XXXXXXX,    
       XXXXXXX,     KC_Z,        KC_X,       KC_C,       NUM_D,        KC_V,                   KC_K,        RCMD_H,     KC_COMM,     KC_DOT,     KC_SLSH,    XXXXXXX,    
                                                       SYM_BSP,    NAV_SPC,    XXXXXXX,        MOU_ENT,     KC_TAB
  ),
  [_NAV] = LAYOUT(
       XXXXXXX,     KC_ESC,     XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,               KC_PGUP,     C(KC_LEFT), KC_UP,       C(KC_RIGHT), KC_HOME,    XXXXXXX,
       XXXXXXX,     KC_LCTL,    KC_LOPT,    KC_LCMD,     KC_LSFT,       KC_HYPR,               KC_PGDN,     KC_LEFT,    KC_DOWN,     KC_RGHT,     KC_END,     XXXXXXX,
       XXXXXXX,     CTL_SFT,    OPT_SFT,    CMD_SFT,     XXXXXXX,       XXXXXXX,               G(KC_LBRC),  G(KC_RBRC), LAG(KC_LEFT),LAG(KC_RGHT),XXXXXXX,    XXXXXXX,
                                                       _______,     TG(_NAV),   XXXXXXX,       _______,     TG(_NAV)
  ),
  [_SYM] = LAYOUT(
       XXXXXXX,     KC_GRV,     XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,               KC_MINUS,    KC_EXLM,    KC_LBRC,     KC_RBRC,     KC_SCLN,    XXXXXXX,
       XXXXXXX,     XXXXXXX,    XXXXXXX,    KC_AT,       KC_HASH,       XXXXXXX,               KC_EQUAL,    KC_AMPR,    KC_LPRN,     KC_RPRN,     KC_QUOT,    XXXXXXX,
       XXXXXXX,     XXXXXXX,    XXXXXXX,    KC_PERC,     KC_ASTR,       KC_CIRC,               KC_BSLS,     KC_DOLLAR,  KC_COMM,     KC_DOT,      KC_SLSH,    XXXXXXX,
                                                       _______,     _______,    XXXXXXX,       _______,     TG(_SYM)
  ),
  [_NUM] = LAYOUT(
       XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,               KC_MINUS,    KC_7,       KC_8,        KC_9,        KC_PPLS,    XXXXXXX,
       XXXXXXX,     KC_F1,      KC_F12,     XXXXXXX,     XXXXXXX,       XXXXXXX,               KC_EQUAL,    KC_4,       KC_5,        KC_6,        KC_MINUS,   XXXXXXX,
       XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,               KC_0,        KC_1,       KC_2,        KC_3,        KC_SLSH,    XXXXXXX,
                                                       _______,     _______,    XXXXXXX,       KC_COMMA,    KC_DOT
  ),
  [_MOUSE] = LAYOUT(
       XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,               XXXXXXX,     XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,
       XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,               XXXXXXX,     XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,
       XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,               XXXXXXX,     XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,
                                                       _______,     _______,    XXXXXXX,       _______,     XXXXXXX
  ),
};
// clang-format on

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
