#include <Wire.h>
#include <PCA9635.h>

const int ADDR = B0101010;

PCA9635 leds = PCA9635(ADDR);

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  int ret = leds.begin();
  Serial.println(ret);
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  leds.analogWrite(8, 0);
  leds.analogWrite(9, 0);
  leds.analogWrite(7, 0);
  delay(250);
  digitalWrite(13, LOW);
  leds.analogWrite(8, 16);
  leds.analogWrite(9, 16);
  leds.analogWrite(7, 16);
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




