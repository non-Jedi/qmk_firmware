/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

// Combos
enum combos {
	WE,SD,DF,XC,CV,
	UI,IO,OP,HJ,JK,KL,NM,MC,
	GB,FV,HN,
	SDJK
};

// NOTE: If you're using MT,LT or anything you must 
// define it here. Note this if you change your layout!

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END}; 
const uint16_t PROGMEM mc_combo[] = {KC_M, KC_COMM, COMBO_END};

const uint16_t PROGMEM gb_combo[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM fv_combo[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM hn_combo[] = {KC_H, KC_N, COMBO_END};

const uint16_t PROGMEM sdjk_combo[] = {KC_J, KC_K, KC_S, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	// Horizontal Chords
    [WE] = COMBO(we_combo, KC_ESC),
    [SD] = COMBO(sd_combo, KC_BSPC),
    [DF] = COMBO(df_combo, KC_TAB),
    [XC] = COMBO(xc_combo, KC_MINS),
    [CV] = COMBO(cv_combo, KC_ENT),

    [UI] = COMBO(ui_combo, KC_ESC),
    [IO] = COMBO(io_combo, KC_QUOT),
    [OP] = COMBO(op_combo, KC_BSLS),
    [HJ] = COMBO(hj_combo, KC_LT),
    [JK] = COMBO(jk_combo, KC_EQL),
    [KL] = COMBO(kl_combo, KC_GT),
    [NM] = COMBO(nm_combo, KC_QUOT),
    [MC] = COMBO(mc_combo, KC_UNDS), // m,
	
	// Vertical
    [GB] = COMBO(gb_combo, KC_BTN1),
    [FV] = COMBO(fv_combo, KC_BTN2),
    [HN] = COMBO(hn_combo, KC_ENT)
};

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_gergoplex(
        MT(MOD_LALT, KC_Q), KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   MT(MOD_RALT, KC_P),
        MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,   MT(MOD_RCTL, KC_SCLN),
        MT(MOD_RSFT, KC_Z), KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

        MT(MOD_LGUI, KC_ESC), MT(MOD_LSFT, KC_TAB), LT(SYMB, KC_BSPC), // Left
        LT(NUMB, KC_SPC), MT(MOD_RSFT, KC_ENT), MT(MOD_RALT, KC_DEL)   // Right
        ),

    [SYMB] = LAYOUT_gergoplex(
        KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,   KC_GRV,  KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS,
        KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2,   KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT,
        KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1,   KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_MINS,
        KC_BTN3, KC_SCLN, KC_EQL,                      KC_EQL, KC_SCLN, KC_DEL
        ),

    [NUMB] = LAYOUT_gergoplex(
        KC_1,  KC_2,  KC_3,  KC_4,  KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
        KC_F11, KC_F12, KC_TRNS,                    KC_TRNS, KC_MPLY, KC_MNXT
        )
};
