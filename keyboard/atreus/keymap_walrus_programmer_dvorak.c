#include "keymap_common.h"

#define KC_TILDE    SHIFT(KC_GRAVE)
#define KC_AT       SHIFT(KC_2)
#define KC_CARET    SHIFT(KC_6)
#define KC_DOLLAR   SHIFT(KC_4)
#define KC_PCT      SHIFT(KC_5)
#define KC_ASTERISK SHIFT(KC_8)
#define KC_EXCLMRK  SHIFT(KC_1)
#define KC_AMP      SHIFT(KC_7)
#define KC_LPAREN   SHIFT(KC_9)
#define KC_RPAREN   SHIFT(KC_0)
#define KC_LBRACE   SHIFT(KC_LBRACKET)
#define KC_RBRACE   SHIFT(KC_RBRACKET)
#define KC_PIPE     SHIFT(KC_BSLASH)
#define KC_HASH     SHIFT(KC_3)
#define KC_COLON    SHIFT(KC_SCLN)

/* Keymaps */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: letters */
  KEYMAP(KC_COLON, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, \
         KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S,    \
         KC_QUOT, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,   \
         KC_SPC, KC_FN0, KC_MINS, KC_SLSH, KC_ENT),                     \

  /* 1: fn with undvorak-ized punctuation
   *
   *  ~    @      ^     $    %        ||     pgup    7     8     9    *
   *  !    &      {     (    [        ||     pgdn    4     5     6    +
   *  \    |      }     )    ]        ||       `     1     2     3    -
   * L2  insert super   =  bkspc ctrl || alt space   fn    .     0    #
   */
  KEYMAP(KC_TILDE, KC_AT, KC_CARET, KC_DOLLAR, KC_PCT,                  \
         KC_PGUP, KC_7, KC_8, KC_9, KC_ASTERISK,                        \
         KC_EXCLMRK, KC_AMP, KC_LBRACKET, KC_LPAREN, KC_LBRACE,         \
         KC_PGDN, KC_4, KC_5, KC_6, KC_KP_PLUS,                         \
         KC_BSLASH, KC_PIPE, KC_RBRACKET, KC_RPAREN, KC_RBRACE,         \
         KC_GRAVE, KC_1, KC_2, KC_3, KC_KP_MINUS,                       \
         KC_FN1, SHIFT(KC_INS), KC_LGUI, KC_EQUAL, KC_BSPC, KC_FN4, KC_FN5, \
         KC_SPC, KC_FN0, KC_KP_DOT, KC_0, KC_HASH),                     \

  /* 2: arrows and function keys
   *
   *        home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   * mouse volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll enter
   */
  KEYMAP(KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP,                        \
         KC_UP, KC_F7, KC_F8, KC_F9, KC_F10,                            \
         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,                   \
         KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11,                          \
         KC_FN22, KC__VOLUP, KC_NO, KC_NO, KC_FN3, KC_NO,               \
         KC_F1, KC_F2, KC_F3, KC_F12,                                   \
         KC_NO, KC__VOLDOWN, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL,        \
         KC_LALT, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_ENT),

  /* 3: mouse control, reached by fn+esc, then holding z*/
  KEYMAP(
         //       left    up/down  right                              mouse wheel: left up/down right
         KC_NO,   KC_NO,   KC_FN6,  KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_FN11, KC_NO,   KC_NO, \
         KC_NO,   KC_FN8,  KC_FN7,  KC_FN9,  KC_NO,                   KC_NO,   KC_FN13, KC_FN10, KC_FN12, KC_NO, \
         //       acceleration settings                               buttons:    left   middle   right
         KC_ESC,  KC_FN19, KC_FN20, KC_FN21, KC_NO,                   KC_FN17,   KC_FN14, KC_FN16, KC_FN15, KC_FN18, \
         KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_NO,     KC_FN23,  KC_NO,   KC_NO,   KC_ENT \
         )
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_UP),
  [5] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_DOWN),

  [6] = ACTION_MOUSEKEY(KC_MS_U), // mouse movement
  [7] = ACTION_MOUSEKEY(KC_MS_D),
  [8] = ACTION_MOUSEKEY(KC_MS_L),
  [9] = ACTION_MOUSEKEY(KC_MS_R),
  [10] = ACTION_MOUSEKEY(KC_WH_U), // wheel
  [11] = ACTION_MOUSEKEY(KC_WH_D),
  [12] = ACTION_MOUSEKEY(KC_WH_L),
  [13] = ACTION_MOUSEKEY(KC_WH_R),
  [14] = ACTION_MOUSEKEY(KC_BTN1), // clicks
  [15] = ACTION_MOUSEKEY(KC_BTN2),
  [16] = ACTION_MOUSEKEY(KC_BTN3),
  [17] = ACTION_MOUSEKEY(KC_BTN4),
  [18] = ACTION_MOUSEKEY(KC_BTN5),
  [19] = ACTION_MOUSEKEY(KC_ACL0), // acceleration settings
  [20] = ACTION_MOUSEKEY(KC_ACL1),
  [21] = ACTION_MOUSEKEY(KC_ACL2),

  [22] = ACTION_LAYER_ON(3, 1),  // switch to layer 3
  [23] = ACTION_LAYER_OFF(3, 1),  // switch back to layer 2
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
