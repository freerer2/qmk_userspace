#pragma once

// 콤보 정의(이름, 작동키, 콤보키)
#define COMBO_LIST \
COMBO_X(ZX,				LT(U_DEBUG,KC_ESC),	KC_Z,				KC_X) \
COMBO_X(XC,				LT(U_NAV,KC_SPC),	KC_X,				KC_C) \
COMBO_X(CV,				LT(U_MOUSE,KC_TAB),	KC_C,				KC_V) \
COMBO_X(MCOMM,	    	LT(U_FUN,KC_ENT),	KC_M,				KC_COMM) \
COMBO_X(COMMDOT,	    LT(U_NUM,KC_BSPC),	KC_COMM,			KC_DOT) \
COMBO_X(DOTSLASH,	    KC_DEL,				KC_DOT,				KC_SLSH) \
COMBO_X(DF,				KC_UNDS,			LCTL_T(KC_D),		LSFT_T(KC_F)) \
COMBO_X(JK,	    		KC_B,				LSFT_T(KC_J),		LCTL_T(KC_K)) \
COMBO_X(SD,				KC_ALGR,			LALT_T(KC_S),		LCTL_T(KC_D)) \
COMBO_X(KL,				KC_CAPS,			LCTL_T(KC_K),		LALT_T(KC_L)) \
COMBO_X(GRAV1,			KC_DOT,				KC_GRV,				KC_1) \
COMBO_X(_12,			KC_0,				KC_1,				KC_2) \
COMBO_X(_23,			KC_MINS,			KC_2,				KC_3) \
COMBO_X(_78,			KC_0,				KC_7,				KC_8)

