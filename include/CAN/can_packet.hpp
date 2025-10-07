#ifndef CAN_PACKET_SEEN
#define CAN_PACKET_SEEN

#include <array>

struct CANPacket {
    CANPacket(int set_id);
    void Clear();

    int ID;
    std::array<uint8_t, 8> buf;
};

CANPacket::CANPacket(int set_id) : ID(set_id) { Clear(); }
void CANPacket::Clear() { buf.fill(0); }

#endif