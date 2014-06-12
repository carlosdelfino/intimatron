#include <Keypad.h>
#include "parameters.h"
#include "phone.h"

bool onHookChk(Phone ph);
void myKeyPadListener(Phone ph, KeypadEvent key);

static bool lastHook[PHONE_COUNT];

void setup() {
  Serial.begin(9600);
  
  while (!Serial); // para analise da real necessidade, na pratica a ausencia nao interferil em nada ate o momento

  Serial.println("/init/begin/");

  for (int i = 0; i < PHONE_COUNT; i++) {
    pinMode(p[i].hook, INPUT_PULLUP);
    lastHook[i] = true;
  }
  
  Serial.println("/init/ports/ok/");

  p[0].kp.addEventListener(P0_KeyPadEvent);  // Add an event listener.
  p[0].kp.setHoldTime(P0_KEYS_HOLD_TIME);               // Default is 1000mS
  p[0].kp.setDebounceTime(P0_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  Serial.println("/init/phone/0/keypad/ok/");

  p[1].kp.addEventListener(P1_KeyPadEvent);  // Add an event listener.
  p[1].kp.setHoldTime(P1_KEYS_HOLD_TIME);               // Default is 1000mS
  p[1].kp.setDebounceTime(P1_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  Serial.println("/init/phone/1/keypad/ok/");

  p[2].kp.addEventListener(P2_KeyPadEvent);  // Add an event listener.
  p[2].kp.setHoldTime(P2_KEYS_HOLD_TIME);               // Default is 1000mS
  p[2].kp.setDebounceTime(P2_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  Serial.println("/init/phone/2/keypad/ok/");

  p[3].kp.addEventListener(P3_KeyPadEvent);  // Add an event listener.
  p[3].kp.setHoldTime(P3_KEYS_HOLD_TIME);               // Default is 1000mS
  p[3].kp.setDebounceTime(P3_KEYS_DEBOUNCE_TIME);           // Default is 50mS

  Serial.println("/init/phone/3/keypad/ok/");

  p[4].kp.addEventListener(P4_KeyPadEvent);  // Add an event listener.
  p[4].kp.setHoldTime(P4_KEYS_HOLD_TIME);               // Default is 1000mS
  p[4].kp.setDebounceTime(P4_KEYS_DEBOUNCE_TIME);           // Default is 50mS
  
  Serial.println("/init/phone/4P0_/keypad/ok/");

  Serial.println("/init/ok/");
}

void loop() {
  static long lastKeyTime;
  static  long lastTimeMsg;
  
  for (int i = 0; i < PHONE_COUNT; i++) {
    Phone ph = p[i];
    if (offHookChk(ph)) {
      char key = p[i].kp.getKey();
      long keyTime = millis();
      if (!key && lastKeyTime - keyTime > DELAY_KEY_NOTHING){
        String msg = String("/phone/");
        msg += ph.id;
        msg += "/nothing/";
        Serial.println(msg);
        lastKeyTime = keyTime;
      }
    } else {
      delay(DELAY_ONHOOK * DELAY_COEF);
    }
    delay(DELAY_INTERPHONE * DELAY_COEF);
  }
  long timeMsg = millis();
  if (timeMsg - lastTimeMsg > DELAY_TIME_MSG) {
    String msg = String("/millis/");
    msg += timeMsg;
    msg += "/";
    lastTimeMsg = timeMsg;
    Serial.println(msg);
  }
  delay(DELAY_LOOP * DELAY_COEF);
}

bool offHookChk(Phone ph) {

  static long lastTimeHook[PHONE_COUNT];
  bool offHook = digitalRead(ph.hook);
  digitalWrite(ph.led, !offHook);
  byte idx = ph.id;
  
  long timeHook = millis();
  
  if ( (lastTimeHook[idx] - timeHook > DELAY_SHOW_OFFHOOK_EVENTS) || (lastHook[idx] != offHook)) {
    String msg = "/Phone/";
    msg += ph.id;
    msg += "/hook/";
    msg += offHook ? "off/" : "on/";
    Serial.println(msg);
  }
  lastHook[idx] = offHook;
  lastTimeHook[idx] = timeHook;
  
  return offHook;
}


void myKeyPadListener(Phone_t ph, KeypadEvent key) {

  byte phoneId = ph.id;
  Keypad kp = ph.kp;

  byte state = kp.getState();

  String msg;
  if (SHOW_KEY_ALL_EVENTS) {

    msg = String("/phone/");
    msg += phoneId;
    msg += "/key/";
    msg += key;
    msg += "/event/";
    switch (state) {
      case PRESSED:
        msg += "PRESSED";
        break;
      case RELEASED:
        msg += "RELEASED";
        break;
      case HOLD:
        msg += "HOLD";
        break;
      case IDLE:
        msg += "IDLE";
        break;
      default:
        msg += state;
    }
    msg += "/";
    Serial.println(msg);
  } else{
    switch (state) {
      case PRESSED:
        msg = String("/phone/");
        msg += ph.id;
        msg += "/key/";
        msg += (char)key;
        msg += "/";
        Serial.println(msg);
    }
  } 
}

void P0_KeyPadEvent(KeypadEvent key) {
  myKeyPadListener(p[0], key);
}
void P1_KeyPadEvent(KeypadEvent key) {
  myKeyPadListener(p[1], key);
}
void P2_KeyPadEvent(KeypadEvent key) {
  myKeyPadListener(p[2], key);
}
void P3_KeyPadEvent(KeypadEvent key) {
  myKeyPadListener(p[3], key);
}
void P4_KeyPadEvent(KeypadEvent key) {
  myKeyPadListener(p[4], key);
}
