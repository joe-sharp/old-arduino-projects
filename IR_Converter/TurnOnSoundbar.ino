/*
 * Quick code to test sending IR power signals to my sound bar.
 *
 * Based on IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * Copyright 2018 Joe Sharp
 */


#include <IRremote.h>

IRsend irsend;

void setup()
{
}

void loop() {
	for (int i = 0; i < 3; i++) {
		irsend.sendRC6(0x150C, 20);
		delay(100);
	}
	delay(5000); //5 second delay between each signal burst
}
