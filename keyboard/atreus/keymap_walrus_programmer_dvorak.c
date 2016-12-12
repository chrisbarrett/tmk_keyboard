#include "keymap_common.h"

/* Soft dvorak layout
 *
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_FN4, KC_FN5,         \
         // KC_MINS and KC_LBRC are inverse-dvorakized
         KC_SPC, KC_FN0, KC_QUOT, KC_LBRC, KC_ENT),                     \

  /* 1: fn with undvorak-ized punctuation */
  KEYMAP(KC_1,            KC_2,        KC_3,           KC_4,         KC_5,                         KC_6,    KC_7,           KC_8,    KC_9,    KC_0, \
         KC_GRAVE,        SHIFT(KC_2), SHIFT(KC_MINS), SHIFT(KC_6),  KC_9,                         KC_PGUP, SHIFT(KC_RBRC), KC_LBRC, KC_RBRC, KC_BSLS, \
         SHIFT(KC_BSLS),  SHIFT(KC_9), SHIFT(KC_3),    SHIFT(KC_0),  KC_QUOT,                      KC_PGDN, KC_1,           KC_7,    KC_MINS, KC_EQL, \
         KC_FN1,          SHIFT(KC_5), SHIFT(KC_8),    SHIFT(KC_4),  SHIFT(KC_7), KC_LSFT, KC_FN5, KC_LSFT, KC_FN0,         KC_F3,   KC_F4,   KC_F11), \
                                                                        \
  /* 2: arrows and function keys */
  LAYER_TWO
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),

  // Modifier keys use different behaviours when tapped or held.
  [4] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_UP),
  [5] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_DOWN),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
