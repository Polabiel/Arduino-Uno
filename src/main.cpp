#include <Arduino.h>

int leds[] = {11, 12, 13};

int milisdelay = 1000;

void turnOnLedAndOff(int led)
{
  digitalWrite(led, HIGH);
  delay(milisdelay);
  digitalWrite(led, LOW);
}
 
void setup()
{
  int lengthLeds = sizeof(leds) / sizeof(int);
  for (int i = 0; i < lengthLeds; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop()
{
  if (Serial.available() > 0)
  {
    Serial.println("Received");
    switch (Serial.read())
    {
    case 'R': // R = Red
      turnOnLedAndOff(leds[0]);
      break;
    case 'G': // G = Green
      turnOnLedAndOff(leds[1]);
      break;
    case 'B': // B = Blue
      turnOnLedAndOff(leds[2]);
      break;
    }
  }
  Serial.println("Waiting");
}
