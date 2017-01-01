#include "keymap_common.h"

/* Soft dvorak layout
 *
 */


/* Mapping from Programmer Dvorak to qwerty.
 *
 * This is needed to account for the difference in symbol and number keys
 * between standard dvorak and Programmer Dvorak.
 */

#define DV_EXCLMRK    KC_MINUS
#define DV_AT         KC_RBRACKET
#define DV_PCT        SHIFT(KC_1)
#define DV_LBRKT      KC_3
#define DV_RBRKT      KC_4
#define DV_HASH       KC_EQUAL
#define DV_CARET      SHIFT(KC_RBRACKET)
#define DV_TILDE      SHIFT(KC_GRAVE)
#define DV_DOLLAR     KC_GRAVE
#define DV_ASTERISK   KC_7
#define DV_PIPE       KC_BSLASH
#define DV_BSLASH     SHIFT(KC_BSLASH)
#define DV_LBRACE     KC_2
#define DV_RBRACE     KC_0
#define DV_LPAREN     KC_5
#define DV_RPAREN     KC_8
#define DV_AMP        KC_1
#define DV_GRAVE      SHIFT(KC_EQUAL)
#define DV_MINUS      KC_QUOT
#define DV_SLASH      KC_LBRACKET
#define DV_EQUAL      KC_6

#define DV_1        SHIFT(KC_5)
#define DV_2        SHIFT(KC_8)
#define DV_3        SHIFT(KC_4)
#define DV_4        SHIFT(KC_9)
#define DV_5        SHIFT(KC_3)
#define DV_6        SHIFT(KC_0)
#define DV_7        SHIFT(KC_2)
#define DV_8        SHIFT(KC_MINUS)
#define DV_9        SHIFT(KC_6)
#define DV_0        SHIFT(KC_7)

/* Keymaps */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,    \
         KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_FN4, KC_FN5,     \
         KC_SPC, KC_FN0, DV_MINUS, DV_SLASH, KC_ENT),                   \

  /* 1: fn with undvorak-ized punctuation
   *
   *  ~    @      ^     $    %        ||     pgup    7     8     9    *
   *  !    &      {     (    [        ||     pgdn    4     5     6    +
   *  \    |      }     )    ]        ||       `     1     2     3    -
   * L2  insert super   =  bkspc ctrl || alt space   fn    .     0    #
   */
  KEYMAP(DV_TILDE, DV_AT, DV_CARET, DV_DOLLAR, DV_PCT,                  \
         KC_PGUP, DV_7, DV_8, DV_9, DV_ASTERISK,                        \
         DV_EXCLMRK, DV_AMP, DV_LBRKT, DV_LPAREN, DV_LBRACE,            \
         KC_PGDN, DV_4, DV_5, DV_6, KC_KP_PLUS,                         \
         DV_BSLASH, DV_PIPE, DV_RBRKT, DV_RPAREN, DV_RBRACE,            \
         DV_GRAVE, DV_1, DV_2, DV_3, KC_KP_MINUS,                       \
         KC_FN1, SHIFT(KC_INS), KC_LGUI, DV_EQUAL, KC_BSPC, KC_FN4, KC_FN5, \
         KC_SPC, KC_FN0, KC_KP_DOT, DV_0, DV_HASH),                     \

  /* 2: arrows and function keys
   *
   *        home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   * mouse volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  KEYMAP(KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP,                        \
         KC_UP, KC_F7, KC_F8, KC_F9, KC_F10,                            \
         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,                   \
         KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11,                          \
         KC_FN22, KC__VOLUP, KC_NO, KC_NO, KC_FN3, KC_NO,               \
         KC_F1, KC_F2, KC_F3, KC_F12,                                   \
         KC_NO, KC__VOLDOWN, KC_LGUI, KC_FN4, KC_BSPC, KC_LCTL,         \
         KC_LALT, KC_SPC, KC_FN2, KC_NO, KC_NO, KC_ENT),

  /* 3: mouse control, reached by fn+esc, then holding z*/
  KEYMAP(
         //       left    up/down  right                              mouse wheel: left up/down right
         KC_NO,   KC_NO,   KC_FN6,  KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_FN11, KC_NO,   KC_NO, \
         KC_NO,   KC_FN8,  KC_FN7,  KC_FN9,  KC_NO,                   KC_NO,   KC_FN12, KC_FN10, KC_FN13, KC_NO, \
         //       acceleration settings                               buttons:    left   middle   right
         KC_NO,   KC_FN19, KC_FN20, KC_FN21, KC_NO,                   KC_FN17,   KC_FN14, KC_FN16, KC_FN15, KC_FN18, \
         KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_NO,     KC_FN23,  KC_NO,   KC_NO,   KC_NO \
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
