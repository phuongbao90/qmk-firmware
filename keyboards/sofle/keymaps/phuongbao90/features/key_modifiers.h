#include "layers.h"

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐

#define CTL_A     CTL_T(KC_A)
#define ALT_R     OPT_T(KC_R)
#define GUI_S     CMD_T(KC_S)
#define SHT_T     LSFT_T(KC_T)
#define HYP_G     HYPR_T(KC_G)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

#define SHT_N     RSFT_T(KC_N)
#define GUI_E     CMD_T(KC_E)
#define ALT_I     OPT_T(KC_I)
#define CTL_O     CTL_T(KC_O)
#define HYP_M     HYPR_T(KC_M)
#define RCMD_K    RCMD_T(KC_K)

// LAYERKEYS ├───────────────────────────────────────┐
#define NAV_SPC   LT(MO(_NAV),KC_SPC)  
#define SYM_BSP   LT(MO(_SYM),KC_BSPC)
#define MOU_ENT   LT(MO(_MOUSE),KC_ENT)
// #define TOG_SYM   layer_invert(_SYM)
// #define TOG_NAV   layer_invert(_NAV)

#define VNI_TAB   LT(MO(_VNI),KC_TAB)
#define NUM_D     LT(MO(_NUM),KC_D)
#define NUM_H     LT(_NUM,KC_H)
#define NUM_ENT   LT(MO(_VNI),KC_ENT)

// TAP HOLD
#define Q_ESC     KC_Q
#define AT_HASH   KC_AT
#define PARENS    KC_LPRN








