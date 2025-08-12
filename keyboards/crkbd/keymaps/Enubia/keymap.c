/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

// changes save action depending on the operating system
#ifdef __APPLE__
    #define KC_SAVE LGUI(KC_S)
#else
    #define KC_SAVE LCTL(KC_S)
#endif

enum layer_names {
    _BASE,
    // games layers
    _POE,
    // other layers
    _SYMBOL,
    _NAVIGATION,
    _NUMBERS,
    _MEDIA,
    _FUNCTION
};

enum home_row_mods {
    LSFT_F = LSFT_T(KC_F),
    LCTL_D = LCTL_T(KC_D),
    LALT_S = LALT_T(KC_S),
    LGUI_A = LGUI_T(KC_A),

    RSFT_J = RSFT_T(KC_J),
    RCTL_K = RCTL_T(KC_K),
    RALT_L = RALT_T(KC_L),
    RGUI_SEM = RGUI_T(KC_SEMICOLON),

    // swaps
    LCTL_A = LCTL_T(KC_A),
    LGUI_D = LGUI_T(KC_D),

    RGUI_K = RGUI_T(KC_K),
    RCTL_SEM = RCTL_T(KC_SEMICOLON),
};

enum other_mods {
    RE_SHFT = RSFT_T(KC_ENT),
    LALT_TAB = LALT_T(KC_TAB)
};

enum thumb_cluster_mods {
    ESC_MD = LT(_MEDIA, KC_ESC),
    BCSP_NAV = LT(_NAVIGATION, KC_BSPC),
    // TAB_MS = LT(_EMPTY, KC_TAB),
    ENT_SYM = LT(_SYMBOL, KC_ENT),
    SPC_NUM = LT(_NUMBERS, KC_SPACE),
    DEL_FUN = LT(_FUNCTION, KC_DELETE),
};

enum shifted_keys {
    LCURLY = S(KC_LBRC),
    RCURLY = S(KC_RBRC),
    EXCL = S(KC_1),
    AT = S(KC_2),
    HASH = S(KC_3),
    DLR = S(KC_4),
    PERC = S(KC_5),
    CIRC = S(KC_6),
    AMPER = S(KC_7),
    ASTER = S(KC_8),
    LPRN = S(KC_9),
    RPRN = S(KC_0),
    PLUS = S(KC_EQL),
    UNDR = S(KC_MINS),
    TILD = S(KC_GRV),
    PIPE = S(KC_BSLS),
    COLON = S(KC_SCLN),
    QUOTE = S(KC_QUOTE),
    LESS = S(KC_COMMA),
    GREATER = S(KC_DOT),
    QUESTION = S(KC_SLASH)
};

enum permanent_layers {
    BASE = PDF(_BASE),
    POE = PDF(_POE)
};

enum media_keys {
    VOL_UP = KC_KB_VOLUME_UP,
    VOL_DWN = KC_KB_VOLUME_DOWN,
    MUTE = KC_KB_MUTE,
};

enum discord_keys {
    TGL_MT = KC_F24,
    TGL_DFN = KC_F23,
};

enum combo_events {
    AS_SAVE_COMBO,
    COMBO_LENGTH
};

// gui and ctrl are swapped on macOS
// ORDER IS IMPORTANT, BASE AND POE LAYERS NEED TO BE FIRST SO THAT OTHER LAYERS ARE NOT AFFECTED
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,   POE  ,   XXXXXXX,   KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        #ifdef __APPLE__
            KC_ESC , LGUI_A , LALT_S , LCTL_D , LSFT_F ,  KC_G  , XXXXXXX,   XXXXXXX,   KC_H  , RSFT_J ,  RCTL_K,  RALT_L,RGUI_SEM, KC_QUOT,
        #else
            KC_ESC , LCTL_A , LALT_S , LGUI_D , LSFT_F ,  KC_G  , XXXXXXX,   XXXXXXX,   KC_H  , RSFT_J ,  RGUI_K,  RALT_L,RCTL_SEM, KC_QUOT,
        #endif
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,                       KC_N  ,  KC_M  , KC_COMM, KC_DOT ,KC_SLASH, RE_SHFT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                ESC_MD ,BCSP_NAV, KC_TAB ,    ENT_SYM, SPC_NUM, DEL_FUN
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    // games layers

    [_POE] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_GRV ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,   BASE  ,   XXXXXXX,  _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_ESC ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  , XXXXXXX ,   XXXXXXX,  _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_G  ,  KC_P  ,  KC_C  ,  KC_I  ,  KC_O  ,                      _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LCTL,KC_SPACE,LALT_TAB,    _______, _______, _______
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    // other layers

    [_SYMBOL] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, LCURLY ,  AMPER ,  ASTER ,  LPRN  , RCURLY , XXXXXXX,   XXXXXXX,  _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        #ifdef __APPLE__
            _______,  COLON ,   DLR  ,   PERC ,  CIRC  ,  PLUS  , XXXXXXX,   XXXXXXX,  _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        #else
            _______,  COLON ,   DLR  ,   PERC ,  CIRC  ,  PLUS  , XXXXXXX,   XXXXXXX,  _______, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
        #endif
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_GRV ,  EXCL  ,    AT  ,  HASH  ,  PIPE  ,                      _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                LPRN   ,  RPRN  , KC_MINS,    _______, _______, _______
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    [_NAVIGATION] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, KC_AGAIN,KC_PASTE, KC_COPY, KC_CUT , KC_UNDO, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        #ifdef __APPLE__
            _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, XXXXXXX,   XXXXXXX,  _______, KC_LEFT, KC_DOWN,  KC_UP ,KC_RIGHT, KC_EQL ,
        #else
            _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______, XXXXXXX,   XXXXXXX,  _______, KC_LEFT, KC_DOWN,  KC_UP ,KC_RIGHT, KC_EQL ,
        #endif
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______,                      KC_INS , KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,   KC_ENTER, KC_BSPC, KC_DEL
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    [_NUMBERS] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_LBRC,  KC_7  ,  KC_8  ,  KC_9  , KC_RBRC, XXXXXXX,   XXXXXXX,  _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        #ifdef __APPLE__
            _______, KC_SCLN,  KC_4  ,  KC_5  ,  KC_6  , KC_EQL , XXXXXXX,   XXXXXXX,  _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        #else
            _______, KC_SCLN,  KC_4  ,  KC_5  ,  KC_6  , KC_EQL , XXXXXXX,   XXXXXXX,  _______, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
        #endif
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_GRV ,  KC_1  ,  KC_2  ,  KC_3  , KC_BSLS,                      _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_DOT ,  KC_0  , KC_MINS,    _______, _______, _______
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    [_MEDIA] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX,  _______, _______, TGL_MT , TGL_DFN, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        #ifdef __APPLE__
            _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, XXXXXXX,   XXXXXXX,  _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______,
        #else
            _______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, _______, XXXXXXX,   XXXXXXX,  _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______,
        #endif

        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______,                      _______, _______, VOL_DWN, VOL_UP , _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    _______, _______, _______
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    [_FUNCTION] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,  KC_F9 , KC_F10 , KC_F11 , KC_F12 , _______, XXXXXXX,   XXXXXXX,  _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        #ifdef __APPLE__
            _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______, XXXXXXX,   XXXXXXX,  _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        #else
            _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______, XXXXXXX,   XXXXXXX,  _______, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
        #endif
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______,                      _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______,KC_SPACE, KC_TAB ,    _______, _______, _______
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_F:
        case LGUI_D:
        case LALT_S:
        case LGUI_A:
        case RSFT_J:
        case RCTL_K:
        case RALT_L:
        case RGUI_SEM:
            return TAPPING_TERM + 70;
        default:
            return TAPPING_TERM;
    }
}

enum combos {
    AS_SAVE
};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};

combo_t key_combos[] = {
    [AS_SAVE] = COMBO(as_combo, KC_SAVE),
};

const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_WHITE}
);
const rgblight_segment_t PROGMEM poe_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_GREEN}
);
const rgblight_segment_t PROGMEM sym_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_PINK}
);
const rgblight_segment_t PROGMEM num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM media_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_CYAN}
);
const rgblight_segment_t PROGMEM fun_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_MAGENTA}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    poe_layer,
    sym_layer,
    nav_layer,
    num_layer,
    media_layer,
    fun_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;

    // Default layer color
    rgblight_sethsv(HSV_WHITE);
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
};

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            rgblight_sethsv(HSV_WHITE);
            break;
        case _POE:
            rgblight_sethsv(HSV_GREEN);
            break;
    }

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t highest_layer = get_highest_layer(state);

    switch (highest_layer) {
        case _BASE:
        case _POE:
            // Check which base layer is the default
            if (biton32(default_layer_state) == _POE) {
                rgblight_sethsv(HSV_GREEN);
            } else {
                rgblight_sethsv(HSV_WHITE);
            }
            break;
        case _SYMBOL:
            rgblight_sethsv(HSV_PURPLE);
            break;
        case _NAVIGATION:
            rgblight_sethsv(HSV_PINK);
            break;
        case _NUMBERS:
            rgblight_sethsv(HSV_YELLOW);
            break;
        case _MEDIA:
            rgblight_sethsv(HSV_CYAN);
            break;
        case _FUNCTION:
            rgblight_sethsv(HSV_MAGENTA);
            break;
    };

    return state;
};

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    switch (detected_os) {
        case OS_MACOS:
        case OS_LINUX:
        case OS_WINDOWS:
            set_single_persistent_default_layer(_BASE);
            rgblight_sethsv(HSV_WHITE);
            break;
        case OS_UNSURE:
        case OS_IOS:
            break;
    }

    return true;
}
