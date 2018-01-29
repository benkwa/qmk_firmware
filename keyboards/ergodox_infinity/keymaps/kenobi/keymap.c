#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "kenobi.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  BK_EQLS,
};

#define BUILD_FOR_OSX 0
#if BUILD_FOR_OSX
  // Unswap caps and tab for osx. 
  #define BK_CAPS KC_CAPS
  #define BK_TAB KC_TAB
#else
  #define BK_CAPS KC_TAB
  #define BK_TAB KC_CAPS
#endif // SWAP_CAPS_AND_TAB

// Hyper function keys
#define BK_H1   HYPR(KC_F1) 
#define BK_H2   HYPR(KC_F2)  
#define BK_H3   HYPR(KC_F3)  
#define BK_H4   HYPR(KC_F4)  
#define BK_H5   HYPR(KC_F5)  
#define BK_H6   HYPR(KC_F6)  
#define BK_H7   HYPR(KC_F7)  
#define BK_H8   HYPR(KC_F8)  
#define BK_H9   HYPR(KC_F9)  
#define BK_H10  HYPR(KC_F10)
#define BK_H11  HYPR(KC_F11)
#define BK_H12  HYPR(KC_F12)

#define BK_M1   MEH(KC_F1) 
#define BK_M2   MEH(KC_F2)  
#define BK_M3   MEH(KC_F3)  
#define BK_M4   MEH(KC_F4)  
#define BK_M5   MEH(KC_F5)  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
  - left thumb:
    - hold - activate symbol layer
    - tap - backspace.
    
  - right thumb:
    - hold - symbol layer
    - tap - space
      
 */

/* Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | ESC  |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Caps   |   Q  |   W  |   E  |   R  |   T  |      |           | Num  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |  Pad |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| HYPR |           |  FN  |------+------+------+------+------+--------|
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
        BK_TAB,   KC_Q,    KC_W,   KC_E,     KC_R,     KC_T,     KC_NO,
        BK_CAPS,  KC_A,    KC_S,   KC_D,     KC_F,     KC_G,     
        KC_LSFT,  KC_Z,    KC_X,   KC_C,     KC_V,     KC_B,     MO(L_HYPER),
        KC_LGUI,  KC_GRV,  KC_NO,  KC_LEFT,  KC_RGHT,

                                                    KC_LCTL,  KC_LALT,
                                                              KC_HOME,
                              LT(L_BLUE0, KC_BSPC),  KC_DEL,  KC_END,
        
        // right hand
        KC_NO     ,  KC_6,   KC_7,   KC_8,     KC_9,     KC_0,     KC_MINS,
        TG(L_NPAD),  KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_BSLS,
                     KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        MO(L_FKEY),  KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                             KC_UP,  KC_DOWN,  KC_LBRC,  KC_RBRC,  KC_RGUI,

        KC_LALT,  KC_LCTL,
        KC_PGUP,
        KC_PGDN,  KC_ENT,   LT(L_BLUE1, KC_SPC)
),

/* Symbol Layers
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   @  |      |   !  |      |      |           |      |      |   {  |   }  |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   &  |   *  |   =  |      |------|           |------|  -   |   (  |   )  |  <   |   >  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   -  |   +  |      |      |           |      |      |   [  |   ]  |      |      |        |
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
// SYMBOL LAYER TEMPLATE
/* LAYOUT_ergodox( */
/*         // left hand */
/*         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_TRNS, */
/*         KC_TRNS,  KC_NO,    KC_AT,    KC_NO,    KC_EXLM,  KC_NO,  KC_TRNS, */
/*         KC_TRNS,  KC_HASH,  KC_AMPR,  KC_ASTR,  BK_EQLS,  KC_NO, */
/*         KC_TRNS,  KC_PERC,  KC_CIRC,  KC_MINS,  KC_PLUS,  KC_NO,  KC_TRNS, */
/*         KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO, */
        
/*                                                       KC_TRNS,  KC_TRNS, */
/*                                                                 KC_TRNS, */
/*                                              KC_TRNS,  KC_TRNS, KC_TRNS, */
        
/*         // right hand */
/*         KC_TRNS, KC_NO,    KC_NO,    KC_NO,    KC_F9,   KC_NO,  KC_NO, */
/*         KC_TRNS, KC_NO,    KC_LCBR,  KC_RCBR,  KC_NO,   KC_NO,  KC_NO, */
/*                  KC_MINS,  KC_LPRN,  KC_RPRN,  KC_LT,   KC_GT,  KC_NO, */
/*         KC_TRNS, KC_NO,    KC_LBRC,  KC_RBRC,  KC_NO,   KC_NO,  KC_TRNS, */
/*                            KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_TRNS, */
        
/*         KC_TRNS, KC_TRNS, */
/*         KC_TRNS, */
/*         KC_TRNS, KC_TRNS, KC_TRNS */
/* ), */
[L_BLUE0] = LAYOUT_ergodox(
        // left hand
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_TRNS,
        KC_TRNS,  KC_NO,    KC_AT,    KC_NO,    KC_EXLM,  KC_NO,  KC_TRNS,
        KC_TRNS,  KC_HASH,  KC_AMPR,  KC_ASTR,  KC_EQL,   KC_NO,
        KC_TRNS,  KC_PERC,  KC_CIRC,  KC_MINS,  KC_PLUS,  KC_NO,  KC_TRNS,
        KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
        
                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                             KC_TRNS,  KC_TRNS, KC_TRNS,
        
        // right hand
        KC_TRNS, KC_NO,    KC_NO,    KC_NO,    KC_F9,   KC_NO,  KC_NO,
        KC_TRNS, KC_NO,    KC_LCBR,  KC_RCBR,  KC_NO,   KC_NO,  KC_NO,
                 KC_MINS,  KC_LPRN,  KC_RPRN,  KC_LT,   KC_GT,  KC_NO,
        KC_TRNS, KC_NO,    KC_LBRC,  KC_RBRC,  KC_NO,   KC_NO,  KC_TRNS,
                           KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_TRNS,
        
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_UNDS
),

[L_BLUE1] = LAYOUT_ergodox(
        // left hand
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_TRNS,
        KC_TRNS,  KC_NO,    KC_AT,    KC_NO,    KC_EXLM,  KC_NO,  KC_TRNS,
        KC_TRNS,  KC_HASH,  KC_AMPR,  KC_ASTR,  BK_EQLS,  KC_NO,
        KC_TRNS,  KC_PERC,  KC_CIRC,  KC_MINS,  KC_PLUS,  KC_NO,  KC_TRNS,
        KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
        
                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_MINS,  KC_TRNS,  KC_TRNS,
        
        // right hand
        KC_TRNS, KC_NO,    KC_NO,    KC_NO,    KC_F9,   KC_NO,  KC_NO,
        KC_TRNS, KC_NO,    KC_LCBR,  KC_RCBR,  KC_NO,   KC_NO,  KC_NO,
                 KC_MINS,  KC_LPRN,  KC_RPRN,  KC_NO,   KC_NO,  KC_NO,
        KC_TRNS, KC_NO,    KC_LBRC,  KC_RBRC,  KC_LT,   KC_GT,  KC_TRNS,
                           KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_TRNS,
        
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
        KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,
        KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,
        KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,
        KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        
                                             KC_TRNS,  KC_TRNS,
                                                       KC_TRNS,
                                   KC_TRNS,  KC_TRNS,  KC_TRNS,
        
        // right hand
        KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,
        KC_TRNS,  KC_NO,  KC_7,   KC_8,   KC_9,    KC_NO,  KC_NO,
                  KC_NO,  KC_4,   KC_5,   KC_6,    KC_NO,  KC_NO,
        KC_TRNS,  KC_NO,  KC_1,   KC_2,   KC_3,    KC_NO,  KC_NO,
                          KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_TRNS,
        
        KC_TRNS,  KC_TRNS,
        KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_0
),

/* Function keys
 *
 * ,-------------------------------------.           ,--------------------------------------------.
 * |     | F1 | F2 | F3 | F4 | F5 |      |           |      | F6 | F7 |  F8   | F9 | F10 |        | 
 * |-----+----+----+----+----+----+------|           |------+----+----+-------+----+-----+--------|
 * |     |    |    |    |    |    |      |           |      |    |    | VolUp |    |     |        |
 * |-----+----+----+----+----+----|      |           |      |----+----+-------+----+-----+--------|
 * |     |    |    |    |    |    |------|           |------|    | FR | Play  | FF |     |        |
 * |-----+----+----+----+----+----|      |           |      |----+----+-------+----+-----+--------|
 * |     |    |    |    |    |    |      |           |      |    |    | VolDn |    |     |        |
 * `-----+----+----+----+----+-----------'           `-----------+----+-------+----+-----+--------'
 *   |   |    |    |    |    |                                   |    |       |    |     |      |
 *   `-----------------------'                                   `------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_FKEY] = LAYOUT_ergodox(
        // left hand
        KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,

// right hand
        KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        
        KC_TRNS,  KC_TRNS,
        KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Hyper
 *
 * ,-------------------------------------.           ,--------------------------------------------.
 * |     | H1 | H2 | H3 | H4 | H5 |  H6  |           |  H7  | H8 | H9 |  H10  | H11| H12 |        | 
 * |-----+----+----+----+----+----+------|           |------+----+----+-------+----+-----+--------|
 * |     | M1 | M2 | M3 | M4 | M5 |      |           |      |    |    | VolUp |    |     |        |
 * |-----+----+----+----+----+----|      |           |      |----+----+-------+----+-----+--------|
 * |     |    |    |    |    |    |------|           |------|    | FR | Play  | FF |     |        |
 * |-----+----+----+----+----+----|      |           |      |----+----+-------+----+-----+--------|
 * |     |    |    |    |    |    |      |           |      |    |    | VolDn |    |     |        |
 * `-----+----+----+----+----+-----------'           `-----------+----+-------+----+-----+--------'
 *   |   |    |    |    |    |                                   |    |       |    |     |      |
 *   `-----------------------'                                   `------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_HYPER] = LAYOUT_ergodox(
        // left hand
        KC_NO,    BK_H1,    BK_H2,    BK_H3,    BK_H4,    BK_H5,    BK_H6,
        KC_TRNS,  BK_M1,    BK_M2,    BK_M3,    BK_M4,    BK_M5,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,

// right hand
        BK_H7,    BK_H8,    BK_H9,    BK_H10,   BK_H11,   BK_H12,   KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLU,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                  KC_TRNS,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_TRNS,  KC_TRNS,  
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        
        KC_TRNS,  KC_TRNS,
        KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* TEMPLATE
 *
 * ,---------------------------------------------------.           ,----------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |     |     |     |     |        | 
 * |---------+------+------+------+------+------+------|           |------+------+-----+-----+-----+-----+--------|
 * |         |      |      |      |      |      |      |           |      |      |     |     |     |     |        |
 * |---------+------+------+------+------+------|      |           |      |------+-----+-----+-----+-----+--------|
 * |         |      |      |      |      |      |------|           |------|      |     |     |     |     |        |
 * |---------+------+------+------+------+------|      |           |      |------+-----+-----+-----+-----+--------|
 * |         |      |      |      |      |      |      |           |      |      |     |     |     |     |        |
 * `---------+------+------+------+------+-------------'           `-------------+-----+-----+-----+-----+--------'
 *   |       |      |      |      |      |                                       |     |     |     |     |      |
 *   `-----------------------------------'                                       `------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/*[L_LAYER] = LAYOUT_ergodox(
 *        // left hand
 *        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
 *        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
 *        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
 *        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
 *        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
 *        
 *                                             KC_TRNS,  KC_TRNS,
 *                                                       KC_TRNS,
 *                                   KC_TRNS,  KC_TRNS,  KC_TRNS,
 *        
 *        // right hand
 *        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
 *        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
 *                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
 *        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
 *                            KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
 *        
 *        KC_TRNS,  KC_TRNS,
 *        KC_TRNS,
 *        KC_TRNS,  KC_TRNS,  KC_TRNS
 *        ),
 */
};

const uint16_t PROGMEM fn_actions[] = {
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  case EPRM:
    if (record->event.pressed) {
      eeconfig_init();
    }
    return false;

  case VRSN:
    if (record->event.pressed) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;

  case RGB_SLD:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
#endif
    }
    return false;

  case BK_EQLS:
    if (record->event.pressed) {
      SEND_STRING (" = ");
    }
    return false;

  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

// function row
