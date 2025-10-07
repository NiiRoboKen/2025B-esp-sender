#ifndef CAN_PACKET_SEEN
#define CAN_PACKET_SEEN

#include <array>

struct CANPacket {
    CANPacket(int set_id);
    void Clear();

    int ID;
    std::array<uint8_t, 8> buf;
};

#endif