// SOS Button
const int LED = 13; // LED connected to
                    // digital pin 13
const int BUTTON = 7; // the input pin where the
                      // pushbutton is connected
int val = 0;          // val will be used to store the state
                      // of the input pin
void setup()
{
  pinMode(LED, OUTPUT); // sets the digital
                        // pin as output
  pinMode(BUTTON, INPUT); // and BUTTON is an input
}
// Start Code here:


void loop() 
{
  val = digitalRead(BUTTON); // read input value and store it
  // check whether the input is HIGH (button pressed)
  if (val == HIGH) {
  
  
  digitalWrite(LED, HIGH); // turns the LED on
  delay(200);   // waits for 2 hundred milliseconds
  digitalWrite(LED, LOW); // turns the LED off
  delay(500);   // waits for a second
  digitalWrite(LED, HIGH); // turns the LED on
  delay(200);   // waits for 2 hundred milliseconds
  digitalWrite(LED, LOW); // turns the LED off
  delay(500);   // waits for a second
  digitalWrite(LED, HIGH); // turns the LED on
  delay(200);   // waits for 2 hundred milliseconds
  digitalWrite(LED, LOW); // turns the LED off
  delay(500);   // waits for a second
  digitalWrite(LED, HIGH); // turns the LED on
  delay(1000);   // waits for a second
  digitalWrite(LED, LOW); // turns the LED off
  delay(500);   // waits for a second
  digitalWrite(LED, HIGH); // turns the LED on
  delay(1000);   // waits for a second
  digitalWrite(LED, LOW); // turns the LED off
  delay(500);   // waits for a second
  digitalWrite(LED, HIGH); // turns the LED on
  delay(1000);   // waits for a second
  digitalWrite(LED, LOW); // turns the LED off
  delay(500);   // waits for a second
  digitalWrite(LED, HIGH); // turns the LED on
  delay(200);   // waits for 2 hundred milliseconds
  digitalWrite(LED, LOW); // turns the LED off
  delay(500);   // waits for a second
  digitalWrite(LED, HIGH); // turns the LED on
  delay(200);   // waits for 2 hundred milliseconds
  digitalWrite(LED, LOW); // turns the LED off
  delay(500);   // waits for a second
  digitalWrite(LED, HIGH); // turns the LED on
  delay(200);   // waits for 2 hundred milliseconds
  digitalWrite(LED, LOW); // turns the LED off
  delay(500);   // waits for a second
}
}
