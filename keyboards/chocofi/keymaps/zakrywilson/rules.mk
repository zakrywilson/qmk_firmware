# Liatris
# MCU = atmega32u4
# F_CPU = 16000000
CONVERT_TO=promicro_rp2040  # Convert from Elite-C to standard RP2040

# Features list:
# https://github.com/qmk/qmk_firmware/blob/master/docs/config_options.md#feature-options-idfeature-options

# Dynamic tapping term
#
# Source: https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#dynamic-tapping-term-iddynamic-tapping-term
#
# A feature you can enable in rules.mk that lets you use three special keys in
# your keymap to configure the tapping term on the fly:
# - DT_PRNT: types the current tapping term.
# - DT_UP: Increases the current tapping term.
# - DT_DOWN: Decreases the current tapping term.
# TODO: Do we need this?
# DYNAMIC_TAPPING_TERM_ENABLE = yes

# Combos
#
# Source: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
#
# The Combo feature is a chording type solution for adding custom actions. It
# lets you hit multiple keys at once and produce a different effect. For
# instance, hitting A and B within the combo term would hit ESC instead, or have
# it perform even more complex tasks.
# TODO: Copy over combos
VPATH += keyboards/gboards
COMBO_ENABLE = yes

# Magic
# Required for Alt/Ctrl swapping
MAGIC_ENABLE = yes

# Reducing footprint
# Source: https://docs.qmk.fm/#/squeezing_avr
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MUSIC_ENABLE = no
AUDIO_ENABLE = no
RGBLIGHT_ENABLE = no
