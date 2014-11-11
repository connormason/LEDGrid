// I2C Signals
//   signal = 0 --> all white
//   signal = 1 --> night mode (dim red)
//   signal = 2 --> party mode (various animations)

#include <Wire.h>
#include "Tlc5940.h"

int curMode;
int signal;

//void recieveEvent(int howMany) {
//  signal = Wire.read();
//}

void allWhite();
void nightMode();
void animation1();

void setup() {
//  Wire.begin(9);
//  Wire.onReceive(receiveEvent);
  Tlc.init();
  Serial.begin(9600);
  signal = 0;
}

void loop() { 
  if (signal == 2) {
    Serial.print("Party lighting");
    animation1();
  } else if (signal == 1) {
    Serial.print("Night mode");
    nightMode();
  } else if (signal == 0) {
    Serial.print("Normal lighting");
    allWhite();
  } else {
    Serial.print("Error, incorrect signal received");
  }
}

void allWhite() {
  Tlc.clear();
  for (int i = 0; i < 24; i++) {
    Tlc.set(i, 4095);
    Tlc.update();
  }
}

void nightMode() {
  Tlc.clear();
  for (int i = 0; i < 24; i+=3) {
    Tlc.set(i, 4095);
    Tlc.update();
  }
}

void animation1() {
  Tlc.clear();
  for(int i = 0; i < 2000; i+=4){
    Tlc.set(0, i);
    Tlc.set(3, i);
    Tlc.set(6, i);
    Tlc.set(9, i);
    Tlc.set(12, i);
    Tlc.update();
    delay(1);
  }
  for(int i = 2000; i > 0; i-=4){
    Tlc.set(1, i);
    Tlc.set(4, i);
    Tlc.set(7, i);
    Tlc.set(10, i);
    Tlc.set(13, i);
    Tlc.update();
    delay(1);
  }
  for(int i = 0; i < 1500; i+=2){
    Tlc.set(0, i);
    Tlc.set(1, i);
    Tlc.set(2, i);
    Tlc.set(3, i);
    Tlc.set(4, i);
    Tlc.set(5, i);
    Tlc.set(6, i);
    Tlc.set(7, i);
    Tlc.set(8, i);
    Tlc.set(9, i);
    Tlc.set(10, i);
    Tlc.set(11, i);
    Tlc.set(12, i);
    Tlc.set(13, i);
    Tlc.set(14, i);
    Tlc.update();
    delay(1);
  }
  Tlc.clear();
  for(int i = 2000; i > 0; i-=4){
    Tlc.set(2, i);
    Tlc.set(4, i);
    Tlc.set(6, i);
    Tlc.set(10, i);
    Tlc.set(14, i);
    Tlc.update();
    delay(1);
  }
}

