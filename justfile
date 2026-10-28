keyboard := "splitkb/aurora/corne/rev1"
keymap := "jack"

# Compile the firmware; the .uf2 is copied to the repo root
build:
    qmk compile -kb {{keyboard}} -km {{keymap}}

# Compile and flash; put one half in bootloader mode (double-tap reset), then repeat for the other
flash:
    qmk flash -kb {{keyboard}} -km {{keymap}}

# Update the local QMK firmware checkout
update:
    eval "$(qmk env | grep QMK_HOME)" && git -C "$QMK_HOME" pull --ff-only
    qmk git-submodule
