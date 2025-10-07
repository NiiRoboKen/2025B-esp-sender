#ifndef OMNI_WHEELS_SEEN
#define OMNI_WHEELS_SEEN

#include "omni_wheel.hpp"

template<int num>
class OmniWheels {
    public:
        OmniWheels(double first_omni_angle);
        void Run(double vecotor_x, double vector_y, double rotation);
        bool ReceivePacket();
        static const double INPUT_COUNT_PER_EXEC;
    private:
        std::array<OmniWheel, num> Wheels;
        double m_input_count;
};

#endif