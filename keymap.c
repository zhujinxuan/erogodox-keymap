// An Ergodox EZ keymap mostly following the programmer's dvorak layout.
// There is a standard QWERTY layer as well
//
// See the README.md file for an image of this keymap.

#include QMK_KEYBOARD_H
#include "keycodes/dual.h"

// SAFE_RANGE must be used to tag the first element of the enum.
// DYNAMIC_MACRO_RANGE must always be the last element of the enum if other
// values are added (as its value is used to create a couple of other keycodes
// after it).
enum custom_keycodes {
    MC_ARROW = SAFE_RANGE,
    DYNAMIC_MACRO_RANGE
};

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO

// Some combined keys (one normal keycode when tapped and one modifier or layer
// toggle when held).
#define SPC_RALT  MT(MOD_RALT, KC_SPC)  // SPACE key and right alt modifier.

// The most portable copy/paste keys (windows (mostly), linux, and some terminal emulators).
#define MK_CUT    LSFT(KC_DEL)  // shift + delete
#define MK_COPY   LCTL(KC_INS)  // ctrl + insert
#define MK_PASTE  LSFT(KC_INS)  // shift + insert
//Move mac desktop spaces
#define MAC_L     LGUI(LSFT(KC_UP)) // cmd + shift + up
#define MAC_R     LGUI(LSFT(KC_DOWN)) // cmd + shift + down

// This file must be included after DYNAMIC_MACRO_RANGE is defined...
#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0: basic keys.
  [_DVORAK] = LAYOUT_ergodox_pretty(
    KC_DLR,           KC_AMPR,  KC_LBRC,  KC_LCBR, KC_RCBR, KC_LPRN, KC_CIRC,           KC_F4,        KC_EQUAL,KC_ASTR, KC_BSLASH, KC_PLUS, KC_RBRACKET, KC_EXLM,
    OSMGUI, KC_SCOLON,KC_COMMA, KC_DOT,  KC_P,    KC_Y,    KC_PERC,           KC_DELETE,    KC_F,    KC_G,    KC_C,      KC_R,    KC_V,        KC_SLASH,
    OSMCTL,          KC_A,     KC_O,     LOWE,    KC_U,    KC_I,                                     KC_D,    KC_H,    LOWT,      KC_N,    KC_S,        KC_MINUS,
    OSMALT,          KC_QUOTE, KC_Q,     KC_J,    KC_K,    KC_X,    KC_LALT,           ___,          KC_B,    KC_L,    KC_M,      KC_W,    KC_Z,        KC_RSPC,
    RESET,            KC_HASH,  KC_GRAVE, KC_LEFT, KC_RIGHT,                                                   KC_UP,   KC_DOWN,   KC_HOME, KC_END,     ___,
    KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
    KC_BSLASH,           ___,
    GUI_T(KC_ESCAPE), SFT_T(KC_TAB), KC_ASTR,          KC_ASTR, SFT_T(KC_ENTER), GUI_T(KC_SPACE)),

  // Layer 1: function and numpad keys.
  [_LOWER] = LAYOUT_ergodox_pretty(
    ___,  KC_F1,   KC_F2,    KC_F3,       KC_F4,       KC_F5,      ___,  ___, KC_F6,   KC_F7,  KC_F8,  KC_F9,      KC_F10,       KC_F11,
    ___,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, ___,              ___,  KC_EQL,  KC_7,   KC_8,   KC_9,       KC_ASTR,      KC_F12,
    ___,  KC_CIRC, KC_LEFT, KC_UP,   KC_RGHT, KC_AMPR,                        KC_PLUS, KC_4,   KC_5,   KC_6,       KC_BSPC,      KC_UNDS,
    ___,  KC_COPY, KC_PASTE,KC_DOWN, KC_RPRN, KC_RBRC,    ___,  ___, KC_DQT,    KC_1,   KC_2,   KC_3,       KC_F12,  KC_BSLASH,
    ___,  ___,     ___,      ___,         ___,                                                ___,    KC_KP_DOT, KC_0,    KC_EQUAL,     ___,
    ___,    ___,         KC_KP_ASTERISK, KC_KP_SLASH,
    KC_LCTL,         ___,
    KC_KP_PLUS,  KC_KP_MINUS, KC_DLR,         KC_DELETE, KC_BSPACE,  KC_SPACE),

    // Layer 3: Mac layer
  [_RAISE] = LAYOUT_ergodox_pretty(
      /* left hand */
      ___,  KC_1, KC_2, KC_3,   KC_4,   KC_5, ___,        ___, KC_6,  KC_7, KC_8, KC_9, KC_0, ___,
      ___,  ___,  ___,  ___,    ___,    ___,  ___,        ___, ___,   ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  ___,    ___,    ___,                   ___,   ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  ___,    ___,    ___,  ___,        ___, ___,   ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  MAC_L,  MAC_R,                                ___,  ___,  ___,  ___,  ___,
                                        ___,  ___,        ___, ___,
                                              ___,        ___,
                      KC_LGUI,  KC_LALT,  KC_LGUI,        KC_LGUI, KC_LALT, KC_LGUI),
  // Layer 3: Mac layer
  [_ADJUST] = LAYOUT_ergodox_pretty(
                                   /* left hand */
                                   ___,  KC_1, KC_2, KC_3,   KC_4,   KC_5, ___,        ___, KC_6,  KC_7, KC_8, KC_9, KC_0, ___,
                                   ___,  ___,  ___,  ___,    ___,    ___,  ___,        ___, ___,   ___,  ___,  ___,  ___,  ___,
                                   ___,  ___,  ___,  ___,    ___,    ___,                   ___,   ___,  ___,  ___,  ___,  ___,
                                   ___,  ___,  ___,  ___,    ___,    ___,  ___,        ___, ___,   ___,  ___,  ___,  ___,  ___,
                                   ___,  ___,  ___,  MAC_L,  MAC_R,                                ___,  ___,  ___,  ___,  ___,
                                   ___,  ___,        ___, ___,
                                   ___,        ___,
                                   KC_LGUI,  KC_LALT,  KC_LGUI,        KC_LGUI, KC_LALT, KC_LGUI),
};

// Whether the macro 1 is currently being recorded.
static bool is_macro1_recording = false;

// The current set of active layers (as a bitmask).
// There is a global 'layer_state' variable but it is set after the call
// to layer_state_set_user().
static uint32_t current_layer_state = 0;
uint32_t layer_state_set_user(uint32_t state);

// Runs for each key down or up event.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // That key is processed by the macro_tapdance_fn. Not ignoring it here is
  // mostly a no-op except that it is recorded in the macros (and uses space).
  // We can't just return false when the key is a tap dance, because
  // process_record_user, is called before the tap dance processing (and
  // returning false would eat the tap dance).
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if(record->event.pressed) {
    switch(keycode) {
      case MC_ARROW:
        SEND_STRING("=>");
        return false;
        break;
    }
  }

  return true; // Let QMK send the enter press/release events
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Value to use to switch LEDs on. The default value of 255 is far too bright.
static const uint8_t max_led_value = 20;

// Whether the given layer (one of the constant defined at the top) is active.
#define LAYER_ON(layer) (current_layer_state & (1<<layer))

void led_1_on(void) {
  ergodox_right_led_1_on();
  ergodox_right_led_1_set(max_led_value);
}

void led_2_on(void) {
  ergodox_right_led_2_on();
  ergodox_right_led_2_set(max_led_value);
}

void led_3_on(void) {
  ergodox_right_led_3_on();
  ergodox_right_led_3_set(max_led_value);
}

void led_1_off(void) {
  ergodox_right_led_1_off();
}

void led_2_off(void) {
  ergodox_right_led_2_off();
}

void led_3_off(void) {
  ergodox_right_led_3_off();
}

uint32_t layer_state_set_user(uint32_t state) {
  current_layer_state = state;

  if (is_macro1_recording) {
    led_1_on();
    led_2_on();
    led_3_on();
    return state;
  }

  if (LAYER_ON(_LOWER)) {
    led_1_on();
  } else {
    led_1_off();
  }

  if (LAYER_ON(_RAISE)) {
    led_2_on();
  } else {
    led_2_off();
  }

  if (LAYER_ON(_ADJUST)) {
    led_1_on();
    led_2_on();
    led_3_on();
  } else {
    led_1_off();
    led_2_off();
    led_3_off();
  }

  return state;
};
