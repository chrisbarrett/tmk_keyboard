#include "keymap_common.h"

/* Soft dvorak layout
 *
 */


/* Mapping from Programmer Dvorak to qwerty.
 *
 * This is needed to account for the difference in symbol and number keys
 * between standard dvorak and Programmer Dvorak.
 */

#define DV_EXCLMRK    SHIFT(KC_MINUS)
#define DV_AT         SHIFT(KC_RBRACKET)
#define DV_PCT        SHIFT(KC_1)
#define DV_LBRKT      KC_3
#define DV_RBRKT      KC_4
#define DV_HASH       KC_EQUAL
#define DV_CARET      SHIFT(KC_RBRACKET)
#define DV_DOLLAR     SHIFT(KC_QUOTE)
#define DV_PIPE       KC_BSLASH
#define DV_BSLASH     SHIFT(KC_BSLASH)
#define DV_LBRACE     KC_2
#define DV_RBRACE     KC_0
#define DV_LPAREN     KC_5
#define DV_RPAREN     KC_8
#define DV_AMP        KC_1
#define DV_TICK       KC_EQUAL
#define DV_MINUS      KC_QUOT
#define DV_SLASH      KC_LBRACKET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,    \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_FN4, KC_FN5,     \
         KC_SPC, KC_FN0, DV_MINUS, DV_SLASH, KC_ENT),                   \

  /* 1: fn with undvorak-ized punctuation
   *
   *  !    @      {     }    %        ||     pgup    7     8     9    *
   *  #    |      ^     $    \        ||     pgdn    4     5     6    +
   *  [    ]      (     )    &        ||       `     1     2     3    -
   * L2  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  KEYMAP(DV_EXCLMRK, DV_AT, DV_LBRKT, DV_RBRKT, DV_PCT,                 \
         KC_PGUP, KC_P7, KC_P8, KC_P9, KC_KP_ASTERISK,                  \
         DV_HASH, DV_PIPE, DV_CARET, DV_DOLLAR, DV_BSLASH,              \
         KC_PGDN, KC_P4, KC_P5, KC_P6, KC_KP_PLUS,                      \
         DV_LBRACE, DV_RBRACE, DV_LPAREN, DV_RPAREN, DV_AMP,            \
         DV_TICK, KC_P1, KC_P2, KC_P3, KC_KP_MINUS,                     \
         KC_FN1, SHIFT(KC_INS), KC_LGUI, KC_FN4, KC_BSPC, KC_LCTL, KC_LALT, \
         KC_SPC, KC_FN0, KC_KP_DOT, KC_KP_0, KC_KP_EQUAL),              \

  /* 2: arrows and function keys */
  KEYMAP(KC_INS, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_UP, KC_F7, KC_F8, KC_F9, KC_F10, \
         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_FN3, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, \
         KC_NO, KC_LSFT, KC_LGUI, KC_FN4, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_ENT)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_UP),
  [5] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_DOWN),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
