// SPDX-License-Identifier: CC-BY-SA-4.0
// Copyright 2025 antlers <antlers@illucid.net>

// Re: Backspace
// > Nope. It's the inner/outer thumb keys. They are used as a combo with other keys for the alternative outputs (like inner is mostly capitalized letters and outer is more numbers and symbols), but when pressed alone outer is backspace and inner is space
// >
// > I'd like to recreate bubbleology's graphic to add that since it's one of the common questions, but I think it was originally omitted because some people liked to swap the thumbs
// >
// > The other confusing key in that graphic is AGR which is AltGr. Though I actually replaced that with shift+insert on my personal keymap
// >
// > There is also no mouse or bluetooth management like in artsey, but I think adding that is beyond the base taipo layout's purview
// - hunner

#let margins = (x: 2em, y: 1em)

#let palette = (
  grey-0: rgb("#f0f0f0"),
  grey-1: rgb("#444444"),
  grey-2: rgb("#898989"),
  green: rgb("#b5e2da"),
  lav: rgb("#e9d8ff"),
  blue: rgb("#cad6ff"),
  dark-blue: rgb("#134676"),
  orange: rgb("#ffd2a9"),
)

#let key-size = 16mm

// @typstyle off
#let left-matrix = (
  "r", "s", "n", "i",
  "a", "o", "t", "e",
)

// @typstyle off
#let outer-thumb-bindings = (
  ">", "}", "]", ")",
  "<", "{", "[", "(",
)

#let empty-combo = ("base", "inner", "outer").map(it => (str(it): none)).sum()

#let opposing-binding-columns = (
  (
    "rs": (base: "b", outer: "9"),
    "ao": (base: "l", outer: "4"),
    "ns": (base: "p", outer: "7"),
    "ri": (base: "g", outer: "#"),
    "rn": (base: "z", outer: "8"),
    "at": (base: "q", outer: "3"),
    "rt": (base: "x", outer: "^"),
    "se": (base: "v", outer: "*"),
    "re": (base: "m", outer: "$"),
    "st": (base: "/", inner: "\\", outer: "|"),
    "ro": (base: ";", inner: ":"),
    "ne": (base: ",", inner: ".", outer: "~"),
  ),
  (
    "ni": (base: "y", outer: "5"),
    "te": (base: "h", outer: "0"),
    "ot": (base: "u", outer: "2"),
    "ae": (base: "d", outer: "@"),
    "si": (base: "f", outer: "6"),
    "oe": (base: "c", outer: "1"),
    "oi": (base: "k", outer: "+"),
    "an": (base: "j", outer: "="),
    "ai": (base: "w", outer: "&"),
    "no": (base: "-", inner: "_", outer: "%"),
    "it": (base: "?", inner: "!"),
    "sa": (base: ['], inner: ["], outer: "`"),
  ),
)

#let name(side) = ("left", "right").at((left, right).position(it => it == side))

// I'm writing relative to the left-hand side of the chart,
// in `rlt` order so the bindings-grid comes before thumb and one-shot bindings.
#let dir(side) = (rtl, ltr).at((left, right).position(it => it == side))

#let flip(matrix) = matrix.slice(0, 4).rev() + matrix.slice(4).rev()
#let matrix(side) = if side == right { flip(left-matrix) } else { left-matrix }

#let key(
  letter,
  width: key-size,
  height: key-size,
  fill: palette.grey-0,
  stroke: none,
) = {
  set align(center + horizon)
  set text(size: 30pt, weight: "bold")

  box(
    letter,
    width: width,
    height: height,
    fill: fill,
    stroke: stroke,
  )
}

#let keyboard(binding, side: none) = context {
  let combo = none
  if binding != none { combo = binding.at(0) }

  // @typstyle off
  let key_(key-letter) = key(
    if binding == none { key-letter },

    ..if binding == none or binding.at(0) != none { (stroke: 1.5pt + black) },
    ..if binding != none and key-letter in combo { (fill: palette.dark-blue) },
  )

  let matrix = left-matrix.slice(0, 4).zip(left-matrix.slice(4))
  if stack.dir == dir(side) { matrix = matrix.rev() }

  stack(..matrix.map(it => stack(dir: ttb, ..it.map(key_))))
}

#let binding-block(binding, side: none) = {
  let (combo, layers) = (binding.at(0), empty-combo + binding.at(1))

  if layers.at("base", default: none) == none { return }

  let outer-fill = palette.grey-0

  if layers.inner == none { layers.inner = upper(layers.base) }
  if layers.outer != none { outer-fill = palette.lav }

  show: scale.with(x: 50%, y: 50%, reflow: true)

  set box(radius: 6pt)
  set stack(spacing: 0pt)

  // @typstyle off
  stack(spacing: stack.spacing * 2,
    stack(dir: ttb,
      key(layers.inner, fill: palette.green),
      key(layers.outer, fill: outer-fill)),

    scale(x: 200%, y: 200%, reflow: true, {
      set box(radius: 4pt)
      key(layers.base, fill: box.fill)
    }),

    keyboard(binding, side: side)
  )
}

#let bindings-grid(bindings, side: none) = {
  show grid.cell: it => {
    set stack(dir: if it.x == 0 { ltr } else { rtl })
    set box(fill: if it.y > 8 { palette.orange } else { palette.blue })

    let it = it.body.fields().at("value", default: none)
    if it == none { return none }
    context binding-block(it, side: side)
  }

  if side == right { bindings = bindings.rev() }
  let bindings = array.zip(..bindings.map(dictionary.pairs)).sum()
  context grid(columns: 2, gutter: stack.spacing * 2, ..bindings.map(metadata))
}

#let thumb-legend() = context {
  let blank-keyboard = {
    set text(size: 30pt)
    align(center + horizon, box(
      width: key-size * 2,
      height: key-size,
      fill: palette.grey-0,
      // For my own layouts I've taken pains to line-up dashes on-top of <=3 visible corners;
      // AFAIK that isn't trivial to replicate here.
      stroke: (paint: black, thickness: 2pt, dash: (7.4pt,)),
    )[+])
  }

  let key_ = key.with(none, width: key-size / 2, height: key-size / 2)
  let inactive = key_(fill: palette.grey-0, stroke: (dash: (1.2pt,)))

  // @typstyle off
  stack(dir: ltr, spacing: key-size/2,
    ..(
      (0, "Inner", palette.green),
      (1, "Outer", palette.lav),
    ).map(((active-idx, pos, fill)) => {
      show: box

      stack(h(key-size / 2), [
        #set highlight(fill: fill, extent: 2pt, top-edge: 1em)
        === Input +#linebreak() #highlight[#pos Thumb]
        #blank-keyboard
      ])

      let thumb-keys = (inactive, key_(fill: fill, stroke: 1.5pt + black))
      if active-idx == 1 { thumb-keys = thumb-keys.rev() }

      set block(above: stack.spacing)
      stack(..thumb-keys)
    })
  )
}

#let thumb-bindings(side: none) = block({
  // @typstyle off
  grid(columns: 4,
    ..matrix(side).map(it => key(
      width: key-size * 1.33,
      height: key-size * 1.33,
      fill: palette.grey-0,
      stroke: (thickness: 1.5pt, paint: black, dash: (4pt,)),

      context {
        show: box.with(inset: stack.spacing)

        let active-corners = if side == left { (1, 2) } else { (0, 3) }
        let is-outer-thumb(idx) = idx == calc.max(..active-corners)

        grid(columns: 2, ..range(4).map(idx => {
          if idx in active-corners {
            let (binding, fill) = if is-outer-thumb(idx) {
              (outer-thumb-bindings.at(left-matrix.position(k => k == it)),
                palette.lav)
            } else {
              (upper(it),
                palette.green)
            }

            key(width: 100%, height: 50%, fill: fill,
              text(size: text.size/2, binding)
            )
          }
        }))
      },
    ))
  )
})

#let one-shot-bindings(side: none) = {
  let one-shot-combos = (
    (
      "ra": (base: "GUI", inner: "RT", outer: "PGU"),
      "so": (base: "ALT", inner: "UP", outer: "HOM"),
      ..range(2).map(i => ("dummy-" + str(i): none)).sum(),
    ),
    (
      "ie": (base: "SHFT", inner: "LT", outer: "PGD"),
      "nt": (base: "CTRL", inner: "DWN", outer: "END"),
      "sni": (base: "TAB", inner: "DEL", outer: "FN"),
      "ote": (base: "ENTR", inner: "ESC", outer: "AGR"),
    ),
  )

  show: block
  [=== One Shot Key]
  show text: text.with(size: 0.55em)
  bindings-grid(
    one-shot-combos.map(it => it.pairs().slice(0, 2).to-dict()),
    side: side,
  )
  // v(block.above, weak: true)
  v(par.spacing, weak: true)
  bindings-grid(
    one-shot-combos.map(it => it.pairs().slice(2).to-dict()),
    side: side,
  )
}

// @typstyle off
#let f-key-bindings(side: none) = {
  let f-key(name, prefix) = stack(
    context {
      let width = measure(box("F10-F19")).width
      align(center, box(name, width: width, fill: palette.grey-0))
    },

    box("=", fill: none, inset: (x: 0pt)),

    stack(dir: ltr,
      box[FN],
      ..if prefix != none { (
        box("+", fill: none, inset: (x: 0pt)),
        box(prefix),
      ) },
      box("+", fill: none, inset: (x: 0pt)),
      box[1-9],
    ),
  )

  box[=== F-Key]

  set text(size: 8.5pt, weight: "bold")
  set box(inset: 0.66em, fill: palette.lav,
    ..if name == "F10-F19" { (inset: (x: 2pt)) })
  set stack(dir: dir(side.inv()))
  set block(above: 1.5em)

  stack(dir: ttb, f-key("F1-F9", none), f-key("F10-F19", "0"))
}

#let chart(side) = context {
  set stack(dir: dir(side))

  let base-layer = keyboard(none, side: side)
  let bindings-grid = bindings-grid(opposing-binding-columns, side: side)

  show: box.with(inset: margins, fill: white)

  align(side, [== #(name(side) + " hand")])

  show: it => align(side.inv(), box(it))

  context {
    let width = measure(bindings-grid).width
    box(align(center, box(width: width, base-layer)))
  }

  show: it => stack(spacing: par.spacing, [= Combos] + bindings-grid, it)

  thumb-legend()
  thumb-bindings(side: side)
  one-shot-bindings(side: side)

  show: it => align(side, box(it))

  f-key-bindings(side: side)

  set text(fill: palette.grey-2)
  v(2.2em, weak: true)
  // @typstyle off
  stack(dir: ttb,
    [Original by Bubbleology\#4041],
    stack([v0.3], [-], [Typst clone by antlers \<antlers\@illucid.net>]),
  )
}

#set page(width: auto, height: auto, margin: 0pt)

#set par(spacing: 2.66em)
#set text(font: "DejaVu Sans Mono")
#set box(radius: 4pt)
#set stack(spacing: 4pt)
#set grid(gutter: 4pt)

#show heading: upper
#show heading.where(level: 1): it => { align(center, text(size: 34pt, it)) }
#show heading.where(level: 3): set text(size: 12pt)

// @typstyle off
#box(fill: palette.grey-0,
  stack(dir: ltr, spacing: key-size / 4,
    ..(left, right).map(side => chart(side))))