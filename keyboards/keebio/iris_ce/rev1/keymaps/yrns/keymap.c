#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum custom_layers { GAME, MODS, NUM, SYM, FN };

void eeconfig_init_user(void) {
    set_single_persistent_default_layer(MODS);
}

// home row mod taps
#define _LA LGUI_T(KC_A)
#define _LR LALT_T(KC_R)
#define _LS LCTL_T(KC_S)
#define _LT LSFT_T(KC_T)

#define _RN RSFT_T(KC_N)
#define _RE RCTL_T(KC_E)
#define _RI RALT_T(KC_I)
#define _RO RGUI_T(KC_O)

// layer taps on thumbs
#define _ESC LT(FN, KC_ESC)
#define _SPC LT(NUM, KC_SPC)
#define _TAB LT(SYM, KC_TAB)
#define _ENT LT(SYM, KC_ENT)
#define _BSPC LT(NUM, KC_BSPC)
#define _DEL LT(FN, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [GAME] = LAYOUT(
        KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, /*                  */ KC_6, KC_7, KC_8,    KC_9,  KC_0,     KC_BSPC,
        KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_G, /*                  */ KC_J, KC_L, KC_U,    KC_Y,  KC_SCLN,  KC_DEL,
        KC_LCTL, KC_A, KC_R, KC_S, KC_T, KC_D, /*                  */ KC_H, KC_N, KC_E,    KC_I,  KC_O,     KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_HOME, /* */ KC_END, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        /*                    */ _ESC, KC_SPC, KC_TAB,  /* */ KC_ENT, KC_BSPC, KC_DEL
    ),
    // game + layer and mod taps
    [MODS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______,    _______, _______, _______,
        _______, _LA,     _LR,     _LS,     _LT,     _______, /* */ _______, _RN,     _RE,        _RI,     _RO,     _______,
        _______, _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______, _______,
        /*                      */ _______, _SPC,    _TAB, /*    */ _ENT,    _BSPC,   _DEL
    ),
    [NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, /* */ KC_NUM, KC_TAB, KC_PSLS, KC_ASTR, KC_PPLS, _______,
        _______, _______, _______, _______, _______, KC_LBRC, /* */ KC_RBRC, KC_P7, KC_P8, KC_P9, KC_PMNS, _______,
        _______, _______, _______, _______, _______, KC_LPRN, /* */ KC_RPRN, KC_P4, KC_P5, KC_P6, KC_QUOT, _______,
        _______, KC_GRV, _______, _______, _______, _______, _______, /* */ _______, KC_BSLS, KC_P1, KC_P2, KC_P3, KC_PEQL, _______,
        _______, KC_DOT, _______, /* */ KC_PENT, KC_P0, KC_PDOT
    ),
    [SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
        UG_TOGG, _______, _______, _______, _______, KC_LCBR, /* */ KC_RCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_UNDS, KC_NO,
        UG_NEXT, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_LPRN, /* */ KC_RPRN, KC_DLR,  KC_PERC, KC_CIRC, KC_DQT,  KC_NO,
        KC_MUTE, LSFT(KC_GRV), KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, _______, /* */ _______, KC_PIPE, KC_EXLM, KC_AT, KC_HASH, KC_EQL, KC_NO,
        _______, _______, _______, /* */ _______, _______, _______
    ),
    [FN] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______, /*                   */ _______, KC_F10, KC_F11, KC_F12, _______, _______,
        _______, _______, _______, _______, _______, _______, /*                   */ KC_F12,  KC_F7,  KC_F8,  KC_F9,  _______, _______,
        _______, _______, _______, _______, _______, _______, /*                   */ KC_F11,  KC_F4,  KC_F5,  KC_F6,  _______, _______,
        _______, _______, _______, _______, _______, _______, RM_TOGG, /* */ RM_NEXT, KC_F10,  KC_F1,  KC_F2,  KC_F3,  _______, _______,
        _______, _______, _______, /* */ _______, _______, TG(MODS)
    )
    // clang-format on
};

/* #ifdef OTHER_KEYMAP_C */
/* #    include OTHER_KEYMAP_C */
/* #endif // OTHER_KEYMAP_C */
