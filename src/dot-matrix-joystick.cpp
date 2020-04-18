/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/alvarosaburido/as/electronics/electronics-lab/Particle/dot-matrix-joystick/src/dot-matrix-joystick.ino"
#include "Adafruit_LEDBackpack_RK.h"
#include "Adafruit_GFX_RK.h"

float fmap (float value, float fromLow, float fromHigh, float toLow, float toHigh);
void setup();
void loop();
#line 4 "/Users/alvarosaburido/as/electronics/electronics-lab/Particle/dot-matrix-joystick/src/dot-matrix-joystick.ino"
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
const int ADC_MIN = 4;
const int ADC_MAX = 4093;
const int JoyStick_X = A0; //x
const int JoyStick_Y = A1; //y
const int JoyStick_Z = D3; //key

int x = 4;
int y = 4;
int dx;
int dy;
int z = 0;

float fmap (float value, float fromLow, float fromHigh, float toLow, float toHigh) {
  return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600); // 9600 bps
  pinMode(JoyStick_X, INPUT);
  pinMode(JoyStick_Y, INPUT);
  pinMode(JoyStick_Z, INPUT);
  matrix.begin(0x70);  // pass in the address
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  matrix.clear();
  dx=fmap(analogRead(JoyStick_X), ADC_MIN, ADC_MAX, -1, 1);
  dy=fmap(analogRead(JoyStick_Y), ADC_MIN, ADC_MAX, -1, 1);
  z=digitalRead(JoyStick_Z);
  if(x + dx >= 0 && x + dx < 8) {
    x += dx;
  }
  if(y + dy >= 0 && y + dy < 8) {
    y += dy;
  }
  matrix.drawPixel(x,y, LED_ON);
	matrix.writeDisplay();
  Serial.print(x);
  Serial.print('-');
  Serial.print(y);
  Serial.println();
  delay(100);
}
