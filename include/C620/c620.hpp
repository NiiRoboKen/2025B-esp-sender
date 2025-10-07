#ifndef C620_SEEN
#define C620_SEEN

#include "C620/c620_info.hpp"

class C620 {
    public:
        C620(int set_id);
        C620Info Get();
        bool     ReceiveFeedback();
        void     SetSpeed(CANPacket& ctrl_packet, int16_t speed);

    private:
        C620Info m_Info;
};

bool C620::ReceiveFeedback() {
    return m_Info.ReceiveFeedback();
}
C620::C620(int set_id) : m_Info(C620Info(set_id)) {}

#endif