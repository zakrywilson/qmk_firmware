#----------------------------------------------------------------------------
# make gboards/gergoplex:default:flash
# Make sure you have dfu-programmer installed!
#----------------------------------------------------------------------------
# Firmware options
MOUSEKEY_ENABLE        = no

#Debug options
VERBOSE                = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX           = no
CONSOLE_ENABLE         = no

#Combos!
VPATH                  +=  keyboards/gboards/

DEBOUNCE_TYPE = asym_eager_defer_pk

ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
