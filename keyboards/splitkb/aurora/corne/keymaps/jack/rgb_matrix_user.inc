// Copyright 2026 Jack Klimov (@jaklimoff)
// SPDX-License-Identifier: GPL-2.0-or-later

/* LAYER_SPLASH
 *
 * Keys glow dimly in the current color (set per layer in keymap.c).
 * Every keypress sends a bright, slightly whiter ring outward that fades as it travels.
 * Effect speed controls how fast the rings move.
 */

RGB_MATRIX_EFFECT(LAYER_SPLASH)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// Idle brightness, out of 255, relative to the brightness setting
#    define LAYER_SPLASH_IDLE 90

static bool LAYER_SPLASH(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        // Sum the rings of recent keypresses at this LED
        uint8_t wave = 0;
        for (uint8_t j = 0; j < g_last_hit_tracker.count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));

            // 0 on the ring, growing behind it; wraps to a large value ahead of it
            uint16_t effect = tick - dist;
            if (effect > 255) effect = 255;
            wave = qadd8(wave, 255 - effect);
        }

        hsv_t hsv = rgb_matrix_config.hsv;
        hsv.v     = scale8(qadd8(LAYER_SPLASH_IDLE, scale8(wave, 255 - LAYER_SPLASH_IDLE)), rgb_matrix_config.hsv.v);
        hsv.s     = qsub8(hsv.s, wave / 2);

        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
