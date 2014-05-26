#ifndef phone_h
#define phone_h

#include "Keypad.h"
#include "parameters.h"

#define PHONE_COUNT 5
 
struct Phone_t{
  byte id;
  Keypad kp;
  byte hook;
  byte led; 
}  
p[PHONE_COUNT] = {
  {
    1, Keypad( KEYS_MAP, P1_ROW_PINS, P1_COL_PINS, KEY_ROWS, KEY_COLS ), P1_HOOK, P1_DISP}
  ,
  {
    2, Keypad( KEYS_MAP, P2_ROW_PINS, P2_COL_PINS, KEY_ROWS, KEY_COLS ), P2_HOOK, P2_DISP}
  ,
  {
    3, Keypad( KEYS_MAP, P3_ROW_PINS, P3_COL_PINS, KEY_ROWS, KEY_COLS ), P3_HOOK, P3_DISP}
  ,
  {
    4, Keypad( KEYS_MAP, P4_ROW_PINS, P4_COL_PINS, KEY_ROWS, KEY_COLS ), P4_HOOK, P4_DISP}
  ,
  {
    5, Keypad( KEYS_MAP, P5_ROW_PINS, P5_COL_PINS, KEY_ROWS, KEY_COLS ), P5_HOOK, P5_DISP}
};

typedef Phone_t Phone;

#endif



