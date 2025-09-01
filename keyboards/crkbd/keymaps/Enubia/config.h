/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MASTER_RIGHT

#define SPLIT_MODS_ENABLE

// Allow the current layer to be synced between the halves.
#define SPLIT_LAYER_STATE_ENABLE

# define RGBLED_SPLIT \
    { 23, 23 }

#define USE_SERIAL_PD2

#define TAPPING_TERM 180

#define TAPPING_TERM_PER_KEY

// no longer needed since it's default now
// #define IGNORE_MOD_TAP_INTERRUPT

#define PERMISSIVE_HOLD

#define COMBO_TERM 15

#define COMBO_TERM_PER_COMBO

#ifdef RGBLIGHT_ENABLE
#    undef RGBLIGHT_LED_COUNT
#    define RGBLIGHT_LED_COUNT 46
#    undef RGBLED_SPLIT
#    undef RGBLIGHT_LIMIT_VAL
#    define RGBLIGHT_LIMIT_VAL 200
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_MAX_LAYERS 8
#    define SPLIT_LAYER_STATE_ENABLE
#endif
