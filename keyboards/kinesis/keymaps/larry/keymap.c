#include "kinesis.h"

#define _QWERTY 0
#define _LOWER 1

#define _______ KC_TRNS

enum custom_keycodes {
  LOWER = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/****************************************************************************************************
*
* Keymap: Default Qwerty Left Hand
*
* ,-----------------------------------------------------------------
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |
* |--------+------+------+------+------+------+---------------------
* | `~     |  1!  |  2@  |  3#  |  4$  |  5%  |
* |--------+------+------+------+------+------|
* | =+     |   Q  |   W  |   E  |   R  |   T  |
* |--------+------+------+------+------+------|
* | Tab    |   A  |   S  |   D  |   F  |   G  |
* |--------+------+------+------+------+------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |
* `--------+------+------+------+------+-------
*          | [{   | ]}   | Left | Right|
*          `---------------------------'
*                                        ,-------------.
*                                        | Gui  | Alt  |
*                                 ,------|------|------|
*                                 |      |      | Esc  |
*                                 | BkSp | Del  |------|
*                                 |      |      | Ctrl |
*                                 `--------------------'
*/
[_QWERTY] = KEYMAP(
  KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
  KC_GRV, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
  KC_EQL, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
  KC_TAB, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
  KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
          KC_LBRC,KC_RBRC,KC_LEFT,KC_RGHT,
                                          KC_LGUI,KC_LALT,
                                                  KC_ESC,
                                  KC_BSPC,KC_DEL ,KC_LCTL,

/****************************************************************************************************
*
* Keymap: Default Qwerty Right Hand
*
* -----------------------------------------------------------------.
* |  F9  |  F10 |  F11 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* ---------------------+------+------+------+------+------+--------|
*                      |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
*                      +------+------+------+------+------+--------|
*                      |   Y  |   U  |   I  |   O  |   P  | \|     |
*                      |------+------+------+------+------+--------|
*                      |   H  |   J  |   K  |   L  |  ;:  | '"     |
*                      |------+------+------+------+------+--------|
*                      |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
*                      `------+------+------+------+------+--------'
*                             | Down | Up   |  [{  |  ]}  |
*                             `---------------------------'
*             ,--------------.
*             | Alt   | Gui  |
*             |-------+------+------.
*             | Lower |      |      |
*             |-------|Return| Space|
*             | Ctrl  |      |      |
*             `---------------------'
*/
  KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, KC_1,
                          KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
                          KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
                          KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
                          KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                                  KC_DOWN,KC_UP  ,KC_LBRC,KC_RBRC,
                          KC_RALT,KC_RGUI,
                          LOWER,
                          KC_RCTL,KC_ENTER ,KC_SPC
  ),

/****************************************************************************************************
*
* Keymap: Lower Left Hand
*
* ,-----------------------------------------------------------------
* |        |      |      |      |      |      |      |      |      |
* |--------+------+------+------+------+------+---------------------
* |        |      |      |      |      |      |
* |--------+------+------+------+------+------|
* |        |   !  |   @  |   {  |   }  |   |  |
* |--------+------+------+------+------+------|
* |        |   #  |   $  |   (  |   )  |   `  |
* |--------+------+------+------+------+------|
* |        |   %  |   ^  |   [  |   ]  |   ~  |
* `--------+------+------+------+------+-------
*          |      |      |      |      |
*          `---------------------------'
*                                        ,-------------.
*                                        |      |      |
*                                 ,------|------|------|
*                                 |      |      |      |
*                                 |      |      |------|
*                                 |      |      |      |
*                                 `--------------------'
*/
[_LOWER] = KEYMAP(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,
  _______,KC_EXLM,KC_AT  ,KC_LCBR,KC_RCBR,KC_PIPE,
  _______,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,
  _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,
          _______,_______,_______,_______,
                                          _______,_______,
                                                  _______,
                                  _______,_______,_______,

/****************************************************************************************************
*
* Keymap: Lower Right Hand
*
* -----------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |        |
* ---------------------+------+------+------+------+------+--------|
*                      |      |      |      |      |      |        |
*                      +------+------+------+------+------+--------|
*                      |      |   7  |   8  |   9  |   *  |        |
*                      |------+------+------+------+------+--------|
*                      |   &  |   4  |   5  |   6  |   +  |        |
*                      |------+------+------+------+------+--------|
*                      |      |   1  |   2  |   3  |   \  |        |
*                      `------+------+------+------+------+--------'
*                             |   .  |   0  |   =  |      |
*                             `---------------------------'
*             ,-------------.
*             |      |      |
*             |------+------+------.
*             |      |      |      |
*             |------|      |      |
*             |      |      |      |
*             `--------------------'
*/
  _______,_______,_______,_______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,_______,
                          _______,KC_7   ,KC_8   ,KC_9   ,KC_ASTR,_______,
                          KC_AMPR,KC_4   ,KC_5   ,KC_6   ,KC_PLUS,_______,
                          _______,KC_1   ,KC_2   ,KC_3   ,KC_BSLS,_______,
                                  KC_DOT ,KC_0   ,KC_EQL ,_______,
                          _______,_______,
                          _______,
                          _______,_______,_______
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
  }
  return true;
}
