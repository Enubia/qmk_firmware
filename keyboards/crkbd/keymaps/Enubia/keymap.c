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

enum layer_names {
    _MAC,
    _WIN,
    _COLEMAKDH_MAC,
    _COLEMAKDH_WIN,
    _POE,
    _SYMBOL,
    _NAVIGATION,
    _NUMBERS,
    _MEDIA,
    _FUNCTION
};

enum home_row_mods {
    LGUI_A = LGUI_T(KC_A),
    LALT_S = LALT_T(KC_S),
    LCTL_D = LCTL_T(KC_D),
    LSFT_F = LSFT_T(KC_F),

    RSFT_J = RSFT_T(KC_J),
    RCTL_K = RCTL_T(KC_K),
    RALT_L = RALT_T(KC_L),
    RGUI_SEM = RGUI_T(KC_SEMICOLON),

    // windows swaps
    LCTL_A = LCTL_T(KC_A),
    LGUI_D = LGUI_T(KC_D),

    RGUI_K = RGUI_T(KC_K),
    RCTL_SEM = RCTL_T(KC_SEMICOLON),

    // colemak dh swaps mac
    LGUI_AM = LGUI_T(KC_A),
    LALT_RM = LALT_T(KC_R),
    LCTL_SM = LCTL_T(KC_S),
    LSFT_TM = LSFT_T(KC_T),

    RSFT_NM = RSFT_T(KC_N),
    RCTL_EM = RCTL_T(KC_E),
    RALT_IM = RALT_T(KC_I),
    RGUI_OM = RGUI_T(KC_O),

    // colemak dh swaps windows
    LCTL_AW = LCTL_T(KC_A),
    LALT_RW = LALT_T(KC_R),
    LGUI_SW = LGUI_T(KC_S),
    LSFT_TW = LSFT_T(KC_T),

    RSFT_NW = RGUI_T(KC_N),
    RGUI_EW = RGUI_T(KC_E),
    RALT_IW = RALT_T(KC_I),
    RCTL_OW = RCTL_T(KC_O),
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
    MAC = PDF(_MAC),
    WIN = PDF(_WIN),
    COL_MAC = PDF(_COLEMAKDH_MAC),
    COL_WIN = PDF(_COLEMAKDH_WIN),
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

enum combos {
    COMMA_DOT_SCLN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,   POE  ,   COL_MAC ,   KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_ESC , LGUI_A , LALT_S , LCTL_D , LSFT_F ,  KC_G  ,   WIN  ,   COL_WIN ,   KC_H  ,  RSFT_J,  RCTL_K,  RALT_L,RGUI_SEM, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,                        KC_N  ,  KC_M  , KC_COMM, KC_DOT ,KC_SLASH, RE_SHFT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                ESC_MD ,BCSP_NAV, KC_TAB ,    ENT_SYM, SPC_NUM, DEL_FUN
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    [_WIN] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,   POE  ,   COL_MAC ,   KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_ESC , LCTL_A , LALT_S , LGUI_D , LSFT_F ,  KC_G  ,   MAC  ,   COL_WIN ,   KC_H  ,  RSFT_J,  RGUI_K,  RALT_L,RCTL_SEM, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,                        KC_N  ,  KC_M  , KC_COMM, KC_DOT ,KC_SLASH, RE_SHFT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                ESC_MD ,BCSP_NAV, KC_TAB ,    ENT_SYM, SPC_NUM, DEL_FUN
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    [_COLEMAKDH_MAC] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TAB ,  KC_Q  ,  KC_W  ,  KC_F  ,  KC_P  ,  KC_B  ,   POE  ,   COL_MAC ,   KC_J ,  KC_L  ,  KC_U ,   KC_Y  , KC_SCLN, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_ESC , LGUI_AM, LALT_RM, LCTL_SM, LSFT_TM,  KC_G  ,   MAC  ,   COL_WIN ,   KC_M  ,RSFT_NM, RCTL_EM, RALT_IM, RGUI_OM, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_D  ,  KC_V  ,                        KC_K ,  KC_H  , KC_COMM, KC_DOT ,KC_SLASH, RE_SHFT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                ESC_MD ,BCSP_NAV, KC_TAB ,    ENT_SYM, SPC_NUM, DEL_FUN
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    [_COLEMAKDH_WIN] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TAB ,  KC_Q  ,  KC_W  ,  KC_F  ,  KC_P  ,  KC_B  ,   POE  ,   COL_MAC ,   KC_J ,  KC_L  ,  KC_U ,   KC_Y  , KC_SCLN, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_ESC , LCTL_AW, LALT_RW, LGUI_SW, LSFT_TW,  KC_G  ,   WIN  ,   COL_WIN ,   KC_M  ,RSFT_NW, RGUI_EW, RALT_IW, RCTL_OW, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_D  ,  KC_V  ,                        KC_K ,  KC_H  , KC_COMM, KC_DOT ,KC_SLASH, RE_SHFT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                ESC_MD ,BCSP_NAV, KC_TAB ,    ENT_SYM, SPC_NUM, DEL_FUN
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    [_SYMBOL] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, LCURLY ,  AMPER ,  ASTER ,  LPRN  , RCURLY , XXXXXXX,   XXXXXXX,  _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,  COLON ,   DLR  ,   PERC ,  CIRC  ,  PLUS  , XXXXXXX,   XXXXXXX,  _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
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
            KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, XXXXXXX,   XXXXXXX,  _______, KC_LEFT, KC_DOWN,  KC_UP ,KC_RIGHT, KC_EQL ,
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
            _______, KC_SCLN,  KC_4  ,  KC_5  ,  KC_6  , KC_EQL , XXXXXXX,   XXXXXXX,  _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
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
            _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, XXXXXXX,   XXXXXXX,  _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______,
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
            _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______, XXXXXXX,   XXXXXXX,  _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______,                      _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______,KC_SPACE, KC_TAB ,    _______, _______, _______
        //                                    |--------+--------+--------|  |--------+--------+--------|
    ),

    // games layers

    [_POE] = LAYOUT_split_3x6_3_ex2(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_GRV ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,   WIN  ,   COL_MAC , _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_ESC ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,   MAC  ,   COL_WIN , _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT,  KC_G  ,  KC_P  ,  KC_C  ,  KC_I  ,  KC_O  ,                      _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LCTL,KC_SPACE,LALT_TAB,    _______, _______, _______
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

const rgblight_segment_t PROGMEM mac_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_BLUE}
);
const rgblight_segment_t PROGMEM win_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_RED}
);
const rgblight_segment_t PROGMEM colm_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM colw_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_TEAL}
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
    mac_layer,
    win_layer,
    colm_layer,
    colw_layer,
    poe_layer,
    sym_layer,
    nav_layer,
    num_layer,
    media_layer,
    fun_layer
);

const uint16_t PROGMEM comma_dot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [COMMA_DOT_SCLN] = COMBO(comma_dot_combo, KC_SCLN)
};

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;

    // Default to MAC layer color
    rgblight_sethsv(HSV_WHITE);
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
};

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _MAC:
            rgblight_sethsv(HSV_WHITE);
            break;
        case _WIN:
            rgblight_sethsv(HSV_BLUE);
            break;
        case _COLEMAKDH_MAC:
            rgblight_sethsv(HSV_ORANGE);
            break;
        case _COLEMAKDH_WIN:
            rgblight_sethsv(HSV_TEAL);
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
        case _MAC:
        case _WIN:
        case _POE:
        case _COLEMAKDH_MAC:
        case _COLEMAKDH_WIN:
            // Check which base layer is the default
            switch (biton32(default_layer_state)) {
                case _MAC:
                    rgblight_sethsv(HSV_WHITE);
                    break;
                case _WIN:
                    rgblight_sethsv(HSV_BLUE);
                    break;
                case _COLEMAKDH_MAC:
                    rgblight_sethsv(HSV_ORANGE);
                    break;
                case _COLEMAKDH_WIN:
                    rgblight_sethsv(HSV_TEAL);
                    break;
                case _POE:
                    rgblight_sethsv(HSV_GREEN);
                    break;
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
            set_single_persistent_default_layer(_MAC);
            rgblight_sethsv(HSV_WHITE);
            break;
        case OS_LINUX:
        case OS_WINDOWS:
            set_single_persistent_default_layer(_WIN);
            rgblight_sethsv(HSV_BLUE);
            break;
        case OS_UNSURE:
        case OS_IOS:
            break;
    }

    return true;
}
