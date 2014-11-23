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
  allWhite();
  delay(200);
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
  for (int i = 0; i < 24; i++) {
    if ((i % 3) == 0) {
      Tlc.set(i, 0);
    } else {
      Tlc.set(i, 4095);
    }
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

