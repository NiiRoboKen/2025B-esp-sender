#ifndef OMNI_WHEELS_SEEN
#define OMNI_WHEELS_SEEN

#include "omni_wheel.hpp"

template<int num>
class OmniWheels {
    public:
        OmniWheels(double first_omni_angle);
        Run(double vecotor_x, double vector_y, double rotation);
    private:
        std::array<OmniWheel, num> Wheels;
        double m_input_count;
};

#endif