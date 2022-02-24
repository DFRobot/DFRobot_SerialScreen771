# DFRobot_SerialScreen771

* [中文](./README_CN.md)

This RGB soft screen is composed of 7x71 RGB lights. It communicates with the main control through the serial port to display strings and change the font and background color.
You can set the display brightness and moving speed, modify and display the contents of the message list.
* Feature
1. Support soft and hard serial communication, baud rate 19200

![产品效果图](./resources/images/DFR0597.png)

## Product Link（[https://www.dfrobot.com/product-1992.html](https://www.dfrobot.com/product-1992.html)）
    SKU: DFR0597

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [Credits](#credits)

## Summary
This is a library for the Arduino IDE, which can help Arduino to communicate with 7x71 Flexible RGB LED Matrix.<br>
The library makes it easy to configure the sensor via Serial<br>

# Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++

  /**
   * @fn DFRobot_SerialScreen771
   * @brief DFRobot_SerialScreen771 constructor
   * @param s_ Abstract class Stream, users need to transmit its serial subclass object.
   */
  DFRobot_SerialScreen771(Stream &s_);
  ~DFRobot_SerialScreen771();
  /**
   * @fn begin
   * @brief Initialize the screen
   * @return  Init status
   * @retval true  Init succeeded
   * @retval false Init failed
   */
  bool begin();
  /**
   * @fn setMoveMode
   * @brief Set banner information move mode.
   * @param m_  Move direction
   * @n     eMoveLeft        banner move left
   * @n     eMoveRight       banner move right
   * @n     eMoveHold        banner hold still
   * @n     eMoveUp          banner move up
   * @n     eMoveDown        banner move down
   * @n     eMoveFlash       banner flash
   * @return  Setting status
   * @retval true  Setting succeeded
   * @retval false Setting failed
   */
  bool setMoveMode(eMoveMode_t m_);
  /**
   * @fn setDispalyColor
   * @brief Set the foreground and background colors for the screen display.
   * @param font  font display color
   * @n     eColorRed      red
   * @n     eColorYellow   yellow
   * @n     eColorGreen    green
   * @n     eColorCyan     cyan
   * @n     eColorBlue     blue
   * @n     eColorPurple   purple
   * @n     eColorWhite    white
   * @n     eColorBlack    black
   * @param shading  font shading
   * @n     eColorRed      red
   * @n     eColorYellow   yellow
   * @n     eColorGreen    green
   * @n     eColorCyan     cyan
   * @n     eColorBlue     blue
   * @n     eColorPurple   purple
   * @n     eColorWhite    white
   * @n     eColorBlack    black
   * @return  Setting status
   * @retval true  Setting succeeded
   * @retval false Setting failed
   */
  bool setDispalyColor(eColorMode_t font, eColorMode_t shading);
  /**
   * @fn setBrightness
   * @brief Set brightness level, higher level for higher brightness.
   * @param b_  Brightness level
   * @n eBrightLevel_1    brightness level 1
   * @n eBrightLevel_2    brightness level 2
   * @n eBrightLevel_3    brightness level 3
   * @n eBrightLevel_4    brightness level 4
   * @n eBrightLevel_5    brightness level 5
   * @n eBrightLevel_6    brightness level 6
   * @n eBrightLevel_7    brightness level 7
   * @n eBrightLevel_8    brightness level 8
   * @return  Setting status
   * @retval true  Setting succeeded
   * @retval false Setting failed
   */
  bool setBrightness(eBrightLevel_t b_);
  /**
   * @fn setMoveSpeed
   * @brief Set banner information move speed.
   * @param s_  Set speed level, higher level for higher speed.
   * @n eSpeedLevel_1    move speed level 1
   * @n eSpeedLevel_2    move speed level 2
   * @n eSpeedLevel_3    move speed level 3
   * @n eSpeedLevel_4    move speed level 4
   * @n eSpeedLevel_5    move speed level 5
   * @n eSpeedLevel_6    move speed level 6
   * @n eSpeedLevel_7    move speed level 7
   * @n eSpeedLevel_8    move speed level 8
   * @return  Setting status
   * @retval true  Setting succeeded
   * @retval false Setting failed
   */
  bool setMoveSpeed(eSpeedLevel_t s_);
  /**
   * @fn setMessageList
   * @brief Set message list, this screen can store 8 message lists, and users can change the content in any list by the function.
   * @param banN  banN  Display the set of message list serial numbers
   * @n eBanner_1 or 1 << 0 Set the content of the first message list
   * @n eBanner_2 or 1 << 1 Set the content of the 2nd message list
   * @n eBanner_3 or 1 << 2 Set the content of the 3rd message list
   * @n eBanner_4 or 1 << 3 Set the content of the 4th message list
   * @n eBanner_5 or 1 << 4 Set the content of the 5th message list
   * @n eBanner_6 or 1 << 5 Set the content of the 6th message list
   * @n eBanner_7 or 1 << 6 Set the content of the 7th message list
   * @n eBanner_8 or 1 << 7 Set the content of the 8th message list
   * @n eBanner_ALL or 0xFF Set all the message lists to the same content
   * @n eBanner_1 ~ eBanner_7 can be combined random, which indicates the combined two message lists are set to the same content, for example: eBanner_1 | eBanner_8 indicates the contents of the 1st and the 8th message lists are set to the same.
   * @n message_ Message content
   * @return  Setting status
   * @retval true  Setting succeeded
   * @retval false Setting failed
   */
  bool setMessageList(uint8_t banN, const char *message_);
  bool setMessageList(eBanner_t banN, const char *message_);
  /**
   * @fn displayBanner
   * @brief Display the banner information in message lists, this screen stores the information of 8 data lists, users can use this function to display one or more information lists in order.
   * @param banN  banN  Display the set of message list serial numbers
   * @n eBanner_1 or 1 << 0 The banner message of the 1st message list stored in the display
   * @n eBanner_2 or 1 << 1 The banner message of the 2nd message list stored in the display
   * @n eBanner_3 or 1 << 2 The banner message of the 3rd message list stored in the display
   * @n eBanner_4 or 1 << 3 The banner message of the 4th message list stored in the display
   * @n eBanner_5 or 1 << 4 The banner message of the 5th message list stored in the display
   * @n eBanner_6 or 1 << 5 The banner message of the 6th message list stored in the display
   * @n eBanner_7 or 1 << 6 The banner message of the 7th message list stored in the display
   * @n eBanner_8 or 1 << 7 The banner message of the 8th message list stored in the display
   * @n eBanner_ALL or 0xFF Display all the stored message lists in order
   * @n eBanner_1 ~ eBanner_7 can be combined random, which means to display the selected banner information in order, for example: eBanner_1 | eBanner_8 means to display the 1st and the 8th banner information.
   * @return  None
   */
  void displayBanner(uint8_t banN);
  void displayBanner(eBanner_t banN);
  /**
   * @fn displayMessage
   * @brief display information
   * @param message_  display information   
   */
  void displayMessage(const char *message_);
  /**
   * @fn setFullScreenColor
   * @brief Full screen lights up to show a certain color
   * @param color_  RGB color
   * @n     eColorRed      red
   * @n     eColorYellow   yellow
   * @n     eColorGreen    green
   * @n     eColorCyan     cyan
   * @n     eColorBlue     blue
   * @n     eColorPurple   purple
   * @n     eColorWhite    white
   * @n     eColorBlack    black
   * @return  set state
   * @retval true  success
   * @retval false failed
   */
  bool setFullScreenColor(eColorMode_t color_);
```

## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno |       √      |             |            | 
Arduino Leonardo |       √      |             |            | 
Arduino Mega2560  |       √      |             |            | 

## History
- 2019/06/12 - Version 1.0.0 released.
- 2022/01/24 - Version 1.1.0 released.

## Credits

Written by Arya(xue.peng@dfrobot.com), 2019. (Welcome to our [website](https://www.dfrobot.com/))
