#include "tmux.h"

//------------< TMUX MACRO IMPLEMENTATION >------------//

bool process_tmux_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TM_NEXT:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "n");
            }
            return false;
        case TM_PREV:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "p");
            }
            return false;
        case TM_LABR:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "<");
            }
            return false;
        case TM_RABR:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX ">");
            }
            return false;
        case TM_NEW:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "c");
            }
            return false;
        case TM_SLCT:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "[");
            }
            return false;
        case TM_LEFT:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "h");
            }
            return false;
        case TM_DOWN:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "j");
            }
            return false;
        case TM_UP:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "k");
            }
            return false;
        case TM_RGHT:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "l");
            }
            return false;
        case TM_ZOOM:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "z");
            }
            return false;
        case TM_DTCH:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX "d");
            }
            return false;
        case TM_CMD:
            if (record->event.pressed) {
                SEND_STRING(TMUX_PREFIX ":");
            }
            return false;
        default: break;
    }
    return true;
}
