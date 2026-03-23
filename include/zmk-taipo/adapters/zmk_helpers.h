#pragma once

// Adapter to map taipo positions to a set of key positions from urob's zmk-helpers.
// Allows the disabling of either hand for single-handed keyboards

#ifdef TAIPO_ONLY_RIGHT_HAND
#define TAIPO_POS_LI TAIPO_UNUSED_POS
#define TAIPO_POS_LN TAIPO_UNUSED_POS
#define TAIPO_POS_LS TAIPO_UNUSED_POS
#define TAIPO_POS_LR TAIPO_UNUSED_POS
#define TAIPO_POS_LE TAIPO_UNUSED_POS
#define TAIPO_POS_LT TAIPO_UNUSED_POS
#define TAIPO_POS_LO TAIPO_UNUSED_POS
#define TAIPO_POS_LA TAIPO_UNUSED_POS
#define TAIPO_POS_H1 TAIPO_UNUSED_POS
#define TAIPO_POS_H2 TAIPO_UNUSED_POS
#else
#ifndef TAIPO_POS_LI
#define TAIPO_POS_LI LT1
#endif
#ifndef TAIPO_POS_LN
#define TAIPO_POS_LN LT2
#endif
#ifndef TAIPO_POS_LS
#define TAIPO_POS_LS LT3
#endif
#ifndef TAIPO_POS_LR
#define TAIPO_POS_LR LT4
#endif
#ifndef TAIPO_POS_LE
#define TAIPO_POS_LE LM1
#endif
#ifndef TAIPO_POS_LT
#define TAIPO_POS_LT LM2
#endif
#ifndef TAIPO_POS_LO
#define TAIPO_POS_LO LM3
#endif
#ifndef TAIPO_POS_LA
#define TAIPO_POS_LA LM4
#endif
#ifndef TAIPO_POS_H2
#define TAIPO_POS_H2 LH0
#endif
#ifndef TAIPO_POS_H1
#define TAIPO_POS_H1 LH1
#endif
#endif

#ifdef TAIPO_ONLY_LEFT_HAND
#define TAIPO_POS_RI TAIPO_UNUSED_POS
#define TAIPO_POS_RN TAIPO_UNUSED_POS
#define TAIPO_POS_RS TAIPO_UNUSED_POS
#define TAIPO_POS_RR TAIPO_UNUSED_POS
#define TAIPO_POS_RE TAIPO_UNUSED_POS
#define TAIPO_POS_RT TAIPO_UNUSED_POS
#define TAIPO_POS_RO TAIPO_UNUSED_POS
#define TAIPO_POS_RA TAIPO_UNUSED_POS
#define TAIPO_POS_H3 TAIPO_UNUSED_POS
#define TAIPO_POS_H4 TAIPO_UNUSED_POS
#else
#ifndef TAIPO_POS_RI
#define TAIPO_POS_RI RT1
#endif
#ifndef TAIPO_POS_RN
#define TAIPO_POS_RN RT2
#endif
#ifndef TAIPO_POS_RS
#define TAIPO_POS_RS RT3
#endif
#ifndef TAIPO_POS_RR
#define TAIPO_POS_RR RT4
#endif
#ifndef TAIPO_POS_RE
#define TAIPO_POS_RE RM1
#endif
#ifndef TAIPO_POS_RT
#define TAIPO_POS_RT RM2
#endif
#ifndef TAIPO_POS_RO
#define TAIPO_POS_RO RM3
#endif
#ifndef TAIPO_POS_RA
#define TAIPO_POS_RA RM4
#endif
#ifndef TAIPO_POS_H3
#define TAIPO_POS_H3 RH0
#endif
#ifndef TAIPO_POS_H4
#define TAIPO_POS_H4 RH1
#endif
#endif
