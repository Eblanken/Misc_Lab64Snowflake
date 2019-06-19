/*
 * File: Snowflake_V1.ino
 * ------------------------------
 * Author: Erick Blankenberg
 * Date:   7/30/2018
 *
 * Description:
 *  This sketch drives an electronic snowflake.
 *  
 * Pinout:
 *  Toiuch pins (clockwise from top right):
 *    PA05: 18
 *    PA06: 8
 *    PA07: 9
 *    PB08: 4
 *    PB09: 3
 *    PA04: 17
 *  Top of branches (clockwise from top):
 *    PA10: 1
 *    PB10: 23
 *    PA12: 22
 *    PA16: 11
 *    PA18: 10
 *    PA08: 4
 *  Bottom of branches (clockwise from top):
 *    PA11: 0
 *    PB11: 24
 *    PA13: 28 // Greenwired to 2 on #1
 *    PA17: 13
 *    PA19: 12
 *    PA09: 3
 *  RGB LED (R, G, B):
 *    PA22: 20
 *    PA21: 7
 *    PA20: 6
 */

 #include "Adafruit_FreeTouch.h"

const int INNER_PINS[] = {0, 24, 2, 13, 12, 3}; // {d[16], d[], d[], d[], d[], d[]}
const int OUTER_PINS[] = {1, 23, 22, 11, 10, 4}; // {d[15], d[], d[], d[], d[], d[]}
const int RGB_PINS[]   = {20, 7, 6};
const int TOUCH_PINS[] = 

Adafruit_FreeTouch touchArray[] = 

void setup() {
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(20, OUTPUT);
  digitalWrite(20, LOW);
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  for(int index = 0; index < 6; index++) {
    pinMode(INNER_PINS[index], OUTPUT);
    pinMode(OUTER_PINS[index], OUTPUT);
  }
}

void loop() {
  for(int value = 0; value < 255; value++) {
    for(int index = 0; index < 6; index++) {
      analogWrite(INNER_PINS[index], (256 - value));
      analogWrite(OUTER_PINS[index], value);
      delay(5);
    }
  }
  for(int value = 0; value < 255; value++) {
    for(int index = 0; index < 6; index++) {
      analogWrite(INNER_PINS[index], value);
      analogWrite(OUTER_PINS[index], (256 - value));
      delay(5);
    }
  }
    
  /*
  for(int index = 0; index < 6; index++) {
    pinMode(INNER_PINS[index], OUTPUT);
    digitalWrite(INNER_PINS[index], HIGH);
    delay(500);
    //digitalWrite(INNER_PINS[index], LOW);
  }
  
  for(int index = 0; index < 6; index++) {
    pinMode(OUTER_PINS[index], OUTPUT);
    digitalWrite(OUTER_PINS[index], HIGH);
    delay(500);
    //digitalWrite(OUTER_PINS[index], LOW);
  }
  for(int r = 0; r < 256; r+=25) {
    for(int g = 0; g < 256; g+=25) {
      for(int b = 0; b < 256; b+=25) {
        analogWrite(7, r);
        analogWrite(20, g);
        analogWrite(6, b);
        delay(100);
      }
    }
  }
  */
}

/*
 * TODO LIST
 * 
 * 1: Bad center LED, 3rd bottom pin cannot be written to?
 * 2: Power good, has shorted pins on MCU, no bootloader?
 * 3: Power good, has shorted pins on MCU, no bootloader?
 * 4: No status determined
 */
