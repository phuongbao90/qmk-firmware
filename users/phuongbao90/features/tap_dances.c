
#include "quantum.h"
#include "tap_dances.h"
#include "phuongbao90.h"
static int td_state = -1; 
// -----
int cur_dance (tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)  return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    }
    else return 8;
}

// __attribute__ ((weak))
// void process_tap_dance_keycode (bool reset, uint8_t toggle_layer) { };
// void td_trigger_layer_finished (tap_dance_state_t *state, void *user_data) {
//     tap_dance_trigger_layer_t *data = (tap_dance_trigger_layer_t *)user_data;
//     data->state = cur_dance(state);

//     if (data->state == data->trigger) {
//         layer_on(data->layer);
//     } else {
//         process_tap_dance_keycode(false, data->layer);
//     }

// }
// void td_trigger_layer_reset (tap_dance_state_t *state, void *user_data) {
//     tap_dance_trigger_layer_t *data = (tap_dance_trigger_layer_t *)user_data;
//     if (data->state == data->trigger) {
//         switch (data->trigger) {
//             case SINGLE_HOLD:
//             case DOUBLE_HOLD:
//             case TRIPLE_HOLD:
//                 layer_off(data->layer);
//                 break;
//         }
//     } else {
//         process_tap_dance_keycode(true, data->layer);
//     }
//     data->state = 0;
// }

// -----
void td_a_ctl_nav_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_A);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case DOUBLE_HOLD: // Allow nesting of 2 parens `((` within tapping term
            layer_on(_NAV);
            register_mods(MOD_BIT(KC_LCTL));
            break;
        default:
            break;
    }
}

void td_a_ctl_nav_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_A);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCTL));
            layer_off(_NAV);
            break;
        default:
            break;
    }
}
// -----
// -----
void td_r_opt_nav_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_R);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case DOUBLE_HOLD: // Allow nesting of 2 parens `((` within tapping term
            layer_on(_NAV);
            register_mods(MOD_BIT(KC_LALT));
            break;
        default:
            break;
    }
}

void td_r_opt_nav_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_R);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LALT));
            layer_off(_NAV);
            break;
        default:
            break;
    }
}
// -----
// -----
void td_s_cmd_nav_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_S);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LCMD)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case DOUBLE_HOLD: // Allow nesting of 2 parens `((` within tapping term
            layer_on(_NAV);
            register_mods(MOD_BIT(KC_LCMD));
            break;
        default:
            break;
    }
}

void td_s_cmd_nav_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_S);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCMD)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LCMD));
            layer_off(_NAV);
            break;
        default:
            break;
    }
}
// -----
// -----
void td_t_sht_nav_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_T);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case DOUBLE_HOLD: // Allow nesting of 2 parens `((` within tapping term
            layer_on(_NAV);
            register_mods(MOD_BIT(KC_LSFT));
            break;
        default:
            break;
    }
}

void td_t_sht_nav_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_T);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case DOUBLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            layer_off(_NAV);
            break;
        default:
            break;
    }
}
// -----
// --------
tap_dance_action_t tap_dance_actions[] = {
    [TD_A_CTL_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_a_ctl_nav_finished, td_a_ctl_nav_reset),
    [TD_R_OPT_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_r_opt_nav_finished, td_r_opt_nav_reset),
    [TD_S_CMD_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_s_cmd_nav_finished, td_s_cmd_nav_reset),
    [TD_T_SHT_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_t_sht_nav_finished, td_t_sht_nav_reset),
};