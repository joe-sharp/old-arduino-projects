/*
 * This project was designed to "watch" for the power signal
 * from a Comcast "universal" remote. When seen it sends the
 * IR signal to power on my sound bar. It's ugly but it worked.
 *
 * Based on IRRecord
 * Version 0.11 September, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * Copyright 2018 Joe Sharp
 */

#include <IRremote.h>

int RECV_PIN = 6;
int BUTTON_PIN = 9;
int STATUS_PIN = 3;

IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(STATUS_PIN, OUTPUT);
}

bool powerPressed = false;
// Storage for the recorded code
int codeType = -1; // The type of code
unsigned long codeValue; // The code value if not raw
unsigned int rawCodes[RAWBUF]; // The durations if raw
int codeLen; // The length of the code
int toggle = 0; // The RC5/6 toggle state

// Stores the code for later playback
// Most of this code is just logging
///// I edited this to just hardcode the 4 different power codes the Comcast remote would send. - js
bool storeCode(decode_results *results) {
  codeType = results->decode_type;
  int count = results->rawlen;
  codeValue = results->value;
  codeLen = results->bits;
  Serial.println(codeValue, HEX);
  if (codeValue == 0x1000C || codeValue == 0xBBE98CC8 || codeValue == 0x104C7 || codeValue == 0x4C7) {
    Serial.println("Power ON/OFF Seen!");
    return true;
  }
  return false;
}

void sendCode(bool repeat) {
  codeValue = 0x150C;
  Serial.print(toggle);
  Serial.print(repeat);
  if (!repeat) {
    // Flip the toggle bit for a new button press
    toggle = 1 - toggle;
  }
  Serial.print(toggle);
  if (!toggle) {
    codeValue = 0x1150C;
  }
  irsend.sendRC6(codeValue, codeLen);
  Serial.print("Sent RC6 ");
  Serial.println(codeValue, HEX);
}

void loop() {
  if (irrecv.decode(&results)) {
    digitalWrite(STATUS_PIN, HIGH);
    powerPressed = storeCode(&results);
    irrecv.resume(); // resume receiver
    digitalWrite(STATUS_PIN, LOW);
    delay(500); // Wait a bit between retransmissions
  }

  if (powerPressed) {
    Serial.println("Pressed, sending");
    digitalWrite(STATUS_PIN, HIGH);
    sendCode(false);
    digitalWrite(STATUS_PIN, LOW);
    delay(100); // Wait a bit between retransmissions
    digitalWrite(STATUS_PIN, HIGH);
    sendCode(true);
    digitalWrite(STATUS_PIN, LOW);
    delay(100); // Wait a bit between retransmissions
    digitalWrite(STATUS_PIN, HIGH);
    sendCode(true);
    digitalWrite(STATUS_PIN, LOW);
    delay(500); // Wait a bit between retransmissions
    powerPressed = false;
    irrecv.enableIRIn();
    //irrecv.resume(); // resume receiver
  }
}
