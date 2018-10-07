#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define ______ KC_TRNS

enum larry_layers {
  _QWERTY,
  _OMG,
  _WTF,
  _LOL
};

enum larry_keycodes {
  OMG = SAFE_RANGE,
  WTF
};

// TODO:
//  - [ ] Add media keys
//  - [ ] Investigate QMK_KEYS_PER_SCAN https://github.com/qmk/qmk_firmware/tree/master/keyboards/ergodox_ez#settings
//  - [ ] Add function keys to a layer on number row
//  - [ ] A button to print QMK version info https://github.com/lmarburger/qmk_firmware/blob/5526570cd3e03ee25d9442c0829ef60e00d75fa1/keyboards/ergodox_ez/keymaps/default/keymap.c#L177-L182

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/****************************************************************************************************
*
* Keymap: Qwerty Default Layer
*
* ┌────────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬────────┐
* │        │  1!  │  2@  │  3#  │  4$  │  5%  │  `~  │  │  \|  │  6^  │  7&  │  8*  │  9(  │  0)  │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
* │        │  Q   │  W   │  E   │  R   │  T   │  =+  │  │  -_  │  Y   │  U   │  I   │  O   │  P   │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┤      │  │      ├──────┼──────┼──────┼──────┼──────┼────────┤
* │ Tab    │  A   │  S   │  D   │  F   │  G   ├──────┤  ├──────┤  H   │  J   │  K   │  L   │  ;:  │ '"     │
* ├────────┼──────┼──────┼──────┼──────┼──────┤      │  │      ├──────┼──────┼──────┼──────┼──────┼────────┤
* │ Shift  │  Z   │  X   │  C   │  V   │  B   │ Shift│  │ Shift│  N   │  M   │  ,<  │  .>  │  /?  │ Shift  │
* └─┬──────┼──────┼──────┼──────┼──────┼──────┴──────┘  └──────┴──────┼──────┼──────┼──────┼──────┼──────┬─┘
*   │      │      │      │      │      │                              │      │      │      │      │      │
*   └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
*                                      ┌──────┬──────┐  ┌──────┬──────┐
*                                      │ Gui  │ Alt  │  │ Alt  │ Gui  │
*                               ┌──────┼──────┼──────┤  ├──────┼──────┼──────┐
*                               │      │      │ Omg  │  │ Wtf  │      │      │
*                               │ BkSp │ Esc  ├──────┤  ├──────┤Return│ Space│
*                               │      │      │ Ctrl │  │ Ctrl │      │      │
*                               └──────┴──────┴──────┘  └──────┴──────┴──────┘
*/
[_QWERTY] = LAYOUT_ergodox(
    ______,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5, KC_GRAVE,
    ______,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T, KC_EQUAL,
    KC_TAB,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
    KC_LSHIFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, KC_LSHIFT,
    ______,    ______, ______, ______, ______,
                                           KC_LGUI,   KC_LALT,
                                                      OMG,
                                KC_BSPACE, KC_ESCAPE, KC_LCTRL,

    KC_BSLASH, KC_6, KC_7,   KC_8,     KC_9,   KC_0,      ______,
    KC_MINUS,  KC_Y, KC_U,   KC_I,     KC_O,   KC_P,      ______,
               KC_H, KC_J,   KC_K,     KC_L,   KC_SCOLON, KC_QUOTE,
    KC_RSHIFT, KC_N, KC_M,   KC_COMMA, KC_DOT, KC_SLASH,  KC_RSHIFT,
                     ______, ______,   ______, ______,    ______,
    KC_RALT,  KC_RGUI,
    WTF,
    KC_RCTRL, KC_ENTER, KC_SPACE
  ),

/****************************************************************************************************
*
* Keymap: OMG Layer
*
* ┌────────┬──────┬──────┬──────┬──────┬───────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬────────┐
* │        │      │      │      │      │       │      │  │      │      │      │      │      │      │        │
* ├────────┼──────┼──────┼──────┼──────┼───────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
* │        │      │      │      │      │       │      │  │      │      │      │      │      │      │        │
* ├────────┼──────┼──────┼──────┼──────┼───────┤      │  │      ├──────┼──────┼──────┼──────┼──────┼────────┤
* │        │      │MsLeft│MsDown│ MsUp │MsRight├──────┤  ├──────┤ Left │ Down │  Up  │ Right│      │        │
* ├────────┼──────┼──────┼──────┼──────┼───────┤      │  │      ├──────┼──────┼──────┼──────┼──────┼────────┤
* │        │      │      │      │      │       │      │  │      │      │      │      │      │      │        │
* └─┬──────┼──────┼──────┼──────┼──────┼───────┴──────┘  └──────┴──────┼──────┼──────┼──────┼──────┼──────┬─┘
*   │      │      │      │      │      │                               │      │      │      │      │      │
*   └──────┴──────┴──────┴──────┴──────┘                               └──────┴──────┴──────┴──────┴──────┘
*                                       ┌──────┬──────┐  ┌──────┬──────┐
*                                       │      │      │  │      │      │
*                                ┌──────┼──────┼──────┤  ├──────┼──────┼──────┐
*                                │      │      │      │  │      │      │      │
*                                │      │      ├──────┤  ├──────┤      │      │
*                                │      │      │      │  │      │      │      │
*                                └──────┴──────┴──────┘  └──────┴──────┴──────┘
*/
[_OMG] = LAYOUT_ergodox(
  ______, ______, ______,     ______,     ______,   ______,      ______,
  ______, ______, ______,     ______,     ______,   ______,      ______,
  ______, ______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT,
  ______, ______, ______,     ______,     ______,   ______,      ______,
  ______, ______, ______,     ______,     ______,
                                                         ______, ______,
                                                                 ______,
                                                 ______, ______, ______,

  ______, ______,  ______,  ______, ______,   ______, ______,
  ______, ______,  ______,  ______, ______,   ______, ______,
          KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, ______, ______,
  ______, ______,  ______,  ______, ______,   ______, ______,
                   ______,  ______, ______,   ______, ______,
  ______, ______,
  ______,
  ______, KC_MS_BTN2, KC_MS_BTN1
  ),

/****************************************************************************************************
*
* Keymap: WTF Layer
*
* ┌────────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬────────┐
* │        │      │      │      │      │      │      │  │      │      │      │      │      │      │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
* │        │      │      │      │      │      │      │  │      │      │      │      │      │      │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┤      │  │      ├──────┼──────┼──────┼──────┼──────┼────────┤
* │        │  <   │  >   │  (   │  )   │      ├──────┤  ├──────┤      │  {   │  }   │  [   │  ]   │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┤      │  │      ├──────┼──────┼──────┼──────┼──────┼────────┤
* │        │      │      │      │      │      │      │  │      │      │      │      │      │      │        │
* └─┬──────┼──────┼──────┼──────┼──────┼──────┴──────┘  └──────┴──────┼──────┼──────┼──────┼──────┼──────┬─┘
*   │      │      │      │      │      │                              │      │      │      │      │      │
*   └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
*                                      ┌──────┬──────┐  ┌──────┬──────┐
*                                      │      │      │  │      │      │
*                               ┌──────┼──────┼──────┤  ├──────┼──────┼──────┐
*                               │      │      │      │  │      │      │      │
*                               │ Del  │      ├──────┤  ├──────┤      │      │
*                               │      │      │      │  │      │      │      │
*                               └──────┴──────┴──────┘  └──────┴──────┴──────┘
*/
[_WTF] = LAYOUT_ergodox(
    ______, ______, ______, ______,        ______,         ______, ______,
    ______, ______, ______, ______,        ______,         ______, ______,
    ______, KC_LT,  KC_GT,  KC_LEFT_PAREN, KC_RIGHT_PAREN, ______,
    ______, ______, ______, ______,        ______,         ______, ______,
    ______, ______, ______, ______,        ______,
                                                           ______, ______,
                                                                   ______,
                                                   ______, ______, ______,

    ______, ______, ______,              ______,               ______,      ______,      ______,
    ______, ______, ______,              ______,               ______,      ______,      ______,
            ______, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_LBRACKET, KC_RBRACKET, ______,
    ______, ______, ______,              ______,               ______,      ______,      ______,
                    ______,              ______,               ______,      ______,      ______,
    ______, ______,
    ______,
    ______, ______, ______
  ),

/****************************************************************************************************
*
* Keymap: LOL Layer
*
* ┌────────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬────────┐
* │        │      │      │      │      │      │      │  │      │      │      │      │      │      │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
* │        │      │      │      │      │      │      │  │      │      │      │      │      │      │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┤      │  │      ├──────┼──────┼──────┼──────┼──────┼────────┤
* │        │  1!  │  2@  │  3#  │  4$  │  5%  ├──────┤  ├──────┤  6^  │  7&  │  8*  │  9(  │  0)  │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┤      │  │      ├──────┼──────┼──────┼──────┼──────┼────────┤
* │        │      │      │      │      │      │      │  │      │      │      │      │      │      │        │
* └─┬──────┼──────┼──────┼──────┼──────┼──────┴──────┘  └──────┴──────┼──────┼──────┼──────┼──────┼──────┬─┘
*   │      │      │      │      │      │                              │      │      │      │      │      │
*   └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
*                                      ┌──────┬──────┐  ┌──────┬──────┐
*                                      │      │      │  │      │      │
*                               ┌──────┼──────┼──────┤  ├──────┼──────┼──────┐
*                               │      │      │      │  │      │      │      │
*                               │      │      ├──────┤  ├──────┤      │      │
*                               │      │      │      │  │      │      │      │
*                               └──────┴──────┴──────┘  └──────┴──────┴──────┘
*/
[_LOL] = LAYOUT_ergodox(
    ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______,
    ______, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
    ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______,
                                            ______, ______,
                                                    ______,
                                    ______, ______, ______,

    ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______,
            KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   ______,
    ______, ______, ______, ______, ______, ______, ______,
                    ______, ______, ______, ______, ______,
    ______, ______,
    ______,
    ______, ______, ______
  )

};


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OMG:
      if (record->event.pressed) {
        layer_on(_OMG);
        update_tri_layer(_OMG, _WTF, _LOL);
      } else {
        layer_off(_OMG);
        update_tri_layer(_OMG, _WTF, _LOL);
      }
      return false;
      break;
    case WTF:
      if (record->event.pressed) {
        layer_on(_WTF);
        update_tri_layer(_OMG, _WTF, _LOL);
      } else {
        layer_off(_WTF);
        update_tri_layer(_OMG, _WTF, _LOL);
      }
      return false;
      break;
  }
  return true;
}


/****************************************************************************************************
*
* Keymap: Template
*
* ┌────────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬────────┐
* │        │      │      │      │      │      │      │  │      │      │      │      │      │      │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
* │        │      │      │      │      │      │      │  │      │      │      │      │      │      │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┤      │  │      ├──────┼──────┼──────┼──────┼──────┼────────┤
* │        │      │      │      │      │      ├──────┤  ├──────┤      │      │      │      │      │        │
* ├────────┼──────┼──────┼──────┼──────┼──────┤      │  │      ├──────┼──────┼──────┼──────┼──────┼────────┤
* │        │      │      │      │      │      │      │  │      │      │      │      │      │      │        │
* └─┬──────┼──────┼──────┼──────┼──────┼──────┴──────┘  └──────┴──────┼──────┼──────┼──────┼──────┼──────┬─┘
*   │      │      │      │      │      │                              │      │      │      │      │      │
*   └──────┴──────┴──────┴──────┴──────┘                              └──────┴──────┴──────┴──────┴──────┘
*                                      ┌──────┬──────┐  ┌──────┬──────┐
*                                      │      │      │  │      │      │
*                               ┌──────┼──────┼──────┤  ├──────┼──────┼──────┐
*                               │      │      │      │  │      │      │      │
*                               │      │      ├──────┤  ├──────┤      │      │
*                               │      │      │      │  │      │      │      │
*                               └──────┴──────┴──────┘  └──────┴──────┴──────┘
*
[_TODO] = LAYOUT_ergodox(
    ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______,
                                            ______, ______,
                                                    ______,
                                    ______, ______, ______,

    ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______,
            ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______,
                    ______, ______, ______, ______, ______,
    ______, ______,
    ______,
    ______, ______, ______
  ),
*/
