#include <Keypad.h>
#include "parameters.h"
#include "phone.h"

bool onHookChk(Phone ph);
void myKeyPadListener(Phone ph, KeypadEvent key);

void setup() {
  Serial.begin(9600);

  for(int i=0; i< PHONE_COUNT;i++){
    pinMode(p[i].hook,INPUT_PULLUP);
  }

  p[0].kp.addEventListener(P1_KeyPadEvent);  // Add an event listener.
  p[0].kp.setHoldTime(P1_KEYS_HOLD_TIME);               // Default is 1000mS
  p[0].kp.setDebounceTime(P1_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  p[1].kp.addEventListener(P2_KeyPadEvent);  // Add an event listener.
  p[1].kp.setHoldTime(P2_KEYS_HOLD_TIME);               // Default is 1000mS
  p[1].kp.setDebounceTime(P2_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  p[2].kp.addEventListener(P3_KeyPadEvent);  // Add an event listener.
  p[2].kp.setHoldTime(P3_KEYS_HOLD_TIME);               // Default is 1000mS
  p[2].kp.setDebounceTime(P3_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  p[3].kp.addEventListener(P4_KeyPadEvent);  // Add an event listener.
  p[3].kp.setHoldTime(P4_KEYS_HOLD_TIME);               // Default is 1000mS
  p[3].kp.setDebounceTime(P4_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  p[4].kp.addEventListener(P5_KeyPadEvent);  // Add an event listener.
  p[4].kp.setHoldTime(P5_KEYS_HOLD_TIME);               // Default is 1000mS
  p[4].kp.setDebounceTime(P5_KEYS_DEBOUNCE_TIME);           // Default is 50mS
}


void loop() {
  for(int i=0;i< PHONE_COUNT;i++){
    Phone ph = p[i];
    if(offHookChk(ph)){
      Keypad kp = ph.kp;
      char key = kp.getKey();
      if (!key){
        String msg = String("/phone/");
        msg += ph.id;
        msg += "/nothing/";
      }
    }
    else{
      delay(300/DELAY_COEF);
    }
    delay(100);
  }
  delay(200);
} 

bool offHookChk(Phone ph){
  static bool lastHook;
  bool offHook = !digitalRead(ph.hook);
  digitalWrite(ph.led,offHook);
  if(SHOW_ON_HOOK || (lastHook != offHook)){
    String msg = "/Phone/";
    msg += ph.id;
    msg += "/hook/";
    msg += offHook?"off/":"on/";
    Serial.println(msg);
  }
  else if(offHook){
    String msg = "/Phone/";
    msg += ph.id;
    msg += "/hook/off/";
    Serial.println(msg);
  }
  lastHook = offHook;
  return offHook;
}


 void myKeyPadListener(Phone ph, KeypadEvent key){

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

void P1_KeyPadEvent(KeypadEvent key){
  myKeyPadListener(p[0], key);
}
void P2_KeyPadEvent(KeypadEvent key){
  myKeyPadListener(p[1], key);
}
void P3_KeyPadEvent(KeypadEvent key){
  myKeyPadListener(p[2], key);
}
void P4_KeyPadEvent(KeypadEvent key){
  myKeyPadListener(p[3], key);
}
void P5_KeyPadEvent(KeypadEvent key){
  myKeyPadListener(p[4], key);
}
















