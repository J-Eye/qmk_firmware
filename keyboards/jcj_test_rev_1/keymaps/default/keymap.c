#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Keypad\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("random\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);

    return false;
}
#endif



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_numpad_4x4(
        KC_1,              KC_2,    KC_3,          KC_A,
        KC_4,              KC_5,    KC_6,          KC_B,
        KC_7,              KC_8,    KC_9,          KC_C,
        KC_KP_ASTERISK,   KC_0,    KC_NONUS_HASH,  KC_D,
        KC_CAPS_LOCK
    ),

    [1] = LAYOUT_numpad_4x4(
        KC_W,              KC_W,    KC_E,          KC_R,
        KC_A,              KC_S,    KC_D,          KC_F,
        KC_Z,              KC_X,    KC_C,          KC_B,
        KC_Y,   KC_U,    KC_I,  KC_P,
        _______
    )
};
