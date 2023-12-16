#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include <stdio.h>


// Layers
enum chocofi_layers {
  _BASE = 0,  // Colemak
  _SYM,       // Symbols and numbers
  _NAV,       // Navigation and modifiers
  _FN,        // F-keys, number pad, and misc.
};

// Aliases: Layer keys
#define FN       MO(_FN)           // Momentarily turn on number layer when pressed
#define NAV_SPC  LT(_NAV, KC_SPC)  // Turn on navigration layer when held, space when tapped
#define SYM_BSPC LT(_SYM, KC_BSPC) // Turn on symbol layer when held, backspace when tapped

// Aliases: Modifiers
#define CTL_0    LCTL_T(KC_0)      // Left Ctrl if held, 0 if tapped
#define CTRL_ESC LCTL_T(KC_ESC)    // Left Ctrl if held, escape if tapped
#define OPT_0    LOPT_T(KC_0)      // Left Opt if held, 0 if tapped
#define OPT_Z    LOPT_T(KC_Z)      // Left Opt when held, Z when tapped
#define SFT_SPC  LSFT_T(KC_SPC)    // Left shift if held, space if tapped

// Aliases: Operating systems
#define MAC      AG_NORM           // Unswap Alt & Opt and Gui & Cmd to work for Mac (default)
#define NIX      AG_SWAP           // Swap Alt & Opt and Gui & Cmd to work for Linux


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ F │ P │ G │       │ J │ L │ U │ Y │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ D │       │ H │ N │ E │ I │ O │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ K │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │Cmd├───┐           ┌───┤   │
      *           └───┤Sft├───┐   ┌───┤Spc├───┘
      *               └───┤Ctl│   │Bsp├───┘
      *                   └───┘   └───┘
      */
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                               KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
        OPT_Z,   KC_X,    KC_C,    KC_V,    KC_B,                               KC_K,    KC_M ,   KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_LCMD, KC_LSFT, CTRL_ESC,        SYM_BSPC, NAV_SPC, FN
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        KC_TAB,  KC_7,    KC_8,    KC_9,    KC_PERC,                            KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_COLON,
        CTL_0,   KC_4,    KC_5,    KC_6,    KC_PIPE,                            KC_GRV,  KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT,
        OPT_0,   KC_1,    KC_2,    KC_3,    KC_COLON,                           KC_BSLS, KC_EQL,  KC_LT,   KC_GT,   KC_TRNS,
                                   KC_TRNS, SFT_SPC, CTL_0,            KC_TRNS, KC_LCMD, KC_LOPT
    ),
    [_NAV] = LAYOUT_split_3x5_3(
        DT_UP,   DT_DOWN, DT_PRNT, MAC,     NIX,                                KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_PGUP,
        KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_DEL,                             KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_ENT,  KC_HOME, KC_END,  KC_TRNS,
                                   KC_TRNS, SFT_SPC, KC_TRNS,            KC_NO, KC_TRNS, KC_NO
    ),
    [_FN] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_TAB,  KC_7,    KC_8,    KC_9,    KC_COLON,
        KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_DEL,                             KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                             KC_ENT,  KC_1,    KC_2,    KC_3,    KC_SLSH,
                                   KC_LCMD, KC_LSFT, KC_LCTL,            KC_NO, KC_NO,   KC_TRNS
    )
};

// Hold on other key press
// Source: https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#hold-on-other-key-press
// Requires `#define HOLD_ON_OTHER_KEY_PRESS` in config.h
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYM_BSPC:
      return true;
    default:
      return false;
  }
}

// Turn off power LED
// Source: https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}
