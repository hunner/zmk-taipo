# zmk-taipo

Reusable Taipo layout module for ZMK.

## Dependencies

- [`zmk-helpers`](https://github.com/urob/zmk-helpers) for key-label conventions.
- Optional: [`zmk-leader-key`](https://github.com/urob/zmk-leader-key) if you include `features/leader.dtsi`.

## Prerequisites

This module assumes your keyboard is using the zmk-helpers key labeling conventions, as found in https://github.com/urob/zmk-helpers/tree/main/include/zmk-helpers/key-labels . This means your keyboard has key positions labeled as `LT4` for the left top pinky, `RM1` for the right middle index, etc.

This module will map combos using `LT4..LT1`, `LM4..LM1`, `RT1..RT4`, and `RM1..RM4` for the Taipo finger positions. This can be overridden by defining the `TAIPO_POS_*` macros as described in the "Positions Contract" section below.

## Usage

1. Add this repository as a west project (commonly at `modules/zmk/taipo`)
2. In your keymap, include key-labels
3. Define a layer called `TAIPO` and assign it a layer number
4. Include the core Taipo combos DTSI file
5. Include optional feature files as needed

Example:

```c
#include <zmk-helpers/helper.h>
#include <zmk-helpers/key-labels/34.h>

#define TAIPO 6
#define TAIPO_INNER 7 // Used by virtual thumbs
#define TAIPO_OUTER 8 // Used by virtual thumbs
#define TAIPO_THUMB_ORDER_OIIO 1

#include <zmk-taipo/taipo.dtsi>
#include <zmk-taipo/features/virtual_thumbs.dtsi>
```

## Positions Contract

`<zmk-taipo/taipo.dtsi>` requires position macros to be defined to understand which keysyms correspond to which Taipo finger positions. You can use the default positions as defined in the zmk-helpers key labels, or you can define your own positions by defining the following macros before including `taipo.dtsi`:

- `TAIPO_POS_L{R,S,N,I,A,O,T,E}`
- `TAIPO_POS_R{R,S,N,I,A,O,T,E}`
- `TAIPO_POS_H{1,2,3,4}`

These correspond to the `RSNIAOTE` Taipo keys for the left and right hands, and the four thumb keys. The defaults when using a standard zmk-helpers key label adapter map to qwerty's `QWERASDF` positions on the left hand and `POIU;LKJ` on the right hand. The four thumb keys map to zmk-helpers `LH1`, `LH0`, `RH0`, and `RH1` by default, which vary based on which keyboard you are using.

If you want to define your own positions you can define the `TAIPO_POS_*` macros to the key positions you want. For example, if your right hand pinky is at position `LM4`, you can define:
```c
#define TAIPO_POS_LR LM4
// ...
```

or if you want to use raw key positions instead of key labels, you can define:
```c
#define TAIPO_POS_LR 25
// ...
```

## Config Flags

- `TAIPO_COMBO_TERM_FAST` (default `100`) is the combo term for the Taipo combos. This is a shorter combo term than the default ZMK combo term, which allows for faster combos. You can adjust this value to suit your typing speed and accuracy.
- `TAIPO_PASTE_BINDING` (default `&kp LS(INSERT)`) is the binding for the paste combo. You can change this to any binding you want for pasting, such as `LC(V)` for Ctrl+V. This is bound to outer `OTE`, since the original AltGr key is not as useful.

## Optional Features

### Thumb inner/outer order

By default, the inner thumb keys are the ones closer to the center of the keyboard (`LH0` and `RH0`) and the outer thumb keys are the ones farther from the center (`LH1` and `RH1`). If you want this swapped, you can define `TAIPO_THUMB_ORDER_IOOI` instead of the default `TAIPO_THUMB_ORDER_OIIO`.

```c
#define TAIPO_THUMB_ORDER_IOOI 1
#include <zmk-taipo/taipo.dtsi>
```

### One-handed keyboards

If you have a one-handed keyboard, you can define `TAIPO_ONLY_LEFT_HAND` or `TAIPO_ONLY_RIGHT_HAND` to only enable the combos for that hand. For example, for a left-handed keyboard:

```c
#define TAIPO_ONLY_LEFT_HAND 1
#include <zmk-taipo/taipo.dtsi>
```

### `<zmk-taipo/features/virtual_thumbs.dtsi>`
This feature is useful for using Taipo on keyboards without thumb keys, such as the 8-key [The Paintbrush](https://github.com/arduxio/thepaintbrush) keyboard.

The feature adds virtual inner/outer one-shots and lock/unlock combos, as well as space/backspace combos.

- `AOT` is a one-shot-mod for inner
- `RSN` is a one-shot-mod for outer
- `AOTE` for space
- `RSNI` for backpsace
- `AOTI` to lock inner. Press again to unlock
- `RSNE` to lock outer. Press again to unlock

Note: It is required to define two additional layers before including this dtsi file:
```c
#define TAIPO_INNER 7
#define TAIPO_OUTER 8
```

## Adapters and Examples
- Usage snippets: `examples/`
