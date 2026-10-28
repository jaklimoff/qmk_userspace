// Copyright 2024-2026 Jack Klimov (@jaklimoff)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Home row mods
#define TAPPING_TERM 280
#define PERMISSIVE_HOLD

// Lighting: layer-colored glow with a ripple on every keypress
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_LAYER_SPLASH
#define RGB_MATRIX_DEFAULT_SPD 160

// Additional effects, selectable from the Adjust layer
#define ENABLE_RGB_MATRIX_SOLID_COLOR
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
