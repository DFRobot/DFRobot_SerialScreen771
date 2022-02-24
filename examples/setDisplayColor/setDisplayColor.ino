/*!
 * @file setDisplayColor.ino
 * @brief Set the color of the display background and font, a total of 8 colors of red, yellow, green, cyan, blue, purple, white, black.
 * @n The string "DFRobot" is displayed, the background is black, and the font color changes in red, yellow, green, cyan, blue, purple, and white colors every 5 seconds.
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
    /*Set the string to display the background and font color, set it to red on the black background*/
    screen.setDispalyColor(screen.eColorRed, screen.eColorBlack);
}

void loop() {
    /*Switch one font color every 5s*/
    DFRobot_SerialScreen771::eColorMode_t backgroud,font;
    backgroud = screen.eColorBlack;
    DFRobot_SerialScreen771::eColorMode_t buf[]= {screen.eColorRed, screen.eColorYellow, screen.eColorGreen, screen.eColorCyan, screen.eColorBlue, screen.eColorPurple, screen.eColorWhite};
    for(int i = 0; i < sizeof(buf)/sizeof(DFRobot_SerialScreen771::eColorMode_t); i++){
        font = buf[i];
        screen.setDispalyColor(font, backgroud);
        delay(5000);
    }
}
