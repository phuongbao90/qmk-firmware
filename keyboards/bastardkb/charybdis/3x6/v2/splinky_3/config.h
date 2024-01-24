/*
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Handedness. */
#define MASTER_LEFT

// To use the handedness pin, resistors need to be installed on the adapter PCB.
// If so, uncomment the following code, and undefine MASTER_RIGHT above.
// #define SPLIT_HAND_PIN GP15
// #define SPLIT_HAND_PIN_LOW_IS_LEFT  // High -> right, Low -> left.

/* SPI & PMW3360 settings. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23
#define POINTING_DEVICE_CS_PIN GP16

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// my configs
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// #define COMBO_COUNT 2
#define COMBO_VARIABLE_LEN
#define COMBO_ALLOW_ACTION_KEYS 

#define PERMISSIVE_HOLD      
#ifdef TAPPING_TERM          
    #undef TAPPING_TERM      
#endif                       
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0
// #define TAPPING_TERM_PER_KEY

// #define MOUSEKEY_MAX_SPEED 5
// #define MOUSEKEY_MOVE_DELTA 5
// #define TAPPING_FORCE_HOLD
#define NO_AUTO_SHIFT_ALPHA

// #define PMW33XX_CPI 2200

// #define MK_COMBINED

#ifdef POINTING_DEVICE_ENABLE
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif // POINTING_DEVICE_ENABLE

