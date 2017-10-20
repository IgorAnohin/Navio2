#ifndef RCOUTPUT_NAVIO2_H
#define RCOUTPUT_NAVIO2_H

#include "PWM.h"
#include <Common/RCOutput.h>


class RCOutput_Navio2 : public RCOutput
{
public:
    RCOutput_Navio2();
    bool initialize();
    void setFrequency(float frequency);
    bool set_duty_cycle(unsigned int channel, float period);

private:
    PWM pwm;
};

#endif // RCOUTPUT_NAVIO2_H
