// This layout file is based on the "default" layout. I wanted to add another keyboard,
// that was the style I wanted to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _NAV 5
#define _MOUSE 6
#define _ADJUST 16

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 1000

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define COLEMAK M(_COLEMAK)
#define DVORAK M(_DVORAK)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
#define MOUSE M(_MOUSE)
#define M_BL 5
#define NAV LT(_NAV,KC_ESC)
#define EXT_PLV M(13)
#define TOG_OUT M(14)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSPC |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | RSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |Leader| Alt  | GUI  |Lower |    Space    |Raise | Hypr |Enter |      |  fn  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  { KC_TAB,    KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,   KC_Y,  KC_U,    KC_I,     KC_O,    KC_P, KC_BSPC},
  {KC_LCTL,    KC_A,    KC_S,    KC_D,  KC_F,   KC_G,   KC_H,  KC_J,    KC_K,     KC_L, KC_SCLN,  KC_ENT},
  {KC_LSPO,    KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,   KC_N,  KC_M, KC_COMM,   KC_DOT, KC_SLSH, KC_RSFT},
  {    NAV, KC_LEAD, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_HYPR,KC_RETURN, KC_KP_ENTER, XXXXXXX}
},//KC_RSFT MT(MOD_LSFT, KC_RPRN), KC_RSPC

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {M(M_BL), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSPC |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | RSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Lead | Alt  | GUI  |Lower |    Space    |Raise | Hypr |Enter |      | fn?  |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {/*KC_SLSH*/
  { KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,  KC_P,   KC_Y,   KC_F,  KC_G,    KC_C,      KC_R,    KC_L, KC_BSPC},
  {KC_LCTL,    KC_A,    KC_O,    KC_E,  KC_U,   KC_I,   KC_D,  KC_H,    KC_T,      KC_N,    KC_S,  KC_ENT},
  {KC_LSPO, KC_SCLN,    KC_Q,    KC_J,  KC_K,   KC_X,   KC_B,  KC_M,    KC_W,      KC_V,    KC_Z, KC_RSPC},
  {    NAV, KC_LEAD, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_HYPR, KC_RETURN, XXXXXXX, XXXXXXX}
},

/* Lower  |
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |   =  |   [  |   ]  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |   /  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Lead |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {/* KC_BSLS KC_PIPE KC_UNDS KC_LCBR KC_RCBR KC_TILD */
  { KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL},
  {_______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______,  KC_EQL, KC_LBRC, KC_RBRC, KC_MINS},
  {_______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______, KC_SLSH, KC_BSLS, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,    KC_UP, KC_RGHT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | ISO# | ISO~ | ISO/ | ISO| |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Prev | Play | Next | Mute | Vol- | Vol+ |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,    KC_9,       KC_0,  KC_DEL},
  {_______, _______, _______, _______, _______, _______, _______, KC_NUHS, S(KC_NUHS), KC_NUBS, S(KC_NUBS), _______},
  {_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,    _______,   KC_UP,    _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_LEFT, KC_DOWN,    KC_RGHT, _______}
},

/* Navigation layer
 * ,------------------------------------------------------------------------------------.
 * |      |      |   W  |      |  B1  | MUp  |  B2  |      |      |      |      |       |
 * |------+------+------+------+------+-------------+------+------+------+------+-------|
 * |      |   A  |   S  |   D  |MRight|  B3  |MLeft |   H  |   J  |   K  |   L  |       |
 * |------+------+------+------+------+------|------+------+------+------+------+-------|
 * |      |      |      |      |  B4  |MDown |  B5  |      |      |  Up  |      |TogOut |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * |      |      |      |      |      |             |      | Left | Down |Right |EXT_PLV|
 * `-----------------------------------------------------------------------------------'
 */

[_NAV] = {
  {_______, XXXXXXX,    KC_W, XXXXXXX, KC_MS_BTN1,   KC_MS_UP,  KC_MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {_______,    KC_A,    KC_S,    KC_D, KC_MS_LEFT, KC_MS_BTN3, KC_MS_RIGHT,    KC_H,    KC_J,    KC_K,    KC_L, XXXXXXX},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN4, KC_MS_DOWN,  KC_MS_BTN5, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, TOG_OUT},
  {_______, _______, _______, _______,    _______,     KC_SPC,      KC_SPC, _______, KC_LEFT, KC_DOWN, KC_RGHT, EXT_PLV}
},

/* Mouse layer

    Mousekey wheel KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_LEFT, KC_MS_WH_RIGHT,      0xFC 
    Mousekey accel KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2         0xFF 

 * ,-----------------------------------------------------------------------------------.
 * |      |      |   W  |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TogOut|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |      |Lower |             |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_MOUSE] = {
  {XXXXXXX, XXXXXXX,    KC_W, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX,    KC_A,    KC_S,    KC_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {TOG_OUT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {EXT_PLV, _______, XXXXXXX, XXXXXXX, _______,  KC_SPC,  KC_SPC, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},


/* Adjust (Lower + Raise)
 * ,-------------------------------------------------------------------------------------.
 * |       | Reset|      |      |      |      |      |      |      |      |      |  Del  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |       |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak| Nav  |       |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * |       |Voice-|Voice+|Mus on|Musoff|      |      |      |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |      |      |      |      |             |      |      |      |      |M(M_BL)|
 * `------------------------------------------------------------------------------------'
 */
[_ADJUST] = {/*COLEMAK*/
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  DVORAK, M(_NAV), _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M(M_BL) }
}


};

const uint16_t PROGMEM fn_actions[] = {

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_nav[][2]        = SONG(PLOVER_SOUND);
float tone_nav_gb[][2]     = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer)
{
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id)
    {
        case _QWERTY:
            if (record->event.pressed)
            {
                #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
                #endif
                persistant_default_layer_set(1UL<<_QWERTY);
            }
            break;
        case _COLEMAK:
            if (record->event.pressed)
            {
                #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_colemak, false, 0);
                #endif
                persistant_default_layer_set(1UL<<_COLEMAK);
            }
            break;
        case _DVORAK:
            if (record->event.pressed)
            {
                #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
                #endif
                persistant_default_layer_set(1UL<<_DVORAK);
            }
            break;
        case _LOWER:
            if (record->event.pressed)
            {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            else
            {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            break;
        case _RAISE:
            if (record->event.pressed)
            {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            else
            {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            break;
        case M_BL:  //change backlighting
            if (record->event.pressed)
            {
                register_code(KC_RSFT);
                #ifdef BACKLIGHT_ENABLE
                backlight_step();
                #endif
            }
            else
            {
                unregister_code(KC_RSFT);
            }
            break;
        case 12:    //switch to NAV
            if (record->event.pressed)
            {
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_NOTE_ARRAY(tone_nav, false, 0);
                #endif
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_on(_NAV);
                if (!eeconfig_is_enabled()) {eeconfig_init();}
                keymap_config.raw = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            break;
        case 13:    //exit PLV
            if (record->event.pressed)
            {
                #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_nav_gb, false, 0);
                #endif
                layer_off(_NAV);
            }
            break;
        case 14:        //tog out ?????
            if (record->event.pressed)
            {//erfvolerfvol
                return MACRO( D(E), D(R), D(F), D(V), D(O), D(L), U(E), U(R), U(F), U(V), U(O), U(L), END );
            }
            break;
    }
    return MACRO_NONE;
};

void matrix_init_user(void)
{
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

LEADER_EXTERNS();

void matrix_scan_user(void)
{
    LEADER_DICTIONARY()
    {
        leading = false;
        leader_end();
        
        SEQ_ONE_KEY(KC_V){SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);}
        SEQ_ONE_KEY(KC_T){SEND_STRING("Thank You");}
        
        SEQ_ONE_KEY(KC_A)
        {
/*  KC_LCTRL   -> shift
    KC_LSHIFT, -> control
    KC_LALT,   -> shift
    KC_LGUI,   -> control
    KC_RCTRL,
    KC_RSHIFT,
    KC_RALT,
    KC_RGUI,
*/
            register_code(KC_LSFT);
            register_code(KC_A);
            unregister_code(KC_A);
            unregister_code(KC_LSFT);
        }
        
        SEQ_ONE_KEY(KC_M)
        {
            register_code(KC_A);
            unregister_code(KC_A);
            register_code(KC_2);
            unregister_code(KC_2);
            register_code(KC_3);
            unregister_code(KC_3);
            register_code(KC_4);
            unregister_code(KC_4);
            register_code(KC_5);
            unregister_code(KC_5);
        }
        
        SEQ_TWO_KEYS(KC_A, KC_A)
        {
            SEND_STRING("am");
        }
        
        
        //tmux go left
        SEQ_TWO_KEYS(KC_B, KC_L)
        {
            register_mods(KC_LCTL);
            register_code(KC_B);
            
            unregister_code(KC_B);
            unregister_mods(KC_LCTL);
            
            register_code(KC_LEFT);
            unregister_code(KC_LEFT);
        }
        
        SEQ_THREE_KEYS(KC_S, KC_D, KC_F)
        {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
        }
    }
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
