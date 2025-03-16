#pragma once
#include "quantum.h"

#include "features/custom_keys.h"
#include "layout_macros.h"
#include "features/key_modifiers.h" 
#include "features/taphold.h" 
// #include "features/orbital_mouse.h"
#include "features/one_shot.h"

#ifdef ENCODER_ENABLE
#    include "features/encoder.h"
#endif

#ifdef TAP_DANCE_ENABLE
  #include "features/tap_dances.h"
#endif

typedef enum {
    _COLEMAK,
    _NAV,
    _SYM,
    _NUM,
    LAYER_POINTER
} layers_t;
