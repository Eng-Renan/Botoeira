#include "Wire.h"
byte ler();
byte l=0;
void setup() {
  Serial.begin(9600);
  Wire.begin();                     // wake up I2C Bus
  Wire.beginTransmission(0x20);     // MCP23017 Address
  Wire.write(0x00);                 // IODIRA register
  Wire.write(0x01);                 // set all port A to output
  Wire.endTransmission();

  Wire.beginTransmission(0x20);     // MCP23017 Address
  Wire.write(0x01);                 // IODIRB register
  Wire.write(0x00);                 // set all port B to output
  Wire.endTransmission();
  pinMode(3,OUTPUT);
}

// Function for Port A LED ON/OFF
void ledBlinkPortA(byte a)
{
  Wire.beginTransmission(0x20);
  Wire.write(0x12);                 // address bank A
  Wire.write(a);
  Wire.endTransmission();
  delay(100);
}

// Function for Port B LED ON/OFF
void ledBlinkPortB(byte a)
{
  Wire.beginTransmission(0x20);
  Wire.write(0x13);                 // address bank B
  Wire.write(a);
  Wire.endTransmission();
  delay(100);
}
byte ler(){
  byte i=0;
  Wire.beginTransmission(0x20);
  Wire.write(0x12);
  i= Wire.read();
  Wire.endTransmission();
  Serial.println(i);
  return i;
}

void loop() {
  l=ler();
  digitalWrite(3, bitRead(l,0));
  delay(500);
  ledBlinkPortB((byte)0xfe);        // LED9 ON
  ledBlinkPortB((byte)0xfd);        // LED10 ON
  ledBlinkPortB((byte)0xfb);        // LED11 ON
  ledBlinkPortB((byte)0xf7);        // LED12 ON
  ledBlinkPortB((byte)0xef);        // LED13 ON
  ledBlinkPortB((byte)0xdf);        // LED14 ON
  ledBlinkPortB((byte)0xbf);        // LED15 ON
  ledBlinkPortB((byte)0x7f);        // LED16 ON
}
