/*!
  * file setBrightness.ino
  * Set the brightness level of the display.
  * @Adjust the brightness level of the display.
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
    /*Display string "DFRobot"*/
    screen.setMessage("DFRobot");
    /*Set the brightness level of the display*/
    /*eBrightLevel_t: eBrightLevel_1 = Brightness level 1
                      eBrightLevel_2 = Brightness level 2
                      eBrightLevel_3 = Brightness level 3
                      eBrightLevel_4 = Brightness level 4
                      eBrightLevel_5 = Brightness level 5
                      eBrightLevel_6 = Brightness level 6
                      eBrightLevel_7 = Brightness level 7
                      eBrightLevel_8 = Brightness level 8
    */
    screen.setBrightness(eBrightLevel_1);
}

void loop() {

}