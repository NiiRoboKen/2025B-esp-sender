#ifndef OMNI_WHEEL_SEEN
#define OMNI_WHEEL_SEEN

#include "C620/c620.hpp"

class OmniWheel {
    public:
        OmniWheel(double vector_x, double vector_y, double shift_power_percentage, double turn_power_percentage);
        void Run(double vector_x, double vector_y, double rotation);
        void Stop();
        bool ReceiveFeedback();
    private:
        C620 m_robomas_motor;
        double m_vector_x ;
        double m_vector_y ;
        double m_shift_power_percentage ;
        double m_turn_power_percentage ;
};

#endif