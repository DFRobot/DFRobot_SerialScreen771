/*!
 * @file setMoveSpeed.ino
 * @brief Set the speed at which the string moves. Set the displayed moving speed level.
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Arya](xue.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2019-6-12
 * @url https://github.com/DFRobot/DFRobot_SerialScreen771
 */
#include <Arduino.h>
#include <HardwareSerial.h>
#include <SoftwareSerial.h>
#include "DFRobot_SerialScreen771.h"

#ifdef ARDUINO_AVR_UNO
SoftwareSerial Serial1(2, 3); //RX, TX
#endif

DFRobot_SerialScreen771 screen(Serial1);

void setup() {
    /*Initialize communication interface (Serial1) and debug interface (Serial)*/
    Serial.begin(115200);
    Serial1.begin(19200);
    screen.begin();
 
    delay(5);
    /*Display string "DFRobot"*/
    screen.displayMessage("DFRobot");
    /*Set the display's movement mode to shift left*/
    screen.setMoveMode(screen.eMoveLeft);
    /*Set the displayed moving speed level*/
    /*eBrightLevel_t: eSpeedLevel_1 = Speed class 1
                      eSpeedLevel_2 = Speed class 2
                      eSpeedLevel_3 = Speed class 3
                      eSpeedLevel_4 = Speed class 4
                      eSpeedLevel_5 = Speed class 5
                      eSpeedLevel_6 = Speed class 6
                      eSpeedLevel_7 = Speed class 7
                      eSpeedLevel_8 = Speed class 8
    */
    screen.setMoveSpeed(screen.eSpeedLevel_1);
}

void loop() {

}
