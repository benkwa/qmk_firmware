#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


enum layers {
  L_BASE, // default layer
  L_SYMB, // symbols
  L_NPAD,  // numeric keypad
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  BK_SPC,  // TODO(kenobi): Figure out why this keycode doesn't seem to work.
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | ESC  |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Caps   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  L1  |           |  L1  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |   ~  |      | Left | Right|                                       |  Up  | Down |   [  |   ]  | RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ctrl | Alt  |       | Alt  | Ctrl |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Home |       | PgUp |       |      |
 *                                 |BkSp/ | Del  |------|       |------| Enter | Spc/ |
 *                                 | L1   |      | End  |       | PgDn |       |  L1  |
 *                                 `--------------------'       `----------------------'
 */
[L_BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,   KC_1,    KC_2,   KC_3,     KC_4,     KC_5,     KC_ESC,
        KC_CAPS,  KC_Q,    KC_W,   KC_E,     KC_R,     KC_T,     KC_NO,
        KC_TAB,   KC_A,    KC_S,   KC_D,     KC_F,     KC_G,     
        KC_LSFT,  KC_Z,    KC_X,   KC_C,     KC_V,     KC_B,     MO(L_SYMB),
        KC_LGUI,  KC_GRV,  KC_NO,  KC_LEFT,  KC_RGHT,

                                                    KC_LCTL,  KC_LALT,
                                                              KC_HOME,
                               LT(L_SYMB, KC_BSPC),  KC_DEL,  KC_END,
        
        // right hand
        TG(L_NPAD),  KC_6,   KC_7,   KC_8,     KC_9,     KC_0,     KC_MINS,
        KC_NO,       KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_BSLS,
                     KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        MO(L_SYMB),  KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                             KC_UP,  KC_DOWN,  KC_LBRC,  KC_RBRC,  KC_RGUI,

        KC_LALT,  KC_LCTL,
        KC_PGUP,
        KC_PGDN,  KC_ENT,   LT(L_SYMB, KC_SPC)
    ),

/* Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |   !  |      |      |           |      |      |   {  |   }  |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   &  |   *  |      |------|           |------|  -   |   (  |   )  |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |      |      |           |      |      |   [  |   ]  |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |  _   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_SYMB] = LAYOUT_ergodox(
                          // left hand
                          KC_NO,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  KC_NO,
                          KC_NO,  KC_NO,    KC_AT,    KC_NO,    KC_EXLM,  KC_NO,  KC_TRNS,
                          KC_NO,  KC_HASH,  KC_DLR,   KC_AMPR,  KC_ASTR,  KC_NO,   
                          KC_NO,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_NO,  KC_TRNS,
                          KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,

                                                                        KC_TRNS,  KC_TRNS,
                                                                                  KC_TRNS,
                                                               KC_TRNS,  KC_TRNS, KC_TRNS,

                          // right hand
                          KC_NO,   KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10, KC_NO,
                          KC_NO,   KC_NO,    KC_LCBR,  KC_RCBR,  KC_NO,   KC_NO,  KC_NO,
                                   KC_MINS,  KC_LPRN,  KC_RPRN,  KC_NO,   KC_NO,  KC_NO,
                          KC_TRNS, KC_NO,    KC_LBRC,  KC_RBRC,  KC_NO,   KC_NO,  KC_NO,
                                             KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_NO,

                          KC_TRNS, KC_TRNS,
                          KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS
                          ),

/* Numeric Keypad
 *
 * ,---------------------------------------------------.           ,----------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |     |     |     |     |        | 
 * |---------+------+------+------+------+------+------|           |------+------+-----+-----+-----+-----+--------|
 * |         |      |      |      |      |      |      |           |      |      |  7  |  8  |  9  |     |        |
 * |---------+------+------+------+------+------|      |           |      |------+-----+-----+-----+-----+--------|
 * |         |      |      |      |      |      |------|           |------|      |  4  |  5  |  6  |     |        |
 * |---------+------+------+------+------+------|      |           |      |------+-----+-----+-----+-----+--------|
 * |         |      |      |      |      |      |      |           |      |      |  1  |  2  |  3  |     |        |
 * `---------+------+------+------+------+-------------'           `-------------+-----+-----+-----+-----+--------'
 *   |       |      |      |      |      |                                       |     |     |     |     |      |
 *   `-----------------------------------'                                       `------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |  0   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_NPAD] = LAYOUT_ergodox(
                          // left hand
                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,

                                                                  KC_NO,  KC_NO,
                                                                          KC_NO,
                                                          KC_NO,  KC_NO,  KC_NO,

                          // right hand
                          KC_TRNS, KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,
                          KC_NO, KC_NO,  KC_7,   KC_8,   KC_9,    KC_NO,  KC_NO,
                                 KC_NO,  KC_4,   KC_5,   KC_6,    KC_NO,  KC_NO,
                          KC_NO, KC_NO,  KC_1,   KC_2,   KC_3,    KC_NO,  KC_NO,
                                 KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,
       
                          KC_NO, KC_NO,
                          KC_NO,
                          KC_NO, KC_NO, KC_0
                          ),
};

const uint16_t PROGMEM fn_actions[] = {
                                       [1] = ACTION_LAYER_TAP_TOGGLE(L_SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

// action_get_macro is deprecated.
/* const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) */
/* { */
/*   // MACRODOWN only works in this function */
/*       switch(id) { */
/*         case 0: */
/*         if (record->event.pressed) { */
/*           SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION); */
/*         } */
/*         break; */
/*         case 1: */
/*         if (record->event.pressed) { // For resetting EEPROM */
/*           eeconfig_init(); */
/*         } */
/*         break; */
/*       } */
/*     return MACRO_NONE; */
/* }; */

bool shift_pressed(void) {
  return get_mods() & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT));
}

static uint16_t bkshift_code;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  case EPRM:
    if (record->event.pressed) {
      eeconfig_init();
    }
    return false;
    break;

  case VRSN:
    if (record->event.pressed) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;
    break;

  case RGB_SLD:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
#endif
    }
    return false;
    break;

    case BK_SPC:
      if (record->event.pressed) {
        // Memoize the code that is sent, so we don't send a down event for one
        // key and an up event for another.
        bkshift_code = shift_pressed() ? KC_UNDERSCORE : KC_SPACE;
        register_code(bkshift_code);
      } else {
        unregister_code(bkshift_code);
      }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
