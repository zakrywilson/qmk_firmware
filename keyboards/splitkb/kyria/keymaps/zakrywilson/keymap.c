// Author: Zach Wilson
// Keymap codes: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
#include QMK_KEYBOARD_H

// Layers
enum layers {
  _COLEMAK,
  _QWERTY,
  _SYM,     // "symbols"
  _MV,      // "move"
  _FN,      // "function"
};

// Custom keys
#define CLMK     DF(_COLEMAK)     // Set the base (default) layer to Colemak (default)
#define LOCK     LCMD(LCTL(KC_Q)) // Lock Mac
#define MAC      AG_NORM          // Unswap Alt/Opt and Gui/Cmd to work for Mac (default)
#define MOD_LCMD MOD_LGUI         // Alias for MOD_LGUI
#define MOD_LOPT MOD_LALT         // Alias for MOD_LALT
#define MV_SLSH  LT(_MV, KC_SLSH) // Turn on layer when held, kc when tapped
#define NIX      AG_SWAP          // Swap Alt/Opt and Gui/Cmd to work for Linux
#define QWTY     DF(_QWERTY)      // Set the base (default) layer to QWERTY
#define S_SPC    LSFT_T(KC_SPC)   // Shift if held, space if tapped
#define DEL_WD   LOPT(KC_BSPC)    // Delete a word (backwards)
#define DEL_LN   LCMD(KC_BSPC)    // Delete a line (backwards)

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
 * Combomap
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * |     |     |     |     |     ⌦     |                          |     ⌦     |     |     :     |     |
 * |-----+- ! -+- @ -+- # -+- $ -+- % -|                          |- ^ -+- & -+- * -+--(--+--)--+-----|
 * |     |     |     |     |     ⌫     |                          |     ⌫     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |     |     |     ⇤     ⇥     |     |     |     |  |     |     |     |     ⌅     |     |     |     |
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
 * |  ⇥  |  Q  |  W  |  F  |  P  |  G  |                          |  J  |  L  |  U  |  Y  |  ;  |  -  |
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * | ` ⎋ |  A  |  R  |  S  |  T  |  D  |                          |  H  |  N  |  E  |  I  |  O  |  '  |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |  \  |  Z  |  X  |  C  |  V  |  B  |  ⌫  |  ⌦  |  |  ⌦  |  ⌅  |  K  |  M  |  ,  |  .  |MV(/)|  =  |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   |  ⌥  |  ⌘  |  ⇧  |  ⌃  |  ⌅  |  |  ⌫  | SYM |  ␣  | MV  | FN  |
 *                   `-----------------------------'  `-----------------------------'
 */
[_COLEMAK] = LAYOUT(
    KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_G,                                       KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS,
    QK_GESC, KC_A, KC_R, KC_S, KC_T, KC_D,                                       KC_H, KC_N, KC_E, KC_I, KC_O,    KC_QUOT,
    KC_BSLS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC, KC_DEL,   KC_DEL,  KC_ENT,   KC_K, KC_M, KC_COMM,    KC_DOT,  MV_SLSH, KC_EQL,
    KC_LOPT, KC_LCMD, KC_LSFT, KC_LCTL, KC_ENT,               KC_BSPC, TT(_SYM), KC_SPC, MO(_MV), MO(_FN)),

/*
 * Keymap 1: Alternative Base (Qwerty)
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * |  ⇥  |  Q  |  W  |  E  |  R  |  T  |                          |  Y  |  U  |  I  |  O  |  P  |  -  |
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * | ` ⎋ |  A  |  S  |  D  |  F  |  G  |                          |  H  |  J  |  K  |  L  |  ;  |  '  |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |  \  |  Z  |  X  |  C  |  V  |  B  |  ⌫  |  ⌦  |  |  ⌦  |  ⌅  |  N  |  M  |  ,  |  .  |MV(/)|  =  |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   |  ⌥  |  ⌘  |  ⇧  |  ⌃  |  ⌅  |  |  ⌫  | SYM |  ␣  | MV  | FN  |
 *                   `-----------------------------'  `-----------------------------'
 */
[_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                                       KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_MINS,
    QK_GESC, KC_A, KC_S, KC_D, KC_F, KC_G,                                       KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_BSLS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC, KC_DEL,   KC_DEL,  KC_ENT,   KC_K, KC_M, KC_COMM, KC_DOT, MV_SLSH, KC_EQL,
    KC_LOPT, KC_LCMD, KC_LSFT, KC_LCTL, KC_ENT,               KC_BSPC, TT(_SYM), KC_SPC, MO(_MV), MO(_FN)),

/*
 * Keymap 2: Symbols & Numbers
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * | Tab |  0  |  7  |  8  |  9  |  ,  |                          |  {  |  }  |  (  |  )  |  :  |  _  |
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * | ⌘ ⌥ |  0  |  4  |  5  |  6  |  .  |                          |  `  |  -  |  [  |  ]  |  ~  |  "  |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |  \  |  0  |  1  |  2  |  3  |  :  |     |     |  |     |     |  \  |  =  |  <  |  >  |MV(/)|  +  |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   |  ⌥  |  ⌘  | ⇧ ␣ |  ⌃  |     |  |     |#####| ⇧ ␣ |     |     |
 *                   `-----------------------------'  `-----------------------------'
 */
[_SYM] = LAYOUT(
    KC_TRNS, KC_0, KC_7, KC_8, KC_9, KC_COMM,                                     KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLON, KC_UNDS,
    OSM(MOD_LCMD|MOD_LOPT), KC_0, KC_4, KC_5, KC_6, KC_DOT,                       KC_GRV, KC_MINS, KC_LBRC, KC_RBRC, KC_TILD, KC_DQUO,
    KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_COLON, KC_NO, KC_NO,      KC_NO, KC_NO,   KC_BSLS, KC_EQL, KC_LT, KC_GT, KC_TRNS, KC_PLUS,
    KC_TRNS, KC_TRNS, S_SPC, KC_TRNS, KC_NO,                      KC_NO, KC_TRNS, S_SPC, KC_NO, KC_NO),

/*
 * Keymap 3: Movement
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * |     |     |     |     |     |     |                          | ⌘(⌫)|     |  ↑  |     |     |     |
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * |     |  ⌃  |  ⌥  |  ⌘  |  ⇧  |  ⌦  |                          |  ⌫  |  ←  |  ↓  |  →  |     |     |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |  |  ⌦  |  ⌅  | ⌥(⌫)|  ⌅  |  ↖  |  ↘  |#####|     |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   |  ⌥  |  ⌘  |  ⇧  |  ⌃  |     |  |  ⌫  |  ⌃  | ⇧ ␣ |  ⇞  |  ⇟  |
 *                   `-----------------------------'  `-----------------------------'
 */
[_MV] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    DEL_LN,  KC_NO, KC_UP, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_DEL,                           KC_BSPC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_TRNS, KC_TRNS, DEL_WD,  KC_ENT, KC_HOME, KC_END, KC_TRNS, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                 KC_BSPC, KC_LCTL, S_SPC,   KC_PGUP, KC_PGDN),

/*
 * Keymap 4: Functions
 *
 * ,-----------------------------------.                          ,-----------------------------------.
 * |     | F1  | F2  | F3  | F4  | F5  |                          |Clmk |Qwrty| Nix | Mac |     | Lock|
 * |-----+-----+-----+-----+-----+-----|                          |-----+-----+-----+-----+-----+-----|
 * |     |  ⌃  |  ⌥  |  ⌘  |  ⇧  |     |                          |BriUp|VolUp| Mute|     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----------.  ,-----------+-----+-----+-----+-----+-----+-----|
 * |     | F6  | F7  | F8  | F9  | F10 | F11 | F12 |  |     |     |BriDn|VolDn|MPlay|     |     |     |
 * `-----------------+-----+-----+-----+-----+-----|  |-----+-----+-----+-----+-----+-----------------'
 *                   |     |     |     |     |     |  |     |     |     |     |#####|
 *                   `-----------------------------'  `-----------------------------'
 */
[_FN] = LAYOUT(
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                   CLMK,    QWTY,    NIX,  MAC,      KC_NO, LOCK,
    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                           KC_BRIU, KC_VOLU, KC_MUTE, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,    KC_NO, KC_NO, KC_BRID, KC_VOLD, KC_MPLY, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
  static const char PROGMEM kyria_logo[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
    0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
    0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
  };
  oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_status(void) {
  // QMK Logo and version information
  oled_write_ln_P(PSTR("Kyria rev1.3\n"), false);

  oled_write_ln_P(keymap_config.swap_lalt_lgui ? PSTR("System: Linux\n") : PSTR("System: Mac\n"), false);

  oled_write_P(PSTR("Layout: "), false);
  switch (get_highest_layer(default_layer_state)) {
    case _COLEMAK:
      oled_write_ln_P(PSTR("Colemak\n"), false);
      break;
    case _QWERTY:
      oled_write_ln_P(PSTR("Qwerty\n"), false);
      break;
    default:
      oled_write_P(PSTR("Undefined\n"), false);
  }

  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer:  "), false);
  switch (get_highest_layer(layer_state)) {
    case _COLEMAK:
    case _QWERTY:
      oled_write_P(PSTR("Base\n"), false);
      break;
    case _SYM:
      oled_write_P(PSTR("Symbols\n"), false);
      break;
    case _MV:
      oled_write_P(PSTR("Navigation\n"), false);
      break;
    case _FN:
      oled_write_P(PSTR("Functions\n"), false);
      break;
    default:
      oled_write_P(PSTR("Undefined\n"), false);
  }
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_kyria_logo();
  }
  return false;
}
#endif
