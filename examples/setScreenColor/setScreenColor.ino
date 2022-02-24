/*!
 * @file setScreenColor.ino
 * @brief Full screen lighting, full screen display red, yellow, green, blue, blue, purple, white and other colors.
 * @n Light up the full screen, switch the color every 5s, and cycle
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Arya](xue.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2019-6-12
 * @url https://github.com/DFRobot/DFRobot_SerialScreen771
 */

#include <Arduino.h>
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
    /*Set screen color*/
    /*eColorMode_t: eColorRed = red
                    eColorYellow = yellow
                    eColorGreen = green
                    eColorCyan = cyan
                    eColorBlue = blue
                    eColorPurple = purple
                    eColorWhite = white
                    eColorBlack = black
    */
    screen.setFullScreenColor(screen.eColorBlack);
}

void loop() {
    /*Switch one screen color every 5s*/
    DFRobot_SerialScreen771::eColorMode_t buf[]= {screen.eColorRed, screen.eColorYellow, screen.eColorGreen, screen.eColorCyan, screen.eColorBlue, screen.eColorPurple, screen.eColorWhite,screen.eColorBlack};
    for(int i=0; i < sizeof(buf)/sizeof(DFRobot_SerialScreen771::eColorMode_t); i++){
        screen.setFullScreenColor(buf[i]);
        delay(5000);
    }
}