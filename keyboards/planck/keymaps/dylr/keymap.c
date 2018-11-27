#include "planck.h"
#include "action_layer.h"


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap
// matrix below.  The underscores don't mean anything - you can have a layer
// called STUFF or any other name.  Layer names don't all need to be of the same
// length, obviously, and you can also skip them entirely and just use numbers.
enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUM,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  EXT_PLV
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NUMS | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY] = {
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC },
  { KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT) },
  { TT(_NUM),KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT }
},


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Pause |      |      |      |      |      |      |   -  |   =  |   {  |   }  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Enter    |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = { 
  { KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN  , KC_RPRN, KC_DELT },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL , KC_LCBR  , KC_RCBR, KC_BSLS },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LBRC  , KC_RBRC, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END  }
},


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |      |PrvTrk| Pause|NxtTrk|      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Pause |      |      |      |      |      |      |CShTab| CtTb |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left |  Up  | Down | Right|      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDw | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = { 
  { KC_GRV , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY        , KC_MNXT     , XXXXXXX  , XXXXXXX, KC_DELT },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, LCTL(S(KC_TAB)), LCTL(KC_TAB), KC_BTN5  , XXXXXXX, XXXXXXX },
  { _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE        , XXXXXXX     , XXXXXXX  , XXXXXXX, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______        , KC_HOME     , KC_PGDOWN, KC_PGUP, KC_END  }
},


/* Num
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |   7  |   8  |   9  |      |BackSp|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  F9  |  F10 |  F11 |  F12 |      |      |   1  |   2  |   3  |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |   0  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */


[_NUM] = { 
  { XXXXXXX, KC_F1   , KC_F2  , KC_F3  , KC_F4  , XXXXXXX, XXXXXXX, KC_7   , KC_8, KC_9   , XXXXXXX, KC_BSPC },
  { KC_PAUS, KC_F5   , KC_F6  , KC_F7  , KC_F8  , XXXXXXX, XXXXXXX, KC_4   , KC_5, KC_6   , XXXXXXX, XXXXXXX },
  { _______, KC_F9   , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, XXXXXXX, KC_1   , KC_2, KC_3   , XXXXXXX, _______ },
  { _______, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_0, XXXXXXX, XXXXXXX, XXXXXXX }
}
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      }
      return false;
      break;
  }
  return true;
}
