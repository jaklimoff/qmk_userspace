// Copyright 2024-2026 Jack Klimov (@jaklimoff)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _GAMING,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCTION,
};

enum custom_keycodes {
    DBL_OPT = SAFE_RANGE, // double-tap right Option
    DBL_CMD,              // double-tap right Command
};

// Layer keys
#define FUNCTN MO(_FUNCTION)
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define QWERTY PDF(_QWERTY)
#define GAMING PDF(_GAMING)

// Home row mods: Ctrl, Option, Command, Shift
#define HOME_A    LCTL_T(KC_A)
#define HOME_S    LALT_T(KC_S)
#define HOME_D    LGUI_T(KC_D)
#define HOME_F    LSFT_T(KC_F)
#define HOME_J    RSFT_T(KC_J)
#define HOME_K    RGUI_T(KC_K)
#define HOME_L    LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Letters with home row mods
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_BSPC,
        KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,         KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_BSLS,
                                   FUNCTN,  LOWER,   KC_ENT,       KC_SPC,  RAISE,   KC_BSPC
    ),

    // QWERTY without home row mods, plain Shift/Ctrl for games
    [_GAMING] = LAYOUT_split_3x6_3(
        KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    HOME_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_BSLS,
                                   KC_LCTL, KC_SPC,  KC_ENT,       KC_SPC,  RAISE,   KC_BSPC
    ),

    // Numpad
    [_LOWER] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, KC_A,    _______,      KC_PAST, KC_7,    KC_8,    KC_9,    KC_PPLS,   _______,
        _______, _______, _______, _______, _______, _______,      KC_PEQL, KC_4,    KC_5,    KC_6,    KC_0,      KC_PDOT,
        _______, _______, _______, _______, _______, _______,      KC_PSLS, KC_1,    KC_2,    KC_3,    KC_MINS,   _______,
                                   _______, _______, _______,      KC_BSPC, ADJUST,  KC_DEL
    ),

    // Brackets and arrows
    [_RAISE] = LAYOUT_split_3x6_3(
        KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, _______,      KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______,   _______,
        _______, _______, _______, _______, _______, _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,   _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,   _______,
                                   _______, ADJUST,  KC_ESC,       _______, _______, _______
    ),

    // Lighting, media, default layer switch
    [_ADJUST] = LAYOUT_split_3x6_3(
        RM_TOGG, RM_NEXT, RM_PREV, XXXXXXX, RM_VALD, RM_VALU,      KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, QWERTY,    GAMING,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RM_SPDD, RM_SPDU,      KC_RSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
                                   _______, _______, _______,      _______, _______, _______
    ),

    // F-keys, double-tap Option/Command
    [_FUNCTION] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, KC_A,    _______,      KC_PAST, KC_F7,   KC_F8,   KC_F9,   KC_PPLS,   _______,
        _______, _______, DBL_OPT, DBL_CMD, _______, _______,      KC_PEQL, KC_F4,   KC_F5,   KC_F6,   KC_0,      KC_PDOT,
        _______, _______, _______, _______, _______, _______,      KC_PSLS, KC_F1,   KC_F2,   KC_F3,   KC_MINS,   _______,
                                   _______, _______, _______,      KC_BSPC, ADJUST,  KC_DEL
    ),
};
// clang-format on

/* Double-tap modifiers
 *
 * Some macOS apps trigger on a double-tap of a modifier. Besides DBL_OPT / DBL_CMD,
 * holding both matching home row mods sends the double-tap:
 *   K + D (both Command) -> right Command x2
 *   L + S (both Option)  -> right Option x2
 * It fires only once both keys have resolved as holds (TAPPING_TERM),
 * so a quick Cmd+D or Option+S still works as usual.
 */

static void double_tap(uint16_t keycode) {
    tap_code_delay(keycode, 20);
    wait_ms(40);
    tap_code_delay(keycode, 20);
}

enum { RIGHT_HAND, LEFT_HAND };

static bool gui_held[2];
static bool alt_held[2];

static bool process_mod_pair(bool held[2], uint8_t hand, keyrecord_t *record, uint8_t mods, uint16_t out) {
    if (!record->event.pressed) {
        held[hand] = false;
        return true;
    }
    if (record->tap.count) return true; // tapped, not held

    held[hand] = true;
    if (!held[!hand]) return true;

    unregister_mods(mods); // release the first key's modifier
    wait_ms(30);
    double_tap(out);
    return false; // and skip this key's modifier
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t gui = MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI);
    const uint8_t alt = MOD_BIT(KC_LALT);

    switch (keycode) {
        case HOME_K:
            return process_mod_pair(gui_held, RIGHT_HAND, record, gui, KC_RGUI);
        case HOME_D:
            return process_mod_pair(gui_held, LEFT_HAND, record, gui, KC_RGUI);
        case HOME_L:
            return process_mod_pair(alt_held, RIGHT_HAND, record, alt, KC_RALT);
        case HOME_S:
            return process_mod_pair(alt_held, LEFT_HAND, record, alt, KC_RALT);
        case DBL_OPT:
            if (record->event.pressed) double_tap(KC_RALT);
            return false;
        case DBL_CMD:
            if (record->event.pressed) double_tap(KC_RGUI);
            return false;
    }
    return true;
}

/* Lighting
 *
 * The active RGB Matrix effect takes its color from the current layer.
 * The default effect is LAYER_SPLASH (see rgb_matrix_user.inc).
 */

static const hsv_t layer_colors[] = {
    [_QWERTY]   = {HSV_BLUE},
    [_GAMING]   = {HSV_GREEN},
    [_LOWER]    = {HSV_YELLOW},
    [_RAISE]    = {HSV_PURPLE},
    [_ADJUST]   = {HSV_CYAN},
    [_FUNCTION] = {HSV_GREEN},
};

// Takes hue and saturation from the layer and keeps the user's brightness
static void set_layer_color(layer_state_t layers) {
    hsv_t color = layer_colors[get_highest_layer(layers)];
    rgb_matrix_sethsv_noeeprom(color.h, color.s, rgb_matrix_get_val());
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    set_layer_color(layer_state | default_layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_layer_color(state | default_layer_state);
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    set_layer_color(layer_state | state);
    return state;
}
