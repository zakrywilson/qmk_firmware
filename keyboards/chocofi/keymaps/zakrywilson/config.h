#pragma once

// Tapping term
//
// Source: https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#tapping-term
//
// The crux of all of the following features is the tapping term setting. This
// determines what is a tap and what is a hold. The exact timing for this to
// feel natural can vary from keyboard to keyboard, from switch to switch, and
// from key to key.
#define TAPPING_TERM 200

// Permissive hold
//
// Source: https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#permissive-hold
//
// This makes tap and hold keys (like Layer Tap) work better for fast typists,
// or for high TAPPING_TERM settings. If you press a dual-role key, tap another
// key (press and release) and then release the dual-role key, all within the
// tapping term, by default the dual-role key will perform its tap action.
// If the PERMISSIVE_HOLD option is enabled, the dual-role key will perform its
// hold action instead.
#define PERMISSIVE_HOLD

// Hold on other press
//
// Source: https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#hold-on-other-key-press
//
// This mode makes tap and hold keys (like Layer Tap) work better for fast
// typists, or for high TAPPING_TERM settings. Compared to the "permissive hold"
// mode, this mode selects the hold action in more cases.
// If you press a dual-role key, press another key, and then release the
// dual-role key, all within the tapping term, by default the dual-role key will
// perform its tap action. If the HOLD_ON_OTHER_KEY_PRESS option is enabled, the
// dual-role key will perform its hold action instead.
//
// "Per key" requires implementing `get_hold_on_other_key_press` in keymap.c
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// https://docs.qmk.fm/#/feature_combo?id=combo-term
#define COMBO_TERM 30

// Reducing footprint
// Source: https://docs.qmk.fm/#/squeezing_avr
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
