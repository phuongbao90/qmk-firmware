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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT(
  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                         XXXXXXX,    XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
  XXXXXXX,   Q_ESC,    KC_W,     KC_F,     KC_P,     KC_B,                            KC_J,       KC_L,       KC_U,     KC_Y,     KC_SCLN,   XXXXXXX,
  XXXXXXX,   CTL_A,    ALT_R,    GUI_S,    SHT_T,    HYP_G,                           HYP_M,      SHT_N,      GUI_E,    ALT_I,    CTL_O,     XXXXXXX,
  XXXXXXX,   KC_Z,     KC_X,     KC_C,     NUM_D,    KC_V,     QK_BOOT,   QK_BOOT,    RCMD_K,     NUM_H,     KC_COMM,  KC_DOT,   KC_SLSH,   XXXXXXX,
                    XXXXXXX,  XXXXXXX,  XXXXXXX,   SYM_BSP,    NAV_SPC,   MOU_ENT,    KC_TAB,     XXXXXXX,    XXXXXXX,    XXXXXXX
),

[_NAV] = LAYOUT(
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                             XXXXXXX,     XXXXXXX,     XXXXXXX,      XXXXXXX,      XXXXXXX,   XXXXXXX, 
  XXXXXXX,   KC_ESC,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                             KC_PGUP,     C(KC_LEFT),  KC_UP,        C(KC_RIGHT),  KC_HOME,   XXXXXXX,
  XXXXXXX,   KC_LCTL,   KC_LOPT,   KC_LCMD,   KC_LSFT,   KC_HYPR,                             KC_PGDN,     KC_LEFT,     KC_DOWN,      KC_RGHT,      KC_END,    XXXXXXX,
  XXXXXXX,   CTL_SFT,   OPT_SFT,   CMD_SFT,   XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,   G(KC_LBRC),  G(KC_RBRC),  LAG(KC_LEFT), LAG(KC_RGHT), XXXXXXX,   XXXXXXX,
          XXXXXXX,        XXXXXXX,        XXXXXXX,       TG(_NAV),    XXXXXXX,                XXXXXXX,     KC_RSFT,      XXXXXXX,     XXXXXXX,      XXXXXXX
),

[_SYM] = LAYOUT(
  XXXXXXX,     XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,    XXXXXXX,                          XXXXXXX,    XXXXXXX  ,  XXXXXXX,    XXXXXXX ,   XXXXXXX ,   XXXXXXX,
  XXXXXXX,     KC_EXLM,    KC_AT,      KC_HASH,     KC_DOLLAR,     KC_PERC,                KC_PAST,     KC_GRV,     KC_DOLLAR,   KC_PIPE,     KC_PPLS,    XXXXXXX,
  XXXXXXX,     KC_LCTL,    KC_LOPT,    KC_LCMD,     KC_LSFT,       KC_CIRC,                KC_EQUAL,    KC_LPRN,    KC_LCBR,     KC_LBRC,     KC_QUOT,    XXXXXXX,
  XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,     KC_BSLS,       KC_AMPR,XXXXXXX,XXXXXXX,KC_TILD,     KC_RPRN,    KC_RCBR,     KC_RBRC,     KC_MINS,    XXXXXXX,
              XXXXXXX,     XXXXXXX,    XXXXXXX,     XXXXXXX,       XXXXXXX,                XXXXXXX,     KC_RSFT,    XXXXXXX,     XXXXXXX,     XXXXXXX
),

[_NUM] = LAYOUT(
  XXXXXXX,  XXXXXXX ,   XXXXXXX ,   XXXXXXX ,   XXXXXXX ,  XXXXXXX,                          XXXXXXX,    XXXXXXX  ,  XXXXXXX,    XXXXXXX ,   XXXXXXX ,   XXXXXXX,
  XXXXXXX,     KC_F7  ,    KC_F8  ,    KC_F9  ,     KC_F12 ,       XXXXXXX,                  KC_PAST,     KC_7,       KC_8,        KC_9,        KC_PPLS,    XXXXXXX,
  XXXXXXX,     KC_F4,      KC_F5 ,     KC_F6  ,     KC_F11 ,       XXXXXXX,                  KC_EQUAL,    KC_4,       KC_5,        KC_6,        KC_QUOT,    XXXXXXX,
  XXXXXXX,     KC_F1,      KC_F2  ,    KC_F3  ,     KC_F10 ,       XXXXXXX, XXXXXXX,XXXXXXX, KC_0,        KC_1,       KC_P2,       KC_P3,       KC_MINS,    XXXXXXX,
              XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,    KC_SPC,                       KC_COMMA,    KC_RSFT,    XXXXXXX,    XXXXXXX,      XXXXXXX
),
/* VNI
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |   |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |--------|   |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
// [_MOUSE] = LAYOUT(
//   XXXXXXX,    XXXXXXX,      XXXXXXX,     XXXXXXX ,    XXXXXXX ,     XXXXXXX,                         XXXXXXX,    XXXXXXX  ,  XXXXXXX,     XXXXXXX ,   XXXXXXX ,   XXXXXXX,
//   XXXXXXX,    XXXXXXX,      XXXXXXX,     XXXXXXX  ,   XXXXXXX ,     XXXXXXX,                         KC_WH_U,    KC_BTN1  ,  KC_MS_U ,    KC_BTN2 ,   KC_ACL0 ,   XXXXXXX,
//   XXXXXXX,    XXXXXXX,      XXXXXXX,     XXXXXXX ,    XXXXXXX ,     XXXXXXX ,                        KC_WH_D,    KC_MS_L ,   KC_MS_D ,    KC_MS_R ,   KC_ACL1 ,   XXXXXXX,
//   XXXXXXX,    XXXXXXX,      XXXXXXX,     XXXXXXX ,    XXXXXXX ,     XXXXXXX,    XXXXXXX,   XXXXXXX,  KC_F16 ,    KC_WH_L ,   KC_BTN3 ,    KC_WH_R ,   KC_ACL2 ,   XXXXXXX,
//                   XXXXXXX,      XXXXXXX,      XXXXXXX,     XXXXXXX,      XXXXXXX,                  XXXXXXX,      XXXXXXX,      XXXXXXX,     XXXXXXX,    XXXXXXX
// ),
// [_QWERTY] = LAYOUT(
//   XXXXXXX,    XXXXXXX ,      XXXXXXX ,     XXXXXXX ,    XXXXXXX ,     XXXXXXX,                         XXXXXXX,    XXXXXXX  ,  XXXXXXX,    XXXXXXX ,   XXXXXXX ,   XXXXXXX,
//   XXXXXXX,    KC_Q  ,       KC_W  ,      KC_E  ,     KC_R  ,      KC_T  ,                         KC_Y  ,    KC_U  ,    KC_I  ,    KC_O  ,    KC_P ,    XXXXXXX,
//   XXXXXXX,    KC_A      ,    KC_S    ,     KC_D    ,    KC_F    ,     KC_G    ,                        HYPR_T(KC_H)    ,   LSFT_T(KC_J)    ,   CMD_T(KC_K)    ,   OPT_T(KC_L)    ,   CTL_T(KC_0)    ,   XXXXXXX,
//   XXXXXXX,    KC_Z,        KC_X ,      KC_C ,     KC_V ,      KC_B ,    XXXXXXX,   XXXXXXX,  KC_N ,    KC_M ,    TG(_COLEMAK) ,    TG(_COLEMAK) ,    TG(_COLEMAK) ,   XXXXXXX,
//                   XXXXXXX,      XXXXXXX,      XXXXXXX,     LT(MO(_SYM),KC_BSPC),      LT(MO(_NAV),KC_SPC),                  LT(MO(_NUM),KC_ENT),      LT(OSL(_VNI),KC_TAB),      XXXXXXX,      XXXXXXX,      XXXXXXX
// )
};


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


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A T R I X _ S C A N _ U S E R                                                                                                                               │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

void matrix_scan_user(void) {
  tap_hold_matrix_scan_user();
  one_shot_matrix_scan_user();
}

