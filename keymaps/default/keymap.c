#include QMK_KEYBOARD_H



enum layer_names { _BASE, _LOWERED, _RAISED, _FLAYER };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_ESC,//QK_BOOTLOADER,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ENT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_LGUI, MO(_LOWERED),  KC_SPC,             LT(_FLAYER, KC_BSPC), MO(_RAISED), KC_RIGHT_ALT
                                            //`--------------------------'  `--------------------------'
        ),
    [_LOWERED] = LAYOUT(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,     KC_9,   KC_0, _______,//QK_BOOTLOADER,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, KC_LBRC, KC_RBRC,                      KC_PAST,    KC_4,    KC_5,    KC_6, KC_PPLS, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______,                      KC_PSLS,    KC_1,    KC_2,    KC_3, KC_PMNS, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      _______, _______,  _______,                      _______,    KC_0, _______
                                            //`--------------------------'  `--------------------------'
        ),
    [_RAISED] = LAYOUT(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,//QK_BOOTLOADER,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       _______, _______, _______,                      _______, _______, _______
                                            //`--------------------------'  `--------------------------'
        ),
    [_FLAYER] = LAYOUT(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TILD,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,                      KC_HOME,   KC_UP,  KC_END, KC_PGUP, _______, QK_BOOT,//QK_BOOTLOADER,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,                      KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,                      _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______, _______,                      _______, _______, _______
                                            //`--------------------------'  `--------------------------'
        )
};

#ifdef OLED_ENABLE
#include <quantum/split_common/split_util.h>
bool oled_task_user(void) {
    if(is_keyboard_master()){
        oled_write_P(PSTR("MASTER!"), false);
    }
    else{
        oled_write_P(PSTR("SLAVE!"), false);
    }
    return false;
}
#endif