#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion
#define SUPR 3 // WM commands/macros

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
};

// thumb keys.
#define OSL_SFT   OSM(MOD_LSFT)
#define SYM_ENT   LT(SYMB, KC_ENT)
#define OSL_SYM   OSL(SYMB)
#define NUM_SPC   LT(NUMB, KC_SPC)
#define OSL_SUP   OSL(SUPR)

// home row mods.
#define CT_X    LCTL_T(KC_X)
#define CT_SCLN RCTL_T(KC_SCLN)
#define AL_C    LALT_T(KC_C)
#define GU_Z    LGUI_T(KC_Z)
#define GU_SLSH LGUI_T(KC_SLSH)

// Combos
enum combos {
  WE_ESC,
  IO_BSP,
  KL_TAB,
  JL_DAS,
  UO_QUT,
};

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM uo_combo[] = {KC_U, KC_O, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [WE_ESC] = COMBO(we_combo, KC_ESC),
  [IO_BSP] = COMBO(io_combo, KC_BSPC),
  [KL_TAB] = COMBO(kl_combo, KC_TAB),
  [JL_DAS] = COMBO(jl_combo, KC_MINS),
  [UO_QUT] = COMBO(uo_combo, KC_QUOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
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
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
        KC_NO, KC_Q,  KC_W,  KC_E,  KC_R,   KC_T,   KC_NO,
        KC_NO, KC_A,  KC_S,  KC_D,  KC_F,   KC_G,
        KC_NO, GU_Z,  CT_X,  KC_C,  KC_V,   KC_B,   KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, C(KC_A),
                                                      KC_NO,  KC_NO,
                                                              KC_NO,
                                              OSL_SFT,SYM_ENT,KC_NO,
        // right hand
             KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,   KC_NO,
             KC_NO, KC_Y,  KC_U,  KC_I,   KC_O,   KC_P,    KC_NO,
                    KC_H,  KC_J,  KC_K,   KC_L,   CT_SCLN, KC_NO,
             KC_NO, KC_N,  KC_M,  KC_COMM,KC_DOT, GU_SLSH, KC_NO,
                           OSL_SUP, KC_NO,KC_NO,  KC_NO,   KC_NO,
             KC_NO, KC_NO,
             KC_NO,
             KC_NO, OSL_SYM, NUM_SPC
    ),

// SYMBOLS
[SYMB] = LAYOUT_ergodox(
        // left hand
        KC_NO, KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_EXLM,  KC_AT,   KC_LCBR,  KC_RCBR, KC_QUOT, KC_NO,
        KC_NO, KC_HASH,  KC_DLR,  KC_LPRN,  KC_RPRN, KC_GRV,
        KC_NO, KC_PERC,  KC_CIRC, KC_LBRC,  KC_RBRC, KC_TILD, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                                                      KC_NO,  KC_NO,
                                                              KC_NO,
                                              KC_TRNS,KC_TRNS,KC_NO,
        // right hand
             KC_NO, KC_NO,      KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,
             KC_NO, S(KC_QUOT), S(KC_MINS), KC_PIPE, KC_BSLS, KC_NO,   KC_NO,
                    KC_PLUS,    KC_MINS,    KC_SLSH, KC_ASTR, KC_PERC, KC_NO,
             KC_NO, KC_AMPR,    KC_EQL,     KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
                           KC_TRNS, KC_NO,KC_NO,  KC_NO,   KC_NO,
             KC_NO, KC_NO,
             KC_NO,
             KC_NO, KC_TRNS, KC_TRNS
),
// NUMBERS
[NUMB] = LAYOUT_ergodox(
        // left hand
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,
        KC_NO, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,   KC_NO,
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                                                      KC_NO,  KC_NO,
                                                              KC_NO,
                                              KC_TRNS,KC_TRNS,KC_NO,
        // right hand
             KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
             KC_NO, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU, KC_NO,
             KC_NO, KC_TRNS, KC_TRNS, KC_MPLY, KC_MNXT, KC_VOLD, KC_NO,
                                 KC_TRNS, KC_NO,KC_NO,  KC_NO,   KC_NO,
             KC_NO, KC_NO,
             KC_NO,
             KC_NO, KC_TRNS, KC_TRNS
),
// Control
[SUPR] = LAYOUT_ergodox(
        // left hand
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
                                                      KC_NO,  KC_NO,
                                                              KC_NO,
                                              KC_TRNS,KC_TRNS,KC_NO,
        // right hand
             KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
             KC_NO, G(KC_TAB), G(KC_1), G(KC_3), G(KC_5), G(KC_7), KC_NO,
                    KC_TRNS,   G(KC_2), G(KC_4), G(KC_6), G(KC_8), KC_NO,
             KC_NO, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                                   KC_TRNS, KC_NO,KC_NO,  KC_NO,   KC_NO,
             KC_NO, KC_NO,
             KC_NO,
             KC_NO, KC_TRNS, KC_TRNS
),
};
