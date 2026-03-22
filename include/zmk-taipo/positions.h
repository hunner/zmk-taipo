#pragma once

// Positions contract for zmk-taipo.
//
// Required macros:
// - TAIPO_POS_LT1..TAIPO_POS_LT4
// - TAIPO_POS_LM1..TAIPO_POS_LM4
// - TAIPO_POS_RT1..TAIPO_POS_RT4
// - TAIPO_POS_RM1..TAIPO_POS_RM4
// - TAIPO_POS_LH0, TAIPO_POS_LH1
// - TAIPO_POS_RH0, TAIPO_POS_RH1
//
// Adapters in zmk-taipo/adapters provide common mappings from zmk-helpers
// key-labels to this contract.

#define TAIPO_UNUSED_POS 99

#ifndef TAIPO_POS_LT1
#error "Missing TAIPO_POS_LT1 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_LT2
#error "Missing TAIPO_POS_LT2 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_LT3
#error "Missing TAIPO_POS_LT3 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_LT4
#error "Missing TAIPO_POS_LT4 (include a zmk-taipo adapter or define contract macros manually)"
#endif

#ifndef TAIPO_POS_LM1
#error "Missing TAIPO_POS_LM1 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_LM2
#error "Missing TAIPO_POS_LM2 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_LM3
#error "Missing TAIPO_POS_LM3 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_LM4
#error "Missing TAIPO_POS_LM4 (include a zmk-taipo adapter or define contract macros manually)"
#endif

#ifndef TAIPO_POS_RT1
#error "Missing TAIPO_POS_RT1 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_RT2
#error "Missing TAIPO_POS_RT2 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_RT3
#error "Missing TAIPO_POS_RT3 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_RT4
#error "Missing TAIPO_POS_RT4 (include a zmk-taipo adapter or define contract macros manually)"
#endif

#ifndef TAIPO_POS_RM1
#error "Missing TAIPO_POS_RM1 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_RM2
#error "Missing TAIPO_POS_RM2 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_RM3
#error "Missing TAIPO_POS_RM3 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_RM4
#error "Missing TAIPO_POS_RM4 (include a zmk-taipo adapter or define contract macros manually)"
#endif

#ifndef TAIPO_POS_LH0
#error "Missing TAIPO_POS_LH0 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_LH1
#error "Missing TAIPO_POS_LH1 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_RH0
#error "Missing TAIPO_POS_RH0 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_RH1
#error "Missing TAIPO_POS_RH1 (include a zmk-taipo adapter or define contract macros manually)"
#endif
