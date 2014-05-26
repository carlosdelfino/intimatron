#include <Keypad.h>
#include "parameters.h"


struct Phone_t{
  byte id;
  Keypad kp;
}  
p[4] = {
  {
    1, Keypad( KEYS_MAP, T1_ROW_PINS, T1_COL_PINS, KEY_ROWS, KEY_COLS )                }
  ,
  {
    2, Keypad( KEYS_MAP, T2_ROW_PINS, T2_COL_PINS, KEY_ROWS, KEY_COLS )                }
  ,
  {
    3, Keypad( KEYS_MAP, T3_ROW_PINS, T3_COL_PINS, KEY_ROWS, KEY_COLS )                }
  ,
  {
    4, Keypad( KEYS_MAP, T4_ROW_PINS, T4_COL_PINS, KEY_ROWS, KEY_COLS )                }
};

void myKeyPadListener(Phone_t ph, KeypadEvent key);

void setup() {
  Serial.begin(9600);

  p[0].kp.addEventListener(T1_KeyPadEvent);  // Add an event listener.
  p[0].kp.setHoldTime(T1_KEYS_HOLD_TIME);               // Default is 1000mS
  p[0].kp.setDebounceTime(T1_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  p[1].kp.addEventListener(T2_KeyPadEvent);  // Add an event listener.
  p[1].kp.setHoldTime(T2_KEYS_HOLD_TIME);               // Default is 1000mS
  p[1].kp.setDebounceTime(T2_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  p[2].kp.addEventListener(T3_KeyPadEvent);  // Add an event listener.
  p[2].kp.setHoldTime(T3_KEYS_HOLD_TIME);               // Default is 1000mS
  p[2].kp.setDebounceTime(T3_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  p[3].kp.addEventListener(T4_KeyPadEvent);  // Add an event listener.
  p[3].kp.setHoldTime(T4_KEYS_HOLD_TIME);               // Default is 1000mS
  p[3].kp.setDebounceTime(T4_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  p[4].kp.addEventListener(T5_KeyPadEvent);  // Add an event listener.
  p[4].kp.setHoldTime(T5_KEYS_HOLD_TIME);               // Default is 1000mS
  p[4].kp.setDebounceTime(T5_KEYS_DEBOUNCE_TIME);           // Default is 50mS
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(int i=0;i<5;i++){
    char key = p[i].kp.getKey();
    if (key) {
      Serial.print("Loop: Key ");
      Serial.println((char)key);
    }
    else{
      Serial.println("/nothing/");
    }
    delay(100);
  }
  delay(300);
} 

void myKeyPadListener(Phone_t ph, KeypadEvent key){

  byte phoneId = ph.id;
  Keypad kp = ph.kp;

  byte state = kp.getState();

  String msg;
  if(SHOW_EVENTS){
    msg = String("/phone/");
    msg+=phoneId;
    msg+="/key/event/";
    switch (state){
    case PRESSED:
      msg+="PRESSED";
      break;
    case RELEASED:
      msg+="RELEASED";
      break;
    case HOLD:
      msg+="HOLD";
      break;
    case IDLE:
      msg+="IDLE";
      break;
    default:
      msg+=state;
    }  
    msg+="/";
    Serial.println(msg);
  }

  switch (state){
  case PRESSED:
    msg = String("/phone/");
    msg+= ph.id;
    msg+="/key/";
    msg+= (char)key;
    msg+="/";
    Serial.println(msg);
  }
}

void T1_KeyPadEvent(KeypadEvent key){
  myKeyPadListener(p[0], key);
}
void T2_KeyPadEvent(KeypadEvent key){
  myKeyPadListener(p[1], key);
}
void T3_KeyPadEvent(KeypadEvent key){
  myKeyPadListener(p[2], key);
}
void T4_KeyPadEvent(KeypadEvent key){
  myKeyPadListener(p[3], key);
}
void T5_KeyPadEvent(KeypadEvent key){
  myKeyPadListener(p[4], key);
}










