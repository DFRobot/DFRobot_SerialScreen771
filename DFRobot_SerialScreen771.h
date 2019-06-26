#ifndef __DFROBOT_SERIALSCREEN771_H
#define __DFROBOT_SERIALSCREEN771_H
#include <Arduino.h>
#include <HardwareSerial.h>
#include <SoftwareSerial.h>

#if 0
#define DBG(...) if(dbg) {dbg->print("["); dbg->print(__FUNCTION__); dbg->print("(): "); dbg->print(__LINE__); dbg->print(" ] "); dbg->println(__VA_ARGS__);}
#else
#define DBG(...)
#endif

#define BUFSIZE   250
#define MESSAGE_SIZE  250

#define TYPE_INFROMTION   0X01
#define TYPE_BRIGHT       0X02
#define TYPE_SPEED        0x03
#define TYPE_LIST  0X04

#define DATA_FIXED_SIZE   4
#define OTHER_FIXED_SIZE  1

#define BANNER   8
#define FULLSCREEN  0x32


extern Stream *dbg;

typedef struct{
    uint8_t head1;
    uint8_t head2;
    uint8_t head3;
    uint8_t head4;
    uint8_t head5;
}__attribute__ ((packed)) sHeader_t, *pHeader_t;

typedef struct{
    uint8_t lenH;
    uint8_t lenL;
}__attribute__ ((packed)) sLength_t, *pLength_t;

typedef struct{
    sHeader_t  head;
    uint8_t type;
    uint8_t addr;
    sLength_t length;
    uint8_t payload[0];
    uint8_t cs;
}__attribute__ ((packed)) sPacketHeader_t, *pPacketHeader_t;

typedef enum{
    eMove_left = 0x31,
    eMove_right = 0x32,
    eMove_hold = 0x33,
    eMove_up = 0x35,
    eMove_down = 0x36,
    eMove_flash = 0x37
}eMoveMode_t;

typedef enum{
    eColor_red = 0x0052,
    eColor_yellow = 0x0059,
    eColor_green = 0x0047,
    eColor_cyan = 0x0043,
    eColor_blue = 0x0042,
    eColor_purple = 0x0050,
    eColor_white = 0x0057,
    eColor_black = 0x0044
}eColorMode_t;

typedef enum{
    eBrightLevel_1 = 0x31,
    eBrightLevel_2 = 0x32,
    eBrightLevel_3 = 0x33,
    eBrightLevel_4 = 0x34,
    eBrightLevel_5 = 0x35,
    eBrightLevel_6 = 0x36,
    eBrightLevel_7 = 0x37,
    eBrightLevel_8 = 0x38
}eBrightLevel_t;

typedef enum{
    eSpeedLevel_1 = 0x31,
    eSpeedLevel_2 = 0x32,
    eSpeedLevel_3 = 0x33,
    eSpeedLevel_4 = 0x34,
    eSpeedLevel_5 = 0x35,
    eSpeedLevel_6 = 0x36,
    eSpeedLevel_7 = 0x37,
    eSpeedLevel_8 = 0x38
}eSpeedLevel_t;

class DFRobot_SerialScreen771{
public:
    DFRobot_SerialScreen771();
    ~DFRobot_SerialScreen771();
    bool begin(Stream &s_);
    void setDbgSerial(Stream &s_){dbg = &s_;}
    bool setMoveMode(eMoveMode_t m_);
    bool setDispalyColor(eColorMode_t font_, eColorMode_t back_);
    bool setBrightness(eBrightLevel_t b_);
    bool setMoveSpeed(eSpeedLevel_t s_);
    bool setMessageList(uint8_t banN, const char *message_);
    bool displayBanner(const char *message_);
    bool setMessage(const char *message_);
    bool setFullScreenColor(eColorMode_t color_);
protected:
    pPacketHeader_t packed(uint8_t type, const char *pay_, uint16_t len);
    uint8_t getCs(pPacketHeader_t header);
    const char * handleData(uint8_t type, const char *src, uint16_t &len);
    void sendPacket(pPacketHeader_t header);
private:
    Stream *s;
    uint8_t sendBuf[BUFSIZE];
    uint8_t cs;
	uint8_t order;
    eMoveMode_t moveMode;
	eColorMode_t  backgroud;
	eColorMode_t  font;
    eBrightLevel_t brightLevel;
    eSpeedLevel_t speedLevel;
    char message[MESSAGE_SIZE+1];
    char M[BANNER+1];
};


#endif