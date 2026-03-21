#pragma once

// Positions contract for zmk-taipo.
//
// Required macros:
// - TAIPO_POS_L_T1..TAIPO_POS_L_T4
// - TAIPO_POS_L_M1..TAIPO_POS_L_M4
// - TAIPO_POS_R_T1..TAIPO_POS_R_T4
// - TAIPO_POS_R_M1..TAIPO_POS_R_M4
// - TAIPO_POS_LH_INNER, TAIPO_POS_LH_OUTER
// - TAIPO_POS_RH_INNER, TAIPO_POS_RH_OUTER
//
// Adapters in zmk-taipo/adapters provide common mappings from zmk-helpers
// key-labels to this contract.

#ifndef TAIPO_UNUSED_POS
#define TAIPO_UNUSED_POS 99
#endif

#ifndef TAIPO_POS_L_T1
#error "Missing TAIPO_POS_L_T1 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_L_T2
#error "Missing TAIPO_POS_L_T2 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_L_T3
#error "Missing TAIPO_POS_L_T3 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_L_T4
#error "Missing TAIPO_POS_L_T4 (include a zmk-taipo adapter or define contract macros manually)"
#endif

#ifndef TAIPO_POS_L_M1
#error "Missing TAIPO_POS_L_M1 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_L_M2
#error "Missing TAIPO_POS_L_M2 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_L_M3
#error "Missing TAIPO_POS_L_M3 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_L_M4
#error "Missing TAIPO_POS_L_M4 (include a zmk-taipo adapter or define contract macros manually)"
#endif

#ifndef TAIPO_POS_R_T1
#error "Missing TAIPO_POS_R_T1 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_R_T2
#error "Missing TAIPO_POS_R_T2 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_R_T3
#error "Missing TAIPO_POS_R_T3 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_R_T4
#error "Missing TAIPO_POS_R_T4 (include a zmk-taipo adapter or define contract macros manually)"
#endif

#ifndef TAIPO_POS_R_M1
#error "Missing TAIPO_POS_R_M1 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_R_M2
#error "Missing TAIPO_POS_R_M2 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_R_M3
#error "Missing TAIPO_POS_R_M3 (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_R_M4
#error "Missing TAIPO_POS_R_M4 (include a zmk-taipo adapter or define contract macros manually)"
#endif

#ifndef TAIPO_POS_LH_INNER
#error "Missing TAIPO_POS_LH_INNER (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_LH_OUTER
#error "Missing TAIPO_POS_LH_OUTER (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_RH_INNER
#error "Missing TAIPO_POS_RH_INNER (include a zmk-taipo adapter or define contract macros manually)"
#endif
#ifndef TAIPO_POS_RH_OUTER
#error "Missing TAIPO_POS_RH_OUTER (include a zmk-taipo adapter or define contract macros manually)"
#endif
