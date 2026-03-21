#pragma once

// Adapter for standard zmk-helpers key-labels.
// Requires labels like LT1, LM1, RT1, RM1, LH0, RH0 and optionally LH1/RH1.

#ifndef TAIPO_POS_L_T1
#define TAIPO_POS_L_T1 LT1
#endif
#ifndef TAIPO_POS_L_T2
#define TAIPO_POS_L_T2 LT2
#endif
#ifndef TAIPO_POS_L_T3
#define TAIPO_POS_L_T3 LT3
#endif
#ifndef TAIPO_POS_L_T4
#define TAIPO_POS_L_T4 LT4
#endif

#ifndef TAIPO_POS_L_M1
#define TAIPO_POS_L_M1 LM1
#endif
#ifndef TAIPO_POS_L_M2
#define TAIPO_POS_L_M2 LM2
#endif
#ifndef TAIPO_POS_L_M3
#define TAIPO_POS_L_M3 LM3
#endif
#ifndef TAIPO_POS_L_M4
#define TAIPO_POS_L_M4 LM4
#endif

#ifndef TAIPO_POS_R_T1
#define TAIPO_POS_R_T1 RT1
#endif
#ifndef TAIPO_POS_R_T2
#define TAIPO_POS_R_T2 RT2
#endif
#ifndef TAIPO_POS_R_T3
#define TAIPO_POS_R_T3 RT3
#endif
#ifndef TAIPO_POS_R_T4
#define TAIPO_POS_R_T4 RT4
#endif

#ifndef TAIPO_POS_R_M1
#define TAIPO_POS_R_M1 RM1
#endif
#ifndef TAIPO_POS_R_M2
#define TAIPO_POS_R_M2 RM2
#endif
#ifndef TAIPO_POS_R_M3
#define TAIPO_POS_R_M3 RM3
#endif
#ifndef TAIPO_POS_R_M4
#define TAIPO_POS_R_M4 RM4
#endif

#ifndef TAIPO_POS_LH_INNER
#define TAIPO_POS_LH_INNER LH0
#endif

#ifndef TAIPO_POS_LH_OUTER
#if defined(LH1)
#define TAIPO_POS_LH_OUTER LH1
#else
#define TAIPO_POS_LH_OUTER LB1
#endif
#endif

#ifndef TAIPO_POS_RH_INNER
#define TAIPO_POS_RH_INNER RH0
#endif

#ifndef TAIPO_POS_RH_OUTER
#if defined(RH1)
#define TAIPO_POS_RH_OUTER RH1
#else
#define TAIPO_POS_RH_OUTER RB1
#endif
#endif
