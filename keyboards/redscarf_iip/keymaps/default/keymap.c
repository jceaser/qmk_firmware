/* Copyright 2017 thomas cherry thomas.cherry@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
Red Scarf II+
Creator: thomas.cherry@gmail.com
Author: thomas.cherry@gmail.com
Date: 2017-05-24

Style: Each file should follow the same style conventions
    * This file: \n{, tab==4
    * All functions must be documented in javadoc style
*/

#include "redscarf_iip.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

/*  physical keys
    {K5B, K5C,   K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I, K0J, K0K, K0L, K0M, K0N, K0P, NO, NO}, \
    {K5D, K5E,   K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M, K1N, K1P, NO, NO}, \
    {K5F, K5G,   K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L, K2M, K2N, K2P, NO, NO}, \
    {K5H, K5I,   K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N, K3P, NO, NO}, \
    {K5J, K5K,   K4A, K4B, K4C,           K4J,                K4K, K4L, K4H, K4M, K4N, K4P, NO, NO}  \

*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] =
/*
Dvorak: -- NOTE -- default.c will eventually be QWERTY, I just don't type in that so for testing this is it.
* control instead of caps lock which is gone
*/
{
    {KC_F1, KC_F2, KC_ESC,  KC_1,     KC_2,      KC_3,   KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_LBRC, KC_RBRC, KC_BSPC,  KC_INT1, KC_HOME},
    {KC_F3, KC_F4, KC_TAB,  KC_QUOT,  KC_COMM,   KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_EQL,  KC_BSLS,  KC_NO,   KC_PGUP},
    {KC_F5, KC_F6, KC_LCTL, KC_A,     KC_O,      KC_E,   KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_NO,   KC_ENT,   KC_NO,   KC_PGDOWN},
    {KC_F7, KC_F8, KC_LSFT, KC_GRAVE, KC_SCOLON, KC_Q,   KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z,             KC_RSHIFT,KC_UP,   KC_END},
    {KC_F9, KC_F10,KC_LCTL, KC_LALT,  KC_LGUI,   KC_SPACE,                                KC_RGUI, KC_FN1,  KC_RALT, KC_RIGHT, KC_DOWN, KC_RIGHT}
},

[1] =
{/* Alt keys */
    {KC_F11, KC_F12, RESET,   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_DEL,   KC_INT2,  KC_WH_L},
    {KC_F13, KC_F14, _______, KC_MS_BTN1, KC_MS_U,    KC_MS_BTN2, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  KC_WH_U},
    {KC_F15, KC_F16, _______, KC_MS_L,    KC_MS_D,    KC_MS_R,    _______,    _______, KC_H,    KC_J,    KC_K,    KC_L,    _______, _______, _______, _______,  _______,  KC_WH_D},
    {KC_F17, KC_F18, KC_LSFT, _______,    KC_MS_BTN3, KC_MS_BTN4, KC_MS_BTN5, _______, _______, _______, KC_MUTE, KC_MPLY, _______, _______,          KC_RSHIFT,KC_VOLU,  KC_WH_R},
    {KC_F19, KC_F20, KC_LCTL, KC_LALT,    _______,    KC_SPACE,                                                            KC_HYPR, KC_FN1,  KC_RALT, KC_MPRV,  KC_VOLD,  KC_MNXT}
}

};

const uint16_t PROGMEM fn_actions[] =
{

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id)
    {
        case 0:
            if (record->event.pressed)
            {
                register_code(KC_RSFT);
            }
            else
            {
                unregister_code(KC_RSFT);
            }
            break;
    }
    return MACRO_NONE;
};


void matrix_init_user(void)
{

}

void matrix_scan_user(void)
{

}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    return true;
}

void led_set_user(uint8_t usb_led)
{

}
