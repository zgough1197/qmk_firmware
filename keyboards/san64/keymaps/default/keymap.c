#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN,
};

enum custom_keycodes {
    ILY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_64_ansi(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,
        KC_CAPS,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,     KC_ENT,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DEL,
        KC_LCTL,    KC_LWIN, KC_LALT,                         KC_SPC,                           MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN] = LAYOUT_64_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_ESC,
        _______,   RGB_TOG, RGB_RMOD, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,    QK_BOOT,
        _______,      RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, ILY,     KC_PGUP, KC_PGDN,     _______,
        _______,        RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, NK_TOGG, KC_MUTE, _______, _______, AG_TOGG, _______, KC_VOLU, _______,
        _______,    _______, _______,                         KC_MPLY,                          _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ILY:
            if (record->event.pressed) {
                SEND_STRING("I love you!");
            };
            return false;
        default:
            return true;
    };
}
