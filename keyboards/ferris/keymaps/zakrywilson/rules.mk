# Liatris
MCU = atmega32u4
F_CPU = 16000000
# Convert from Elite-C to standard RP2040
CONVERT_TO=promicro_rp2040

COMBO_ENABLE = yes
MAGIC_ENABLE = yes  # required for Alt/Ctrl swapping
TAP_DANCE_ENABLE = yes

# Reducing footprint
# https://docs.qmk.fm/#/squeezing_avr
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
