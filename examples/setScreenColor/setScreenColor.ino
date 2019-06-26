/*!
  * file setScreenColor.ino
  * Full screen lighting, full screen display red, yellow, green, blue, blue, purple, white and other colors
  * @Light up the full screen, switch the color every 5s, and cycle
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V1.0
  * date  2019-6-12
  */

#include <Arduino.h>
#include <HardwareSerial.h>
#include <SoftwareSerial.h>
#include "DFRobot_SerialScreen771.h"

#ifdef ARDUINO_AVR_UNO
SoftwareSerial Serial1(2, 3); //RX, TX
#endif

DFRobot_SerialScreen771 screen;

void setup() {
    /*Initialize communication interface (Serial1) and debug interface (Serial)*/
    Serial.begin(115200);
    Serial1.begin(19200);
    screen.begin(Serial1);
    screen.setDbgSerial(Serial);
    /*Set screen color*/
    /*eColorMode_t: eColor_red = red
                    eColor_yellow = yellow
                    eColor_green = green
                    eColor_cyan = cyan
                    eColor_blue = blue
                    eColor_purple = purple
                    eColor_white = white
                    eColor_black = black
    */
    screen.setFullScreenColor(eColor_black);
}

void loop() {
    /*Switch one screen color every 5s*/
    eColorMode_t buf[]= {eColor_red, eColor_yellow, eColor_green, eColor_cyan, eColor_blue, eColor_purple, eColor_white};
    for(int i=0; i < sizeof(buf)/sizeof(eColorMode_t); i++){
        screen.setFullScreenColor(buf[i]);
        delay(5000);
    }
}