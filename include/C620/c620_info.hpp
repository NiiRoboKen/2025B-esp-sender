#ifndef C620_INFO_SEEN
#define C620_INFO_SEEN

#include "CAN/can_packet.hpp"

struct C620Info {
    public:
        int MotorID;
        int16_t Angle();
        int16_t RPM();
        int16_t Current();
        uint8_t Temp();
        bool ReceiveFeedback();
    private:
        CANPacket FeedbackPacket;
};


#endif