#ifndef PARAMETERS_INTIMATRON
#define PARAMETERS_INTIMATRON

#include "Arduino.h"
#include <Keypad.h">

#define SHOW_EVENTS true

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

// ** Teclado T2 **
#define T1_KC1 27
#define T1_KC2 29
#define T1_KC3 31
#define T1_KC4 33
#define T1_KL1 35 
#define T1_KL2 37
#define T1_KL3 39
#define T1_KL4 41

byte T1_ROW_PINS[KEY_ROWS] = {T1_KL1, T1_KL2, T1_KL3, T1_KL4}; //connect to the row pinouts of the keypad
byte T1_COL_PINS[KEY_COLS] = {T1_KC1, T1_KC2, T1_KC3, T1_KC4}; //connect to the column pinouts of the keypad

#define T1_KEYS_HOLD_TIME 500
#define T1_KEYS_DEBOUNCE_TIME 250

// ** KeyBoard Map **
//char T1_KEYS[KEY_ROWS][KEY_COLS][] ={
//   {"/phone/1/key/1", "/phone/1/key/2", "/phone/1/key/3", "/phone/1/key/A"},
//   {"/phone/1/key/1", "/phone/1/key/1", "/phone/1/key/6", "/phone/1/key/B"},
//   {"/phone/1/key/1", "/phone/1/key/1", "/phone/1/key/9", "/phone/1/key/C"},
//   {"/phone/1/key/*", "/phone/1/key/0", "/phone/1/key/#", "/phone/1/key/D"},
//} 

// ** Gancho T2 **
#define T1_HOOK 25
// ** Led Display T2 **
#define T1_DISP 23


/************************
 ************************
 *
 * TELEFONE 2
 *
 ************************
 ************************/

// ** Teclado T2 **
#define T2_KC1  47
#define T2_KC2  49
#define T2_KC3  51
#define T2_KC4  53
#define T2_KL1 A12
#define T2_KL2 A13
#define T2_KL3 A15
#define T2_KL4 A14

byte T2_ROW_PINS[KEY_ROWS] = {T2_KL1, T2_KL2, T2_KL3, T2_KL4}; //connect to the row pinouts of the keypad
byte T2_COL_PINS[KEY_COLS] = {T2_KC1, T2_KC2, T2_KC3, T2_KC4}; //connect to the column pinouts of the keypad

#define T2_KEYS_HOLD_TIME 500
#define T2_KEYS_DEBOUNCE_TIME 250

// ** Gancho T2 **
#define T2_HOOK  45
// ** Led Display T2 **
#define T2_DISP  43

/************************
 ************************
 *
 * TELEFONE 3
 *
 ************************
 ************************/

// ** Teclado T3 **
#define T3_KC1 A8
#define T3_KC2 A9
#define T3_KC3 A10
#define T3_KC4 A11
#define T3_KL1  52
#define T3_KL2  50
#define T3_KL3  48
#define T3_KL4  46

byte T3_ROW_PINS[KEY_ROWS] = {T3_KL1, T3_KL2, T3_KL3, T3_KL4}; //connect to the row pinouts of the keypad
byte T3_COL_PINS[KEY_COLS] = {T3_KC1, T3_KC2, T3_KC3, T3_KC4}; //connect to the column pinouts of the keypad

#define T3_KEYS_HOLD_TIME 500
#define T3_KEYS_DEBOUNCE_TIME 250

// ** Gancho T3 **
#define T3_HOOK A7
// ** Led Display T3 **
#define T3_DISP A6

/************************
 ************************
 *
 * TELEFONE 4
 *
 ************************
 ************************/

// ** Teclado T4 **
#define T4_KC1  40
#define T4_KC2  38
#define T4_KC3  36
#define T4_KC4  34
#define T4_KL1  32
#define T4_KL2  30
#define T4_KL3  28
#define T4_KL4  26

byte T4_ROW_PINS[KEY_ROWS] = {T4_KL1, T4_KL2, T4_KL3, T4_KL4}; //connect to the row pinouts of the keypad
byte T4_COL_PINS[KEY_COLS] = {T4_KC1, T4_KC2, T4_KC3, T4_KC4}; //connect to the column pinouts of the keypad

#define T4_KEYS_HOLD_TIME 500
#define T4_KEYS_DEBOUNCE_TIME 250

// ** Gancho T4 **
#define T4_HOOK 42
// ** Led Display T5 **
#define T4_DISP 44



/************************
 ************************
 *
 * TELEFONE 5
 *
 ************************
 ************************/

// ** Teclado T5 **
#define T5_KC1  21
#define T5_KC2  20
#define T5_KC3  19
#define T5_KC4  18
#define T5_KL1  17
#define T5_KL2  16
#define T5_KL3  15
#define T5_KL4  14

byte T5_ROW_PINS[KEY_ROWS] = {T5_KL1, T5_KL2, T5_KL3, T5_KL4}; //connect to the row pinouts of the keypad
byte T5_COL_PINS[KEY_COLS] = {T5_KC1, T5_KC2, T5_KC3, T5_KC4}; //connect to the column pinouts of the keypad

#define T5_KEYS_HOLD_TIME 500
#define T5_KEYS_DEBOUNCE_TIME 250

// ** Gancho T5 **
#define T5_HOOK 22
// ** Led Display T5 **
#define T5_DISP 24

#endif
