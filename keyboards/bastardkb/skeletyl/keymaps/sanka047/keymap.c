#include QMK_KEYBOARD_H
#include "print.h"
#include <stdio.h>

#include "tmux.h"

//------------< KEYMAP DEFINITION >------------//

enum kb_layers {
    _QWER,
    _SYM,
    _NAV,
    _NUM,
    _TMUX,
    _KB
};

//------------< CUSTOM KEYCODES >------------//

// Print screen shortcut
#define MY_PRNT G(S(KC_4))

// Mod-Tap keys (QWERTY)
#define MOD_F GUI_T(KC_F)
#define MOD_J GUI_T(KC_J)
#define MOD_D ALT_T(KC_D)
#define MOD_K ALT_T(KC_K)
#define MOD_S SFT_T(KC_S)
#define MOD_L SFT_T(KC_L)
#define MOD_A CTL_T(KC_A)
#define MOD_SCLN CTL_T(KC_SCLN)

// Layer keys (QWERTY)
#define NUM_SPC LT(_NUM, KC_SPC)
#define NUM_ESC LT(_NUM, KC_ESC)
#define TMUX_T LT(_TMUX, KC_T)
#define TMUX_Y LT(_TMUX, KC_Y)
#define OSL_SYM OSL(_SYM)
#define MO_NAV MO(_NAV)
#define MO_KB MO(_KB)

//------------< KEYMAP >------------//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWER] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┐
     KC_Q    ,KC_W    ,KC_E    ,KC_R    ,TMUX_T  ,                       TMUX_Y  ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     MOD_A   ,MOD_S   ,MOD_D   ,MOD_F   ,KC_G    ,                       KC_H    ,MOD_J   ,MOD_K   ,MOD_L   ,MOD_SCLN,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                       KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,
  //└────────┴────────┴────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┴────────┴────────┘
                                MO_NAV  ,NUM_ESC ,KC_HYPR ,     KC_HYPR ,NUM_SPC ,OSL_SYM
  //                           └────────┴────────┴────────┘    └────────┴────────┴────────┘
  ),

  [_SYM] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                       KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_UNDS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_PLUS ,KC_LPRN ,KC_RPRN ,KC_EQL  ,                       KC_PIPE ,KC_LBRC ,KC_RBRC ,KC_MINS ,KC_ENT  ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     KC_TILDE,KC_GRV  ,KC_QUOT ,KC_DQT  ,XXXXXXX ,                       XXXXXXX ,KC_LCBR ,KC_RCBR ,KC_EXLM ,KC_BSLS ,
  //└────────┴────────┴────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┴────────┴────────┘
                                _______ ,_______ ,_______ ,     _______ ,_______ ,_______
  //                           └────────┴────────┴────────┘    └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                       KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,KC_DEL  ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LSFT ,KC_LALT ,KC_LGUI ,KC_ENT  ,                       KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                       XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┴────────┴────────┘
                                _______ ,_______ ,_______ ,     _______ ,_______ ,_______
  //                           └────────┴────────┴────────┘    └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┐
     KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                       KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                       KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MINS ,KC_PLUS ,KC_EQL  ,                       XXXXXXX ,KC_ASTR ,KC_COMM ,KC_DOT  ,KC_SLSH ,
  //└────────┴────────┴────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┴────────┴────────┘
                                MO_KB   ,_______ ,_______ ,     _______ ,_______ ,MO_KB
  //                           └────────┴────────┴────────┘    └────────┴────────┴────────┘
  ),

  [_TMUX] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                       TM_PREV ,TM_LABR ,TM_RABR ,TM_NEXT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,TM_DTCH ,XXXXXXX ,XXXXXXX ,                       TM_LEFT ,TM_DOWN ,TM_UP   ,TM_RGHT ,TM_CMD  ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     TM_ZOOM ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                       TM_NEW  ,TM_SLCT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┴────────┴────────┘
                                XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX
  //                           └────────┴────────┴────────┘    └────────┴────────┴────────┘
  ),

  [_KB] = LAYOUT_split_3x5_3(
  //┌────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┐
     QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                       KC_BRID ,KC_BRIU ,XXXXXXX ,XXXXXXX ,KC_PSCR ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,DB_TOGG ,XXXXXXX ,XXXXXXX ,                       KC_MPRV ,KC_MPLY ,XXXXXXX ,KC_MNXT ,MY_PRNT ,
  //├────────┼────────┼────────┼────────┼────────┤                      ├────────┼────────┼────────┼────────┼────────┤
     QK_RBT  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                       KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┼────────┼────────┼────────┐    ┌────────┼────────┼────────┼────────┴────────┴────────┘
                                XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX
  //                           └────────┴────────┴────────┘    └────────┴────────┴────────┘
  ),
};

//------------< EXTRA CONFIG >------------//

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
       case NUM_SPC:
       case NUM_ESC:
           // Immediately select the hold action when another key is tapped.
           return true;
       default:
           // Do not select the hold action when another key is tapped.
           return false;
   }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   // Process tmux keycodes
   if (!process_tmux_record_user(keycode, record)) {
       return false;
   }

   dprintf("tap: %d\n", record->tap.count);
   switch (keycode) {
       default:
           return true;
   }
}

//------------< COMBOS >------------//

enum combos {
    SDF_CAPS_WORD,

    // always last place
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_caps_word[] = {MOD_S, MOD_D, MOD_F, COMBO_END};

combo_t key_combos[] = {
    [SDF_CAPS_WORD] = COMBO_ACTION(combo_caps_word),
};

bool get_combo_must_tap(uint16_t index, combo_t *combo) { return true; }

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case SDF_CAPS_WORD:
            if (pressed) { caps_word_toggle(); }
            break;
    }
}

//------------< CAPS WORD >------------//

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
        // allow list MO_NAV because it is required to get to BSPC
        case MO_NAV:
            return true;
        default:
            return false; // Deactivate Caps Word.
    }
}
