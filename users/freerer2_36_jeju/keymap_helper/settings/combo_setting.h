#pragma once

// 콤보 정의(이름, 작동키, 콤보키)
#define COMBO_LIST \
COMBO_X(left_thumb,		U_DEBUG(KC_ESC),	U_NAV(KC_SPC),		U_MOUSE(KC_TAB)) \
COMBO_X(left_thumb2,	U_DEBUG(KC_ESC),	U_NAV(KC_SPC),		U_FUN(KC_TAB)) \
COMBO_X(right_thumb,	KC_DEL,				U_FUN(KC_ENT),		U_NUM(KC_BSPC)) \
COMBO_X(right_thumb2,	KC_DEL,				U_SYM(KC_ENT),		U_NUM(KC_BSPC)) \
COMBO_X(DF,				KC_UNDS,			LCTL_T(KC_D),		LSFT_T(KC_F)) \
COMBO_X(JK,	    		KC_B,				LSFT_T(KC_J),		LCTL_T(KC_K)) \
COMBO_X(SD,				KC_ALGR,			LALT_T(KC_S),		LCTL_T(KC_D)) \
COMBO_X(KL,				KC_CAPS,			LCTL_T(KC_K),		LALT_T(KC_L)) \
COMBO_X(BTN3_SCRL,		TD(U_TD_BTN3_SCRL),	KC_BTN1,			KC_BTN2) \
COMBO_X(BTN3_SCRL2,		TD(U_TD_BTN3_SCRL),	TD(U_TD_CLICK_HOLD),KC_BTN2) \
COMBO_X(GO_CONTENT,		DF(L_CONTENT),		U_DEBUG(KC_ESC),	KC_DEL)
