#pragma once

#define SIX_XXX  _______, _______, _______, _______, _______
#define FIVE_XX  _______, _______, _______, _______, _______
#define FOUR_XX  _______, _______, _______, _______
#define THREE_X  _______, _______, _______

/* --------------------------------- colemak -------------------------------- */

#define ROW4_LEFT_COLEMAK      KC_Q,            KC_W,               KC_F,        KC_P,          KC_B
#define ROW3_LEFT_COLEMAK      CTL_A,           ALT_R,              GUI_S,       SHT_T,         HYP_G
#define ROW2_LEFT_COLEMAK      KC_Z,            KC_X,               KC_C,        NUM_D,         KC_V
#define ROW1_LEFT_COLEMAK      SYM_BSP,         NAV_SPC

#define ROW4_RGHT_COLEMAK      KC_J,            KC_L,               KC_U,        KC_Y,          KC_SCLN
#define ROW3_RGHT_COLEMAK      HYP_M,           SHT_N,              GUI_E,       ALT_I,         CTL_O
#define ROW2_RGHT_COLEMAK      RCMD_K,          NUM_H,              KC_COMM,     KC_DOT,        KC_SLSH
#define ROW1_RGHT_COLEMAK      MOU_ENT,         SHT_TAB

/* ------------------------------- navigation ------------------------------- */

#define ROW4_LEFT_NAV          KC_ESC,          XXXXXXX,            XXXXXXX,     XXXXXXX,       XXXXXXX
#define ROW3_LEFT_NAV          KC_LCTL,         KC_LOPT,            KC_LCMD,     KC_LSFT,       KC_HYPR
#define ROW3_LEFT_NAV_KLOR     KC_LCTL,         KC_LOPT,            KC_LCMD,     SAFE_SHIFT,    KC_HYPR

#define ROW2_LEFT_NAV          CTL_SFT,         OPT_SFT,            CMD_SFT,     XXXXXXX,       XXXXXXX
#define ROW1_LEFT_NAV          XXXXXXX,         XXXXXXX

#define ROW4_RGHT_NAV          KC_PGUP,         C(KC_LEFT),         KC_UP,       C(KC_RIGHT),   KC_HOME
#define ROW3_RGHT_NAV          KC_PGDN,         KC_LEFT,            KC_DOWN,     KC_RGHT,       KC_END
#define ROW2_RGHT_NAV          G(KC_LBRC),      G(KC_RBRC),         LAG(KC_LEFT),LAG(KC_RGHT),  QK_REP
#define ROW1_RGHT_NAV          _______,         KC_RSFT

/* --------------------------------- symbol --------------------------------- */

#define ROW4_LEFT_SYM          KC_EXLM,         KC_AT,              KC_HASH,     KC_DOLLAR,     KC_PERC
#define ROW3_LEFT_SYM          KC_LCTL,         KC_LOPT,            KC_LCMD,     KC_LSFT,       KC_GRV
#define ROW2_LEFT_SYM          KC_CIRC,         KC_AMPR,            KC_ASTR,     KC_PIPE,       KC_BSLS
#define ROW1_LEFT_SYM          _______,         _______

#define ROW4_RGHT_SYM          _______,         _______,            _______,     KC_MINS,       KC_EQL
#define ROW3_RGHT_SYM          KC_EQUAL,        KC_LPRN,            KC_LCBR,     KC_LBRC,       KC_QUOT
#define ROW2_RGHT_SYM          KC_TILD,         KC_RPRN,            KC_RCBR,     KC_RBRC,       KC_MINS
#define ROW1_RGHT_SYM          XXXXXXX,         KC_RSFT

/* ---------------------------------- num ----------------------------------- */

#define ROW4_LEFT_NUM          KC_F4,           KC_F5,              KC_F6,       KC_F12,        KC_F9
#define ROW3_LEFT_NUM          KC_LCTL,         KC_LOPT,            KC_LCMD,     KC_LSFT,       KC_F8
#define ROW2_LEFT_NUM          KC_F1,           KC_F2,              KC_F3,       KC_F10,        KC_F7
#define ROW1_LEFT_NUM          _______,         _______

#define ROW4_RGHT_NUM          KC_PAST,         KC_7,               KC_8,        KC_9,          KC_PPLS
#define ROW3_RGHT_NUM          KC_EQUAL,        KC_4,               KC_5,        KC_6,          KC_QUOT
#define ROW2_RGHT_NUM          KC_0,            KC_1,               KC_2,        KC_3,          KC_MINS
#define ROW1_RGHT_NUM          KC_COMMA,        KC_RSFT

/* ------------------------------ LAYER_MOUSE ----------------------------- */
#define ROW4_LEFT_MOUSE        XXXXXXX,         XXXXXXX,            XXXXXXX,     XXXXXXX,       XXXXXXX
#define ROW3_LEFT_MOUSE        KC_LCTL,         KC_LOPT,            KC_LCMD,     KC_LSFT,       XXXXXXX
#define ROW2_LEFT_MOUSE        XXXXXXX,         XXXXXXX,            XXXXXXX,     XXXXXXX,       XXXXXXX
#define ROW1_LEFT_MOUSE        KC_BTN2,         KC_BTN1

#define ROW4_RGHT_MOUSE        OM_DBLS,         OM_BTNS,            OM_U   ,     OM_BTN2,       HYPR(KC_J)
#define ROW3_RGHT_MOUSE        OM_HLDS,         OM_L   ,            OM_D   ,     OM_R   ,       HYPR(KC_L)
#define ROW2_RGHT_MOUSE        OM_RELS,         OM_W_D ,            OM_W_U ,     OM_BTN3,       HYPR(KC_K)
#define ROW1_RGHT_MOUSE        XXXXXXX,         XXXXXXX

#define ROW1_LEFT_MOUSE_CHA       KC_BTN2,  KC_BTN1,  KC_BTN3

#define ROW1_LEFT_COLEMAK_CHA     SYM_BSP,  NAV_SPC,  _______
#define ROW1_LEFT_NAV_CHA_CHA     _______,  _______,  _______
#define ROW1_LEFT_SYM_CHA_CHA     _______,  _______,  _______
#define ROW1_LEFT_NUM_CHA_CHA     _______,  _______,  _______

/* ------------------------------ SOFLE ----------------------------- */
#define ROW3_LEFT_COLEMAK_SOFLE     CTL_A,   ALT_R,   GUI_S,   SHT_T, HYP_G
#define ROW1_RGHT_COLEMAK_SOFLE     SHT_TAB, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT