#ifndef CAN_TRANSCEIVER_SEEN
#define CAN_TRANSCEIVER_SEEN

#include <CAN.h>
#include "can_packet.hpp"

class CANTransceiver{
    public:
        static void Send(CANPacket sent_packet);
        static bool Receive(CANPacket& received_packet);
};

void CANTransceiver::Send(CANPacket sent_packet) {
    CAN.beginPacket(sent_packet.ID);
    for(int i = 0; i < 8; i++) CAN.write(sent_packet.buf.at(i));
    CAN.endPacket();
}

bool CANTransceiver::Receive(CANPacket& received_packet) {
    if(received_packet.ID != CAN.packetId()) return false;
    int read_count = 0;
    while(CAN.available()) {
        received_packet.buf.at(read_count) = CAN.read();
        read_count++;
    }
    return true;
}

#endif