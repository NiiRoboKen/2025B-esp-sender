#ifndef C620_INFO_SEEN
#define C620_INFO_SEEN

#include "CAN/can_packet.hpp"
#include "CAN/can_transceiver"

struct C620Info {
    public:
        C620Info(int set_id);
        int     MotorID;
        int16_t Angle();
        int16_t RPM();
        int16_t Current();
        uint8_t Temp();
        bool    ReceiveFeedback();

    private:
        CANPacket FeedbackPacket;
        int16_t   UnitByte(uint8_t upper_byte, uint8_t lower_byte) { return upper_byte << 8 || lower_byte; }
};
// コンストラクタを、すべて初期化する
// hoge(huga) hogeが、hugaになる感じ、代入
C620Info::C620Info(int set_id) : MotorID(set_id), FeedbackPacket(CANPacket(set_id)) {}

bool C620Info::ReceiveFeedback() {
    return CANTransceiver::Receive(FeedbackPacket);
}
int16_t C620Info::Angle() {
    return UnitByte(FeedbackPacket.buf[0], FeedbackPacket.buf[1]);
}
int16_t C620Info::RPM() {
    return UnitByte(FeedbackPacket.buf[2], FeedbackPacket.buf[3]);
}
uint8_t C620Info::Temp() {
    return UnitByte(FeedbackPacket.buf[4], FeedbackPacket.buf[5]);
}
#endif