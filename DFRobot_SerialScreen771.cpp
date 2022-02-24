/*!
 * @file DFRobot_SerialScreen771.cpp
 * @brief Define the basic structure of class DFRobot_SerialScreen771 
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Arya](xue.peng@dfrobot.com)
 * @version  V1.0.0
 * @date  2019-6-12
 * @url https://github.com/DFRobot/DFRobot_SerialScreen771
 */

#include "DFRobot_SerialScreen771.h"

#define TYPE_INFROMTION   0X01   //< type information
#define TYPE_BRIGHT       0X02   //< type bright
#define TYPE_SPEED        0x03   //< type speed
#define TYPE_LIST         0X04   //< type list
#define FULLSCREEN        0x32   //< the maximum number of characters displayed on the full screen

DFRobot_SerialScreen771::DFRobot_SerialScreen771(Stream &s_)
  :_s(&s_),_order(0){
      _moveMode    = eMoveHold;
      _backgroud   = eColorBlack;
      _font        = eColorBlue;
      _brightLevel = eBrightLevel_5;
      _speedLevel  = eSpeedLevel_1;
    
	  memset(_sendBuf, 0 ,sizeof(_sendBuf));
      memset(_message, 0, sizeof(_message));
      for(int i = 0 ; i < BANNER; i++){
          _M[i] = 0x41 + i;
      }
      memcpy(_M, "ABCDEFGHI", BANNER);
}

DFRobot_SerialScreen771::~DFRobot_SerialScreen771()
{
}

bool DFRobot_SerialScreen771::DFRobot_SerialScreen771::begin(){
    if(_s == NULL){
        return false;
    }
    return true;
}

bool DFRobot_SerialScreen771::setMoveMode(eMoveMode_t m_){
    bool ret = true;
    if((m_ < eMoveLeft) | (m_ == 0x34) | (m_ > eMoveFlash)){
        return false;
    }
    _moveMode = m_;
    if(strlen(_message) == 0){
        memcpy(_message, "DFRobot", strlen("DFRobot"));
        _message[strlen("DFRobot")] = '\0';
    }
    DBG(_message);
    displayMessage(_message);
    return ret;
}

bool DFRobot_SerialScreen771::setDispalyColor(eColorMode_t font_, eColorMode_t back_){
    _backgroud = back_;
    _font = font_;
    char s1[MESSAGE_SIZE] = {0x3C, 0x43,(char)(_font&0x00FF), (char)(_backgroud&0x00FF), 0x3E};
    if(strlen(_message) == 0){
        memset(_message, 0, sizeof(_message));
        memcpy(_message, "DFRobot", strlen("DFRobot"));
        _message[strlen("DFRobot")] = '\0';
    }
    DBG(_message);
    if((strlen(s1)+strlen(_message)) > MESSAGE_SIZE){
        DBG("packed !");
        return false;
    }
    memcpy((s1+strlen(s1)), _message, strlen(_message));
    pPacketHeader_t header = packed(TYPE_INFROMTION, s1, strlen(s1));
    if(header == NULL){
        DBG("Memory ERROR!");
        return false;
    }
    sendPacket(header);
    free(header);
    return true;
}

bool DFRobot_SerialScreen771::setBrightness(eBrightLevel_t b_){
    char mess[1];
    mess[0] = b_;
    _brightLevel = b_;
    //message[0] = b_;
    pPacketHeader_t header = packed(TYPE_BRIGHT, mess, strlen(mess));
    if(header == NULL){
        DBG("Memory ERROR!");
        return false;
    }
    DBG("payload:");DBG((const char *)header->payload);
    sendPacket(header);
    DBG("payload:");DBG((const char *)header->payload);
    free(header);
    return true;
}

bool DFRobot_SerialScreen771::setMoveSpeed(eSpeedLevel_t s_){
    char mess[1];
    mess[0] = s_;
    //message[0] = b_;
    pPacketHeader_t header = packed(TYPE_SPEED, mess, strlen(mess));
    if(header == NULL){
        DBG("Memory ERROR!");
        return false;
    }
    DBG("payload:");DBG((const char *)header->payload);
    sendPacket(header);
    DBG("payload:");DBG((const char *)header->payload);
    free(header);
    return true;
}

bool DFRobot_SerialScreen771::setMessageList(eBanner_t banN, const char *message_){
    return setMessageList((uint8_t)banN, message_);
}

bool DFRobot_SerialScreen771::setMessageList(uint8_t banN, const char *message_){
    if(strlen(message_) > MESSAGE_SIZE ){
       return false;
    }
    if(!banN) return false;
    memset(_message, 0, sizeof(_message));
    memcpy(_message, message_ ,strlen(message_));
    _message[strlen(message_)] = '\0';
    for(int i = 0; i < BANNER; i++){
        if(banN & (1 << i)){
            _order = i;
            pPacketHeader_t header = packed(TYPE_INFROMTION, _message, strlen(_message));
            if(header == NULL){
                DBG("Memory ERROR!");
                return false;
            }
            sendPacket(header);
            free(header);
            delay(5);
        }
    }
    return true;
}

void DFRobot_SerialScreen771::displayBanner(uint8_t banN){
    String message = "";
    if(!banN) return;
    for(int i = 0; i < 8; i++){
        if(banN & (1 << i)){
            switch(i){
                case 0:
                       message += 'A';
                       break;
                case 1:
                       message += 'B';
                       break;
                case 2:
                       message += 'C';
                       break;
                case 3:
                       message += 'D';
                       break;
                case 4:
                       message += 'E';
                       break;
                case 5:
                       message += "F";
                       break;
                case 6:
                       message += "G";
                       break;
                case 7:
                       message += "H";
                       break;
            }
        }
    }
    DBG(message);
    Serial.println(message.c_str());
    Serial.println( strlen(message.c_str()));
    pPacketHeader_t header = packed(TYPE_LIST, message.c_str(), strlen(message.c_str()));
    if(header == NULL){
        DBG("Memory ERROR!");
        return ;
    }
    sendPacket(header);
    free(header);
    return;
}
void DFRobot_SerialScreen771::displayBanner(eBanner_t banN){
    return displayBanner((uint8_t)banN);
}

void DFRobot_SerialScreen771::displayMessage(const char *message_){
    if(strlen(message_) > MESSAGE_SIZE){
       return ;
    }
    char mess[250];
    memcpy(mess, message_, strlen(message_));
    mess[strlen(message_)] = '\0';
    memset(_message, 0, sizeof(_message));
    memcpy(_message, mess, strlen(mess));
    _message[strlen(mess)] = '\0';
    pPacketHeader_t header = packed(TYPE_INFROMTION, _message, strlen(_message));
    if(header == NULL){
        DBG("Memory ERROR!");
        return;
    }
    DBG("payload:");
    for(int i = 0; i< header->length.lenL; i++){
        DBG(header->payload[i],HEX);
        DBG(i);
    }
    sendPacket(header);
    free(header);
}

bool DFRobot_SerialScreen771::setFullScreenColor(eColorMode_t color_){
    _backgroud = color_;
    _font = color_;
    _moveMode = eMoveHold;
    _order = 0;
    char s1[MESSAGE_SIZE] = {0x3C, 0x43,(char)(_font&0x00FF), (char)(_backgroud&0x00FF), 0x3E};
    memset((s1+strlen(s1)), 0x20, ((FULLSCREEN - strlen(s1)*2 - 4)/2));
    s1[((FULLSCREEN - strlen(s1)*2 - 4)/2)+strlen(s1)] = '\0';
    DBG(s1);
    pPacketHeader_t header = packed(TYPE_INFROMTION, s1, strlen(s1));
    if(header == NULL){
        DBG("Memory ERROR!");
        return false;
    }
    sendPacket(header);
    free(header);
    return true;
}

DFRobot_SerialScreen771::pPacketHeader_t DFRobot_SerialScreen771::packed(uint8_t type, const char *pay_, uint16_t len){
    const char *payload = handleData(type, pay_, len);
    if(payload == NULL){
        DBG("Memory ERROR!");
        return NULL;
    }
    DBG(payload);
    DBG(len);
    DBG(sizeof(sPacketHeader_t));
    pPacketHeader_t header;
    if((header = (pPacketHeader_t)malloc(sizeof(sPacketHeader_t)+len+1)) == NULL){
            DBG("Memory ERROR");
            return NULL;
        }
    header->head.head1 = 0x42; //B
    header->head.head2 = 0x54; //T
    header->head.head3 = 0x30; //0
    header->head.head4 = 0x31; //1
    header->head.head5 = 0x35; //5
    header->type = type;
    header->addr = 0x00; 
    header->length.lenH = (len>>8)&0xFF;
    header->length.lenL = (len)&0x00FF;
    DBG("payload: ");DBG(payload);
    memcpy((char *)header->payload, payload, len);
    DBG("payload: ");DBG((const char *)header->payload);
    header->payload[len] = getCs(header);
    header->payload[len+1] = '\0';
    /*DBG((uint32_t)&(header->head.head1),HEX);
    DBG((uint32_t)&(header->head.head2), HEX);
    DBG((uint32_t)&(header->payload),HEX);
    DBG("cs: ");DBG((uint32_t)&(header->cs),HEX);*/
    free((char *)payload);
    return header;

}

uint8_t DFRobot_SerialScreen771::getCs(pPacketHeader_t header){
    uint8_t cs = 0;
    uint16_t length = (header->length.lenH<<8)|(header->length.lenL);
    for(uint16_t i = 0; i< length; i++){
        cs ^= header->payload[i];
        DBG("biao: ");DBG(i);DBG(header->payload[i], HEX);
    }
    DBG(cs, HEX);
    return cs;
}

const char * DFRobot_SerialScreen771::handleData(uint8_t type, const char *src, uint16_t &len){
    uint16_t length = len;
    DBG(src);
    uint16_t i = 0;
    if(type == TYPE_INFROMTION){
        len += 4 +length;
    }else{
        len += 1;
    }
    char *dst;
    if( (dst= (char *)malloc(len+1)) == NULL){
        DBG("Memory ERROR!");
        return NULL;
    }
    DBG(len);
    memset(dst, 0x00, len);
    switch(type){
        case TYPE_INFROMTION:
                dst[i++] = _M[_order];
                dst[i++] = 0x41;
                dst[i++] = _moveMode;
                dst[i++] = 0x41;
                for(uint16_t j = 0; j < length; j++ ){
                    dst[2*j+1+i] = src[j];
                }
                break;
        case TYPE_BRIGHT:
                dst[i++] = 0x55;
                for(uint16_t j = i; j < len; j++ ){
                    dst[j] = src[j-i];
                }
                //memcpy();
                memcpy((char *)(dst+i), src, length);
                DBG("");
                break;;
        case TYPE_SPEED:
                dst[i++] = 0xAA;
                memcpy((char *)(dst+i), src, length);
                break;;
        case TYPE_LIST:
                dst[i++] = 0x30;
                memcpy((char *)(dst+i), src, length);
                break;
        default: 
                break;
    }
    dst[len]='\0';
    DBG("dst: ");DBG(dst);
    for(i=0;i<len;i++){
        //DBG(i);
        DBG(dst[i]);
    }
    return dst;
}
void DFRobot_SerialScreen771::sendPacket(pPacketHeader_t header){
    DBG("head1:");DBG(header->head.head1,HEX);
    DBG("head2:");DBG(header->head.head2,HEX);
    DBG("head3:");DBG(header->head.head3,HEX);
    DBG("head4:");DBG(header->head.head4,HEX);
    DBG("head5:");DBG(header->head.head5,HEX);
    DBG("type: ");DBG(header->type,HEX);
    DBG("addr: ");DBG(header->addr,HEX);
    DBG("lenH: ");DBG(header->length.lenH,HEX);
    DBG("lenL: ");DBG(header->length.lenL,HEX);
    //DBG("payload:");DBG((const char *)header->payload);
    //delay(10);
    //Serial1.println("hello");
    DBG("payload:");
    uint16_t n = header->length.lenH<<8|header->length.lenL;
    for(uint16_t i=0;i< n+1;i++){
        //DBG(i);
        DBG(header->payload[i],HEX);
    }
    _s->write((uint8_t *)header, n+sizeof(sPacketHeader_t));
    delay(100);
}
