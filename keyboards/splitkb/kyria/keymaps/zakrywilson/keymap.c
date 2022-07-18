// Author: Zach Wilson
// Keymap codes: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
#include QMK_KEYBOARD_H

#define COLEMAK 0
#define QWERTY 1
#define SYM 2
#define MOVE 3
#define FUN 4


#ifdef COMBO_ENABLE

  enum combos {
    QA_EXLM,
    WR_AT,
    FS_HASH,
    PT_DLR,
    GD_PERC,
    JH_CIRC,
    LN_AMPR,
    UE_ASTR,
    YI_LPAREN,
    SCLNO_RPAREN,
    YSCLN_COLON,
    PG_DEL,
    JL_DEL,
    TD_BCSP,
    HN_BCSP,
    XC_SFT_TAB,
    CV_TAB,
    MComm_ENT
  };

  const uint16_t PROGMEM qa_combo[] = {KC_Q, KC_A, COMBO_END};
  const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};
  const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
  const uint16_t PROGMEM pt_combo[] = {KC_P, KC_T, COMBO_END};
  const uint16_t PROGMEM gd_combo[] = {KC_G, KC_D, COMBO_END};
  const uint16_t PROGMEM jh_combo[] = {KC_J, KC_H, COMBO_END};
  const uint16_t PROGMEM ln_combo[] = {KC_L, KC_N, COMBO_END};
  const uint16_t PROGMEM ue_combo[] = {KC_U, KC_E, COMBO_END};
  const uint16_t PROGMEM yi_combo[] = {KC_Y, KC_I, COMBO_END};
  const uint16_t PROGMEM sclno_combo[] = {KC_SCLN, KC_O, COMBO_END};
  const uint16_t PROGMEM yscln_combo[] = {KC_Y, KC_SCLN, COMBO_END};
  const uint16_t PROGMEM pg_del[] = {KC_P, KC_G, COMBO_END};
  const uint16_t PROGMEM jl_del[] = {KC_J, KC_L, COMBO_END};
  const uint16_t PROGMEM td_bcsp[] = {KC_T, KC_D, COMBO_END};
  const uint16_t PROGMEM hn_bcsp[] = {KC_H, KC_N, COMBO_END};
  const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
  const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
  const uint16_t PROGMEM mcomm_combo[] = {KC_M, KC_COMM, COMBO_END};

/*
 * Combomap (vertical)
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * |     |     |     |     |     |     |                          |     |     |     |     |     |     |
 * |-----+- ! -+- @ -+- # -+- $ -+- % -|                          |- ^ -+- & -+- * -+--(--+--)--+-----|
 * |     |     |     |     |     |     |                          |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |  |     |     |     |     |     |     |     |     |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   |     |     |     |     |     |  |     |     |     |     |     |
 *                   `-----------------------------'  `-----------------------------'
 */
/*
 * Combomap (horizontal)
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * |     |     |     |     |    Del    |                          |    Del    |     |     :     |     |
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |    Bcsp   |                          |   Bcsp    |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |     |     |  S(Tab)  Tab    |     |     |     |  |     |     |     |    Ent    |     |     |     |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   |     |     |     |     |     |  |     |     |     |     |     |
 *                   `-----------------------------'  `-----------------------------'
 */
  combo_t key_combos[COMBO_COUNT] = {
    [QA_EXLM] = COMBO(qa_combo, KC_EXLM),
    [WR_AT] = COMBO(wr_combo, KC_AT),
    [FS_HASH] = COMBO(fs_combo, KC_HASH),
    [PT_DLR] = COMBO(pt_combo, KC_DLR),
    [GD_PERC] = COMBO(gd_combo, KC_PERC),
    [JH_CIRC] = COMBO(jh_combo, KC_CIRC),
    [LN_AMPR] = COMBO(ln_combo, KC_AMPR),
    [UE_ASTR] = COMBO(ue_combo, KC_ASTR),
    [YI_LPAREN] = COMBO(yi_combo, KC_LPRN),
    [SCLNO_RPAREN] = COMBO(sclno_combo, KC_RPRN),
    [YSCLN_COLON] = COMBO(yscln_combo, KC_COLON),
    [PG_DEL] = COMBO(pg_del, KC_DEL),
    [JL_DEL] = COMBO(jl_del, KC_DEL),
    [TD_BCSP] = COMBO(td_bcsp, KC_BSPC),
    [HN_BCSP] = COMBO(hn_bcsp, KC_BSPC),
    [XC_SFT_TAB] = COMBO(xc_combo, S(KC_TAB)),
    [CV_TAB] = COMBO(cv_combo, KC_TAB),
    [MComm_ENT] = COMBO(mcomm_combo, KC_ENT)
  };

#endif


// Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Keymap 0: Default Base (Colemak)
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * | Tab |  Q  |  W  |  F  |  P  |  G  |                          |  J  |  L  |  U  |  Y  |  ;  |  -  |
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * |GvEsc|  A  |  R  |  S  |  T  |  D  |                          |  H  |  N  |  E  |  I  |  O  |  '  |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |  \  |  Z  |  X  |  C  |  V  |  B  | Bspc| Del |  | Del | Ent |  K  |  M  |  ,  |  .  |MV(/)|  =  |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   | Meta| Alt | Shft| Ctrl| Ent |  | Bspc| SYM | Spc | MV  | FN  |
 *                   `-----------------------------'  `-----------------------------'
 */
[COLEMAK] = LAYOUT(
    KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_G,                                      KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS,
    QK_GESC, KC_A, KC_R, KC_S, KC_T, KC_D,                                      KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
    KC_BSLS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC, KC_DEL,   KC_DEL, KC_ENT,   KC_K, KC_M, KC_COMM, KC_DOT, LT(MOVE, KC_SLSH), KC_EQL,
    KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_ENT,               KC_BSPC, TT(SYM), KC_SPC, MO(MOVE), MO(FUN)),

/*
 * Keymap 1: Alternative Base (Qwerty)
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * | Tab |  Q  |  W  |  E  |  R  |  T  |                          |  Y  |  U  |  I  |  O  |  P  |  -  |
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * |GvEsc|  A  |  S  |  D  |  F  |  G  |                          |  H  |  J  |  K  |  L  |  ;  |  '  |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |  \  |  Z  |  X  |  C  |  V  |  B  | Bspc| Del |  | Del | Ent |  N  |  M  |  ,  |  .  |MV(/)|  =  |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   | Meta| Alt | Shft| Ctrl| Ent |  | Bspc| SYM | Spc | MV  | FN  |
 *                   `-----------------------------'  `-----------------------------'
 */
[QWERTY] = LAYOUT(
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
    QK_GESC, KC_A, KC_S, KC_D, KC_F, KC_G,                                      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_BSLS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC, KC_DEL,   KC_DEL, KC_ENT,   KC_K, KC_M, KC_COMM, KC_DOT, LT(MOVE, KC_SLSH), KC_EQL,
    KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_ENT,               KC_BSPC, TT(SYM), KC_SPC, MO(MOVE), MO(FUN)),

/*
 * Keymap 2: Symbols & Numbers
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * | Tab |  0  |  7  |  8  |  9  |  ,  |                          |  {  |  }  |  (  |  )  |  :  |  _  |
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * | Alt |  0  |  4  |  5  |  6  |  .  |                          |  `  |  -  |  [  |  ]  |  ~  |  "  |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |  \  |  0  |  1  |  2  |  3  |  :  |     |     |  |     |     |  \  |  =  |  <  |  >  |MV(/)|  +  |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   |     |     | Shft| Ctrl|     |  |     |     | Shft|     |     |
 *                   `-----------------------------'  `-----------------------------'
 */
[SYM] = LAYOUT(
    KC_TRNS, KC_0, KC_7, KC_8, KC_9, KC_COMM,                                     KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLON, KC_UNDS,
    OSM(MOD_LALT|MOD_LGUI), KC_0, KC_4, KC_5, KC_6, KC_DOT,                       KC_GRV, KC_MINS, KC_LBRC, KC_RBRC, KC_TILD, KC_DQUO,
    KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_COLON, KC_NO, KC_NO,      KC_NO, KC_NO,   KC_BSLS, KC_EQL, KC_LT, KC_GT, KC_TRNS, KC_PLUS,
    KC_TRNS, KC_TRNS, LSFT_T(KC_SPC), KC_TRNS, KC_NO,             KC_NO, KC_TRNS, RSFT_T(KC_SPC), KC_NO, KC_NO),

/*
 * Keymap 3: Movement
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * |     |     |     |     |     |     |                          |     |     | Up  |     |     |     |
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * |     | Ctrl| LGui| LAlt| Shft| Del |                          | Bspc| Left| Down| Rght|     |     |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |  | Del |     |     | Home|     | End |     |     |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   |     |     |     |     |     |  | Bspc| Ent | Shft| PgUp| PgDn|
 *                   `-----------------------------'  `-----------------------------'
 */
[MOVE] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_DEL,                           KC_BSPC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_TRNS, KC_TRNS, KC_NO, KC_HOME, KC_NO, KC_END, KC_TRNS, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                 KC_BSPC, KC_ENT,  RSFT_T(KC_SPC), KC_PGUP, KC_PGDN),

/*
 * Keymap 4: Functions
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * |     | F1  | F2  | F3  | F4  | F5  |                          |Clmk |Qwrty|     | Nix | Mac |     |
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * |     | Ctrl| LGui| LAlt| Shft|     |                          |BriUp|VolUp|     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |     | F6  | F7  | F8  | F9  | F10 | F11 | F12 |  |     |     |BriDn|VolDn|     |     |     |     |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   |     |     |     |     |     |  |     |     |     |     |     |
 *                   `-----------------------------'  `-----------------------------'
 */
[FUN] = LAYOUT(
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                   DF(COLEMAK), DF(QWERTY), KC_NO, AG_SWAP, AG_NORM, KC_NO,
    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                           KC_BRIU, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,    KC_NO, KC_NO, KC_BRID, KC_VOLD, KC_TRNS, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS),
};
