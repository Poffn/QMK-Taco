#include QMK_KEYBOARD_H
#include <quantum/split_common/split_util.h>



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_LGUI)
};

#ifdef OLED_ENABLE
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