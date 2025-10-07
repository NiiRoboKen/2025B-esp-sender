#ifndef C620_SEEN
#define C620_SEEN

#include "c620_info.hpp"

class C620 {
    public:
        C620Info Get();
        bool ReceiveFeedBack();
        void SetSpeed(CANPacket& ctrl_packet, int16_t speed);
    private:
        C620Info m_Info;
};

#endif