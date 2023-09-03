#include QMK_KEYBOARD_H
#include "config.h"
// clang-format off

enum custom_keycodes {
    UNSAFE = SAFE_RANGE,
    SPAM_M1,
};

bool spamming_m1 = false;

// Key mappings
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// RGB LED layout
// led number, function of the key
//  67, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      69, Prt       Rotary(Mute)   68, Side led 12
//  70, Side led 02    1, ~        7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       78, (=+)     85, BackSpc   72, Del        71, Side led 13
//  73, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       89, ]}       93, \|        75, PgUp       74, Side led 14
//  76, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"                    96, Enter     86, PgDn       77, Side led 15
//  80, Side led 05    4, Sh_L     10, Z       16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?                    90, Sh_R     94, Up        82, End        81, Side led 16
//  83, Side led 06    5, Ct_L     11,Win_L    17, Alt_L                              33, SPACE                              49, Alt_R    55, FN                    65, Ct_R     95, Left     97, Down      79, Right      84, Side led 17
//  87, Side led 07                                                                                                                                                                                                        88, Side led 18
//  91, Side led 08                                                                                                                                                                                                        92, Side led 19

// Default Keyboard Layout
//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, UNSAFE,  _______, _______, SPAM_M1, _______, _______, RGB_MOD, RGB_VAD, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_PSCR,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_INS,
        _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        QK_LOCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          TG(2),   KC_PGUP, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_HOME, KC_PGDN, KC_END
    ),

	[2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_WH_U,
        QK_LOCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_WH_D,
        _______,          _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3,          TG(2),   KC_MS_U, KC_BTN2,
        _______, _______, _______,                            _______,                            _______, _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R
    ),

};

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case UNSAFE:
        if (record->event.pressed) SEND_STRING("thisisunsafe");
        break;
    case SPAM_M1:
        if (record->event.pressed) spamming_m1 = !spamming_m1; 
        break;
    case KC_ESC:
        if (record->event.pressed) if (spamming_m1) spamming_m1 = false;
        break;
    }
    return true;
};

void matrix_scan_user(void) {
    if (spamming_m1) tap_code(KC_BTN1);
};

// clang-format on
// Rotary Encoder mapping
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

// Caps Lock and FN indicators
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	uint8_t outer_led_array[] = {0, 6, 12, 18, 23, 28, 34, 39, 44, 50, 56, 61, 66, 69, 67, 68, 70, 71, 73, 74, 76, 77, 80, 81, 83, 84, 87, 88, 91, 92};
	void set_outer_leds(uint8_t redValue, uint8_t greenValue, uint8_t blueValue) {
		for (uint8_t i=0; i < (sizeof(outer_led_array) / sizeof(outer_led_array[0])); i++) {
			RGB_MATRIX_INDICATOR_SET_COLOR((outer_led_array[i]), redValue, greenValue, blueValue);
		}
	}
	if (host_keyboard_led_state().caps_lock) set_outer_leds(RGB_RED);
	switch(get_highest_layer(layer_state|default_layer_state)) {
		case 1:
		set_outer_leds(RGB_GREEN);
		break;
		case 2:
		set_outer_leds(RGB_BLUE);
		break;
    }
    if (spamming_m1) set_outer_leds(RGB_ORANGE);
	return false;
};