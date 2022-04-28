#include QMK_KEYBOARD_H

#define COLEMAK 0
#define QWERTY 1
#define SYM 2
#define MOVE 3
#define FUN 4
#define SETTINGS 5


#ifdef COMBO_ENABLE

  enum combos {
    QA_EXLM,
    WR_AT,
    FS_HASH,
    PT_DLR,
    GD_PERC,
    JH_CIRC,
    LN_AMPR,
    UE_ASTR
  };

  const uint16_t PROGMEM qa_combo[] = {KC_Q, KC_A, COMBO_END};
  const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
  const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
  const uint16_t PROGMEM pt_combo[] = {KC_P, KC_T, COMBO_END};
  const uint16_t PROGMEM gd_combo[] = {KC_G, KC_D, COMBO_END};
  const uint16_t PROGMEM jh_combo[] = {KC_J, KC_H, COMBO_END};
  const uint16_t PROGMEM ln_combo[] = {KC_L, KC_N, COMBO_END};
  const uint16_t PROGMEM ue_combo[] = {KC_U, KC_E, COMBO_END};

  combo_t key_combos[COMBO_COUNT] = {
    [QA_EXLM] = COMBO(qa_combo, KC_EXLM),
    [WR_AT] = COMBO(wr_combo, KC_AT),
    [FS_HASH] = COMBO(fs_combo, KC_HASH),
    [PT_DLR] = COMBO(pt_combo, KC_DLR),
    [GD_PERC] = COMBO(gd_combo, KC_PERC),
    [JH_CIRC] = COMBO(jh_combo, KC_CIRC),
    [LN_AMPR] = COMBO(ln_combo, KC_AMPR),
    [UE_ASTR] = COMBO(ue_combo, KC_ASTR)
  };

#endif


// Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// 0: Colemak
[COLEMAK] = LAYOUT(
    KC_GRV, KC_Q, KC_W, KC_F, KC_P, KC_G,                         KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS,
    KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_D,                         KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
    KC_BSLS, KC_Z, KC_X, KC_C, KC_V, KC_B, TT(SYM), KC_BSPC,      RCTL_T(KC_ESC), KC_ENT, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL,
    KC_LGUI, KC_LALT, KC_LSFT, KC_ENT, LCTL_T(KC_ESC),            KC_BSPC, MO(SYM), KC_SPC, MO(MOVE), MO(SETTINGS)),

// 1: Qwerty
[QWERTY] = LAYOUT(
    KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T,                         KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
    KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,                         KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_BSLS, KC_Z, KC_X, KC_C, KC_V, KC_B, TT(SYM), KC_BSPC,      RCTL_T(KC_ESC), KC_ENT, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL,
    KC_LGUI, KC_LALT, KC_LSFT, KC_ENT, LCTL_T(KC_ESC),            KC_BSPC, MO(SYM), KC_SPC, MO(MOVE), MO(SETTINGS)),

// 2: Symbols & Numbers
[SYM] = LAYOUT(
    KC_TRNS, KC_0, KC_7, KC_8, KC_9, KC_COLN,                     KC_TILD, KC_EXLM, KC_LPRN, KC_RPRN, KC_COLON, KC_TRNS,
    KC_NO, KC_0, KC_4, KC_5, KC_6, KC_MINS,                       KC_HASH, KC_PERC, KC_LCBR, KC_RCBR, KC_ASTR, KC_DQUO,
    KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_SLSH, KC_TRNS, KC_NO,       KC_NO, KC_NO, KC_AMPR, KC_PIPE, KC_LT, KC_GT, KC_TRNS, KC_PLUS,
    KC_TRNS, KC_TRNS, LSFT_T(KC_SPC), KC_TRNS, KC_LCTL,           KC_NO, KC_TRNS, RSFT_T(KC_SPC), KC_LBRC, KC_RBRC),

// 3: Movement
[MOVE] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO, KC_HOME, KC_UP, KC_PGUP, KC_NO, KC_NO,
    KC_TRNS, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_NO,           KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,     KC_NO, KC_NO, KC_NO, KC_END, MO(FUN), KC_PGDN, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, LSFT_T(KC_SPC), KC_TRNS, KC_LCTL,           KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO),

// 4: Functions
[FUN] = LAYOUT(
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_LCTL,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

// 5: Settings
[SETTINGS] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO, KC_NO, KC_NO, KC_NO, DF(QWERTY), DF(COLEMAK),
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO, KC_NO, KC_NO, KC_NO, AG_SWAP, AG_NORM,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                            KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_TRNS)
};
