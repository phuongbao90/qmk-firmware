#pragma once
#include QMK_KEYBOARD_H

bool one_shot_process_record_user(uint16_t keycode, keyrecord_t *record);
void one_shot_matrix_scan_user(void);
