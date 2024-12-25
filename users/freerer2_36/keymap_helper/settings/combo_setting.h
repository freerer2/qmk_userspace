#pragma once

// 콤보 정의(이름, 작동키, 콤보키)
#define COMBO_LIST \
COMBO_X(left_thumb,		LT(U_DEBUG,KC_ESC),		LT(U_NAV,KC_SPC),	LT(U_MOUSE,KC_TAB)) \
COMBO_X(right_thumb,	KC_DEL,		LT(U_FUN,KC_ENT),	LT(U_NUM,KC_BSPC)) \
COMBO_X(XC,				KC_UNDS,	KC_X,				KC_C) \
COMBO_X(COMMDOT,	    KC_B,		KC_COMM,			KC_DOT) \
COMBO_X(DF,				KC_UNDS,	LCTL_T(KC_D),		LSFT_T(KC_F)) \
COMBO_X(JK,	    		KC_B,		LSFT_T(KC_J),		LCTL_T(KC_K)) \
COMBO_X(SD,				KC_ALGR,	LALT_T(KC_S),		LCTL_T(KC_D)) \
COMBO_X(KL,				KC_CAPS,	LCTL_T(KC_K),		LALT_T(KC_L))
