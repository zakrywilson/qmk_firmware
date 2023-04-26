#include QMK_KEYBOARD_H

enum ferris_layers {
  _BASE,
  _SYM,
  _NAV,
  _NUM,
};

#define NAV_SLSH LT(_NAV, KC_SLSH) // Turn on navigration layer when held, slash when tapped
#define NUM      MO(_NUM)          // Momentarily turn on number layer when pressed
#define SYM_BSPC LT(_SYM, KC_BSPC) // Turn on symbol layer when held, backspace when tapped

#define CMD_0    LCMD_T(KC_0)      // Left Cmd if held, 0 if tapped
#define CMD_ESC  LCMD_T(KC_ESC)    // Left Cmd if held, escape if tapped
#define CTL_0    LCTL_T(KC_0)      // Left Ctrl if held, 0 if tapped
#define CTL_SPC  LCTL_T(KC_SPC)    // Left Ctrl if held, space if tapped
#define OPT_0    LOPT_T(KC_0)      // Left Opt if held, 0 if tapped
#define OPT_Z    LOPT_T(KC_Z)      // Left Opt when held, Z when tapped
#define SFT_SPC  LSFT_T(KC_SPC)    // Left shift if held, space if tapped

#define MAC      AG_NORM           // Unswap Alt & Opt and Gui & Cmd to work for Mac (default)
#define NIX      AG_SWAP           // Swap Alt & Opt and Gui & Cmd to work for Linux


enum combos {
  // Top row
  Q_A__EXLM,
  W_R__AT,
  F_S__HASH,
  P_T__DLR,
  G_D__PERC,
  J_H__CIRC,
  L_N__AMPR,
  U_E__ASTR,
  Y_I__LPRN,
  SCLN_O__RPRN,
  // Left hand
  X_C__STAB,
  C_V__TAB,
  P_G__DEL,
  T_D__BSPC,
  V_B__ENT,
  // Right hand hand
  M_COMM__ENT,
  // Length
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// Top row
const uint16_t PROGMEM q_a[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM w_r[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM f_s[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM p_t[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM g_d[] = {KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM j_h[] = {KC_J, KC_H, COMBO_END};
const uint16_t PROGMEM l_n[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM u_e[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM y_i[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM scln_o[] = {KC_SCLN, KC_O, COMBO_END};
// Left hand
const uint16_t PROGMEM x_c[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_v[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM p_g[] = {KC_P, KC_G, COMBO_END};
const uint16_t PROGMEM t_d[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM v_b[] = {KC_V, KC_B, COMBO_END};
// Right hand
const uint16_t PROGMEM m_comm[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[] = {
  // Top row
  [Q_A__EXLM] = COMBO(q_a, KC_EXLM),
  [W_R__AT] = COMBO(w_r, KC_AT),
  [F_S__HASH] = COMBO(f_s, KC_HASH),
  [P_T__DLR] = COMBO(p_t, KC_DLR),
  [G_D__PERC] = COMBO(g_d, KC_PERC),
  [J_H__CIRC] = COMBO(j_h, KC_CIRC),
  [L_N__AMPR] = COMBO(l_n, KC_AMPR),
  [U_E__ASTR] = COMBO(u_e, KC_ASTR),
  [Y_I__LPRN] = COMBO(y_i, KC_LPRN),
  [SCLN_O__RPRN] = COMBO(scln_o, KC_RPRN),
  // Left hand
  [X_C__STAB] = COMBO(x_c, S(KC_TAB)),
  [C_V__TAB] = COMBO(c_v, KC_TAB),
  [P_G__DEL] = COMBO(p_g, KC_DEL),
  [T_D__BSPC] = COMBO(t_d, KC_BSPC),
  [V_B__ENT] = COMBO(v_b, KC_ENT),
  // Right hand
  [M_COMM__ENT] = COMBO(m_comm, KC_ENT),
};


enum tap_dances {
  SPC_CTL = 0
};

tap_dance_action_t tap_dance_actions[] = {
  [SPC_CTL]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_LCTL)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,  KC_W, KC_F, KC_P, KC_G,    KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,
    KC_A,  KC_R, KC_S, KC_T, KC_D,    KC_H, KC_N, KC_E,    KC_I,   KC_O,
    OPT_Z, KC_X, KC_C, KC_V, KC_B,    KC_K, KC_M, KC_COMM, KC_DOT, NAV_SLSH,
             TD(SPC_CTL), CMD_ESC,    SYM_BSPC, CTL_SPC
  ),

  [_SYM] = LAYOUT(
    KC_TAB, KC_7, KC_8, KC_9, KC_PERC,     KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_COLON,
    CTL_0,  KC_4, KC_5, KC_6, KC_PIPE,     KC_GRV,  KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT,
    OPT_0,  KC_1, KC_2, KC_3, KC_COLON,    KC_BSLS, KC_EQL,  KC_LT,   KC_GT,   KC_TRNS,
                        SFT_SPC, CMD_0,    KC_TRNS, KC_LCTL
  ),

  [_NAV] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_HOME, KC_UP,   KC_END,  MAC,
    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_DEL,    KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, NIX,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_ENT,  KC_PGUP, KC_PGDN, KC_TRNS,
                              SFT_SPC, KC_LCMD,    NUM, CTL_SPC

  ),

  [_NUM] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_TAB,  KC_7, KC_8, KC_9, KC_COLON,
    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_DEL,    KC_MINS, KC_4, KC_5, KC_6, KC_0,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_ENT,  KC_1, KC_2, KC_3, KC_SLSH,
                              KC_LSFT, KC_LCMD,    KC_TRNS, SFT_SPC
  )

};


// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#hold-on-other-key-press
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SYM_BSPC:
      return true;
    default:
      return false;
  }
}
