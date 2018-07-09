#include "kinesis.h"

#define _______ KC_TRNS

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/****************************************************************************************************
*
* Keymap: Qwerty Default Layer
*
* ,----------------------------------------------------------------- -----------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  | |  F9  |  F10 |  F11 |  F12 | Vol- | Vol+ | Prev | Next |  Play  |
* |--------+------+------+------+------+------+--------------------- ---------------------+------+------+------+------+------+--------|
* | `~     |  1!  |  2@  |  3#  |  4$  |  5%  |                                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                                           +------+------+------+------+------+--------|
* | =+     |   Q  |   W  |   E  |   R  |   T  |                                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                                           |------+------+------+------+------+--------|
* | Tab    |   A  |   S  |   D  |   F  |   G  |                                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                                           |   N  |   M  |  ,<  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                                           `------+------+------+------+------+--------'
*          |      |      |      |      |                                                         |      |      |      |      |
*          `---------------------------'                                                         `---------------------------'
*                                        ,-------------.                         ,-------------.
*                                        | Gui  | Alt  |                         | Alt  | Gui  |
*                                 ,------|------|------|                         |------+------+------.
*                                 |      |      | Omg  |                         | Wtf  |      |      |
*                                 | BkSp | Esc  |------|                         |------|Return| Space|
*                                 |      |      | Ctrl |                         | Ctrl |      |      |
*                                 `--------------------'                         `--------------------'
*/
[_QWERTY] = KEYMAP(
  KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
  KC_GRV, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
  KC_EQL, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
  KC_TAB, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
  KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
          _______,_______,_______,_______,
                                          KC_LGUI,KC_LALT,
                                                  OMG    ,
                                  KC_BSPC,KC_ESC ,KC_LCTL,

  KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_VOLD,KC_VOLU,KC_MPRV,KC_MNXT,KC_MPLY,
                          KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
                          KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
                          KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
                          KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                                  _______,_______,_______,_______,
                          KC_RALT,KC_RGUI,
                          WTF    ,
                          KC_RCTL,KC_ENTER ,KC_SPC
  ),

/****************************************************************************************************
*
* Keymap: OMG Layer
*
* ,----------------------------------------------------------------- -----------------------------------------------------------------.
* |        |      |      |      |      |      |      |      |      | |      |      |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------+--------------------- ---------------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                                           +------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                           | Left | Down |  Up  | Right|      |        |
* |--------+------+------+------+------+------|                                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                           |      |      |      |      |      |        |
* `--------+------+------+------+------+-------                                           `------+------+------+------+------+--------'
*          |      |      |      |      |                                                         |      |      |      |      |
*          `---------------------------'                                                         `---------------------------'
*                                        ,-------------.                         ,-------------.
*                                        |      |      |                         |      |      |
*                                 ,------|------|------|                         |------+------+------.
*                                 |      |      |      |                         |      |      |      |
*                                 |      |      |------|                         |------|      |      |
*                                 |      |      |      |                         |      |      |      |
*                                 `--------------------'                         `--------------------'
*/
[_OMG] = KEYMAP(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
          _______,_______,_______,_______,
                                          _______,_______,
                                                  _______,
                                  _______,_______,_______,

  _______,_______,_______,_______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,_______,
                          KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______,
                          _______,_______,_______,_______,_______,_______,
                                  _______,_______,_______,_______,
                          _______,_______,
                          _______,
                          _______,_______,_______
  ),

/****************************************************************************************************
*
* Keymap: WTF Layer
*
* ,----------------------------------------------------------------- -----------------------------------------------------------------.
* |        |      |      |      |      |      |      |      |      | |      |      |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------+--------------------- ---------------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                                           +------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                                           |------+------+------+------+------+--------|
* |        |   <  |   >  |   (  |   )  |      |                                           |      |   {  |   }  |   [  |   ]  |        |
* |--------+------+------+------+------+------|                                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                           |      |      |      |      |      |        |
* `--------+------+------+------+------+-------                                           `------+------+------+------+------+--------'
*          |      |      |      |      |                                                         |      |      |      |      |
*          `---------------------------'                                                         `---------------------------'
*                                        ,-------------.                         ,-------------.
*                                        |      |      |                         |      |      |
*                                 ,------|------|------|                         |------+------+------.
*                                 |      |      |      |                         |      |      |      |
*                                 | Del  |      |------|                         |------|      |      |
*                                 |      |      |      |                         |      |      |      |
*                                 `--------------------'                         `--------------------'
*/
[_WTF] = KEYMAP(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
  _______,KC_LT  ,KC_GT  ,KC_LPRN,KC_RPRN,_______,
  _______,_______,_______,_______,_______,_______,
          _______,_______,_______,_______,
                                          _______,_______,
                                                  _______,
                                  KC_DEL ,_______,_______,

  _______,_______,_______,_______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,_______,
                          _______,KC_LCBR,KC_RCBR,KC_LBRC,KC_RBRC,_______,
                          _______,_______,_______,_______,_______,_______,
                                  _______,_______,_______,_______,
                          _______,_______,
                          _______,
                          _______,_______,_______
  ),

/****************************************************************************************************
*
* Keymap: LOL Layer
*
* ,----------------------------------------------------------------- -----------------------------------------------------------------.
* |        |      |      |      |      |      |      |      |      | |      |      |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------+--------------------- ---------------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                                           +------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                                           |------+------+------+------+------+--------|
* |        |  1!  |  2@  |  3#  |  4$  |  5%  |                                           |  6^  |  7&  |  8*  |  9(  |  0)  |        |
* |--------+------+------+------+------+------|                                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                                           |      |      |      |      |      |        |
* `--------+------+------+------+------+-------                                           `------+------+------+------+------+--------'
*          |      |      |      |      |                                                         |      |      |      |      |
*          `---------------------------'                                                         `---------------------------'
*                                        ,-------------.                         ,-------------.
*                                        |      |      |                         |      |      |
*                                 ,------|------|------|                         |------+------+------.
*                                 |      |      |      |                         |      |      |      |
*                                 |      |      |------|                         |------|      |      |
*                                 |      |      |      |                         |      |      |      |
*                                 `--------------------'                         `--------------------'
*/
[_LOL] = KEYMAP(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
  _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
  _______,_______,_______,_______,_______,_______,
          _______,_______,_______,_______,
                                          _______,_______,
                                                  _______,
                                  _______,_______,_______,

  _______,_______,_______,_______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,_______,
                          KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______,
                          _______,_______,_______,_______,_______,_______,
                                  _______,_______,_______,_______,
                          _______,_______,
                          _______,
                          _______,_______,_______
  )
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
