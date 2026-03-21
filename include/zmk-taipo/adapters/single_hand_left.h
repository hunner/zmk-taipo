#pragma once

// Adapter for single-hand Taipo boards that only expose left-hand positions.
// Requires LT1..LT4 and LM1..LM4. Optional LH0/LB1 for thumb mapping.

#ifndef TAIPO_ENABLE_RIGHT_HAND
#define TAIPO_ENABLE_RIGHT_HAND 0
#endif

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

#ifndef TAIPO_POS_LH_INNER
#if defined(LH0)
#define TAIPO_POS_LH_INNER LH0
#else
#define TAIPO_POS_LH_INNER LB1
#endif
#endif

#ifndef TAIPO_POS_LH_OUTER
#if defined(LB1)
#define TAIPO_POS_LH_OUTER LB1
#else
#define TAIPO_POS_LH_OUTER TAIPO_POS_LH_INNER
#endif
#endif

#ifndef TAIPO_POS_R_T1
#define TAIPO_POS_R_T1 TAIPO_UNUSED_POS
#endif
#ifndef TAIPO_POS_R_T2
#define TAIPO_POS_R_T2 TAIPO_UNUSED_POS
#endif
#ifndef TAIPO_POS_R_T3
#define TAIPO_POS_R_T3 TAIPO_UNUSED_POS
#endif
#ifndef TAIPO_POS_R_T4
#define TAIPO_POS_R_T4 TAIPO_UNUSED_POS
#endif

#ifndef TAIPO_POS_R_M1
#define TAIPO_POS_R_M1 TAIPO_UNUSED_POS
#endif
#ifndef TAIPO_POS_R_M2
#define TAIPO_POS_R_M2 TAIPO_UNUSED_POS
#endif
#ifndef TAIPO_POS_R_M3
#define TAIPO_POS_R_M3 TAIPO_UNUSED_POS
#endif
#ifndef TAIPO_POS_R_M4
#define TAIPO_POS_R_M4 TAIPO_UNUSED_POS
#endif

#ifndef TAIPO_POS_RH_INNER
#define TAIPO_POS_RH_INNER TAIPO_UNUSED_POS
#endif
#ifndef TAIPO_POS_RH_OUTER
#define TAIPO_POS_RH_OUTER TAIPO_UNUSED_POS
#endif
