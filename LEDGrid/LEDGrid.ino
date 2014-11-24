#include <Wire.h>
#include "LEDGrid.h"

LEDGrid grid;
int counter = 0;

void allWhite();
void nightMode();
void chillMode();
void animation1();
void animation2();
void animation3();

void setup() {
  Serial.begin(9600);
}

void loop() { 
  chillMode();
  
//  for (int i = 0; i < 3; i++) {
//    while(counter < 15) {
//      if (i == 0) {
//        animation1(); 
//      } else if (i == 1) {
//        animation2();
//      } else {
//        animation3(); 
//      }
//      counter++; 
//    }
//    counter = 0;
//  }
}

void allWhite() {
  grid.clear();
  for (int i = 0; i < 8; i++) {
    grid.set(i, 4095, 4095, 4095);
  }
  grid.update();
}

void nightMode() {
  grid.clear();
  
  
  Tlc.set(0, 500);
  Tlc.set(3, 500);
  Tlc.set(6, 1000);
  Tlc.set(9, 500);
  Tlc.set(12, 500);
  Tlc.set(15, 500);
  Tlc.set(18, 1000);
  Tlc.set(21, 500);
  Tlc.update();
}

void chillMode() {
  Tlc.clear();
  Tlc.set(0, 1000);
  Tlc.set(2, 2000);
  Tlc.set(5, 2200);
  Tlc.set(6, 2000);
  Tlc.set(8, 1000);
  Tlc.set(11, 2200);
  Tlc.set(12, 1000);
  Tlc.set(14, 2000);
  Tlc.set(17, 2200);
  Tlc.set(18, 2000);
  Tlc.set(20, 1000);
  Tlc.set(23, 2200);
  Tlc.update();
}

void animation1() {
  int time = 200;
  for (int i = 0; i < 15; i+=3) {
    if (i != 0) {
      Tlc.set(i-3, 0);
    }
    Tlc.set(i, 4095);
    delay(time);
    Tlc.update();
  }
  Tlc.set(12, 0);
  Tlc.set(15, 4095);
  Tlc.set(16, 0);
  Tlc.set(17, 0);
  Tlc.set(18, 4095);
  Tlc.set(19, 0);
  Tlc.set(20, 0);
  Tlc.set(21, 4095);
  Tlc.set(22, 0);
  Tlc.set(23, 0);
  Tlc.update();
  for (int i = 1; i < 15; i+=3) {
    if (i != 1) {
      Tlc.set(i-3, 0);
    }
    Tlc.set(i, 4095);
    delay(time);
    Tlc.update();
  }
  Tlc.set(13, 0);
  Tlc.set(15, 0);
  Tlc.set(16, 4095);
  Tlc.set(17, 0);
  Tlc.set(18, 0);
  Tlc.set(19, 4095);
  Tlc.set(20, 0);
  Tlc.set(21, 0);
  Tlc.set(22, 4095);
  Tlc.set(23, 0);
  Tlc.update();
  for (int i = 2; i < 15; i+=3) {
    if (i != 2) {
      Tlc.set(i-3, 0);
    }
    Tlc.set(i, 4095);
    delay(time);
    Tlc.update();
  }
  Tlc.set(14, 0);
  Tlc.set(15, 0);
  Tlc.set(16, 0);
  Tlc.set(17, 4095);
  Tlc.set(18, 0);
  Tlc.set(19, 0);
  Tlc.set(20, 4095);
  Tlc.set(21, 0);
  Tlc.set(22, 0);
  Tlc.set(23, 4095);
  Tlc.update();
}

void animation2() {
  for (int offset = 0; offset < 3; offset++) {
    for (int i = 0; i < 4096; i+=5) {
      Tlc.set(15, i);
      Tlc.set(16, i);
      Tlc.set(17, i);
      Tlc.set(18, i);
      Tlc.set(19, i);
      Tlc.set(20, i);
      Tlc.set(21, i);
      Tlc.set(22, i);
      Tlc.set(23, i);
      delay(1);
      Tlc.update();
    } 
    
    Tlc.clear();
    Tlc.set(0 + offset, 0);
    Tlc.set(3 + offset, 0);
    Tlc.set(6 + offset, 4095);
    Tlc.set(9 + offset, 0);
    Tlc.set(12 + offset, 0);
    Tlc.update();
    
    for (int i = 4095; i > 0; i-=5) {
      Tlc.set(15, i);
      Tlc.set(16, i);
      Tlc.set(17, i);
      Tlc.set(18, i);
      Tlc.set(19, i);
      Tlc.set(20, i);
      Tlc.set(21, i);
      Tlc.set(22, i);
      Tlc.set(23, i);
      delay(1);
      Tlc.update();
    } 
    
    
    for (int i = 0; i < 4096; i+=5) {
      Tlc.set(15, i);
      Tlc.set(16, i);
      Tlc.set(17, i);
      Tlc.set(18, i);
      Tlc.set(19, i);
      Tlc.set(20, i);
      Tlc.set(21, i);
      Tlc.set(22, i);
      Tlc.set(23, i);
      delay(1);
      Tlc.update();
    } 
    
    Tlc.clear();
    Tlc.set(0 + offset, 0);
    Tlc.set(3 + offset, 4095);
    Tlc.set(6 + offset, 0);
    Tlc.set(9 + offset, 4095);
    Tlc.set(12 + offset, 0);
    Tlc.update();
    
    for (int i = 4095; i > 0; i-=5) {
      Tlc.set(15, i);
      Tlc.set(16, i);
      Tlc.set(17, i);
      Tlc.set(18, i);
      Tlc.set(19, i);
      Tlc.set(20, i);
      Tlc.set(21, i);
      Tlc.set(22, i);
      Tlc.set(23, i);
      delay(1);
      Tlc.update();
    } 
    
    
    for (int i = 0; i < 4096; i+=5) {
      Tlc.set(15, i);
      Tlc.set(16, i);
      Tlc.set(17, i);
      Tlc.set(18, i);
      Tlc.set(19, i);
      Tlc.set(20, i);
      Tlc.set(21, i);
      Tlc.set(22, i);
      Tlc.set(23, i);
      delay(1);
      Tlc.update();
    } 
    
    Tlc.clear();
    Tlc.set(0 + offset, 4095);
    Tlc.set(3 + offset, 0);
    Tlc.set(6 + offset, 0);
    Tlc.set(9 + offset, 0);
    Tlc.set(12 + offset, 4095);
    Tlc.update();
    
    for (int i = 4095; i > 0; i-=5) {
      Tlc.set(15, i);
      Tlc.set(16, i);
      Tlc.set(17, i);
      Tlc.set(18, i);
      Tlc.set(19, i);
      Tlc.set(20, i);
      Tlc.set(21, i);
      Tlc.set(22, i);
      Tlc.set(23, i);
      delay(1);
      Tlc.update();
    } 
  }
}

void animation3() {
  int time = 300;
  for (int offset = 0; offset < 3; offset++) {
    Tlc.clear();
    Tlc.set(0 + offset, 0);
    Tlc.set(3 + offset, 0);
    Tlc.set(6 + offset, 4095);
    Tlc.set(9 + offset, 0);
    Tlc.set(12 + offset, 0);
    Tlc.set(15 + offset, 0);
    Tlc.set(18 + offset, 4095);
    Tlc.set(21 + offset, 0);
    Tlc.update();
    delay(time);
    
    Tlc.clear();
    Tlc.set(0 + offset, 0);
    Tlc.set(3 + offset, 4095);
    Tlc.set(6 + offset, 0);
    Tlc.set(9 + offset, 4095);
    Tlc.set(12 + offset, 0);
    Tlc.set(15 + offset, 4095);
    Tlc.set(18 + offset, 0);
    Tlc.set(21 + offset, 4095);
    Tlc.update();
    delay(time);
  }
}
