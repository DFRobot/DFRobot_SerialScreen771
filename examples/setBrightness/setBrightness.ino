/*!
 * @file setBrightness.ino
 * @brief Set the brightness level of the display. Adjust the brightness level of the display.
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
    // Initialize communication interface (Serial1) and debug interface (Serial)
    Serial.begin(115200);
    Serial1.begin(19200);
    screen.begin();

    // Display string "DFRobot"
    screen.displayMessage("DFRobot");
    // Set the brightness level of the display
    /*eBrightLevel_t: eBrightLevel_1 = Brightness level 1
                      eBrightLevel_2 = Brightness level 2
                      eBrightLevel_3 = Brightness level 3
                      eBrightLevel_4 = Brightness level 4
                      eBrightLevel_5 = Brightness level 5
                      eBrightLevel_6 = Brightness level 6
                      eBrightLevel_7 = Brightness level 7
                      eBrightLevel_8 = Brightness level 8
    */
    screen.setBrightness(screen.eBrightLevel_1);
}

void loop() {

}