// This layout file is based on the "default" layout. I wanted to add another keyboard,
// that was the style I wanted to emulate.

#include "planck.h"
#include "action_layer.h"
#include "keymap_dvorak.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_keycodes
{
    QWERTY = SAFE_RANGE
    , COLEMAK
    , DVORAK
    , LOWER
    , RAISE
    , NAV
    , MOUSE
    , QWERTY_DVORAK
    , ADJUST
    , DYNAMIC_MACRO_RANGE
};

#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _NAV 5
#define _MOUSE 6
#define _QWERTY_DVORAK 7
#define _ADJUST 8
#define _DYN 9
#define NUM_LAYERS _ADJUST+1

//functions
#define _M_BL 12
#define _EXT_NAV 13
#define _TOG_OUT 14

#include "dynamic_macro.h"

#define DM_R1 DYN_REC_START1
#define DM_R2 DYN_REC_START2

#define DM_P1 DYN_MACRO_PLAY1
#define DM_P2 DYN_MACRO_PLAY2

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 1000

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define COLEMAK M(_COLEMAK)
#define DVORAK M(_DVORAK)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
#define MOUSE M(_MOUSE)
#define QD M(_QWERTY_DVORAK)
#define NAV LT(_NAV,KC_ESC)
#define BK_LIT M(_M_BL)
#define ENT_NAV M(_NAV)
#define EXT_NAV M(_EXT_NAV)
#define TOG_OUT M(_TOG_OUT)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

/*

Qwerty/Dvorak --
  |       |      \
Lower - Raise    Nav
      |
    ADJUST
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSPC |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | RSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |Leader| Alt  | GUI  |Lower |    Space    |Raise | Hypr |Enter |  M1  |  fn  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  { KC_TAB,    KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,   KC_Y,  KC_U,    KC_I,      KC_O,     KC_P, KC_BSPC},
  {KC_LCTL,    KC_A,    KC_S,    KC_D,  KC_F,   KC_G,   KC_H,  KC_J,    KC_K,      KC_L,  KC_SCLN,  KC_ENT},
  {KC_LSPO,    KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,   KC_N,  KC_M, KC_COMM,    KC_DOT,  KC_SLSH, KC_RSFT},
  {    NAV, KC_LEAD, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_HYPR, KC_RETURN, MO(_DYN),   DM_P1}
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
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT},
  { BK_LIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
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
  { KC_TAB, KC_QUOT, KC_COMM,  KC_DOT,  KC_P,   KC_Y,   KC_F,  KC_G,    KC_C,      KC_R,     KC_L, KC_BSPC},
  {KC_LCTL,    KC_A,    KC_O,    KC_E,  KC_U,   KC_I,   KC_D,  KC_H,    KC_T,      KC_N,     KC_S,  KC_ENT},
  {KC_LSPO, KC_SCLN,    KC_Q,    KC_J,  KC_K,   KC_X,   KC_B,  KC_M,    KC_W,      KC_V,     KC_Z, KC_RSPC},
  {    NAV, KC_LEAD, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_HYPR, KC_RETURN, MO(_DYN),   DM_P1}
},

/* Qwerty-Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSPC |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | RSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Lead | Alt  | GUI  |Lower |    Space    |Raise | Hypr |Enter |MR_P1 |MR_P2 |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY_DVORAK] = {/*KC_SLSH*/
  { KC_TAB, DV_QUOT, DV_COMM,  DV_DOT,  DV_P,   DV_Y,   DV_F,  DV_G,    DV_C,      DV_R,     DV_L, KC_BSPC},
  {KC_LCTL,    DV_A,    DV_O,    DV_E,  DV_U,   DV_I,   DV_D,  DV_H,    DV_T,      DV_N,     DV_S,  KC_ENT},
  {KC_LSPO, DV_SCLN,    DV_Q,    DV_J,  DV_K,   DV_X,   DV_B,  DV_M,    DV_W,      DV_V,     DV_Z, KC_RSPC},
  {    NAV, KC_LEAD, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_HYPR, KC_RETURN, MO(_DYN),   DM_P1}
},


/* Lower  |
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   [  |   ]  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |      |      |      |      |      |      |      |      |   =  |   /  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |  ←  |   ↓  |   ↑  |  →   |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {/* KC_BSLS KC_PIPE KC_UNDS KC_LCBR KC_RCBR KC_TILD */
  { KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, _______},
  {KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______,  KC_EQL, KC_SLSH, KC_MINS},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______},
  {_______, _______, _______, _______, _______,  KC_SPC,  KC_SPC, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Int1 | Int2 | Int3 | Int4 | ISO# | ISO/ |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Prev | Play | Next | Mute | Vol- | Vol+ |      |  M1  |   ↑  |  M2  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |  ←  |   ↓  |  →   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _______},
  {KC_BSPC, KC_INT1, KC_INT2, KC_INT3, KC_INT4, KC_NUHS, KC_NUBS, _______, KC_SLSH,  KC_EQL, KC_BSLS, KC_RETURN},
  {_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,   KC_UP, _______,   _______},
  {_______, _______, _______, _______, _______,  KC_SPC,  KC_SPC, _______, KC_LEFT, KC_DOWN, KC_RGHT,   _______}
},

/* Navigation layer
 * ,------------------------------------------------------------------------------------.
 * |      |      |   W  |      |  B1  | MUp  |  B2  |      |      |      |      |       |
 * |------+------+------+------+------+-------------+------+------+------+------+-------|
 * |      |   A  |   S  |   D  |MRight|  B3  |MLeft |   H  |   J  |   K  |   L  |       |
 * |------+------+------+------+------+------|------+------+------+------+------+-------|
 * |      |      |      |      |  B4  |MDown |  B5  |      |      |  Up  |      |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------|
 * |      |      |      |      |      |             |      | Left | Down |Right |  del  |
 * `-----------------------------------------------------------------------------------'
 */

[_NAV] = {
  {_______, XXXXXXX,    KC_W, XXXXXXX, KC_MS_BTN1,   KC_MS_UP,  KC_MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______,    KC_A,    KC_S,    KC_D, KC_MS_LEFT, KC_MS_BTN3, KC_MS_RIGHT,    KC_H,    KC_J,    KC_K,    KC_L, _______},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN4, KC_MS_DOWN,  KC_MS_BTN5, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, _______},
  {_______, _______, EXT_NAV, TOG_OUT,    _______,     KC_SPC,      KC_SPC, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC}
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
  {XXXXXXX, XXXXXXX,    KC_W, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {XXXXXXX,    KC_A,    KC_S,    KC_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {TOG_OUT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {EXT_NAV, _______, XXXXXXX, XXXXXXX, _______,  KC_SPC,  KC_SPC, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},


/* Adjust (Lower + Raise)
 * ,-------------------------------------------------------------------------------------.
 * | Reset |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      | F10  |       |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |       | F11  | F12  | F13  | F14  |      |      |      |      |      |      |       |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * |       |Voice-|Voice+|Mus on|Musoff|Aud on|Audoff|      |      |AGswap|AGNORM|       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |       |Qwerty|Dvorak| Nav  |      |             |      |      |BK_LIT|      |       |
 * `-------------------------------------------------------------------------------------'
 */
[_ADJUST] = {/*dropped COLEMAK*/
  {  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______},
  {_______,  KC_F11,  KC_F12,  KC_F13,  KC_F14, _______, _______, _______, _______, _______, _______, _______},
  {_______,  MUV_DE,  MUV_IN,   MU_ON,  MU_OFF,   MI_ON,  MI_OFF,   AU_ON,  AU_OFF, AG_SWAP, AG_NORM, _______},
  {   QD  ,  QWERTY,  DVORAK, ENT_NAV, _______,  KC_SPC,  KC_SPC, _______, _______,  BK_LIT, _______, _______}
},

[_DYN] = {/*Macro layer, must be last*/
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______,   DM_P1,   DM_R1, _______, _______, _______, _______,   DM_R2,   DM_P2, _______, _______},

},

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

/** handles action macros
@param record key info
@param id macro ID
@param opt
@return event
*/
const macro_t *action_get_macro(keyrecord_t* record, uint8_t id, uint8_t opt)
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
        case _QWERTY_DVORAK:
            if (record->event.pressed)
            {
                #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
                PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
                #endif
                persistant_default_layer_set(1UL<<_QWERTY_DVORAK);
            }
            break;
        case _LOWER:
            backlight_toggle();
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
            backlight_toggle();
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
        case _M_BL:  //change backlighting
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
        case _NAV:    //switch to NAV
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
        case _EXT_NAV:    //exit nav
            if (record->event.pressed)
            {
                #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_nav_gb, false, 0);
                #endif
                layer_off(_NAV);
            }
            break;
        case _TOG_OUT:        //tog out ?????
            if (record->event.pressed)
            {//erfvolerfvol
                return MACRO( D(E), D(R), D(F), D(V), D(O), D(L), U(E), U(R), U(F), U(V), U(O), U(L), END );
            }
            break;
        default:
            //if (macro_record_macro_handler(record, id))
            {
                //return MACRO_NONE;
            }
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
        
        //SEQ_ONE_KEY(KC_V){SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);}
        SEQ_ONE_KEY(KC_T){SEND_STRING("Thank You");}
        
        SEQ_ONE_KEY(KC_A)
        {
            register_code(KC_LSFT);
            register_code(KC_A);
            unregister_code(KC_A);
            unregister_code(KC_LSFT);
        }
        
        SEQ_ONE_KEY(KC_D)
        {
            register_code(KC_BSPC);
            unregister_code(KC_BSPC);
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
        
        SEQ_TWO_KEYS(KC_Q, KC_E)
        {
            SEND_STRING("thomas.cherry@gmail.com");
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
        //SEQ_THREE_KEYS(KC_, KC_D, KC_F)
        {
            //register_code();
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    /*if (!process_record_dynamic_macro(keycode, record))
    {
        return false;
    }*/
    return true;
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
