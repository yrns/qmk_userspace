#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum custom_layers {
     GAME,
     MODS,
     NUM,
     SYM,
     FN
};

// home row mod taps
#define _LA LGUI_T(KC_A)
#define _LR LALT_T(KC_R)
#define _LS LCTL_T(KC_S)
#define _LT LSFT_T(KC_T)

#define _RN RSFT_T(KC_N)
#define _RE RCTL_T(KC_E)
#define _RI RALT_T(KC_I)
#define _RO RGUI_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [GAME] = LAYOUT(
               KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, /*                  */ KC_6, KC_7, KC_8,    KC_9,  KC_0,     KC_BSPC,
               KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_G, /*                  */ KC_J, KC_L, KC_U,    KC_Y,  KC_SCLN,  KC_DEL,
               KC_LCTL, KC_A, KC_R, KC_S, KC_T, KC_D, /*                  */ KC_H, KC_N, KC_E,    KC_I,  KC_O,     KC_QUOT,
               KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_HOME, /* */ KC_END, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
               /*           */ LT(FN,KC_ESC), KC_SPC, KC_TAB,  /* */ KC_ENT, KC_BSPC, KC_DEL
                  ),
  // game + layer and mod taps
  [MODS] = LAYOUT(
               _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______,    _______, _______, _______,
               _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______,    _______, _______, _______,
               _______, _LA,     _LR,     _LS,     _LT,     _______, /* */ _______, _RN,     _RE,        _RI,     _RO,     _______,
               _______, _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______, _______,
               /*      */ LT(FN,KC_ESC), LT(NUM,KC_SPC), LT(SYM,KC_TAB), /*  */ LT(SYM,KC_ENT), LT(NUM,KC_BSPC), LT(FN,KC_DEL)
               ),
  [NUM] = LAYOUT(
                 _______, _______, _______, _______, _______, _______, /* */ KC_NUM, KC_TAB, KC_PSLS, LSFT(KC_8), KC_PPLS, _______,
                 _______, _______, _______, _______, _______, KC_LBRC, /* */ KC_RBRC, KC_P7, KC_P8, KC_P9, KC_PMNS, _______,
                 _______, _______, _______, _______, _______, LSFT(KC_9), /* */ LSFT(KC_0), KC_P4, KC_P5, KC_P6, KC_QUOT, _______,
                 _______, KC_GRV, _______, _______, _______, _______, _______, /* */ _______, LSFT(KC_BSLS), KC_P1, KC_P2, KC_P3, KC_PEQL, _______,
                 _______, KC_DOT, _______, /* */ KC_PENT, KC_P0, KC_PDOT
                 ),
  [SYM] = LAYOUT(
                 _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
                 UG_TOGG, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_LBRC), /* */ LSFT(KC_RBRC), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_MINS), KC_NO,
                 UG_NEXT, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, LSFT(KC_9), /* */ LSFT(KC_0), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_QUOT), KC_NO,
                 KC_MUTE, LSFT(KC_GRV), KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, LSFT(KC_9), /* */ _______, KC_BSLS, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_PPLS, KC_NO,
                 _______, _______, _______, /* */ _______, _______, _______
                 ),
  [FN] = LAYOUT(
                QK_BOOT, _______, _______, _______, _______, _______, /*                   */ _______, KC_F10, KC_F11, KC_F12, _______, _______,
                _______, _______, _______, _______, _______, _______, /*                   */ KC_F12,  KC_F7,  KC_F8,  KC_F9,  _______, _______,
                _______, _______, _______, _______, _______, _______, /*                   */ KC_F11,  KC_F4,  KC_F5,  KC_F6,  _______, _______,
                _______, _______, _______, _______, _______, _______, RM_TOGG, /* */ RM_NEXT, KC_F10,  KC_F1,  KC_F2,  KC_F3,  _______, _______,
                _______, _______, _______, /* */ _______, _______, TG(MODS)
                )
};

/* #ifdef OTHER_KEYMAP_C */
/* #    include OTHER_KEYMAP_C */
/* #endif // OTHER_KEYMAP_C */
