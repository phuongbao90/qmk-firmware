// tap_hold.h
#pragma once
#include QMK_KEYBOARD_H

bool tap_hold_process_record_user(uint16_t keycode, keyrecord_t *record);
void tap_hold_matrix_scan_user(void);
