# Zilpzalp QMK Firmware

## Introduction

This is a QMK keyboard definition for the zilpzalp keyboard. I wrote this
because the latest version of QMK does not support the label-based layout that
the
[existing firmware](https://github.com/kilipan/qmk-config-zilpzalp)
uses. This keyboard definition uses a matrix-based layout that has been mapped
onto the physical layout of the keyboard.

One caveat: I have altered the matrix map so that the layout, as defined in
`keyboard.json`, places the two outer "pinky" keys onto the second row of the
keymap instead of the third, which makes more sense to my fingers. This means
that keymaps are defined with a row of eight, ten, six and four keycodes.

The following example shows how the keymaps work, with the keycodes in
alphabetical order to indicate how the layout flows:

```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
              KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H,
        KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R,
              KC_S, KC_T, KC_U,             KC_V, KC_W, KC_X,
                          KC_Y, KC_Z, KC_1, KC_2
    )
};
```

## QMK Blurb

* Keyboard Maintainer: [hbmorrison](https://github.com/hbmorrison)
* Hardware Supported: Zilpzalp keyboard, Seeed Studio Xiao RP2040 Controller
* Hardware Availability: [zilpzalp keyboard](https://github.com/kilipan/zilpzalp)

Make example for this keyboard (after setting up your build environment):

    make zilpzalp:default

Flashing example for this keyboard:

    make zilpzalp:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
