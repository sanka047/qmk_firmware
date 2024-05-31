#pragma once

//#define USE_MATRIX_I2C

/* Flash handedness on EEPROM */
#undef MASTER_RIGHT
#define EE_HANDS

#define FORCE_NKRO

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 200

#define PERMISSIVE_HOLD_PER_KEY

#define ONESHOT_TIMEOUT 750

#define TAP_HOLD_CAPS_DELAY 100

// Combos
#define EXTRA_SHORT_COMBOS 6
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM 50
