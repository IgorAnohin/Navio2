#ifndef RCOUTPUT_NAVIO_H
#define RCOUTPUT_NAVIO_H

#include <Common/RCOutput.h>
#include "PCA9685.h"
#include <Common/gpio.h>

using namespace Navio;


class RCOutput_Navio : public RCOutput
{
public:
    RCOutput_Navio();
    bool initialize();
    void setFrequency(float frequency);
    bool set_duty_cycle(unsigned int channel, float period);

private:
    PCA9685 pwm;
};

#endif // RCOUTPUT_NAVIO_H
