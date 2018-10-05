#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

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

// TODO:
//  - [ ] Update ascii drawings from Kinesis mappings
//  - [ ] Add media keys
//  - [ ] Probably disable LEDs
//  - [ ] Check out default `process_record_user() stuff`

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
[_QWERTY] = LAYOUT_ergodox(
  KC_GRV,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5, _______,
  KC_EQL,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T, _______,
  KC_TAB,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
  KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, _______,
  _______,_______,_______,_______,_______,
                                          KC_LGUI,KC_LALT,
                                                      OMG,
                                  KC_BSPC,KC_ESC ,KC_LCTL,

          _______, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS,
          _______, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSLS,
                   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
          _______, KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
                        _______,_______,_______,_______,_______,
          KC_RALT, KC_RGUI,
          WTF,
          KC_RCTL, KC_ENTER, KC_SPC
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
* |        |      | Left |  Up  | Down | Right|                                           | Left | Down |  Up  | Right|      |        |
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
[_OMG] = LAYOUT_ergodox(
  _______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,
  _______,_______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,
  _______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,
                                          _______,_______,
                                                  _______,
                                  _______,_______,_______,

          _______,_______,_______,_______,_______,_______,_______,
          _______,_______,_______,_______,_______,_______,_______,
                  KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,_______,
          _______,_______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,
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
[_WTF] = LAYOUT_ergodox(
  _______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,
  _______,  KC_LT,  KC_GT,KC_LPRN,KC_RPRN,_______,
  _______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,
                                          _______,_______,
                                                  _______,
                                  _______,_______,_______,

          _______,_______,_______,_______,_______,_______,_______,
          _______,_______,_______,_______,_______,_______,_______,
                  _______,KC_LCBR,KC_RCBR,KC_LBRC,KC_RBRC,_______,
          _______,_______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,
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
[_LOL] = LAYOUT_ergodox(
  _______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,
  _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
  _______,_______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,
                                          _______,_______,
                                                  _______,
                                  _______,_______,_______,

          _______,_______,_______,_______,_______,_______,_______,
          _______,_______,_______,_______,_______,_______,_______,
                     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,_______,
          _______,_______,_______,_______,_______,_______,_______,
                          _______,_______,_______,_______,_______,
          _______,_______,
          _______,
          _______,_______,_______
  )
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};

/*
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}
*/
