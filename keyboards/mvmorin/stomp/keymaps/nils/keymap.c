// Copyright 2026 nilsvreman (@nilsvreman)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/*
 * Physical shape:
 *
 *   12 keys
 *   12 keys
 *   12 keys
 *    1 key, two gaps, 3 thumb keys, 3 thumb keys, two gaps, 1 key
 *
 * ---------------------------------------------------------------
 *
 * Useful QMK key patterns:
 *
 *   MO(_LAYER)     hold to activate _LAYER
 *   TG(_LAYER)     toggle _LAYER on/off
 *   _______        transparent; fall through to a lower layer
 *   XXXXXXX        disabled key
 *
 *   LCTL(kc)       Left Ctrl + kc
 *   LSFT(kc)       Left Shift + kc
 *   LALT(kc)       Left Alt + kc
 *   LGUI(kc)       Left GUI/Windows + kc
 *
 *   LCS(kc)        Left Ctrl + Left Shift + kc
 *   LSG(kc)        Left Shift + Left GUI/Windows + kc
 */

enum layers {
    _BASE,     // alphas
    _FLIP,     // flip Win/Alt
    _SYMBOLS,  // symbols and arrows
    _NUMPAD,   // numpad and command keys
    _FUNCTION, // function, f-keys, and movement
};

#define NAV_PREV LALT(KC_LEFT)
#define NAV_NEXT LALT(KC_RGHT)
#define TAB_NEXT LCTL(KC_TAB)
#define TAB_PREV LCS(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
               KC_TAB, KC_Q, KC_W,    KC_E,        KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,
         MO(_SYMBOLS), KC_A, KC_S,    KC_D,        KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
              KC_LSFT, KC_Z, KC_X,    KC_C,        KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
              KC_LCTL,             KC_LGUI, MO(_NUMPAD), KC_LALT,       KC_ENT,  KC_SPC,  KC_BSPC,                  KC_RCTL
    ),

    [_FLIP] = LAYOUT(
              _______,  _______,  _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
              _______,  _______,  _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
              _______,  _______,  _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
              _______,                     KC_LALT, _______, KC_LGUI,       _______, _______, _______,                   _______
    ),

    [_SYMBOLS] = LAYOUT(
               KC_GRV, S(KC_1), S(KC_2), S(KC_3),       S(KC_4), S(KC_5),       S(KC_6), S(KC_7), S(KC_8),    S(KC_9),    S(KC_0),    KC_EQL,
              _______, _______, _______, _______,       _______, _______,       KC_LEFT, KC_DOWN, KC_UP,      KC_RGHT,    S(KC_MINS), KC_NUHS,
              _______, _______, _______, _______,       _______, _______,       KC_LBRC, KC_RBRC, S(KC_LBRC), S(KC_RBRC), KC_NUBS,    _______,
              _______,                   _______, MO(_FUNCTION), _______,       _______, _______, KC_DEL,                             _______
    ),

    [_NUMPAD] = LAYOUT(
               KC_ESC, _______, _______, _______, _______, _______,     XXXXXXX, KC_7, KC_8,    KC_9, S(KC_EQL), KC_EQL,
        MO(_FUNCTION), KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, _______,     XXXXXXX, KC_4, KC_5,    KC_6, KC_MINS,   S(KC_NUHS),
              _______, _______, _______, _______, _______, _______,     XXXXXXX, KC_1, KC_2,    KC_3, KC_SLSH,   _______,
              _______,                   _______, _______, _______,     _______, KC_0, _______,                  _______
    ),

    [_FUNCTION] = LAYOUT(
              _______, _______,  _______,  _______,  _______,  _______,       _______, KC_F7,  KC_F8,   KC_F9, KC_F11,    KC_F12,
              _______, _______, NAV_PREV, TAB_PREV, TAB_NEXT, NAV_NEXT,       _______, KC_F4,  KC_F5,   KC_F6, KC_PIPE,   XXXXXXX,
              _______, _______,  _______,  _______,  _______,  _______,       _______, KC_F1,  KC_F2,   KC_F3, TG(_FLIP), _______,
              _______,                     _______,  _______,  _______,       _______, KC_F10, _______,                   _______
    ),
};
