#----------------------------------------------------------------------------
# make gboards/gergoplex:default:flash
# Make sure you have dfu-programmer installed!
#----------------------------------------------------------------------------

#Debug options
VERBOSE                = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX           = no
CONSOLE_ENABLE         = yes

#Combos!
VPATH                  +=  keyboards/gboards/

ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
