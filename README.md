# 7x71 Flexible RGB LED Matrix.

This RGB soft screen is composed of 7x71 RGB lights. It communicates with the main control through the serial port to display strings and change the font and background color.
You can set the display brightness and moving speed, modify and display the contents of the message list.

## DFRobot_SerialScreen771 Library for Arduino
---------------------------------------------------------
Provide an Arduino library for the 771 RGB flexible Screen.

## Table of Contents

* [Summary](#summary)
* [Feature](#feature)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [Credits](#credits)
<snippet>
<content>

## Summary
This is a library for the Arduino IDE, which can help Arduino to communicate with 7x71 Flexible RGB LED Matrix.<br>
The library makes it easy to configure the sensor via Serial<br>

## Feature
1. Support soft and hard serial communication, baud rate 19200

# Installation

Download the library ZIP file and unzip it to the Arduino folder of the library.<br>

## Methods

```C++

#include "DFRobot_SerialScreen771.h"

/*!
 * @brief Initialize the communication serial port
 *
 * @param &s_  Stream port
 * @return  true if execute successfully, false otherwise.
 */
bool begin(Stream &s_);

/*!
 * @brief Set the debug serial port
 *
 * @param &s_  Stream port
 * @return  true if execute successfully, false otherwise.
 */
void setDbgSerial(Stream &s_){dbg = &s_;}

/*!
 * @brief Set display movement mode
 *
 * @param m_  Direction of movement
 *    eMove_left : Move to the left
 *    eMove_right : Move to the right
 *    eMove_hold : hold
 *    eMove_up : Move to the up
 *    eMove_down : Move to the down
 *    eMove_flash : flicker
 * @return  true if execute successfully, false otherwise.
 */
bool setMoveMode(eMoveMode_t m_);

/*!
 * @brief Set display color
 *
 * @param font_  font color
 *    eColor_red : red
 *    eColor_yellow : yellow
 *    eColor_green : green
 *    eColor_cyan : cyan
 *    eColor_blue : blue
 *    eColor_purple : purple
 *    eColor_white : white
 *    eColor_black : black
 *  @param font_  background color
 *    eColor_red : red
 *    eColor_yellow : yellow
 *    eColor_green : green
 *    eColor_cyan : cyan
 *    eColor_blue : blue
 *    eColor_purple : purple
 *    eColor_white : white
 *    eColor_black : black
 *  @return  true if execute successfully, false otherwise.
 */
bool setDispalyColor(eColorMode_t font_, eColorMode_t back_);

/*!
 * @brief Set the display brightness level
 *
 * @param b_  Brightness level
 *    eBrightLevel_1 
 *    eBrightLevel_2
 *    eBrightLevel_3 
 *    eBrightLevel_4 
 *    eBrightLevel_5
 *    eBrightLevel_6
 *    eBrightLevel_7 
 *    eBrightLevel_8 
 * @return  true if execute successfully, false otherwise.
 */
bool setBrightness(eBrightLevel_t b_);

/*!
 * @brief Set display speed level
 *
 * @param s_  Speed level
 *    eSpeedLevel_1 
 *    eSpeedLevel_2
 *    eSpeedLevel_3 
 *    eSpeedLevel_4 
 *    eSpeedLevel_5
 *    eSpeedLevel_6
 *    eSpeedLevel_7 
 *    eSpeedLevel_8 
 * @return  true if execute successfully, false otherwise.
 */
bool setMoveSpeed(eSpeedLevel_t s_);

/*!
 * @brief Modify the value of the message list
 *
 * @param s_  banN
 *    banN of range 1~8
 * @param s_  message_
 *    String information
 * @return  true if execute successfully, false otherwise.
 */
bool setMessageList(uint8_t banN, const char *message_);

/*!
 * @brief Display data for a list of messages
 *
 * @param s_  message_
 *    "A" -> "JIHGFEDCBA"
 * @return  true if execute successfully, false otherwise.
 */
bool displayBanner(const char *message_);

/*!
 * @brief Set display information
 *
 * @param s_  message_
 *
 * @return  true if execute successfully, false otherwise.
 */
bool setMessage(const char *message_);

/*!
 * @brief Full screen lights up to show a certain color
 *
 * @param color_  RGB color
 *    eColor_red : red
 *    eColor_yellow : yellow
 *    eColor_green : green
 *    eColor_cyan : cyan
 *    eColor_blue : blue
 *    eColor_purple : purple
 *    eColor_white : white
 *    eColor_black : black
 * @return  true if execute successfully, false otherwise.
 */
bool setFullScreenColor(eColorMode_t color_);
```

## Compatibility
Not compatible with Arduino IDE 1.0.x


MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno |       √      |             |            | 
Arduino Leonardo |       √      |             |            | 
Arduino Mega2560  |       √      |             |            | 

## Credits

·author [Arya xue.peng@dfrobot.com]
