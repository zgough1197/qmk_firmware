#include QMK_KEYBOARD_H
#include "version.h"

enum layer_names {
    _WIN_BASE,
    _MAC_BASE,
    _FN,
    _AK,
    _MK,
    _NP,
};

enum custom_keycodes {
    LOCK = SAFE_RANGE,
    ILY,
    SWAP_OS,
    FOR_OS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN_BASE] = LAYOUT_ergodox_pretty(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TO(_WIN_BASE),    TO(_FN), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,          KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LWIN, KC_LALT, TT(_FN), TO(_WIN_BASE),                                        KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, SWAP_OS,
                                                     KC_ESC,  LOCK,             KC_MEH,  KC_APP,
                                                              KC_HOME,          KC_PGUP,
                                            KC_BSPC, KC_DEL,  KC_END,           KC_PGDN, KC_ENT,  KC_SPC
    ),
    [_MAC_BASE] = LAYOUT_ergodox_pretty(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TO(_MAC_BASE),    TO(_FN), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,          KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LOPT, KC_LCMD, MO(_FN), TO(_MAC_BASE),                                        KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, SWAP_OS,
                                                     KC_ESC,  LOCK,             C(KC_UP), C(KC_DOWN),
                                                              KC_HOME,          KC_PGUP,
                                            KC_BSPC, KC_DEL,  KC_END,           KC_PGDN, KC_ENT,  KC_SPC
    ),
    [_FN] = LAYOUT_ergodox_pretty(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, ILY,     _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, FOR_OS,  _______,
        _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, _______,
                                                     QK_BOOT, KC_PSCR,          KC_SCRL, KC_PAUS,
                                                              _______,          _______,
                                            _______, _______, KC_INS,           _______, _______, SWAP_OS
    ),
    [_AK] = LAYOUT_ergodox_pretty(
        _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,           KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______,
        _______, _______, _______, _______, _______, _______, _______,          TO(_MK), _______, _______, KC_RGHT, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                              _______, _______, _______, _______, _______,
                                                     _______, _______,          _______, _______,
                                                              _______,          _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [_MK] = LAYOUT_ergodox_pretty(
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, TO(_AK),          TO(_NP), _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_MUTE, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                              KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT, _______,
                                                     _______, _______,          _______, _______,
                                                              _______,          _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [_NP] = LAYOUT_ergodox_pretty(
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, _______,
        _______, _______, _______, _______, _______, _______, TO(_MK),          XXXXXXX, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______,                            _______, KC_KP_4, KC_KP_5, KC_KP_6, _______, KC_PENT,
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
        _______, _______, _______, _______, _______,                                              KC_KP_0, KC_KP_0, KC_PDOT, _______, _______,
                                                     _______, _______,          _______, _______,
                                                              _______,          _______,
                                            _______, _______, _______,          _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SWAP_OS:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_MAC_BASE)) {
                    // MAC is currently on
                    layer_clear();
                    layer_on(_WIN_BASE);
                    set_single_persistent_default_layer(_WIN_BASE);
                } else {
                    // WINDOWS is currently on
                    layer_clear();
                    layer_on(_MAC_BASE);
                    set_single_persistent_default_layer(_MAC_BASE);
                };
            };
            return false;
        case FOR_OS:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_MAC_BASE)) {
                    // MAC
                    SEND_STRING("macos");
                } else {
                    // WINDOWS
                    SEND_STRING("windows");
                };
            };
            return false;
        case LOCK:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_MAC_BASE)) {
                    // MAC
                    register_code16(C(G(KC_Q)));
                } else {
                    // WINDOWS
                    register_code16(G(KC_L));
                };
            } else {
                unregister_code16(C(G(KC_Q)));
                unregister_code16(G(KC_L));
            };
            return false;
        case ILY:
            if (record->event.pressed) {
                SEND_STRING("I love you!\n");
            };
            return false;
        default:
            return true;
    };
}
