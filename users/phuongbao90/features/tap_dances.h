#pragma once
#include "quantum.h"
#include "phuongbao90.h"

enum td_keycodes {
  TD_R_OPT_NAV = 0, // Tap for R, Tap and hold for OPT, double tap and hold for _NAV
  TD_A_CTL_NAV,
  TD_S_CMD_NAV,
  TD_T_SHT_NAV,
} td_state_t;

enum tap_dance_states {
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3,
    DOUBLE_HOLD = 4,
    DOUBLE_SINGLE_TAP = 5,
    TRIPLE_TAP = 6,
    TRIPLE_HOLD = 7
};

// Function to determine the current tapdance state
int cur_dance (tap_dance_state_t *state);
void process_tap_dance_keycode (bool reset, uint8_t toggle_layer);

typedef struct {
    uint8_t  trigger;
    uint8_t  layer;
    uint8_t  state;
} tap_dance_trigger_layer_t;

#define ACTION_TAP_DANCE_TRIGGER_LAYER(trigger, layer) { \
    .fn = { NULL, td_trigger_layer_finished, td_trigger_layer_reset }, \
    .user_data = (void *)&((tap_dance_trigger_layer_t) { trigger, layer, 0 }), \

// `finished` and `reset` functions for each tapdance keycode
void td_trigger_layer_finished (tap_dance_state_t *state, void *user_data);
void td_trigger_layer_reset (tap_dance_state_t *state, void *user_data);