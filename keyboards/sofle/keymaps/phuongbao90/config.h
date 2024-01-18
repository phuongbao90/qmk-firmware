#pragma once
#define MASTER_LEFT
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// Press both shift to enable caplocks
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Optimization to save memory
// #define NO_ACTION_MACRO   
// #define NO_ACTION_FUNCTION
// #define NO_MUSIC_MODE     
// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE
                        
#define COMBO_COUNT 2
#define COMBO_VARIABLE_LEN
#define COMBO_ALLOW_ACTION_KEYS 

// Make it easier to work with tap hold
#define PERMISSIVE_HOLD      
// #define HOLD_ON_OTHER_KEY_PRESS
// #define RETRO_TAPPING     
#ifdef TAPPING_TERM          
    #undef TAPPING_TERM      
#endif                       
#define TAPPING_TERM 150     

#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_MOVE_DELTA 5
                             
// #define QUICK_TAP_TERM_PER_KEY
// #define TAPPING_FORCE_HOLD_PER_KEY
// #define TAPPING_TERM_PER_KEY
// #define TAPPING_FORCE_HOLD
                             
// #define ONESHOT_TAP_TOGGLE 2
// #define TAPPING_TOGGLE 1  
                             
#define NO_AUTO_SHIFT_ALPHA                
                             
// #define ONESHOT_TIMEOUT 2000
                             
// Configure leader key      
// #define LEADER_TIMEOUT 500
// #define LEADER_PER_KEY_TIMING
// #define LEADER_NO_TIMEOUT

// Configure combos
// #define COMBO_TERM 25
// #define COMBO_MUST_HOLD_MODS
// #define COMBO_COUNT 1
// #define EXTRA_SHORT_COMBOS
// #define COMBO_STRICT_TIMER
// #define COMBO_HOLD_TERM 175
// #define COMBO_MUST_TAP_PER_COMBO
// #define COMBO_ALLOW_ACTION_KEYS 
// #define COMBO_VARIABLE_LEN
// #define COMBO_TERM 50
// Disable Alt Repeat
// #define NO_ALT_REPEAT_KEY

// Dynamic macros
// #define DYNAMIC_MACRO_NO_NESTING

// /* -------------------------------------------------------------------------- */
// // default but used in macros
// #undef TAPPING_TERM
// #define TAPPING_TERM 175
// #define TAPPING_TERM_PER_KEY

// // Prevent normal rollover on alphas from accidentally triggering mods.
// #define PERMISSIVE_HOLD

// // Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define QUICK_TAP_TERM 0

// // Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP

// // Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// // #define TAPPING_FORCE_HOLD
// #define BILATERAL_COMBINATIONS
// #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// // Configure leader key
// #define LEADER_TIMEOUT 500
// #define LEADER_PER_KEY_TIMING
// #define LEADER_NO_TIMEOUT


/* ------------------------------ ON SHORT KEY ------------------------------ */
// #define ONESHOT_TAP_TOGGLE 1
// #define ONESHOT_TIMEOUT 3000

