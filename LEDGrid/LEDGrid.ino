@@ -1,87 +1,329 @@
/*
    Basic Pin setup:
    ------------                                  ---u----
    ARDUINO   13|-> SCLK (pin 25)           OUT1 |1     28| OUT channel 0
              12|                           OUT2 |2     27|-> GND (VPRG)
              11|-> SIN (pin 26)            OUT3 |3     26|-> SIN (pin 11)
              10|-> BLANK (pin 23)          OUT4 |4     25|-> SCLK (pin 13)
               9|-> XLAT (pin 24)             .  |5     24|-> XLAT (pin 9)
               8|                             .  |6     23|-> BLANK (pin 10)
               7|                             .  |7     22|-> GND
               6|                             .  |8     21|-> VCC (+5V)
               5|                             .  |9     20|-> 2K Resistor -> GND
               4|                             .  |10    19|-> +5V (DCPRG)
               3|-> GSCLK (pin 18)            .  |11    18|-> GSCLK (pin 3)
               2|                             .  |12    17|-> SOUT
               1|                             .  |13    16|-> XERR
               0|                           OUT14|14    15| OUT channel 15
    ------------                                  --------

    -  Put the longer leg (anode) of the LEDs in the +5V and the shorter leg
         (cathode) in OUT(0-15).
    -  +5V from Arduino -> TLC pin 21 and 19     (VCC and DCPRG)
    -  GND from Arduino -> TLC pin 22 and 27     (GND and VPRG)
    -  digital 3        -> TLC pin 18            (GSCLK)
    -  digital 9        -> TLC pin 24            (XLAT)
    -  digital 10       -> TLC pin 23            (BLANK)
    -  digital 11       -> TLC pin 26            (SIN)
    -  digital 13       -> TLC pin 25            (SCLK)
    -  The 2K resistor between TLC pin 20 and GND will let ~20mA through each
       LED.  To be precise, it's I = 39.06 / R (in ohms).  This doesn't depend
       on the LED driving voltage.
    - (Optional): put a pull-up resistor (~10k) between +5V and BLANK so that
                  all the LEDs will turn off when the Arduino is reset.

    If you are daisy-chaining more than one TLC, connect the SOUT of the first
    TLC to the SIN of the next.  All the other pins should just be connected
    together:
        BLANK on Arduino -> BLANK of TLC1 -> BLANK of TLC2 -> ...
        XLAT on Arduino  -> XLAT of TLC1  -> XLAT of TLC2  -> ...
    The one exception is that each TLC needs it's own resistor between pin 20
    and GND.

    This library uses the PWM output ability of digital pins 3, 9, 10, and 11.
    Do not use analogWrite(...) on these pins.

    This sketch does the Knight Rider strobe across a line of LEDs.
#include "Tlc5940.h"
#include "LEDGridAnimations.h"

    Alex Leone <acleone ~AT~ gmail.com>, 2009-02-03 */
#define SIGNAL_WIRE 2  // signal wire from other Arduino

#include "Tlc5940.h"
int curMode;

void setup()
{
  pinMode(SIGNAL_WIRE, INPUT);
  Tlc.init();
  Serial.begin(9600);
}

void loop()
{
  Tlc.clear();
  Tlc.set(9, 4095);
  Tlc.set(10, 0);
  Tlc.set(11, 0);
  Tlc.set(12, 4095);
  Tlc.set(13, 0);
  Tlc.set(14, 0);
  Tlc.update();
  delay(100);
  Tlc.clear();
  Tlc.set(9, 0);
  Tlc.set(10, 4095);
  Tlc.set(11, 0);
  Tlc.set(12, 0);
  Tlc.set(13, 4095);
  Tlc.set(14, 0);
  Tlc.update();
  delay(100);
  Tlc.clear();
  Tlc.set(9, 0);
  Tlc.set(10, 0);
  Tlc.set(11, 4095);
  Tlc.set(12, 0);
  Tlc.set(13, 0);
  Tlc.set(14, 4095);
  Tlc.update();
  delay(100);
  curMode = digitalRead(SIGNAL_WIRE);

  
  if (curMode == LOW) {
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
//    Tlc.set(0, 4095);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(30);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 4095);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(30);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 4095);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(30);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 4095);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(30);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 4095);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(10);
//    Tlc.set(0, 0);
//    Tlc.set(1, 4095);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(100);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 4095);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(20);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 4095);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(900);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 4095);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(70);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 4095);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(10);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 4095);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(70);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 4095);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(10);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 4095);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(10);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 4095);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 0);
//    Tlc.update();
//    delay(10);
//    Tlc.set(0, 0);
//    Tlc.set(1, 0);
//    Tlc.set(2, 0);
//    Tlc.set(3, 0);
//    Tlc.set(4, 0);
//    Tlc.set(5, 0);
//    Tlc.set(6, 0);
//    Tlc.set(7, 0);
//    Tlc.set(8, 0);
//    Tlc.set(9, 0);
//    Tlc.set(10, 0);
//    Tlc.set(11, 0);
//    Tlc.set(12, 0);
//    Tlc.set(13, 0);
//    Tlc.set(14, 4095);
//    Tlc.update();
//    delay(10);
  }
  else {
    allWhite();
  }
}


