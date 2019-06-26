/*!
  * file setMoveMode.ino
  * Set the movement mode of the display, such as left, right, hold, up, down, flash display, etc.
  * @The character string "DFRobot" is displayed, and the mobile display mode is switched once every 5s
  * @The string "DFRobot" sequentially performs cyclic display such as left, right, hold, up, down, and flash.
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
    /*Set the move mode to hold*/
    /*eMoveMode_t: eMove_left = left
                   eMove_right = right
                   eMove_hold = hold
                   eMove_down = down
                   eMove_up = up
                   eMove_flash = flash
    */
    screen.setMoveMode(eMove_hold);
}

void loop() {
    /*Switch a mobile display mode every 5s*/
    eMoveMode_t buf[]= {eMove_left,eMove_right,eMove_hold,eMove_down,eMove_up,eMove_flash};
    for(int i = 0; i < sizeof(buf)/sizeof(eMoveMode_t); i++){
        screen.setMoveMode(buf[i]);
        delay(5000);
    }
}