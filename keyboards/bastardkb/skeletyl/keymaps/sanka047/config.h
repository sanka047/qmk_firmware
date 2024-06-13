#pragma once

//#define USE_MATRIX_I2C

/* Flash handedness on EEPROM */
#undef MASTER_RIGHT
// See: https://docs.qmk.fm/features/split_keyboard#handedness-by-eeprom
#define EE_HANDS

#define FORCE_NKRO

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 200
// If a mod-tap key is tapped _consecutively_ within this threshold, it will enable auto-repeat
// (mirroring default hold behavior for regular keys). By default, this is set to TAPPING_TERM.
//
// Personally, I always run into typos with this enabled and using home-row mods. Setting it to 0
// disables this behavior entirely
//
// See: https://docs.qmk.fm/tap_hold#quick-tap-term
#define QUICK_TAP_TERM 0
// This is used for special handling of mod-tap thumb keys to prefer the hold action (avoiding
// further tuning of TAPPING_TERM).
//
// See: https://docs.qmk.fm/tap_hold#permissive-hold
#define PERMISSIVE_HOLD_PER_KEY

#define ONESHOT_TIMEOUT 750

#define TAP_HOLD_CAPS_DELAY 100

// Combos
#define EXTRA_SHORT_COMBOS 6
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM 50
