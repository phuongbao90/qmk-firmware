#pragma once

#define SIX_XXX  _______, _______, _______, _______, _______
#define FIVE_XX  _______, _______, _______, _______, _______
#define FOUR_XX  _______, _______,____, _______
#define THREE_X  _______, _______, _______

#define KC_SWITCH_APP LOPT(KC_GRAVE)

/* --------------------------------- colemak -------------------------------- */

#define ROW4_LEFT_COLEMAK      KC_Q,            KC_W,               KC_F,        KC_P,          KC_B
#define ROW3_LEFT_COLEMAK      CTL_A,           ALT_R,              GUI_S,       SHT_T,         HYP_G
#define ROW2_LEFT_COLEMAK      KC_Z,            KC_X,               KC_C,        NUM_D,         KC_V
#define ROW1_LEFT_COLEMAK      SYM_BSP,         NAV_SPC

#define ROW4_RGHT_COLEMAK      KC_J,            KC_L,               KC_U,        KC_Y,          KC_SCLN
#define ROW3_RGHT_COLEMAK      HYP_M,           SHT_N,              GUI_E,       ALT_I,         CTL_O
#define ROW2_RGHT_COLEMAK      RCMD_K,          NUM_H,              KC_COMM,     KC_DOT,        KC_SLSH
#define ROW1_RGHT_COLEMAK      VSCODE_K,        SHT_TAB
#define ROW1_RGHT_COLEMAK_KLOR SHT_TAB,         SYM

/* ------------------------------- navigation ------------------------------- */

#define ROW4_LEFT_NAV          KC_ESC,          XXXXXXX,            XXXXXXX,     XXXXXXX,       XXXXXXX
#define ROW3_LEFT_NAV          KC_LCTL,         KC_LOPT,            KC_LCMD,     KC_LSFT,       KC_HYPR
#define ROW3_LEFT_NAV_KLOR     KC_LCTL,         KC_LOPT,            KC_LCMD,     XXXXXXX,       KC_LSFT
#define ROW2_LEFT_NAV          CTL_SFT,         OPT_SFT,            CMD_SFT,     XXXXXXX,       XXXXXXX
#define ROW1_LEFT_NAV          XXXXXXX,         XXXXXXX

#define ROW4_RGHT_NAV          KC_PGUP,         KC_HOME,            KC_UP,        KC_END,        KC_INSERT
#define ROW3_RGHT_NAV          KC_PGDN,         KC_LEFT,            KC_DOWN,      KC_RGHT,       XXXXXXX
#define ROW2_RGHT_NAV          C(KC_PAGE_UP),   C(KC_PAGE_DOWN),    KC_SWITCH_APP,XXXXXXX,       QK_REP
#define ROW1_RGHT_NAV          _______,         KC_RSFT

/* --------------------------------- symbol --------------------------------- */

#define ROW4_LEFT_SYM          KC_EXLM,         KC_AT,              KC_HASH,     KC_DOLLAR,     KC_PERC
#define ROW3_LEFT_SYM          KC_LCTL,         KC_LOPT,            KC_LCMD,     KC_LSFT,       KC_GRV
#define ROW2_LEFT_SYM          KC_CIRC,         KC_AMPR,            KC_ASTR,     KC_PIPE,       KC_BSLS
#define ROW1_LEFT_SYM          _______,         _______

#define ROW4_RGHT_SYM          _______,         _______,            _______,     KC_MINS,       KC_EQL
#define ROW3_RGHT_SYM          KC_EQUAL,        LSFT_T(KC_LPRN), CMD_T(KC_LCBR), OPT_T(KC_LBRC),  KC_QUOT
#define ROW2_RGHT_SYM          KC_TILD,         KC_RPRN,            KC_RCBR,     KC_RBRC,       KC_MINS
#define ROW1_RGHT_SYM          XXXXXXX,         KC_RSFT

/* ---------------------------------- num ----------------------------------- */

#define ROW4_LEFT_NUM          KC_F12,          KC_F7,              KC_F8,        KC_F9,        KC_F12
#define ROW3_LEFT_NUM          KC_F11,          KC_F4,              KC_F5,        KC_F6,        KC_F11
#define ROW2_LEFT_NUM          KC_F10,          KC_F1,              KC_F2,        KC_F3,        KC_F10
#define ROW1_LEFT_NUM          KC_LCTL,         KC_LOPT

#define ROW4_RGHT_NUM          KC_PAST,         KC_7,               KC_8,        KC_9,          KC_PPLS
#define ROW3_RGHT_NUM          KC_EQUAL,        KC_4,               KC_5,        KC_6,          KC_QUOT
#define ROW2_RGHT_NUM          KC_0,            KC_1,               KC_2,        KC_3,          KC_MINS
#define ROW1_RGHT_NUM          KC_LCMD,         KC_RSFT

/* ------------------------------ LAYER_MOUSE ----------------------------- */
#define ROW4_LEFT_MOUSE        KC_MS_ACCEL0,    KC_MS_ACCEL1,       KC_MS_ACCEL2,XXXXXXX,       XXXXXXX
#define ROW3_LEFT_MOUSE        KC_LCTL,         KC_ROPT,            KC_LCMD,     KC_LSFT,       XXXXXXX
#define ROW2_LEFT_MOUSE        XXXXXXX,         XXXXXXX,            XXXXXXX,     XXXXXXX,       XXXXXXX
#define ROW1_LEFT_MOUSE        _______,         _______

#define ROW4_RGHT_MOUSE        KC_MS_WH_UP,     KC_MS_BTN1,         MEH(KC_UP)  ,   KC_MS_BTN2,    HYPR(KC_J)
#define ROW3_RGHT_MOUSE        KC_MS_WH_DOWN,   MEH(KC_LEFT),       MEH(KC_DOWN),   MEH(KC_RGHT),  HYPR(KC_M)
#define ROW2_RGHT_MOUSE        XXXXXXX,         XXXXXXX ,           KC_BTN5 ,       XXXXXXX,       HYPR(KC_K)
#define ROW1_RGHT_MOUSE        KC_MS_BTN2,      KC_MS_BTN1

/* ------------------------------ VSCODE ----------------------------- */
#define ROW4_LEFT_VSCODE       KC_U,       _______,       _______,   _______,    _______
#define ROW3_LEFT_VSCODE       _______,    _______,       _______,   _______,    _______
#define ROW2_LEFT_VSCODE       _______,    _______,       _______,   _______,    _______
#define ROW1_LEFT_VSCODE       _______,    _______

#define ROW4_RGHT_VSCODE       _______,     _______,      _______,   _______,    _______
#define ROW3_RGHT_VSCODE       _______,     _______,      _______,   _______,    _______
#define ROW2_RGHT_VSCODE       _______,     _______,      _______,   _______,    _______
#define ROW1_RGHT_VSCODE       _______,     _______

#define ROW1_LEFT_MOUSE_CHA       _______,  _______,  _______

#define ROW1_LEFT_COLEMAK_CHA     SYM_BSP,  NAV_SPC,  MOU_ENT
#define ROW1_LEFT_NAV_CHA_CHA     _______,  _______,  _______
#define ROW1_LEFT_SYM_CHA_CHA     _______,  _______,  _______
#define ROW1_LEFT_NUM_CHA_CHA     KC_LCTL,  KC_LOPT,  KC_LCMD

/* ------------------------------ SOFLE ----------------------------- */
#define ROW3_LEFT_COLEMAK_SOFLE     CTL_A,   ALT_R,   GUI_S,   SHT_T, HYP_G
#define ROW1_RGHT_COLEMAK_SOFLE     SHT_TAB, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT