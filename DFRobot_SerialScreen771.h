/*!
 * @file DFRobot_SerialScreen771.h
 * @brief Define the basic structure of class DFRobot_SerialScreen771 
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Arya](xue.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2019-6-12
 * @url https://github.com/DFRobot/DFRobot_SerialScreen771
 */

#ifndef __DFROBOT_SERIALSCREEN771_H
#define __DFROBOT_SERIALSCREEN771_H
#include <Arduino.h>
#include <Stream.h>

#if 0
#define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

extern Stream *dbg;
class DFRobot_SerialScreen771{
public:
  #define MESSAGE_SIZE      250    //< data cache size
  #define BANNER            8      //< The screen can store the information of 8 banners.
  
  /**
   * @struct sHeader_t, pHeader_t
   * @brief packet header
   */
  typedef struct{
      uint8_t head1;
      uint8_t head2;
      uint8_t head3;
      uint8_t head4;
      uint8_t head5;
  }__attribute__ ((packed)) sHeader_t, *pHeader_t;

  /**
   * @struct sLength_t, pLength_t
   * @brief packet length
   */
  typedef struct{
      uint8_t lenH;
      uint8_t lenL;
  }__attribute__ ((packed)) sLength_t, *pLength_t;
  /**
   * @struct sPacketHeader_t, pPacketHeader_t
   * @brief packet structure
   */
  typedef struct{
      sHeader_t  head;
      uint8_t type;
      uint8_t addr;
      sLength_t length;
      uint8_t payload[0];
      uint8_t cs;
  }__attribute__ ((packed)) sPacketHeader_t, *pPacketHeader_t;
  
  /**
   * @struct eMoveMode_t
   * @brief Display move mode
   */
  typedef enum{
      eMoveLeft = 0x31,   /**< move left */
      eMoveRight = 0x32,  /**< move right */
      eMoveHold = 0x33,   /**< hold still */
      eMoveUp = 0x35,     /**< move up */
      eMoveDown = 0x36,   /**< move down */
      eMoveFlash = 0x37   /**< flash */
  }eMoveMode_t;
  
  /**
   * @struct eColorMode_t
   * @brief Display color
   */
  typedef enum{
      eColorRed = 0x0052,    /**< red */
      eColorYellow = 0x0059, /**< yellow */
      eColorGreen = 0x0047,  /**< green */
      eColorCyan = 0x0043,   /**< cyan */
      eColorBlue = 0x0042,   /**< blue */
      eColorPurple = 0x0050, /**< purple */
      eColorWhite = 0x0057,  /**< white */
      eColorBlack = 0x0044   /**< black */
  }eColorMode_t;
  
  /**
   * @struct eBrightLevel_t
   * @brief Brightness level
   */
  typedef enum{
      eBrightLevel_1 = 0x31,    /**< brightness level 1 */
      eBrightLevel_2 = 0x32,    /**< brightness level 2 */
      eBrightLevel_3 = 0x33,    /**< brightness level 3 */
      eBrightLevel_4 = 0x34,    /**< brightness level 4 */
      eBrightLevel_5 = 0x35,    /**< brightness level 5 */
      eBrightLevel_6 = 0x36,    /**< brightness level 6 */
      eBrightLevel_7 = 0x37,    /**< brightness level 7 */
      eBrightLevel_8 = 0x38     /**< brightness level 8 */
  }eBrightLevel_t;
  
  typedef enum{
      eSpeedLevel_1 = 0x31,     /**< speed level 1 */
      eSpeedLevel_2 = 0x32,     /**< speed level 2 */
      eSpeedLevel_3 = 0x33,     /**< speed level 3 */
      eSpeedLevel_4 = 0x34,     /**< speed level 4 */
      eSpeedLevel_5 = 0x35,     /**< speed level 5 */
      eSpeedLevel_6 = 0x36,     /**< speed level 6 */
      eSpeedLevel_7 = 0x37,     /**< speed level 7 */
      eSpeedLevel_8 = 0x38      /**< speed level 8 */
  }eSpeedLevel_t;

  typedef enum{
      eBanner_1 = 1 << 0,   /**< Information list (banner) NO. 1 */ 
      eBanner_2 = 1 << 1,   /**< Information list (banner) NO. 2 */
      eBanner_3 = 1 << 2,   /**< Information list (banner) NO. 3 */
      eBanner_4 = 1 << 3,   /**< Information list (banner) NO. 4 */
      eBanner_5 = 1 << 4,   /**< Information list (banner) NO. 5 */
      eBanner_6 = 1 << 5,   /**< Information list (banner) NO. 6 */
      eBanner_7 = 1 << 6,   /**< Information list (banner) NO. 7 */
      eBanner_8 = 1 << 7,   /**< Information list (banner) NO. 8 */
      eBanner_ALL = 0xFF    /**< 1~8 all the information list serial numbers */
  }eBanner_t;

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
   * @n eBanner_1 or 1 << 0 Set the content of the 1st message list
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
   * @brief Display the banner information in message lists, this screen stores the information of 8 data lists, users can use this function to display one or more information lists in order
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
protected:
    pPacketHeader_t packed(uint8_t type, const char *pay_, uint16_t len);
    uint8_t getCs(pPacketHeader_t header);
    const char * handleData(uint8_t type, const char *src, uint16_t &len);
    void sendPacket(pPacketHeader_t header);
private:
    Stream *_s;
    uint8_t _sendBuf[MESSAGE_SIZE];
	uint8_t _order;
    eMoveMode_t _moveMode;
	eColorMode_t  _backgroud;
	eColorMode_t  _font;
    eBrightLevel_t _brightLevel;
    eSpeedLevel_t _speedLevel;
    char _message[MESSAGE_SIZE+1];
    char _M[BANNER+1];
};


#endif
