#pragma once
#include QMK_KEYBOARD_H
#include "one_shot.h"
#include "layers.h"

uint16_t one_shot_key_timer;
uint16_t one_shot_held_key;

bool one_shot_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:   return true; // Process all other keycodes normally
    }
}

void one_shot_matrix_scan_user(void) {
}
