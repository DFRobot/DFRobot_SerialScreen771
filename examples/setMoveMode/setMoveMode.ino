/*!
 * @file setMoveMode.ino
 * @brief Set the movement mode of the display, such as left, right, hold, up, down, flash display, etc.
 * @n The character string "DFRobot" is displayed, and the mobile display mode is switched once every 5s
 * @n The string "DFRobot" sequentially performs cyclic display such as left, right, hold, up, down, and flash.
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
    /*Set the move mode to hold*/
    /*eMoveMode_t: eMoveLeft = left
                   eMoveRight = right
                   eMoveHold = hold
                   eMoveDown = down
                   eMoveUp = up
                   eMoveFlash = flash
    */
    screen.setMoveMode(screen.eMoveHold);
}

void loop() {
    /*Switch a mobile display mode every 5s*/
    DFRobot_SerialScreen771::eMoveMode_t buf[]= {screen.eMoveLeft,screen.eMoveRight,screen.eMoveHold,screen.eMoveDown,screen.eMoveUp,screen.eMoveFlash};
    for(int i = 0; i < sizeof(buf)/sizeof(DFRobot_SerialScreen771::eMoveMode_t); i++){
        screen.setMoveMode(buf[i]);
        delay(5000);
    }
}