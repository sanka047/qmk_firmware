// Tmux implementation was based off of daliusd's layout:
//     https://github.com/daliusd/qmk_firmware/tree/daliusd-redox/keyboards/ferris/keymaps/daliusd
#pragma once

#include QMK_KEYBOARD_H

//------------< TMUX MACRO DECLARATIONS >------------//

enum custom_keycodes {
    TM_NEXT = SAFE_RANGE,
    TM_PREV,
    TM_LABR,
    TM_RABR,
    TM_NEW,
    TM_SLCT,
    TM_LEFT,
    TM_DOWN,
    TM_UP,
    TM_RGHT,
    TM_ZOOM,
    TM_DTCH,
    TM_CMD,
};

#define TMUX_PREFIX SS_DOWN(X_LCTL) "b" SS_UP(X_LCTL)

bool process_tmux_record_user(uint16_t keycode, keyrecord_t *record);
