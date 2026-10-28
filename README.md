# Aurora Corne keymap

[![Build QMK firmware](https://github.com/jaklimoff/qmk_userspace/actions/workflows/build_binaries.yaml/badge.svg)](https://github.com/jaklimoff/qmk_userspace/actions/workflows/build_binaries.yaml)

My [QMK](https://qmk.fm) keymap for the [splitkb Aurora Corne](https://splitkb.com/products/aurora-corne-pcb-kit),
kept as a QMK [external userspace](https://docs.qmk.fm/newbs_external_userspace): this repo holds only the keymap,
QMK itself is a separate, unmodified checkout.

## Hardware

- splitkb Aurora Corne rev1, 3x6 + 3 thumb keys per half
- Two [Liatris](https://splitkb.com/products/liatris) (RP2040) controllers, left half is master
- Per-key and underglow RGB (54 LEDs)
- Built for macOS

## Features

- **Home row mods**: Ctrl, Option, Command, Shift on `A S D F` and `J K L ;` (280 ms tapping term, permissive hold)
- **Six layers**: QWERTY, Gaming, numpad, symbols/arrows, F-keys and an Adjust layer
- **Layer-colored lighting**: the whole board takes the active layer's color
- **Ripple effect**: a custom RGB Matrix effect (`LAYER_SPLASH`) sends a ring of light outward from every keypress
- **Double-tap modifiers** for macOS app hotkeys: hold `K`+`D` to send right Command twice, `L`+`S` for right Option.
  A quick Cmd+D or Option+S still works as usual.

## Layout

Home row keys show their hold action after the dot (`A·Ctl` is `A` on tap, Ctrl on hold).
Blank keys fall through to the layer below.

### QWERTY

Default layer. Lights: blue.

```
┌──────┬──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┬──────┐
│  `   │  Q   │  W   │  E   │  R   │  T   │   │  Y   │  U   │  I   │  O   │  P   │ Bspc │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│ Tab  │A·Ctl │S·Opt │D·Cmd │F·Sft │  G   │   │  H   │J·Sft │K·Cmd │L·Opt │;·Ctl │  '   │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │  Z   │  X   │  C   │  V   │  B   │   │  N   │  M   │  ,   │  .   │  /   │  \   │
└──────┴──────┴──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┴──────┴──────┘
                     │  Fn  │Lower │Enter │   │Space │Raise │ Bspc │
                     └──────┴──────┴──────┘   └──────┴──────┴──────┘
```

### Lower

Hold `Lower`. Numpad on the right hand. Lights: yellow.

```
┌──────┬──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┬──────┐
│      │      │      │      │  A   │      │   │  *   │  7   │  8   │  9   │  +   │      │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │   │  =   │  4   │  5   │  6   │  0   │  .   │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │   │  /   │  1   │  2   │  3   │  -   │      │
└──────┴──────┴──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┴──────┴──────┘
                     │      │      │      │   │ Bspc │Adjust│ Del  │
                     └──────┴──────┴──────┘   └──────┴──────┴──────┘
```

### Raise

Hold `Raise`. Brackets and arrows. Lights: purple.

```
┌──────┬──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┬──────┐
│  (   │  )   │  [   │  ]   │      │      │   │  (   │  )   │  [   │  ]   │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │   │ Left │ Down │  Up  │Right │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │   │      │      │      │      │      │      │
└──────┴──────┴──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┴──────┴──────┘
                     │      │Adjust│ Esc  │   │      │      │      │
                     └──────┴──────┴──────┘   └──────┴──────┴──────┘
```

### Function

Hold `Fn`. F-keys on the right, double-tap Option / Command on the left. Lights: green.

```
┌──────┬──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┬──────┐
│      │      │      │      │  A   │      │   │  *   │  F7  │  F8  │  F9  │  +   │      │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │2×Opt │2×Cmd │      │      │   │  =   │  F4  │  F5  │  F6  │  0   │  .   │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │   │  /   │  F1  │  F2  │  F3  │  -   │      │
└──────┴──────┴──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┴──────┴──────┘
                     │      │      │      │   │ Bspc │Adjust│ Del  │
                     └──────┴──────┴──────┘   └──────┴──────┴──────┘
```

### Adjust

Hold `Lower` or `Fn` and press the right middle thumb, or hold `Raise` and press the left middle thumb. Lights: cyan.

`RGB` toggles lighting, `Next` / `Prev` cycle effects, `Lit` is brightness, `Spd` is effect speed.
`QWERTY` / `Gaming` set the default layer (remembered across power cycles).

```
┌──────┬──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┬──────┐
│ RGB  │ Next │ Prev │      │ Lit- │ Lit+ │   │ Bri- │ Bri+ │ Vol- │ Vol+ │QWERTY│Gaming│
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │ Spd- │ Spd+ │   │Shift │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │   │      │      │      │      │      │      │
└──────┴──────┴──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┴──────┴──────┘
                     │      │      │      │   │      │      │      │
                     └──────┴──────┴──────┘   └──────┴──────┴──────┘
```

### Gaming

Optional default layer without home row mods. Lights: green.

```
┌──────┬──────┬──────┬──────┬──────┬──────┐   ┌──────┬──────┬──────┬──────┬──────┬──────┐
│  `   │  Q   │  W   │  E   │  R   │  T   │   │  Y   │  U   │  I   │  O   │  P   │ Bspc │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│ Tab  │  A   │  S   │  D   │  F   │  G   │   │  H   │  J   │  K   │  L   │;·Ctl │  '   │
├──────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┼──────┼──────┤
│Shift │  Z   │  X   │  C   │  V   │  B   │   │  N   │  M   │  ,   │  .   │  /   │  \   │
└──────┴──────┴──────┼──────┼──────┼──────┤   ├──────┼──────┼──────┼──────┴──────┴──────┘
                     │ Ctrl │Space │Enter │   │Space │Raise │ Bspc │
                     └──────┴──────┴──────┘   └──────┴──────┴──────┘
```

## Lighting effects

`Next` on the Adjust layer cycles through:

| Effect | Description |
|---|---|
| Layer splash (default) | Dim layer color, ripple from every keypress |
| Solid color | Static layer color |
| Solid reactive simple | Pressed key lights up and fades |
| Multicross / Multinexus | Pulse along the pressed key's row and column |
| Multisplash | Rainbow ripple |
| Typing heatmap | Frequently used keys glow warmer |

## Building

Prebuilt firmware is published on the [Releases](https://github.com/jaklimoff/qmk_userspace/releases) page
by GitHub Actions on every push.

To build locally on macOS:

```sh
brew install qmk/qmk/qmk just
qmk setup                                  # clones QMK into ~/qmk_firmware
git clone git@github.com:jaklimoff/qmk_userspace.git
cd qmk_userspace
qmk config user.overlay_dir="$(pwd)"
```

Then:

```sh
just build    # compile; the .uf2 is copied to the repo root
just flash    # flash; double-tap reset on one half, then repeat for the other
just update   # update the local QMK checkout
```

Without `just`: `qmk compile -kb splitkb/aurora/corne/rev1 -km jack`.

## Repository layout

```
.
├── keyboards/splitkb/aurora/corne/keymaps/jack/
│   ├── keymap.c             # layers, double-tap modifiers, layer colors
│   ├── rgb_matrix_user.inc  # LAYER_SPLASH effect
│   ├── config.h             # tapping and lighting settings
│   └── rules.mk             # Liatris converter, RGB Matrix
├── qmk.json                 # userspace build targets
└── justfile                 # build / flash / update
```

## License

[GPL-2.0-or-later](LICENSE), same as QMK.
