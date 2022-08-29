// Author: Zach Wilson
// Keymap codes: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum {
  COLEMAK, // default base layer
  QWERTY,  // alternative base layer
  SYM,     // symbols (right hand) and numbers (left hand)
  MV,      // movement
  NUM,     // number pad (for the right hand)
  FN,      // functions and settings
};

/* Combomap
 *
 * ,-----------------------------.     ,-----------------------------.
 * |     |     |     |     ⌦     |     |     ⌦     |     |     :     |
 * |- ! -+- @ -+- # -+- $ -+- % -|     |- ^ -+- & -+- * -+- ( -+- ) -|
 * |     |     |     |     ⌫     |     |     ⌫     |     |     |     |
 * |-----+-----|- ⌅ -|- ⎋ -|- ␣ -+     |- + -+- - -+- = -+-----+-----|
 * |     |     ⇤     ⇥     `     |     |     |     ⌅     |     |     |
 * `-----------------------------'     `-----------------------------'
 *      .------------------------.     .------------------------.
 *      |       |        |       |     |       |       |        |
 *      '------------------------'     '------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Default Base (Colemak layer)
 *
 * ,-----------------------------.      ,-----------------------------.
 * |  Q  |  W  |  F  |  P  |  G  |     |  J  |  L  |  U  |  Y  |  ;  |
 * |-----+-----+-----+-----+-----+     |-----+-----+-----+-----+-----|
 * |  A  |  R  |  S  |  T  |  D  |     |  H  |  N  |  E  |  I  |  P  |
 * |-----+-----+-----+-----+-----+     |-----+-----+-----+-----+-----|
 * |  Z  |  X  |  C  |  V  |  B  |     |  K  |  M  |  ,  |  .  |MV(/)|
 * `-----------------------------'     `-----------------------------'
 *      .------------------------.     .------------------------.
 *      |  Alt  |  Sft  |  Ctrl  |     |  SYM  |  Spc  |  Meta  |
 *      '------------------------'     '------------------------'
 */
[COLEMAK] = LAYOUT_split_3x5_3(
    KC_Q,         KC_W, KC_F, KC_P, KC_G,    KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,
    KC_A,         KC_R, KC_S, KC_T, KC_D,    KC_H, KC_N, KC_E,    KC_I,   KC_O,
    LGUI_T(KC_Z), KC_X, KC_C, KC_V, KC_B,    KC_K, KC_M, KC_COMM, KC_DOT, LT(MV, KC_SLSH),

    KC_LALT, KC_LSFT, KC_LCTL,               TT(SYM), KC_SPC,  KC_LGUI
    ),
/* Keymap 1: Alternative Base (Qwerty layer)
 *
 * ,-----------------------------.     ,-----------------------------.
 * |  Q  |  W  |  E  |  R  |  T  |     |  Y  |  U  |  I  |  O  |  P  |
 * |-----+-----+-----+-----+-----+     |-----+-----+-----+-----+-----|
 * |  A  |  S  |  D  |  F  |  G  |     |  H  |  J  |  K  |  L  |  ;  |
 * |-----+-----+-----+-----+-----+     |-----+-----+-----+-----+-----|
 * |  Z  |  X  |  C  |  V  |  B  |     |  K  |  M  |  ,  |  .  |MV(/)|
 * `-----------------------------'     `-----------------------------'
 *      .------------------------.     .------------------------.
 *      |  Alt  |  Sft  |  Ctrl  |     |  SYM  |  Spc  |  Meta  |
 *      '------------------------'     '------------------------'
 */
[QWERTY] = LAYOUT_split_3x5_3(
    KC_Q,         KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A,         KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    LGUI_T(KC_Z), KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, LT(MV, KC_SLSH),

    KC_LALT, KC_LSFT, KC_LCTL,               TT(SYM), KC_SPC,  KC_LGUI
    ),
/* Keymap 2: Symbols & Numbers
 *
 * ,-----------------------------.     ,-----------------------------.
 * | Tab |  7  |  8  |  9  |  ,  |     |  {  |  }  |  (  |  )  |  :  |
 * |-----+-----+-----+-----+-----|     |-----------------------------|
 * |  0  |  4  |  5  |  6  |  .  |     |  `  |  -  |  [  |  ]  |  '  |
 * |-----+-----+-----+-----+-----+     |-----------------------------|
 * | Ent |  1  |  2  |  3  |  :  |     |  \  |  =  |  <  |  >  | Trns|
 * `-----+-----+-----+-----+-----'     `-----------------------------'
 *      .------------------------.     .------------------------.
 *      | Trns | S_T(Spc) | Ctrl |     | #### | S_T(Spc) | Trns |
 *      '------------------------'     '------------------------'
 */
[SYM] = LAYOUT_split_3x5_3(
    KC_TAB,         KC_7, KC_8, KC_9, KC_COMMA,    KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLON,
    KC_0,           KC_4, KC_5, KC_6, KC_DOT,      KC_GRV,  KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT,
    LGUI_T(KC_ENT), KC_1, KC_2, KC_3, KC_COLON,    KC_BSLS, KC_EQL,  KC_LT,   KC_GT,   KC_TRNS,

    _______, LSFT_T(KC_SPC), KC_LCTL,              _______, RSFT_T(KC_SPC), KC_LGUI
    ),
/* Keymap 3: Movement
 *
 * ,-----------------------------.     ,-----------------------------.
 * | F1  | F2  | F3  | F4  | F5  |     |     |     | Up  |     | PgUp|
 * |-----+-----+-----+-----+-----|     |-----------------------------|
 * | Ctl | OS  | Alt | Sft | Del |     | Bspc| Left| Dwn | Rght| PgDn|
 * |-----+-----+-----+-----+-----+     |-----------------------------|
 * | F6  | F7  | F8  | F9  | F10 |     |     | Ent | Home| End | ### |
 * `-----+-----+-----+-----+-----'     `-----------------------------'
 *      .------------------------.     .------------------------.
 *      | F11  | S_T(Spc) | F12  |     | NUM  | S_T(Spc) | FN   |
 *      '------------------------'     '------------------------'
 */
[MV] = LAYOUT_split_3x5_3(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_PGUP,
    KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_DEL,    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_NO,   KC_ENT,  KC_HOME, KC_END,  KC_TRNS,

    KC_F11,  LSFT_T(KC_SPC), KC_F12,               MO(NUM), RSFT_T(KC_SPC), MO(FN)
    ),
/* Keymap 3: Number pad
 *
 * ,-----------------------------.     ,-----------------------------.
 * |     |     |     |     |     |     | Tab |  7  |  8  |  9  |  :  | // : → Mod-Tap: Ctrl
 * |-----+-----+-----+-----+-----|     |-----+-----+-----+-----------|
 * |     |     |     |     |     |     |  -  |  4  |  5  |  6  |  0  | // 0 → Mod-Tap: Alt/Cmd
 * |-----+-----+-----+-----+-----+     |-----+-----+-----+-----------|
 * |     |     |     |     |     |     | Ent |  1  |  2  |  3  |  /  | // / → Mod-Tap: Shift
 * `-----------------------------'     `-----+-----+-----+-----------'
 *      .------------------------.     .------------------------.
 *      |       |        |       |     | #### | S_T(Spc) | Meta |
 *      '------------------------'     '------------------------'
 */
[NUM] = LAYOUT_split_3x5_3(
    _______, _______, _______, _______, _______,    KC_TAB,  KC_7, KC_8, KC_9, CTL_T(KC_COLON),
    _______, _______, _______, _______, _______,    KC_MINS, KC_4, KC_5, KC_6, KC_0,
    _______, _______, _______, _______, _______,    KC_ENT,  KC_1, KC_2, KC_3, GUI_T(KC_SLSH),

    _______, _______, _______,                      KC_TRNS, RSFT_T(KC_SPC), KC_LALT
    ),
/* Keymap 4: Functions & Settings
 *
 * ,-----------------------------.     ,-----------------------------.
 * |     |     |     |     |     |     |DF(1)|DF(2)|     |AGSwp|AGNrm| // 1=Colemak, 2=Qwerty
 * |-----+-----+-----+-----+-----|     |-----------------------------|
 * |     |     |     |     |     |     | BriU| VolU| Mute|     |     |
 * |-----+-----+-----+-----+-----+     |-----------------------------|
 * |     |     |     |     |     |     | BriD| VolD| MPly|     |     |
 * `-----------------------------'     `-----------------------------'
 *      .------------------------.     .------------------------.
 *      |       |        |       |     | Ctl  |   Sft    | #### |
 *      '------------------------'     '------------------------'
 */
[FN] = LAYOUT_split_3x5_3(
    _______, _______, _______, _______, _______,    DF(QWERTY), DF(COLEMAK), KC_NO,   AG_SWAP, AG_NORM,
    _______, _______, _______, _______, _______,    KC_BRIU,    KC_VOLU,     KC_MUTE, KC_NO,   KC_NO,
    _______, _______, _______, _______, _______,    KC_BRID,    KC_VOLD,     KC_MPLY, KC_NO,   KC_NO,

    _______, _______, _______,                      KC_RCTL, KC_RSFT, KC_TRNS
    )
};
