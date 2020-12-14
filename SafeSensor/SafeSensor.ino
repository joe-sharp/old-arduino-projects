/*
 *
 * Safe Sensor
 * Copyright 2014 - Joe Sharp
 *
 */
#include <VirtualWire.h>

const int TX_DIO_Pin = 2; //433 MHz Send data
const int LED = 13; // LED connected to digital pin 13
const int REED = 7; // Reed Switch connected to digital pin 7
int rSwitch = 0;          // Default state for Reed Switch
int someData = 1101;    //Default value

void setup()
{
  pinMode(LED, OUTPUT); // sets the digital
                        // pin as output
  pinMode(REED, INPUT); // and BUTTON is an input

  vw_set_tx_pin(TX_DIO_Pin); // Set 433 MHz Pin

  vw_set_ptt_inverted(true); // Set transmit logic level

  vw_setup(2000); // Transmit at 2000 Bps

}

void loop()
{
  byte TxBuffer[2]; // Transmit Buffer
  TxBuffer[0] = someData >> 8;
  TxBuffer[1] = someData;
  rSwitch = digitalRead(REED); // read input value and store it
  // check whether the input is HIGH (switch engaged)
  if (rSwitch == HIGH) {  //if switch is engaged, do nothing
  digitalWrite(LED, LOW); // turns the LED off
} else {
  digitalWrite(LED, HIGH);// turns the LED on
  vw_send((byte *)TxBuffer, 2);//data send
  vw_wait_tx();//wait for send
  digitalWrite(LED, LOW);// turns the LED off
  delay(500);
  }
}
