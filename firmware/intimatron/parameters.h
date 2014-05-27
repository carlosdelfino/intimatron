#ifndef PARAMETERS_INTIMATRON
#define PARAMETERS_INTIMATRON

#include "Arduino.h"
#include <variant.h>
#include <Keypad.h>


#define DELAY_COEF .1
#define DELAY_ONHOOK 300
#define DELAY_INTERPHONE 100
#define DELAY_LOOP 100

#define DELAY_KEY_NOTHING 400

#define DELAY_TIME_MSG 1500

#define DELAY_SHOW_OFFHOOK_EVENTS 1000

#define DEFAULT_KEY_HOLD_TIME 500
#define DEFAULT_KEY_DEBOUNCE_TIME 250


#define SHOW_KEY_EVENTS true
#define SHOW_ON_HOOK_EVENTS true


#define KEY_ROWS 4
#define KEY_COLS 4
char KEYS[KEY_ROWS][KEY_COLS] = {
 {'1', '2', '3','A'},
 {'4', '5', '6','B'},
 {'7', '8', '9','C'},
 {'*', '0', '#','D'}
};

char* KEYS_MAP = makeKeymap(KEYS);


/************************
 ************************
 *
 * TELEFONE 1
 *
 ************************
 ************************/

// ** Teclado T1 **
#define P1_KC3 27
#define P1_KC2 29
#define P1_KC1 31
#define P1_KC4 33
#define P1_KR1 35 
#define P1_KR2 37
#define P1_KR3 39
#define P1_KR4 41

byte P1_ROW_PINS[KEY_ROWS] = {P1_KR1, P1_KR2, P1_KR3, P1_KR4}; //connect to the row pinouts of the keypad
byte P1_COL_PINS[KEY_COLS] = {P1_KC1, P1_KC2, P1_KC3, P1_KC4}; //connect to the column pinouts of the keypad

#define P1_KEYS_HOLD_TIME 500
#define P1_KEYS_DEBOUNCE_TIME 250
// ** Gancho T1 **
#define P1_HOOK 25
// ** Led Display T1 **
#define P1_DISP 23


/************************
 ************************
 *
 * TELEFONE 2
 *
 ************************
 ************************/

// ** Teclado T2 **
#define P2_KC3  47
#define P2_KC2  49
#define P2_KC1  51
#define P2_KC4  53
#if defined(__SAM3U4E__) || defined(__SAM3X8E__) || defined(__SAM3X8H__)
#define P2_KR1 DAC0
#define P2_KR2 DAC1
#define P2_KR4 CANRX
#define P2_KR3 CANTX
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__)
#define P2_KR1 A12
#define P2_KR2 A13
#define P2_KR4 A14
#define P2_KR3 A15
#else
#error "Este Firmware somente funciona com Arduino Mega e Arduino DUE"
#endif

byte P2_ROW_PINS[KEY_ROWS] = {P2_KR1, P2_KR2, P2_KR3, P2_KR4}; //connect to the row pinouts of the keypad
byte P2_COL_PINS[KEY_COLS] = {P2_KC1, P2_KC2, P2_KC3, P2_KC4}; //connect to the column pinouts of the keypad

#define P2_KEYS_HOLD_TIME 500
#define P2_KEYS_DEBOUNCE_TIME 250

// ** Gancho T2 **
#define P2_HOOK  45
// ** Led Display T2 **
#define P2_DISP  43

/************************
 ************************
 *
 * TELEFONE 3
 *
 ************************
 ************************/

// ** Teclado T3 **
#define P3_KC3 A8
#define P3_KC2 A9
#define P3_KC1 A10
#define P3_KC4 A11
#define P3_KR1  52
#define P3_KR2  50
#define P3_KR3  48
#define P3_KR4  46

byte P3_ROW_PINS[KEY_ROWS] = {P3_KR1, P3_KR2, P3_KR3, P3_KR4}; //connect to the row pinouts of the keypad
byte P3_COL_PINS[KEY_COLS] = {P3_KC1, P3_KC2, P3_KC3, P3_KC4}; //connect to the column pinouts of the keypad

#define P3_KEYS_HOLD_TIME 500
#define P3_KEYS_DEBOUNCE_TIME 250

// ** Gancho T3 **
#define P3_HOOK A7
// ** Led Display T3 **
#define P3_DISP A6

/************************
 ************************
 *
 * TELEFONE 4
 *
 ************************
 ************************/

// ** Teclado T4 **
#define P4_KC3  40
#define P4_KC2  38
#define P4_KC1  36
#define P4_KC4  34
#define P4_KR1  32
#define P4_KR2  30
#define P4_KR3  28
#define P4_KR4  26

byte P4_ROW_PINS[KEY_ROWS] = {P4_KR1, P4_KR2, P4_KR3, P4_KR4}; //connect to the row pinouts of the keypad
byte P4_COL_PINS[KEY_COLS] = {P4_KC1, P4_KC2, P4_KC3, P4_KC4}; //connect to the column pinouts of the keypad

#define P4_KEYS_HOLD_TIME 500
#define P4_KEYS_DEBOUNCE_TIME 250

// ** Gancho T4 **
#define P4_HOOK 42
// ** Led Display T5 **
#define P4_DISP 44



/************************
 ************************
 *
 * TELEFONE 5
 *
 ************************
 ************************/

// ** Teclado T5 **
#define P5_KC3  21
#define P5_KC2  20
#define P5_KC1  19
#define P5_KC4  18
#define P5_KR1  17
#define P5_KR2  16
#define P5_KR3  15
#define P5_KR4  14

byte P5_ROW_PINS[KEY_ROWS] = {P5_KR1, P5_KR2, P5_KR3, P5_KR4}; //connect to the row pinouts of the keypad
byte P5_COL_PINS[KEY_COLS] = {P5_KC1, P5_KC2, P5_KC3, P5_KC4}; //connect to the column pinouts of the keypad

#define P5_KEYS_HOLD_TIME 1000
#define P5_KEYS_DEBOUNCE_TIME 250

// ** Gancho T5 **
#define P5_HOOK 22
// ** Led Display T5 **
#define P5_DISP 24

#endif
