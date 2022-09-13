// Author: Zach Wilson
// Keymap codes: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
  _COLEMAK, // default base layer
  _QWERTY,  // alternative base layer
  _SYM,     // symbols (right hand) and numbers (left hand)
  _MV,      // movement
  _NUM,     // number pad (for the right hand)
  _FN,      // functions and settings
};

#define CLMK     DF(_COLEMAK)     // Set the base (default) layer to Colemak (default)
#define CTL_CLN  LCTL_T(KC_COLON) // Left Opt when held, : when tapped
#define DEL_LN   LCMD(KC_BSPC)    // Delete a line (backwards)
#define DEL_WD   LOPT(KC_BSPC)    // Delete a word (backwards)
#define FN       MO(_FN)          // Momentarily turn on function layer when pressed
#define LOCK     LCMD(LCTL(KC_Q)) // Lock Mac
#define MAC      AG_NORM          // Unswap Alt / Opt and Gui / Cmd to work for Mac (default)
#define MV_SLSH  LT(_MV, KC_SLSH) // Turn on layer when held, kc when tapped
#define NIX      AG_SWAP          // Swap Alt / Opt and Gui / Cmd to work for Linux
#define NUM      MO(_NUM)         // Momentarily turn on number layer when pressed
#define OPT_ENT  LOPT_T(KC_ENT)   // Left Opt when held, Enter when tapped
#define OPT_SLSH LOPT_T(KC_ENT)   // Left Opt when held, / when tapped
#define OPT_Z    LOPT_T(KC_Z)     // Left Opt when held, Z when tapped
#define QWTY     DF(_QWERTY)      // Set the base (default) layer to QWERTY
#define SYM      TT(_SYM)         // Normally acts like MO unless it's tapped multiple times, which toggles layer on
#define S_SPC    LSFT_T(KC_SPC)   // Shift if held, space if tapped

#ifdef COMBO_ENABLE

enum combos {
  // Shifted number row
  Q_A__EXLM,
  W_R__AT,
  F_S__HASH,
  P_T_DLR,
  G_D__PERC,
  J_H__CIRC,
  L_N__AMPR,
  U_E__ASTR,
  Y_I__LPRN,
  SCLN_O__RPRN,
  // Modifiers
  T_D__BSPC,
  H_N__BSPC,
  P_G__DEL,
  J_L__DEL,
  // Characters
  X_C__S_TAB,
  C_V__TAB,
  M_COMM__ENT,
  S_C__ENT,
  D_B__SPC,
  // Experimental
  T_V__ESC,
  V_B__GRV,
  H_K__PLUS,
  N_M__MINS,
  E_COMM__EQL,
  Y_SCLN_COLON
};

const uint16_t PROGMEM q_a__combo[]    = {KC_Q,    KC_A,    COMBO_END};
const uint16_t PROGMEM w_r__combo[]    = {KC_W,    KC_R,    COMBO_END};
const uint16_t PROGMEM f_s__combo[]    = {KC_F,    KC_S,    COMBO_END};
const uint16_t PROGMEM p_t__combo[]    = {KC_P,    KC_T,    COMBO_END};
const uint16_t PROGMEM g_d__combo[]    = {KC_G,    KC_D,    COMBO_END};
const uint16_t PROGMEM j_h__combo[]    = {KC_J,    KC_H,    COMBO_END};
const uint16_t PROGMEM l_n__combo[]    = {KC_L,    KC_N,    COMBO_END};
const uint16_t PROGMEM u_e__combo[]    = {KC_U,    KC_E,    COMBO_END};
const uint16_t PROGMEM y_i__combo[]    = {KC_Y,    KC_I,    COMBO_END};
const uint16_t PROGMEM scln_o__combo[] = {KC_SCLN, KC_O,    COMBO_END};
const uint16_t PROGMEM p_g__combo[]    = {KC_P,    KC_G,    COMBO_END};
const uint16_t PROGMEM j_l__combo[]    = {KC_J,    KC_L,    COMBO_END};
const uint16_t PROGMEM t_d__combo[]    = {KC_T,    KC_D,    COMBO_END};
const uint16_t PROGMEM h_n__combo[]    = {KC_H,    KC_N,    COMBO_END};
const uint16_t PROGMEM x_c__combo[]    = {KC_X,    KC_C,    COMBO_END};
const uint16_t PROGMEM c_v__combo[]    = {KC_C,    KC_V,    COMBO_END};
const uint16_t PROGMEM m_comm_combo[]  = {KC_M,    KC_COMM, COMBO_END};
const uint16_t PROGMEM s_c__combo[]    = {KC_S,    KC_C,    COMBO_END};
const uint16_t PROGMEM d_b__combo[]    = {KC_D,    KC_B,    COMBO_END};
const uint16_t PROGMEM t_v__combo[]    = {KC_T,    KC_V,    COMBO_END};
const uint16_t PROGMEM v_b__combo[]    = {KC_V,    KC_B,    COMBO_END};
const uint16_t PROGMEM h_k__combo[]    = {KC_H,    KC_K,    COMBO_END};
const uint16_t PROGMEM n_m__combo[]    = {KC_N,    KC_M,    COMBO_END};
const uint16_t PROGMEM e_comm_combo[]  = {KC_E,    KC_COMM, COMBO_END};
const uint16_t PROGMEM y_scln__combo[] = {KC_Y,    KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [Q_A__EXLM]    = COMBO(q_a__combo,    KC_EXLM),
  [W_R__AT]      = COMBO(w_r__combo,    KC_AT),
  [F_S__HASH]    = COMBO(f_s__combo,    KC_HASH),
  [P_T_DLR]      = COMBO(p_t__combo,    KC_DLR),
  [G_D__PERC]    = COMBO(g_d__combo,    KC_PERC),
  [J_H__CIRC]    = COMBO(j_h__combo,    KC_CIRC),
  [L_N__AMPR]    = COMBO(l_n__combo,    KC_AMPR),
  [U_E__ASTR]    = COMBO(u_e__combo,    KC_ASTR),
  [Y_I__LPRN]    = COMBO(y_i__combo,    KC_LPRN),
  [SCLN_O__RPRN] = COMBO(scln_o__combo, KC_RPRN),
  [T_D__BSPC]    = COMBO(t_d__combo,    KC_BSPC),
  [H_N__BSPC]    = COMBO(h_n__combo,    KC_BSPC),
  [P_G__DEL]     = COMBO(p_g__combo,    KC_DEL),
  [J_L__DEL]     = COMBO(j_l__combo,    KC_DEL),
  [X_C__S_TAB]   = COMBO(x_c__combo,    S(KC_TAB)),
  [C_V__TAB]     = COMBO(c_v__combo,    KC_TAB),
  [M_COMM__ENT]  = COMBO(m_comm_combo,  KC_ENT),
  [S_C__ENT]     = COMBO(s_c__combo,    KC_ENT),
  [D_B__SPC]     = COMBO(d_b__combo,    KC_SPC),
  [T_V__ESC]     = COMBO(t_v__combo,    KC_ESC),
  [V_B__GRV]     = COMBO(v_b__combo,    KC_GRV),
  [H_K__PLUS]    = COMBO(h_k__combo,    KC_PLUS),
  [N_M__MINS]    = COMBO(n_m__combo,    KC_MINS),
  [E_COMM__EQL]  = COMBO(e_comm_combo,  KC_EQL),
  [Y_SCLN_COLON] = COMBO(y_scln__combo, KC_COLON),
};

#endif // COMBO_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   OPT_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M, KC_COMM,  KC_DOT, MV_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCMD, KC_LSFT, KC_LCTL,        SYM,  KC_SPC, KC_LOPT
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   OPT_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, MV_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCMD, KC_LSFT, KC_LCTL,        SYM,  KC_SPC, KC_LOPT
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_TAB,    KC_7,    KC_8,    KC_9,KC_COMMA,                      XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN,KC_COLON, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_0,    KC_4,    KC_5,    KC_6,  KC_DOT,                       KC_GRV, KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, OPT_ENT,    KC_1,    KC_2,    KC_3,KC_COLON,                      KC_BSLS,  KC_EQL,   KC_LT,   KC_GT, KC_TRNS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   S_SPC, KC_LCTL,    KC_TRNS,   S_SPC, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       DEL_LN, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT,  KC_DEL,                      KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       DEL_WD,  KC_ENT, KC_PGUP, KC_PGDN, KC_TRNS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   S_SPC, KC_LCTL,        NUM,   S_SPC,      FN
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, _______, _______, _______, _______, _______,                       KC_TAB,    KC_7,    KC_8,    KC_9, CTL_CLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|--------|
      XXXXXXX, _______, _______, _______, _______, _______,                      KC_MINS,    KC_4,    KC_5,    KC_6,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|--------|
      XXXXXXX, _______, _______, _______, _______, _______,                       KC_ENT,    KC_1,    KC_2,    KC_3,OPT_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCMD,   S_SPC, KC_LCTL,        SYM,   S_SPC, KC_LOPT
                                      //`--------------------------'  `--------------------------'
  ),

  [_FN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         CLMK,    QWTY,     MAC,     NIX,    LOCK, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, _______, _______,                      KC_BRIU, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_BRID, KC_VOLD, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_F11,   S_SPC,  KC_F12,    KC_LCTL, KC_LSFT, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_system_state(void) {
  oled_write_P(PSTR("System  |  "), false);
  if (keymap_config.swap_lalt_lgui) {
    oled_write_ln_P(PSTR("Linux"), false);
  } else {
    oled_write_ln_P(PSTR("Mac"), false);
  }
}

void oled_render_layout_state(void) {
  oled_write_P(PSTR("Layout  |  "), false);
  switch (get_highest_layer(default_layer_state)) {
    case _COLEMAK:
      oled_write_ln_P(PSTR("Colemak"), false);
      break;
    case _QWERTY:
      oled_write_ln_P(PSTR("Qwerty"), false);
      break;
    default:
      oled_write_P(PSTR("Undefined"), false);
  }
}

void oled_render_layer_state(void) {
  oled_write_P(PSTR("Layer   |  "), false);
  switch (get_highest_layer(layer_state)) {
    case _COLEMAK:
    case _QWERTY:
      oled_write_ln_P(PSTR("Base"), false);
      break;
    case _SYM:
      oled_write_ln_P(PSTR("Symbol"), false);
      break;
    case _MV:
      oled_write_ln_P(PSTR("Navigation"), false);
      break;
    case _NUM:
      oled_write_ln_P(PSTR("Numpad"), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR("Function"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undefined"), false);
  }
}

void render_bootmagic_status(bool status) {
  // Show Ctrl-Gui Swap options
  static const char PROGMEM logo[][2][3] = {
    {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
    {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
  };
  if (status) {
    oled_write_ln_P(logo[0][0], false);
    oled_write_ln_P(logo[0][1], false);
  } else {
    oled_write_ln_P(logo[1][0], false);
    oled_write_ln_P(logo[1][1], false);
  }
}

void oled_render_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0};
  oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_system_state();
    oled_render_layout_state();
    oled_render_layer_state();
  } else {
    oled_render_logo();
  }
  return false;
}

#endif // OLED_ENABLE
