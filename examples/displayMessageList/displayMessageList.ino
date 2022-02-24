/*!
 * @file displayMessageList.ino
 * @brief Initialize 8 information lists M1->M8 and directly print the list of "DFRobot" in the information list.
 * @n Display a list of previously stored values of "DFRobot"
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

const char* M1 = "DFRobot";       // eBanner_1  display list 1
const char* M2 = "<CRY>DFRobot";  // eBanner_2  display list 2
const char* M3 = "Hi!";           // eBanner_3  display list 3
const char* M4 = "<CRY>Hello!";   // eBanner_4  display list 4
const char* M5 = "World!";        // eBanner_5  display list 5
const char* M6 = "66";            // eBanner_6  display list 6
const char* M7 = "77";            // eBanner_7  display list 7
const char* M8 = "88";            // eBanner_8  display list 8


void setup() {
    // Initialize communication interface (Serial1) and debug interface (Serial)
    Serial.begin(115200);
    Serial1.begin(19200);
    screen.begin();

    // Send 8 information lists to the serial screen
    screen.setMessageList(screen.eBanner_1, M1);
    screen.setMessageList(screen.eBanner_2, M2);
    screen.setMessageList(screen.eBanner_3, M3);
    screen.setMessageList(screen.eBanner_4, M4);
    screen.setMessageList(screen.eBanner_5, M5);
    screen.setMessageList(screen.eBanner_6, M6);
    screen.setMessageList(screen.eBanner_7, M7);
    screen.setMessageList(screen.eBanner_8, M8);

    // Prints a list of "DFRobot" in the message list, and the data of the M0 message list
    screen.displayBanner(screen.eBanner_1);
    // Print data of M8 information list
    //screen.displayBanner(screen.eBanner_8);
    // Print data for M1 and M8 information lists
    //screen.displayBanner(screen.eBanner_1 | screen.eBanner_8);
    // Display all information lists for M0~M8
    //screen.displayBanner(screen.eBanner_1|screen.eBanner_2|screen.eBanner_3|screen.eBanner_4|screen.eBanner_5|screen.eBanner_6|screen.eBanner_7|screen.eBanner_8);
    //or
    //screen.displayBanner(screen.eBanner_ALL);
}

void loop() {

}
