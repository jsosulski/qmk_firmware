#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, MT(MOD_LCTL,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_RALT, KC_DEL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_ENT, MO(2), KC_BSPC, KC_RALT),
	[1] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_EQL, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS),
	[2] = LAYOUT(KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_HOME, KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)






// static uint16_t key_timer; // timer to track the last keyboard activity
// static void refresh_rgb(void); // refreshes the activity timer and RGB, invoke whenever activity happens
// static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
// bool is_rgb_timeout = false; // store if RGB has timed out or not in a boolean


// void refresh_rgb() {
//   key_timer = timer_read(); // store time of last refresh
//   if (is_rgb_timeout) { // only do something if rgb has timed out
//     print("Activity detected, removing timeout\n");
//     is_rgb_timeout = false;
//     rgb_matrix_wakeup();
//   }
// }

// void check_rgb_timeout() {
//   if (!is_rgb_timeout && timer_elapsed(key_timer) > RGBLIGHT_TIMEOUT) {
//     rgb_matrix_suspend();
//     is_rgb_timeout = true;
//   }
// }


// /* Then, call the above functions from QMK's built in post processing functions like so */

// /* Runs at the end of each scan loop, check if RGB timeout has occured */
// void housekeeping_task_user(void) {
//   #ifdef RGBLIGHT_TIMEOUT
//   check_rgb_timeout();
//   #endif
  
//   /* rest of the function code here */
// }

// /* Runs after each key press, check if activity occurred */
// void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   #ifdef RGBLIGHT_TIMEOUT
//   if (record->event.pressed) refresh_rgb();
//   #endif

//   /* rest of the function code here */
// }


void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

void highlight_bound_keys(uint8_t layer, uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index;
            // Returns false if there is no LED at this key position
            // Otherwise, it writes the index of the LED to the given variable
            if (!rgb_matrix_map_row_column_to_led(row, col, &led_index))
                continue;  // Skip any key with no led
            
            // If the current key has a keycode assigned to it, set the LED to the given color
            // If the key is KC_NO or KC_TRANSPARENT, set the LED color to black/off
            if (keymaps[layer][row][col] > KC_TRANSPARENT) {
                rgb_matrix_set_color(led_index, red, green, blue);
            } else {
                rgb_matrix_set_color(led_index, RGB_OFF);
            }
        }
    }
}
 
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)) {
        case 1:                                    // if _MODLAYER2 is the top active layer
            highlight_bound_keys(1, 0, 30, 0);
            break;
        case 2:                                    // if _MODLAYER2 is the top active layer
            highlight_bound_keys(2, 0, 0, 30);  // highlight keys that have keycodes with the color MAGENTA
            break;
        case 3:                                    // if _MODLAYER2 is the top active layer
            highlight_bound_keys(3, 30, 30, 0);  // highlight keys that have keycodes with the color MAGENTA
            break;
    }
    return true;
}
