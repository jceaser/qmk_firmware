// This layout file is based on the "default" layout. I wanted to add another keyboard,
// that was the style I wanted to emulate.

#include "planck.h"
#include "action_layer.h"
//#include "keymap_dvorak.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"
#include "quantum.h"
#include "version.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_keycodes
{
    DVORAK = SAFE_RANGE
    , QWERTY
    , LOWER
    , RAISE
    , ADJUST
    , DYNAMIC_MACRO_RANGE
};

#define _DVORAK 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4
#define _DYN 5

//functions
#define _M_BL 12
#define _TOG_OUT 13

#include "dynamic_macro.h"

#define DM_R1 DYN_REC_START1
#define DM_R2 DYN_REC_START2

#define DM_SP DYN_REC_STOP

#define DM_P1 DYN_MACRO_PLAY1
#define DM_P2 DYN_MACRO_PLAY2

#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 1000

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define DVORAK M(_DVORAK)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
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
Lower - Raise    Nav(esc)
      |
    ADJUST
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | '    |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSPC |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | RSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Lead | Alt  | GUI  |Lower |Enter |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  { KC_TAB , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T   , KC_Y   , KC_U  , KC_I    , KC_O    , KC_P    , KC_BSPC},
  {KC_LCTL , KC_A    , KC_S    , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT},
  {KC_LSPO , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT},
  { KC_ESC , KC_LEAD , KC_LALT , KC_LGUI , LOWER , KC_ENT , KC_SPC , RAISE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT}
},// MT(MOD_LSFT, KC_RPRN), KC_RSPC

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | -    |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSPC |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | RSPC |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Lead | Alt  | GUI  |Lower |Enter |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {/* Dvorak layout */
  { KC_TAB , KC_QUOT , KC_COMM , KC_DOT  , KC_P  , KC_Y   , KC_F   , KC_G  , KC_C    , KC_R    , KC_L  , KC_BSPC},
  {KC_LCTL , KC_A    , KC_O    , KC_E    , KC_U  , KC_I   , KC_D   , KC_H  , KC_T    , KC_N    , KC_S  , KC_MINS},
  {KC_LSPO , KC_SCLN , KC_Q    , KC_J    , KC_K  , KC_X   , KC_B   , KC_M  , KC_W    , KC_V    , KC_Z  , KC_RSPC},
  { KC_ESC , KC_LEAD , KC_LALT , KC_LGUI , LOWER , KC_ENT , KC_SPC , RAISE , KC_LEFT , KC_DOWN , KC_UP , KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |Delete|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | App  |SYSREQ|      |      |      | ISO# | Help |   /  |   =  |   \  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | ISO/ | Yen  |  [   | Hyper|   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  (X) |      |      |      | Home |PG DN |PG UP | End  |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = {/* KC_BSLS KC_PIPE KC_UNDS KC_LCBR KC_RCBR KC_TILD */
  { KC_GRV , KC_1    , KC_2      , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_DEL},
  {_______ , KC_APP  , KC_SYSREQ , _______ , _______ , _______ , KC_NUHS , KC_HELP , KC_SLSH , KC_EQL  , KC_BSLS , _______},
  {_______ , _______ , _______   , _______ , _______ , _______ , KC_NUBS , KC_JYEN , KC_LBRC , KC_HYPR , KC_RBRC , _______},
  {_______ , _______ , _______   , _______ , KC_TRNS ,  KC_ENT , KC_SPC  , _______ , KC_HOME , KC_PGDN , KC_PGUP , KC_END}
},

/* Raise  KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_ACL0, KC_ACL1, KC_ACL3
 * ,-----------------------------------------------------------------------------------.
 * |      | B1   | B2   | B3   | B4   | B5   |M ACL0|      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | RCtr | M←  | M↓   | M↑   | M→   |      |M ACL1|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | W←  | W↓   | W↑   | W→   |      |M ACL2|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | RAlt | RGui |      |KEnter|      | (X)  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {//KC_HYPR
  {_______ , KC_BTN1 , KC_BTN2 , KC_BTN3 , KC_BTN4 , KC_BTN5 , KC_ACL0 , _______ , _______ , _______ , _______ , _______ },
  {KC_RCTL , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , _______ , KC_ACL1 , _______ , _______ , _______ , _______ , _______ },
  {_______ , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , _______ , KC_ACL2 , _______ , _______ , _______ , _______ , _______ },
  {_______ , _______ , KC_RALT , KC_RGUI , _______ , KC_PENT , _______ , KC_TRNS , _______ , _______ , _______ , _______ }
},

/* Adjust (Lower + Raise)KC_POWER
 * ,-------------------------------------------------------------------------------------.
 * | Reset |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | EJCT  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |MusTog | F11  | F12  | F13  | F14  | F15  |Dvorak|BK LIT|      |      |      |       |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * |AudTog |      |Qwerty|POWER |      |      |      | Mute |      |      |      |       |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |MIDITog|      |AGswap|AGNORM| (X)  |      | Play | (X)  | Pre  |vDown | vUp  | Next  |
 * `-------------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {  RESET , KC_F1   , KC_F2   , KC_F3    , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_EJCT},
  { MU_TOG , KC_F11  , KC_F12  , KC_F13   , KC_F14  , KC_F15  , DVORAK  , BK_LIT  , _______ , _______ , _______ , _______},
  { AU_TOG , _______ , QWERTY  , KC_POWER , _______ , _______ , _______ , KC_MUTE , _______ , _______ , _______ , _______},
  { MI_TOG , _______ , AG_SWAP , AG_NORM  , KC_TRNS , _______ , KC_MPLY , KC_TRNS , KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT}
},

[_DYN] = {/*Macro layer, must be last*/
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, MI_ON  , MU_ON  , TOG_OUT, _______, AU_ON  , AU_OFF , _______, _______, _______},
  {_______, MUV_DE , MUV_IN , MI_OFF , _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, DM_P1  , DM_R1  , _______, _______, _______, _______,   DM_R2,   DM_P2, _______, _______},

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

float tone_goodbye[][2]    = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer)
{
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

/**
handles action macros
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
                PLAY_SONG(tone_qwerty);
                //PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
                #endif
                persistant_default_layer_set(1UL<<_QWERTY);
            }
            break;
        case _DVORAK:
            if (record->event.pressed)
            {
                #ifdef AUDIO_ENABLE
                PLAY_SONG(tone_dvorak);
                //PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
                #endif
                persistant_default_layer_set(1UL<<_DVORAK);
            }
            break;
        case _LOWER:
            #ifdef BACKLIGHT_ENABLE
            backlight_toggle();
            #endif
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
            #ifdef BACKLIGHT_ENABLE
            backlight_toggle();
            #endif
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
        /*case _NAV:    //switch to NAV
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
            break;*/
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
        //startup_user();
    #endif
}

LEADER_EXTERNS();

void matrix_scan_user(void)
{
    /**
    keyboard  keys:
    hjkl - tmux navigation
    thankyou
    a -
    d - delete
    m - bbedit mark line
    v - version
    */
    LEADER_DICTIONARY()
    {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_V){SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);}
        SEQ_ONE_KEY(KC_T){SEND_STRING("Thank You");}
        //SEQ_ONE_KEY(KC_DOT){SEND_STRING("../");}
        SEQ_THREE_KEYS(KC_DOT, KC_DOT, KC_DOT){SEND_STRING("\xE2\x33");}

        /*SEQ_ONE_KEY(KC_D)
        {
            register_code(KC_BSPC);
            unregister_code(KC_BSPC);
        }*/
        SEQ_ONE_KEY(KC_D)
        {//degree ; alt-k - 88 bytes
            register_code(KC_LALT);
            register_code(KC_K);
            unregister_code(KC_K);
            unregister_code(KC_LALT);
        }
        SEQ_ONE_KEY(KC_MINUS)
        {//long dash ; alt-shift-minus - 96 bytes
            register_code(KC_LALT);
            register_code(KC_LSHIFT);
            register_code(KC_MINUS);
            unregister_code(KC_MINUS);
            unregister_code(KC_LSHIFT);
            unregister_code(KC_LALT);
        }
        SEQ_ONE_KEY(KC_DOT)
        {//elipse ; alt-; - 84
            register_code(KC_LALT);
            register_code(KC_SCLN);
            unregister_code(KC_SCLN);
            unregister_code(KC_LALT);
        }

        SEQ_ONE_KEY(KC_LBRC){SEND_STRING("[ ]"SS_TAP(X_LEFT)SS_TAP(X_LEFT));}
        SEQ_ONE_KEY(KC_SLSH){SEND_STRING("/**/"SS_TAP(X_LEFT)SS_TAP(X_LEFT));}
        //4 spaces ; '    '
        SEQ_ONE_KEY(KC_TAB){SEND_STRING("    ");}
        SEQ_ONE_KEY(KC_4)
        {// take a screen shot of a region
            register_code(KC_LSFT);
            register_code(KC_LGUI);
            register_code(KC_4);
            unregister_code(KC_4);
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
        }

        SEQ_ONE_KEY(KC_LEFT)
        {//select left ; alt-control-shift-left
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_LCTRL);
            register_code(KC_LEFT);
            unregister_code(KC_LEFT);
            unregister_code(KC_LCTRL);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
        }
        SEQ_ONE_KEY(KC_RIGHT)
        {//select right ; alt-shift-control-right
            register_code(KC_RALT);
            register_code(KC_RSFT);
            register_code(KC_LCTRL);
            register_code(KC_RIGHT);
            unregister_code(KC_RIGHT);
            unregister_code(KC_LCTRL);
            unregister_code(KC_RSFT);
            unregister_code(KC_RALT);
        }

        /* * * * * * * * * * * * * * * */
        /* tmux settings */

        //tmux go left ctr-b + left
        SEQ_ONE_KEY(KC_H)
        {
            register_mods(KC_LCTL);
            register_code(KC_B);

            unregister_code(KC_B);
            unregister_mods(KC_LCTL);

            clear_keyboard();
            _delay_ms(100);

            register_code(KC_LEFT);
            unregister_code(KC_LEFT);
        }

        //tmux go down  ctr-b + down
        SEQ_ONE_KEY(KC_J)
        {
            register_mods(KC_LCTL);
            register_code(KC_B);

            unregister_code(KC_B);
            unregister_mods(KC_LCTL);

            register_code(KC_DOWN);
            unregister_code(KC_DOWN);
        }

        //tmux go up  ctr-b + up
        SEQ_ONE_KEY(KC_K)
        {
            register_mods(KC_LCTL);
            register_code(KC_B);

            unregister_code(KC_B);
            unregister_mods(KC_LCTL);

            register_code(KC_UP);
            unregister_code(KC_UP);
        }

        //tmux go right
        SEQ_ONE_KEY(KC_L)
        {
            register_mods(KC_LCTL);
            register_code(KC_B);

            unregister_code(KC_B);
            unregister_mods(KC_LCTL);

            register_code(KC_RIGHT);
            unregister_code(KC_RIGHT);
        }

        /* coding */
        SEQ_ONE_KEY(KC_M){SEND_STRING("// #mark - label\n");}

        SEQ_TWO_KEYS(KC_T, KC_C){SEND_STRING("thomas.cherry@gmail.com");}

        /** command s */
        /*SEQ_THREE_KEYS(KC_S, KC_D, KC_F)
        {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_S);
            unregister_code(KC_LGUI);
        }*/
        /*SEQ_THREE_KEYS(KC_, KC_D, KC_F) {register_code();}*/

        SEQ_ONE_KEY(KC_C){SEND_STRING("/* ********** */");}
        SEQ_TWO_KEYS(KC_C, KC_C){SEND_STRING("/* ********** ********** */");}
        SEQ_THREE_KEYS(KC_C, KC_C, KC_C)
        {
            SEND_STRING("/* ********** ********** ********** ********** */");
        }
        SEQ_ONE_KEY(KC_S){SEND_STRING("step\nlist");}
        SEQ_ONE_KEY(KC_N){SEND_STRING("next\nlist");}
        SEQ_ONE_KEY(KC_T){SEND_STRING("continue");}
    }
}

/**
This is not really used unless macros are working
*/
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
    PLAY_SONG(tone_startup);
    //PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    //PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
    //PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
