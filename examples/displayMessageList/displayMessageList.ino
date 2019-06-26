/*!
  * file displayMessageList.ino
  * 
  * Initialize 8 information lists M1->M8 and directly print the list of "DFRobot" in the information list.
  * @Display a list of previously stored values of "DFRobot"
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
const char *s = "DFRobot";
eMoveMode_t moveMode;

const char* M1 = "DFRobot";       //"A"
const char* M2 = "<CRY>DFRobot";  //"B"
const char* M3 = "Hi!";           //"C"
const char* M4 = "<CRY>Hello!";   //"D"
const char* M5 = "World!";        //"E"
const char* M6 = "66";            //"F"
const char* M7 = "77";            //"G"
const char* M8 = "88";            //"H"


void setup() {
    /*Initialize communication interface (Serial1) and debug interface (Serial)*/
    Serial.begin(115200);
    Serial1.begin(19200);
    screen.begin(Serial1);
    screen.setDbgSerial(Serial);
    /*Send 8 information lists to the serial screen*/
    screen.setMessageList(1, M1);
    screen.setMessageList(2, M2);
    screen.setMessageList(3, M3);
    screen.setMessageList(4, M4);
    screen.setMessageList(5, M5);
    screen.setMessageList(6, M6);
    screen.setMessageList(7, M7);
    screen.setMessageList(8, M8);
    /* Prints a list of "DFRobot" in the message list, and the data of the M0 message list*/
    screen.displayBanner("A");
    /*Print data of M8 information list*/
    //screen.displayBanner("H");
    /*Print data for M1 and M8 information lists*/
    //screen.displayBanner("AH");
    /*Display all information lists for M0~M8*/
    //screen.displayBanner("ABCDEFGH");
}

void loop() {

}
