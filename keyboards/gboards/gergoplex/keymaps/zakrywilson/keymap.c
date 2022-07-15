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

/* Combomap (horizontal)
 *
 * ,-----------------------------.     ,-----------------------------.
 * |     |     |     |    Del    |     |    Del    |     |   Colon   |
 * |-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----|
 * |     |     |     |    Bspc   |     |    Bspc   |     |     |     |
 * |-----+-----+-----+-----+-----+     |-----+-----+-----+-----+-----|
 * |     |  S(Tab)  Tab   Grv    |     |     |    Ent    |     |     |
 * `-----------------------------'     `-----------------------------'
 *      .------------------------.     .------------------------.
 *      |       |        |       |     |       |       |        |
 *      '------------------------'     '------------------------'
 */
/* Combomap (vertical)
 *
 * ,-----------------------------.     ,-----------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |
 * |- ! -+- @ -+- # -+- $ -+- % -|     |- ^ -+- & -+- * -+- ( -+- ) -|
 * |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----  Ent   Esc   Spc +     |- + -+- - -+- = -+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |
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
 *      | Trns | S_T(Spc) | Ctrl |     | Trns | S_T(Spc) | Trns |
 *      '------------------------'     '------------------------'
 */
[SYM] = LAYOUT_split_3x5_3(
    KC_TAB,         KC_7, KC_8, KC_9, KC_COMMA,    KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLON,
    KC_0,           KC_4, KC_5, KC_6, KC_DOT,      KC_GRV,  KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT,
    LGUI_T(KC_ENT), KC_1, KC_2, KC_3, KC_COLON,    KC_BSLS, KC_EQL,  KC_LT,   KC_GT,   KC_TRNS,

    KC_TRNS, LSFT_T(KC_SPC), KC_LCTL,              KC_TRNS, RSFT_T(KC_SPC), KC_LGUI
    ),
/* Keymap 3: Movement
 *
 * ,-----------------------------.     ,-----------------------------.
 * |     |     |     |     |     |     |     | Home| Up  | Pgu |     |
 * |-----+-----+-----+-----+-----|     |-----------------------------|
 * | Ctl | OS  | Alt | Sft | Del |     | Bspc| Left| Dwn | Rght|     |
 * |-----+-----+-----+-----+-----+     |-----------------------------|
 * |     |     |     |     |     |     | Ent | End | FN  | Pgd | Trns|
 * `-----+-----+-----+-----+-----'     `-----------------------------'
 *      .------------------------.     .------------------------.
 *      | Trns | S_T(Spc) | Ctrl |     |NUM(/)| S_T(Spc) | Trns |
 *      '------------------------'     '------------------------'
 */
[MV] = LAYOUT_split_3x5_3(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,  KC_HOME, KC_UP,   KC_PGUP, KC_NO,
    KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_DEL,    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_ENT,  KC_END,  MO(FN),  KC_PGDN, KC_TRNS,

    KC_TRNS, LSFT_T(KC_SPC), KC_LCTL,              LT(NUM, KC_SLSH), RSFT_T(KC_SPC), KC_LGUI
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
 *      |       |        |       |     | Trns |   Spc    | Meta |
 *      '------------------------'     '------------------------'
 */
[NUM] = LAYOUT_split_3x5_3(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TAB,  KC_7, KC_8, KC_9, CTL_T(KC_COLON),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_MINS, KC_4, KC_5, KC_6, ALT_T(KC_0),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_ENT,  KC_1, KC_2, KC_3, SFT_T(KC_SLSH),

    KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_SPC, KC_TRNS
    ),
/* Keymap 4: Functions & Settings
 *
 * ,-----------------------------.     ,-----------------------------.
 * | F1  | F2  | F3  | F4  | F5  |     |DF(1)|DF(2)|     |AGSwp|AGNrm| // 1=Colemak, 2=Qwerty
 * |-----+-----+-----+-----+-----|     |-----------------------------|
 * | Ctl | OS  | Alt | Sft |     |     | BriU| VolU|     |     |     |
 * |-----+-----+-----+-----+-----+     |-----------------------------|
 * | F6  | F7  | F8  | F9  | F10 |     | BriD| VolD| Trns|     |     |
 * `-----+-----+-----+-----+-----'     `-----------------------------'
 *      .------------------------.     .------------------------.
 *      | F11  | S_T(Spc) | F12  |     | Ctl  |   Sft    | Trns |
 *      '------------------------'     '------------------------'
 */
[FN] = LAYOUT_split_3x5_3(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     DF(QWERTY), DF(COLEMAK), KC_NO,   AG_SWAP, AG_NORM,
    KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_NO,     KC_BRIU,    KC_VOLU,     KC_NO,   KC_NO,   KC_NO,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_BRID,    KC_VOLD,     KC_TRNS, KC_NO,   KC_NO,

    KC_F11,  KC_LSFT, KC_F12,                      KC_RCTL, KC_RSFT, KC_LGUI
    )
};
