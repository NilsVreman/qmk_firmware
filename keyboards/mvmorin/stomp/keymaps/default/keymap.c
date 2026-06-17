// Copyright 2026 mvmorin (@mvmorin)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,     // alphas
    _FLIP,     // flip Win/Alt
    _SYMBOLS,  // symbols and arrows
    _NUMPAD,   // numpad, f-keys and movement
    _FUNCTION, // function and media
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_TAB,       KC_Q, KC_W, KC_E,    KC_R, KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        MO(_SYMBOLS), KC_A, KC_S, KC_D,    KC_F, KC_G,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,      KC_Z, KC_X, KC_C,    KC_V, KC_B,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,                  KC_LALT, MO(_NUMPAD), KC_LGUI, KC_DEL,  KC_SPC,  KC_BSPC,          KC_ENT
    ),

    [_FLIP] = LAYOUT(
        _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
        _______,                   KC_LGUI, _______, KC_LALT,    _______, _______, _______,                   _______
    ),

    [_SYMBOLS] = LAYOUT(
        _______, S(KC_1),       S(KC_2),    S(KC_3), S(KC_5),       S(KC_6),   S(KC_7),    S(KC_8),    S(KC_9),    RALT(KC_MINS), S(KC_MINS), S(KC_RBRC),
        _______, RALT(KC_NUBS), RALT(KC_2), XXXXXXX, RALT(KC_4),    XXXXXXX,   KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,       S(KC_EQL),  KC_NUHS,
        _______, XXXXXXX,       XXXXXXX,    KC_F11,  KC_F12,        KC_RBRC,   RALT(KC_8), RALT(KC_7), RALT(KC_0), RALT(KC_9),    KC_EQL,     _______,
        _______,                            _______, MO(_FUNCTION), _______,  _______,    _______,    _______,                               _______
    ),

    [_NUMPAD] = LAYOUT(
        KC_ESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    S(KC_0),    KC_7, KC_8, KC_9, KC_MINS, RALT(KC_RBRC),
        MO(_FUNCTION), KC_LALT, KC_HOME, KC_PGUP, KC_PGDN, KC_END,   KC_NUBS,    KC_4, KC_5, KC_6, S(KC_7), S(KC_NUHS),
        _______,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   S(KC_NUBS), KC_1, KC_2, KC_3, KC_SLSH, _______,
        _______,                         _______, _______, _______,  _______,    KC_0,  _______,            _______
    ),

    [_FUNCTION] = LAYOUT(
        _______, XXXXXXX, XXXXXXX,       KC_VOLD,            KC_VOLU,      KC_MUTE,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
        _______, XXXXXXX, LALT(KC_LEFT), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LALT(KC_RGHT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
        _______, XXXXXXX, XXXXXXX,       KC_MPRV,            KC_MNXT,      KC_MPLY,       KC_PSCR, KC_INS,  KC_APP,  XXXXXXX, TG(_FLIP), _______,
        _______,                         _______,            _______,      _______,       _______, _______, _______,                     _______
    ),
};
