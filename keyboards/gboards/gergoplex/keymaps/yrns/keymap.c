#include QMK_KEYBOARD_H
//#include "g/keymap_combo.h"

// from https://docs.qmk.fm/#/faq_debug
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}

// always prefer the hold on the right thumb mod tap keys for games
// (HOLD_ON_OTHER_KEY_PRESS_PER_KEY)
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RALT_T(KC_ENT):
    case RSFT_T(KC_BSPC):
    case RCTL_T(KC_DEL):
      return true;
    default:
      return false;
    }
}

enum layers { BASE, MODS, NUM, SYM, FN };

#define DEFAULT_LAYER MODS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Do we want a base-base layer w/o mod taps on the right thumb? It
  // depends on whether or not the game allows binding to
  // modifiers. The mod taps can be slow/finnicky too.
  
  // "game layer", mod taps on right thumb, no windows key. My left hand is on the mouse.
  [BASE] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN,
      KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O,
      KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH,
      LT(FN, KC_ESC), LT(NUM, KC_SPC), LT(SYM, KC_TAB), RALT_T(KC_ENT), RSFT_T(KC_BSPC), RCTL_T(KC_DEL)
      ),
  // add home row mods, replaces right thumb cluster w/ layer taps
  [MODS] = LAYOUT_split_3x5_3(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), _______, _______,
      RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),     
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, LT(SYM, KC_ENT), LT(NUM, KC_BSPC), LT(FN, KC_DEL)
      ),
  // add redundant ./3 keys since that key doesn't work
  [NUM] = LAYOUT_split_3x5_3(
      KC_1,    KC_2,    KC_3,    KC_4,    KC_LBRC, KC_RBRC, KC_7,    KC_8,    KC_9, KC_MINUS,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_LPRN, KC_RPRN, KC_4,    KC_5,    KC_6, KC_QUOT,
      KC_GRV,  KC_NO,   KC_NO,   KC_ALGR, KC_NO,   KC_BSLS, KC_1,    KC_2,    KC_3, KC_PLUS,
      /*             */ KC_NO,   KC_DOT,  KC_NO,   KC_ENT,  KC_0,    KC_DOT
  ),
  // FIX: "shift" 9 and right paren are redundant parens
  // FIX: right thumbs unused?
  [SYM] = LAYOUT_split_3x5_3(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_UNDS,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   KC_RPRN, KC_DLR,  KC_PERC, KC_CIRC, KC_DQT,
      KC_TILD, KC_ALGR, KC_NO,   KC_NO,   KC_NO,   KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_EQL,
      /*             */ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
      ),
  // FIX: right thumbs unused?
  [FN] = LAYOUT_split_3x5_3(
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,
    KC_NO,   KC_NO,   KC_NO,   TG(MODS), KC_NO,  KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,
    DB_TOGG, KC_ALGR, KC_NO,   KC_NO,    KC_NO,  KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,
    /*             */ KC_APP,  KC_SPC,   KC_TAB, KC_NO,   KC_NO,   KC_NO
  ),
};
