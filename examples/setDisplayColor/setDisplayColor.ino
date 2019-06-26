/*!
  * file setDisplayColor.ino
  * Set the color of the display background and font, a total of 8 colors of red, 
  * yellow, green, cyan, blue, purple, white, black.
  * @The string "DFRobot" is displayed, the background is black, and the font color 
  * @changes in red, yellow, green, cyan, blue, purple, and white colors every 5 seconds.
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
    delay(5);
    /*Display string "DFRobot"*/
    screen.setMessage("DFRobot");
    /*Set the string to display the background and font color, set it to red on the black background*/
    screen.setDispalyColor(eColor_red, eColor_black);
}

void loop() {
    /*Switch one font color every 5s*/
    eColorMode_t backgroud,font;
    backgroud = eColor_black;
    eColorMode_t buf[]= {eColor_red, eColor_yellow, eColor_green, eColor_cyan, eColor_blue, eColor_purple, eColor_white};
    for(int i = 0; i < sizeof(buf)/sizeof(eColorMode_t); i++){
        font = buf[i];
        screen.setDispalyColor(font, backgroud);
        delay(5000);
    }
}
