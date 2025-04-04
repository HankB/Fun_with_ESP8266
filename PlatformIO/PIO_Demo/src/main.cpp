#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  // Set software serial baud to 115200;
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  int counter = 0;
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, LOW);            // turn the LED on
  delay(20);                                 // wait 20 ms ...
  digitalWrite(LED_BUILTIN, _QUAD_HIGHWORD); // turn the LED off
  delay(230);                                // wait 230 ms (blink @ 4Hz)
  if (counter++ > 10)
  {
    Serial.println("hello world");
    counter = 0;
  }
}