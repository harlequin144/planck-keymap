#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// place overrides here

// It makes sure the release happens on the same layer as the press, regardless
// of the actual state of layers. 
#define PREVENT_STUCK_MODIFIERS


// Disabling rollover allows you to use the opposite shift key to cancel the
// space cadet state in the event of an erroneous press instead of emitting a
// pair of parentheses when the keys are released.
//#define DISABLE_SPACE_CADET_ROLLOVER


// Number of taps needed to toggle number layer
#define TAPPING_TOGGLE 2

#endif
