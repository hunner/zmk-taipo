# zmk-taipo

Reusable Taipo layout module for ZMK.

## Dependencies

- [`zmk-helpers`](https://github.com/urob/zmk-helpers) for key-label conventions.
- Optional: [`zmk-leader-key`](https://github.com/urob/zmk-leader-key) if you include `features/leader.dtsi`.

## Prerequisites

This module assumes your keyboard is using the zmk-helpers key labeling conventions, as found in https://github.com/urob/zmk-helpers/tree/main/include/zmk-helpers/key-labels . This means your keyboard has key positions labeled as `LT4` for the left top pinky, `RM1` for the right middle index, etc.

This module will map combos using `LT4..LT1`, `LM4..LM1`, `RT1..RT4`, and `RM1..RM4` for the Taipo finger positions.

## Usage

1. Add this repository as a west project (commonly at `modules/zmk/taipo`)
2. In your keymap, include key-labels
3. Include a Taipo adapter to map your key positions to the Taipo layout contract
4. Include the core Taipo combos DTSI file
5. Include optional feature files as needed

Example:

```c
#include <zmk-helpers/helper.h>
#include <zmk-helpers/key-labels/34.h>

#define TAIPO 6
#define TAIPO_INNER 7
#define TAIPO_OUTER 8
#define TAIPO_THUMB_ORDER_OIIO 1

#include <zmk-taipo/adapters/zmk_helpers.h>
#include <zmk-taipo/taipo.dtsi>
#include <zmk-taipo/features/virtual_thumbs.dtsi>
#include <zmk-taipo/features/leader.dtsi>
```

## Positions Contract

`<zmk-taipo/taipo.dtsi>` requires these macros to be defined:

- `TAIPO_POS_L_T1..TAIPO_POS_L_T4`
- `TAIPO_POS_L_M1..TAIPO_POS_L_M4`
- `TAIPO_POS_R_T1..TAIPO_POS_R_T4`
- `TAIPO_POS_R_M1..TAIPO_POS_R_M4`
- `TAIPO_POS_LH_INNER`, `TAIPO_POS_LH_OUTER`
- `TAIPO_POS_RH_INNER`, `TAIPO_POS_RH_OUTER`

For standard zmk-helpers key labels, include:

- `<zmk-taipo/adapters/zmk_helpers.h>`

For one-hand left-only boards, include:

- `<zmk-taipo/adapters/single_hand_left.h>`

## Config Flags

- `TAIPO_ENABLE_RIGHT_HAND` (default `1`)
- `TAIPO_THUMB_ORDER_IOOI` or `TAIPO_THUMB_ORDER_OIIO` (default `OIIO`)
- `TAIPO_COMBO_TERM_FAST` (default `100`)
- `TAIPO_COMBO_TERM_SLOW` (default `80`)
- `TAIPO_PASTE_BINDING` (default `&kp LS(INSERT)`)

## Optional Features

- `<zmk-taipo/features/virtual_thumbs.dtsi>`
  - Adds virtual inner/outer thumb one-shots and lock/unlock combos.
  - Adds space/backspace fallback combos for thumbless Taipo.
- `<zmk-taipo/features/leader.dtsi>`
  - Adds the Taipo leader combo.
  - Adds default F1-F19 leader sequences.

## Adapters and Examples

- Adapters: `include/zmk-taipo/adapters/`
- Usage snippets: `examples/`
