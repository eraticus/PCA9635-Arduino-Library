#include <Wire.h>
#include <PCA9635.h>

const int ADDR = B1010101;

PCA9635 leds = PCA9635(B1010101);

void setup()
{
  Wire.begin();
  leds.begin();
}

void loop()
{
  leds.analogWrite(8, 0);
  leds.analogWrite(9, 0);
  leds.analogWrite(7, 0);
  delay(250);
  leds.analogWrite(8, 64);
  leds.analogWrite(9, 64);
  leds.analogWrite(7, 64);
  delay(250);
  leds.analogWrite(8, 255);
  leds.analogWrite(9, 255);
  leds.analogWrite(7, 255);
  delay(250);
}




