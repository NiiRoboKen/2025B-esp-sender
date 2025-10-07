#ifndef CAN_MANAGER_SEEN
#define CAN_MANAGER_SEEN

#include "can_packet.hpp"

class CANManager{
    public:
        static void Send(CANPacket sent_packet);
        static bool Receive(CANPacket& received_packet);
};

#endif