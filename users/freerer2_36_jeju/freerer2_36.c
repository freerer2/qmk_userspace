#include QMK_KEYBOARD_H
#include "freerer2_36.h"

// 더블탭 실행함수
void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
	if (state->count == 2) {
		reset_keyboard();
	}
};

#define LAYER_X(LAYER, STRING) \
void u_td_fn_L_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << L_##LAYER); \
  } \
}
LAYER_LIST
#undef LAYER_X

void u_td_fn_slsh_finish(tap_dance_state_t *state, void *user_data) {
	td_state = cur_dance(state);
	switch (td_state) {
		case TD_SINGLE_TAP:
			register_code(KC_SLSH);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(true);
			#endif
			layer_on(L_MOUSE);
			break;
		case TD_DOUBLE_TAP:
			tap_code(KC_SLSH);
			tap_code(KC_SLSH);
			break;
		case TD_TRIPPLE_TAP:
			tap_code(KC_SLSH);
			tap_code(KC_SLSH);
			tap_code(KC_SLSH);
		default:
			break;
    }
}

void u_td_fn_slsh_reset(tap_dance_state_t *state, void *user_data) {
	switch (td_state) {
		case TD_SINGLE_TAP:
			unregister_code(KC_SLSH);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(false);
			#endif
			layer_off(L_MOUSE);
			break;
		default:
			break;
    }
	td_state = TD_NONE;
}

void u_td_fn_btn2scrl_finish(tap_dance_state_t *state, void *user_data) {
	td_state = cur_dance(state);
	switch (td_state) {
		case TD_SINGLE_TAP:
			register_code(KC_BTN2);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(true);
			#else
				register_code(KC_LSFT);
			#endif
			break;
		default:
			break;
    }
}

void u_td_fn_btn2scrl_reset(tap_dance_state_t *state, void *user_data) {
	switch (td_state) {
		case TD_SINGLE_TAP:
			unregister_code(KC_BTN2);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(false);
			#else
				unregister_code(KC_LSFT);
			#endif
			break;
		default:
			break;
    }
	td_state = TD_NONE;
}

void u_td_fn_btn3scrl_finish(tap_dance_state_t *state, void *user_data) {
	td_state = cur_dance(state);
	switch (td_state) {
		case TD_SINGLE_TAP:
			register_code(KC_BTN3);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(true);
			#else
				register_code(KC_LSFT);
			#endif
			break;
		default:
			break;
    }
}

void u_td_fn_btn3scrl_reset(tap_dance_state_t *state, void *user_data) {
	switch (td_state) {
		case TD_SINGLE_TAP:
			unregister_code(KC_BTN3);
			break;
		case TD_SINGLE_HOLD:
			#ifdef POINTING_DEVICE_ENABLE
				charybdis_set_pointer_dragscroll_enabled(false);
			#else
				unregister_code(KC_LSFT);
			#endif
			break;
		default:
			break;
    }
	td_state = TD_NONE;
}

static bool is_click = false;
void u_td_fn_clickhold_finish(tap_dance_state_t *state, void *user_data) {
	td_state = cur_dance(state);
	switch (td_state) {
		case TD_SINGLE_TAP:
			register_code(KC_BTN1);
			is_click = false;
			break;
		case TD_SINGLE_HOLD:
			if(!is_click){
				register_code(KC_BTN1);
				is_click = true;
			} else {
				is_click = false;
			}
			break;
		default:
			break;
    }
}

void u_td_fn_clickhold_reset(tap_dance_state_t *state, void *user_data) {
	switch (td_state) {
		case TD_SINGLE_TAP:
			if(!is_click){
				unregister_code(KC_BTN1);
			}
			break;
		default:
			break;
    }
	td_state = TD_NONE;
}

// 더블탭 실행 액션 추가
tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
    [U_TD_SLSH_SCRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_td_fn_slsh_finish, u_td_fn_slsh_reset),
    [U_TD_BTN2_SCRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_td_fn_btn2scrl_finish, u_td_fn_btn2scrl_reset),
    [U_TD_BTN3_SCRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_td_fn_btn3scrl_finish, u_td_fn_btn3scrl_reset),
    [U_TD_CLICK_HOLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_td_fn_clickhold_finish, u_td_fn_clickhold_reset),
	#define LAYER_X(LAYER, STRING) [U_TD_L_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_L_##LAYER),
	LAYER_LIST
	#undef LAYER_X
};

//유저키코드
static bool is_eclipse = false;
static bool is_browser = false;
static bool is_nexaro = false;

static bool dpad_up    = false;
static bool dpad_down  = false;
static bool dpad_left  = false;
static bool dpad_right = false;

void update_dpad_hat(void) {
    if (dpad_up && dpad_right)
        joystick_set_hat(JOYSTICK_HAT_NORTHEAST);
    else if (dpad_up && dpad_left)
        joystick_set_hat(JOYSTICK_HAT_NORTHWEST);
    else if (dpad_down && dpad_right)
        joystick_set_hat(JOYSTICK_HAT_SOUTHEAST);
    else if (dpad_down && dpad_left)
        joystick_set_hat(JOYSTICK_HAT_SOUTHWEST);
    else if (dpad_up)
        joystick_set_hat(JOYSTICK_HAT_NORTH);
    else if (dpad_down)
        joystick_set_hat(JOYSTICK_HAT_SOUTH);
    else if (dpad_right)
        joystick_set_hat(JOYSTICK_HAT_EAST);
    else if (dpad_left)
        joystick_set_hat(JOYSTICK_HAT_WEST);
    else
        joystick_set_hat(JOYSTICK_HAT_CENTER);
}

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_VIRTUAL, // 0: 좌측 X
    JOYSTICK_AXIS_VIRTUAL, // 1: 좌측 Y
    JOYSTICK_AXIS_VIRTUAL, // 2: 우측 X
    JOYSTICK_AXIS_VIRTUAL  // 3: 우측 Y
};

// 유저키코드 처리
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		
	case CMOS:
		if (record->event.pressed) {
			SEND_STRING("u175060@" SS_DELAY(1000) SS_TAP(X_ENT));
		}
		
		return false;
		
		
	case ECLIPSE:
		if (record->event.pressed) {
			is_eclipse = true;
			is_browser = false;
			is_nexaro = false;
		}
		return false;
		
	case BROWSER:
		if (record->event.pressed) {
			is_eclipse = false;
			is_browser = true;
			is_nexaro = false;
		}
		return false;
		
	case NEXACRO:
		if (record->event.pressed) {
			is_eclipse = false;
			is_browser = false;
			is_nexaro = true;
		}
		return false;
		
    case STEP_INTO:
		if(is_eclipse){
			if (record->event.pressed) {
				register_code(KC_F5);
			} else {
				unregister_code(KC_F5);
			}
		} else if (is_browser || is_nexaro){
			if (record->event.pressed) {
				register_code(KC_F11);
			} else {
				unregister_code(KC_F11);
			}
		}
		return false;
		
    case STEP_OVER:
		if(is_eclipse){
			if (record->event.pressed) {
				register_code(KC_F6);
			} else {
				unregister_code(KC_F6);
			}
		} else if (is_browser || is_nexaro){
			if (record->event.pressed) {
				register_code(KC_F10);
			} else {
				unregister_code(KC_F10);
			}
		}
		return false;
		
    case STEP_OUT:
		if(is_eclipse){
			if (record->event.pressed) {
				register_code(KC_F7);
			} else {
				unregister_code(KC_F7);
			}
		} else if (is_browser || is_nexaro){
			if (record->event.pressed) {
				register_code(KC_LSFT);
				register_code(KC_F11);
			} else {
				unregister_code(KC_F11);
				unregister_code(KC_LSFT);
			}
		}
		return false;
		
    case RESUME:
		if(is_eclipse || is_browser){
			if (record->event.pressed) {
				register_code(KC_F8);
			} else {
				unregister_code(KC_F8);
			}
		} else if (is_nexaro){
			if (record->event.pressed) {
				register_code(KC_F5);
			} else {
				unregister_code(KC_F5);
			}
		}
		return false;
		
	case JS_10: // L3
		if (record->event.pressed) {
			joystick_set_axis(0, -127); // X축 최대로 왼쪽
		} else {
			joystick_set_axis(0, 0);    // 뗄 때 원점 복귀
		}
		return false;
	case JS_11: // R3: 오른쪽으로 스틱 이동
		if (record->event.pressed) {
			joystick_set_axis(2, 127);  // X축 최대로 오른쪽
		} else {
			joystick_set_axis(2, 0);    // 뗄 때 원점 복귀
		}
		return false;
	case JS_UP:
		dpad_up = record->event.pressed;
		update_dpad_hat();
		return false;
	case JS_DOWN:
		dpad_down = record->event.pressed;
		update_dpad_hat();
		return false;
	case JS_LEFT:
		dpad_left = record->event.pressed;
		update_dpad_hat();
		return false;
	case JS_RGHT:
		dpad_right = record->event.pressed;
		update_dpad_hat();
		return false;
	}
    return true;
};

//탭 시간간격
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case TD(U_TD_BTN3_SCRL): /*case TD(U_TD_SLSH_SCRL):*/
			return TAPPING_TERM - 50;
		case LCTL_T(KC_D): case LSFT_T(KC_F): /*검지중지는 기본값*/
		case LSFT_T(KC_J): case LCTL_T(KC_K): 
            return TAPPING_TERM;
        case LGUI_T(KC_A): case LALT_T(KC_S): /*약지소지는 기본값-50*/
		case LALT_T(KC_L): case LGUI_T(KC_QUOT):
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}

// matrix_scan_user에서 홀드 판정 및 스틱 이동 처리
void matrix_scan_user(void) {
}