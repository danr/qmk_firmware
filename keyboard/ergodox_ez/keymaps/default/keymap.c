#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "led.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define QWER 2 // qwerty keys, for other to test and when a dvorak layout is on

#define UNUSED KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,          KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_CAPS,
        LT(SYMB,KC_TAB), KC_QUOT, KC_COMM,KC_DOT, KC_P,   KC_Y,   TG(QWER),
        CTL_T(KC_ESC),   KC_A,    KC_O,   KC_E,   KC_U,   KC_I,
        KC_LSFT,         KC_SCLN, KC_Q,   KC_J,   KC_K,   KC_X,   TG(SYMB),
        KC_BSLS,         KC_LBRC, KC_RBRC,KC_PIPE, KC_LGUI,
                                                     KC_LALT, UNUSED,
                                                               KC_HOME,
                                               KC_BSPC,KC_DELT,KC_END,
        // right hand
             KC_CAPS,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   UNUSED,
             TG(QWER),    KC_F,   KC_G,   KC_C,   KC_R,   KC_L,   LT(SYMB,KC_SLSH),
                          KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   CTL_T(KC_MINS),
             TG(SYMB),    KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,   KC_RSFT,
                                  KC_LGUI,KC_EQL, UNUSED, UNUSED, UNUSED,
             KC_APP /* for åäö */, KC_RALT,
             KC_PGUP,
             KC_PGDN, KC_ENT, KC_SPC
    ),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_AMPR, KC_BSLS,KC_SLSH, KC_EQL,  KC_MINS, KC_TRNS,
                KC_WH_U, KC_LEFT,KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS,
       KC_TRNS, KC_WH_D, KC_MS_L,KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
                         KC_TRNS,KC_BTN1, KC_BTN2, KC_BTN3, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

[QWER] = KEYMAP(
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_TRNS,
        KC_TRNS,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_TRNS,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_TRNS,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_TRNS,        KC_QUOT,      KC_TRNS,KC_TRNS,KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
             KC_TRNS,     KC_6,KC_7,       KC_8,   KC_9,   KC_0,            KC_MINS,
             KC_TRNS,     KC_Y,KC_U,       KC_I,   KC_O,   KC_P,            KC_BSLS,
                          KC_H,KC_J,       KC_K,   KC_L,   KC_SCLN,         KC_QUOT,
             KC_TRNS,     KC_N,KC_M,       KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT,
                               KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS,         KC_FN1,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
    )


};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {
    return NULL;
};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            // SYMB
            ergodox_right_led_2_on();
            break;
        case 2:
            // QWER
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

    // CAPS
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
      ergodox_right_led_1_on();
    }
    return NULL;

};
