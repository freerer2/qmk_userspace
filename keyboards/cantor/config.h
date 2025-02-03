// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define LAYOUT_freerer2_36(\
		K00,	K01,	K02,	K03,	K04,				K05,	K06,	K07,	K08,	K09,\
		K10,	K11,	K12,	K13,	K14,				K15,	K16,	K17,	K18,	K19,\
		K20,	K21,	K22,	K23,	K24,				K25,	K26,	K27,	K28,	K29,\
						K32,	K33,	K34,				K35,	K36,	K37\
)\
LAYOUT_split_3x6_3( \
XXX,	K00,	K01,	K02,	K03,	K04,				K05,	K06,	K07,	K08,	K09,	XXX, \
XXX,	K10,	K11,	K12,	K13,	K14,				K15,	K16,	K17,	K18,	K19,	XXX, \
XXX,	K20,	K21,	K22,	K23,	K24,				K25,	K26,	K27,	K28,	K29,	XXX, \
						K32,	K33,	K34,				K35,	K36,	K37\
)

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define MASTER_RIGHT
#define MASTER_LEFT